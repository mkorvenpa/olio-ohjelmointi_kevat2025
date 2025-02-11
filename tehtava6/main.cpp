#include <iostream>
#include <vector>
#include <algorithm>
#include "student.h"

using namespace std;

int main ()
{
    int selection =0;
    vector<Student>studentList;

    do
    {
        cout<<endl;
        cout<<"Select"<<endl;
        cout<<"Add students = 0"<<endl;
        cout<<"Print all students = 1"<<endl;
        cout<<"Sort and print students according to Name = 2"<<endl;
        cout<<"Sort and print students according to Age = 3"<<endl;
        cout<<"Find and print student = 4"<<endl;
        cin>>selection;

        switch(selection)
        {
            case 0:
            // Kysy käyttäjältä uuden opiskelijan nimi ja ikä
            // Lisää uusi student StudentList vektoriin.
            {
                string nimi;
                int ika;
                cout<<"Student's name?"<<endl;
                cin>>nimi;
                cout<<"Student's age?"<<endl;
                cin>>ika;
                Student oppilas (nimi, ika);
                studentList.emplace_back(oppilas);
                break;
            }
            case 1:
            {
            // Tulosta StudentList vektorin kaikkien opiskelijoiden
            // nimet.
                cout<<"Student info:"<<endl;
                for(auto& student : studentList){
                    student.printStudentInfo();
                    break;
                }
                break;
            }
            case 2:
            {
            // Järjestä StudentList vektorin Student oliot nimen mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat
                cout<<"Student info sorted by name:\n";
                sort(studentList.begin(), studentList.end(), [](Student& a, Student& b){
                return a.getName()<b.getName();
                });
                for(auto& student : studentList){
                    student.printStudentInfo();
                }
                break;
            }
            case 3:
            {
            // Järjestä StudentList vektorin Student oliot iän mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat
                cout<<"Student info sorted by age:\n";
                sort(studentList.begin(), studentList.end(), [](Student& a, Student& b){
                    return a.getAge()<b.getAge();
                });
                for(auto& student : studentList){
                    student.printStudentInfo();
                }
                break;
            }
            case 4:
            {
            // Kysy käyttäjältä opiskelijan nimi
            // Etsi studentListan opiskelijoista algoritmikirjaston
            // find_if funktion avulla löytyykö käyttäjän antamaa nimeä
            // listalta. Jos löytyy, niin tulosta opiskelijan tiedot.
                string nimi;
                cout<<"Student to be found name:"<<endl;
                cin>>nimi;
                for(auto& student : studentList){
                    if(student.getName()==nimi){
                        cout<<"Student found!"<<endl;
                        student.printStudentInfo();
                    }
                }
                break;
            }
            default:
                cout<< "Wrong selection, stopping..."<<endl;
                break;
        }
    }while(selection < 5);

    return 0;
}
