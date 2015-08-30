#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Meteorite 
{
    const char * name;
    float geoX;
    float geoY;
    int date;
    const char *map[50];	
};

void printHelp();
void listMet();
void getMet(char * args[], int argc, char name[]);
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
            if (argv[argc - 1][0] == '-') 
                printf("Missing meteorite name.\nUse SpaceApps -list to check meteorites.\n");
	    else if (metExists(argv[argc - 1]) == 1)
            {
                char ** maps = calloc(argc - 1, sizeof(char *));
                int i = 1;
                for (i = 1; i < argc - 1; i++)
                {
                    maps[i-1] = malloc(strlen(argv[i]));
                    memcpy(maps[i-1], argv[i], strlen(argv[i]));
                }	        
                getMet(maps, argc - 1, argv[argc - 1]);
            }
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
    exit(1);
}

void listMet()
{
    system("python3.4 meteorite.py list");
}

void getMet(char * args[], int argc, char name[])
{
   int index = 0;
   char * map;
   for (index = 0; index < argc - 1; index++)
   {
       map = args[index];
       
       if(strcmp(map, "-aOT") == 0)
           met.map[index] = "";
           
       if(strcmp(map, "-aPR") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-cM") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-cF") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-cOT") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-cPR") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-cWC") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-fCM") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-nD") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-oZ") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-rF") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-tCM") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-tCV") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-wV") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-aB") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-aLD") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-aLT") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-aST") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-gTA") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-lAD") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-lAN") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-lTD") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-lTN") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-nR") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-oLR") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-rSR") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-sTA") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-sTW") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-sTO") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-sAA") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-sL") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-uVI") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-aF") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-bMG") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-lCC") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-lAI") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-nPP") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-pF") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-sNH") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-sEG") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-sC") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-sWE") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-tG") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-vI") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-wEA") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-cC") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-pP") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-bA") == 0)
           met.map[index] = "";
           
       if(strcmp(map,  "-sSS") == 0)
           met.map[index] = "";
           
       if(map == NULL)
           printHelp();
   }

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
