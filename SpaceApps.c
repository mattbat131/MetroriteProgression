#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Meteorite 
{
    const char * name;
    float geoX;
    float geoY;
    int date;
    const char *map[75];	
};

void printHelp();
void listMet();
void getMet(char args[], char name[]);
int metExists(char name[]);

struct Meteorite met;

int main (int argc, char *argv[])
{   
    if (argc <= 1)		
        printHelp();
    else 
    {
        if (strcmp(argv[1], "-list") == 0)
            listMet();
	else if (strcmp(argv[1], "-h") == 0)
            printHelp();
        else if (argv[1][0] == '-')
        {
            if (argc < 3) 
                printf("Missing meteorite name.\nUse SpaceApps -list to check meteorites.\n");
	    else if (metExists(argv[2]) == 1)
	        getMet(argv[1], argv[2]);
            else
                printf("Meteorite does not exist.\nUse SpaceApps -list to check meteorites.\n");
        }
    }
    return 0;
}


void printHelp() 
{
    char c;
    FILE *file;
    file = fopen("help.txt", "r");
    if (file)
    {
        while ((c  = getc(file)) != EOF)
            putchar(c);
        fclose(file);
    }
    printf("\n");
}

void listMet()
{
    system("python3.4 meteorite.py list");
}

void getMet(char args[], char name[])
{
   FILE *file;
   file = fopen("datafile.txt", "r");

   char ignore[1024];  

   char *temp;   

   met.name = name;
   fscanf(file, "%s %d %f %f", ignore, &met.date, &met.geoX, &met.geoY);
}

int metExists(char name[])
{
    const char* command = "python3.4 meteorite.py ";
    const char* n = name;

    char* pyCommand;
    pyCommand = malloc(strlen(command)+strlen(n)+2);
    strcpy(pyCommand, command);
    strcat(pyCommand, n);
    system(pyCommand);
    int * bool;
    FILE * file = fopen("datafile.txt", "r");
    if (fscanf(file, "%d", bool) == 1) 
    {
        fclose(file);
        return 1;
    }
    fclose(file);
    return 0; 
    
}
