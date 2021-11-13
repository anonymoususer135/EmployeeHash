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
