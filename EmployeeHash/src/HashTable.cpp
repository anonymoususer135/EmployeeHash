//
//  HashTable.cpp
//  hashApp
//
//  Created by user on 11/14/21.
//

#include "HashTable.h"
#include "Employee.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

bool HashTable::insertEmp(Employee e){
    if (this->isFull())
    {
        //cout << "Employee table is full, unable to insert" << endl;
        return false;


    }
    else
    {
        int empIndex=hashFunc(e);
        if (this->emp[empIndex].getName()!="")
        {
            //cout << "Collision happens, unable to insert" << endl;
            return false;
            //this->collisionCount++;
        }
        else
        {
           this->emp[hashFunc(e)]=e;
           this->empCount++;
           return true;
        }
    }
}

bool HashTable::isFull() const{
    if (this->empCount>=emp_size)
    {
        return true;
    }
    else
        return false;
}

bool HashTable::isEmpty() const{
    if (this->empCount==0)
    {
        return true;
    }
    else
        return false;
}

bool HashTable::searchEmp(string name, Employee &reference)
{
    for (int i=0; i<emp_size; i++)
    {
        if (this->emp[i].getName()==name)
        {
			reference = Employee(emp[i].getName(), emp[i].getNumber(), emp[i].getHireDate());
            return true;
        }
    }
    return false;

}

int HashTable::hashFunc(Employee e) {
    const std::hash<std::string> builtInHash;
    const auto result = builtInHash(e.getName())%emp_size;
    return (int)result;
}

int HashTable::getEmCount(){
    return empCount;

}

void HashTable::display10Emp() {
    cout << "Employee Names" << endl;
    short empCount=0;
    short i=0;
    while (true)
    {
        if (empCount>=10 || i>=1000)
            break;
        if (emp[i].getName()!="")
        {
          cout << emp[i].getName() << endl;
          empCount++;
        }
        i++;

    }


}


