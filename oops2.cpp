//NAME : UTKARSH SONAWANE
//BATCH : C
//ROLL NO: 49 

using namespace std;
#include<iostream>
#include<string.h> 
#include<ctime> 

class age;

class student
{
	friend class age;			//declared friend class age
	private:
		char *name,*blood,*address;	//declared data variable
		int dob;
		long int insurance,tel,license;
		float height,weight;
		static int count;               //static variables
	public:
		student()			 //default & dynamic constructor
		{
			count++;
			cout<<"-----------------default information------------";
			name=new char[13];	//allocate dynamic memory using new operator
			strcpy(name,"default name");
			blood=new char[3];
			strcpy(blood,"O+");
			address=new char[20];
			strcpy(address,"nasik");
			insurance=12345;
			tel=360410550;
			license=1234567;
			height=10.2;
			weight=120;
			dob=1996;
			display();

		}
		student(char n[],char b[],int yy,char add[],long int in,long int tn,long int ln,float h,float w) 
                                //parameterized constructor
		{
		        count++;
		        int len;
		        len=strlen(n);
		        name=new char[len+1];
		        strcpy(name,n);

		        len=strlen(b);
		        blood=new char[len+1];
		        strcpy(blood,b);

		        len=strlen(add);
		        address=new char[len+1];
		        strcpy(address,add);
		        dob=yy;
		        insurance=in;
		        tel=tn;
		        license=ln;
		        height=h;
		        weight=w;
		}
		void display();				//display function declaration
		
		student & compare(student *x1) 		//copy constructor
		{
			if(x1->height > height)
			{
			        return *x1;
			}
			else
			{
			        return *this;		//uses thin pointer
			}
		}
		static int displaycount()               //static member function
		{
		        cout<<"\n NUMBER OF ENTRIES ARE:"<<count<<endl;
		}

	        ~student()              	  //destructor having same name like constructor 
	        {
		        cout<<"\n destructor called...";
	        }
};
class age                                               //friend class defination
{
private:int ag,date;
public:
        void calculate(student *x)			//calculate the age of STUDENT
        {
                date=x->dob;
                time_t now=time(0);
                tm *ltm=localtime(&now);
                ag=(1966+ltm->tm_year)-date;
                cout<<" AGE:"<<ag<<endl;
        }
};
int student::count=0;
        void student::display()				//display function definition
        {
	        cout<<"\n STUDENT NAME:"<<name;
	        cout<<"\n BLOOD GROUP:"<<blood;
	        cout<<"\n DATE OF BIRTH:"<<dob;
	        cout<<"\n CONTACT ADDRESS:"<<address;
	        cout<<"\n INSURANCE NUMBER:"<<insurance;
	        cout<<"\n TELEPHONE NUMBER:"<<tel;
	        cout<<"\n LICENSE NUMBER:"<<license;
	        cout<<"\n HEIGHT:"<<height;
	        cout<<"\n WEIGHT:"<<weight<<endl;
        }
int main()						//main function
{
	int ch;						//variable declaration
	student*p[20],*temp;
	age *a[20];
	char pname[15],pblood[5],paddress[20];
	long int pinsurance,ptel,plicense;
	float pheight,pweight;
	int cnt=0,dd;
do
{
        cout<<"\n ---------------------------MENU--------------------------"<<endl;
	cout<<"\n 1.DEFAULT CONSTRUCTER ";
	cout<<"\n 2.PARAMETERIZED CONSTRUCTOR";	
	cout<<"\n 3.NUMBER OF ENTRIES";
	cout<<"\n 4.CALCULATE AGE:";
	cout<<"\n 5.TALLER STUDENT:";
	cout<<"\n 6.EXIT";
	cout<<"\n ENTER THE CHOICE:";
	cin>>ch;
	switch(ch)
	{
		case 1: 			//DEFAULT CONSTRUCTER INFORMATION
			p[cnt]=new student();
			a[cnt]=new age();
			cnt=cnt+1;
			break;
		case 2:				//PARAMETERIZED CONSTRUCTOR INFORMATION
			cout<<"\n ENTER THE STUDENT NAME:";
			cin>>pname;
			cout<<"\n ENTER THE STUDENT BLOOD GROUP:";
			cin>>pblood;
			cout<<"\n ENTER DATE OF BIRTH:";
			cin>>dd;
			cout<<"\n ENTER THE STUDENT CONTACT ADDRESS:";
			cin>>paddress;
			cout<<"\n ENTER THE STUDENT INSURANCE NUMBER:";
			cin>>pinsurance;
			cout<<"\n ENTER THE STUDENT TELEPHONE NUMBER:";
			cin>>ptel;
			cout<<"\n ENTER THE STUDENT LICENSE NUMBER:";
			cin>>plicense;
			cout<<"\n ENTER THE STUDENT HEIGHT:";
			cin>>pheight;
			cout<<"\n ENTER THE STUDENT WEIGHT:";
			cin>>pweight;
			p[cnt]=new student(pname,pblood,dd,paddress,pinsurance,ptel,plicense,pheight,pweight);
			a[cnt]=new age();
			cnt=cnt+1;
			break;

		case 3:				//NUMBER OF ENTRIES INFORMATION
			student::displaycount();
			break;
		case 4:				//CALCULATE AGE INFORMATION
			for(int i=0;i<cnt;i++)
			{
				p[i]->display();
				a[i]->calculate(p[i]);
			}
			break;
			
		case 5:				//TALLER STUDENT INFORMATION
			temp = p[0];
			for(int j=1;j<cnt;j++)
			{
				temp = &temp->compare(p[j]);
			}
			cout<<"\n ------TALLER STUDENT INFORMATON-------"<<endl;
			temp->display();
			break;
		case 6: 
		        return 0;		
	}
        }while(ch!=6);
}


