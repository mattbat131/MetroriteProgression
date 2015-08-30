from io import BytesIO
import json
import pycurl
import sys


def getList(file):
    print([file[index]["name"] for index in range(len(file))])
    #beautify

def getIndex(name, file): 
    for index in range(len(file)):
        if (file[index]["name"] == name):
            return index

#gets meteorite date: returns int
def getDate(name, file):
    year = file[getIndex(name, file)]["year"]
    return year


#gets meteorite location: returns int array
def getLocation(name, file):
    location = file[getIndex(name, file)]["location"]
    return location

def exists(name, file):
    if (getIndex(name, file) == NULL):
        return 0;
    else return 1; 

def getJsonFromUrl(url):
    curl_result = curl(url)
    json_result = json.loads(curl_result, encoding='iso-8859-1')
    return json_result

#gets son file:: returns son
def curl(url):
    buffer=BytesIO()
    c=pycurl.Curl()
    c.setopt(pycurl.URL, url)
    c.setopt(pycurl.WRITEDATA, buffer)
    c.perform()
    c.close()
    body=buffer.getvalue()
    return body.decode('iso-8859-1')

#does the main shit
def main():
    json_file = getJsonFromUrl("https://data.nasa.gov/resource/gh4g-9sfh.json")
    if (sys.argv[1] == "list"):
        getList(json_file)
    elif (sys.argv[1] == "year"):
        getDate(sys.argv[2], json_file)
	#write to data file
    elif (sys.argv[1] == "location"):
        getLocation(sys.argv[2], json_file)
        #write to data file
    elif (sys.argv[1] == “exists”):
        exists(sys.argv[2], json_file)
        #write to exist file

if __name__ == "__main__":
    main()

