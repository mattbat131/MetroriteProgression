import os, fnmatch
import sys
from ftplib import FTP

def find(files, pattern='"{0}_{1}".format(sys.argv[index], date)'):
    matchedFiles = []
    
    for filename in files:
         if re.match(pattern, filename):
             matcheFiles.append(filename)

    return matchedFiles


def main():
    length = len(sys.argv)
    y = sys.argv[length - 1]
    x = sys.argv[length - 2]
    date = sys.argv[length - 3]
    
    maps = list()
    for index in range(length - 4):
        ftp = FTP('ftp://neoftp.sci.gsfc.nasa.gov/rgb/{0}/'.format(sys.argv[index]))
        files = ftp.nlst() 
        maps[index] = find(files)
    print(maps)


if __name__ == "__main__":
    main()


