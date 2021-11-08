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
        //cin>>cab_model;
        getline(cin,cab_model);
        cout<<"Enter Cab type : ";
        getline(cin,cab_type);
        //cin>>cab_type;
        cout<<"Enter Cab company : ";
        //cin>>cab_company;
        getline(cin,cab_company);
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
         cout<<"cab ID : "<<cab_id<<endl;
        
        cout<<"Cab Reg. Number : "<<cab_reg_no<<endl;
  
        cout<<"Cab model : "<<cab_model<<endl;
 
        cout<<"Cab type : "<<cab_type<<endl;
    
        cout<<"Cab company : "<<cab_company<<endl;
       
        cout<<"Cab capacity : "<<cab_capacity<<endl;
 
        cout<<"Cab location ID : "<<location_id<<endl;

        cout<<"Cab status : "<<cab_status<<endl;
    
        cout<<"Cab driver_id : "<<cab_driver_id<<endl;
    }
    int getCabId(){
        return cab_id;
    }
    string getCabReg(){
        return cab_reg_no;
    }
    int getCabLoc(){
        return location_id;
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
            string cab_reg;
            cout<<"Enter cab registration number ";
            cin>>cab_reg;
            ifstream fin;
            fin.open("Cab.dat",ios::binary);
            Cab c1;
            while(fin.read((char*)&c1,sizeof(c1))){
                string reg_no=c1.getCabReg();
                if(reg_no==cab_reg)
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
int main(){
    addCab();
    getCabDetails();
    return 0;
}