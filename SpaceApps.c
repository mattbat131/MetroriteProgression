#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Python.h>
#include <wchar.h>

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
    struct Meteorite met;
    
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
    FILE* file;
    int py_argc;
    wchar_t * py_argv[2];

    py_argc = 2;
    py_argv[0] = L"meteorite.py";
    py_argv[1] = L"list";

    Py_SetProgramName(py_argv[0]);
    Py_Initialize();
    Py_Main(py_argc, py_argv);
    file = fopen("meteorite.py", "r");
    PyRun_SimpleFile(file, "meteorite.py");
    Py_Finalize();
}

void getMet(char * args[], struct Meteorite *met)
{
   printf("Hi");
}

int metExists(char * name[])
{
    return 0;
}
