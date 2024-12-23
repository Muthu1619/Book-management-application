#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<sstream>
using namespace std;
ifstream fin;
ofstream fout;
class bookshop{
	string bookname,bookid,author,sellername,sellerid;
	int stock;
	float price;
	public:
	void menu(string id,string pass){
		do{
		system("CLS");
		cout<<"*** Note: ***\nDon't use backspace here instead use _ underscore.\n ";
		int ch;
        cout<<"\n\n\t\t\t|~~~~~~~~~Menu~~~~~~~~~~~~~~|";
        cout<<"\n\t\t\t| (1) Buy Book              |";
        cout<<"\n\t\t\t| (2) Add Book              |";
        cout<<"\n\t\t\t| (3) Delete Book           |";
        cout<<"\n\t\t\t| (4) Show All Book List    |";
        cout<<"\n\t\t\t| (5) Show Balance          |";
        cout<<"\n\t\t\t| (6) Show My Sold List     |";
        cout<<"\n\t\t\t| (7) Recharge wallet       |";
        cout<<"\n\t\t\t| (8) Logout                |";
        cout<<"\n\t\t\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~|";
        try{
        	cout<<"\n Enter the choice:";
        	cin>>ch;
        	if(ch==1){
        		buy(id,pass);
			}
        	else if(ch==2){
        		add(id,pass);
			}
			else if(ch==3){
				delet(id,pass);
			}
			else if(ch==4){
				showa();
			}
			else if(ch==5){
				showb(id,pass);
			}
			else if(ch==6){
				shows(id,pass);
			}
			else if(ch==7){
				recharge(id,pass);
			}
			else{
				throw 1;
			}
		}catch(int x){
			cout<<"\n*** Invalid input ***\n";
			break;
		}}while(1);
	}
	bool check(string id,string pass){
		string id1,id2;
        string name1,pass1,pass2;
        float b;
        id1=id;
        pass1=pass;
        try{
        fin.open("user.txt");
        	if(!fin){
        		throw 1;
			}
			else{
				while(fin>>id2>>name1>>pass2>>b){
					if(id1==id2&&pass1==pass2){
						fin.close();
						sellername=name1;
						sellerid=id2;
						return true;
					}
				}
				fin.close();
				return false;
			}
		}catch(int x){
			return false;
		}
	}
	void add(string id,string pass){
		int s,s1;
		float p,p1;
		string bn,bi,a,bn1,bi1,a1,sname,sid;
		bool z=check(id,pass);
		if(z){
		cout<<"\nEnter book name:";
		cin>>bn;
		try{
		cout<<"\nEnter book id:";
		cin>>bi;
		try{
		fin.open("books.txt");
		if(!fin){
			throw 1;
		}
		else{
			while(fin>>bn1>>bi1>>a1>>s1>>p1>>sname>>sid){
				if((bn==bn1&&bi==bi1)||bi==bi1){
					fin.close();
					throw 1;
				}
			}
		}
		fin.close();}catch(int x){
			cout<<"\n*** File not found ***\n";
			system("pause");
			return;
		}
		}
		catch(int x){
			cout<<"\n*** Id already registered ***\n";
			system("pause");
			return;
		}
		cout<<"\nEnter author name:";
		cin>>a;
		cout<<"\nEnter the stock available:";
		cin>>s;
		cout<<"\nEnter the price of one book:";
		cin>>p;
		try{
		fout.open("books.txt",ios::app);
		if(!fout){
			throw 1;
		}
		else{
			fout<<bn<<"\t"<<bi<<"\t"<<a<<"\t"<<s<<"\t"<<p<<"\t"<<sellername<<"\t"<<sellerid<<"\n";
			fout<<endl;
			fout.close();
			cout<<"\n***Book added successfully***\n";
			system("pause");
			return;
		}
		}catch(int x){
			cout<<"\n*** File not found ***\n";
			system("pause");
			return;
		}}
		else{
			cout<<"\n*** User not found ***\n\n";
			system("pause");
			return;
		}
	}
	void showa(){
		string name,id,author;
	    int stock;
	    float price;
	    string sname,sid;
		system("cls");
    cout<<"|~~~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~|~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout<<"|Id         | Book Name             | Author Name          | Copy      | Price  | Seller name\n";
    cout<<"|~~~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~|~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~|\n";
    try{
    	fin.open("books.txt");
    	if(!fin){
    		throw 1;
		}
		else{
			while(fin>>name>>id>>author>>stock>>price>>sname>>sid){
				cout<<" "<<id<<"\t\t"<<name<<"\t\t\t"<<author<<"\t\t    "<<stock<<"\t\t"<<price<<"\t  "<<sname<<"\n";
			}
			cout<<"|~~~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~|~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~|\n";
			fin.close();
			system("pause");
			return;
		}
	}catch(int x){
		cout<<"\n*** File not found ***\n";
		system("pause");
		return;
	}
    
	}
	void showb(string id,string pass){
		string id1,name,pass1;
		float b;
		int z=check(id,pass);
		if(z){
			try{
				fin.open("user.txt");
				if(!fin){
					throw 1;
				}
				else{
					while(fin>>id1>>name>>pass1>>b){
						if(id1==id&&pass1==pass){
							cout<<"Mr. "<<name<<" ,Your balance: "<<b<<"\n\n";
							fin.close();
							system("pause");
							return;
						}
					}
				}
			}
			catch(int x){
				cout<<"\n*** File not found ***\n\n";
				system("pause");
				return;
			}
		}
		else{
			cout<<"\n*** User not found ***\n\n";
			system("pause");
			return;
		}
	}
	bool  findb(string bn,string bi,string id){
		try{
        fin.open("books.txt");
        string bna,bid,a,sn,sid;
        int s;
        float p;
        	if(!fin){
        		throw 1;
			}
			else{
				while(fin>>bna>>bid>>a>>s>>p>>sn>>sid){
					if(bna==bn&&bid==bi&&sid==id){
						fin.close();
						return true;
					}
				}
				fin.close();
				return false;
			}
		}catch(int x){
			return false;
		}
	}
	bool  findb1(string bn,string bi){
		try{
        fin.open("books.txt");
        string bna,bid,a,sn,sid;
        int s;
        float p;
        	if(!fin){
        		throw 1;
			}
			else{
				while(fin>>bna>>bid>>a>>s>>p>>sn>>sid){
					if(bna==bn&&bid==bi){
						fin.close();
						return true;
					}
				}
				fin.close();
				return false;
			}
		}catch(int x){
			return false;
		}
	}
	void delet(string id,string pass){
		string bn,bid,bn1,bid1,a,sn,si;
		int s;
		float p;
		cout<<"\nEnter the book name:";
		cin>>bn;
		cout<<"\nEnter the book id:";
		cin>>bid;
		if(check(id,pass)){
			if(findb(bn,bid,id)){
				try{
					fin.open("books.txt");
					fout.open("temp.txt",ios::app);
					if(!fin||!fout){
						throw 1;
					}
					else{
						while(fin>>bn1>>bid1>>a>>s>>p>>sn>>si){
							if(bn1==bn&&bid1==bid){
								continue;
							}
							fout<<bn1<<"\t"<<bid1<<"\t"<<a<<"\t"<<s<<"\t"<<p<<"\t"<<sn<<"\t"<<si<<"\n";
						}
					fin.close();
					fout.close();
					remove("books.txt");
                    rename("temp.txt","books.txt");	
                    cout<<"\n ***Book deleted successfully*** \n";
                    system("pause");
                    return;
					}
				}
				catch(int x){
					cout<<"\n*** Error in files ***\n";
					system("pause");
					return;
				}
			}
			else{
				cout<<"\n ***Book not found*** \n";
				system("pause");
				return;
			}
		}
		else{
			cout<<"\n*** User not found *** \n";
			system("pause");
			return;
		}
	}
	void buy(string id,string pass){
		string bn,bid,bid1,bn1,a,sn,sid,eid,en,ep,buid;
		float p,amnt,b;
		ifstream fin1;
		ofstream fout1;
		int s;
		int c;
		cout<<"\nEnter the book name:";
		cin>>bn;
		cout<<"\nEnter the book id:";
		cin>>bid;
		cout<<"\nEnter the number of copies:";
		cin>>c;
		if(check(id,pass)){
			if(findb1(bn,bid)){
				try{
					fin.open("books.txt");
					fin1.open("user.txt");
					if(!fin||!fin1){
						throw 1;
					}
					else{
						while(fin>>bn1>>bid1>>a>>s>>p>>sn>>sid){
							if(bid1==bid&&bn==bn1){
								if(c>s){
									cout<<"\n ***Only "<<s<<" copies are available.*** \n";
									fin.close();
									system("pause");
									return;
								}
								else{
									amnt=c*p;
								}
							}
						}
						while(fin1>>eid>>en>>ep>>b){
							if(eid==id&&ep==pass){
								if(amnt>b){
									cout<<"\n ***You have only Rs. "<<b<<" balance.***\n";
									system("pause");
									return;
								}
						}}
						fin.close();
						fin1.close();
						fin.open("books.txt");
						fout.open("temp.txt",ios::app);
						fout1.open("sold.txt",ios::app);
						while(fin>>bn1>>bid1>>a>>s>>p>>sn>>sid){
							if(bid1==bid&&bn==bn1){
								buid=sid;
								s=s-c;
								fout<<bn1<<"\t"<<bid1<<"\t"<<a<<"\t"<<s<<"\t"<<p<<"\t"<<sn<<"\t"<<sid<<"\n";
								fout1<<bn1<<"\t"<<bid1<<"\t"<<a<<"\t"<<c<<"\t"<<p<<"\t"<<sn<<"\t"<<sid<<"\n";
							}
							else{
							fout<<bn1<<"\t"<<bid1<<"\t"<<a<<"\t"<<s<<"\t"<<p<<"\t"<<sn<<"\t"<<sid<<"\n";}
						}
						fin.close();
						fout.close();
						fout1.close();
						remove("books.txt");
						rename("temp.txt","books.txt");
						fin.open("user.txt");
						fout.open("temp.txt",ios::app);
						while(fin>>eid>>en>>ep>>b){
							if(eid==id&&ep==pass){
								b=b-amnt;
								fout<<eid<<"\t"<<en<<"\t"<<ep<<"\t"<<b<<"\n";
						}
						else if(buid==eid){
							b=b+amnt;
							fout<<eid<<"\t"<<en<<"\t"<<ep<<"\t"<<b<<"\n";
						}
						else{
							fout<<eid<<"\t"<<en<<"\t"<<ep<<"\t"<<b<<"\n";
						}
						}
						fin.close();
						fout.close();
						remove("user.txt");
						rename("temp.txt","user.txt");
						cout<<"\n *** Book bought sucessfully *** \n";
						system("pause");
				}}
				catch(int x){
					fin.close();
					fin1.close();
					cout<<"\n*** Error in files ***\n";
					system("pause");
					return;
				}}
			
			else{
				cout<<"\n ***Book not found*** \n";
				system("pause");
				return;
			}
		}
		else{
			cout<<"\n*** User not found *** \n";
			system("pause");
			return;
			
		}
	}
	void shows(string id,string pass){
		string n1,bid1,a,sn,sid;
		float p;
		int s;
		system("cls");
    cout<<"|~~~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~|~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout<<"|Id         | Book Name             | Author Name          | Copy      | Price  | Seller name\n";
    cout<<"|~~~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~|~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~|\n";
		if(check(id,pass)){
			try{
				fin.open("sold.txt");
				if(!fin){
					throw 1;
				}
				else{
					while(fin>>n1>>bid1>>a>>s>>p>>sn>>sid){
						if(id==bid1){
						cout<<" "<<bid1<<"\t\t"<<n1<<"\t\t\t"<<a<<"\t\t    "<<s<<"\t\t"<<p<<"\t  "<<sn<<"\n";
					}}
				}
			
			fin.close();
			cout<<"|~~~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~|~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~|\n";
			system("pause");
			return;}
			catch(int x){
				    cout<<"\n*** Error in files ***\n";
					system("pause");
					return;
			}
		}
	}
	void recharge(string id,string pass){
		string eid,en,ep;
		float amnt,b;
		cout<<"\nEnter the recharge amount:";
		cin>>amnt;
		if(check(id,pass)){
			try{
			fin.open("user.txt");
			fout.open("temp.txt",ios::app);
			if(!fin||!fout){
				throw 1;
			}
			else{
				while(fin>>eid>>en>>ep>>b){
							if(eid==id&&ep==pass){
								b=b+amnt;
								fout<<eid<<"\t"<<en<<"\t"<<ep<<"\t"<<b<<"\n";
						}
			}
			
		}
		fin.close();
		fout.close();
		remove("user.txt");
		rename("temp.txt","user.txt");
		cout<<"\n*** Recharged  sucessfully ***\n";
		system("pause");
		return;
		}
		catch(int x){
			fin.close();
			fout.close();
			cout<<"\n*** Error in files ***\n";
			system("pause");
			return;
		}
		}
		else{
			cout<<"\n*** User not found *** \n";
			system("pause");
			return;
		}
	}
};
class Employee:public bookshop{
	string id;
	string name,pass;
	float balance;
	public:
	Employee(){
		int ch;
		do{
			system("CLS");
			cout<<"\n\n\t\t\t|~~~~~~~~~Menu~~~~~~~~~~~~~~~~|";
            cout<<"\n\t\t\t| (1) Sign In                 |";
            cout<<"\n\t\t\t| (2) Sign Up                 |";
            cout<<"\n\t\t\t| (3) Forgot Id/Password      |";
            cout<<"\n\t\t\t| (4) Exit                    |";
            cout<<"\n\t\t\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|";
            try{
            cout<<"\n\nEnter Your choice : ";
            cin>>ch;
            if(ch==1){
			    signin();
			}
            else if(ch==2){
            	signup();
			}
			else if(ch==3){
				forgot();
			}
            else{
            	throw ch;
			}}
			catch(int ch){
				cout<<"\n\n***Invalid Input***\n\n";
				system("pause");
				continue;
			}}while(1);}
	void signin(){
		string id1,id2;
        string name1,pass1,pass2;
        
		float b;
        cout<<"\nEnter the id:";
        cin>>id1;
        cout<<"\nEnter the password:";
        cin>>pass1;
        try{
        fin.open("user.txt");
        	if(!fin){
        		throw 1;
			}
			else{
				while(fin>>id2>>name1>>pass2>>b){
					if(id1==id2&&pass1==pass2){
						cout<<"\n*** Welcome,  Mr "+name1+" you have logged in successfull ***\n";
						system("pause");
						fin.close();
						menu(id1,pass1);
						return;
					}
				}
				fin.close();
				cout<<"\n*** Id or password does not match try again ***\n";
				system("pause");
				return;
	}
		}catch(int x){
			cout<<"\n*** File not found ***\n";
			system("pause");
			return;
		}
	}
	void signup(){
		
		string name1;
		string pass1,id;
		float b=500,b1;
		try{
		cout<<"\nEnter the username:";
		cin>>name;
		try{
		fin.open("user.txt");
		if(!fin){
			throw 1;
		}
		else{
			while(fin>>id>>name1>>pass1>>b1){
				if(name1==name){
					fin.close();
					throw 1;
				}
			}
        }
        fin.close();
		}catch(int x){
			cout<<"\n***Username is already available***\n\n***Try again***\n\n";
			system("pause");
			return;
		}}
		catch(int x){
			cout<<"\n***File not found***\n";
			system("pause");
			return;
		}
		cout<<"\nEnter the password:";
		cin>>pass;
		try{
			fout.open("user.txt",ios::app);
			if(!fout){
				throw 1;
			}
			else{
				int c;
				cout<<"\n*** To create an account,You have to pay min amount Rs.500. Do you want to create ? \n\n";

    cout<<"\n\t\t\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~|";
    cout<<"\n\t\t\t| (1) Yes                   |";
    cout<<"\n\t\t\t| (2) No                    |";
    cout<<"\n\t\t\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~|";

    cout<<"\n\nEnter Your choice : ";
    try{
    	    long eid;
    	    fin.open("ucount.txt");
    	    fin>>eid;
    	    fin.close();
    	    cin>>c;
    	    if(c==1){
    	    stringstream ss;
    	    ss<<eid;
    	    eid++;
    	    id=ss.str();
			fout<<id<<"\t"<<name<<"\t"<<pass<<"\t"<<b;
			fout<<endl;
			fout.close();
			cout<<"\n***Accoount created successfully***\n\nYour id is: "<<(eid-1)<<"\n";
			fout.open("temp.txt",ios::app);
			fout<<eid;
			fout.close();
			remove("ucount.txt");
			rename("temp.txt","ucount.txt");
			system("pause");
			return;}
			if(c==2){
				cout<<"\n *** Thanks for requesting service ***\n";
				system("pause");
				return;
			}else{
				throw 1;
			}}catch(int x){
				cout<<"\n*** Invalid choice ***\n\n";
				system("pause");
				return;
				
			}}
			}
		
		catch (int x){
			cout<<"\n***File not found***\n";
			system("pause");
			return;
		}
	}
	void forgot(){
		int ch;
		string id2,id1;
		string pass2,pass1,name1;
		cout<<"\n1.Id\t\t2.Password\n";
		try{
			cout<<"\nEnter the option:";
			cin>>ch;
			if(ch==1){
				cout<<"\nEnter password:";
				cin>>pass2;
				try{
				fin.open("user.txt");
				if(!fin){
					throw 1;
				}
			else{
				while(fin>>id1>>name1>>pass1){
					if(pass2==pass1){
						cout<<"\nYour id is "<<id1<<"\n";
						fin.close();
						system("pause");
						return;
					}
				}
				fin.close();
				cout<<"\n***Sorry id not regiestred***\n";
				system("pause");
				return;
			}
			}catch(int x){
				cout<<"\n***File not found***\n";
			    return;
			}}
			if(ch==2){
				cout<<"\nEnter id:";
				cin>>id2;
				try{
				fin.open("user.txt");
				if(!fin){
					throw 1;
				}
			else{
				while(fin>>id1>>name1>>pass1){
					if(id==id1){
						cout<<"\nYour password is "<<pass1<<"\n";
						fin.close();
						system("pause");
						return;
					}
				}
				fin.close();
				cout<<"\n***Sorry id not regiestred***\n";
				system("pause");
				return;
			}
			}catch(int x){
				cout<<"\n***File not found***\n";
				system("pause");
			    return;
			}}
			else{
				throw 1;
			}
		}catch(int x){
			cout<<"\n***Invalid Input**\n";
			system("pause");
			return;
		}
	}	
};
int main(){
	Employee obj;
}
