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
    char cab_reg_no[10];
    char cab_model[20];
    char cab_type[20];
    char cab_company[30];
    int cab_capacity;
    int location_id;
    char cab_status[15];
    int cab_driver_id;
public:
    void getdata(){
        cout<<"Enter cab ID : ";
        cin>>cab_id;
        cout<<"Enter Cab Reg. Number : ";
        cin>>cab_reg_no;
        cin.sync();
        cout<<"Enter Cab model : ";
        //cin>>cab_model;
        gets(cab_model);
        cout<<"Enter Cab type : ";
        gets(cab_type);
        //cin>>cab_type;
        cout<<"Enter Cab company : ";
        //cin>>cab_company;
        gets(cab_company);
        cout<<"Enter Cab capacity : ";
        cin>>cab_capacity;
        cout<<"Enter Cab location ID : ";
        cin>>location_id;
        cin.sync();
        cout<<"Enter Cab status (booked/available): ";
        gets(cab_status);
        cout<<"Enter Cab driver_id : ";
        cin>>cab_driver_id;
    }

    void showdata(){
         cout<<"cab ID : "<<cab_id<<endl;
        
        cout<<"Cab Reg. Number : ";
        puts(cab_reg_no);
        cout<<endl;
  
        cout<<"Cab model : ";
        puts(cab_model);
        cout<<endl;
 
        cout<<"Cab type : ";
        puts(cab_type);
        cout<<endl;
    
        cout<<"Cab company : ";
        puts(cab_company);
        cout<<endl;
       
        cout<<"Cab capacity : "<<cab_capacity<<endl;
 
        cout<<"Cab location ID : "<<location_id<<endl;

        cout<<"Cab status : ";
        puts(cab_status);
        cout<<endl;
    
        cout<<"Cab driver_id : "<<cab_driver_id<<endl;
    }
    int getCabId(){
        return cab_id;
    }
    char * getCabReg(){
        return cab_reg_no;
    }
    int getCabLoc(){
        return location_id;
    }
};
class Driver{
private:
    int driver_id;
    int driver_user_id;
    char driver_name[20];
    char driver_contact[10];
    char driver_dl[20];
    char driver_aadhar[12];
    int driver_cab_id;
    int driver_age;
    int driver_ride_count;

public:
    void getdata(){
        cout<<"Enter Driver ID : ";
        cin>>driver_id;
        cout<<"Enter driver user id : ";
        cin>>driver_user_id;
        cin.sync();
        cout<<"Enter Driver name : ";
        gets(driver_name);
        cout<<"Enter contact number : ";
        gets(driver_contact);
        cout<<"Enter Driving license number : ";
        gets(driver_dl);
        cout<<"Enter Driver Aadhar number : ";
        gets(driver_aadhar);
        cin.sync();
        cout<<"Enter Cab id : ";
        cin>>driver_cab_id;
        cout<<"Enter Driver age : ";
        cin>>driver_age;
        cout<<"Enter driver ride count : ";
        cin>>driver_ride_count;
    }
    void showdata(){
         cout<<"Driver ID : "<<driver_id<<endl;
        
        cout<<"Driver User id : "<<driver_user_id;
        cout<<endl;
  
        cout<<"Driver Name : ";
        puts(driver_name);
        cout<<endl;
 
        cout<<"Contact number : ";
        puts(driver_contact);
        cout<<endl;
    
        cout<<"Dl number : ";
        puts(driver_dl);
        cout<<endl;

        cout<<"Aadhar number : ";
        puts(driver_aadhar);
        cout<<endl;
       
        cout<<"Cab Id : "<<driver_cab_id<<endl;
 
        cout<<"Driver age : "<<driver_age<<endl;
    
        cout<<"Driver ride count : "<<driver_ride_count<<endl;
    }
    int getdriverId(){
        return driver_id;
    }
    char * getDriverName(){
        return driver_name;
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
void addDriver(){
    ofstream fout;
    fout.open("Driver.dat",ios::binary);
    Driver d1;
    char choice='y';
    while(choice=='y'){
        d1.getdata();
        fout.write((char*)&d1,sizeof(d1));
        cout<<"Want to add more? y/n ";
        cin>>choice;
    }
    fout.close();
}
void getCabDetails(){
    int choice;
    cout<<"Select type of search :"<<endl;
    cout<<"Search by Cab ID (1)"<<endl;
    cout<<"Search by Cab Registration No. (2)"<<endl;
    cout<<"Search by Cab Location (3)"<<endl;
    cin>>choice;
    switch (choice)
    {
    case 1:
        {
            int cab_id;
            cout<<"Enter cab id ";
            cin>>cab_id;
            ifstream fin;
            fin.open("Cab.dat",ios::binary);
            Cab c1;
            while(fin.read((char*)&c1,sizeof(c1))){
                int id=c1.getCabId();
                if(id==cab_id)
                    c1.showdata();
            }
            fin.close();
            break;
        }
        case 2:
        {
            char cab_reg[10];
            cout<<"Enter cab registration number ";
            gets(cab_reg);
            ifstream fin;
            fin.open("Cab.dat",ios::binary);
            Cab c1;
            while(fin.read((char*)&c1,sizeof(c1))){
                if(!strcmpi(c1.getCabReg(),cab_reg))
                    c1.showdata();
            }
            fin.close();
            break;
        }
        case 3:
        {
            int loc_id;
            cout<<"Enter cab location id ";
            cin>>loc_id;
            ifstream fin;
            fin.open("Cab.dat",ios::binary);
            Cab c1;
            while(fin.read((char*)&c1,sizeof(c1))){
                int id=c1.getCabLoc();
                if(id==loc_id)
                    c1.showdata();
            }
            fin.close();
            break;
        }
        
    
    default:
        cout<<"Wrong Choice ";
        getCabDetails();
        break;
    }
}
void getDriverDetails(){
    int choice;
    cout<<"Select type of search :"<<endl;
    cout<<"Search by Driver ID (1)"<<endl;
    cout<<"Search by Driver Name. (2)"<<endl;
    cin>>choice;
    switch (choice)
    {
    case 1:
        {
            int driver_id;
            cout<<"Enter Driver id ";
            cin>>driver_id;
            ifstream fin;
            fin.open("Driver.dat",ios::binary);
            Driver d1;
            while(fin.read((char*)&d1,sizeof(d1))){
                int id=d1.getdriverId();
                if(id==driver_id)
                    d1.showdata();
            }
            fin.close();
            break;
        }
        case 2:
        {
            char dname[20];
            cout<<"Enter Driver name ";
            gets(dname);
            ifstream fin;
            fin.open("Driver.dat",ios::binary);
            Driver d1;
            while(fin.read((char*)&d1,sizeof(d1))){
                if(!strcmp(d1.getDriverName(),dname))
                    d1.showdata();
            }
            fin.close();
            break;
        }
        
    
    default:
        cout<<"Wrong Choice ";
        getDriverDetails();
        break;
    }
}
void updateCabDetails(){
     int choice;
    cout<<"Select type of search :"<<endl;
    cout<<"Search by Cab ID (1)"<<endl;
    cout<<"Search by Cab Registration No. (2)"<<endl;
    cin>>choice;
    switch (choice)
    {
    case 1:
        {
            int cab_id;
            cout<<"Enter cab id ";
            cin>>cab_id;
            fstream f;
            f.open("Cab.dat",ios::app | ios::binary);
            Cab c1;
            int flag=0;
            int pos;
            while(!f.eof()){
                pos=f.tellg();
                f.read((char*)&c1,sizeof(c1));
                int id=c1.getCabId();
                if(id==cab_id){
                    c1.getdata();
                    f.seekg(pos);
                    f.write((char*)&c1,sizeof(c1));
                    flag=1;
                    break;
                }
            }
            f.close();
            if(flag==0)
                cout<<"Record not found";
            break;
        }
        case 2:
        {
            string cab_reg;
            cout<<"Enter cab registration number ";
            cin>>cab_reg;
            fstream f;
            f.open("Cab.dat",ios::app | ios::binary);
            Cab c1;
            int flag=0;
            int pos;
            while(!f.eof()){
                pos=f.tellg();
                f.read((char*)&c1,sizeof(c1));
                string reg_no=c1.getCabReg();
                if(reg_no==cab_reg){
                    c1.getdata();
                    f.seekg(pos);
                    f.write((char*)&c1,sizeof(c1));
                    flag=1;
                    break;
                }
            }
            f.close();
            if(flag==0)
                cout<<"Record not found";
            break;
        }
        
    
    default:
        cout<<"Wrong Choice ";
        getCabDetails();
        break;
    }
}
int main(){
    addCab();
    getCabDetails();
    return 0;
}