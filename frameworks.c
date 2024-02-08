// Framework for CRUDS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LENGTH_OF_SHOW_MENU_OPTION 100
#define LENGTH_OF_FIELD_NAME 20
#define LENGTH_OF_FIELD_DATA 40
#define DOMAIN_DATA_FILE "StudentsDetailsOfTecnics.dat"
#define FIELDS_DATA_FILE "Fields.cfg"
#define MENU_DATA_FILE "Menu.cfg"

FILE *fpDomainDataFile;
FILE *fpFieldDataFile; 

void Create();
void ShowMenu();
// void ShowAllRecords();
int GetChoice();

void main()
{
while(1)
{
ShowMenu();
}
}

void Create()
{
char FieldName[LENGTH_OF_FIELD_NAME];

fpFieldDataFile = fopen(FIELDS_NAMES_DATA_FILE, "r");

if (fpFieldDataFile != NULL)
{
fpDomainDataFile = fopen(DOMAIN_DATA_FILE, "a");

int LengthOfFieldName;

while (!feof(fpFieldDataFile))
{
char UserInput[LENGTH_OF_FIELD_DATA];

fgets(FieldName, LENGTH_OF_FIELD_NAME, fpFieldDataFile);

LengthOfFieldName = strlen(FieldName);

if (FieldName[LengthOfFieldName - 1] == '\n')
{
FieldName[LengthOfFieldName - 1] = '\0';
}

printf("Enter %s: ", FieldName);
scanf(" %[^\n]s", UserInput);

fputs(UserInput, fpDomainDataFile);
}

fclose(fpFieldDataFile);
}
}

int GetChoice()
{
int Choice;

printf("Enter your choice: ");
scanf("%d", &Choice);

return Choice;
}

void ShowMenu()
{
char OptionName[LENGTH_OF_SHOW_MENU_OPTION];

fpShowMenuData = fopen(SHOW_MENU_DATA_FILE, "r");

while (!feof(fpShowMenuData))
{
fgets(OptionName, LENGTH_OF_SHOW_MENU_OPTION, fpShowMenuData);

printf("%s", OptionName);
}

fclose(fpShowMenuData);

switch(GetChoice())
{
case 1: Create();
break;

// case 2: ShowAllRecords();
// break;

// case 3: Update();
// break;

// case 4: Delete();
// break;

// case 5: Search();
// break;

case 6: exit(0);

default: printf("\nEntered invalid choice.\n");
}
}

// void ShowAllRecords()
// {

// }
