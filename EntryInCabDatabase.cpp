// Add new cab to database
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
    fstream fil,fil2;
    int i=0;
    cab ob;
    char ch='y';
    fil.open("cabdatabase.txt",ios::out);
    while(ch=='Y'|| ch=='y')
    {
        cout<<"Enter cab number: "<<endl;
        cin>>ob.cabno;
        cin.clear();
        cout<<"Enter cab booking status: "<<endl;
        cin>>ob.cab_status;
        cin.clear();
        cout<<"Enter driver_name: "<<endl;
        cin>>ob.driver_name;
        cin.clear();
        cout<<"Enter cab's current pickup: "<<endl;
        cin>>ob.pickup;
        cin.clear();
        cout<<"Enter cab name: "<<endl;
        cin>>ob.cab_name;
        cin.clear();
        cout<<"Enter cab's current drop: "<<endl;
        cin>>ob.drop;
        cin.clear();
        ob.avg_rating=5;
        cout<<"Enter cab's earnings till now: "<<endl;
        cin>>ob.earnings;
        cin.clear();
        cout<<"Enter cab's total no. of booking with us till now: "<<endl;
        cin>>ob.noofbookings;
        cin.clear();
        ob.id=((int)(rand())*10000)+((int)(ob.cabno[5])*1000) + ((int)(ob.cabno[6])*100) + ((int)(ob.cabno[7])*10) + ((int)(ob.cabno[8]));
        fil.write((char*) &ob,sizeof(ob));
        cin.clear();
        cout<<"Do you want to add more ? [Y/N]";
        cin>>ch;
    }
    fil.close();
    //return 0;
}
