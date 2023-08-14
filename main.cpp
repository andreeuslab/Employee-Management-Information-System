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
        string firstName;
        string lastName;
        string userId;
        string password;
        string department;
    public:
        Employee(): firstName(""),lastName(""),userId(""),password(""),department(""){}
        Employee(string tFirstName, string tLastName, string tUserId, string tPass, int depId){
            firstName = tFirstName;
            lastName = tLastName;
            userId = tUserId;
            password = tPass;
            department = setDepartmentByClassId(depId);
        }

        // Action Methods
        void view(){
            cout << "+" << setw(50) << "Employee " <<  setw(50) << "+" << endl;
            cout << "+" << setw(50) << "Name: " + firstName + " " + lastName << setw(50) << "+" << endl;
            cout << "+" << setw(50) << "User Id: " + userId << setw(50) << "+" << endl;
            cout << "+" << setw(50) << "Department: " + department << setw(50) << "+" << endl;
        }
        

        // Setters Methods
        void setFirstName(string tFirstName){
            firstName = tFirstName;
        }
        void setLastName(string tLastName){
            lastName = tLastName;
        }
        void setUserId(string tUserId){
            userId = tUserId;
        }
        void setPassword(string tPass){
            password = tPass;
        }
        string setDepartmentByClassId(int id){
            string department_classification[] = {"Human Resource", "Management", "General Employee"};
            return department = department_classification[id];
        }
        void setDepartmentByTitle(string tDepartment){
            department = tDepartment;
        }

        // Getter Methods
        string getDepartmentClassification(){
            return department;
        }
        int getDepartmentByClassId(){
            if(department == "Human Resource") return 0;
            else if(department == "Management") return 1;
            else return 2;
        }
        string getFullName(){
            return firstName + " " + lastName;
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

int getIndexOfVector(vector<Employee> employee, string tempId){
    int temporaryIndex;
    for(vector<int>::size_type i =0; i<employee.size(); i++){
        if(employee.at(i).getUserId() == tempId) temporaryIndex = i;
    }
    return temporaryIndex;
}

int main(){
    vector<Employee> employees;
    Employee *newEmployee = new Employee("Jonathan","Vazquez","zbdt4n","studycom",0);
    employees.push_back(*newEmployee);
    delete newEmployee;
    int vIndex;
    char userInput;
    
    bool runapp = true;
    char pauseButton;

    while(runapp){
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
            cout << "Next screen, enter n: " << endl;
            cout << "Exit Application, enter x" << endl;
            cout << "Entry: ";
            cin >> userInput;
            if(userInput == 'x'){
                goodByeMessage("Exiting Application!");
            }
        }while(userInput != 'n');
    
        string userId, userPassword;    
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
            vIndex = getIndexOfVector(employees, userId); 
        }while(userId != employees.at(vIndex).getUserId() || userPassword != employees.at(vIndex).getPassword()); 

        bool logout = false;
        bool isLoggedIn = true;
        while(isLoggedIn){
            cout << "At this point, what is my departmentclassid? " << employees.at(0).getDepartmentByClassId() << endl;
            int option;
            if((employees.at(vIndex).getDepartmentByClassId() == 0)){
                system("clear");
                printHorizontalLine();
                printHorizontalLine(1);
                cout << "JVs Better Software LLC Employee Portal" << endl;
                cout << "Department Identification: " << employees.at(vIndex).getDepartmentClassification() << endl;
                cout << "Welcome "; 
                cout << employees.at(vIndex).getFullName() << endl;

                do{
                    cout << "What would you like to do?" << endl;
                    cout << "1. Would you like to view own personal file?" << endl;
                    cout << "2. Would you like to add new employee to database?" << endl;
                    cout << "3. Would you like to search for a specific employee file?" << endl;
                    cout << "4. Would you like to modify a specific employee file?" << endl;
                    cout << "5. Would you like to delete a specific employee file?" << endl;
                    cout << "6. logout?" << endl;
                    printHorizontalLine(1);
                    printHorizontalLine(0);
                    cout << "Enter your integer choice: ";
                    cin >> option;
                    switch(option){
                        case 1:{
                            system("clear");
                            printHorizontalLine();
                            printHorizontalLine(1);
                            employees.at(vIndex).view(); 
                            printHorizontalLine(1);
                            printHorizontalLine();
                            cout << endl << endl << "enter next screen: ";
                            cin >> pauseButton;
                            system("clear");                      
                            break;
                        }
                        case 2: {
                            system("clear");
                            //add new employee
                            string firstName, lastName, userId, password;
                            int departmentId;
                            printHorizontalLine();
                            printHorizontalLine(1);
                            cout << "Enter new employee first name: ";
                            cin >> firstName;
                            cout << "Enter new employee last name: ";
                            cin >> lastName;
                            cout << "Enter new employee custom user identification: ";
                            cin >> userId;
                            password = "studycom";
                            cout << "New employee default password set!" << endl;
                            cout << "Department Identification integer: 0 {HR}, 1 {Management}, any other int {General Employee}" << endl;
                            cin >> departmentId;
                            Employee *newEmp = new Employee(firstName,lastName,userId,password,departmentId);
                            employees.push_back(*newEmp);
                            delete newEmp;

                            // check user was added, give confirmation of such
                            printHorizontalLine(1);
                            printHorizontalLine();
                            cout << "user has being added!" << endl;

                            cout << endl << endl << "enter next screen: ";
                            cin >> pauseButton;
                            system("clear");
                            break;
                        }
                        case 3:{
                            int employeeIndex;
                            system("clear");
                            // search employee file
                            printHorizontalLine();
                            printHorizontalLine(1);
                            cout << "Here are all the current employees by Name: " << endl;
                            for(vector<int>::size_type i =0; i<employees.size(); i++){
                                cout << i << ". ";
                                cout << employees.at(i).getFullName() << endl;
                            }
                            cout << "Interested in viewing any specific employee file?" << endl;
                            cout << "Enter employee index: ";
                            cin >> employeeIndex;
                            if((vector<int>::value_type)employeeIndex > employees.size()){
                                cout << "Incorrect entry!" << endl;
                            }
                            employees.at(employeeIndex).view();
                            printHorizontalLine(1);
                            printHorizontalLine();
                            cout << endl << endl << "enter any character for next screen: ";
                            cin >> pauseButton;
                            system("clear");
                            break;
                        }
                        case 4: 
                        {
                            // It is imperative to make sure user is not able to delete his own account.
                            // If i do delete my own login account, objects shift.
                            int employeeIndex;
                            int modifyOption;
                            system("clear");
                            // modify employee file
                            printHorizontalLine();
                            printHorizontalLine(1);
                            // search employee file
                            cout << "Here are all the current employees by Name: " << endl;
                            for(vector<int>::size_type i =0; i<employees.size(); i++){
                                cout << i << ". ";
                                cout << employees.at(i).getFullName() << endl;
                            }
                            printHorizontalLine(1);
                            printHorizontalLine(0);
                            cout << "Interested in viewing any specific employee file?" << endl;
                            cout << "Enter employee index: ";
                            cin >> employeeIndex;
                            cout << endl;
                            if((vector<int>::value_type)employeeIndex > employees.size()){
                                cout << "Incorrect entry!" << endl;
                            }
                            employees.at(employeeIndex).view();
                            printHorizontalLine(1);
                            string firstName, lastName, userId, password, department;
                            cout << "1. Modify First Name" << endl;
                            cout << "2. Modify Last Name" << endl;
                            cout << "3. Modify User Identification" << endl;
                            cout << "4. Modify Password" << endl;
                            cout << "5. Modify Department" << endl;
                            printHorizontalLine(1);
                            cout << "Enter Modification number: ";
                            cin >> modifyOption;
                            if(modifyOption == 1){
                                cout << "Enter new employee first name: ";
                                cin >> firstName;
                                employees.at(employeeIndex).setFirstName(firstName);
                            }else if(modifyOption == 2){
                                cout << "Enter new employee last name: ";
                                cin >> lastName;
                                employees.at(employeeIndex).setLastName(lastName);
                            }else if(modifyOption == 3){
                                cout << "Enter new employee custom user identification: ";
                                cin >> userId;
                                employees.at(employeeIndex).setUserId(userId);
                            }else if(modifyOption == 4){
                                cout << "Enter new employee password: ";
                                cin >> password;
                                employees.at(employeeIndex).setPassword(password);
                            }else if(modifyOption == 5){
                                cout << "Enter new employee department: \n[0]";
                                cin >> department;
                                employees.at(employeeIndex).setDepartmentByTitle(department); // careful that user enters correctly
                            }else{
                                cout << "No modification made" << endl;    
                            }
                            printHorizontalLine(1);
                            printHorizontalLine();
                            cout << endl << endl << "enter next screen: ";
                            cin >> pauseButton;
                            system("clear");
                            break;
                        }
                        case 5:{
                            int employeeIndex;
                            system("clear");
                            // delete employee file
                            printHorizontalLine();
                            printHorizontalLine(1);
                            cout << "Here are all the current employees by Name: " << endl;
                            for(vector<int>::size_type i =0; i<employees.size(); i++){
                                cout << i << ". ";
                                cout << employees.at(i).getFullName() << endl;
                            }
                            cout << "Which account would you like to erase, enter index id: ";
                            cin >> employeeIndex;
                            employees.erase(employees.begin()+employeeIndex);
                            cout << "Here are all the current employees by Name: " << endl;
                            for(vector<int>::size_type i =0; i<employees.size(); i++){
                                cout << i << ". ";
                                cout << employees.at(i).getFullName() << endl;
                            }
                            printHorizontalLine(1);
                            printHorizontalLine();
                            cout << endl << endl << "enter next screen: ";
                            cin >> pauseButton;
                            system("clear");
                            break;}
                        default:{ 
                            system("clear");
                            printHorizontalLine();
                            printHorizontalLine(1);

                            printHorizontalLine(1);
                            printHorizontalLine();
                            cout << endl << endl << "enter next screen: ";
                            cin >> pauseButton;
                            logout = true;    
                            system("clear");
                            break;
                        }
                    }
                }while(!logout);
            // Management profiles    
            }else if(employees.at(vIndex).getDepartmentByClassId() == 1){
                cout << "What would you like to do ";
                cout << employees.at(vIndex).getFullName() << endl;
                cout << endl << "1. Would you like to view own personal file?" << endl;
                cout << "2. Would you like to search for a specific employee file?" << endl;
                cin >> option;
                switch(option){
                    case 1:{
                        system("clear");
                        printHorizontalLine();
                        printHorizontalLine(1);
                        employees.at(vIndex).view();
                        printHorizontalLine(1);
                        printHorizontalLine();
                        cout << endl << endl << "enter next screen: ";
                        cin >> pauseButton;
                        break;}
                    case 2:{
                        system("clear");
                        // search employee file
                        printHorizontalLine();
                        printHorizontalLine(1);

                        printHorizontalLine(1);
                        printHorizontalLine();
                        cout << endl << endl << "enter next screen: ";
                        cin >> pauseButton;
                        break;}
                    default:{ 
                        system("clear");
                        printHorizontalLine();
                        printHorizontalLine(1);

                        printHorizontalLine(1);
                        printHorizontalLine();
                        cout << endl << endl << "enter next screen: ";
                        cin >> pauseButton;
                        logout = true;
                        break;
                    }
                }
            // General Employee Profile
            }else{
                system("clear");
                printHorizontalLine();
                printHorizontalLine(1);
                cout << "General Employee Portal File" << endl;
                employees.at(vIndex).view();
                printHorizontalLine(1);
                printHorizontalLine();
                cout << endl << endl << "enter next screen: ";
                cin >> pauseButton;
                logout = true;
            }
        // terminating the application run
        }
        char stop;
        cout << "Before terminating program";
        cin >> stop;
        isLoggedIn = false;
        runapp = false;
        goodByeMessage("App Closing!");
    }

    return 0;
}