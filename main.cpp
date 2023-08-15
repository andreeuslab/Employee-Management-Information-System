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
#include <vector>

using namespace std;

const char screenWidth = 'U';

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
            cout << "+\tEmployee " << endl;
            cout << "+\tName: " + firstName + " " + lastName << endl;
            cout << "+\tUser Id: " + userId << endl;
            cout << "+\tDepartment: " + department << endl;
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

void printHorizontalLine(bool truth){
  // 1 byte, when casted to int(2) = 50, decimal based on ASCII
  cout << "+";
  if(truth){
    // print Horizontal line with spaces
    for(int i =0; i<int(screenWidth); i++){
        cout << " ";
    }
  }else{
      for(int i=0; i<int(screenWidth); i++){
        cout << "*";
    }
  }
    cout << "+" << endl;
}

int getIndexOfVector(vector<Employee> employees, string tempId){
    int temporaryIndex;
    for(vector<int>::size_type i =0; i<employees.size(); i++){
        if(employees.at(i).getUserId() == tempId) temporaryIndex = i;
    }
    return temporaryIndex;
}
string inputStringCheck(int max_size){
    string userInput;
    cin >> userInput;
    //testing for single character string
    if(max_size == userInput.length() && (userInput[0] > 64 && userInput[0] < 123)){ 
        return userInput;
    }
    if(userInput.length() <= max_size){
        for(int i =0; i<userInput.length();i++){
            if(userInput[i] > 64 && userInput[i] < 123){
                return userInput;
            }
        }
    }
    return " Incorrect Input, try again!";
}
bool verifyProfile(vector<Employee> employees, string userId, string userPassword){
    for(vector<int>::size_type i =0; i<employees.size(); i++){
        if(userId == employees[i].getUserId() && userPassword == employees[i].getPassword()) return 1;
    }
    return 0;
}
bool checkIntegerInput(int option){
    if(!(cin)){
        cin.clear();
        cin.ignore(1000,'\n');
        return 0;
    }
    return 1;
}
void goodByeMessage(string msg){
  system("clear");
  printHorizontalLine(0);
  printHorizontalLine(1);
  printHorizontalLine(1);
  cout << "+\t" + msg << endl;
  cout << "+\tThank you for trying out my program." << endl;
  cout << "+\tWherever in the wild you may be, have a wonderful day!" << endl;
  printHorizontalLine(1);
  printHorizontalLine(1);
  printHorizontalLine(0);
  exit(1);
}

int main(){
    vector<Employee> employees;
    Employee *newEmployee = new Employee("Jonathan","Vazquez","zbdt4n","studycom",0);
    employees.push_back(*newEmployee);
    delete newEmployee;
    int vIndex;
    
    bool runapp = true;
    string pauseButton;

    string inputValidated;
    do{
        system("clear");
        printHorizontalLine(0);
        printHorizontalLine(1);
        cout << "+\t\tJVs Better Software LLC" << endl;
        cout << "+\t\tAuthor: Jonathan Vazquez" << endl;
        printHorizontalLine(1);
        printHorizontalLine(0);
        printHorizontalLine(1);
        cout << "+\t\tFULL SCREEN RECOMMENDED" << endl;
        printHorizontalLine(1);
        printHorizontalLine(0);
        cout << "\tNext screen, enter n: " << endl;
        cout << "\tExit Application, enter x" << endl;
        cout << "\tEntry: ";
        inputValidated = inputStringCheck(1);
        if(inputValidated == "x"){
            goodByeMessage("Exiting Application!");
        }
    }while(inputValidated != "n");

    while(runapp){
        string userId, userPassword, strValidation;
        int tries = 0;    
        do{
            system("clear");
            printHorizontalLine(0);
            printHorizontalLine(1);
            cout << "+\tPurpose: Track all employees within the Better Software LLC Business" << endl;
            printHorizontalLine(1);
            printHorizontalLine(0);
            printHorizontalLine(1);
            cout << "+\tProgram Rules" << endl;
            cout << "+\t1. Submit 1 single file, hence no read/write to file, dynamic creation." << endl;
            cout << "+\t2. You are responsible for adding/manipulating other employees at runtime!" << endl;
            cout << "+\t3. Default HR Sample Users [User Id, Password] -> [zbdt4n, studycom]" << "+" << endl;
            cout << "+\tNote: If this is your 2nd run, you can try another employee identification." << "+" << endl;            
            printHorizontalLine(1);
            printHorizontalLine(0);
            cout << "User Identification Login: ";
            userId = inputStringCheck(12);
            cout << "User Password Login: ";
            userPassword = inputStringCheck(12);
            tries++;
            if(tries>5) goodByeMessage("You've exceeded the maximum amount of tries for credential verification!");
        }while(!verifyProfile(employees,userId,userPassword));

        bool logout = false;
        bool loggedIn = true;
        while(loggedIn){
            vIndex = getIndexOfVector(employees, userId);
            int option;
            if((employees.at(vIndex).getDepartmentByClassId() == 0)){
                while(!logout){
                    system("clear");
                    printHorizontalLine(0);
                    printHorizontalLine(1);
                    cout << "+\t\tJVs Better Software LLC Employee Portal" << endl;
                    cout << "+\t\tDepartment Identification: " << employees.at(vIndex).getDepartmentClassification() << endl;
                    cout << "+\t\tWelcome " + employees.at(vIndex).getFullName() << endl; 
                    printHorizontalLine(1);
                    printHorizontalLine(0);
                    printHorizontalLine(1);

                    cout << "+\t\tWhat would you like to do?\t\t" << endl;
                    cout << "+\t\t1. Would you like to view own personal file?\t\t" << endl;
                    cout << "+\t\t2. Would you like to add new employee to database?" << endl;
                    cout << "+\t\t3. Would you like to search for a specific employee file?" << endl;
                    cout << "+\t\t4. Would you like to modify a specific employee file?" << endl;
                    cout << "+\t\t5. Would you like to delete a specific employee file?" << endl;
                    cout << "+\t\t6. logout?" << endl;
                    printHorizontalLine(1);
                    printHorizontalLine(0);
                    do{
                        cout << "\tEnter your integer choice: ";
                        cin >> option;
                    }while(!checkIntegerInput(option));
                    
                    system("clear");
                    switch(option){
                        case 1:{
                            printHorizontalLine(0);
                            printHorizontalLine(1);
                            cout << "+\tView Personal Employee File!" << endl;
                            employees.at(vIndex).view(); 
                            printHorizontalLine(1);
                            printHorizontalLine(0);
                            cout << "\tEnter next screen: ";
                            cout << inputStringCheck(1) << endl;               
                            break;
                        }
                        case 2:{
                            string firstName, lastName, userId, password;
                            int departmentId;
                            printHorizontalLine(0);
                            printHorizontalLine(1);
                            cout << "+\tAdding new employee member to database!" << endl;
                            cout << "+\tEntering personal information for new employee ..." << endl;
                            cout << "+\tEnter new employee first name: ";
                            firstName = inputStringCheck(12);
                            cout << "+\tEnter new employee last name: ";
                            lastName = inputStringCheck(12);
                            cout << "+\tEnter new employee custom user identification: ";
                            userId = inputStringCheck(12);
                            password = "studycom";
                            cout << "+\tNew employee default password set to: " + password << endl;
                            cout << "+\tDepartment Identification integer: 0 {HR}, 1 {Management}, any other int {General Employee}" << endl;
                            do{
                                cout << "+\tEnter your integer choice: ";
                                cin >> departmentId;
                            }while(!checkIntegerInput(departmentId));

                            printHorizontalLine(1);
                            printHorizontalLine(0);
                            printHorizontalLine(1);
                            
                
                            Employee *newEmp = new Employee(firstName,lastName,userId,password,departmentId);
                            employees.push_back(*newEmp);
                            delete newEmp;

                            cout << "+\tuser has being added!" << endl;
                            printHorizontalLine(1);
                            printHorizontalLine(0);

                            cout << "\tEnter next screen: ";
                            pauseButton = inputStringCheck(12);
                            break;
                        }
                        case 3:{
                            int employeeIndex;
                            printHorizontalLine(0);
                            printHorizontalLine(1);
                            cout << "+\tSearching Employee file" << endl;
                            cout << "+\tHere are all the current employees by Name: " << endl;
                            for(vector<int>::size_type i =0; i<employees.size(); i++){
                                cout << "+\t" << i << ". ";
                                cout << employees.at(i).getFullName() << endl;
                            }
                            printHorizontalLine(1);
                            printHorizontalLine(0);
                            printHorizontalLine(1);
                    
                            cout << "+\tInterested in viewing any specific employee file?" << endl;
                            printHorizontalLine(1);
                            printHorizontalLine(0);
                
                            do{
                                cout << "Enter your integer choice: ";
                                cin >> employeeIndex;
                            }while(!checkIntegerInput(employeeIndex));

                            if((vector<int>::value_type)employeeIndex > employees.size()){
                                cout << "Incorrect entry!" << endl;
                            }
                            system("clear");
                            printHorizontalLine(0);
                            printHorizontalLine(1);
                            employees.at(employeeIndex).view();
                            printHorizontalLine(1);
                            printHorizontalLine(0);
                            cout << "\tEnter any character for next screen: ";
                            pauseButton = inputStringCheck(12);
                            break;
                        }
                        case 4:{
                            int employeeIndex;
                            int modifyOption;
                            printHorizontalLine(0);
                            printHorizontalLine(1);
                            cout << "+\tModifying Employee File!" << endl;
                            cout << "+\tHere are all the current employees by Name: " << endl;
                            for(vector<int>::size_type i =0; i<employees.size(); i++){
                                cout << "+\t" << i << ". ";
                                cout << employees.at(i).getFullName() << endl;
                            }
                            printHorizontalLine(0);
                            printHorizontalLine(1);
                            printHorizontalLine(1);
                            cout << "+\tInterested in viewing any specific employee file?" << endl;
                            printHorizontalLine(0);
                            printHorizontalLine(1);

                            do{
                                cout << "\tEnter your integer choice: ";
                                cin >> employeeIndex;
                            }while(!checkIntegerInput(employeeIndex));

                            if((vector<int>::value_type)employeeIndex > employees.size()){
                                cout << "Incorrect entry!" << endl;
                            }
                            // Continue or exit? 
                            printHorizontalLine(1);
                            printHorizontalLine(0);
                            printHorizontalLine(1);
                            employees.at(employeeIndex).view();
                            printHorizontalLine(1);
                            string firstName, lastName, userId, password, department;
                            cout << "+\t1. Modify First Name" << endl;
                            cout << "+\t2. Modify Last Name" << endl;
                            cout << "+\t3. Modify User Identification" << endl;
                            cout << "+\t4. Modify Password" << endl;
                            cout << "+\t5. Modify Department" << endl;
                            printHorizontalLine(1);
                            printHorizontalLine(0);
                            printHorizontalLine(1);
                            
                            do{
                                cout << "Enter your integer choice: ";
                                cin >> modifyOption;
                            }while(!checkIntegerInput(modifyOption));
                            
                            printHorizontalLine(1);
                            printHorizontalLine(0);
                            printHorizontalLine(1);
                            
                            if(modifyOption == 1){
                                cout << "+\tEnter new employee first name: ";
                                firstName = inputStringCheck(12);
                                employees.at(employeeIndex).setFirstName(firstName);
                            }else if(modifyOption == 2){
                                cout << "+\tEnter new employee last name: ";
                                lastName = inputStringCheck(12);
                                employees.at(employeeIndex).setLastName(lastName);
                            }else if(modifyOption == 3){
                                cout << "+\tEnter new employee custom user identification: ";
                                userId = inputStringCheck(12);
                                employees.at(employeeIndex).setUserId(userId);
                            }else if(modifyOption == 4){
                                cout << "+\tEnter new employee password: ";
                                password = inputStringCheck(12);
                                employees.at(employeeIndex).setPassword(password);
                            }else if(modifyOption == 5){
                                cout << "+\tEnter new employee department: \n\t[0]->Human resources\n\t[1]->Management\n\t[#]->General Employee";
                                department = inputStringCheck(12);
                                employees.at(employeeIndex).setDepartmentByTitle(department); // careful that user enters correctly
                            }else{
                                cout << "+\tNo modification made" << endl;    
                            }
                            printHorizontalLine(1);
                            printHorizontalLine(0);

                            // Need to loop to determine if user wants to proceed with further modification or quit.

                            cout << "\tEnter next screen: ";
                            pauseButton = inputStringCheck(12);
                            system("clear");
                            break;
                        }
                        case 5:{
                            int employeeIndex;
                            printHorizontalLine(0);
                            printHorizontalLine(1);
                            cout << "+\tDeleting employee from database!" << endl;
                            cout << "+\tHere are all the current employees by Name: " << endl;
                            for(vector<int>::size_type i =0; i<employees.size(); i++){
                                cout << "+\t" << i << ". ";
                                cout << employees.at(i).getFullName() << endl;
                            }
                            printHorizontalLine(1);
                            printHorizontalLine(0);
                            
                            do{
                                cout << "Enter your integer choice: ";        
                                cin >> employeeIndex;
                            }while(!checkIntegerInput(employeeIndex));

                            employees.erase(employees.begin()+employeeIndex);
                            printHorizontalLine(0);
                            printHorizontalLine(1);
                            
                            cout << "+\tUpdated List of Employees: " << endl;
                            for(vector<int>::size_type i =0; i<employees.size(); i++){
                                cout << "+\t" << i << ". ";
                                cout << employees.at(i).getFullName() << endl;
                            }
                            printHorizontalLine(1);
                            printHorizontalLine(0);
                            cout << "\tEnter next screen: ";
                            pauseButton = inputStringCheck(12);
                            system("clear");
                            break;
                        }
                        default:{
                            logout = true;
                            break;
                        }
                    }
                }
            // Management profiles    
            }else if(employees.at(vIndex).getDepartmentByClassId() == 1){
                while(!logout){
                    system("clear");
                    printHorizontalLine(0);
                    printHorizontalLine(1);
                    cout << "+\tWhat would you like to do ";
                    cout << employees.at(vIndex).getFullName() << endl;

                    printHorizontalLine(1);
                    printHorizontalLine(0);
                    printHorizontalLine(1);

                    cout << "+\t1. Would you like to view own personal file?" << endl;
                    cout << "+\t2. Would you like to search for a specific employee file?" << endl;
                    cout << "+\t#. Logout" << endl;
                    printHorizontalLine(1);
                    printHorizontalLine(0);
                    do{
                        cout << "\tEnter your integer choice: ";
                        cin >> option;
                    }while(!checkIntegerInput(option));
                    
                    switch(option){
                        case 1:{
                            system("clear");
                            printHorizontalLine(0);
                            printHorizontalLine(1);
                            cout << "+\tView Personal Employee File!" << endl;
                            employees.at(vIndex).view(); 
                            printHorizontalLine(1);
                            printHorizontalLine(0);
                            cout << "\tEnter next screen: ";
                            cout << inputStringCheck(1) << endl;               
                            break;
                        }
                        case 2:{
                            int employeeIndex;
                            system("clear");
                            printHorizontalLine(0);
                            printHorizontalLine(1);
                            cout << "+\t Searching Employee file" << endl;
                            cout << "+\tHere are all the current employees by Name: " << endl;
                            for(vector<int>::size_type i =0; i<employees.size(); i++){
                                cout << "+\t" << i << ". ";
                                cout << employees.at(i).getFullName() << endl;
                            }
                            printHorizontalLine(1);
                            printHorizontalLine(0);
                            printHorizontalLine(1);
                    
                            cout << "+\tInterested in viewing any specific employee file?" << endl;
                            printHorizontalLine(1);
                            printHorizontalLine(0);
                
                            do{
                                cout << "Enter your integer choice: ";
                                cin >> employeeIndex;
                            }while(!checkIntegerInput(employeeIndex));

                            if((vector<int>::value_type)employeeIndex > employees.size()){
                                cout << "Incorrect entry!" << endl;
                            }
                            system("clear");
                            printHorizontalLine(0);
                            printHorizontalLine(1);
                            employees.at(employeeIndex).view();
                            printHorizontalLine(1);
                            printHorizontalLine(0);
                            cout << "\tEnter any character for next screen: ";
                            pauseButton = inputStringCheck(12);
                            break;
                        }
                        default:{
                            logout = true;
                            break;
                        }
                    }
                }
            // General Employee Profile
            }else{
                system("clear");
                printHorizontalLine(0);
                printHorizontalLine(1);
                cout << "+\tView Personal Employee File!" << endl;
                employees.at(vIndex).view(); 
                printHorizontalLine(1);
                printHorizontalLine(0);
                cout << "\tEnter any character to Logout!";
                cout << inputStringCheck(1) << endl;
           }
            loggedIn = false;
        }
    }
    goodByeMessage("Exiting...");
    return 0;
}