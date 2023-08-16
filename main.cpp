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
#include <limits>

using namespace std;

const char screenWidth = 'U'; // Setting width of screen, char U = decimal (85)
const unsigned short MAXSIZE = 12;

class Employee{
    private:
        string firstName;
        string lastName;
        string userId;
        string password;
        string department;

    public:
        Employee(string tFirstName, string tLastName, string tUserId, string tPass, int depId){
            firstName = tFirstName;
            lastName = tLastName;
            userId = tUserId;
            password = tPass;
            department = setDepartmentByClassId(depId);
        }

        void view(){
            cout << "+\tEmployee " << endl;
            cout << "+\tName: " + firstName + " " + lastName << endl;
            cout << "+\tUser Id: " + userId << endl;
            cout << "+\tDepartment: " + department << endl;
        }
        
        // Setters Methods for initializing private member variables.
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

        // Getter Methods for accessing private member variables.
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

// Printing Horizontal Line for Menu Display
void printHorizontalLine(bool truth){
    cout << "+";
    if(truth){
        // print Horizontal line with spaces
        for(int i =0; i<int(screenWidth); i++){
            cout << " ";
        }
    }else{
        // print Horizontal Line without spaces
        for(int i=0; i<int(screenWidth); i++){
            cout << "*";
        }
    }
    cout << "+" << endl;
}

// Retrieve index of a specific Vector Element
int getIndexOfVector(vector<Employee> employees, string tempId){
    int temporaryIndex;
    for(vector<int>::size_type i =0; i<employees.size(); i++){
        if(employees.at(i).getUserId() == tempId) temporaryIndex = i;
    }
    return temporaryIndex;
}

// Checking String for character size
bool checkSingleStringCheck(string userInput){
    //testing for single character string
    if(1 == userInput.length() && (userInput[0] > 64 && userInput[0] < 123)) return true;
    return false;
}
// Checking each individual character in a string to determine if it has invalid characters. 
// Someone name does not need to have numbers.
bool isStringCheck(string userInput){
    for(unsigned int i = 0; i< userInput.length();i++){
        if(!((userInput[i] > 64 || userInput[i] < 91) || (userInput[i] > 96 || userInput[i] < 123))){
            return true;
        }
    }
    return false;
}

// Return TRUE or FALSE if user profile is contained within vector and if variables match vector elements
bool verifyProfile(vector<Employee> employees, string userId, string userPassword){
    for(vector<int>::size_type i =0; i<employees.size(); i++){
        if(userId == employees[i].getUserId() && userPassword == employees[i].getPassword()) return 1;
    }
    return 0;
}

// Determine if user Identification that has being entered during Add function of HR, is already in use, unique identifiers.
bool idExists(vector<Employee> &employees, string tempId){
    for(vector<int>::size_type i = 0; i<employees.size();i++){
        if(tempId == employees.at(i).getUserId()) return 1;
    }
    return 0;
}

int getValidIntegerInput(){
    int input = 0;
    bool failedInput = true;
 
    do{
        cout << "\tEnter a Numeric Choice: ";
        cin >> input;
 
        if(!cin.fail()){
            failedInput = false;
        }else{
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "\tIncorrect input, numeric value between 0-9 only." << endl;
        }
    }while(failedInput); // If cin.fail, meaning its not an integer, it will as again. If integer then it will stop loop.
    
    return input;
}

// Exit Application message
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
    // Initializing the Vector Storage along with 1x usable employee file.
    vector<Employee> employees;
    Employee *newEmployee = new Employee("Jonathan","Vazquez","zbdt4n","studycom",0);
    employees.push_back(*newEmployee);
    delete newEmployee;

    bool runapp = true;
    string pauseButton; // pausing screen in place to allow user to read message.
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
        
        // Checking if user entry is of string and if its 1 character as instructed.
        do{
            cin >> inputValidated;
            if(inputValidated.length() > 1) cout << "Incorrect text, only 1 char allowed" << endl;

        }while(!checkSingleStringCheck(inputValidated));

        // Exit Application if choice matches.
        if(inputValidated == "x")
            goodByeMessage("Exiting Application!");

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
            cout << "+\t3. Default HR Sample Users [User Id, Password] -> [zbdt4n, studycom]" << "+" << endl<<endl;
            
            printHorizontalLine(1);
            
            cout << "+\tNote: If this is your 2nd run, you can try another employee identification." << "+" << endl;            
            
            printHorizontalLine(1);
            printHorizontalLine(0);

            do{
                cout << "User Identification Login: ";
                cin >> userId;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }while(isStringCheck(userId));

            do{
                cout << "User Password Login: ";
                cin >> userPassword;
                if(userPassword.length() >= MAXSIZE) cout << "Incorrect Size!" << endl;
            }while(userPassword.length() >= MAXSIZE);
            
            // If user enters profile information more than 5 times, boot them out. Prevent bruteforce entries.
            tries++;
            if(tries>5) goodByeMessage("You've exceeded the maximum amount of tries for credential verification!");

        }while(!verifyProfile(employees,userId,userPassword));

        bool logout = false;
        bool loggedIn = true;
        int vIndex = getIndexOfVector(employees, userId);;
        
        while(loggedIn){
            
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

                    cout << "+\tWhat would you like to do?\t\t" << endl;
                    cout << "+\t1. Would you like to view own personal file?\t\t" << endl;
                    cout << "+\t2. Would you like to add new employee to database?" << endl;
                    cout << "+\t3. Would you like to search for a specific employee file?" << endl;
                    cout << "+\t4. Would you like to modify a specific employee file?" << endl;
                    cout << "+\t5. Would you like to delete a specific employee file?" << endl;
                    cout << "+\t6. logout from user" << endl;
                    cout << "+\t7. Quit Application" << endl;
                    
                    printHorizontalLine(1);
                    printHorizontalLine(0);
                    
                    do{
                        option = getValidIntegerInput();
                    }while(option < 1 || option > 7); // 1 <= option <= 7
                    
                    system("clear");
                    
                    switch(option){
                        case 1:{
                            printHorizontalLine(0);
                            printHorizontalLine(1);
                            
                            cout << "+\tView Personal Employee File!" << endl;
                            employees.at(vIndex).view(); 
                            
                            printHorizontalLine(1);
                            printHorizontalLine(0);
                            
                            do{
                                cout << "\tEnter next screen: ";
                                cin >> inputValidated;
                                if(inputValidated.length() > 1) cout << "Incorrect text, only 1 char allowed" << endl;
                            }while(!checkSingleStringCheck(inputValidated));

                            
                            break;
                        }
                        case 2:{
                            string firstName, lastName, userId, password;
                            int departmentId;
                            
                            printHorizontalLine(0);
                            printHorizontalLine(1);
                            
                            cout << "+\tAdding new employee member to database!" << endl;
                            cout << "+\tEntering personal information for new employee ..." << endl;
                            
                            do{
                                cout << "+\tEnter first name of new employee: ";
                                cin >> firstName;
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            }while(isStringCheck(firstName));
                            
                            do{
                                cout << "+\tEnter last name of new employee: ";
                                cin >> lastName;
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            }while(isStringCheck(lastName));

                            // check that userId is not the same as already stored, UNIQUE.
                            do{
                                cout << "+\tEnter new employee user identification name: ";
                                cin >> userId;
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            }while(!idExists(employees, userId));  

                            password = "studycom";
                            cout << "+\tNew employee default password set to: " + password << endl;
                            cout << "+\tDepartment Identification integer: 0 {HR}, 1 {Management}, 2 {General Employee}" << endl;
                            do{
                                departmentId = getValidIntegerInput();
                            }while(departmentId > 2 || departmentId < 0); // 0 <= departmentId <= 2

                            printHorizontalLine(1);
                            printHorizontalLine(0);
                            printHorizontalLine(1);
                
                            Employee *newEmp = new Employee(firstName,lastName,userId,password,departmentId);
                            employees.push_back(*newEmp);
                            delete newEmp;

                            cout << "+\tuser has being added!" << endl;
                            printHorizontalLine(1);
                            printHorizontalLine(0);

                            
                            do{
                                cout << "\tEnter any single character to move to next screen: ";
                                cin >> inputValidated;
                                if(inputValidated.length() > 1) cout << "Incorrect text, only 1 char allowed" << endl;
                            }while(!checkSingleStringCheck(inputValidated));
                            
                            break;
                        }
                        case 3:{
                            unsigned int employeeIndex;
                            
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
                                employeeIndex = getValidIntegerInput();
                            }while(employeeIndex < 0 || employeeIndex >= employees.size()); // 0 < employeeIndex <= employees.size()
                            
                            system("clear");
                            
                            printHorizontalLine(0);
                            printHorizontalLine(1);
                            
                            employees.at(employeeIndex).view();
                            
                            printHorizontalLine(1);
                            printHorizontalLine(0);
                            
                            
                            do{
                                cout << "\tEnter any single character for next screen: ";
                                cin >> inputValidated;
                                if(inputValidated.length() > 1) cout << "Incorrect text, only 1 char allowed" << endl;
                            }while(!checkSingleStringCheck(inputValidated));
                            
                            break;
                        }
                        case 4:{
                            unsigned int employeeIndex;
                            int modifyOption;
                            string userInput;
                            
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

                            cout << "+\tWould you like to modify an account?" << endl;// Continue or exit? 
                            cout << "+\t y - yes || n - no:\t";
                            
                            // If user did not entered a single character, loop will continue to ask.
                            do{
                                cin >> userInput;
                                if(userInput.length() > 1) cout << "Incorrect text, only 1 char allowed" << endl;
                            }while(!checkSingleStringCheck(userInput));

                            if(userInput != "y"){
                                system("clear");
                                break;
                            }

                            printHorizontalLine(1);
                            printHorizontalLine(0);
                            printHorizontalLine(1);

                            do{
                                employeeIndex = getValidIntegerInput();
                            }while(employeeIndex < 0 || employeeIndex >= employees.size()); // 0 < employeeIndex <= employees.size()
                             
                            printHorizontalLine(1);
                            printHorizontalLine(0);
                            printHorizontalLine(1);
                            
                            employees.at(employeeIndex).view();
                            
                            printHorizontalLine(1);
                            
                            string firstName, lastName, userId, password;
                            int departmentId;
                            cout << "+\t1. Modify First Name" << endl;
                            cout << "+\t2. Modify Last Name" << endl;
                            cout << "+\t3. Modify User Identification" << endl;
                            cout << "+\t4. Modify Password" << endl;
                            cout << "+\t5. Modify Department" << endl;
                            
                            printHorizontalLine(1);
                            printHorizontalLine(0);
                            printHorizontalLine(1);
                            
                            do{
                                modifyOption = getValidIntegerInput();
                            }while(modifyOption > 5 || modifyOption < 1); // 1 <= modifyOption <= 5
                            
                            printHorizontalLine(1);
                            printHorizontalLine(0);
                            printHorizontalLine(1);
                            
                            if(modifyOption == 1){
                                do{
                                    cout << "+\tEnter new employee first name: ";
                                
                                    cin >> firstName;
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                }while(isStringCheck(firstName));
                                
                                employees.at(employeeIndex).setFirstName(firstName);

                            }else if(modifyOption == 2){
                                do{
                                    cout << "+\tEnter new employee last name: ";
                                
                                    cin >> lastName;
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                }while(isStringCheck(lastName));
                                
                                employees.at(employeeIndex).setLastName(lastName);

                            }else if(modifyOption == 3){

                                do{
                                    cout << "+\tEnter new employee custom user identification: ";
                               
                                    cin >> userId;
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                }while(!idExists(employees,userId));
                                
                                employees.at(employeeIndex).setUserId(userId);

                            }else if(modifyOption == 4){
                                do{
                                    cout << "+\tEnter new employee password: ";
                                
                                    cin >> password;
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                }while(isStringCheck(password));

                                employees.at(employeeIndex).setPassword(password);
                                
                            }else if(modifyOption == 5){
                                if(employeeIndex == 0){
                                    system("clear");
                                
                                    printHorizontalLine(0);
                                    printHorizontalLine(1);
                                
                                    cout << "+\tYou may not modify this account!" << endl;     
                                
                                    printHorizontalLine(1);
                                    printHorizontalLine(0);
                                }else{  
                                    cout << "+\tEnter new employee department: \n\t[0]->Human resources\n\t[1]->Management\n\t[2]->General Employee";
                                    do{
                                        departmentId = getValidIntegerInput();
                                    }while(employeeIndex < 0 || departmentId > 2); // 0 < departmentId < 2 
                                    employees.at(employeeIndex).setDepartmentByClassId(departmentId); 
                                }
                            }else{
                                cout << "+\tNo modification made" << endl;    
                            }
                            
                            printHorizontalLine(1);
                            printHorizontalLine(0);

                            
                            do{
                                cout << "\tEnter any single character to next screen: ";
                                cin >> inputValidated;
                                if(inputValidated.length() > 1) cout << "Incorrect text, only 1 char allowed" << endl;
                            }while(!checkSingleStringCheck(inputValidated));

                            system("clear");
                            
                            break;
                        }
                        case 5:{
                            unsigned int employeeIndex;
                            
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
                                employeeIndex = getValidIntegerInput();
                            }while(employeeIndex >= employees.size() || employeeIndex < 0); // 0 < employeeIndex <= employees.size()

                            if(employees.size() == 1 || employeeIndex == 0 || employees.at(employeeIndex).getUserId() == userId){
                                system("clear");
                            
                                printHorizontalLine(0);
                                printHorizontalLine(1);
                            
                                cout << "+\tYou may not delete this account!" << endl;     
                            
                                printHorizontalLine(1);
                                printHorizontalLine(0);
                            }else{
                            
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
                            }
                            
                            do{
                                cout << "\tEnter a single character for next screen: ";
                                cin >> inputValidated;
                                if(inputValidated.length() > 1) cout << "Incorrect text, only 1 char allowed" << endl;
                            }while(!checkSingleStringCheck(inputValidated));

                            system("clear");

                            break;
                        }
                        case 6:{
                            logout = true;
                            break;
                        }
                        default:{
                            goodByeMessage("Exiting Application ... ");
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
                    cout << "+\t3. logout from user" << endl;
                    cout << "+\t4. Quit Application" << endl;
                    
                    printHorizontalLine(1);
                    printHorizontalLine(0);
                    
                    do{
                        option = getValidIntegerInput();
                    }while(option > 4 || option < 1); //  1 <= option <= 4
                    
                    switch(option){
                        case 1:{
                            system("clear");
                    
                            printHorizontalLine(0);
                            printHorizontalLine(1);
                    
                            cout << "+\tView Personal Employee File!" << endl;
                            employees.at(vIndex).view(); 
                    
                            printHorizontalLine(1);
                            printHorizontalLine(0);
                            
                            do{
                                cout << "\tEnter single character for next screen: ";
                                cin >> inputValidated;
                                if(inputValidated.length() > 1) cout << "Incorrect text, only 1 char allowed" << endl;
                            }while(!checkSingleStringCheck(inputValidated));              
                    
                            break;
                        }
                        case 2:{
                            unsigned int employeeIndex;
                            
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
                                employeeIndex = getValidIntegerInput();
                            }while(employeeIndex < 0 || employeeIndex >= employees.size()); // 0 < employeeIndex <= employees.size()
                            
                            system("clear");
                            
                            printHorizontalLine(0);
                            printHorizontalLine(1);
                            
                            employees.at(employeeIndex).view();
                            
                            printHorizontalLine(1);
                            printHorizontalLine(0);
                            
                            
                            do{
                                cout << "\tEnter any single character for next screen: ";
                                cin >> inputValidated;
                                if(inputValidated.length() > 1) cout << "Incorrect text, only 1 char allowed" << endl;
                            }while(!checkSingleStringCheck(inputValidated));
                            
                            break;
                        }
                        case 3:{
                            logout = true;
                            break;
                        }
                        default:{
                            goodByeMessage("Exiting Application");
                        }
                    }
                }
            // General Employee Profile
            }else{
                system("clear");
                
                int userInput;
                
                printHorizontalLine(0);
                printHorizontalLine(1);
                
                cout << "+\tView Personal Employee File!" << endl;
                employees.at(vIndex).view(); 
                
                printHorizontalLine(1);
                printHorizontalLine(0);
                printHorizontalLine(1);
                
                cout << "+\t1. Logout" << endl;
                cout << "+\t2. Exit Application" << endl;
                
                printHorizontalLine(1);
                printHorizontalLine(0);
                
                do{
                    userInput = getValidIntegerInput();
                }while(userInput > 2 || userInput < 1); //  1 <= userInput <= 4

                if(userInput == 1){
                    logout = true;
                }else{
                    // Any integer should terminate the application.
                    goodByeMessage("Exiting Application ...");
                }
            }
            loggedIn = false;
        }
    }
    return 0;
}