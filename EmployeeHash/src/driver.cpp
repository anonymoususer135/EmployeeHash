//
//  main.cpp
//  hashApp
//
//  Created by user on 11/13/21.
//

#include "HashTable.h"
#include "Employee.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

int main(int argc, const char * argv[]) {
    // insert code here...
 //   std::cout << "Hello, World!\n";
    HashTable h;
    /*
     This will require a for loop. Create an array of letters. Randomly select a random number of characters. Perhaps 1-12 letters. Combine these letters into a name string.
     � The employee numbers could be the loop counter, converted to string.
     � Consider something unique for the hire date string.
     � Combine these values into a new Employee object. Each employee should have
     unique values.
     */
    const char letter[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    short letterIndex;
    string empName;
    string empNumber;
    int collisionCount = 0;
    int employeeCount = 0;
    string inputName;
    //Create 1000 employee
    int temp=1920;
    int choice;
    //int key=0;


    for (int i = 0; i <emp_size; i++)
        {
        //within each Employee object,generate a random name of 12 chars
        for (int j=0;j<12;j++)
        {
            letterIndex=rand()%26;
            empName+=letter[letterIndex];
        }
        //generate a hire date
            string hireDate="01/01/"+to_string(temp);
            temp++;
            Employee e=Employee(empName, to_string(i), hireDate);
            bool insertResult=h.insertEmp(e); //when that happens it should return true or false

    if (insertResult == false) {
        collisionCount++;
    }
            empName="";
            employeeCount++;
        }
    cout<<"Number of Employee successfully added to emp array: "<< h.getEmCount() <<endl;

    cout<<"Number of Employee failed to added to emp array due to collision: "<< collisionCount++ <<endl;
    cout << "Select a number " << endl;
    cout << "1. Search for an employee" << endl;
    cout << "2. Display 10 employees for search test" << endl;
    cout << "3. Quit" << endl;
    cin >> choice;
    while (choice == 1 || choice == 2 || choice == 3) {
    switch(choice) {
        case 1:
        {
            cout << "Enter name of employee ";
            cin >> inputName;
            Employee e;
            bool searchResult=h.searchEmp(inputName, e);
            if (searchResult==true)
            {
                cout << "" << endl;
                cout << "Employee name: " << e.getName() << endl;
                cout << "Employee number: " << e.getNumber() << endl;
                cout << "Employee hire date: " << e.getHireDate() << endl;

            }
            else {
                cout << "Not found" << endl;
            }
        }
                break;
        case 2:

            h.display10Emp();

            break;
        case 3: {
                return 0;
        }
        default: {
                cout << "Invalid input" << endl;
        }

        }
        cout << "Select a number " << endl;
        cout << "1. Search for an employee" << endl;
        cout << "2. Display 10 employees for search test" << endl;
        cout << "3. Quit" << endl;
        cin >> choice;
    }
    return 0;
}

