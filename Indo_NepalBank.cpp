#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
using namespace std;
void SetCursor(int x,int y)
	{
    	HANDLE output=GetStdHandle(STD_OUTPUT_HANDLE);
    	COORD pos={x,y};
    	SetConsoleCursorPosition(output,pos);
	}
class admin
{ 
	long long unsigned int totalacc, totalsavingacc, totalcurrentacc;
	double totalbalance;
	public:
		void total(string type,double balance,int n)
		{
			fstream fp;
			fp.open("total.txt",ios::in);
			if(!fp)
			{
				fp.open("total.txt",ios::out);
				totalacc=1;
				totalbalance=balance;
				if(type=="s")
				{
					totalsavingacc=1;
					totalcurrentacc=0;
				}
				else if(type=="c")
				{
					totalcurrentacc=1;
					totalsavingacc=0;
				}
				fp<<totalacc<<endl<<totalsavingacc<<endl<<totalcurrentacc<<endl<<totalbalance;
				fp.close();
			}
			else
			{
				fp>>totalacc>>totalsavingacc>>totalcurrentacc>>totalbalance;
				if(n==1)
				{
					totalacc++;
					totalbalance=(double)totalbalance+balance;
					if(type=="s")
						totalsavingacc++;
					else if(type=="c")
						totalcurrentacc++;
				}
				else if(n==2)
				{
					totalacc--;
					totalbalance=(double)totalbalance-balance;
					if(type=="s")
						totalsavingacc--;
					else if(type=="c")
						totalcurrentacc--;
				}
				fp.close();
				fp.open("total.txt",ios::out);
				fp<<totalacc<<endl<<totalsavingacc<<endl<<totalcurrentacc<<endl<<totalbalance;
				fp.close();
			}
	}
		void gettotal(double balance,int temp)
		{
			fstream fp;
			fp.open("total.txt",ios::in);
			if(!fp)
			cout<<"Error: Analytics file may have been deleted. Please check total.txt file\n";
			else
			{
				fp>>totalacc>>totalsavingacc>>totalcurrentacc>>totalbalance;
				if(temp==1)
				totalbalance=(double)balance+totalbalance;
				else if(temp==2)
				totalbalance=(double)totalbalance-balance;
				fp.close();
				fp.open("total.txt",ios::out);
				fp<<totalacc<<endl<<totalsavingacc<<endl<<totalcurrentacc<<endl<<totalbalance;
				fp.close();
			}
		}
		void total(string type)
		{
			fstream fp;
			fp.open("total.txt",ios::in);
				fp>>totalacc>>totalsavingacc>>totalcurrentacc>>totalbalance;
				if(type=="s")
				{
					totalsavingacc++;
					totalcurrentacc--;
				}
				else if(type=="c")
				{
					totalcurrentacc++;
					totalsavingacc--;
				}
				fp.close();
				fp.open("total.txt",ios::out);
				fp<<totalacc<<endl<<totalsavingacc<<endl<<totalcurrentacc<<endl<<totalbalance;
				fp.close();
		}
		void showtotal()
		{
			fstream fp;
			fp.open("total.txt",ios::in);
			if(!fp)
			cout<<"Access Denied!\nInfo: No Accounts Created\n";
			else
			{
				fp>>totalacc>>totalsavingacc>>totalcurrentacc>>totalbalance;
				cout<<left<<setw(20)<<"Total Accounts";
				cout<<left<<setw(20)<<"Saving Accounts";
				cout<<left<<setw(20)<<"Current Accounts";
				cout<<left<<setw(20)<<"Total Balance\n";
				cout<<left<<setw(20)<<totalacc;
				cout<<left<<setw(20)<<totalsavingacc;
				cout<<left<<setw(20)<<totalcurrentacc;
				cout<<left<<setw(20)<<totalbalance<<endl;
			}
		}
};
class account
{
	long long unsigned int pass,pas,pa;
	string acc;
	public:
	void setaccount()
		{
			int choice,c=0;
			fstream fp,ft;
			ft.open("pass.txt",ios::in);
			ft>>pass;
			if(ft)
			{
				do{
					system("cls");
					SetCursor(45,4);
					cout<<"Enter Password To continue";
					SetCursor(50,6);
					cin>>pas;
				}while(pas!=pass);
				do{
						
						system("cls");
						SetCursor(45,2);
						cout<<"Enter Your Choice:";
						Sleep(100);
						SetCursor(45,4);
						cout<<"1.Change Password:";
						SetCursor(45,6);
						Sleep(100);
						cout<<"0.Exit";
						SetCursor(50,8);
						cin>>choice;
						switch(choice)
						{
							case 1:
								ft.close();
								cout<<"\nEnter a New Password:";
								cin>>pas;
								cout<<"\nEnter Again:";
								cin>>pa;
								if(pas==pa)
								{
									c++;
									ft.open("pass.txt",ios::out);
									cout<<"\nPassword Changed!";
									ft<<pas;
									getch();
								}
								else
								{
									cout<<"\nPassword Didn't Match!";
									getch();
								}
								break;
							case 0:
								ft.close();
								break;	
							default:
								cout<<"Wrong Choice!";
								break;
						}
						if(c==1)
						break;
				}while(choice!=0);
			}
			else
			{
				string countrycode,postalcode,bankcode,branchcode;
				fp.open("account.txt",ios::out);
				ft.open("pass.txt",ios::out);
				cout<<"Please enter your country code ";
				cin>>countrycode;
				cout<<"Please enter your postal code ";
				cin>>postalcode;
				cout<<"Please enter your Bank code ";
				cin>>bankcode;
				cout<<"Please enter branch code ";
				cin>>branchcode;
				acc=countrycode+postalcode+bankcode+branchcode+"0001";
				cout<<acc<<endl;
				cout<<"Please set a password.";
				cin>>pass;
				ft<<pass;
				fp<<acc;
				fp.close();
				ft.close();
			}
		}
		int check()
		{
			fstream ft;
			int i=0;
			long long unsigned int pass,pas;
			ft.open("pass.txt",ios::in);
			ft>>pass;
			do
			{
			system("cls");		
			SetCursor(40,5);
			cout<<"**********************************"<<endl;
    		SetCursor(45,7);
			cout<<"WELCOME TO INDO-NEPAL BANK"<<endl;
    		SetCursor(40,9);
			cout<<"**********************************"<<endl<<endl<<endl;
			SetCursor(45,11);
			cout<<"Enter Password to Continue:";
			SetCursor(55,12);
			cin>>pas;
				if(pas==pass)
				{
					system("cls");
					ft.close();
					return(1);
				}
				else
				{
					i++;
					SetCursor(45,14);
					cout<<"Wrong Password! Try Again!\n";
					SetCursor(55,15);
					getch();
					if(i==3)
					{
						system("cls");
						ft.close();
						return(0);
					}
				}
			}while(pas!=pass);
		}
		long long unsigned int getaccount()
		{
			fstream fp;
			long long unsigned int ac;
			fp.open("account.txt",ios::in);
			fp>>acc;
			stringstream ss(acc);
			ss>>ac;
			fp.close();
			ac=ac+1;
			fp.open("account.txt",ios::out);
			fp<<ac;
			fp.close();
			return(ac);
		}
};
class bank
{
    private:
    string acno,fname,lname,type,pin,balance,ch,interest;
    public:
    	admin ob;
    void getdata(string ch)
    {
    		int c;
    		double x=0;
    		cout<<"Enter your First name\n";
            cin.ignore();
            cin>>fname;
            cout<<"Enter your last name\n";
            cin.ignore();
            cin>>lname;
            cout<<"Press S for saving account or Press C for current account\n";
            cin>>type;
            cin.ignore();
            cout<<"Enter a Account Pin Number\n";
            cin>>pin;
            do
            {
            	c=0;
            	cout<<"Enter the amount you want to deposit. Minimum Amount>=500.\n";
            	cin>>balance;
            	stringstream ss(balance);
            	ss>>x;
            	if(x<500)
            	{
            		c=1;
            		cout<<"Minimum Amount Deposit to open a Bank Account is 500. Enter Again\n";
            	}
            }while(c!=0);
            ob.total(type,x,1);
	}
	void showdata()
	{
		cout<<left<<setw(20)<<"Account Number";
		cout<<left<<setw(20)<<"Name";
		cout<<left<<setw(20)<<"Account type";
		cout<<left<<setw(20)<<"Balance";
		cout<<left<<setw(20)<<"Date of creation";
		cout<<left<<setw(20)<<"Interest generated";
		cout<<"\n"<<endl;
		cout<<left<<setw(20)<<acno;
		cout<<left<<setw(20)<<fname;
		cout<<left<<setw(20)<<type;
		cout<<left<<setw(20)<<balance;
		cout<<left<<setw(20)<<ch;
		cout<<left<<setw(20)<<interest;
		cout<<"\n"<<endl;
	}
	void showdata(int x)
	{	
		if(x==1)
		{
			cout<<left<<setw(20)<<"Account Number";
			cout<<left<<setw(20)<<"Name";
			cout<<left<<setw(20)<<"Account type";
			cout<<left<<setw(20)<<"Balance";
			cout<<"\n"<<endl;
		}
		cout<<left<<setw(20)<<acno;
		cout<<left<<setw(20)<<fname;
		cout<<left<<setw(20)<<type;
		cout<<left<<setw(20)<<balance;
		cout<<"\n"<<endl;
	}
public:
        void create_account(long long unsigned int acno,string ch)
        {
            fstream fp;
            cout<<"**Account Creation**\n";
            cout<<"Your Account Number is "<<acno<<endl;
            getdata(ch);
            interest="0";
            fp.open("GlocalBank.csv",ios::app);
            fp<<acno<<","<<fname<<" "<<lname<<","<<type<<","<<balance<<","<<ch<<","<<pin<<","<<interest<<endl;
            cout<<"Your account has been created\n";
            fp.close();
        }
         void displayall()
        {
            ifstream fp;
            fp.open("GlocalBank.csv");
			if(!fp)
			cout<<"Account does not exist\n";
			 else
			 {
			 		getline(fp,acno,',');
			 		getline(fp,fname,',');
			 		getline(fp,type,',');
			 		getline(fp,balance,',');
			 		getline(fp,ch,',');
			 		getline(fp,pin,',');
			 		getline(fp,interest,'\n');
			 		int x=1;
			 	while(fp.good())
			 	{
			 		showdata(x);
			 		x++;
				 	getline(fp,acno,',');
			 		getline(fp,fname,',');
			 		getline(fp,type,',');
			 		getline(fp,balance,',');
			 		getline(fp,ch,',');
			 		getline(fp,pin,',');
			 		getline(fp,interest,'\n');
				}
				fp.close();
			 }
        }
         void display()
        {
        	cout<<"Enter your acccount number ";
        	string acc;
        	cin>>acc;
            ifstream fp;
            fp.open("GlocalBank.csv");
			if(!fp)
			cout<<"Account does not exist\n";
			 else
			 {
			 	int counter=0;
			 		getline(fp,acno,',');
			 		getline(fp,fname,',');
			 		getline(fp,type,',');
			 		getline(fp,balance,',');
			 		getline(fp,ch,',');
			 		getline(fp,pin,',');
			 		getline(fp,interest,'\n');
			 	while(!fp.eof())
			 	{
			 		if(acc==acno)
			 		{
			 			showdata();
			 			counter=1;
					}
				 	getline(fp,acno,',');
			 		getline(fp,fname,',');
			 		getline(fp,type,',');
			 		getline(fp,balance,',');
			 		getline(fp,ch,',');
			 		getline(fp,pin,',');
			 		getline(fp,interest,'\n');
				}
				fp.close();
				if(counter==0)
				cout<<"Account does not Exist\n";
			 }
        }
        void deposit()
        {
        	string acc;
        	cout<<"Enter your account number ";
        	cin>>acc;
        	fstream fp;
        	fp.open("Glocalbank.csv",ios::in);
        	if(!fp)
        	cout<<"Account does not exist\n";
        	else
        	{
        		fstream fout;
        		fout.open("temp.csv",ios::out);
        		getline(fp,acno,',');
			 	getline(fp,fname,',');
			 	getline(fp,type,',');
			 	getline(fp,balance,',');
			 	getline(fp,ch,',');
			 	getline(fp,pin,',');
			 	getline(fp,interest,'\n');
			 	int counter=0;
			 	while(fp.good())
			 	{
			 		if(acc==acno)
			 		{
			 			admin adm;
			 			double bal,x;
        				cout<<"Enter the amount you want to deposit ";
        				cin>>bal;
        				adm.gettotal(bal,1);
			 			stringstream ss(balance);
			 			ss>>x;
			 			bal=bal+x;
			 			stringstream object;
			 			object<<bal;
			 			balance=object.str();
			 			fout<<acno<<","<<fname<<","<<type<<","<<balance<<","<<ch<<","<<pin<<","<<interest<<endl;
			 			cout<<"The balance has been deposited.\nNew Balance= "<<balance<<endl;
			 			counter=1;
			 		}
			 		else
			 			fout<<acno<<","<<fname<<","<<type<<","<<balance<<","<<ch<<","<<pin<<","<<interest<<endl;
					getline(fp,acno,',');
					getline(fp,fname,',');
					getline(fp,type,',');
					getline(fp,balance,',');
					getline(fp,ch,',');
					getline(fp,pin,',');
					getline(fp,interest,'\n');
				}
				fp.close();
				fout.close();
				remove("GlocalBank.csv");
				rename("temp.csv","GlocalBank.csv");
				if(counter==0)
				cout<<"Account does not exist\n";
			}
		}
		void withdraw()
		{
			string acc;
			int counter;
			cout<<"Enter account number ";
			cin>>acc;
			fstream fp;
			fp.open("GlocalBank.csv",ios::in);
			if(!fp)
			cout<<"Account does not exists\n";
			else
			{
				ofstream fout;
				fout.open("temp.csv");
				getline(fp,acno,',');
				getline(fp,fname,',');
				getline(fp,type,',');
				getline(fp,balance,',');
				getline(fp,ch,',');
				getline(fp,pin,',');
				getline(fp,interest,'\n');
				while(!fp.eof())
				{
					if(acc==acno)
					{
						counter=1;
						double bal,x;
						cout<<"Enter the amount you want to withdraw ";
						cin>>bal;
						stringstream ss(balance);
						ss>>x;
						if(bal>x)
						{
							fout<<acno<<","<<fname<<","<<type<<","<<balance<<","<<ch<<","<<pin<<","<<interest<<endl;
							cout<<"Transaction Failed!!!\nInfo: You do not have sufficient balance.\n";
						}
						else
						{
							
							admin adm;
							adm.gettotal(bal,2);
							x=x-bal;
							stringstream object;
							object<<x;
							balance=object.str();
							fout<<acno<<","<<fname<<","<<type<<","<<balance<<","<<ch<<","<<pin<<","<<interest<<endl;
							cout<<"Transaction successful!\nNew Balance= "<<balance<<endl;
						}
					}
					else
					{
						fout<<acno<<","<<fname<<","<<type<<","<<balance<<","<<ch<<","<<pin<<","<<interest<<endl;
					}
						getline(fp,acno,',');
						getline(fp,fname,',');
						getline(fp,type,',');
						getline(fp,balance,',');
						getline(fp,ch,',');
						getline(fp,pin,',');
						getline(fp,interest,'\n');
				}
				fp.close();
				fout.close();
				remove("GlocalBank.csv");
				rename("temp.csv","GlocalBank.csv");
				if(counter==0)
				cout<<"Account does not exist\n";	
			}
		}
		void withdraw(int y)
		{	
			string acc;
			int counter=0;
			string pi;
			cout<<"Enter account number ";
			cin>>acc;
			fstream fp;
			fp.open("GlocalBank.csv",ios::in);
			if(!fp)
			cout<<"Account does not exists\n";
			else
			{
				ofstream fout;
				fout.open("temp.csv");
				cout<<"Enter your Pin Number";
				cin>>pi;
				getline(fp,acno,',');
				getline(fp,fname,',');
				getline(fp,type,',');
				getline(fp,balance,',');
				getline(fp,ch,',');
				getline(fp,pin,',');
				getline(fp,interest,'\n');
				while(!fp.eof())
				{
					if(acc==acno)
					{
						counter=1;
						if(pin==pi)
						{
							double bal,x;
							cout<<"Enter the amount you want to withdraw ";
							cin>>bal;
							stringstream ss(balance);
							ss>>x;
						if(bal>x)
						{
							fout<<acno<<","<<fname<<","<<type<<","<<balance<<","<<ch<<","<<pin<<","<<interest<<endl;
							cout<<"Transaction Failed!!!\nInfo: You do not have sufficient balance.\n";
						}
						else
						{
							
							admin adm;
							adm.gettotal(bal,2);
							x=x-bal;
							stringstream object;
							object<<x;
							balance=object.str();
							fout<<acno<<","<<fname<<","<<type<<","<<balance<<","<<ch<<","<<pin<<","<<interest<<endl;
							cout<<"Transaction successful!!!\nNew Balance= "<<balance<<endl;
						}
						}
						else
						{
							fout<<acno<<","<<fname<<","<<type<<","<<balance<<","<<ch<<","<<pin<<","<<interest<<endl;
							cout<<"Access Denied!!!\nPin number did not match. Please try again!";
						}
					}
					else
					fout<<acno<<","<<fname<<","<<type<<","<<balance<<","<<ch<<","<<pin<<","<<interest<<endl;
						getline(fp,acno,',');
						getline(fp,fname,',');
						getline(fp,type,',');
						getline(fp,balance,',');
						getline(fp,ch,',');
						getline(fp,pin,',');
						getline(fp,interest,'\n');
				}
				fp.close();
				fout.close();
				remove("GlocalBank.csv");
				rename("temp.csv","GlocalBank.csv");
				if(counter==0)
				cout<<"Account does not exist\n";	
			}
		}
	void modify()
   		{
   			cout<<"Enter account number to modify ";
   			string acc;
   			cin>>acc;
   			ifstream fp;
   			fp.open("GlocalBank.csv");
   			if(!fp)
   			cout<<"Account does not exists\n";
   			else
   			{
   				ofstream fout;
   				fout.open("temp.csv");
   				int counter=0;
   				getline(fp,acno,',');
			 	getline(fp,fname,',');
			 	getline(fp,type,',');
			 	getline(fp,balance,',');
			 	getline(fp,ch,',');
			 	getline(fp,pin,',');
			 	getline(fp,interest,'\n');
			 	while(fp.good())
			 	{
			 		if(acc==acno)
			 		{
			 			admin obj;
			 			counter=1;
			 			showdata();
			 			cout<<"Enter new name\nFirst name:- ";
			 			cin>>fname;
			 			cout<<"Last name:- ";
			 			cin>>lname;
			 			cout<<"Enter account type (C/S) ";
			 			cin>>type;
			 			obj.total(type);
			 			fout<<acno<<","<<fname<<" "<<lname<<","<<type<<","<<balance<<","<<ch<<","<<pin<<","<<interest<<endl;
			 			cout<<"Account modified...\n";
					}
					else
						fout<<acno<<","<<fname<<","<<type<<","<<balance<<","<<ch<<","<<pin<<","<<interest<<endl;
					getline(fp,acno,',');
			 		getline(fp,fname,',');
			 		getline(fp,type,',');
			 		getline(fp,balance,',');
			 		getline(fp,ch,',');
			 		getline(fp,pin,',');
			 		getline(fp,interest,'\n');
				}
				fp.close();
				fout.close();
				remove("GlocalBank.csv");
				rename("temp.csv","GlocalBank.csv");
				if(counter==0)
				cout<<"Account does not exist\n";
			}
		}
		void modify(int y)
   		{
   			string pi,p;
   			cout<<"Enter account number to modify ";
   			string acc;
   			cin>>acc;
   			ifstream fp;
   			fp.open("GlocalBank.csv");
   			if(!fp)
   			cout<<"Account does not exists\n";
   			else
   			{
   				ofstream fout;
   				fout.open("temp.csv");
   				cout<<"Enter your Pin Number";
   				cin>>pi;
   				int counter=0;
   				getline(fp,acno,',');
			 	getline(fp,fname,',');
			 	getline(fp,type,',');
			 	getline(fp,balance,',');
			 	getline(fp,ch,',');
			 	getline(fp,pin,',');
			 	getline(fp,interest,'\n');
			 	while(fp.good())
			 	{
			 		if(acc==acno)
			 		{
			 		counter=1;
			 			if(pi==pin)
			 			{
			 				admin obj;
			 				showdata();
			 				cout<<"Enter New Pin Number ";
			 				cin>>p;
			 				cout<<"Enter New Pin number again ";
			 				cin>>pi;
			 				if(p==pi)
			 				{
			 					fout<<acno<<","<<fname<<","<<type<<","<<balance<<","<<ch<<","<<pi<<","<<interest<<endl;
			 					cout<<"Pin Number changed...\n";
							}
			 				else
			 				{
			 					fout<<acno<<","<<fname<<","<<type<<","<<balance<<","<<ch<<","<<pin<<","<<interest<<endl;
							}
						}
						else
						{
							cout<<"Pin number did not match\n";
							fout<<acno<<","<<fname<<","<<type<<","<<balance<<","<<ch<<","<<pin<<","<<interest<<endl;
						}
					}
					else
					{
						fout<<acno<<","<<fname<<","<<type<<","<<balance<<","<<ch<<","<<pin<<","<<interest<<endl;
					}
					getline(fp,acno,',');
			 		getline(fp,fname,',');
			 		getline(fp,type,',');
			 		getline(fp,balance,',');
			 		getline(fp,ch,',');
			 		getline(fp,pin,',');
			 		getline(fp,interest,'\n');
				}
				fp.close();
				fout.close();
				remove("GlocalBank.csv");
				rename("temp.csv","GlocalBank.csv");
				if(counter==0)
				cout<<"Account does not exist\n";
			}
		}
        void close()
        {
        	cout<<"Enter your acccount number ";
        	string acc;
        	cin>>acc;
            ifstream fp;
            fp.open("GlocalBank.csv");
			if(!fp)
			cout<<"Account does not exist\n";
			 else
			 {
			 	int counter=0;
			 	ofstream fout;
            	fout.open("temp.csv");
			 		getline(fp,acno,',');
			 		getline(fp,fname,',');
			 		getline(fp,type,',');
			 		getline(fp,balance,',');
			 		getline(fp,ch,',');
			 		getline(fp,pin,',');
			 		getline(fp,interest,'\n');
			 	while(fp.good())
			 	{		
			 		if(acc==acno)
			 		{
			 			counter=1;
			 			char ch;
			 			cout<<"Ensure you withdraw your balance before closing your account!!!\n";
			 			cout<<"Are you sure you want to close your account(y/n) ";
			 			cin>>ch;
			 			if(ch=='y')
			 			{
			 				admin ob;
			 			double bal,x=0;
            			stringstream ss(balance);
            			ss>>x;
            			ob.total(type,x,2);
			 			cout<<"Account has been DELETED!\n";
						 }
			 			else
			 			fout<<acno<<","<<fname<<","<<type<<","<<balance<<","<<ch<<","<<pin<<","<<interest<<endl;
					}
					else
					{
							fout<<acno<<","<<fname<<","<<type<<","<<balance<<","<<ch<<","<<pin<<","<<interest<<endl;
					}
					getline(fp,acno,',');
			 		getline(fp,fname,',');
			 		getline(fp,type,',');
			 		getline(fp,balance,',');
			 		getline(fp,ch,',');
			 		getline(fp,pin,',');
			 		getline(fp,interest,'\n');
				}
				fp.close();
				fout.close();
				if(counter==0)
				cout<<"Account does not exist\n";
				remove("GlocalBank.csv");
				rename("temp.csv","GlocalBank.csv");
        }
    }
    void transfer()
    {
    	string acc,ac;
    	double bal,x;
    	cout<<"Enter your account number ";
    	cin>>acc;
    	cout<<"Enter amount you want to transfer ";
    	cin>>bal;
    	cout<<"Enter receiver's account number ";
    	cin>>ac;
    	fstream fp;
    	fp.open("GlocalBank.csv",ios::in);
    	if(!fp)
    	cout<<"Account does not exist\n";
    	else
    	{
    		int counter=0,i=0,n=0;
    		getline(fp,acno,',');
			getline(fp,fname,',');
			getline(fp,type,',');
			getline(fp,balance,',');
			getline(fp,ch,',');
			getline(fp,pin,',');
			getline(fp,interest,'\n');
			while(fp.good())
			{
				if(acno==acc)
				{
					stringstream ss(balance);
					ss>>x;
					counter=1;
					if(x>=bal)
					i=1;
					else
					cout<<"Access Denied! Info: Insufficient Balance\n";
				}
				if(acno==ac)
				n=1;
				getline(fp,acno,',');
				getline(fp,fname,',');
				getline(fp,type,',');
				getline(fp,balance,',');
				getline(fp,ch,',');
				getline(fp,pin,',');
				getline(fp,interest,'\n');
			}
			fp.close();
			if(i==1&&n==1)
			{
				ifstream fp;
				ofstream fout;
				fout.open("temp.csv");
				fp.open("GlocalBank.csv");
				getline(fp,acno,',');
				getline(fp,fname,',');
				getline(fp,type,',');
				getline(fp,balance,',');
				getline(fp,ch,',');
				getline(fp,pin,',');
				getline(fp,interest,'\n');
				while(fp.good())
				{
					if(acno==acc)
					{
						x=x-bal;
						stringstream obj;
						obj<<x;
						balance=obj.str();
						fout<<acno<<","<<fname<<","<<type<<","<<balance<<","<<ch<<","<<pin<<","<<interest<<endl;
					}
					else if(acno==ac)
					{
						double y;
						stringstream obj(balance);
						obj>>y;
						y=y+bal;
						stringstream object;
						object<<y;
						balance=object.str();
						fout<<acno<<","<<fname<<","<<type<<","<<balance<<","<<ch<<","<<pin<<","<<interest<<endl;
						cout<<"Transaction Succcessful!!!\n";
					}
					else
					fout<<acno<<","<<fname<<","<<type<<","<<balance<<","<<ch<<","<<pin<<endl;
					getline(fp,acno,',');
					getline(fp,fname,',');
					getline(fp,type,',');
					getline(fp,balance,',');
					getline(fp,ch,',');
					getline(fp,pin,',');
					getline(fp,interest,'\n');
				}
				fp.close();
				fout.close();
				remove("GlocalBank.csv");
				rename("temp.csv","GlocalBank.csv");
			}
			else if(counter==0||n==0)
			cout<<"Account does not exist\n";
		}
	}
	void transfer(int y)
    {
    	string acc,ac,pi;
    	double bal,x;
    	cout<<"Enter your account number ";
    	cin>>acc;
    	cout<<"Enter your Pin Number";
    	cin>>pi;
    	cout<<"Enter amount you want to transfer ";
    	cin>>bal;
    	cout<<"Enter the reciver's account number ";
    	cin>>ac;
    	fstream fp;
    	fp.open("GlocalBank.csv",ios::in);
    	if(!fp)
    	cout<<"Account does not exist\n";
    	else
    	{
    		int counter=0,i=0,n=0;
    		getline(fp,acno,',');
			getline(fp,fname,',');
			getline(fp,type,',');
			getline(fp,balance,',');
			getline(fp,ch,',');
			getline(fp,pin,',');
			getline(fp,interest,'\n');
			while(fp.good())
			{
				if(acno==acc)
				{
					counter=1;
					if(pin==pi)
					{		
						stringstream ss(balance);
						ss>>x;
						if(x>=bal)
						i=1;
						else
							cout<<"Transaction Failed! Info: Insufficient Balance\n";
					}
					else
					{
						cout<<"Pin Number does not match!!! Please try again!\n";
						break;
					}
				}
				if(acno==ac)
				n=1;
				getline(fp,acno,',');
				getline(fp,fname,',');
				getline(fp,type,',');
				getline(fp,balance,',');
				getline(fp,ch,',');
				getline(fp,pin,',');
				getline(fp,interest,'\n');
			}
			fp.close();
			if(i==1&&n==1)
			{
				ifstream fp;
				ofstream fout;
				fout.open("temp.csv");
				fp.open("GlocalBank.csv");
				getline(fp,acno,',');
				getline(fp,fname,',');
				getline(fp,type,',');
				getline(fp,balance,',');
				getline(fp,ch,',');
				getline(fp,pin,',');
				getline(fp,interest,'\n');
				while(fp.good())
				{
					if(acno==acc)
					{
						x=x-bal;
						stringstream obj;
						obj<<x;
						balance=obj.str();
						fout<<acno<<","<<fname<<","<<type<<","<<balance<<","<<ch<<","<<pin<<","<<interest<<endl;
					}
					else if(acno==ac)
					{
						double y;
						stringstream obj(balance);
						obj>>y;
						y=y+bal;
						stringstream object;
						object<<y;
						balance=object.str();
						fout<<acno<<","<<fname<<","<<type<<","<<balance<<","<<ch<<","<<pin<<","<<interest<<endl;
						cout<<"Transaction Succcessful!!!\n";
					}
					else
					fout<<acno<<","<<fname<<","<<type<<","<<balance<<","<<ch<<","<<pin<<","<<interest<<endl;
					getline(fp,acno,',');
					getline(fp,fname,',');
					getline(fp,type,',');
					getline(fp,balance,',');
					getline(fp,ch,',');
					getline(fp,pin,',');
					getline(fp,interest,'\n');
				}
				fp.close();
				fout.close();
				remove("GlocalBank.csv");
				rename("temp.csv","GlocalBank.csv");
			}
			else if(counter==0||n==0)
			cout<<"Account does not exist\n";
		}
	}
	void calinterest()
	{
		 int x;
		 time_t now;
		 time(&now);
		 struct tm *mytime=localtime(&now);
		 fstream ft;
		 ft.open("time.txt",ios::in);
		 if(!ft)
		 {
		 	ifstream obj;
		 	obj.open("GlocalBank.csv");
		 	if(!obj)
		 	{
		 		cout<<"No Accounts Created!!!";
		 		return;
			}
		 	ft.open("time.txt",ios::out);
		 	ft<<mytime->tm_mday<<endl;
		 	ft.close();
		 	goto label;
		 }
		 else
		 {
		 	ft>>x;
		 	if(x==mytime->tm_mday)
		 	{
		 		cout<<"Access Denied!!!\nInfo: Previously updated interest for today i.e. "<<mytime->tm_mday<<endl;
		 		ft.close();
			 }
		 	else
		 	{
		 		
		 		ft.close();
		 		label:
		 		ofstream ft;
		 		ft.open("time.txt");
		 		ft<<mytime->tm_mday<<endl;
		 		ft.close();
		 			ifstream fp;
		 			fp.open("GlocalBank.csv");
		 			if(!fp)
		 			cout<<"No Accounts\n";
		 			else
		 			{
		 				ofstream fout;
		 				fout.open("temp.csv");
		 				getline(fp,acno,',');
		 				getline(fp,fname,',');
		 				getline(fp,type,',');
		 				getline(fp,balance,',');
		 				getline(fp,ch,',');
		 				getline(fp,pin,',');
		 				getline(fp,interest,'\n');
		 				while(fp.good())
		 				{
		 					if(type=="s")
		 					{
		 						showdata();
		 						double bal,in,y;
		 						stringstream ss(balance);
		 						stringstream obj(interest);
		 						ss>>bal;
		 						obj>>in;
		 						cout<<"Old Interest is "<<in<<" Balance is "<<bal<<endl;
		 						y=(bal*0.002739*4)/100.0;
		 						in=in+y;
		 						cout<<"New Interest is "<<in<<endl;
		 						stringstream object;
		 						object<<in;
		 						interest=object.str();
		 						fout<<acno<<","<<fname<<","<<type<<","<<balance<<","<<ch<<","<<pin<<","<<interest<<endl;
							}
							else
							fout<<acno<<","<<fname<<","<<type<<","<<balance<<","<<ch<<","<<pin<<","<<interest<<endl;
							getline(fp,acno,',');
		 					getline(fp,fname,',');
			 				getline(fp,type,',');
			 				getline(fp,balance,',');
		 					getline(fp,ch,',');
		 					getline(fp,pin,',');
		 					getline(fp,interest,'\n');
						}
						fp.close();
						fout.close();
						remove("GlocalBank.csv");
						rename("temp.csv","GlocalBank.csv");
					}	
			}
		 }
	}
	void creditinterest()
	{
		int x;
		 time_t now;
		 time(&now);
		 struct tm *mytime=localtime(&now);
		 fstream ft;
		 ft.open("creditdate.txt",ios::in);
		 if(!ft)
		 {
		 	ifstream obj;
		 	obj.open("GlocalBank.csv");
		 	if(!obj)
		 	{
		 		cout<<"No Accounts Created!!!";
		 		return;
			}
		 	ft.open("creditdate.txt",ios::out);
		 	ft<<mytime->tm_mon<<endl;
		 	ft.close();
		 	goto label;
		 }
		 else
		 {
		 	ft>>x;
		 	if(x==mytime->tm_mon)
		 	{
		 		cout<<"Access Denied!!!\nInfo: Previously crediated interest for this month i.e. "<<mytime->tm_mon<<endl;
		 		ft.close();
		 		return;
			}
			else if(mytime->tm_mon!=2||mytime->tm_mon!=5||mytime->tm_mon!=8||mytime->tm_mon!=11)
			{
				cout<<"Interest can only be crediated on last working days of March, June, September, December\n";
				ft.close();
				return;
			}
		 	ft.close();
		 	label:
		 		ifstream fp;
		 		ofstream fout;
		 				fp.open("GlocalBank.csv");
		 				fout.open("temp.csv");
		 				getline(fp,acno,',');
		 				getline(fp,fname,',');
		 				getline(fp,type,',');
		 				getline(fp,balance,',');
		 				getline(fp,ch,',');
		 				getline(fp,pin,',');
		 				getline(fp,interest,'\n');
		 				while(fp.good())
		 				{
		 					if(type=="s")
		 					{
		 						showdata();
		 						double bal,in,y;
		 						stringstream ss(balance);
		 						stringstream obj(interest);
		 						ss>>bal;
		 						obj>>in;
		 						bal=(double)bal+in;
		 						interest="0.0";
		 						cout<<"New balance "<<bal<<" New Interest is "<<interest<<endl;
		 						stringstream object;
		 						object<<bal;
		 						balance=object.str();
		 						fout<<acno<<","<<fname<<","<<type<<","<<balance<<","<<ch<<","<<pin<<","<<interest<<endl;
							}
							else
							fout<<acno<<","<<fname<<","<<type<<","<<balance<<","<<ch<<","<<pin<<","<<interest<<endl;
							getline(fp,acno,',');
		 					getline(fp,fname,',');
			 				getline(fp,type,',');
			 				getline(fp,balance,',');
		 					getline(fp,ch,',');
		 					getline(fp,pin,',');
		 					getline(fp,interest,'\n');
						}
						fp.close();
						fout.close();
						remove("GlocalBank.csv");
						rename("temp.csv","GlocalBank.csv");
		 }
	}
};
int main()
{
	bank ob;
    admin adm;
    int ph,a,y,z,c=0,i=1,f=200;
    string ch;
    time_t now;
	time(&now);
	stringstream obj;
	struct tm *mytime=localtime(&now);
	obj<<mytime->tm_mday<<"  "<<mytime->tm_mon<<"  "<<mytime->tm_year;
	ch=obj.str();
	system("color 70");
		for(int i=0; i<=100; i++)
    	{	
    	SetCursor(40,10);
    	cout<<"Please Wait!\t";
   		cout<<"Loading... ";
    	cout<<i<<"%";
    	Sleep(1);
    	system("cls");
    	}
    	SetCursor(40,5);
		cout<<"**********************************"<<endl;
    	SetCursor(45,7);
		cout<<"WELCOME TO INDO-NEPAL BANK"<<endl;
    	SetCursor(40,9);
		cout<<"**********************************"<<endl<<endl<<endl;
    	SetCursor(55,11);
    	while(f!=500)
    	{
    		Beep(f,1000);
    		f=f+100;
    	}
    	system("cls");
    do{	
    	SetCursor(40,2);
    	cout<<"Enter Your choice:";
    	SetCursor(40,4);
    	Sleep(100);
    	cout<<"1.User Interface";
    	Sleep(100);
    	SetCursor(40,6);
    	cout<<"2.Employee Interface";
    	Sleep(100);
    	SetCursor(40,8);
    	cout<<"0.Exit";
    	SetCursor(45,10);
    	cin>>a;
    	switch(a)
    	{
    		case 1:
    			y=0;
    		do{
    			system("cls");
    			SetCursor(40,2);
    			cout<<"Enter Your choice:";
    			SetCursor(40,4);
    			Sleep(100);
    			cout<<"1.Press 1 to Withdrawl Money";
    			SetCursor(40,6);
    			Sleep(100);
    			cout<<"2.Press 2 to Transfer Money";
    			SetCursor(40,8);
    			Sleep(100);
    			cout<<"3.Press 3 to Change your account Pin Number";
    			SetCursor(40,10);
    			Sleep(100);
    			cout<<"4.Press 4 to Display Account Info";
    			SetCursor(40,12);
    			cout<<"0.Press 0 to Exit";
    			SetCursor(45,14);
    			cin>>z;
    			switch(z)
    			{
    				case 1:	
    					ob.withdraw(1);
						break;	
					case 2:
						ob.transfer(1);
						break;
					case 3:
						ob.modify(1);
						break;
					case 4:
						ob.display();
						break;
					case 0:
						break;
					default:
						cout<<"\nWrong choice!";
						break;
				}
				if(z!=0)
				{	
				cout<<"Strike any key to continue\n";
				getch();
				}
			}while(z!=0);
			break;
    		case 2:
    	do{
    		system("cls");
    		SetCursor(40,2);
    		cout<<"You are on the Employee Interface";
    		SetCursor(40,4);
    		Sleep(100);
    		cout<<"Enter Your choice:";	
			SetCursor(40,6);
    		Sleep(100);
			cout<<"1.Go to administrative part";
			SetCursor(40,8);
    		Sleep(100);
			cout<<"2.Continue Banking System";
			SetCursor(40,10);
    		Sleep(100);
			cout<<"0.Exit";
			SetCursor(45,12);
    	cin>>y;
    	account acc;
    switch(y)
    {
    	case 1:
    		acc.setaccount();
    		cout<<"Strike any key to continue\n";
    		getch();
    		break;
    	case 2:
    		i=1;
    		do
    		{
       			long long unsigned int acno;
    			system("cls");
    			if(i==1)
    			{
    				c=acc.check();
    				i++;
				}
    			if(c==1)
    			{
					system("color 2F");
					SetCursor(40,2);
    				cout<<"Enter your choice\n";
    				SetCursor(40,4);
    				Sleep(100);
    				cout<<"Press 1 to create a account\n";
  					SetCursor(40,6);
    				Sleep(100);
					cout<<"Press 2 to deposit money\n";
					SetCursor(40,8);
    				Sleep(100);
    				cout<<"Press 3 to withdraw money\n";
				    SetCursor(40,10);
    				Sleep(100);
    				cout<<"Press 4 to display your account info\n";
    				SetCursor(40,12);
	    			Sleep(100);
    				cout<<"Press 5 to Transfer Money\n";
    				SetCursor(40,14);
    				Sleep(100);
    				cout<<"Press 6 to Modify Account\n";
	    			SetCursor(40,16);
    				Sleep(100);
   		 			cout<<"Press 7 to display all accounts info\n";
    				SetCursor(40,18);
    				Sleep(100);
    				cout<<"Press 8 for accounts Analysis\n";
    				SetCursor(40,20);
    				Sleep(100);
					cout<<"Press 9 to close an account\n";
					SetCursor(40,22);
					cout<<"Press 10 for interest calculation\n";
					SetCursor(40,24);
					cout<<"Press 11 to credit interest to all accounts\n";
					SetCursor(40,26);
					Sleep(100);
					cout<<"Press 0 to Back To Main Menu\n";
					SetCursor(45,28);
				    cin>>ph;
				    system("cls");
    	switch(ph)
   			{
    		case 1:
    			acno=acc.getaccount();
            	ob.create_account(acno,ch);
            	break;
    		case 2:
            	ob.deposit();
            	break;
    		case 3:
    			ob.withdraw();
            	break;
			case 4:
            	ob.display();
            	break;
			case 5:
				ob.transfer();
				break;	
    		case 6:
    			ob.modify();
    			break;
    		case 7:
            	ob.displayall();
            	break;
    		case 8:
    			adm.showtotal();
            	break;
    		case 9:
    			ob.close();
    			break;
			case 10:
				  ob.calinterest();
				  break;
			case 11:
				  ob.creditinterest();   
				  break;   
    		case 0:
    			break;
    		default:
            	cout<<"Wrong input\n";
            	break;
			}
				if(ph!=0)
				{
					cout<<"Strike any key to continue\n";
    				getch();
				}
    		}
			}while(ph!=0);
			break;
    	case 0:
    		break;
    	default:
    		cout<<"Wrong choice\n";
    		break;
	}
	if(ph==0)
	break;
}while(y!=0);
		case 0:
			break;
		default:
			cout<<"Wrong Choice! Enter Again!\n";
			break;
}
if(y==1 || y==0 || ph==0)
system("cls");
}while(a!=0);
cout<<"THANK YOU for using our application !!!\n";
}
