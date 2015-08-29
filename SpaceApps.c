#include <stdio.h>
#include <string.h>

struct Meteorite 
{
    char name[50];
    float geoX;
    float geoY;
    const char *map[75];	
};

void printHelp();
void listMet();
void getMet(char * args[], struct Meteorite *met);
int metExists(char * name[]);


int main (int argc, char *argv[])
{
    printf("%d",argc);
    struct Meteorite met;
    
    if (argc == 0)		
        printHelp();
    else 
    {
        if (strcmp(argv[1], "-list") == 0)
            listMet();
        else if (argv[1][0] == '-')
        {
	    if (metExists(&argv[2]))
	        getMet(&argv[1], &met);
            else
                printf("Meteorite does not exist.\nUse SpaceApps -list {date} to check meteorites at the time.");
        }
    }
    return 0;
}


void printHelp() 
{
    printf("usage: SpaceApps -[map] meteorite\nSpaceApps -list {date}\n");
    printf("-aOT: Aerosol Optical Thickness\n");
   
}

void listMet()
{
    printf("list");
}

void getMet(char * args[], struct Meteorite *met)
{
   printf("Hi");
}

int metExists(char * name[])
{
    return 0;
}
