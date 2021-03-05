#include<stdio.h>
#include<stdbool.h>
#include<stdint.h>
#include "studentListOperations.h"
/*
One students occupies 52 byte in file
ID = 3byte, name = 30byte, home = 15byte, score = 4
*/

int main()
{
    int order;
    uint8_t choice;
    bool ask = 0;
    bool repeat = 0;

    FILE* fp = fopen(SOURCE, "r+");

    if (fp == NULL)
    {
        printf ("ERROR WITH FILE.\n");
    }

    printf ("STUDENT MANAGEMENT PROGRAM\n");
    do 
    {   
        
        repeat = 0;
        printf ("Please select your option:\n1. Printf Students' list\n2. Add Students\n");
        scanf ("%hhd", &choice);
        switch(choice)
        {
            case 1:
                if (checkEmpty(fp) == 1)
                {
                    printf ("File is empty.\n");
                }
                else if (checkEmpty(fp) == 0)
                {
                    printf ("%-3s%-30s%-15s%4s\n", COL1, COL2, COL3, COL4);
                    printList(fp);
                }
            break;
            case 2:
                addStudent(fp);
            break;
        }
        printf ("Do you want to continue?\n1. Yes\n0. No\n");
        scanf("%d", &ask);
        if (ask == 1)
        {
            repeat = 1;
        }
    }
    while(repeat == 1);
    fclose(fp);
    return 0;
}

