#ifndef STUDENT_LIST_H
#define STUDENT_LIST_H

#define NAME_LEN 30
#define MAX_STUDENTS 50
#define HOME_LEN 15
#define SOURCE "studentList.txt"
#define STUDENT_SIZE 52

#define COL1 "ID"
#define COL2 "Name"
#define COL3 "Home land"
#define COL4 "Score"

struct classList
{
    uint8_t id;
    char name[NAME_LEN];
    char home[HOME_LEN];
    float score;
}student;

int checkEmpty(FILE* filePtr);
void printList(FILE* filePtr);
void addStudent(FILE* filePtr);


#endif