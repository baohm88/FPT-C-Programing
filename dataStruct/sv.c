#include <stdio.h>
#include<string.h>


struct Student {
    char name[50];
    int age;
    char address[50];
};

typedef struct Student STD;


void getStudentInfo(struct Student students[], int numOfStudents);
void printStudentInfo(struct Student students[], int numOfStudents);
int findStudentName(struct Student students[], int numOfStudents, char studentName[]);
void printUpdatedStudentInfo(struct Student students[], int index);

int main() {
    int numOfStudents, index, userChoice, newAge;
    char studentName[50], newName[50], newAddress[50];

    printf("\nNumber of students: ");
    scanf("%d", &numOfStudents);


    STD students[numOfStudents];

    getStudentInfo(students, numOfStudents);
    printStudentInfo(students, numOfStudents);

    // Get student name to search for
    printf("\nEnter name to search for: ");
    scanf("%s", studentName);

    index = findStudentName(students, numOfStudents, studentName);

    if (index)
    {
        printf("\nFound %s at index #%d\n", studentName, index);
    }
    else
    {
        printf("\nStudent %s is not found.\n", studentName);
    }

    // Get name to edit
    printf("\nEnter name to edit: ");
    scanf("%s", studentName);
    
    index = findStudentName(students, numOfStudents, studentName);

    if (index)
    {
        printf("\nFound %s at index #%d\n", studentName, index);
        do
        {
            
            printf("\nWhat info do you want to change?\n1: Name\n2: Age\n3: Address\n4: Exit\nYour choice: ");
            scanf("%d", &userChoice);
            if (userChoice < 1 || userChoice > 4)
            {
                printf("\nINVALID INPUT. Please enter a number <= 4 or >= 1.\n");
            }
            
        } while (userChoice < 1 || userChoice > 4);

        switch (userChoice)
            {
            case 1 /* Edit name */:
                printf("\nEnter new name (< 50 characters): ");
                scanf("%s", students[index - 1].name);
                printUpdatedStudentInfo(students, index);
                break;
            
            case 2 /* Edit age */:
                printf("\nEnter new age (> 0): ");
                scanf("%d", &students[index - 1].age);
                printUpdatedStudentInfo(students, index);
                break;
            
            case 3 /* Edit address */:
                printf("\nEnter new address (< 50 characters): ");
                scanf("%s", students[index - 1].address);
                printUpdatedStudentInfo(students, index);
                break;
            
            case 4: 
                printf("\nGOODBYE!!!\n");
                break;

            default: // Invalid input
                printf("Your input is invalid.");
                break;
            }
    }
    else 
    {
        printf("Student %s is not found.\n", studentName);
    }

    
    return 0;
}







void getStudentInfo(struct Student students[], int numOfStudents)
{
    printf("Enter information of students:\n");
    // storing information
    for (int i = 0; i < numOfStudents; ++i) {
        printf("\nFor student #%d:\n", i + 1);
        printf("Name   : ");
        // fgets(students[i].name, 50, stdin);
        scanf("%s", students[i].name);

        printf("Age    : ");
        scanf("%d", &students[i].age);
        
        printf("Address: ");
        // fgets(students[i].address, 50, stdin);
        scanf("%s", students[i].address);
    }
}


void printStudentInfo(struct Student students[], int numOfStudents)
{
    printf("\nDisplaying Information:\n");

    // displaying information
    for (int i = 0; i < numOfStudents; ++i) {
        printf("\nStudent # %d\n", i + 1);
        printf("Name   : %s\n", students[i].name);
        printf("Age    : %d\n", students[i].age);
        printf("Address: %s\n", students[i].address);
    }
}


int findStudentName(struct Student students[], int numOfStudents, char studentName[])
{
    for (int i = 0; i < numOfStudents; i++)
    {
        if (strcmp(students[i].name, studentName) == 0)
        {
            return i + 1;
        }
    }
    return 0;
}


void printUpdatedStudentInfo(struct Student students[], int index)
{
    printf("Updated info for %s: \n", students[index - 1].name);
    printf("Name   : %s\n", students[index - 1].name);
    printf("Age    : %d\n", students[index - 1].age);
    printf("Address: %s\n", students[index - 1].address);
    
}