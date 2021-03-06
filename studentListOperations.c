#include<stdio.h>
#include<stdint.h>

#include "studentListOperations.h"


int checkEmpty()
{
    FILE* fileCheck = fopen(SOURCE, "r");
    int exitValue = 0;
    int check = fgetc(fileCheck);
    if (check == EOF)
    {
        exitValue = 1;
    }
    else
    {
        exitValue = 0;
    }
    return exitValue;
    fclose(fileCheck);
}

void printList()
{
    FILE* filePrint = fopen(SOURCE, "r");
    char buffer [STUDENT_SIZE];

    while(!feof(filePrint))
    {
        if(fgets(buffer, STUDENT_SIZE, filePrint) != NULL);
        {
            printf ("%s", buffer);
        }
    }
    fclose(filePrint);
}

void addStudent()
{
    FILE* fileAdd = fopen(SOURCE, "a");
    int n = 0;
    printf ("How many student do you want to add?\n");
    scanf ("%d", &n);
    printf ("Enter students' informations:\n");
    int k = 0;
    
    while(k < n)
    {
        printf ("Student %d:\n", k+1);
        printf ("\tID: ");
        scanf ("%hhd", &student[k].id);
        while(getchar() != '\n');

        printf ("\tName: ");
        scanf ("%[^\n]s", &student[k].name);
        while(getchar() != '\n');

        printf ("\tHome land: ");
        scanf ("%[^\n]s", &student[k].home);
        while(getchar() != '\n');

        printf ("\tScore: ");
        scanf ("%f", &student[k].score);
        while(getchar() != '\n');
        
        fseek(fileAdd, k * STUDENT_SIZE, SEEK_CUR);
        fprintf(fileAdd, "%-3d%-30s%-15s%-4.1f\n", student[k].id, student[k].name, student[k].home, student[k].score);
        k = k + 1;
    }
    fclose(fileAdd);
}
