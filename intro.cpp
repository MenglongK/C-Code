#include <iostream>
using namespace std;
struct Student
{
    int id;
    string name;
    char gender;
    float average;

    // No-Args Constructor
    Student()
    {
        // int default values
        cout << "No-Arg is called!" << endl;
        id = 0;
        name = "<Unknown>";
        gender = 'm';
        average - 0;
    }
    // Parameterized Constructor
    Student(int idNumber, string fullName, char sex, float avg)
    {
        cout << "Parameterized is called!!" << endl;
        id = idNumber;
        name = fullName;
        gender = sex;
        average = avg;
    }

    // allow us to create functions
    void input()
    {
        cout << "Enter Student ID : ";
        cin >> id;
        cout << "Enter Student Name : ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Student Gender : ";
        cin >> gender;
        cout << "Enter Student Average : ";
        cin >> average;
    }
    void output()
    {
        cout << "Student ID : " << id << endl;
        cout << "Student Name : " << name << endl;
        cout << "Student Gender : " << gender << endl;
        cout << "Student Average : " << average << endl;
    }
};
int main()
{
    system("cls");
    // Student student1;

    // initialize values for the student1
    Student student1;
    // cout << "[+] Enter information of the student:" << endl;
    // cout << endl;
    // student1.input();
    // cout << endl;
    Student student2(1001, "jame bond", 'm', 89.5);
    cout << "[+] Information of the student:" << endl;
    cout << endl;
    student2.output();
    return 0;
}