#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include "studentListOperations.h"


int checkEmpty(FILE* filePtr)
{
    int check = fgetc(filePtr);
    if (check == EOF)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void printList(FILE* filePtr)
{
    char buffer [STUDENT_SIZE];
    while(!feof(filePtr))
    {
        if (fgets(buffer, STUDENT_SIZE, filePtr) != NULL);
        {
            printf ("%s\n", buffer);
        }
    }
}

void addStudent(FILE* filePtr)
{
    int n = 0;
    printf ("How namy student do you want to add?\n");
    scanf ("%d", &n);
    printf ("Enter students' informations\n");
    int k = 0;
    while(k < n)
    {
        printf ("Student %d:\n", k+1);
        printf ("\tID: ");
        scanf ("%hhd", &student.id);
        while(getchar() != '\n');

        printf ("\tName: ");
        scanf ("%[^\n]s", &student.name);
        while(getchar() != '\n');

        printf ("\tHome land: ");
        scanf ("%[^\n]s", &student.home);
        while(getchar() != '\n');

        printf ("\tScore: ");
        scanf ("%f", &student.score);
        while(getchar() != '\n');
        
        fseek(filePtr, k * STUDENT_SIZE, SEEK_END);
        fprintf(filePtr, "\n%-3d%-30s%-15s%-4.1f", student.id, student.name, student.home, student.score);
        k = k + 1;
    }
}