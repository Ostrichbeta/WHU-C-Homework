#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//Task 14: Advanced student management

bool autoSave = false;
char placeholder[1024];

char filepath[] = "student.txt";

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
    struct student *studentList;
    int count;
} studentDataBase;

void sortList (struct database *database);

void addStudent(struct database *database) {
    if (database->count == 50) {
        printf("Database full.\n\n");
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
    database->studentList = realloc(database->studentList, (database->count + 1) * sizeof(struct student));
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
    if (database->count == 0) {printf("Nothing to delete!\n\n"); return;}
    char *id = malloc(16 * sizeof(char));
    //printf("Input the student ID: ");
    int pos = -1;
    printf("Input the student's identity in the print list (not the student ID!): ");
    while (!(scanf("%d", &pos) == 1 && pos >= 1 && pos <= database->count)) {
        printf("Invalid input, please try again: ");
    }
    //fflush(stdin);
    //ogets(id, 15);
    //for (int i = 0; i < database->count; ++i) {
    //    if (strcmp(id, database->studentList[i].id) == 0) {
    //        pos = i;
    //    }
    //}
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
            if (database->count != 0) {
                database->studentList = realloc(database->studentList, (database->count) * sizeof(struct student));
            }
            printf("Deleted.\n\n");
        } else {
            printf("Cancelled.\n\n");
        }
    }
}

void printList (struct database database) {
    for (int i = 0; i < database.count; ++i) {
        printf("[No. %d]%s, ID: %s, age: %u, Eng: %.1lf, Sci: %.1lf, Mat: %.1lf, Average: %.1lf, Total score: %.1lf\n", i + 1, database.studentList[i].name,
               database.studentList[i].id, database.studentList[i].age, database.studentList[i].English,
               database.studentList[i].Science, database.studentList[i].Mathematics,
               getAverageScore(database.studentList[i]),
               database.studentList[i].English + database.studentList[i].Science + database.studentList[i].Mathematics);
    }
    printf("\n\n");
}

struct database openAndCheckFile(char *filename) {
    FILE * filePointer;
    filePointer = fopen(filename, "r");
    struct database data;
    if (filePointer == NULL) {
        printf("File not exist, create one.\n");
        fclose(filePointer);
        filePointer = fopen(filename, "w");
        if (filePointer == NULL) {
            autoSave = false;
            printf("Could not write file, the auto-save feature will be disabled!\n");
        }
        fclose(filePointer);
        data.count = 0;
        data.studentList = malloc(1);
        return data;
    } else {
        autoSave = true;
        if (fgetc(filePointer) == EOF) {
            data.count = 0;
            data.studentList = malloc(1);
            return data;
        } // Empty file
        char *str = malloc(1);
        unsigned int str_len = 0;
        fseek(filePointer, 0, SEEK_SET);
        char ch;
        do {
            ch = fgetc(filePointer);
            if (ch == EOF) break;
            str_len ++;
            str = realloc(str, (str_len + 1) * sizeof(char));
            str[str_len - 1] = ch;
        } while (ch != EOF);
        // The length will be store in the first line
        // First cut the whole file
        int enterCount = 0;
        for (int i = 0; i < strlen(str); ++i) {
            if (str[i] == '\n') enterCount ++;
        }
        char *countStr = malloc(5);
        strcpy(countStr, str);
        countStr = strtok(countStr, "\n");
        int count = 0;
        sscanf(countStr, "%d", &count);
        data.count = count;
        if (count == 0) {
            data.count = 0;
            data.studentList = malloc(1);
            return data;
        } else {
            // If there is some data, then read them from the file.
            // The format is Name\tID\tAge\tEnglish\tScience\tEnglish
            data.studentList = malloc(count * sizeof(struct student));
            char *remain;
            char *currentData = strtok_r(str, "\n", &remain);
            int i = 0;
            while (currentData != NULL) {
                if (i >= count) break;
                printf("Reading (%d/%d)... ", i + 1, count);
                fflush(stdout);
                currentData = strtok_r(remain, "\n", &remain);
                if (currentData == NULL) break;
                char *line = malloc(2049 * sizeof(char));
                sscanf(currentData, "%[^\n]s", line);
                line = strtok(line, "\t");
                strcpy(data.studentList[i].name, line);
                line = strtok(NULL, "\t");
                strcpy(data.studentList[i].id, line);
                line = strtok(NULL, "\t");
                sscanf(line, "%i", &data.studentList[i].age);
                line = strtok(NULL, "\t");
                sscanf(line, "%lf", &data.studentList[i].English);
                line = strtok(NULL, "\t");
                sscanf(line, "%lf", &data.studentList[i].Science);
                line = strtok(NULL, "\t");
                sscanf(line, "%lf", &data.studentList[i].Mathematics);
                //sscanf(currentData, "%s\t%s\t%i\t%lf\t%lf\t%lf",
                //       data.studentList[i].name, data.studentList[i].id, &data.studentList[i].age,
                //       &data.studentList[i].English, &data.studentList[i].Science, &data.studentList[i].Mathematics);
                i ++;
                printf("Done.\n");
                fflush(stdout);
            }
            return data;
        }
    }

}

bool saveFile(char *filename, struct database data) {
    FILE * filePointer = fopen(filename, "w");
    if (filePointer == NULL) return false;
    if (data.count == 0) {
        fprintf(filePointer, "%d\n", data.count);
        fclose(filePointer);
        return true;
    } else {
        fprintf(filePointer, "%d", data.count);
        for (int i = 0; i < data.count; ++i) {
            fprintf(filePointer, "\n%s\t%s\t%i\t%lf\t%lf\t%lf",
                    data.studentList[i].name, data.studentList[i].id, data.studentList[i].age,
                    data.studentList[i].English, data.studentList[i].Science, data.studentList[i].Mathematics);
        }
        fclose(filePointer);
        printf("File saved.\n");
        return true;
    }
}

void searchStudent (struct database data) {
    char pattern[15];
    do {
        printf("Search by student ID: ");
        ogets(pattern, 15);
    } while (strlen(pattern) == 0);
    int pos = -1;
    for (int i = 0; i < data.count; ++i) {
        if (strcmp(data.studentList[i].id, pattern) == 0) {
            //Find the result
            pos = i;
            printf("Student ID: %s\n", data.studentList[pos].id);
            printf("Name: %s\n", data.studentList[pos].name);
            printf("Age: %d\n", data.studentList[pos].age);
            printf("English mark: %.2lf\n", data.studentList[pos].English);
            printf("Science mark: %.2lf\n", data.studentList[pos].Science);
            printf("Mathematics mark: %.2lf\n", data.studentList[pos].Mathematics);
        }
    }
    if (pos == -1) {
        printf("Student not found.\n\n");
        return;
    }
}

int main() {
    int main_choice;
    studentDataBase.count = 0;
    studentDataBase = openAndCheckFile(filepath);
    // Read the file
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
        printf("==== Student Score Management System Ultimate Version ====\n"
               "Current Database Capacity: %d\n"
               "Student distribution:\n"
               "Excellent (90-100): %d, "
               "Very Well (80-90): %d, "
               "So-so (70-80): %d, "
               "Normal (60-70): %d, "
               "Failed (0-60): %d.\n"
               "\n"
               "1. Print all students\n"
               "2. Add a student\n"
               "3. Delete a student\n"
               "4. Search a student\n"
               "(This program includes an auto-save feature,\n"
               "so no save choice is presented.)\n"
               "5. Exit\n"
               "\n"
               "Enter your choice: ", studentDataBase.count, stat.excellent, stat.veryWell, stat.soSo, stat.normal, stat.failed);
        while (!(scanf("%d", &main_choice) == 1 && main_choice >= 1 && main_choice <= 5)) {
            printf("Invalid input, please try again: ");
        }
        printf("\n");
        switch (main_choice) {
            case 2:
                addStudent(&studentDataBase);
                if (autoSave) {
                    saveFile(filepath, studentDataBase);
                }
                break;

            case 3:
                deteleStudent(&studentDataBase);
                if (autoSave) {
                    saveFile(filepath, studentDataBase);
                }
                break;

            case 1:
                printList(studentDataBase);
                break;

            case 4:
                searchStudent(studentDataBase);
                break;

            case 5:
                break;
            default:
                printf("????\n");
                break;
        }
    } while (main_choice != 5);
    printf("Have a nice day, good bye!");
}
