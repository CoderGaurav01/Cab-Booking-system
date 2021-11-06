//*********************************************************************************************************
//*                        PrOjEcT:- "CaB BoOkInG SyStEm"                                                 *
//*********************************************************************************************************

#include<iostream>//Header File
#include<string>//Header File
#include<fstream>//Header File
#include<conio.h>//Header File
#include<cctype>//Header File
#include<windows.h>//Header File
using namespace std;
class Cab{
private:
    int cab_id;
    string cab_reg_no;
    string cab_model;
    string cab_type;
    string cab_company;
    int cab_capacity;
    int location_id;
    string cab_status;
    int cab_driver_id;
public:
    void getdata(){
        cout<<"Enter cab ID : ";
        cin>>cab_id;
        cout<<"Enter Cab Reg. Number : ";
        cin>>cab_reg_no;
        cout<<"Enter Cab model : ";
        cin>>cab_model;
        cout<<"Enter Cab type : ";
        cin>>cab_type;
        cout<<"Enter Cab company : ";
        getline(cab_company);
        cout<<"Enter Cab capacity : ";
        cin>>cab_capacity;
        cout<<"Enter Cab location ID : ";
        cin>>location_id;
        cout<<"Enter Cab status : ";
        cin>>cab_status;
        cout<<"Enter Cab driver_id : ";
        cin>>cab_driver_id;
    }
    void showdata(){
         cout<<"cab ID : "<<cab_id;
        
        cout<<"Cab Reg. Number : "<<cab_reg_no;
  
        cout<<"Cab model : "<<cab_model;
 
        cout<<"Cab type : "<<cab_type;
    
        cout<<"Cab company : "<<cab_company;
       
        cout<<"Cab capacity : "<<cab_capacity;
 
        cout<<"Cab location ID : "<<location_id;

        cout<<"Cab status : "<<cab_status;
    
        cout<<"Cab driver_id : "<<cab_driver_id;
    }
};
void addCab(){
    ofstream fout;
    fout.open("Cab.dat",ios::binary);
    Cab c1;
    char choice='y';
    while(choice=='y'){
        c1.getdata();
        fout.write((char*)&c1,sizeof(c1));
        cout<<"Want to add more? y/n ";
        cin>>choice;
    }
    fout.close();
}
int main(){
    addCab();
    return 0;
}