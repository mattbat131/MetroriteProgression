from io import BytesIO
import json
import pycurl
import sys


def getList(file):
    print("Name,\trecclass,\tmass(g),\tyear,\treclat,\treclong")
    for index in range(len(file)):
        try:
            print("{0},\t{1},\t{2},\t{3},\t{4},\t{5}".format(file[index]["name"], file[index]["recclass"], file[index]["mass"], file[index]["year"], file[index]["reclat"], file[index]["reclong"])) 
        except: 
            print("{0}".format(file[index]["name"]))


def getIndex(name, file): 
    for index in range(len(file)):
        if (file[index]["name"] == name):
           return index
    return -1

#gets meteorite date: returns int
def getDate(name, file):
    year = file[getIndex(name, file)]["year"]
    return year[:4]

#gets meteorite location: returns int array
def getLocation(name, file):
    location = file[getIndex(name, file)]["geolocation"]
    geoLoc = "{0}, {1}".format(location["latitude"], location["longitude"])
    return geoLoc

def exists(name, file):
    if (getIndex(name, file) == -1):
        return 0
    else:
        return 1 

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
    df=open("datafile.txt",'w')
    if (len(sys.argv) < 2):
        print("To few args")
    elif (sys.argv[1] == "list"):
        getList(json_file)
    elif (sys.argv[1] == "flush"):
        df.flush()
    else:
        if (exists(sys.argv[1], json_file)):
            df.writelines("1")
            df.writelines("\n")
            df.writelines(getDate(sys.argv[1], json_file))
            df.writelines("\n")
            df.writelines(getLocation(sys.argv[1], json_file)) 
        else:
            df.writelines("0")
            print("Meteor doesn't exist")
        #write to exist file
    df.close()

if __name__ == "__main__":
    main()
