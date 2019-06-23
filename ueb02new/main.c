#include <stdio.h>
#include "datastructure.h"
#include "datetime/datetime.h"
#include "tools/tools.h"
#include <stdlib.h>
#include <string.h>
#include "calendar/calendar.h"
#include "database/database.h"

TAppointment Calendar[MAX_APPOINTMENTS];
int countAppointments = 0;

int main()
{

    int Select;                            //Menuewahl
    char *Menu[8];                           //Hauptmenue Strings
    *Menu = "Terminverwaltung V 0.3\n";
    *(Menu+1) = "Neuen Termin anlegen\n";
    *(Menu+2) = "Termin bearbeiten\n";
    *(Menu+3) = "Termin loeschen\n";
    *(Menu+4) = "Termin suchen\n";
    *(Menu+5) = "Termine sortieren\n";
    *(Menu+6) = "Termine auflisten\n";
    *(Menu+7) = "Programm beenden\n";

    //loadCalendar();
        int firstload = 1;
    do
    {
        //Input
        int checkInput=1;
        do
        {
            //MenuAusgabe
            clearScreen();
            if(firstload){
                if(loadCalendar()){
                 printf("Datenbank konnte geladen werden");
                 firstload = 0;
                 }
                 else{
                 if (!firstload)
                 printf("Datenbank konnte nicht geladen werden");
                 }
            }
            getMenu(Menu);

            if(!checkInput)
                printf("\nFalsche Eingabe. Bitte erneut waehlen: ");

            checkInput = scanf("%i", &Select);
            clearBuffer();
            if(Select<1 || Select>7)
                checkInput = 0;
        } while (!checkInput);


        printf("Ihre Wahl: %i\n", Select);
        printf("ToDo: %s", Menu[Select]);


        switch (Select) {
            case 1:
                createAppointment(Menu[Select]);
                break;
            case 2:
                editAppointment(Menu[Select]);
                break;
            case 3:
                deleteAppointment(Menu[Select]);
                break;
            case 4:
                searchAppointment(Menu[Select]);
                break;
            case 5:
                sortCalendar(Menu[Select]);
                break;
            case 6:
                listCalendar();
                break;
        }
    } while (Select != 7);
    
    saveCalendar();
    freeCalendar();
   return 0;
}
