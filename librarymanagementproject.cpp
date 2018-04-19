#include<iostream>
#include<string.h>
using namespace std;
class Library{
	
};
class Book:public Library{
	public:
	char bno[10];
	char bname[20];
	char aname[20];
	void create_book()
	{
		cout<<"ENTER THE NEW ENTR OF BOOK"<<endl;
		cout<<"Enter the book number"<<endl;
		cin>>bno;
		cout<<"Enter the book name"<<endl;
		cin.getline(bname,20);
		cout<<"Enter the name of author of the book"<<endl;
		cin.getline(aname,20);
	}
	
};
class Member:public Library{
	public:
		char mem_name[20];
		int admitno;
		int token_no;
		int duration;
		void create_member()
		{
			cout<<"ENTER THE ENTRY OF THE MEMBER"<<endl;
			cout<<"Enter the name of member"<<endl;
			cin.getline(mem_name,20);
			cout<<"Enter admit card number of the member"<<endl;
			cin>>admitno;
		}
		void issue_book()
		{
			cout<<"Enter the number of books issued"<<endl;
			cin>>token_no;
			if(token_no==4)
			{
				cout<<"SORRY NO MORE BOOKS CAN BE ISSUED !!!"<<endl;
			}
			else if(token_no<4)
			{
				cout<<4-token_no<<" More Number of books can be issued"<<endl;
			}
		}
		void duration_of_books()
		{
			cout<<"Enter the issue date"<<endl;
			int present_date;
			
		}
	
};
class Transaction:public Library{
	
};
