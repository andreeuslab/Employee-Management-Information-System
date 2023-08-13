/*
 *  Employee Management Information System
 *  Written by Jonathan Vazquez
 *  August 10, 2023
 *
 *  Goal: Keep track of Employees at a company, JVs Better Software llc.
 *
 * */
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

const char screenWidth = 'x';

class Employee{
    private:
        static int index;
        string firstName;
        string lastName;
        string userId;
        string password;
        string department;
    public:
        Employee(): firstName(""),lastName(""),userId(""),password(""),department("General Employee"){index++;}
        Employee(string tFirstName, string tLastName, string tUserId, string tPass, int tDepartId){
            //index++;
            firstName = tFirstName;
            lastName = tLastName;
            userId = tUserId;
            password = tPass;
            if(tDepartId == 1){
                department = "Human Resource";
            }else if(tDepartId == 2){
                department = "Management";
            }else{
                department = "General Employee";
            }
        }
        
        void view(){
            cout << "Employee " <<  ""<< endl;
            cout << "Name: " + firstName + " " + lastName << endl;
            cout << "User Id: " + userId << endl;
            cout << "Department: " + department << endl;
        }
        void getFullName(){
            cout << "Name: " + firstName + " " + lastName;
        }
        string getUserId(){
            return userId;
        }
        string getPassword(){
            return password;
        }
        string getDepartment(){
            return department;
        }
        int getIndex(bool loggedIn){
            if(loggedIn)
                return 0;
            else
                return 0;
        }
};

void printHorizontalLine(void){
  // 1 byte, when casted to int(2) = 50, decimal based on ASCII
  cout << "+";
  for(int i=0; i<int(screenWidth); i++){
    cout << "*";
  }
  cout << "+" << endl;
}
void printHorizontalLine(bool){
  cout << "+" << setw(int(screenWidth+1)) << "+" << endl;
}
void goodByeMessage(string msg){
  system("clear");
  cout << endl;
  cout << msg << endl;
  cout << "Thank you for trying out my program." << endl;
  cout << "Wherever in the wild you may be, have a wonderful day!" << endl << endl;
  exit(1);
}
void generatingUserData(vector<Employee> *employees){
    
}

int main(){
    vector<Employee> employees;
    Employee *newEmployee = new Employee("Jonathan","Vazquez","zbdt4n","studycom",1);
    employees.push_back(*newEmployee);
    delete newEmployee;
    int tries = 0;

    char userInput;
    do{
        system("clear");
        printHorizontalLine();
        printHorizontalLine(1);
        cout << "+" << setw(50) << "JVs Better Software LLC"      << setw(71) << "+" << endl;
        cout << "+" << setw(55) << "Author: Jonathan Vazquez" << setw(66) << "+" << endl;
        printHorizontalLine(1);
        printHorizontalLine(1);
        cout << "+" << setw(55) << "FULL SCREEN RECOMMENDED" << setw(66) << "+" << endl;
        printHorizontalLine(1);
        printHorizontalLine();
        cout << "Next screen, enter n: ";
        cin >> userInput;
        tries++;
        if(tries >= 3)
            goodByeMessage("Error: You are not entering correct character.");
    }while(userInput != 'n');
 
    string userId, userPassword;
    tries = 0;
    bool isLoggedIn = true;
    do{
        system("clear");
        printHorizontalLine();
        printHorizontalLine(1);
        cout << "+" << "Purpose: Track all employees within the Better Software LLC Business" << "+" << endl;
        printHorizontalLine(1);
        printHorizontalLine(1);
        cout << "+" << "Program Rules" << endl;
        cout << "+" << "1. Submit 1 single file, hence no read/write to file, dynamic creation." << endl;
        cout << "+" << "2. You are responsible for adding/manipulating other employees at runtime!" << endl;
        cout << "+" << "3. Default HR Sample Users [User Id, Password] -> [zbdt4n, studycom]" << "+" << endl;
        printHorizontalLine(1);
        printHorizontalLine();
        cout << "User Identification Login: ";
        cin >> userId;
        cout << "User Password Login: ";
        cin >> userPassword;
        tries++;
        if(tries >= 3){
            goodByeMessage("Error: Incorrect user identification login.");
        }
    }while(userId != "zbdt4n" || userPassword != "studycom"); 
        
    // Commence usage of employee while we are logged in, otherwise prompt user credentials.
    if(isLoggedIn){
        int option;
        cout << "JVs Better Software LLC Employee Portal" << endl;
        cout << "Department Identification: " << employees[1].getDepartment() << endl;
        cout << "Welcome" << endl;
        cout << "What would you like to do?" << endl;
        if(employees[1].getDepartment() == "Human Resources"){
            switch(option){
                case 1:{
                    // view own file
                    break;
                }
                case 2: {
                    //add new employee
                    string firstName, lastName, userId, password;
                    int departmentId;
                    cout << "Enter new employee first name: ";
                    cin >> firstName;
                    cout << "Enter new employee last name: ";
                    cin >> lastName;
                    cout << "Enter new employee custom user identification: ";
                    cin >> userId;
                    password = "studycom";
                    cout << "New employee default password set!" << endl;
                    cout << "Department Identification integer: 1 {HR}, 2 {Management}, any other int {General Employee}" << endl;
                    cin >> departmentId;
                    Employee *newEmp = new Employee(firstName,lastName,userId,password,departmentId);
                    employees.push_back(*newEmp);
                    delete newEmp;
                    break;
                }
                case 3:{
                    // search employee file
                    break;
                }
                case 4: 
                {
                    // modify employee file
                    break;
                }
                case 5:{
                    // delete employee file
                    break;}
                default:{ 
                    //logout
                    break;}
            }
        }else if(employees[1].getDepartment() == "Management"){
            switch(option){
                case 1:{
                    // view own file
                    break;}
                case 2:{
                    // search employee file
                    break;}
                default:{ 
                    //logout
                    break;}
            }
        }else{
            switch(option){
                case 1:{
                    // view own file
                    break;}
                default:{ 
                    //logout
                    break;}
            }
        }
    }else{
        // bring it back to the login page, via function call
    }
    return 0;
}