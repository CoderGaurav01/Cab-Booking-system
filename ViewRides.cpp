//View all rides details
#include<bits/stdc++.h>
using namespace std;

typedef struct cab
{
    int id;
    char cabno[9];
    int pickup;
    char driver_name[6];
    int drop;
    char cab_name[6];
    int cab_status; //Enter only 1 or 0. 1 for cab is not available, 0 for cab is available
    int avg_rating,earnings;
    int noofbookings;
}cab;

int main()
{
    int i=1;
    fstream fil,fil2;
    cab ob;
    char ch;
    fil.open("cabdata1.txt",ios::in);
    //fil.seekg(0,ios::beg);
    i=i;
    while(fil.read((char*) &ob,sizeof(ob)))
    {
        cout<<i<<"."<<endl;
        cout<<"\nCab's ID: "<<ob.id;
        cout<<"\nCab number: "<<ob.cabno;
        cout<<"\nCab booking status: "<<ob.cab_status;
        cout<<"\nDriver_name: "<<ob.driver_name;
        cout<<"\ncab's current pickup: "<<ob.pickup;
        cout<<"\nCab name: "<<ob.cab_name;
        cout<<"\ncab's current drop: "<<ob.drop;
        cout<<"\nAvg_rating: "<<ob.avg_rating<<endl;
        cout<<"cab's earnings till now: "<<ob.earnings<<endl;
        cout<<"cab's total no. of booking with us till now: "<<ob.noofbookings<<endl;
        cout<<"---------------------------------------------------------"<<endl;
        i++;
    }
    fil.close();
}
