🔹 Class & Object in C++
Class: Blueprint for creating objects. It defines properties (variables) and methods (functions).

Object: Instance of a class, represents a real-world entity.

Example:
class Teacher {
   public:
     string name;
     string dept;
     void teach() {
         cout << name << " is teaching." << endl;
     }
};

Teacher t1; // t1 is an object of class Teacher



🔹 Access Modifiers

Modifier	Access Level
private  	 Accessible only within the class
public	     Accessible from anywhere
protected	 Accessible within class & derived class



🔹 Encapsulation
Encapsulation is:

**Binding data and functions together in a class.

**Example of data hiding: private variables + public getter/setter.


class Account {
 private:
   double balance;
 public:
   void setBalance(double b) { balance = b; }
   double getBalance() { return balance; }
};

🔹 Constructor
Constructors are special functions that run when an object is created.

Types:
Default / Non-Parameterized Constructor

 code
Teacher() {
  dept = "CS";
}


Parameterized Constructor

code
Teacher(string name, string dept, string subject, double salary) {
    this->name = name;
    this->dept = dept;
    this->subject = subject;
    this->salary = salary;
}

Copy Constructor

code
Teacher(Teacher &obj) { // Shallow copy
    this->name = obj.name;
    ...
}


🔹 Constructor Overloading
Multiple constructors with same name but different parameters.

code
class Teacher {
  public:
    Teacher() {}
    Teacher(string name) {}
    Teacher(string name, string dept) {}
};
This is an example of compile-time polymorphism.

🔹 this Pointer
Points to the current object.

Useful to distinguish between class properties and parameters.

code
this->name = name; // object property = parameter
🔹 Shallow Copy vs Deep Copy
🧪 Shallow Copy
Default copy constructor just copies addresses.

If pointer members exist, both objects point to same memory → changes reflect in both.

cpp
Copy code
Student s1("Raihan", 3.5);
Student s2(s1); // shallow by default (if not customized)
🧬 Deep Copy
Creates new memory allocation and copies values.

Prevents shared memory between objects.

cpp
Copy code
Student(Student &obj) {
    this->name = obj.name;
    cgpaPtr = new double;
    *cgpaPtr = *obj.cgpaPtr;
}
🧪 Your Code Summary
✅ Encapsulation:
You used private salary, and public getSalary()/setSalary() – this is data hiding.

✅ Constructor:
You demonstrated both parameterized and copy constructors.

✅ Shallow Copy:
cpp
Copy code
Teacher t2(t1); // Copying object – same values
✅ Deep Copy:
cpp
Copy code
Student s2(s1); // Custom deep copy of pointer (cgpaPtr)
✅ this Pointer:
You used this->name, etc., in constructors.

📌 Suggested Additions (Best Practice)
Add destructor to clean up memory for Student:


~Student() {
    delete cgpaPtr;
}

Code:

/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<iostream>
#include<string>
using namespace std;

class Teacher {
private:
      double salary;
 public:
 string name;
 string dept;
 string subject;
//  Teacher( ){
//       dept="CS";
//       cout<<"hello ,i am constructor \n";
      
//   }
   Teacher( string name,string dept,string subject, double salary){
      // dept="CS";
      // cout<<"hello ,i am constructor \n";
      
    //   name=n;
    //   dept=d;
    //   subject=s;
    //   salary=sal;
    //this ->name(object properties)
    this ->name=name;
    this->dept=dept;
    this->subject=subject;
    this->salary=salary;
   }
    //copy constructor
    Teacher( Teacher &obj){//shallow copy
        cout<<"i am custom copy constructor\n";
      this ->name=obj.name;
    this->dept=obj.dept;
    this->subject=obj.subject;
    this->salary=obj.salary; 
    }
    void setSalary(double s){
        salary=s;
    }
    double getSalary(){
        return salary;
    }
    

    void changeDept(string newDept) {
        dept = newDept;
    }
    
    void getInfo(){
        cout<<"Name :"<<name<<endl;
        cout<<"subject :"<<subject<<endl;
    }
};
 class Account{
    private:
      double blance;
      string password;
      
    public:
      string accountId;
      string username;
 };
 
 class Student{
     public:
      string name;
      double* cgpaPtr;
      
      Student (string name, double cgpa){
          this->name=name;
          cgpaPtr=new double;
          *cgpaPtr=cgpa;
      }
      
    Student(Student &obj){
        this->name=obj.name;
        cgpaPtr=new double;
        *cgpaPtr=*obj.cgpaPtr;
    }
     void getInfo(){
        cout<<"Name :"<<name<<endl;
        cout<<"cgpa :"<<*cgpaPtr<<endl;
    }
    
 };
int main() {
    // 
    Teacher t1("Farhana","CS","C++",25000);
   
    t1.setSalary(25000);
    cout << t1.dept << endl;
    cout<<t1.getSalary()<<endl;
    //t1.getInfo();
    
    Teacher t2(t1);//default/custom copy constructor// shallow copy
    t2.getInfo();
    
    //deep copy
    Student s1("rala nahi",8.9);
    Student s2(s1);
    s1.getInfo();
    *(s2.cgpaPtr)=9.1;
    s1.getInfo();
    
    
    s2.name="fahima";
    s2.getInfo();
    
    
    
    
}


