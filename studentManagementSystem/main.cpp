#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>

#define MAX 100
using namespace std;

struct students {
    int id;
    string name;
    string grade;
};

students studList[MAX];
int total = 0;
int nextId = 1001;

bool nameExists(string n) {
    for (int i = 0; i < total; i++) {
        if (studList[i].name == n) return true;
    }
    return false;
}

void saveToFile() {
    ofstream outFile("students.txt");
    if (!outFile) {
        cout << "Error opening file for writing!" << endl;
        return;
    }
    for (int i = 0; i < total; i++) {
        outFile << studList[i].id << endl;
        outFile << studList[i].name << endl;
        outFile << studList[i].grade << endl;
    }
    outFile.close();
    cout << "Student data saved to file.\n";
}

void loadFromFile() {
    ifstream inFile("students.txt");
    if (!inFile) {
        cout << "Error opening file for reading!" << endl;
        return;
    }
    total = 0;
    while (inFile >> studList[total].id && total < MAX) {
        inFile.ignore();
        getline(inFile, studList[total].name);
        inFile >> studList[total].grade;
        inFile.ignore();
        total++;
    }
    if (total > 0) {
        nextId = studList[total - 1].id + 1;
    }
    inFile.close();
}

void createStudent() {
    char choice;
    do {
        if (total >= MAX) {
            cout << "Maximum student limit reached!" << endl;
            break;
        }

        studList[total].id = nextId++;
        cout << "--Enter data for student (" << total + 1 << ")--" << endl;
        cout << "Generated Student ID: " << studList[total].id << endl;

        cin.ignore();

        do {
            cout << "Enter student name: ";
            getline(cin, studList[total].name);
            if (studList[total].name.empty()) {
                cout << "Name cannot be empty. Please try again.\n";
            } else if (nameExists(studList[total].name)) {
                cout << "Warning: A student with this name already exists.\n";
            }
        } while (studList[total].name.empty());

        do {
            cout << "Enter grade (e.g. A, B+, C): ";
            getline(cin, studList[total].grade);
            if (studList[total].grade.empty()) {
                cout << "Grade cannot be empty. Please try again.\n";
            }
        } while (studList[total].grade.empty());

        total++;
        saveToFile();

        do {
            cout << "Do you have another student (Y/N)? : ";
            cin >> choice;
            choice = tolower(choice);
            if (choice != 'y' && choice != 'n') {
                cout << "Invalid choice. Please use either Y/y or N/n.\n";
            }
        } while (choice != 'y' && choice != 'n');

    } while (choice == 'y');
}

void updateStudent() {
    int id, found = 0;
    cout << "Enter ID to update: ";
    cin >> id;
    for (int i = 0; i < total; i++) {
        if (studList[i].id == id) {
            cin.ignore();
            do {
                cout << "Enter New Name: ";
                getline(cin, studList[i].name);
                if (studList[i].name.empty()) {
                    cout << "Name cannot be empty. Please try again.\n";
                }
            } while (studList[i].name.empty());

            do {
                cout << "Enter New Grade: ";
                getline(cin, studList[i].grade);
                if (studList[i].grade.empty()) {
                    cout << "Grade cannot be empty. Please try again.\n";
                }
            } while (studList[i].grade.empty());

            found = 1;
            break;
        }
    }
    if (found) {
        cout << "Record updated successfully!" << endl;
        saveToFile();
    } else {
        cout << "Student not found!" << endl;
    }
}

void deleteStudent() {
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;
    int index = -1;
    for (int i = 0; i < total; i++) {
        if (studList[i].id == id) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < total - 1; i++) {
            studList[i] = studList[i + 1];
        }
        total--;
        cout << "Student deleted successfully!" << endl;
        saveToFile();
    } else {
        cout << "Student not found!" << endl;
    }
}

void readStudents() {
    if (total == 0) {
        cout << "No student records found!" << endl;
        return;
    }
    cout << "\n--- Student Records ---\n";
    cout << left << setw(10) << "ID" 
         << setw(25) << "Name" 
         << setw(10) << "Grade" << endl;
    cout << "---------------------------------------------\n";
    for (int i = 0; i < total; i++) {
        cout << left << setw(10) << studList[i].id 
             << setw(25) << studList[i].name 
             << setw(10) << studList[i].grade << endl;
    }
}

int main() {
    int choice;
    loadFromFile();
    do {
        cout << "\n===============================================\n";
        cout << "        STUDENT MANAGEMENT SYSTEM\n";
        cout << "===============================================\n";
        cout << "1. ➤ Add Student\n";
        cout << "2. ➤ Display Students\n";
        cout << "3. ➤ Update Student\n";
        cout << "4. ➤ Delete Student\n";
        cout << "5. ➤ Exit\n";
        cout << "-----------------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            createStudent();
            break;
        case 2:
            readStudents();
            break;
        case 3:
            updateStudent();
            break;
        case 4:
            deleteStudent();
            break;
        case 5:
            cout << "\nThank you for using the Student Management System.\n";
            break;
        default:
            cout << "❌ Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

