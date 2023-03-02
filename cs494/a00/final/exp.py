import csv
import requests
import itertools
import threading
import sys
import time
import bisect
import os
import json
from bs4 import BeautifulSoup


animation_done = False
animation_thread = None
years = [*range(1993, 2023, 1)]
months = ["06", "11"]
pages = [1,2,3,4,5]

def reverse_insort(a, x, lo=0, hi=None):
    """Insert item x in list a, and keep it reverse-sorted assuming a
    is reverse-sorted.

    If x is already in a, insert it to the right of the rightmost x.

    Optional args lo (default 0) and hi (default len(a)) bound the
    slice of a to be searched.
    """
    if lo < 0:
        raise ValueError('lo must be non-negative')
    if hi is None:
        hi = len(a)
    while lo < hi:
        mid = (lo+hi)//2
        if x > a[mid]: hi = mid
        else: lo = mid+1
    a.insert(lo, x)

# Converts a number in string format to int or float
# Removes the newlines inside strings
def remove_newlines_and_maybe_convert_to_number(value):
    try:
        return int(value.replace(',', ''))
    except ValueError:
        try:
            return float(value.replace(',', ''))
        except ValueError:
            return value.replace('\n', '')


def merge_page_data(data_per_page):
	if len(data_per_page) == 0:
		return {}
		
	# Get the headers
	headers = list(data_per_page[0].keys())
	if len(headers) == 0:
		return {}
	
	merged = {}
	# Initialize the headers
	for header in headers:
		merged[header] = []
	
	
	for i in range(0, len(data_per_page)):
		for header in headers:
			merged[header] = merged[header] + data_per_page[i][header]
	
	return merged
		


# Get the data from the URL
def get_data_dict(url):

	# Get the html page
    html = requests.get(url).text
    
    # The html parser.
    soup = BeautifulSoup(html, 'html.parser')
    
    # Find all tables on the webpage.
    tables = soup.find_all('table')
    
    # Check if there are none - the URL could be broken.
    if len(tables) == 0:
    	return {}
    	
    # Get the 1st table.
    # Each top500 page has only 1 table so we only need tables[0].
    table = tables[0]
    
    data = {}
    
    headings = [th.get_text().strip().replace('\n', '') for th in table.find("tr").find_all("th")]
    # Get the headings in the table
    for heading in headings:
    	data[heading] = []
    data["Rmax"] = []
    data["Rpeak"] = []
    # Read the data
    for row in table.find_all("tr")[1:]:
    	elements = [	remove_newlines_and_maybe_convert_to_number(td.get_text().strip().replace('\n', ''))
    						for td in row.find_all("td")
    				]
    	ei = 0
    	for heading in headings:
    		if "Rmax (TFlop/s)" in heading:
    			data["Rmax"].append(elements[ei])
    		elif "Rmax (PFlop/s)" in heading:
    			data["Rmax"].append(elements[ei]*1000)
    		elif "Rmax (GFlop/s)" in heading:
    			data["Rmax"].append(elements[ei]/1000)
    		elif "Rpeak (TFlop/s)" in heading:
    			data["Rpeak"].append(elements[ei])
    		elif "Rpeak (PFlop/s)" in heading:
    			data["Rpeak"].append(elements[ei]*1000)
    		elif "Rpeak (GFlop/s)" in heading:
    			data["Rpeak"].append(elements[ei]/1000)
    		elif heading == "Rmax" or heading == "Rpeak":
    			continue
    		else:
    			data[heading].append(elements[ei])
    		ei = ei + 1
    		
    	# for (element, heading) in itertools.zip_longest(elements, headings):

    		
    return data
 
 
def animate(text_start, text_done):
	for c in itertools.cycle(['|', '/', '-', '\\']):
		    if animation_done:
		        break
		    sys.stdout.write(f'\r{text_start}' + c)
		    sys.stdout.flush()
		    time.sleep(0.1)
	sys.stdout.write(f'\r{text_done}\n')
   
def start_animation(text_start, text_done):
	global aniation_done
	global animation_thread
	aniation_done = False
	animation_thread = threading.Thread(target=animate, args=(text_start, text_done,))
	animation_thread.start()
	
def stop_animation():
	global animation_done
	global animation_thread
	animation_done = True
	animation_thread.join()
	animation_thread = None
	sys.stdout.flush()


def user_device_years_top500(rmax_user, data):
	dates_made = {}
	for date_run in data:
		if "Rmax" in list(data[date_run].keys()):
			rmaxs = data[date_run]["Rmax"]
			reverse_insort(rmaxs, rmax_user)
			rank = rmaxs.index(rmax_user) + 1
			rmaxs.remove(rmax_user)
			if rank <= 500:
				dates_made[date_run] = rank
	return dates_made
			
def past10_nov(data):

	# Get the past 10 years
	past_10_years = years[-10:]
	month = "11"
	
	past_10_data = {}
	for year in past_10_years:
		past_10_data[f'{year}-{month}'] = data[f'{year}-{month}']
	return past_10_data

def past10_nov_eff(data):
	past_10_data = past10_nov(data)
	name_eff = {}
	for date in past_10_data:
		for i in range(0, 10):
			system = past_10_data[date]["System"][i]
			system = system.replace(",", "").replace(".", " ")
			rmax = past_10_data[date]["Rmax"][i]
			rpeak = past_10_data[date]["Rpeak"][i]
			if system in name_eff:
				eff_curr = name_eff[system]
				eff_new = rmax/rpeak
				if eff_curr < eff_new:
					name_eff[" ".join(system.split())] = eff_new 
			else:
				name_eff[" ".join(system.split())] = rmax/rpeak
				
	return name_eff
			
			
		

def main():
	
	top500_file = "top500.json"
	data_master = {}
	if os.path.isfile(top500_file) and os.access(top500_file, os.R_OK):
		print(f'Using {top500_file}')
		f = open(top500_file)
		data_master = json.load(f)
	else:
	
		# Get the data tables for each page of each month and year
		
		# Dicstionary of dictionaries
		for year in years:
			for month in months:
				
				# list of dictionaries
				data_per_page = []
				
				start_animation(f'Fetching {year}-{month}', f'Done Fetching {year}-{month}')
				for page in pages:
				
					page_data = get_data_dict(
						"https://www.top500.org/lists/top500/list/{y}/{m}/?page={p}".format(y=year, m=month, p=page))
					data_per_page.append(page_data)
					
				# A dictionary
				merged_data = merge_page_data(data_per_page)
				
				data_master[f'{year}-{month}'] = merged_data
				stop_animation()
		
		with open("top500.json", "w") as outfile:
			json.dump(data_master, outfile)
	
	# Ask user for their machine's Rmax
	rmax_user = float(input("\nEnter the Rmax of your machine(GFlop/s): "))/1000
	dates_made = user_device_years_top500(rmax_user, data_master)
	print("Years for which your device was in top500:")
	for date_made in dates_made:
		print(f'(date={date_made}, rank={dates_made[date_made]})')
		
	user_birth_year = input("\nEnter the year you were born: ")
	fastest= ""
	fastest_rmax = 0
	slowest = ""
	slowest_rmax = 0
	run1_rmax = data_master[f'{user_birth_year}-06']['Rmax'][0]
	run2_rmax = data_master[f'{user_birth_year}-11']['Rmax'][0]
	if run1_rmax >= run2_rmax:
		fastest = data_master[f'{user_birth_year}-06']['System'][0]
		fastest_rmax = run1_rmax
	else:
		fastest = data_master[f'{user_birth_year}-11']['System'][0]
		fastest_rmax = run2_rmax
	print(f'Fastest machine that year: {fastest}')
	run1_rmax = data_master[f'{user_birth_year}-06']['Rmax'][499]
	run2_rmax = data_master[f'{user_birth_year}-11']['Rmax'][499]
	if run1_rmax <= run2_rmax:
		slowest = data_master[f'{user_birth_year}-06']['System'][499]
		slowest_rmax = run1_rmax
	else:
		slowest = data_master[f'{user_birth_year}-11']['System'][499]
		slowest_rmax = run2_rmax
	print(f'Rmax#1@{user_birth_year}/Rmax#500@{user_birth_year}) = {fastest_rmax/slowest_rmax}')
	
	
	print("\nPast 10 years:")
	name_to_eff_past_10_nov_top10 = past10_nov_eff(data_master)
	print("System, Rmax/Rpeak")
	for system in name_to_eff_past_10_nov_top10:
		print(f'{system}, {name_to_eff_past_10_nov_top10[system]}')
	
if __name__ == '__main__':
	main()
	
	
