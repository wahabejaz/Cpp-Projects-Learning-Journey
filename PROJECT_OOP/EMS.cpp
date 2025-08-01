//EVENT MANAGEMENT SYSTEM
/*The purpose of this project(Event Management System), is to streamline the planning,
 coordination, and execution of events by efficiently managing various event details and participants.*/
 //Programmers: Halar Khan,Wahab Ejaz,Muhammad Irfan,Talal Gul
 //Compiler: gcc
 //Date 1-Jan-2025
#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <regex>
#include <windows.h>
#include <thread>
#include <chrono>

using namespace std;

const int MAX = 500;


// Function Prototypes
int getConsoleWidth();
void printCentered(const string& text);
void displayTimer(int seconds);
bool validInput();
bool isLeapYear(int year);
bool isValidDate(int day, int month, int year);

// -------------------- Utility Functions --------------------

// Get console width for centering text
int getConsoleWidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        return csbi.dwSize.X;
    }
    return 80; // Default width if unable to retrieve
}

// Print centered text in console
void printCentered(const string& text) {
    int consoleWidth = getConsoleWidth();
    int padding = (consoleWidth - text.length()) / 2;
    if (padding > 0) {
        cout << string(padding, ' ') << text << "\n";
    } else {
        cout << text << "\n";
    }
}

// Display a countdown timer
void displayTimer(int seconds) {
    for (int i = seconds; i > 0; i--) {
        cout << "\rPlease wait " << i << " seconds before trying again... " << flush;
        this_thread::sleep_for(chrono::seconds(1));
    }
    cout << "\rYou can now try logging in again." << endl << endl;
}

// Validate user input
bool validInput() {
    if (cin.good()) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return true;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid input. Please try again." << endl;
    return false;
}

// Check if a year is a leap year
bool isLeapYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

// Validate date
bool isValidDate(int day, int month, int year) {
    if (month < 1 || month > 12) {
        cout << "Invalid month! Please enter a value between 1 and 12." << endl;
        return false;
    }
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        cout << "Invalid day for the given month!" << endl;
        return false;
    }
    if (month == 2) {
        if (day > (isLeapYear(year) ? 29 : 28)) {
            cout << "Invalid day for February!" << endl;
            return false;
        }
    } else if (day < 1 || day > 31) {
        cout << "Invalid day! Please enter a value between 1 and 31." << endl;
        return false;
    }
    if (year < 1900 || year > 2026) {
        cout << "Invalid year! Please enter a value between 1900 and 2026." << endl;
        return false;
    }
    return true;
}

bool validationName(const string& name) {
    if (name.length() < 3 || name.length() > 20) {
        cout << "Invalid name!" << endl;
        return true;
    }
    return false;
}

bool validationAddress(const string& address) {
    if (address.length() < 5 || address.length() > 30) {
        cout << "Invalid address!" << endl;
        return true;
    }
    return false;
}

bool isValidGmail(const char* gmail) {
    // Regular expression for Gmail format
    regex gmailPattern("^[a-zA-Z0-9._]+@gmail\\.com$");

    // Check if the input matches the pattern
    return regex_match(gmail, gmailPattern);
}

bool isValidPhoneNumber(const char* phoneNo) {
    // Regular expression for phone number format
     regex phonePattern("^\\+?92[ -]?(\\(?\\d{3}\\)?)[ -]?\\d{7}$");

    // Check if the input matches the pattern
    return regex_match(phoneNo, phonePattern);
}
// -------------------- Class Definition --------------------

class Date {
    int dd, mm, yy;

public:
    // Constructor
    Date() : dd(1), mm(1), yy(1900) {}

    // Member Functions
    void setter();
    void getter() const;
};

// Setter: Input and validate date
void Date::setter() {
    do {
        cout << "Enter Event Date (dd): ";
        cin >> dd;
        cout << "Enter Event Month (mm): ";
        cin >> mm;
        cout << "Enter Event Year (yy): ";
        cin >> yy;
    } while (!isValidDate(dd, mm, yy) || !validInput());
}

// Getter: Display the date
void Date::getter() const {
    cout<< "\t\t\tEvent Date is  : " << dd << "/" << mm << "/" << yy ;
}


//Independent Class Event
class Event
{
protected:
	char Name[50];
	int eventId=1111;
	Date eventDate;
	char location[50];
	char eventTiming[60];
	int maxParticipants;
	int eventPrice;
public:
	void setter();
	void idSetter(int n);
	void getter();
	int returnID();

};

void Event::setter()
{
	
	
	do {
	cout << "Enter Event Name: ";
	cin.getline(Name, 50);
	} while (validationName(Name));
	
	eventDate.setter();
	
	do {
	cout << "Enter Event Location: ";
	cin.getline(location, 50);
	} while (validationAddress(location));

	do {
	cout << "Enter Event Timing(HH:MM): ";
	cin.getline(eventTiming, 60);
	if (!eventTiming[0] || strlen(eventTiming) > 60 || !strchr(eventTiming, ':')) 
    cout << "Invalid input. Please enter a valid event timing.\n";
    } while (!eventTiming[0] || strlen(eventTiming) > 60 || !strchr(eventTiming, ':'));
	
    
    do{
	cout << "Enter Num Max Participants: ";
	cin >> maxParticipants;
	}while (!validInput());
	
	do{
	cout << "Enter Event ticket Price: ";
	cin >> eventPrice;
	}while (!validInput());
}

void Event :: idSetter(int n)
{
	eventId+=n;
}

void Event :: getter()
{
	cout << "\n\t\t\tEvent ID       : " << eventId << endl;
    cout << "\t\t\tEvent Name     : " << Name << endl;
    // Assuming the Date class has a getter method to print the event date. 
    eventDate.getter();
    cout << "\n\t\t\tEvent Location : " << location << endl;
    cout << "\t\t\tEvent Timing   : " << eventTiming << endl;
    cout << "\t\t\tEvent Capacity : " << maxParticipants <<" People"<< endl;
    cout << "\t\t\tTicket Price   : $" << eventPrice << endl;	
    cout<<"--------------------------------------------------------------------------------"<<endl;
}


int Event::returnID()
{
	return eventId;
}
void save2disk(Event* ee[], int nn);
void readFfile(Event* ee[], int& nn);



//Independent Class Registration
class Registration
{
	int Id;
	char name[50];
	char gmail[60];
	char phoneNo[20];
	int eventid;
	bool status=false;
public:
	void getter();
	void setter();	
	void eventIdSetter(int id);
	char* returnusername();
	void usernameSetter(char n[50]);
	void changeStatus();
	bool returnStatus();
};

void Registration::setter()
{
	do{
	cout<<"Enter your Id: ";
	cin>>Id;
	}while (!validInput());
	
	do {
	cout<<"Enter Gmail: ";
	cin.getline(gmail,60);
	if(!isValidGmail(gmail))
	cout << "Invalid Gmail. Plz enter a valid Gmail address in standard format!" << endl;
	} while (!isValidGmail(gmail));
	
	do {
	cout<<"Enter Your Contact No: ";
	cin.getline(phoneNo,20);
	if (!isValidPhoneNumber(phoneNo)) {
    cout << "Invalid phone number. Please enter a valid phone number in Pakistani format (e.g., +92 300 1234567)." << endl;
    }
    } while (!isValidPhoneNumber(phoneNo)); 
}

void Registration::getter()
{
	cout<<"\n\t\t\tEvent Id     : "<<eventid;
	cout<<"\n\t\t\tUser Id      : "<<Id;
	cout<<"\n\t\t\tUser Name    : "<<name;
	cout<<"\n\t\t\tUser gmail   : "<<gmail;
	cout<<"\n\t\t\tUser phone NO: "<<phoneNo;
	if(status==true)
		cout<<"\n\n\t\t\t****Appliction Approved**** ";
	else
		cout<<"\n\n\t\t\tAppliction Pending..";
	cout<<"\n____________________________________________________________________ "<<endl;	
	
}

void Registration::eventIdSetter(int id)
{
	eventid=id;
}

char* Registration::returnusername()
{
	
	return name;
}

void Registration::usernameSetter(char n[50])
{
	strcpy(name, n);
}

void Registration::changeStatus()
{
	status=true;
}

bool Registration::returnStatus()
{
	return status;
}


void clearEventArray(Event* e[], int count);
void clearRegistrationArray(Registration* r[], int count);
void saveApplications(Registration* r[],int nn);
void loadApplications(Registration* r[],int& nn);

void clearEventArray(Event* e[], int count) {
    for (int i = 0; i < count; i++) {
        delete e[i]; // Delete each dynamically allocated event
        e[i] = nullptr; // Reset the pointer to nullptr to avoid dangling pointer
    }
}

void clearRegistrationArray(Registration* r[], int count) {
    for (int i = 0; i < count; i++) {
        delete r[i]; // Delete each dynamically allocated registration
        r[i] = nullptr; // Reset the pointer to nullptr to avoid dangling pointer
    }
}


// Base / Parent  Class
class User {
protected:
    char username[50];
    char password[50]="admin123";
    Event* e[MAX];
    Registration* r[MAX];
    int counter=0,count=0;

public:
    virtual bool login() = 0; // Pure virtual function
    void viewEvents();
};

void User::viewEvents()
{
	readFfile(e,count);
	for(int i=0;i<count;i++){
		cout<<"\t\t\t\t\t|  "<<i+1<<"  |"<<endl;
		cout<<"\t\t\t\t\t -----\n";
		e[i]->getter();
	}
		
	// Clear the dynamically allocated memory for events after viewing
    clearEventArray(e, count);	
}


//Child Class from Base
class Admin : virtual public User
{
protected:
	int count = 0;
public:
	int attempts = 0;
	bool login();
	bool checkPassword(const string& enteredPassword);
	void createEvents();
	void viewEvents();
	void updateEvents();
	void deleteEvents();
	void viewRegistrations();
};

bool Admin::checkPassword(const string& enteredPassword)
{
	return enteredPassword == password;
}


bool Admin::login()
{
	printCentered("_______________");
	printCentered(" ****LOGIN**** ");
	printCentered("_______________");

	string enteredPassword;
    int attempts = 0;
    const int maxAttempts = 3;
    bool isAuthenticated = false;

    do 
    {
        while (attempts < maxAttempts) 
        {
            cout << "Enter password: ";
            cin >> enteredPassword;

            if (checkPassword(enteredPassword)) 
            {
            	cout << endl;
                cout << ":) Login successful!" << endl;
                isAuthenticated = true; // Successful login
                int width = getConsoleWidth();
    			for (int i = 0; i < width; i++) cout << "-";
    			cout << endl;
                break;
            } 
            else 
            {
                attempts++;
                cout << endl;
                cout << "Incorrect Password. Attempts left: " << (maxAttempts - attempts) << endl;
            }
        }

        if (!isAuthenticated && attempts >= maxAttempts) 
        {
            cout << "Too many failed attempts. Please wait 30 seconds before trying again.\n";
            displayTimer(30); 
            attempts = 0; // Reset attempts after the timer
        }

    } while (!isAuthenticated); 

    return true; // Return true if login is successful
}

void Admin::createEvents() {
	readFfile(e, count);
	cout << "--------------------------\n";
	char ch;
	do
	{
		if (count < MAX) {
			e[count] = new Event;  // Allocate memory for a new event
			e[count]->idSetter(count);
			e[count]->setter();   // calling Event setter
			count++;
		}
		else {
			cout << "Cannot add more events. Maximum limit reached." << endl;
			break;
		}
		cout << "Do you want add another Event(Y/N)? : ";
		cin >> ch;
		if ((ch != 'Y') && (ch != 'y'))
			break;
	} while (true);
	save2disk(e, count);
	// Clear the dynamically allocated memory for events after saving to disk
	clearEventArray(e, count);
}

void Admin::viewEvents()
{
	User::viewEvents();	
}


void Admin::updateEvents()
{
	readFfile(e, count);
	int ID, found = 0;
	cout << "Enter Event ID to Update: ";
	cin >> ID;
	for (int i = 0; i < count; i++)
	{
		if (e[i]->returnID() == ID)
		{
			cout << "Updating Event....\n";
			e[i]->setter();
			found = 1;
			cout << " Event Updated successfull.\n";
		}
	}

	if (found == 0)
		cout << "Event not found.";

	ofstream outfile;
	outfile.open("Events.DAT", ios::out | ios::binary);
	if (!outfile)
	{
		cout << "Couldn't open file.\n";
		return;
	}
	outfile.write((char*)&count, sizeof(int));
	// Loop through each object and save its type and data
	for (int i = 0; i < count; i++)
	{
		outfile.write((char*)e[i], sizeof(Event));
	}
	outfile.close();
	cout << "Data saved successfully!\n";

	// Clear the dynamically allocated memory for events after viewing
	clearEventArray(e, count);
}

void Admin::deleteEvents()
{
	readFfile(e, count);
	int ID, found = 0;
	cout << "Enter Event ID to Delete: ";
	cin >> ID;
	for (int i = 0; i < count; i++)
	{
		if (e[i]->returnID() == ID)
		{
			cout << "Deleting Event....";
			e[i] = e[i + 1];
			count--;
			found = 1;
			cout << " Event Deleted successfull.";
		}
	}

	if (found == 0)
		cout << "Event not found.";

	ofstream outfile;
	outfile.open("Events.DAT", ios::out | ios::binary);
	if (!outfile)
	{
		cout << "Couldn't open file.\n";
		return;
	}
	outfile.write((char*)&count, sizeof(int));
	// Loop through each object and save its type and data
	for (int i = 0; i < count; i++)
	{
		outfile.write((char*)e[i], sizeof(Event));
	}
	outfile.close();
	cout << "Data saved successfully!\n";

	// Clear the dynamically allocated memory for events after viewing
	clearEventArray(e, count);
}



void Admin::viewRegistrations()
{
	loadApplications(r,counter);
	char ch;
	for(int i=0;i<counter;i++)
	{
		cout<<"\t\t\tApplication # "<<i+1<<endl;
		r[i]->getter();
	}
	for (int j=0;j<counter;j++)
	{	if(r[j]->returnStatus()==false)
		{
			cout<<endl;
			printCentered("*APPROVE APPLICATIONS*");
			cout<<"____________________________________________________________________\n";
			cout<<"\t\t\tApplication # "<<j+1<<endl;
			r[j]->getter(); // Display registration details
	        cout<<"Enter[Y/y] to approve Application: ";
	        cin>>ch;
			if(ch=='y'||ch=='Y')
			r[j]->changeStatus();
		}       
	}
	saveApplications(r,counter);
	// clear dynamically allocated memory 
	clearRegistrationArray(r, counter);
}


void save2disk(Event* ee[], int nn) {
	ofstream outfile("Events.DAT", ios::out | ios::binary);
	if (!outfile) {
		cout << "Couldn't open file OR No Events available.\n";
		return;
	}

	outfile.write((char*)&nn, sizeof(nn)); // Save the number of events
	for (int i = 0; i < nn; i++) {
		outfile.write((char*)ee[i], sizeof(Event));
	}

	outfile.close();
	cout << "Data saved successfully!\n";
}


void readFfile(Event* ee[], int& nn) {
	ifstream infile("Events.DAT", ios::in | ios::binary);
	if (!infile) {
		cout << "Couldn't open file OR No Events available.\n";
		return;
	}

	infile.read((char*)&nn, sizeof(nn)); // Read the number of events
	for (int i = 0; i < nn; i++) {
		ee[i] = new Event; // Allocate memory for each Event object
		infile.read((char*)ee[i], sizeof(Event));
	}

	infile.close();
}


//Drived class from User class
class Attendee :virtual public User
{
	char regName[50];
	char regPassword[50];
public:
	bool login();
	void Register();
	void viewEvents();
	void registerForEvent();
	void checkRegStatus();
};

bool Attendee::login()
{
	printCentered("_______________");
	printCentered(" ****LOGIN**** ");
	bool isAuthenticated=false;
	cout<<"Enter Username:";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.getline(username,50);
	cout<<"Enter Password:";
	cin.getline(password,50);
	ifstream infile("users.dat", ios::in | ios::binary);
    if (!infile) {
        cout << "User not Registered.\n";
    }
    
    
	while (infile.read((char*)regName, sizeof(regName))) {
        infile.read((char*)regPassword, sizeof(regPassword));

        // Check if the entered credentials match the ones in the file
        if (strcmp(username, regName) == 0 && strcmp(password, regPassword) == 0) {
            isAuthenticated = true;
            cout << "Login successful! Welcome, " << username << "!\n";
            break;
        }
    }

    infile.close();
    if (!isAuthenticated) {
        cout << "Login Failed! Wrong Password or User doesn't Exist.. " << "!\n";
        return false;
	}
	return true;
}

void Attendee::Register()
{
	printCentered("______________________");
	printCentered("   ****REGISTER****   ");
	printCentered("______________________");

	cout<<"Enter Username For Account Registration:";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.getline(regName,50);	
	cout<<"Enter Password For Account Registration:";
	cin.getline(regPassword,50);
	
	// Open a file in append mode to store username and password
    ofstream outfile("users.dat", ios::app | ios::binary);
    if (!outfile) {
        cout << "Error opening file for writing.\n";
        return;
    }

    outfile.write((char*)regName, sizeof(regName));       // Store username
    outfile.write((char*)regPassword, sizeof(regPassword)); // Store password

    outfile.close();
    cout << "Account registered successfully and saved to file.\n";
}

void Attendee::registerForEvent()
{
	User::viewEvents();
	loadApplications(r,counter);
	readFfile(e,count);
	int id;
	char ch;
	bool exsists=false;
	do
	{
		cout<<"Enter Event Id to Register:";
		cin>>id;
		for(int j=0;j<count;j++){
			
			if(e[j]->returnID()==id){
				cout<<"Event Exsists...\n";
				exsists=true;
				r[counter]=new Registration;
				r[counter]->eventIdSetter(id);
				r[counter]->usernameSetter(username);
				r[counter]->setter();
				counter++;
			}
		}
		
		if(exsists==false)
			cout<<"Event doesn't Exsist.\n";
		
		cout<<"Do you want to register for another Event: ";
		cin>>ch;
	}while(ch!='N'&&ch!='n');
	saveApplications(r,counter);
	// clear dynamically allocated memory
	clearRegistrationArray(r, counter);
	clearEventArray(e, count);
}
		
void Attendee::checkRegStatus()
{
	loadApplications(r,counter);
	bool found=false;
	for (int i=0;i<counter;i++)
	{
		if (strcmp(username, r[i]->returnusername()) == 0) {
            r[i]->getter(); // Display registration details
            found = true;
        }
	}
	if(!found)
	cout<<"\n***NO Applications Under Username: "<<username<<endl;
	// clear dynamically allocated memory
	clearRegistrationArray(r, counter);
}

void Attendee::viewEvents()
{
	User::viewEvents();
}


void saveApplications(Registration* r[],int nn)
{
	 ofstream outfile("applications.dat", ios::out | ios::binary);
    if (!outfile) {
        cout << "Couldn't open file for writing.\n";
        return;
    }

    outfile.write((char*)&nn, sizeof(nn)); // Save the number of events
    for (int i = 0; i < nn; i++) {
        // Write individual fields using getters
       outfile.write((char*)r[i],sizeof(Registration));
    }

    outfile.close();
    cout << "Data saved successfully!\n";
}

void loadApplications(Registration* r[],int& nn)
{
    ifstream infile("applications.dat", ios::in | ios::binary);
    if (!infile) {
        cout << "Couldn't open file for reading.\n";
        return;
    }

    infile.read((char*)&nn, sizeof(nn)); // Read the number of events
    for (int i = 0; i < nn; i++) {
        r[i] = new Registration; // Allocate memory for each Event object
		infile.read((char*)r[i],sizeof(Registration));
    }
    infile.close();

}

void adminMenu() {
    int admChoice;
    Admin A;
    if (A.login()) {
        do {
            printCentered("============================");
            printCentered("| 1. CREATE EVENTS         |");
            printCentered("| 2. VIEW EVENTS           |");
            printCentered("| 3. UPDATE EVENTS         |");
            printCentered("| 4. DELETE AN EVENT       |");
            printCentered("| 5. VIEW REGISTRATIONS    |");
            printCentered("| 6. RETURN TO MAIN MENU   |");
            printCentered("| 7. EXIT                  |");
            printCentered("============================");
            cout << "Enter your choice: ";

            // Validate the input for admChoice
            cin >> admChoice;

            if (cin.fail()) {
                cout << "Invalid input! Please enter a number between 1 and 8." << endl;
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the invalid input
                continue; // Skip the rest of the loop and prompt again
            }

            switch (admChoice) {
                case 1:
                    A.createEvents();
                    break;
                case 2:
                    A.viewEvents();
                    break;
                case 3:
                    A.updateEvents();
                    break;
                case 4:
                    A.deleteEvents();
                    break;
                case 5:
                    A.viewRegistrations();
                    break;
                case 6:
                   cout << "Returning to main menu...\n";
                    return;  // Return to the main menu
                case 7:
                    cout << "Exiting from the program...\n";
                    exit(0);  // Exit the program
                default:
                    cout << "Invalid choice! Please enter a valid option between 1 and 8.\n";
                    break;
            }
        } while (true);
    } else {
        cout << "Invalid login credentials. Access denied.\n";
    }
}


void attendeeMenu() {
    int attenChoice;
    Attendee E;
    bool exitAttendeeMenu = false;
    int attenChoice2;
    do {
        printCentered("=========================");
        printCentered("|     1. REGISTER       |");
        printCentered("|     2. LOGIN          |");
        printCentered("|     3. RETURN TO MENU |");
        printCentered("=========================");
        cout << "Enter your choice: ";
        
        // Validate the input for attenChoice
        cin >> attenChoice;

        if (cin.fail()) {
            cout << "Invalid input! Please enter a number (1, 2, or 3)." << endl;
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the invalid input
            continue; // Skip the rest of the loop and prompt again
        }

        switch (attenChoice) {
            case 1:
                E.Register();
                break;
            case 2:
                if (E.login()) {
                    do {
                        printCentered("=================================");
                        printCentered("| 1. VIEW EVENTS                |");
                        printCentered("| 2. APPLY FOR EVENT            |");
                        printCentered("| 3. CHECK APPLICATION STATUS   |");
                        printCentered("| 4. RETURN TO MAIN MENU        |");
                        printCentered("=================================");
                        cout << "Enter your choice: ";
                        
                        // Validate the input for attenChoice2
                        cin >> attenChoice2;

                        if (cin.fail()) {
                            cout << "Invalid input! Please enter a number (1, 2, 3, or 4)." << endl;
                            cin.clear(); // Clear the error flag
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the invalid input
                            continue; // Skip the rest of the loop and prompt again
                        }

                        switch (attenChoice2) {
                            case 1:
                                E.viewEvents();
                                break;
                            case 2:
                                E.registerForEvent();
                                break;
                            case 3:
                                E.checkRegStatus();
                                break;
                            case 4:
                                cout << "Returning To Main Menu...\n";
                                exitAttendeeMenu = true;
                                break;
                            default:
                                cout << "Invalid input. Please enter a valid choice." << endl;
                        }
                    } while (!exitAttendeeMenu);
                }
                break;
            case 3:
                cout << "EXITING...\n";
                exitAttendeeMenu = true;
                break;
            default:
                cout << "Invalid input. Please enter a valid choice." << endl;
        }
    } while (!exitAttendeeMenu);
}


int main() {
    int mainChoice;
    cout << left;
    printCentered("|--------------------------------------|");
    printCentered("|        EVENT MANAGEMENT SYSTEM       |");
    printCentered("|--------------------------------------|");
    int width = getConsoleWidth();
    for (int i = 0; i < width; i++) cout << "_";
    cout << endl;
    
    do {
        printCentered("|               MAIN MENU              |");
        for (int i = 0; i < width; i++) cout << "_";
        cout << endl;
        printCentered("============================");
        printCentered("|       1. ORGANIZER       |");
        printCentered("|       2. ATTENDEE        |");
        printCentered("|       3. EXIT            |");
        printCentered("============================");
        cout << "Enter your choice: ";

        // Check if the input is a valid integer
        cin >> mainChoice;

        // Validate if the user entered a valid integer
        if (cin.fail()) {
            cout << "Invalid input! Please enter a number (1, 2, or 3)." << endl;

            // Clear the error flag
            cin.clear();
            // Ignore the invalid input
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        } else {
            // Handle the valid input
            switch (mainChoice) {
                case 1:
                    adminMenu();
                    break;
                case 2:
                    attendeeMenu();
                    break;
                case 3:
                    cout << "EXITING From Program..\n";
                    break;
                default:
                    cout << "Invalid choice. Please enter 1, 2, or 3.\n";
            }
        }

    } while (mainChoice != 3);

    return 0;
}
