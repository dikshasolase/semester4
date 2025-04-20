/*Company maintains employee’s information as employee ID, name, designation and salary. Allow
user to add, delete information of employee. Display information of particular employee. If employee
does not exist an appropriate message is displayed. If it is then system displays employee detail. Use
index sequential file to maintain the data*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Employee {
    int empID;
    char name[50];
    char designation[30];
    float salary;
};

struct Index {
    int empID;
    long position;
};

// Function to add an employee
void addEmployee() {
    Employee emp;
    fstream dataFile("employee.dat", ios::out | ios::app | ios::binary);
    fstream indexFile("index.txt", ios::out | ios::app);

    cout << "Enter Employee ID: ";
    cin >> emp.empID;
    cin.ignore();

    cout << "Enter Name: ";
    cin.getline(emp.name, 50);

    cout << "Enter Designation: ";
    cin.getline(emp.designation, 30);

    cout << "Enter Salary: ";
    cin >> emp.salary;

    long pos = dataFile.tellp();
    dataFile.write((char*)&emp, sizeof(emp));
    indexFile << emp.empID << " " << pos << "\n";

    dataFile.close();
    indexFile.close();

    cout << "Employee added successfully!\n";
}

// Function to search and display an employee
void searchEmployee(int id) {
    ifstream indexFile("index.txt");
    fstream dataFile("employee.dat", ios::in | ios::binary);

    int empID;
    long pos;
    bool found = false;

    while (indexFile >> empID >> pos) {
        if (empID == id) {
            Employee emp;
            dataFile.seekg(pos);
            dataFile.read((char*)&emp, sizeof(emp));

            cout << "\n--- Employee Details ---\n";
            cout << "ID: " << emp.empID << "\n";
            cout << "Name: " << emp.name << "\n";
            cout << "Designation: " << emp.designation << "\n";
            cout << "Salary: " << emp.salary << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Employee with ID " << id << " not found.\n";
    }

    indexFile.close();
    dataFile.close();
}

// Function to delete employee (by creating a new file without the record)
void deleteEmployee(int id) {
    ifstream indexFile("index.txt");
    fstream dataFile("employee.dat", ios::in | ios::binary);
    ofstream newIndexFile("new_index.txt");
    fstream newDataFile("new_employee.dat", ios::out | ios::binary);

    vector<Index> newIndex;
    int empID;
    long pos;
    bool deleted = false;

    while (indexFile >> empID >> pos) {
        Employee emp;
        dataFile.seekg(pos);
        dataFile.read((char*)&emp, sizeof(emp));

        if (emp.empID != id) {
            long newPos = newDataFile.tellp();
            newDataFile.write((char*)&emp, sizeof(emp));
            newIndexFile << emp.empID << " " << newPos << "\n";
        } else {
            deleted = true;
        }
    }

    indexFile.close();
    dataFile.close();
    newIndexFile.close();
    newDataFile.close();

    remove("index.txt");
    remove("employee.dat");
    rename("new_index.txt", "index.txt");
    rename("new_employee.dat", "employee.dat");

    if (deleted)
        cout << "Employee deleted successfully.\n";
    else
        cout << "Employee not found.\n";
}

// Menu-driven main function
int main() {
    int choice, id;

    do {
        cout << "\n==== Employee Record System ====\n";
        cout << "1. Add Employee\n";
        cout << "2. Search Employee\n";
        cout << "3. Delete Employee\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                cout << "Enter Employee ID to search: ";
                cin >> id;
                searchEmployee(id);
                break;
            case 3:
                cout << "Enter Employee ID to delete: ";
                cin >> id;
                deleteEmployee(id);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
