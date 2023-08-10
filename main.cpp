/*
 *  Employee Management Information System
 *  Written by Jonathan Vazquez
 *  August 10, 2023
 *
 *  Goal: Keep track of Employees at a company, BetterSoftware llc.
 *
 * */

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

//General Employee user can only view his or her own file. 
class Employee{
//Employee files will have at least the employee's name and numeric user id.
  private:
    string employeeName;
    int userId;

 public:
    string getEmployeeName();
    int getEmployeeUserId();
    void setEmployeeName(string name);
    void setEmployeeUserId(int id);
};

//A Management user can only search and view employees.
class Management: public Employee{

};
//A Human Resources user will be able to add, view, search, modify, and delete employees
class HumanResources: public Employee{

};

int main(){

  cout << "Hello World!" << endl;

  return 0;
}
