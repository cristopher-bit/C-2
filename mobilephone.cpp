#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Mobilephone{
    public:
    int serialNo;
    string modelNo;
    string brandName;
    double price;

    void accept()
    {
        cout<<"enter the serial number"<<endl;
        cin>>serialNo;
        cout<<"Enter the modelN0:"<<endl;
        cin.ignore();
        getline(cin,modelNo);
        cout<<"enter the brandNAme";
        cin.ignore();
        getline(cin,brandName);
        cout<<"enter the price"<<endl;
        cin>>price;
    }

    void display()
    {
        cout<<"Serial No:"<<serialNo<<endl;
        cout<<"Model No:"<<modelNo<<endl;
        cout<<"Brand Name:"<<brandName<<endl;
        cout<<"Price:"<<price<<endl;

    }
};

    void writetofile(string &filename){
        ofstream fin(filename, ios::app);
        if(!fin){
            cerr<<"error";
        }
        Mobilephone phone;
        phone.accept();
        fin<<phone.serialNo<<endl;
        fin<<phone.modelNo<<endl;
        fin<<phone.brandName<<endl;
        fin<<phone.price<<endl;
        fin.close();
         cout<<"Added";
        }

    int readfromfile(string &filename, Mobilephone phones[], int maxPhones){
        ifstream fout(filename);
        if(!fout){
            cerr<<"error";
            return 0;
        }
        int count=0;
        while(count<maxPhones && fout>>phones[count].serialNo){
            fout.ignore();
            getline(fout,phones[count].modelNo);
            getline(fout,phones[count].brandName);
            fout>>phones[count].price;
            fout.ignore();
            //phones[count].display();
            count++;
        }
        fout.close();
        return count;
}

void sortarraybyprice(Mobilephone phones[],int count)
{
    for(int i=0;i<count-1;i++)
    {
        for(int j=0;j<count-i-1;j++){
            if(phones[j].price>phones[j+1].price)
            {
                Mobilephone temp =phones[j];
                phones[j]=phones[j+1];
                phones[j+1]=temp;
            }
        }
    }
}

void displayphone(Mobilephone phones[], int count){
    for(int i=0;i<count;i++){
        phones[i].display();
        cout<<"-------------\n";
    }
}


int main(){
    int maxPhones = 10;
    Mobilephone phones[maxPhones];
    string filename="abc.txt";
    int phonecount;
    int choice;
    do {
        cout << "\nMenu:\n"
                  << "1. Add MobilePhone to file\n"
                  << "2. Read and display MobilePhones from file\n"
                  << "3. Read, sort by price, and display MobilePhones\n"
                  << "4. Exit\n"
                  << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                writetofile(filename);
                break;
            case 2:
                phonecount=readfromfile(filename,phones,maxPhones);
                displayphone(phones,phonecount);
            break;   
            case 3: 
                phonecount=readfromfile(filename,phones,maxPhones);
            sortarraybyprice(phones,phonecount);
            displayphone(phones,phonecount);
            break;
            case 4:
                cout<<"exiting \n";
                break;
            default:
                cout<<"Invalid choice, please try agian. \n";
                
          }
        } while(choice != 4);
          return 0;
        }
    
