#include<stdio.h>
#include<stdint.h>

#include "studentListOperations.h"
/*
One students occupies 52 byte in file
ID = 3byte, name = 30byte, home = 15byte, score = 4
*/

int main()
{
    uint8_t choice;
    int ask = 0;
    int repeat = 0;
    //char source[50];
    
    printf ("\nSTUDENT MANAGEMENT PROGRAM\n\n");
    
    FILE* fp = fopen(SOURCE, "r");

    if (fp == NULL)
    {
        printf ("ERROR WITH FILE.\n");
        printf ("CREATING FILE...\n");
        //fclose (fp);
        FILE* fp = fopen(SOURCE, "w");
        fclose(fp);
        printf ("\nFILE CREATED.\n\n");
    }
    
    do 
    {   
        repeat = 0;
        printf ("\nPlease select your option:\n1. Printf Students' list\n2. Add Students\n");
        scanf ("%hhd", &choice);
        switch(choice)
        {
            case 1:
                
                if (checkEmpty() == 1)
                {
                    printf ("\n!File is empty!\nPlease add contents to the file\n\n");
                    getchar();
                }
                else if (checkEmpty() == 0)
                {
                    printf ("\nCLASS LIST\n\n");
                    printf ("%-3s%-30s%-15s%4s\n", COL1, COL2, COL3, COL4);
                    printList();
                }
                
            break;
            case 2:
                addStudent();
            break;
        }
        printf ("\n\nDo you want to continue or exit the program?\n1. Continue\n0. Exit\nYour choice: ");
        scanf("%d", &ask);
        if (ask == 1)
        {
            repeat = 1;
        }
    }
    while(repeat == 1);
    //fclose(fp);
    return 0;
}


