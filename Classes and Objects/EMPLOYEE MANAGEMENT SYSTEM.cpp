//EMPLOY MANAGEMENT SYSTEM
//The program stores and display the data of manager,scientist and labor as employ
//Programmer Name: Wahab Ejaz
//Compiler: gcc
//Date: 1 Dec 2024

#include <iostream>
#include <string>
#include <cctype>
using namespace std;
class myDate{
	private:
	int dd,mm,yy;
	public:
	//constructor
	myDate(int d=0,int m=0,int y=0):dd(d),mm(m),yy(y){}
	void setter();
	void getter();	
};
void myDate:: setter()
{
	while (dd < 1 || dd > 31){
	cout << "Enter date(dd): ";
	cin >> dd;
	if (dd<1 || dd> 31)
	cout << "(X)Invalid Input! Please enter again." << endl;
	}
	while (mm < 1 || mm > 31){
	cout << "Enter month(mm): ";
	cin >> mm;
	if (mm < 1 || mm > 31)
	cout << "(X)Invalid Input! Please enter again." << endl;
	}
	while(yy < 1000 || yy > 9999){
	cout << "Enter year(yyyy): ";
	cin >> yy;
	if (yy < 1000 || yy > 9999)
	cout << "(X)Invalid Input! Please enter again." << endl;
	}
}
void myDate :: getter()
{
	cout << dd << "/" << mm << "/" << yy << endl;
}
class employ{
	int empNo;
	string name;
	myDate DOB,DOJ;
	public:
	//employ class constructor
	employ(int eno=0,string n="",int d1=0,int m1=0,int y1=0,int d2=0,int m2=0,int y2=0):
	DOB(d1,m1,y1),DOJ(d2,m2,y2),empNo(eno),name(n){}
	void setter();
	void getter();
};
void employ::setter() {
	cout << "Enter employ number: ";
	cin >> empNo;
	cout << "Enter employ name: ";
	cin.ignore();
	getline(cin,name);
	cout << "--Enter date of birth: " << endl;
	DOB.setter();
	cout << "--Enter date of joining: " << endl;
	DOJ.setter() ;
	
}
void employ :: getter(){
	cout << "Employ NO: " << empNo << endl;
	cout << "Employ Name: " << name << endl;
	cout << "Date of birth: ";
	DOB.getter();
	cout << "Date of joining: ";
	DOJ.getter() ;
}
class manager:public employ{
	string eDesig;
	float eDues;
	public: 
	//manager class constructor
	manager(string ed="",float ecd=0.0,int eno=0,string n="",int d1=0,int m1=0,int y1=0,int d2=0,int m2=0,int y2=0):
	employ(eno,n,d1,m1,y1,d2,m2,y2),eDesig(ed),eDues(ecd){}
	void setter();
	void getter();
};
void manager::setter() {
	employ::setter();
	cout << "Enter manager designation: " ;
	cin.ignore() ;
	getline(cin,eDesig);
	cout << "Enter manager club dues: " ;
	cin >> eDues;
}
void manager::getter() {
	employ::getter();
	cout << "Manager designation: " <<  eDesig << endl;
	cout << "Manager club dues: " << eDues << endl;
}
class scientist:public employ{
	string efield;
	int empPub;
	public:
		//scientist class constructor
	scientist(string field="",int articles=0,int eno=0,string n="",
	int d1=0,int m1=0,int y1=0,int d2=0,int m2=0,int y2=0):employ(eno,n,d1,m1,y1,d2,m2,y2), 
	efield(field),empPub(articles){}
		void setter();
		void getter();
};
void scientist::setter()
{
	employ::setter() ;
	cout << "Enter scientist field: ";
	cin.ignore() ;
	getline(cin,efield);
	cout << "Enter total no of scientist publications: ";
	cin >> empPub;
}
void scientist::getter()
{
	employ::getter() ;
	cout << "Scientist field: "<< efield << endl;
	cout << "Scientist publications: " << empPub << endl;
}
class labor:public employ{
	char eshift;
	float ehw,edw,ehr; //edw means employ daily wage
	public:
	//labor class constructor
	labor(char routine='\0',float hrate=0.0,float hwork=0.0,float pay=0.0
	,int eno=0,string n="",int d1=0,int m1=0,int y1=0,int d2=0,int m2=0,int y2=0):
	employ(eno,n,d1,m1,y1,d2,m2,y2),eshift(routine),ehr(hrate),ehw(hwork),edw(pay){}
	void setter();
	void getter();
};
void labor::setter()
{
	employ::setter() ;
	cout << "Enter shift(M->morning/E->evening/N->night): ";
	cin >> eshift;
	if (eshift == 'e')
	toupper(e);
	cout << "Enter hours worked: ";
	cin >> ehw;
	cout << "Enter hourly rate: ";
	cin >> ehr;
	edw = ehw*ehr;
}
void labor::getter()
{
	employ::getter() ;
	cout << "shift(M->morning/E->evening/N->night): " << eshift << endl;
	cout << "Hours worked: "<< ehw << endl;
	cout << "Hourly rate: "<< ehr << endl;
	cout << "Daily wage: "<< edw << endl;
}
int main()
{
	manager m1;
	scientist s1;
	labor l1;
	char choice,ch;
	do{
		system("color 0F");
	cout << "     ============MAIN MENU============" << endl;
	cout << "      ---EMPLOY MANAGEMENT SYSTEM---  " << endl;
	cout << endl;
	cout << "             1. MANAGER               " << endl;
	cout << "             2. SCIENTIST             " << endl;
	cout << "             3. LABOR                 " << endl;
	cout << "             4. EXIT                  " << endl;
	cout << "_________________________________" << endl;
	cout << "Enter your choice: " ;
	cin >> choice;
	switch (choice)
	{
		case '1' :
			do{
				cout << endl;
			cout << "======MANAGER MENU====== " << endl;
			cout << "  1. STORE DATA          " << endl;
			cout << "  2. DISPLAY DATA        " << endl;
			cout << "  3. RETURN TO MAIN MENU " << endl;
			cout << "Enter your choice: ";
			cin >> ch;
			if (ch == '1'){
			m1.setter();
			cout << "DATA STORED SUCCESSFULLY!" << endl;
			cout << endl;
			}
			else if (ch== '2'){
			cout << endl;
			cout << "---DISPLAYING MANAGER DATA---" << endl;
			m1.getter() ;
		    }
			else if (ch == '3')
			break;
			else if (ch != '1' && ch != '2' && ch!=3 )
			cout << "Invalid Input! Please enter valid number choice." << endl;
		}while(ch !=3);
		break;
		
		case '2' :
			do{
				cout << endl;
			cout << "======SCIENTIST MENU======" << endl;
			cout << "  1. STORE DATA           " << endl;
			cout << "  2. DISPLAY DATA         " << endl;
			cout << "  3. RETURN TO MAIN MENU  " << endl;
			 
			cout << "Enter your choice: ";
			cin >> ch;
			if (ch == '1'){
			s1.setter();
			cout << "DATA STORED SUCCESSFULLY!" << endl;
			cout << endl;
			}
			else if (ch== '2'){
			cout << endl;
			cout << "---DISPLAYING SCIENTIST DATA---" << endl;
			s1.getter() ;
			}
			else if (ch == '3')
			break;
			else if (ch != '1' && ch != '2' && ch!=3 )
			cout << "Invalid Input! Please enter valid number choice." << endl;
			}while (ch!=3);
			break;
	
			case '3' :
			do{
				cout << endl;
			cout << "======LABOR MENU======  " << endl;
			cout << "  1. STORE DATA         " << endl;
			cout << "  2. DISPLAY DATA       " << endl;
			cout << "  3. RETURN TO MAIN MENU" << endl;
			cout << "Enter your choice: ";
			cin >> ch;
			if (ch == '1'){
			l1.setter();
			cout << "DATA STORED SUCCESSFULLY!" << endl;
			cout << endl;
			}
			else if (ch== '2'){
			cout << endl;
			cout << "---DISPLAYING LABOR DATA---" << endl;
			l1.getter() ;
			}
			else if (ch == '3')
			break;
			else if (ch != '1' && ch != '2' && ch!=3 )
			cout << "Invalid Input! Please enter valid number choice." << endl;
			}while (ch!=3);
			break;
	
			case '4' :
			cout << "Program exit successfully!" << endl;
			return 0;
			
			default :
				
			cout << "INVALID INPUT! Please enter valid number." << endl;
			break;
		}
			
			}while (true);
			return 0;
	}