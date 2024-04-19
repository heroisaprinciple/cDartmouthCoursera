/**
 * Your current task is to write a function freeStudents() which takes as input a pointer
 * that holds the address of the start of a linked list of students.
 * Your function should then free the space allocated for each student
 * in this list of students. Your function should not return anything.
 */

#include <stdio.h>
#include <stdlib.h>

struct student {
    char name[50];
    int age;
    struct student *next;
};

struct student *createStudent(char studentName[], int studentAge);
struct student *append(struct student * end, struct student * newStudptr);
void printStudents(struct student * start);
void freeStudents(struct student * start);

int main(void) {
    struct student *start, *newStudptr, *end;
    int ageP, ageR, ageM;

    scanf("%d %d %d", &ageP, &ageR, &ageM);

    start = createStudent("Petra", ageP);
    end = start;
    newStudptr = createStudent("Remi", ageR);
    end = append(end, newStudptr);
    newStudptr = createStudent("Mike", ageM);
    end = append(end, newStudptr);

    printStudents(start);
    freeStudents(start);

    return 0;
}

struct student * createStudent(char studentName[], int studentAge) {
    int i = 0;
    struct student * data = (struct student *)malloc(sizeof(struct student));

    while (studentName[i] != '\0') {
        data->name[i] = studentName[i];
        i++;
    }
    data->name[i] = '\0';
    data->age = studentAge;
    data->next = NULL;
    return data;
}

struct student * append(struct student * end, struct student * newStudptr) {
    end->next = newStudptr;
    end = newStudptr;
    return end;
}

void printStudents(struct student *  start) {
    struct student * ptr = start;
    while (ptr != NULL) {
        printf("%s is %d years old.\n", ptr->name, ptr->age);
        ptr = ptr->next;
    }
}

void freeStudents(struct student * start) {
    struct student * ptr = start;
    struct student * tmp;
    while (ptr != NULL) {
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}
