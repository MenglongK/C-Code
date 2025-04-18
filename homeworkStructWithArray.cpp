#include <iostream>
#include <algorithm>
using namespace std;

struct Worker
{
    int id;
    string name;
    char gender;
    string position;
    float wage, hour, totalSalary, tax;

    void input()
    {
        cout << "Enter worker ID: ";
        cin >> id;
        cout << "Enter worker name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter worker gender: ";
        cin >> gender;
        cout << "Enter worker position: ";
        cin.ignore();
        getline(cin, position);
        cout << "Enter worker wage: ";
        cin >> wage;
        cout << "Enter worker hour: ";
        cin >> hour;
    }
    void output()
    {
        float salary = wage * hour;
        cout << "Worker ID: " << id << endl;
        cout << "Worker name: " << name << endl;
        cout << "Worker gender: " << gender << endl;
        cout << "Worker position: " << position << endl;
        cout << "Worker wage: " << wage << endl;
        cout << "Worker hour: " << hour << endl;
        cout << "Worker salary: " << salary << endl;
        float femaleTax = 0.25;
        float maleTax = 0.3;
        if (salary >= 1000)
        {
            if (gender == 'M' || gender == 'm')
            {
                tax = salary * maleTax;
                cout << "Tax: 30% = " << tax << " $" << endl;
                totalSalary = salary - tax;
            }
            else
            {
                tax = salary * femaleTax;
                cout << "Tax: 25% = " << tax << " $" << endl;
                totalSalary = salary - tax;
            }
        }
        else
        {
            cout << "Tax: 0%" << endl;
            totalSalary = salary;
        }
        cout << "Balance salary: " << totalSalary << endl;
    }
    void update()
    {
        cout << "Enter worker name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter worker gender: ";
        cin >> gender;
        cout << "Enter worker position: ";
        cin.ignore();
        getline(cin, position);
    }
};
void calculateSalary(Worker &w)
{
    float salary = w.wage * w.hour;
    float femaleTax = 0.25;
    float maleTax = 0.3;
    if (salary >= 1000)
    {
        if (w.gender == 'M' || w.gender == 'm')
            w.tax = salary * maleTax;
        else
            w.tax = salary * femaleTax;
        w.totalSalary = salary - w.tax;
    }
    else
    {
        w.tax = 0;
        w.totalSalary = salary;
    }
}
void printLogo()
{
    cout << "__        __         _               __  __                                                   _ " << endl;
    cout << "\\ \\      / /__  _ __| | _____ _ __  |  \\/  | __ _ _ __   __ _  __ _  ___ _ __ ___   ___ _ __ | |_ " << endl;
    cout << " \\ \\ /\\ / / _ \\| '__| |/ / _ \\ '__| | |\\/| |/ _` | '_ \\ / _` |/ _` |/ _ \\ '_ ` _ \\ / _ \\ '_ \\| __|" << endl;
    cout << "  \\ V  V / (_) | |  |   <  __/ |    | |  | | (_| | | | | (_| | (_| |  __/ | | | | |  __/ | | | |_ " << endl;
    cout << "   \\_/\\_/ \\___/|_|  |_|\\_\\___|_|    |_|  |_|\\__,_|_| |_|\\__,_|\\__, |\\___|_| |_| |_|\\___|_| |_|\\__|" << endl;
    cout << "                                                              |___/                               " << endl;
};
int printMenu()
{
    printLogo();
    int option;
    cout << "\t1: Add new worker" << endl;
    cout << "\t2: Edit worker information" << endl;
    cout << "\t3: Delete worker information" << endl;
    cout << "\t4: Search for worker information" << endl;
    cout << "\t5: Show worker information" << endl;
    cout << "\t6: Exit the system" << endl;
    cout << "choose option 1 -> 6: ";
    cin >> option;
    return option;
}
void pressEnterToContinue()
{
    cout << "======Press Enter to Continue======" << endl;
    cin.get();
    cin.ignore();
}
void printLabel(string messages)
{
    cout << "====" << messages << "====" << endl;
}
void printWorker(int counter, Worker workerArray[])
{
    for (int i = 0; i < counter; i++)
    {
        workerArray[i].output();
        cout << "\t_______________" << endl;
    }
}
void intWorker(Worker workerArray[])
{
    workerArray[0] = {1001, "Menglong Keo", 'm', "Shipping", 10, 40};
    workerArray[1] = {1002, "Kesara Kim", 'm', "Shipping Manager", 50, 40};
    workerArray[2] = {1003, "Veasna Neang", 'f', "Admin", 40, 40};
}
int searchWorkerById(int counter, Worker workerArray[])
{
    int workerId;
    cout << "Enter worker ID:";
    cin >> workerId;
    int foundIndex = -1;
    for (int i = 0; i < counter; i++)
        if (workerId == workerArray[i].id)
        {
            foundIndex = i;
            cout << endl;
            printLabel("Worker Result");
            workerArray[i].output();
        }
    if (foundIndex == -1)
        cout << "There is no record ID: " << workerId << endl;
    return foundIndex;
}
int printShowMenu()
{
    printLabel("Show worker info");
    cout << "1. Print worker in ASC (by ID)" << endl;
    cout << "2. Print worker in DEC(by Salary)" << endl;
    cout << "3. Exit the program" << endl;
    int option;
    cout << "\nChoose option!!! (1->3): ";
    cin >> option;
    return option;
}
bool idComparator(Worker worker1, Worker worker2)
{
    return worker1.id < worker2.id;
}
bool totalSalaryComparator(Worker worker1, Worker worker2)
{
    return worker1.totalSalary > worker2.totalSalary;
}
int main()
{
    system("cls");
    int option;
    int n = 50;
    Worker workerArray[n];
    int counter = 3;
    intWorker(workerArray);
    do
    {
        system("cls");
        option = printMenu();
        system("cls");
        switch (option)
        {
        case 1:
        {
            if (counter >= n) // counter is actual number of data worker
            {
                cout << "Memory is full!, cannot add new worker info" << endl
                     << "Try to delete some records" << endl;
                break;
            }
            printLabel("Add new worker");
            workerArray[counter++].input();
            cout << "====Successfully add a new record!====" << endl;
        }
        break;
        case 2:
            cout << "====Search worker ID to update info====" << endl;
            {
                if (counter == 0)
                {
                    cout << "There is no worker to update" << endl;
                    break;
                }
                int foundIndex = searchWorkerById(counter, workerArray);
                if (foundIndex >= 0)
                    cout << "\n====Update information here====" << endl;
                workerArray[foundIndex].update();
                cout << "====Successfully update the worker record" << endl;
            }
            break;
        case 3:
        {
            cout << "====Delete worker by ID====" << endl;
            if (counter == 0)
            {
                cout << "There is no worker to delete" << endl;
                break;
            }
            int foundIndex = searchWorkerById(counter, workerArray);
            if (foundIndex >= 0)
            {
                // declare confirmask for the user confirmation y/n
                char confirmLetter;
                bool isValid = false; //
                while (!isValid)      // We can write isValid != true
                {
                    cout << "Are you sure to delete? y/n: ";
                    cin >> confirmLetter;
                    bool isYes = (confirmLetter == 'Y' || confirmLetter == 'y');
                    bool isNo = (confirmLetter == 'N' || confirmLetter == 'n');
                    isValid = isYes || isNo;
                    if (!isValid)
                    {
                        cout << "Error: Invalid Option!! only choose 'y','n'" << endl;
                        continue; // skip below code
                    }
                    if (isYes)
                    {
                        // we perform delete operation
                        for (int i = foundIndex; i < counter - 1; i++)
                        {
                            workerArray[i] = workerArray[i + 1];
                        }
                        counter--;
                        printLabel("Delete worker successfully!!");
                    }
                    // we abort to delete operation
                    else
                        printLabel("Delete worker is aborted successfully!!");
                }
            }
        }
        break;
        case 4:
        {
            printLabel("Search worker by ID");
            searchWorkerById(counter, workerArray);
        }
        break;
        case 5:
        {
            // if there is no worker, show message
            if (counter == 0)
            {
                printLabel("There is no record");
                break;
            }
            int showOption;
            do
            {
                system("cls");
                showOption = printShowMenu();
                system("cls");
                switch (showOption)
                {
                case 1:
                    printLabel("Show worker ASC by ID");
                    // sort (array, array+size) sort argument
                    sort(workerArray, workerArray + counter, idComparator);
                    printWorker(counter, workerArray);
                    break;
                case 2:
                    printLabel("Show worker DEC by total salary");
                    for (int i = 0; i < counter; i++)
                        calculateSalary(workerArray[i]);
                    sort(workerArray, workerArray + counter, totalSalaryComparator);
                    printWorker(counter, workerArray);
                    break;
                case 3:
                    printLabel("Exit the program");
                    break;
                default:
                    printLabel("Invalid option!! Choose again from 1->3");
                    break;
                }
                if (showOption != 3)
                    pressEnterToContinue();

            } while (showOption != 3);
            break;
        }
        case 6:
            cout << "Exit the system" << endl;
            break;
        default:
            break;
        }
        pressEnterToContinue(); // put here to use all case when break
    } while (option != 6); // if option = 6, loop will stop working

    return 0;
}