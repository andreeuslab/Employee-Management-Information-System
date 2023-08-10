/*
 *  Employee Management Information System
 *  Written by Jonathan Vazquez
 *  August 10, 2023
 *
 *  Goal: Keep track of Employees at a company, BetterSoftware llc.
 *
 * */

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

const char screenWidth = 'x'; // 1 byte, int typecast ASCII into decimal 120.

class Employee{
  public:
    Employee(){
      firstName = "";
      lastName = "";
      userId = "";
      password = "";
      department = "";
    }
    Employee(string tempFirstName, string tempLastName, string tempUserId, string tempPassword){
      firstName = tempFirstName;
      lastName = tempLastName;
      userId = tempUserId;
      password = tempPassword;
      department = "General Employee";
    }
    void viewEmployeeFile(){
      cout << "Name: " << firstName << " " << lastName << endl;
      cout << "User Id: " << userId << endl;
      cout << "Department: " << department << endl;
    }

  protected: // Child are able to access, same as private
    string firstName;
    string lastName;
    string userId;
    string password;
    string department;
};

class HumanResourceEmployee: public Employee{
  public:
    HumanResourceEmployee(): Employee(){
      firstName = "Jonathan";
      lastName = "Vazquez";
      userId = "zbdt4n";
      password = "studycom";
      department = "Human Resources Employee";
    }
    HumanResourceEmployee(string tempFirstName, string tempLastName, string tempUserId, string tempPassword){
      firstName = tempFirstName;
      lastName = tempLastName;
      userId = tempUserId;
      password = tempPassword;
      department = "Human Resource Employee";
    }
    void addEmployeeFile();
    void viewEmployeeFile(){
      cout << "Name: " << firstName << " " << lastName << endl;
      cout << "User Id: " << userId << endl;
      cout << "Department: " << department << endl;
    }
    void searchEmployeeFile();
    void modifyEmployeeFile();
    void deleteEmployeeFile();
  
    string getUserId(){
      return userId;
    }
    string getPassword(){
      return password;
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
  const char text_width = '2';
  cout << "+" << setw(int(screenWidth+1)) << "+" << endl;
}

void goodByeMessage(){
  system("clear");
  cout << endl;
  cout << "Thank you for trying out my program." << endl;
  cout << "Wherever in the wild you may be, have a wonderful day!" << endl << endl;
  exit(1);
}

int main(){
  vector<Employee> listGeneralEmployees;
  vector<HumanResourceEmployee> listHREmployees;

  system("clear");
  printHorizontalLine();
  printHorizontalLine(1);
  cout << "+" << setw(50) << "Better Software LLC"      << setw(71) << "+" << endl;
  cout << "+" << setw(55) << "Author: Jonathan Vazquez" << setw(66) << "+" << endl;
  printHorizontalLine(1);
  printHorizontalLine(1);
  cout << "+" << setw(55) << "FULL SCREEN RECOMMENDED" << setw(66) << "+" << endl;
  printHorizontalLine(1);
  printHorizontalLine();
  char userInput;
  cout << "Next screen, enter Y: ";
  cin >> userInput;

  if(userInput != 'Y')
    goodByeMessage();

  int tries = 3;
  system("clear");
  printHorizontalLine();
  printHorizontalLine(1);
  string titleMsg = "Employee Management Information System";
  int stringSize = titleMsg.length();

  cout << (stringSize/2)% 2 << endl;
  cout << "+" << "Purpose: Track all employees within the Better Software LLC Business" << "+" << endl;
  printHorizontalLine(1);
  printHorizontalLine(1);
  cout << "+" << setw(27) << "Login, enter L"      << setw(26) << "+" << endl;
  printHorizontalLine(1);
  printHorizontalLine(1);
  cout << "+" << "Program Rules" << endl;
  cout << "+" << "1. Submit 1 single file, hence no read/write to file, dynamic creation." << endl;
  cout << "+" << "2. Program will ONLY have other employees as long as program runs, manual creation." << endl; 
  cout << "+" << "3. Only 1 Default Human Resource Employee file will be generated. " << "+" << endl;
  cout << "+" << "- User Login details will be in the main function inside the source code." << endl;
  printHorizontalLine(1);
  printHorizontalLine();
  // At this point i should check what the user input is. 
  // If L, i must check the vector for any individuals, if none then its the first time program starts. 
  // Create a user instead. Once user is logged in, then the fun begins. 
  while(tries != 0){
    cout << "Enter choice: ";
    cin >> userInput;
    if(userInput == 'L'){
      system("clear");
      string userId, userPassword;
      cout << "User Id: ";
      cin >> userId;
      cout << "Password: ";
      cin >> userPassword;
      
      HumanResourceEmployee *defaultEmployee = new HumanResourceEmployee();
      if(userId == defaultEmployee->getUserId() && userPassword == defaultEmployee->getPassword()){
        listHREmployees.push_back(*defaultEmployee);
        delete(defaultEmployee);
        cout << "success! User logged in" << endl;
        cout << "Is the vector empty? " << listHREmployees.empty() << endl;
        cout << "Size of vector: " << listHREmployees.size() << endl;
        defaultEmployee = new HumanResourceEmployee("Andree","Vazquez","new user","01234");
        listHREmployees.push_back(*defaultEmployee);
        HumanResourceEmployee *employee = new HumanResourceEmployee();
        *employee = listHREmployees.at(1);
        cout << "Getting the view function: " << employee->getUserId() << endl;
        cout << "Is the vector empty? " << listHREmployees.empty() << endl;
        cout << "Size of vector: " << listHREmployees.size() << endl;
        delete(employee);
        delete(defaultEmployee);
      }else{
        cout << "Incorrect login!" << endl;

      }
    }else{
      cout << "Wrong Input, try again!" << endl;
      tries--;
    }
  }
  goodByeMessage();
  //cout << "- Default HR Employee user id: zbdt4n" << endl;
  //cout << "- Default HR Employee password: studycom" << endl;
  
  return 0;
}
