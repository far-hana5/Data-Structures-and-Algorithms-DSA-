
/*
Create three static objects with the help of the constructor of the following class.
Student
{
	name;
	roll;
	section;
	math_marks;
	cls;
}
Then compare those 3 objects and print who got the highest math_marks and print his/her name.


*/

#include <bits/stdc++.h>
using namespace std;

class Student {
public:
    string name;
    int roll;
    char section;
    int math_marks;
    int cls;

    // Constructor
    Student(string n, int r, char s, int m, int c) {
        name = n;
        roll = r;
        section = s;
        math_marks = m;
        cls = c;
    }
};

int main() {
    // Create 3 static objects
    Student s1("Alice", 1, 'A', 88, 10);
    Student s2("Bob", 2, 'B', 92, 10);
    Student s3("Charlie", 3, 'C', 85, 10);

    // Assume s1 has highest marks initially
    Student highest = s1;

    // Compare with s2
    if (s2.math_marks > highest.math_marks) {
        highest = s2;
    }

    // Compare with s3
    if (s3.math_marks > highest.math_marks) {
        highest = s3;
    }

    // Print the name of the student with the highest math marks
    cout <<"Highest math marks: " << highest.math_marks << endl;
    cout <<"Name: " << highest.name << endl;

    return 0;
}
