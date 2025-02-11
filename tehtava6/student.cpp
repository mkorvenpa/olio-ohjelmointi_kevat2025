#include "student.h"

Student::Student(string s, int num)
{
    Name=s;
    Age=num;
}

void Student::setAge(int num)
{
    Age=num;
}

void Student::setName(string s)
{
    Name=s;
}

string Student::getName()
{
    return Name;
}

int Student::getAge()
{
    return Age;
}

void Student::printStudentInfo()
{
    cout<<"Student "<<Name<<" age "<<Age<<endl;
}
