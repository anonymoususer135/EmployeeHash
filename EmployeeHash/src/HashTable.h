/*
 * HashTable.h
 *
 *  Created on: Nov 12, 2021
 *      Author: Default
 */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_
#define emp_size 1000

#include "Employee.h"
#include <string>

class HashTable
{
private:
    Employee emp[emp_size] = {};
    int empCount=0;
    //int collisionCount=0;
    int hashFunc(Employee e);
public:
//    void emp(Employee::Employee e);

    bool insertEmp(Employee e);
    bool isFull() const;
    bool isEmpty() const;
    bool searchEmp(string name, Employee &reference);
    int getEmCount();
    void display10Emp();
    //int getCollsionCount();
};
#endif /* HASHTABLE_H_ */
