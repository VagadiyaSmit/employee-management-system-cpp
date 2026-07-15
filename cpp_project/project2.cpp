//Emplooye management system
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <string>


using namespace std;

struct Employee{
    int id;
    string name;
    double salary;
};

void displayEmployee(const Employee& emp){     //referance
    cout << "ID:" << emp.id << endl;
    cout << "Name:" << emp.name << endl;
    cout << "salary: $ " << emp.salary << endl;
}

int main(){

    vector <Employee> employees = {
        {101, "hitesh",100000},
        {102, "smit",30000},
        {103, "ram",40000},
        {104, "laxman",50000},
        {105, "raj",70000},
        {106, "veer",60000},
    };
    cout << "\n Total Employees: " << employees.size() << endl;
    
    sort(employees.begin(),employees.end(),[](const Employee& e1,const Employee& e2){
        return e1.salary > e2.salary;
    });                           // ,lemdas

    cout << "Employee sorted by salary -> Highest to lowest \n";
    for_each(employees.begin(),employees.end(), displayEmployee);

    vector <Employee> highEarners;
    copy_if(employees.begin(),employees.end(),back_inserter(highEarners),[](const Employee& e){
        return e.salary > 50000;
    });

    cout << "\n\nEmployee who are high earners \n";
    for_each(highEarners.begin(),highEarners.end(), displayEmployee);


    double totalSalary = accumulate(employees.begin(),employees.end(),0.0,[](double sum,const Employee& e){
        return sum + e.salary;
    });
    cout << "\n\nTotal salary of all employees: $ " << totalSalary << endl;

    double averageSalary = totalSalary / employees.size();
    cout << "Average salary of all employees: $ " << averageSalary << endl;

    auto highestPaid = max_element(employees.begin(),employees.end(),[](const Employee& e1,const Employee& e2){
        return e1.salary < e2.salary;
    });
    if(highestPaid != employees.end()){
        cout << "\n\nHighest paid employee: \n";
        displayEmployee(*highestPaid);
    }

    return 0;
}
