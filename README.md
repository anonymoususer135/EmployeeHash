# EmployeeHash

## Employee.h

In the header file, there is a class called Employee, and it has three private string variables called name, number, and hireDate, which represents the Employee's name, their employee number, and the date when they were hired.
Like all header files, it should provide a constructor method with no arguments, and contain the three previously-defined private variables as empty strings.
It also has a constructor, which has the three private variables as arguments. 

-First, it defines an integer variable called num, which turns the Employee numbers into integers with the atoi method to make a number.
  
-It then has an if function to determine whether the number is within the 0-9999 range, and then if it is, it will assign the three private variables to the three arguments of the function.
  
-If not, then the InvalidEmployeeNumber exception is thrown. There is a class named InvalidEmployeeNumber at the start of the header file to call an exception.
    
-The setters, or the mutators, each contain a string variable as an argument which are set to their appropriate variables. 
  
-The Employee number setter has its argument turned into an integer via atoi() before being set to its variable if its under the 0-9999 range, otherwise an error is thrown.
    
-The Accessors each return their appropriate types.
  
## HashTableClass.h

This header file defines a statically allocated array with the number of employees, and a hash function in the private section. In the public one, there is an isEmpty, isFull, and some features to add employees or search for them. There will be a menu function in this project.

```cpp
#include "Employee.h";
#include <string>;
#ifndef HASHTABLE_H_
#define HASHTABLE_H_

class HashTable {
	private:
		const int MAX = 1000;
		Employee numberOfEmployees[MAX];
		int hashingEmployee(Employee e) {
			string name = e.getName();
			hash<string> converted;
			if (converted(name) >= 0 && converted(name) < sizeof(numberOfEmployees)) {

			}
			return converted(name);
		}
	public:
		void addEmp(Employee::Employee e);
		bool isFull();
		bool isEmpty();
		bool searchEmp(string s, Employee &reference); //&s are for references
};
```
**11/16/2021**

I found out that some of my code was not working, so I decided to change some things, along with making some code fit my project requirements. It looks like this.

```cpp
#ifndef HASHTABLE_H_
#define HASHTABLE_H_
#define emp_size 1000

#include "Employee.h"
#include <string>

class HashTable
{
private:
    Employee emp[emp_size];
    int empCount=0;
    int collisionCount=0;
    int hashFunc(Employee e);
public:
//    void emp(Employee::Employee e);

    void insertEmp(Employee e);
    bool isFull();
    bool isEmpty();
    bool searchEmp(string name, Employee &reference);
    int getEmCount();
    int getCollsionCount();
};
#endif /* HASHTABLE_H_ */
```

First, I defined a public integer variable for a max size of 1000, before the class. 
Inside the class was a private Employee array with the maximum size variable in the square brackets, then an int variable called empCount.

The empCount variable was set to 0 in the private section, but if an employee was added to the list, then it would increase by 1.

There was also a collisionCount variable in case there was a collision. A collision is when a value is added to the index of the array which already had a value.

The hashFunc was the hash function. It would have a hash array called builtInHash, then the result would consist of the modulus between the hashed employee name and the maximum size, which is 1000, since the reslt must be less than 1000.

``cpp
int HashTable::hashFunc(Employee e) {
    const std::hash<std::string> builtInHash;
    const auto result = builtInHash(e.getName())%emp_size;
    return (int)result;
}
```

In the public function there is the insertEmp function, which has an employee variable as an argument. If the array is not full, then the employee index would define itself to hashFunc with the employee argument in its brackets.

If the current index of the function has a value in it, or is not empty, then a collision will happen, and the collisionCount will increase by 1.

```cpp
int empIndex=hashFunc(e);
if (this->emp[empIndex].getName()!="")
   {
    cout << "Collision happens, unable to insert" << endl;
    this->collisionCount++;
   }
```

If it is empty, then the said index will pick up the hash, and the size of the array will increment by 1.

```cpp
else
 {
    this->emp[hashFunc(e)]=e;
    this->empCount++;
  }
```

The full function consists of the empCount going over the maximum size of 1000 and returning true in that condition.

```cpp
bool HashTable::isFull(){
    if (this->empCount>=emp_size)
    {
        return true;
    }
    else
        return false;
}
```

 It will spark an error message in the insertEmp function if the array is full.
 ```cpp
 void HashTable::insertEmp(Employee e){
    if (this->isFull())
    {
        cout << "Employee table is full, unable to insert" << endl;


    }
    else
    //continued...
    }
 ```
 

The isEmpty function consists of the size of the array being zero and the function returning true. 

```cpp
bool HashTable::isEmpty() {
    if (this->empCount==0)
    {
        return true;
    }
    else
        return false;
}
```

The searchEmp function consists of a for loop through 0 and the maximum size, and inside that loop, an if statement that if one of the employee names inside the array is the name in the argument of the function, the reference would pick up the information of said employee, and the function will return true.

```cpp
bool HashTable::searchEmp(string name, Employee &reference)
{
    for (int i=0; i<1000; i++)
    {
        if (this->emp[i].getName()==name)
        {
			reference = Employee(emp[i].getName(), emp[i].getNumber(), emp[i].getHireDate());
            return true;
        }
    }
    return false;

}
```

The getEmCount method simply returns empCount, and the getCollisionCount function will return collisionCount.

```cpp
int HashTable::getEmCount(){
    return empCount;

}

int HashTable::getCollsionCount(){
    return collisionCount;
}
```
## 11/17/2021

I made an update on some of my files, as well as make a driver file. I will have to create a menu for the file, though. Some notable changes I have made to my project was removing the getCollisionCount() method and instances of it from my HashTable.h file and HashTable.cpp files. And that collision thing has been moved to my new driver file, inside an if statement. 
The size of the employee increases when an employee is added to the array, and the number of collisions increase when the function fails.

```cpp
    if (h.insertEmp(e) == true) {
    	cout<<"Number of Employee successfully added to emp array: "<< employeeCount++ <<endl;
    }
    else {
    	cout<<"Number of Employee failed to added to emp array due to collision: "<< collisionCount++ <<endl;
    }
```

Like so, I've made changes to my insertEmp function by making it a boolean function and commenting out the printing stuff. It returns false if the array is already full when the user tries to add a value to it, or it creates a collision, and true if none of those events happen.

```cpp
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
```

My entire main CPP file besides the insert function consists of a for loop which iterates through 0 and the maximum value, 1000. It would then loop from 0 to 12 in that for loop, and then take a random letter from the letter list and then make a 12-letter name for an employee. 

```cpp
    for (int i = 0; i <emp_size; i++)
        {
        //within each Employee object,generate a random name of 12 chars
        for (int j=0;j<12;j++)
        {
            letterIndex=rand()%26;
            empName+=letter[letterIndex];
   }
```
The hireDate would then be formatted, and then the temp variable would increment, assuming that an employee is hired every year. 
An employee object named e is then created with the name, the string which is the number between 0 and 1000, and the hire date, and then that employee is added to hashTable h.

```cpp
string hireDate="01/01/"+to_string(temp);
temp++;
Employee e=Employee(empName, to_string(i), hireDate);
h.insertEmp(e); //when that happens it should return true or false
```

When I ran my code after making the changes, I noticed that all of the occurences had the insert function fail for every 1000 cases. I believe it's because that the emp array is already full when created, considering when I ran it before commenting out the printing stuff in the insert function, the output read that there were collisions. I wonder if I would add something to the emp array in the HashTable header file?

```cpp
Employee emp[emp_size] = {};
```
