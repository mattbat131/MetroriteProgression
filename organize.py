import os, fnmatch
import sys
from ftplib import FTP

def find(files, name, date):
    matchedFiles = []
    
    for filename in files:
         if name+'_'+date in filename:
             matchedFiles.append(filename)

    return matchedFiles


def main():
    length = len(sys.argv)
    name = sys.argv[length - 1]
    y = sys.argv[length - 2]
    x = sys.argv[length - 3]
    date = sys.argv[length - 4]
 
    ftp = FTP('neoftp.sci.gsfc.nasa.gov')
    ftp.login()
    maps = []
    for index in range(length - 5):
        files = ftp.nlst('/rgb/{0}'.format(sys.argv[index+1]))
        maps.append(find(files, sys.argv[index+1], date))
    
    file = open("meteoritedata.txt", "w")
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


