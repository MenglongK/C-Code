#include <iostream>
#include <algorithm>
using namespace std;
// define the struct for the student
struct Student
{
    // data members
    int id;
    string name;
    string gender;
    string classroom;
    float scores[3];
    // function members
    void input()
    {
        cout << "Enter Student ID: ";
        cin >> id;
        cout << "Enter Student Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Student Gender: ";
        cin >> gender;
        cout << "Enter Student Classroom: ";
        cin.ignore();
        getline(cin, classroom);
        cout << "\tEnter Student Scores: " << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "Enter Score " << (i + 1) << ": ";
            cin >> scores[i];
        };
    };
    void update()
    {
        cout << "Enter Student Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Student Gender: ";
        cin >> gender;
        cout << "Enter Student Classroom: ";
        cin.ignore();
        getline(cin, classroom);
    }
    void output()
    {
        cout << "Student ID: " << id << endl;
        cout << "Student Name: " << name << endl;
        cout << "Student Gender: " << gender << endl;
        cout << "Student Classroom: " << classroom << endl;
        cout << "Student Score: " << endl;
        for (int i = 0; i < 3; i++)
        {
            if (i == 0)
                cout << "\t " << scores[i];
            else
                cout << " " << scores[i];
        }
        cout << endl;
        cout << "\tStudent Average is: " << findAverage() << "%" << endl;
    };
    float findAverage()
    {
        return (scores[0] + scores[1] + scores[2]) / 3;
    }
};
void printLogo()
{
    cout << " ____  __  __ ____         ____                      _      " << endl;
    cout << " / ___||  \\/  / ___|       / ___|___  _ __  ___  ___ | | ___ " << endl;
    cout << " \\___ \\| |\\/| \\___ \\ _____| |   / _ \\| '_ \\/ __|/ _ \\| |/ _ \\" << endl;
    cout << "  ___) | |  | |___) |_____| |__| (_) | | | \\__ \\ (_) | |  __/" << endl;
    cout << " |____/|_|  |_|____/       \\____\\___/|_| |_|___/\\___/|_|\\___|" << endl;
};
int printMainMenu()
{
    printLogo();
    cout << "\t1. Insert New Student " << endl
         << "\t2. Edit Student Info " << endl
         << "\t3. Delete Student " << endl
         << "\t4. Search Students " << endl
         << "\t5. Show Students " << endl
         << "\t6. Exit " << endl;
    cout << "==> Choose your option(1-6): ";
    int option;
    cin >> option;
    return option;
}
void printLabel(string messages)
{
    cout << "----------[" << messages << "]---------------" << endl;
}
void pressEnter()
{
    cout << "=========Press Enter to continue==========" << endl;
    cin.ignore();
    cin.get();
}
void intStudent(Student studentArray[])
{
    studentArray[0] = {1004, "Bjarne Stroustrap", "male", "DevOps Labs", {34, 56, 98}};
    studentArray[1] = {1002, "James Bond", "male", "DevOps Labs", {22, 22, 22}};
    studentArray[2] = {1005, "koko", "male", "frontend Labs", {59, 70, 88}};
}
int searchStudentById(int counter, Student studentArray[])
{
    int studentId;
    cout << "Enter student ID to search: ";
    cin >> studentId;
    int foundIndex = -1;
    for (int i = 0; i < counter; i++)
    {
        if (studentId == studentArray[i].id)
        {
            foundIndex = i;
            printLabel("Student Result");
            studentArray[i].output();
        }
    }
    if (foundIndex == -1)
    {
        cout << "There is no record ID: " << studentId << endl;
    }
    return foundIndex;
}
int printShowMenu()
{
    printLabel("Show Student Info");
    cout << "1. Print Student in ASC (by ID)" << endl;
    cout << "2. Print Student in DES (by average)" << endl;
    cout << "3. Print Student in ASC (by name)" << endl;
    cout << "4. Exit the program " << endl;
    int option;
    cout << "Choose your option!!! (1-4): ";
    cin >> option;
    return option;
}
void printStudent(int counter, Student studentArray[])
{
    for (int i = 0; i < counter; i++)
    {
        studentArray[i].output();
        cout << "\t________________________" << endl;
    }
}

// function to detemine what our sort based on
bool idComparator(Student stu1, Student stu2)
{
    return stu1.id < stu2.id; // ascending order  which one smaller put in left, and bigger put in right
    // decending order (stu1.id > stu2.id)  which one bigger put in left, and smaller put in right
}
bool avgComparator(Student stu1, Student stu2)
{
    return stu1.findAverage() > stu2.findAverage();
}
bool nameComparator(Student stu1, Student stu2)
{
    return stu1.name < stu2.name;
}
int main()
{
    system("cls");
    int option;
    // 1. Create array of student struct
    int n = 50; // n is a number of the student in the systems
    Student studentArray[n];
    int counter = 3; // amount of counter should be similar with intStudent and array will count from 4->

    // int some data
    intStudent(studentArray);
    do
    {
        system("cls");
        option = printMainMenu();
        system("cls");
        switch (option)
        {
        case 1:
        {
            // if array is full, show messages
            if (counter >= n)
            {
                cout << "Memory full!! Cannot add new student!!" << endl
                     << "Try deleting some records" << endl;
                break;
            }
            // Feature 1. Insert New Student
            printLabel("Insert New Student");
            studentArray[counter++].input();
            cout << "===> Successfully Inserted a new records!" << endl;
        }
        break;
        case 2:
        {
            if (counter == 0)
            {
                cout << "There is no student to update " << endl;
                break;
            }
            int foundIndex = searchStudentById(counter, studentArray);
            if (foundIndex >= 0)
            {
                studentArray[foundIndex].update();
                cout << "==> Successfully update the student record" << endl;
            }
        }
        break;
        case 3:
        {
            printLabel("Delete student by ID");
            if (counter == 0)
            {
                cout << "There is no student to delete! " << endl;
                break;
            }
            // foundIndex = -1 (Not found)
            int foundIndex = searchStudentById(counter, studentArray);
            if (foundIndex >= 0)
            {
                // ask for the user confirmation Y/N
                char confirmLetter;
                bool isvalid = false;
                while (isvalid != true) // !isvalid = isvalid != true
                {
                    cout << "Are you sure ? y/n: ";
                    cin >> confirmLetter;
                    bool isYes = (confirmLetter == 'Y' || confirmLetter == 'y');
                    bool isNo = (confirmLetter == 'N' || confirmLetter == 'n');
                    isvalid = isYes || isNo;
                    if (!isvalid)
                    {
                        cout << "Error: Invalid Option!! only choose 'y','n' " << endl;
                        continue; // skip below code
                    }
                    if (isYes)
                    {
                        // we perform delete operation
                        for (int i = foundIndex; i < counter - 1; i++)
                        {
                            studentArray[i] = studentArray[i + 1];
                        }
                        counter--;
                        cout << "Delete student successfully...!" << endl;
                    }
                    else
                    {
                        // we abort the delete operation
                        cout << "Delte student is aborted successfully!" << endl;
                    }
                }
                // cout << "Are you sure? y/n: ";
                // cin >> confirmLetter;
                // if (confirmLetter == 'Y' || confirmLetter == 'y')
                // {
                //     // perform the delete operation
                //     for (int i = foundIndex; i < counter - 1; i++)
                //     {
                //         studentArray[i] = studentArray[i + 1];
                //     }
                //     counter--;
                //     cout << "Delete student successfully....!" << endl;
                // }
                // else if (confirmLetter == 'N' || confirmLetter == 'n')
                // {
                //     cout << "Delete student is aborted successfully!" << endl;
                // }
                // else
                // {
                //     cout << "Invalid option!!, Try again! " << endl;
                // }
            }
        }
        break;
        case 4:
        {
            // Feature 4. Search for student info
            printLabel("Search Student by ID");
            searchStudentById(counter, studentArray);
            break;
        }
        case 5:
        {
            // If there is no student, show message
            if (counter == 0)
            {
                cout << "There is no record" << endl;
                break;
            }
            // Feature 5. Show All Student
            int showOption;
            do
            {
                system("cls");
                showOption = printShowMenu();
                system("cls");
                switch (showOption)
                {
                case 1:
                    printLabel("Show student ASC by ID");

                    // Sort(array, array+size)  sort argument
                    sort(studentArray, studentArray + counter, idComparator); // studentArray (is array), studentArray+counter (is size of array), idComparator (to clarify sort with ID)
                    printStudent(counter, studentArray);
                    break;
                case 2:
                    printLabel("Show student ASC by average");
                    sort(studentArray, studentArray + counter, avgComparator);
                    printStudent(counter, studentArray);
                    break;
                case 3:
                    printLabel("Show student ASC by name");
                    sort(studentArray, studentArray + counter, nameComparator);
                    printStudent(counter, studentArray);
                    break;
                case 4:
                    cout << "Exit from show option!!" << endl;
                    break;
                default:
                    cout << "Invalid option!! Choose again from 1-4 " << endl;
                    break;
                }
                if (showOption != 4)
                    pressEnter();
            } while (showOption != 4);
            break;
        }
        case 6:
            cout << "Exit from the program!" << endl;
            break;
        default:
            break;
        }
        pressEnter(); // Wait for user press enter
    } while (option != 6);

    return 0;
}