#include "chef.h"

Chef::Chef(string n)
{
    chefName = n;
    cout<<"Chef "<<chefName<<" constructor"<<endl;
}

Chef::~Chef()
{
    cout<<"Chef "<<chefName<<" destructor"<<endl;
}

string Chef::getName()
{
    return chefName;
}

int Chef::makeSalad(int i)
{
    int numOfSalad = i/5;
    cout<<"Chef "<<chefName<<" with "<<i<<" items can make "<<numOfSalad<<" salad portions"<<endl;
    return numOfSalad;
}

int Chef::makeSoup(int i)
{
    int numOfSoup = i/3;
    cout<<"Chef "<<chefName<<" with "<<i<<" items can make "<<numOfSoup<<" soup portions"<<endl;
    return numOfSoup;
}
