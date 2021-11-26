#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Task 05: Simple student management

char placeholder[1024];

void ogets (char *pointer, int length) {
    fgets(pointer, length, stdin);
    if (pointer[strlen(pointer) - 1] == '\n') pointer[strlen(pointer) - 1] = '\0';
}

struct student {
    char name[1024];
    char id[15];
    unsigned int age;
    double English;
    double Science;
    double Mathematics;
};

struct studentStatistics {
    int excellent;
    int veryWell;
    int soSo;
    int normal;
    int failed;
};

double getAverageScore (struct student student) {return (student.Mathematics + student.Science + student.English) / 3;}

struct database{
    struct student studentList[100];
    int count;
} studentDataBase;

void sortList (struct database *database);

void addStudent(struct database *database) {
    if (database->count == 100) {
        printf("Database full.\n");
        return;
    }
    char *namep = malloc(1025 * sizeof(char));
    do {
        fflush(stdin);
        printf("Input the name of students: ");
        ogets(namep, 1024);
    } while (strlen(namep) == 0);
    char name[1024];
    strcpy(name, namep);
    free(namep);
    char *studentIdp = malloc(16 * sizeof(char));
    int isHas = 0;
    do {
        isHas = 0;
        printf("Input the ID of students: ");
        ogets(studentIdp, 15);
        for (int i = 0; i < database->count; ++i) {
            if (strcmp(database->studentList[i].id, studentIdp) == 0) {
                printf("There is already a student with the ID %s!\n", studentIdp);
                isHas = 1;
            }
        }
    } while (strlen(studentIdp) == 0 || isHas == 1);
    char studentId[15];
    strcpy(studentId, studentIdp);
    free(studentIdp);
    unsigned int age;
    do {
        printf("Input the age of the student: ");
    } while (scanf("%d", &age) != 1 || age <= 0);
    fflush(stdin);
    double score[3];
    do {
        printf("Enter scores of the student, with the format English, Science, Mathematics: ");
    } while (!(scanf("%lf, %lf, %lf", &score[0], &score[1], &score[2]) == 3 &&
    score[0] >= 0 && score[1] >= 0 && score[2] >= 0));
    strcpy(database->studentList[database->count].name, name);
    strcpy(database->studentList[database->count].id, studentId);
    database->studentList[database->count].age = age;
    database->studentList[database->count].English = score[0];
    database->studentList[database->count].Science = score[1];
    database->studentList[database->count].Mathematics = score[2];
    database->count ++;
    sortList(database);
    printf("Successfully added %s.\n\n", name);
}

void sortList (struct database *database) {
    for (int i = 0; i < database->count; ++i) {
        for (int j = i; j < database->count; ++j) {
            if (getAverageScore(database->studentList[i]) < getAverageScore(database->studentList[j])) {
                struct student swap = database->studentList[i];
                database->studentList[i] = database->studentList[j];
                database->studentList[j] = swap;
            }
        }
    }
}

void deteleStudent (struct database *database) {
    if (database->count == 0) {printf("Nothing to delete!\n"); return;}
    char *id = malloc(16 * sizeof(char));
    printf("Input the student ID: ");
    int pos = -1;
    fflush(stdin);
    ogets(id, 15);
    for (int i = 0; i < database->count; ++i) {
        if (strcmp(id, database->studentList[i].id) == 0) {
            pos = i;
        }
    }
    if (pos != -1) {
        printf("Do you wanna delete the student %s?\n"
               "Press 1 to confirm, press 2 to cancel.\n", database->studentList[pos].name);
        int choice = 0;
        do {
            printf("Choice: ");
            scanf("%d", &choice);
            fflush(stdin);
        } while (choice < 1 || choice > 2);
        if (choice == 1) {
            // Delete the current item.
            for (int i = pos; i < database->count - 1; ++i) {
                database->studentList[i] = database->studentList[i + 1];
            }
            database->count --;
            printf("Deleted.\n");
        } else {
            printf("Cancelled.\n");
        }
    }
}

void printList (struct database database) {
    for (int i = 0; i < database.count; ++i) {
        printf("%s, ID: %s, age: %u, Eng: %.1lf, Sci: %.1lf, MatL %.1lf\n", database.studentList[i].name,
               database.studentList[i].id, database.studentList[i].age, database.studentList[i].English,
               database.studentList[i].Science, database.studentList[i].Mathematics);
    }
}

int main() {
    int main_choice;
    studentDataBase.count = 0;
    do {
        struct studentStatistics stat;
        stat.failed = stat.normal = stat.soSo = stat.veryWell = stat.excellent = 0;
        for (int i = 0; i < studentDataBase.count; ++i) {
            double averageScore = getAverageScore(studentDataBase.studentList[i]);
            if (averageScore >= 90) {
                stat.excellent ++;
            } else if (averageScore >= 80 && averageScore < 90){
                stat.veryWell ++;
            } else if (averageScore >= 70 && averageScore < 80) {
                stat.soSo ++;
            } else if (averageScore >= 60 && averageScore < 70) {
                stat.normal ++;
            } else {
                stat.failed ++;
            }
        }
        printf("==== Student Score Management System (Simplified) ====\n"
               "Current Database Capacity: %d\n"
               "Student distribution:\n"
               "Excellent (90-100): %d, "
               "Very Well (80-90): %d, "
               "So-so (70-80): %d, "
               "Normal (60-70): %d, "
               "Failed (0-60): %d.\n"
               "\n"
               "1. Add a student\n"
               "2. Delete a student\n"
               "3. Search a student\n"
               "4. Print all students\n"
               "5. Exit\n"
               "\n"
               "Enter your choice: ", studentDataBase.count, stat.excellent, stat.veryWell, stat.soSo, stat.normal, stat.failed);
        while (!(scanf("%d", &main_choice) == 1 && main_choice >= 1 && main_choice <= 5)) {
            printf("Invalid input, please try again: ");
        }
        switch (main_choice) {
            case 1:
                addStudent(&studentDataBase);
                break;

            case 2:
                deteleStudent(&studentDataBase);
                break;

            case 4:
                printList(studentDataBase);
                break;
        }
    } while (main_choice != 5);
    printf("Have a nice day, good bye!");
}
