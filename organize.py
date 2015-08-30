import os, fnmatch
import sys
from ftplib import FTP

def find(files, pattern):
    matchedFiles = []
    
    for filename in files:
         if re.match(pattern, filename):
             matcheFiles.append(filename)

    return matchedFiles


def main():
    length = len(sys.argv)
    name = sys.argv[length - 1]
    y = sys.argv[length - 2]
    x = sys.argv[length - 3]
    date = sys.argv[length - 4]
    
    maps = list()
    for index in range(length - 5):
        print('ftp://neoftp.sci.gsfc.nasa.gov/rgb/{0}/'.format(sys.argv[index+1]))
        ftp = FTP('ftp://neoftp.sci.gsfc.nasa.gov/rgb/{0}/'.format(sys.argv[index+1]))
        files = ftp.nlst() 
        maps[index] = find(files, "{0}_{1}".format(sys.argv[index], date))
    print(maps)
    
    file = open("meteoritedata.txt" "w")
    file.writelines(name)
    file.writelines("\n")
    file.writelines(x);
    file.writelines("\n")
    file.writelines(y)
    file.writelines("\n")
    file.writelines(date)
    file.writelines("\n")

    for index in range(len(maps)):
        file.writelines(maps[index])
        file.writeline("\n")

if __name__ == "__main__":
    main()


