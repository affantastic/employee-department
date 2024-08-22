#include <iostream>
#include <string>
using namespace std;
class Employee {
private:
 string name;
 int age;
 string department;
public:
 Employee() : age(0) {}
 Employee( string empName, int empAge, string empDepartment){
 name=empName;
 age=empAge;
 department=empDepartment;
 }
 void displayInfo() {
 cout << "Name: " << name << ", Age: " << age << ", Department: "
<< department << endl;
 }
 string getName() {
 return name;
 }
 int getAge() {
 return age;
 }
};
class Department {
private:
 string departmentName;
 static const int maxEmployees = 10;
 Employee employees[maxEmployees];
 int numEmployees;
public:
 Department( string name) {
 departmentName=name;
 numEmployees=0;
 }
 Department( Department& other)
 : departmentName(other.departmentName),
numEmployees(other.numEmployees) {
 for (int i = 0; i < numEmployees; ++i) {
 employees[i] = other.employees[i];
 }
 }
 void addEmployee( string empName, int empAge) {
 if (numEmployees < maxEmployees) {
 employees[numEmployees] = Employee(empName, empAge,
departmentName);
 numEmployees++;
 } else {
 cout << "Maximum number of employees reached." << endl;
 }
 }
 void listEmployees() {
 cout << "Employees in " << departmentName << ":" << endl;
 for (int i = 0; i < numEmployees; ++i) {
 employees[i].displayInfo();
 }
 }
};
int main() {
 Department CE("Mechanical Engineering");
 CE.addEmployee("Affan", 19);
 CE.addEmployee("Adil", 31);
 Department CS("Computer Science");
 CS.addEmployee("Moeez", 34);
 CS.addEmployee("Mustafa", 28);
 Department CECopy(CE);
 CECopy.addEmployee("Rehman", 28);
 cout << "Original CE Department:" << endl;
 CE.listEmployees();
 cout << endl;
 cout << "\nCopied CE Department:" << endl;
 CECopy.listEmployees();
 return 0;
}
