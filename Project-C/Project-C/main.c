//
//  main.c
//  MainMenu
//
//  Created by Rainer Oktovianus on 2/5/17.
//  Copyright © 2017 Rainer Oktovianus. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

///////////////////////////////////* forward declarations *///////////////////////////////////
char firstChar(char* line);
int strLength(char* line);
char* substring(char* line, int startIndex, int endIndex);
int getTheStartIndex(char* filename, char firstChar);
char** splitString(char* a_str, const char a_delim, int* numberOfComponents);
char** readFile(char* fileAddress, int* numberOfLines);
int numberOfItemsPerRecordInFile(char* fileName);
int convertToNumber(char *);

void logInUser();
bool checkPass(char ID [20],char pass [20]);
void showMenuOption (void);
void printListOfStudents(void);
void printEnrolmentCertificate(void);
void printListOfStudents(void);
void printStudentcourses(void);
void printStudentGPA(void);
void printStudentTranscript(void);
void logOut();
void PrintstudentRanking( int numberOfStudentscourses);
float studentGPA(char* sudentID , int numberOfStudentscourses);
void studentinfoByID();

///////////////////////////////////* structs *///////////////////////////////////
struct Student {
    
    char* studentID;
    char* name;
    char* gender;
    int   grade;
    char* address;
    int   admission_year;
    char** courses;
    int   numberOfCourses;
};

struct Account
{
    char* studentID;
    char* password;
};

struct Course
{
    char* courseID;
    char* name;
};

struct StudentCourse
{
    char* studentID;
    char*  courseID;
    int   mark;
    
};

///////////////////////////////////* source files *///////////////////////////////////
#define CoursesFile "Courses.txt"
#define AccountsFile "Accounts.txt"
#define StudentsFile "Students.txt"
#define StudentsCoursesFile "StudentsCourses.txt"

///////////////////////////////////* global variables *///////////////////////////////////
struct Student* listOfStudents;
struct Account* listOfAccounts;
struct Course*  listOfCourses;
struct StudentCourse* listOfStudentCourses;

int numberOfStudents;
int numberOfCourses;
int numberOfAccounts;

char* studentID;
char* currentPassword;
void studentgender();

int numberOfStudentscourses;

///////////////////////////////////* struct arrays *///////////////////////////////////
struct Student createAStudent(char* studentID, char* name, char* gender, int grade, char* address, int admission_year, char* courses[], int numberOfCourses);
struct Student* getListOfStudentFromFile(char* fileAddress, char* fileName, int* numberOfStudents);

//create an array for account
struct Account createAccount(char* studentID, char* password);
struct Account* getListOfAccountFromFile(char* fileAddress, char* fileName, int* numberOfAccounts);

//create an array for courses
struct Course createACourse(char* courseID, char* name);
struct Course* getListOfCourseFromFile(char* fileAddress, char* fileName, int* numberOfCourses);

//create an array for StudentCourse
struct StudentCourse createAStudentCourse(char* studentID, char* courseID, int mark);
struct StudentCourse* getListOfStudentCourseFromFile(char* fileAddress, char* fileName, int* numberOfStudentscourses);


///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////* main function *///////////////////////////////////
int main(int argc, const char * argv[])
{
    
    /*******************STUDENTS*******************/
    char* studentsFileName = StudentsFile;
    char* studentsFileAddress = "/Users/Better/Documents/College Materials/401 C. Objective C and SWIFT/Project1/Sample-Demo-NewFormat/Students.txt";
    numberOfStudents = 0;
    
    /*******************COURSES*******************/
    char* coursesFileName = CoursesFile;
    char* coursesFileAddress = "/Users/Better/Documents/College Materials/401 C. Objective C and SWIFT/Project1/Sample-Demo-NewFormat/Courses.txt";
    numberOfCourses = 0;
    
    /*******************ACCOUNTS*******************/
    char* accountsFileName =AccountsFile;
    char* accountsFileAddress = "/Users/Better/Documents/College Materials/401 C. Objective C and SWIFT/Project1/Sample-Demo-NewFormat/Accounts.txt";
    numberOfAccounts = 0;
    
    /*******************STUDENTS COURSES*******************/
    char* studentCoursesFileName =StudentsCoursesFile;
    char* studentCoursesFileAddress = "/Users/Better/Documents/College Materials/401 C. Objective C and SWIFT/Project1/Sample-Demo-NewFormat/StudentsCourses.txt";
    numberOfStudentscourses =0;
    
    
    
    listOfStudents = getListOfStudentFromFile(studentsFileAddress, studentsFileName, &numberOfStudents);
    listOfCourses  = getListOfCourseFromFile(coursesFileAddress, coursesFileName, &numberOfCourses);
    listOfAccounts = getListOfAccountFromFile(accountsFileAddress,accountsFileName,&numberOfAccounts);
    listOfStudentCourses = getListOfStudentCourseFromFile(studentCoursesFileAddress,studentCoursesFileName,&numberOfStudentscourses);
    
    
    logInUser();
    
    
    return 0;
}



///////////////////////////////////* user login *///////////////////////////////////
void logInUser()
{
    
    printf("\n************************************************************\n");
    printf("Please enter your account to login:\n");
    printf("************************************************************\n\n");
    
    bool flag = false;
    char ID [20] = " ";
    char pass [20] = " ";
    
    while (flag==false)
    {
        printf ("\n\tUsername: ");
        gets (ID);
        //        fgets (ID, 20, stdin);
        printf ("\n\tPassword: ");
        gets (pass);
        //        fgets (pass, 20, stdin);
        flag=checkPass(ID, pass);
    }
    sleep(2); //to delay 2 seconds
    showMenuOption();
}

///////////////////////////////////* buffer *///////////////////////////////////
void buffer(void){
    char c = '\0';
    while ((c = getchar()!= '\n' && c != EOF));
}


///////////////////////////////////* check user & password *///////////////////////////////////
bool checkPass(char ID [20],char pass [20])
{
    int i= 0;
    bool flag1 = false;
    
    for( i=0; i<numberOfAccounts; i++)
    {
        if(strcmp(listOfAccounts[i].studentID,ID) == 0 && strcmp(listOfAccounts[i].password,pass) == 0)
        {
            studentID = ID;
            currentPassword = pass;
            printf("****** Welcome to Cornerstone International Community College of Canada ******\n\n");
            studentID = ID;
            flag1=true;
            break;
        }
    }
    
    if (flag1 == false)
        printf("\nYour account does not exist. Please try again!\n");
    
    return flag1;
}



///////////////////////////////////* Menu 1: my enrollment certificate *///////////////////////////////////
void printEnrolmentCertificate(void)
{
    /*char* studentsFileName = StudentsFile;
     char* studentsFileAddress = "Students.txt";
     int numberOfStudents = 0;*/
    
    printf("\n************************************************************\n");
    printf("Certificate\n");
    printf("************************************************************\n\n");
    
    //listOfStudents = getListOfStudentFromFile(studentsFileAddress, studentsFileName, &numberOfStudents);
    
    int i;
    char* gender = "male";
    for( i=0; i<numberOfStudents; i++)
    {
        if(strcmp(listOfAccounts[i].studentID,studentID) == 0 )
        {
            printf("\n\tDear Sir/Madam,\n\n");
            printf("\tThis is to certify that ");
            if(strcmp(listOfStudents[i].gender,gender) == 0){
                printf("Mr.");
            }
            else{
                printf("Mrs.");
            }
            printf("%s ", listOfStudents[i].name);
            printf("with student ID %s",listOfStudents[i].studentID);
            printf(" is a student at grade %d",listOfStudents[i].grade);
            printf(" at CICCC. ");
            if(strcmp(listOfStudents[i].gender,gender) == 0){
                printf("He ");
            }
            else{
                printf("She ");
            }
            printf("was admitted to our college in %d",listOfStudents[i].admission_year);
            printf(" and has taken %d course(s). ",listOfStudents[i].numberOfCourses);
            printf("Currently he reside at %s. ",listOfStudents[i].address);
            printf("If you have any question, please do not hesitate to contact us.\n\n\tThanks,\n\tWilliams");
        }
    }
}

///////////////////////////////////* student information *///////////////////////////////////
void studentinfoByID()
{
    int i;
    char* gender = "male";
    for( i=0; i<numberOfStudents; i++)
    {
        if(strcmp(listOfAccounts[i].studentID,studentID) == 0 )
        {
            if(strcmp(listOfStudents[i].gender,gender) == 0){
                printf("\tHi Mr.");
            }
            else{
                printf("\tHi Mrs.");
            }
            printf("%s,\n", listOfStudents[i].name);
        }
    }
}

///////////////////////////////////* Menu 2: my courses *///////////////////////////////////
void printStudentcourses(void)
{
    //===============StudentFile=====================
    /* char* studentsFileName = StudentsFile;
     char* studentsFileAddress = "Students.txt";
     int numberOfStudents = 0;
     //==============courseFile=============================
     char* coursesFileName = CoursesFile;
     char* coursesFileAddress = "Courses.txt";
     int numberOfCourses = 0;*/
    
    // listOfStudents = getListOfStudentFromFile(studentsFileAddress, studentsFileName, &numberOfStudents);
    //  listOfCourses = getListOfCourseFromFile(coursesFileAddress, coursesFileName, &numberOfCourses);
    
    //char* gender = "male";
    printf("\n************************************************************\n");
    printf("Student Courses\n");
    printf("************************************************************\n\n");
    int i,j,k;
    studentinfoByID();
    for( i=0; i<numberOfStudents; i++)
    {
        if(strcmp(listOfAccounts[i].studentID,studentID) == 0 )
        {
            // if(strcmp(listOfStudents[i].gender,gender) == 0){
            //     printf("\tHi Mr.");
            // }
            //  else{
            //     printf("\tHi Mrs.");
            // }
            // printf("%s,\n", listOfStudents[i].name);
            printf("\tYou have taken the following courses:\n");
            printf("\t======================================\n");
            
            for( j=0; j<listOfStudents[i].numberOfCourses; j++)
            {
                printf("\t%d) %s: ",j+1,listOfStudents[i].courses[j]);
                //listOfCourses = getListOfCourseFromFile(coursesFileAddress, coursesFileName, &numberOfCourses);
                // char* currentCourse = listOfStudents[i].courses[j];
                for( k=0; k<numberOfCourses; k++)
                {
                    if(strcmp(listOfStudents[i].courses[j],listOfCourses[k].courseID)==0)
                        printf("%s\n",listOfCourses[k].name);
                }
                
            }
        }
    }
}

///////////////////////////////////* Menu 3: my transcript *///////////////////////////////////
void printStudentTranscript()
{
    int i,j,k,p;
    //    int sum =0;
    //    int count;
    
    printf("\n************************************************************\n");
    printf("Student Transcript\n");
    printf("************************************************************\n\n");
    
    //char* gender = "male";
    studentinfoByID();
    for( i=0; i<numberOfStudents; i++)
    {
        if(strcmp(listOfAccounts[i].studentID,studentID) == 0 )
        {
            //if(strcmp(listOfStudents[i].gender,gender) == 0){
            //   printf("\tHi Mr.");
            //}
            //else{
            //  printf("\tHi Mrs.");
            //}
            //printf("%s,\n", listOfStudents[i].name);
            for( j=0; j<listOfStudents[i].numberOfCourses; j++)
            {
                printf("\t%d) %s: ",j+1,listOfStudents[i].courses[j]);
                //listOfCourses = getListOfCourseFromFile(coursesFileAddress, coursesFileName, &numberOfCourses);
                for( k=0; k<numberOfCourses; k++)
                {
                    if(strcmp( listOfStudents[i].courses[j],listOfCourses[k].courseID)==0)
                    {
                        printf("%s: ",listOfCourses[k].name);
                        
                        for( p = 0; p < numberOfStudentscourses; p++)
                        {
                            if(strcmp( listOfCourses[k].courseID,listOfStudentCourses[p].courseID)==0 && strcmp(listOfStudentCourses[p].studentID,studentID)==0)
                            {
                                printf("%d\n", listOfStudentCourses[p].mark);
                                //sum = sum + listOfStudentCourses[p].mark;
                                // count++;
                            }
                            
                        }
                    }
                }
                
            }
            
        }
    }
    float gpa = studentGPA(studentID,numberOfStudentscourses);
    printf("\n\tYour GPA is: %.2f\n",gpa);
}

///////////////////////////////////* Menu 3: print my GPA *///////////////////////////////////
void printStudentGPA()
{
    float gpa = studentGPA(studentID,numberOfStudentscourses);
    studentinfoByID();
    printf("\n\tYour GPA is: %.2f ",gpa);
    
    /*int i;
     char* gender = "male";
     
     float gpa = studentGPA(studentID,numberOfStudentscourses);
     
     for( i=0; i<numberOfStudentscourses; i++)
     {
     if(strcmp(listOfStudents[i].studentID,studentID)==0)
     {
     if(strcmp(listOfStudents[i].gender,gender) == 0){
     printf("\tHi Mr.");
     }
     else{
     printf("\tHi Mrs.");
     }
     printf("%s,\n", listOfStudents[i].name);
     break;
     }
     break;
     }*/
}

///////////////////////////////////* Menu 4: calculate GPA *///////////////////////////////////
float studentGPA(char* sudentID , int numberOfStudentscourses)
{
    float mark = 0;
    int count = 0;
    float GPA = 0;
    int i;
    
    for( i = 0; i < numberOfStudentscourses; i++)
    {
        if(strcmp(studentID, listOfStudentCourses[i].studentID) == 0)
        {
            mark = mark + listOfStudentCourses[i].mark;
            count++;
        }
    }
    GPA = mark / count;
    return GPA;
}

///////////////////////////////////* Menu 5: print my ranking *///////////////////////////////////
void PrintstudentRanking(int numberOfStudentscourses)
{
    int i,j;
    int count = 0;
    float mark = 0;
    float GPAArray[100];
    int studentRank =1;
    float currentGPA = studentGPA(studentID,numberOfStudentscourses);
    printStudentGPA();
    
    for( i=0; i<numberOfStudents; i++)
    {
        for( j = 0; j < numberOfStudentscourses; j++)
        {
            if(strcmp(listOfStudents[i].studentID, listOfStudentCourses[j].studentID) == 0)
            {
                mark = mark + listOfStudentCourses[j].mark;
                count++;
            }
        }
        GPAArray[i] = mark / count;
        mark =0;
        count=0;
    }
    
    for(i=0;i<numberOfStudents;i++)
    {
        if(currentGPA <GPAArray[i])
        {
            studentRank++;
        }
    }
    printf("and your Ranking is: %d\n",studentRank);
}

///////////////////////////////////* Menu 6: list of available courses *///////////////////////////////////
void printListOfCourses(void)
{
    // char* coursesFileName = CoursesFile;
    // char* coursesFileAddress = "Courses.txt";
    //int numberOfCourses = 0;
    int i;
    
    //listOfCourses = getListOfCourseFromFile(coursesFileAddress, coursesFileName, &numberOfCourses);
    printf("\tThe following courses are offered in CICCC:\n");
    printf("\t===================================================\n\n");
    
    for( i=0; i<numberOfCourses; i++)
    {
        printf("\t%d) %s: %s\n",i+1,listOfCourses[i].courseID,listOfCourses[i].name);
    }
}

///////////////////////////////////* Menu 7: list of all students *///////////////////////////////////
void printListOfStudents(void)
{
    /*char* studentsFileName = StudentsFile;
     char* studentsFileAddress = "Students.txt";
     int numberOfStudents = 0;*/
    //listOfStudents = getListOfStudentFromFile(studentsFileAddress, studentsFileName, &numberOfStudents);
    printf("\tList all students in the college:\n");
    printf("\t=================================================\n\n");
    
    int i;
    for( i=0; i<numberOfStudents; i++)
    {
        printf("\t%d) %s: %s\n",i+1, listOfStudents[i].name, listOfStudents[i].studentID);
    }
    printf("\n\tThere are %d student(s) in CICCC as following:\n",i);
}

///////////////////////////////////* Menu 8: logout *///////////////////////////////////
void logOut()
{
    char ch ;
    //listOfStudents = {NULL}
    // listOfCourses  = getListOfCourseFromFile(coursesFileAddress, coursesFileName, &numberOfCourses);
    //  listOfStudentCourses = getListOfStudentCourseFromFile(studentCoursesFileAddress,studentCoursesFileName,&numberOfStudentscourses);
    printf("\n\t\tAre you sure to logout? ");
    printf("\n\t\tPlease enter y or n :");
    scanf("%c/n",&ch);
    
    if(ch == 'y')
    {
        system("cls");
        studentID = " ";
        currentPassword = " ";
        buffer();
        logInUser();
    }
    else if(ch == 'n'){
        showMenuOption();
    }
    
    
}

///////////////////////////////////* Option selections *///////////////////////////////////
void showMenuOption (void)
{
    int choice;
    do
    {
        printf("\n************************************************************\n");
        printf("Select from the option\n");
        printf("************************************************************\n\n");
        printf("\t__[1] Print my enrolment certificate\n");
        printf("\t__[2] Print my courses\n");
        printf("\t__[3] Print my transcript\n");
        printf("\t__[4] Print my GPA\n");
        printf("\t__[5] Print my ranking among all students in the college\n");
        printf("\t__[6] List all available courses\n");
        printf("\t__[7] List all students\n");
        printf("\t__[8] Logout\n");
        printf("\t__[9] Exit\n");
        printf("\n************************************************************\n\n");
        printf("\tPlease enter your choice: ");
        scanf("%d",&choice);
        printf("\n");
        
        switch(choice)
        {
            case 1:
                printEnrolmentCertificate();
                break;
            case 2:
                printStudentcourses();
                break;
            case 3:
                printStudentTranscript();
                break;
            case 4:
                printStudentGPA();
                break;
            case 5:
                PrintstudentRanking( numberOfStudentscourses);
                break;
            case 6:
                printListOfCourses();
                break;
            case 7:
                printListOfStudents();
                break;
            case 8:
                logOut();
                break;
            case 9:
                system("cls");
                printf("\n--------EXIT-------\n\n");
                exit(0);
                break;
            default:
                printf("\n\tInvalid choice! Please enter a number between 0 to 9\n");
                break;
        }
        
    } while(choice != 9);
    
}

///////////////////////////////////* create student *///////////////////////////////////
struct Student createAStudent(char* studentID, char* name, char* gender, int grade, char* address, int admission_year, char* courses[], int numberOfCourses)
{
    struct Student* student = (struct Student*)malloc(sizeof(struct Student));
    
    (*student).studentID = studentID;
    (*student).name = name;
    (*student).gender = gender;
    (*student).grade = grade;
    (*student).address = address;
    (*student).admission_year = admission_year;
    (*student).courses = courses;
    (*student).numberOfCourses = numberOfCourses;
    
    return *student;
}
///////////////////////////////////* create account *///////////////////////////////////
struct Account createAccount(char* studentID, char* password)
{
    struct Account* account = (struct Account*)malloc(sizeof(struct Account));
    (*account).studentID =studentID; // equal to : account->studentID = studentID;
    (*account).password = password;
    
    return *account;
}
///////////////////////////////////* create courses *///////////////////////////////////
struct Course createCourse(char* courseID, char* name)
{
    struct Course* course = (struct Course*)malloc(sizeof(struct Course));
    (*course).courseID =courseID; ;
    (*course).name = name;
    
    return *course;
}
///////////////////////////////////* create student courses *///////////////////////////////////
struct StudentCourse createAStudentCourse(char* studentID, char* courseID, int mark)
{
    struct StudentCourse* studentCourse = (struct StudentCourse*)malloc(sizeof(struct StudentCourse));
    (*studentCourse).studentID =studentID;
    (*studentCourse).courseID =courseID;
    (*studentCourse).mark = mark;
    
    return *studentCourse;
}
///////////////////////////////////* get students from file *///////////////////////////////////
struct Student* getListOfStudentFromFile(char* fileAddress, char* fileName, int* numberOfStudents)
{
    int numberOfStudentsReadFromFileSoFar = 0;
    int numberOfLinesInTheFile = 0;
    char** lines = readFile(fileAddress, &numberOfLinesInTheFile);
    int numberOfLinesPerRecord = numberOfItemsPerRecordInFile(fileName);
    int numberOfRecords = numberOfLinesInTheFile / numberOfLinesPerRecord;
    
    
    struct Student* listOfStudents = (struct Student*) malloc(numberOfRecords*sizeof(struct Student));
    
    int k,i;
    for(k=0; k<numberOfRecords; k++)
    {
        char* studentID = NULL;
        char* name = NULL;
        char* gender = NULL;
        int grade = 0;
        char* address = NULL;
        int admission_year = 0;
        char** courses= NULL;
        int numberOfCourses = 0;
        
        for( i=0; i<numberOfLinesPerRecord; i++)
        {
            int indexOfLine = k*numberOfLinesPerRecord+i;
            
            if(lines[indexOfLine]!=NULL)
            {
                //printf("\n%s\n", lines[indexOfLine]);
                char firstCharacter = firstChar(lines[indexOfLine]);
                
                int lineLength = strLength(lines[indexOfLine]);
                
                int startIndex = getTheStartIndex(fileName, firstChar(lines[indexOfLine]));
                
                
                if(firstCharacter=='1')
                {
                    studentID = substring(lines[indexOfLine], startIndex, lineLength-2);
                }
                else if(firstCharacter=='2')
                {
                    name = substring(lines[indexOfLine], startIndex, lineLength-2);
                }
                else if(firstCharacter=='3')
                {
                    gender = substring(lines[indexOfLine], startIndex, lineLength-2);
                }
                else if(firstCharacter=='4')
                {
                    char* gradeStr = substring(lines[indexOfLine], startIndex, lineLength-2);
                    
                    grade = convertToNumber(gradeStr);
                }
                else if(firstCharacter=='5')
                {
                    address = substring(lines[indexOfLine], startIndex, lineLength-2);
                }
                else if(firstCharacter=='6')
                {
                    char* admissionYearStr = substring(lines[indexOfLine], startIndex, lineLength-2);
                    admission_year = convertToNumber(admissionYearStr);
                }
                else if(firstCharacter=='7')
                {
                    int numberOfComponents = 0;
                    char* coursesStr = substring(lines[indexOfLine], startIndex, lineLength-2);
                    courses = splitString(coursesStr, ',', &numberOfComponents);
                    numberOfCourses = numberOfComponents;
                    
                }
            }//end of if
        }//end of second for
        
        struct Student student = createAStudent(studentID, name, gender, grade, address, admission_year, courses, numberOfCourses);
        listOfStudents[numberOfStudentsReadFromFileSoFar] = student;
        
        numberOfStudentsReadFromFileSoFar++;
        
    }//end of first for
    
    *numberOfStudents = numberOfStudentsReadFromFileSoFar;
    return listOfStudents;
}

///////////////////////////////////* get accounts from file *///////////////////////////////////
struct Account* getListOfAccountFromFile(char* fileAddress, char* fileName, int* numberOfAccounts)
{
    int numberOfAccountsReadFromFileSoFar = 0;
    int numberOfLinesInTheFile = 0;
    char** lines = readFile(fileAddress, &numberOfLinesInTheFile);
    int numberOfLinesPerRecord = numberOfItemsPerRecordInFile(fileName);
    int numberOfRecords = numberOfLinesInTheFile / numberOfLinesPerRecord;
    
    int k,i;
    struct Account* listOfAccounts = (struct Account*) malloc(numberOfRecords*sizeof(struct Account));
    
    for( k=0; k<numberOfRecords; k++)
    {
        char* studentID = NULL;
        char* password = NULL;
        
        for( i=0; i<numberOfLinesPerRecord; i++)
        {
            int indexOfLine = k*numberOfLinesPerRecord+i;
            
            if(lines[indexOfLine]!=NULL)
            {
                //printf("\n%s\n", lines[indexOfLine]);
                char firstCharacter = firstChar(lines[indexOfLine]);
                int lineLength = strLength(lines[indexOfLine]);
                int startIndex = getTheStartIndex(fileName, firstChar(lines[indexOfLine]));
                
                if(firstCharacter=='1')
                {
                    studentID = substring(lines[indexOfLine], startIndex, lineLength-2);
                }
                else if(firstCharacter=='2')
                {
                    password = substring(lines[indexOfLine], startIndex, lineLength-2);
                }
                
            }//end of if
            
        }//end of second for
        
        struct Account account= createAccount(studentID, password);
        listOfAccounts[numberOfAccountsReadFromFileSoFar] = account;
        
        numberOfAccountsReadFromFileSoFar++;
        
    }//end of first for
    
    *numberOfAccounts = numberOfAccountsReadFromFileSoFar;
    return listOfAccounts;
}
///////////////////////////////////* get students courses from file *///////////////////////////////////
struct StudentCourse* getListOfStudentCourseFromFile(char* fileAddress, char* fileName, int* numberOfStudentscourses)
{
    int numberOfStudentCoursesReadFromFileSoFar = 0;
    int numberOfLinesInTheFile = 0;
    char** lines = readFile(fileAddress, &numberOfLinesInTheFile);
    int numberOfLinesPerRecord = numberOfItemsPerRecordInFile(fileName);
    int numberOfRecords = numberOfLinesInTheFile / numberOfLinesPerRecord;
    
    int k,i;
    struct StudentCourse* listOfStudentCourses = (struct StudentCourse*) malloc(numberOfRecords*sizeof(struct StudentCourse));
    
    for( k=0; k<numberOfRecords; k++)
    {
        char* studentID = NULL;
        char* courseID = NULL;
        int mark = 0;
        
        for( i=0; i<numberOfLinesPerRecord; i++)
        {
            int indexOfLine = k*numberOfLinesPerRecord+i;
            
            if(lines[indexOfLine]!=NULL)
            {
                //                printf("\n%s\n", lines[indexOfLine]);
                char firstCharacter = firstChar(lines[indexOfLine]);
                int lineLength = strLength(lines[indexOfLine]);
                int startIndex = getTheStartIndex(fileName, firstChar(lines[indexOfLine]));
                
                
                if(firstCharacter=='1')
                {
                    studentID = substring(lines[indexOfLine], startIndex, lineLength-2);
                }
                else if(firstCharacter=='2')
                {
                    courseID = substring(lines[indexOfLine], startIndex, lineLength-2);
                }
                else if(firstCharacter=='3')
                {
                    char* markStr = substring(lines[indexOfLine], startIndex, lineLength-2);
                    mark = convertToNumber(markStr);
                }
                
            }//end of if
            
        }//end of second for
        
        struct StudentCourse studentCourse= createAStudentCourse(studentID, courseID, mark);
        listOfStudentCourses[numberOfStudentCoursesReadFromFileSoFar] = studentCourse;
        
        numberOfStudentCoursesReadFromFileSoFar++;
        
    }//end of first for
    
    *numberOfStudentscourses = numberOfStudentCoursesReadFromFileSoFar;
    return listOfStudentCourses;
}

///////////////////////////////////* get courses from file - from Ali *///////////////////////////////////
struct Course* getListOfCourseFromFile(char* fileAddress, char* fileName, int* numberOfCourses)
{
    int numberOfCoursesReadFromFileSoFar = 0;
    int numberOfLinesInTheFile = 0;
    char** lines = readFile(fileAddress, &numberOfLinesInTheFile);
    int numberOfLinesPerRecord = numberOfItemsPerRecordInFile(fileName);
    int numberOfRecords = numberOfLinesInTheFile / numberOfLinesPerRecord;
    
    int k,i;
    struct Course* listOfCourses = (struct Course*) malloc(numberOfRecords*sizeof(struct Course));
    
    for( k=0; k<numberOfRecords; k++)
    {
        char* courseID = NULL;
        char* name = NULL;
        
        for( i=0; i<numberOfLinesPerRecord; i++)
        {
            int indexOfLine = k*numberOfLinesPerRecord+i;
            
            if(lines[indexOfLine]!=NULL)
            {
                //printf("\n%s\n", lines[indexOfLine]);
                char firstCharacter = firstChar(lines[indexOfLine]);
                int lineLength = strLength(lines[indexOfLine]);
                int startIndex = getTheStartIndex(fileName, firstChar(lines[indexOfLine]));
                
                if(firstCharacter=='1')
                {
                    courseID = substring(lines[indexOfLine], startIndex+1, lineLength-2);
                }
                else if(firstCharacter=='2')
                {
                    name = substring(lines[indexOfLine], startIndex+1, lineLength-2);
                }
                
            }//end of if
            
        }//end of second for
        
        struct Course course= createCourse(courseID, name);
        listOfCourses[numberOfCoursesReadFromFileSoFar] = course;
        
        numberOfCoursesReadFromFileSoFar++;
    }//end of first for
    
    *numberOfCourses = numberOfCoursesReadFromFileSoFar;
    return listOfCourses;
    
}

///////////////////////////////////* read characters - from Ali *///////////////////////////////////
char** readFile(char* fileAddress, int* numberOfLines)
{
    int lines_allocated = 128;
    int max_line_len = 100;
    
    /* Allocate lines of text */
    char **words = (char **)malloc(sizeof(char*)*lines_allocated);
    if (words==NULL)
    {
        fprintf(stderr,"Out of memory (1).\n");
        exit(1);
    }
    
    FILE *fp = fopen(fileAddress, "r");
    if (fp == NULL)
    {
        fprintf(stderr,"Error opening file.\n");
        exit(2);
    }
    
    int i;
    for (i=0;1;i++)
    {
        int j;
        
        /* Have we gone over our line allocation? */
        if (i >= lines_allocated)
        {
            int new_size;
            
            /* Double our allocation and re-allocate */
            new_size = lines_allocated*2;
            words = (char **)realloc(words,sizeof(char*)*new_size);
            if (words==NULL)
            {
                fprintf(stderr,"Out of memory.\n");
                exit(3);
            }
            lines_allocated = new_size;
        }
        /* Allocate space for the next line */
        words[i] = malloc(max_line_len);
        if (words[i]==NULL)
        {
            fprintf(stderr,"Out of memory (3).\n");
            exit(4);
        }
        if (fgets(words[i],max_line_len-1,fp)==NULL)
            break;
        
        /* Get rid of CR or LF at end of line */
        for (j=(int)(strlen(words[i]))-1;j>=0 && (words[i][j]=='\n' || words[i][j]=='\r');j--)
            ;
        words[i][j+1]='\0';
    }
    /* Close file */
    fclose(fp);
    
    
    (*numberOfLines) = i;
    
    
    return words;
}
///////////////////////////////////* convert to numbers - from Ali *///////////////////////////////////
int convertToNumber(char * string)
{
    int number = atoi( string );
    return number;
}

///////////////////////////////////* items per record - from Ali *///////////////////////////////////
int numberOfItemsPerRecordInFile(char* fileName)
{
    if(strcmp(fileName, CoursesFile)==0)
    {
        return 2;
    }
    else if(strcmp(fileName, AccountsFile)==0)
    {
        return 2;
    }
    else if(strcmp(fileName, StudentsFile)==0)
    {
        return 7;
    }
    else if(strcmp(fileName, StudentsCoursesFile)==0)
    {
        return 3;
    }
    else
    {
        return 1;
    }
}

///////////////////////////////////* split strings - from Ali *///////////////////////////////////
char** splitString(char* a_str, const char a_delim, int* numberOfComponents)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;
    
    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }
    
    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);
    
    *numberOfComponents = (int)count;
    
    /* Add space for terminating null string so caller
     knows where the list of returned strings ends. */
    count++;
    
    result = malloc(sizeof(char*) * count);
    
    char* components[count];
    int i;
    for( i=0; i<count; i++)
    {
        components[i] = '\0';
    }
    
    int counter = 0;
    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);
        
        while (token)
        {
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
            
            counter++;
            
            components[counter] = token;
        }
        *(result + idx) = 0;
    }
    
    return result;
}
///////////////////////////////////* sub string - from Ali *///////////////////////////////////
char* substring(char* line, int startIndex, int endIndex)
{
    int len = (endIndex-startIndex)+1;
    
    char* substring;
    
    //substring = (char*) malloc((len+1)*sizeof(char));
    
    substring = (char*) malloc((len+1)*sizeof(char));
    int i;
    for( i=0; i<=len; i++)
    {
        substring[i] = '\0';
    }
    
    for( i=0; i<len; i++)
    {
        substring[i] = *(line+startIndex+i);
        
        substring[i] = line[startIndex+i];
        //*(substring+i) = *(line+startIndex+i);
    }
    
    substring[len+1] = '\0';
    return substring;
    
}
///////////////////////////////////* string length - from Ali *///////////////////////////////////
int strLength(char* line)
{
    char c = '\n';
    int index = 0;
    
    int numberOfDoubleQuotes = 0;
    
    while(numberOfDoubleQuotes<2)
    {
        
        c = *((line+index));
        index++;
        
        if(c == '"')
        {
            numberOfDoubleQuotes++;
        }
    }
    
    return index;
}

///////////////////////////////////* read first character - from Ali *///////////////////////////////////
char firstChar(char* line)
{
    return *line;
}

///////////////////////////////////* start index - from Ali *///////////////////////////////////

int getTheStartIndex(char* filename, char firstChar)
{
    
    if(strcmp(filename, AccountsFile)==0 && firstChar=='1')  //1User:”
    {
        return 7;
    }
    else if(strcmp(filename, AccountsFile)==0 && firstChar=='2') //2Pass:”
    {
        return 7;
    }
    if(strcmp(filename, StudentsFile)==0 && firstChar=='1')  //1studentID:”
    {
        return 12;
    }
    else if(strcmp(filename, StudentsFile)==0 && firstChar=='2') //2name:”
    {
        return 7;
    }
    else if(strcmp(filename, StudentsFile)==0 && firstChar=='3') //3gender:”
    {
        return 9;
    }
    else if(strcmp(filename, StudentsFile)==0 && firstChar=='4') //4grade:”
    {
        return 8;
    }
    else if(strcmp(filename, StudentsFile)==0 && firstChar=='5') //5address:“
    {
        return 10;
    }
    else if(strcmp(filename, StudentsFile)==0 && firstChar=='6') //6admission_year:”
    {
        return 17;
    }
    else if(strcmp(filename, StudentsFile)==0 && firstChar=='7') //7courses:”
    {
        return 10;
    }
    
    else if(strcmp(filename, CoursesFile)==0 && firstChar=='1') //courseID
    {
        return 10;
    }//
    else if(strcmp(filename, CoursesFile)==0 && firstChar=='2') //name
    {
        return 6;
    }
    else if(strcmp(filename, StudentsCoursesFile)==0 && firstChar=='1') //1studentID:"
    {
        return 12;
    }
    else if(strcmp(filename, StudentsCoursesFile)==0 && firstChar=='2') //2courseID:"
    {
        return 11;
    }
    else if(strcmp(filename, StudentsCoursesFile)==0 && firstChar=='3') //3mark:"
    {
        return 7;
    }
    
    else
    {
        return 0;
    }
}
