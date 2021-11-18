// Specification file for the Employee class
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

// Exception class
class InvalidEmployeeNumber {};

class Employee
{
private:
	string name;		// Employee name
	string number;		// Employee number
	string hireDate;	// Hire date

public:
	// Default constructor
	Employee()
		{ name = ""; number = ""; hireDate = ""; }

	// Constructor
	Employee(string aName, string aNumber, string aDate)
		{ // Test aNumber...
		  int num = atoi(aNumber.data());
		  if (num >= 0 && num <= 9999)
		  {
			  // aNumber is valid.
			  name = aName;
			  number = aNumber;
			  hireDate = aDate;
		  }
		  else
			  throw InvalidEmployeeNumber();
	    }

	// Mutators
	void setName(string n)
		{ name = n; }

	void setNumber(string aNumber)
		{ int num = atoi(aNumber.data());
		  if (num >= 0 && num <= 9999)
			number = num;
		  else
			throw InvalidEmployeeNumber();
	    }

	void setHireDate(string date)
		{ hireDate = date; }

	// Accessors
	string getName() const
		{ return name; }

	string getNumber() const
		{ return number; }

	string getHireDate() const
		{ return hireDate; }
};

#endif /* EMPLOYEE_H_ */
