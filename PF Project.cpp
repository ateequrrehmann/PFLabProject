#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>
#include<windows.h>
using namespace std;
void addcomplaint();
void y();
void insertcomplaint();
void searchcomplaint();
struct complaints
{
	public:
		int number;
		string name; 
		string cnic;
		string description;
};

void user()
{
	cout<<"Welcome to Complaint Management System"<<endl;
	cout<<"Press 1 to Register complaint"<<endl;
	cout<<"Press 2 to Exit"<<endl;
	int choice;
	cout<<"Enter choice"<<endl;
	cin>>choice;
	while(choice!=1 && choice!=2)
	{
		system("color 4");
		system("CLS");
		cout<<"Wrong. Enter correct command"<<endl;
		cout<<"Welcome to Complaint Management System"<<endl;
		cout<<"Press 1 to Register complaint"<<endl;
		cout<<"Press 2 to Exit"<<endl;
		cout<<"Enter choice"<<endl;
		cin>>choice;
	}
	system("CLS");
	system("color A");
	switch(choice)
	{
		case 1:
			addcomplaint();
			break;
		case 2:
			cout<<"Thanks "<<endl;
			break;
	}
}

void addcomplaint()
{
	int max_complaints = 100;
	int count = 0;
	string choice;
	complaints complaint[max_complaints];
	cout<<"Do you want to register complaint"<<endl;
	cin>>choice;
	system("CLS");
	while(choice!="Yes" && choice!="No")
	{
		system("color 4");
		cout<<"Wrong"<<endl;
		cin>>choice;
	}
	system("color A");
	if(choice=="Yes")
	{
		y();
	}
	if(choice=="No")
	{
		cout<<"Thankx for giving feedback";
	}
}

void y()
{
	int max_complaints = 100;
	complaints complaint[max_complaints];
	int count=0;
	string choice;
		while(count<=max_complaints)
		{
			system("CLS");
			cout<<"Enter complaint number"<<endl;
			cin>>complaint[count].number;
			cout<<"Enter name"<<endl;
			cin>>complaint[count].name;
			cout<<"Enter your cnic without spaces"<<endl;
			cin>>complaint[count].cnic;
			system("color A");
			while(complaint[count].cnic.length()!=13)
			{
				system("color 4");
				cout<<"Wrong! Enter your cnic without spaces"<<endl;
				cin>>complaint[count].cnic;
			}
			system("color A");
			cout<<"Enter the complaint title"<<endl;
			cin>>complaint[count].description;	
			ofstream file("complaint.txt", ios::app);
			file<<complaint[count].number<<" "<<complaint[count].name<<" "<<complaint[count].cnic<<" "<<complaint[count].description<<endl;
			file.close();
			count++;

			system("CLS");
			cout<<"Complaint added successfully"<<endl;
			cout<<"Do you want to register complaint"<<endl;
			cin>>choice;
			while(choice!="Yes" && choice!="No")
			{
				system("color 4");
				system("CLS");
				cout<<"Wrong enter right"<<endl;
				cin>>choice;
				if(choice=="Yes")
				{
					system("color A");
					y();
				}
				else if(choice=="No")
				{
					system("color A");
					cout<<"Thanks for giving feedback";
					return;
				}
			}
			if(choice=="No")
			{
				system("color A");
				cout<<"Thanks for giving feedback"<<endl;
				return;
			}
}

}

void insertcomplaint()
{
	string choice="Yes";
	complaints complaint;
	while(choice=="Yes")
	{
		system("CLS");
		cout<<"Enter complaint number"<<endl;
		cin>>complaint.number;
		cout<<"Enter name"<<endl;
		cin>>complaint.name;
		cout<<"Enter your cnic without spaces"<<endl;
		cin>>complaint.cnic;
		while(complaint.cnic.length()!=13)
		{
			system("color 4");
			cout<<"Wrong! Enter your cnic without spaces"<<endl;
			cin>>complaint.cnic;
		}
		system("color A");
		cout<<"Enter the complaint title"<<endl;
		cin>>complaint.description;
		ofstream file("complaint.txt", ios::app);
		file<<complaint.number<<" "<<complaint.name<<" "<<complaint.cnic<<" "<<complaint.description<<endl;
		file.close();
		system("CLS");;
		cout<<"Complaint inserted Successfully"<<endl;
		cout<<"Do you want to again insert the new complaint"<<endl;
		cin>>choice;
		while(choice!="Yes" && choice!="No")
		{
			system("color 4");
			system("CLS");
			cout<<"Wrong enter right"<<endl;
			cin>>choice;
		}
		system("color A");
	}
	if(choice=="No")
	{
		cout<<"Thank for cooperating with us"<<endl;
		system("pause");
//		system("CLS");
	}
}


void searchcomplaint()
{
	string name, choice;
	complaints complaint;
	choice="Yes";
	while(choice=="Yes")
	{
		system("color A");
		system("CLS");
		cout<<"Enter the name of complainer you want to search for"<<endl;
		cin>>name;
		ifstream file("complaint.txt");
		
		while(file>>complaint.number>>complaint.name>>complaint.cnic>>complaint.description)
		{
//			count=true;
			if(complaint.name==name)
			{
				cout<<"Found:\n";
				cout<<"Complaint Number "<<complaint.number<<endl;
				cout<<"Name "<<complaint.name<<endl;
				cout<<"CNIC "<<complaint.cnic<<endl;
				cout<<"Title "<<complaint.description<<endl;
				cout<<endl;
			}
		}
		cout<<"Do you want to again search the complaint"<<endl;
		cin>>choice;
		while(choice!="Yes" && choice!="No")
		{
			system("color 4");
			system("CLS");
			cout<<"Wrong!Do you want to again search the complaint"<<endl;
			cin>>choice;
		}
		system("color A");
		if(choice=="No")
		{
			cout<<"Thank for cooperating with us"<<endl;
			system("pause");
		}
	//			system("CLS");
		file.close();
//		system("CLS");
	}
	
}

void admin()
{
	int choice;
	string name, password;
	cout<<"Enter name and password for login"<<endl;
	cout<<"Enter your name"<<endl;
	cin>>name;
	cout<<"Enter your password"<<endl;
	cin>>password;
	while(name!="Ateeq" || password!="123")
	{
		system("CLS");
		system("color 4");
		cout<<"Wrong. Reenter"<<endl;
		cout<<"Enter your name"<<endl;
		cin>>name;
		cout<<"Enter your name"<<endl;
		cin>>password;
	}
	system("color A");
	cout<<"Login Successful"<<endl;
	system("pause");
	while(name=="Ateeq" && password=="123")
	{
		system("CLS");
		cout<<"1. Insert a complaint"<<endl;
		cout<<"2. Search for a complaint"<<endl;
		cout<<"3. Exit"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>choice;
		while(choice!=1 && choice!=2 && choice!=3)
		{
			system("CLS");
			system("color 4");
			cout<<"Wrong command. Please reenter"<<endl;
			cout<<"1. Insert a complaint"<<endl;
			cout<<"2. Search for a complaint"<<endl;
			cout<<"3. Exit"<<endl;
			cout<<"Enter your choice"<<endl;
			cin>>choice;
		}
		system("color A");
		switch(choice)
		{
			case 1:
				system("CLS");
				insertcomplaint();
				break;
			case 2:
				system("CLS");
				searchcomplaint();
				break;
			case 3:
				cout<<"Thank you"<<endl;
				return;
		}
	}		
}

int main()
{

	int choice;
	cout<<"Choice:"<<endl;
	cout<<"1. Admin"<<endl;
	cout<<"2. Customer"<<endl;
	cout<<"3. Exit"<<endl;
	cout<<"Enter your choice"<<endl;
	cin>>choice;
	while(choice!=1 && choice!=2 && choice!=3)
	{
		system("color 4");
		system("CLS");
		cout<<"Wrong"<<endl;
		cout<<"Choice:"<<endl;
		cout<<"1. Admin"<<endl;
		cout<<"2. Customer"<<endl;
		cout<<"3. Exit"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>choice;

	}
	system("color A");
	switch(choice)
	{
		case 1: 
			system("CLS");
			admin();
			break;
		case 2:
			system("CLS");
			user();
			break;
		case 3:
			break;
	}
	getch();
	return 0;	
}

