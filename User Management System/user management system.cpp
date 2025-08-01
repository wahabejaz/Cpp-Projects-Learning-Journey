//User Management System
//The program involves user interaction, authentication, and data management
//Programmer Name: Wahab Ejaz
//Compiler: g++
//Date: 4-March-2025
#include <iostream>
#include <string>
#include <fstream>
#include <limits>

using namespace std;

bool validInput()
{
    if (cin.good()) 
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return true;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid input. Please try again." << endl;
    return false;
}

bool isLeapYear(int year) 
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

bool isValidDate(int day, int month, int year) {
    if (month < 1 || month > 12) 
    {
        cout << "Invalid month! Please enter a value between 1 and 12." << endl;
        return false;
    }
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) 
    {
        cout << "Invalid day for the given month!" << endl;
        return false;
    }
    if (month == 2) {
        if (day > (isLeapYear(year) ? 29 : 28))
        {
            cout << "Invalid day for February!" << endl;
            return false;
        }
    } else if (day < 1 || day > 31) 
    {
        cout << "Invalid day! Please enter a value between 1 and 31." << endl;
        return false;
    }
    if (year < 1900 || year > 2026) 
    {
        cout << "Invalid year! Please enter a value between 1900 and 2026." << endl;
        return false;
    }
    return true;
}


class Date 
{
public:
    int dd, mm, yy;

    Date() : dd(1), mm(1), yy(1900) {}
    void setter();
    void getter() const;
};
void Date::setter() 
{
    do{
    cout << "Enter birth Date (dd): ";
    cin >> dd;
    cout << "Enter birth Month (mm): ";
    cin >> mm;
    cout << "Enter birth Year (yy): ";
    cin >> yy;
    } while (!isValidDate(dd, mm, yy) || !validInput());
}
void Date::getter() const
{
    cout << "\t\t\tEvent Date is  : " << dd << "/" << mm << "/" << yy;
}
 
class User {
private:
    string name, fName, className, regNo, userName;
    int age, password;
    Date dob;
public:
    void login();
    void registration();
    void overWriteProfile();
    void createProfile();
    void saveProfile();
    void readProfile();
};
void User::login() 
{
    bool found = false;
    do {
    cout << "Enter username: ";
    cin >> userName;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users_credentials.txt", ios::in);
    if (!file) 
    {
        cout << "=> ERROR OPENING credential FILE" << endl;
        return;
    }
    string fileUsername;
    int filePassword;
    while (file >> fileUsername >> filePassword) 
    {
    if (fileUsername == userName && filePassword == password) 
    {
        found = true;
        break;
    }
    }
    file.close();
    if (found) 
    {
        cout << endl;
        cout << "       ---(Login successful)---     " << endl << endl;
    } else 
    {
        cout << "No username or Password found! Please try again." << endl;
    }
    } while (!found);
}
void User::createProfile()
{
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin,name);
    cout << "Enter Father Name: ";
    getline(cin,fName);
    cout << "Enter Age: ";
    cin >> age;
    cin.ignore();
    cout << "---Enter Date of Birth---" << endl;
    dob.setter();
    cout << "Enter Class Name: ";
    getline(cin,className);
    cout << "Enter registration number: ";
    getline(cin,regNo);
    saveProfile();
}
void User::registration() 
{
    bool exists = false;
    do{
    cout << "Set Username: ";
    cin >> userName;
    ifstream file("users_credentials.txt", ios::in);
    string fileUsername;
    int filePassword;
    while (file >> fileUsername >> filePassword) 
    {
        if (fileUsername == userName) 
        {
        exists = true;
        break;
        }
    }
    file.close();
    if (exists)
    cout << "Username already exists. Please try a different username." << endl;
    } while (exists);

    do 
    {
    cout << "Set Password (xxxxx): ";
    cin >> password;
    if (password < 10000 || password > 65000)
    cout << "PLZ enter again. Password should be in digits (10000-65000)" << endl;
    } while (password < 10000 || password > 65000);

    ofstream file("users_credentials.txt", ios::app);
    if (!file) 
    {
        cout << "Error opening credentials file for writing." << endl;
    }
    file << userName << " " << password << "\n";
    cout << "Registration successful.\nCreate your profile now." << endl;
    createProfile();
}
void User::saveProfile() {
    ofstream outFile(userName + ".txt", ios::out);
    if (!outFile) 
    {
    cout << "=> ERROR CREATING PROFILE." << endl;
    return;
    }
    outFile << "Name: " << name << "\n";
    outFile << "Father's Name: " << fName << "\n";
    outFile << "Age: " << age << "\n";
    outFile << "Date of Birth: " << dob.dd << "/" << dob.mm << "/" << dob.yy << "\n";
    outFile << "Class Name: " << className << "\n";
    outFile << "Registration No: " << regNo << "\n";
    cout << "_________________________________________" << endl;
    cout << "=> PROFILE SAVED SUCCESSFULLY." << endl;
    outFile.close();
}
void User::readProfile()
{
    ifstream inFile;
    inFile.open(userName+".txt",ios::in);
    if (!inFile)
    {
        cout << "(X) Profile not found." << endl;
        return;
    }
    string line;
    cout << "\n----- User Profile -----\n";
    while(getline(inFile,line))
    {
        cout << line << endl;
    }
    cout << "------------------------\n";
}
void User::overWriteProfile()
{
    ofstream outFile;
    outFile.open(userName+".txt",ios::out);
    if (!outFile)
    {
    cout << "=>ERROR OVERWRITING PROFILE." << endl;
    return;
    }
    createProfile();
}
int main() 
{
    User person;
    char choice, ch;
    do {
    cout << endl;
    cout << "---Main Menu---" << endl;
    cout << "1. Login." << endl;
    cout << "2. Register." << endl;
    cout << "3. Exit." << endl;
    cout << "-----------------" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) 
    {
        case '1':
        person.login();
        do {
            cout << endl;
            cout << "1. Read Your Profile." << endl;
            cout << "2. Overwrite Your Profile." << endl;
            cout << "3. Return to main menu." << endl;
            cout << "------------------------------" << endl;
            cout << "Enter your choice: ";
            cin >> ch;
            switch (ch) 
            {
            case '1': 
            person.readProfile(); 
            break;

            case '2': 
            person.overWriteProfile(); 
            break;

            case '3': 
            break;

            default: 
            cout << "Invalid choice. Please enter again." << endl;
            }
            } while (ch != '3');
            break; 

        case '2':
            person.registration(); 
            break;

        case '3': 
            cout << "Exiting program!"; 
            return 0;

            default: 
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '3');
}