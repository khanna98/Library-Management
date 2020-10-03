#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class Book
{
    int book_id;
    string book_name;
    string author;
    float price;
    int status = 0;
public:
    void acceptbook()
    {
        cout<<"Enter book id: ";
        cin>>book_id;
        cout<<"Enter book name: ";
        cin>>book_name;
        cout<<"Enter author name: ";
        cin>>author;
        cout<<"Enter price: ";
        cin>>price;
        status = 0;
    }
    void display()
    {
    	cout<<"*****************************************"<<endl;
        cout<<"Name   : "<<book_name<<endl;
        cout<<"ID     : "<<book_id<<endl;
        cout<<"Author : "<<author<<endl;
        cout<<"Price  : "<<price<<endl;
        if(status == 0)
        {
            cout<<"Status : Not Isseued"<<endl;
        }
        else
        {
            cout<<"Status : Isseued"<<endl;
        }
        cout<<"*****************************************"<<endl;
    }
    void addbook();
    void viewbook();
    void searchbook();
    void deletebook();
};
Book obj;
void Book::addbook()
{
    obj.acceptbook();
    fstream wr;
    wr.open("./book_data.txt",ios::app);
    wr.write((char *)&obj,sizeof(obj));
    cout<<"*****************************************"<<endl;  
    cout<<"Book Added Successfully"<<endl;
    cout<<"*****************************************"<<endl;
}
void Book::viewbook()
{
    fstream rd;
    rd.open("./book_data.txt",ios::in);
    rd.seekg(0,ios::end);
    int size = rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    for(int i=1;i<=size;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        obj.display();
    }
}
void Book::searchbook()
{
    fstream rd;
    rd.open("./book_data.txt",ios::in);
    char n[50];
    cout<<"Enter name of book: ";
    cin>>n;
    rd.seekg(0,ios::end);
    int size = rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    int flag = 0;
    for(int i=1;i<=size;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(strcmp(n,obj.book_name) == 0)
        {
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        cout<<"Sorry We didn't find that book !"<<endl;
    }
    else
    {
    	cout<<"*****************************************"<<endl;
    	cout<<"Book Found"<<endl;
    	cout<<"*****************************************"<<endl;
        obj.display();
    }
}
void Book::deletebook()
{
    fstream rd,wr;
    rd.open("./book_data.txt",ios::in);
    wr.open("./temp.txt",ios::app);
    char n[50];
    cout<<"Enter name of the Book :";
    cin>>n;
    rd.seekg(0,ios::end);
    int size = rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    int flag = 0;
    for(int i=1;i<=size;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(strcmp(n,obj.book_name)==0)
        {
            cout<<"Book Removed"<<endl;
        }
        else
        {
            wr.write((char *)&obj,sizeof(obj));
        }
    }
    rd.close();
    wr.close();
    remove("./book_data.txt");
    rename("./temp.txt","./book_data.txt");
}
int main()
{
    int choice;
    cout<<"********************* Welcome To Library Management System ********************"<<endl;
    while(1)
    {
        cout<<"What would you want me to do ?"<<endl;
        cout<<"1. Add Book"<<endl;
        cout<<"2. View Book"<<endl;
        cout<<"3. Search Book"<<endl;
        cout<<"4. Remove Book"<<endl;
        cout<<"5. Exit"<<endl;
        cin>>choice;
        if(choice == 1)
        {
            Book b1;
            b1.addbook();
        }
        else if(choice == 2)
        {
            Book b1;
            b1.viewbook();
        }
        else if(choice == 3)
        {
            Book b1;
            b1.searchbook();
        }
        else if(choice == 4)
        {
            Book b1;
            b1.deletebook();
        }
        else
        {
            break;
        }
    }
    cout<<"Thank You for using our software"<<endl<<"Have a Nice Day !"<<endl;
    return 0;
}
