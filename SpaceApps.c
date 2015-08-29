#include <stdio.h>
#include <string.h>

void printHelp();
void listMet();
void checkArgs(char * args[], struct Meteorite);

struct Meteorite 
{
    char name[50];
    float geoX;
    float geoY;
    int mapId;	
} meteorite;


int main (int argc, char * argv[])
{
    struct Meteorite meteorite;
    if (argc < 2)		
        printHelp();
    else 
    {
        if (strcmpr(argv[1], "-list") == 0)
            listMet();
        else if (argv[1].charAt(0) == '-')
        {
	    checkArgs(argv[1], meteorite);
        }
    }
}
