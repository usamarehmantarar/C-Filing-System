/*
	tip: Declare the OP type or option varibales out in the main, as it would put them in the scope.
	Program developed by Usama Rehman Tarar.
	This program demonstrates the student management system, by taking inputs for id and name.
	There are three file basic system header files for the filing in C++:
	1-fstreambase --parent file
	2-iftsream --daughter file --derived from fstreambase
	3-ofstream --daughter file --derived from fstreambase
	
	In C++, to work with the file systems you need to open the file. So, basically there are two methods to open the file in C++
	1- using the constructor.
	2- using the member function open() of the class.
*/


#include<fstream>
#include<iostream>
#include<conio.h>
using namespace std;

struct student
{
	int id;
	char name[20];
	
};
void writedata(student s)
{
	ofstream f("record.txt", ios::app);
	f<<s.id<<"\t"<<s.name<<endl;
	//cout<<s.id<<"\t"<<s.name<<endl;
}
void getdata(student s)
{
	cout<<"Enter ID: ";
	cin>>s.id;
	
	cout<<"Enter the Student's Name: ";
	cin>>s.name;
	
	writedata(s);
}
void display(student s)
{
	cout<<"\n";
	cout<<s.id<<"\t"<<s.name<<endl;
	
	
}

void readdata(student s)
{
	ifstream f("record.txt", ios::in);
	if(!f)
	{
		cout<<"File not found!";
		
	}
	else
	{
		/*
		student s;
		char h1[20];
		char h2[20];
		f>>h1>>h2;
		cout<<endl<<h1<<"\t"<<h2;
		*/
		while(f>>s.id>>s.name)
		display(s);
	}
}



int main()
{
	student s;
	int op;
	
	do
	{
		int ch;
		
		
		cout<<"Press 1 to Input\n";
		cout<<"Press 2 to display\n";
		
		ch=getche();
		
		switch (ch)
		{
			case '1':
				getdata(s);
				break;
			case '2':
				readdata(s);
				break;
			
				
		}
		cout<<"\n Do you want to continue..1/2: ";
	}
	while (getche()=='1');
		cout<<"\n\n\n\t\t\t Thanks and Good bye!";
	getch();
	

}
