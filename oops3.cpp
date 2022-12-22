#include <iostream>
#include<string>
using namespace std;

class publication
{
protected:
string title;
float price;
public:
publication()

{
title=" ";
price=0.0;
}
publication(string t,float p)
{
title=t;
price=p;
}

public:

void getdata()
{
cout<<"Enter title of publications: ";
cin>>title;
cout<<"Enter price of publication: ";
cin>>price;

}
void putdata(void)
{
cout<<"Publication titles: "<<title<<endl;
cout<<"Publication price: "<<price<<endl;
}
};
class book:public publication
{
int pagecount;
public:
book()
{
pagecount=0;
}
book(string t,float p,int pe):publication(t,p)
{
pagecount=pe;
}
void getdat(void)
{
publication::getdata();
cout<<"Enter Book Page count: ";
cin>>pagecount;
}
void putdata(void)
{
publication::putdata();
cout<<"Book page count: "<<endl;
}
};
class Cd:public publication
{
float time1;
public:
Cd()
{
time1=0.0;
}
Cd(string t, float p,float tim):publication(t,p)
{
time1=tim;
}
void getdata(void)
{
publication::getdata();
cout<<"Enter tape's playing time: ";
cin>>time1;
}
void putdata(void)
{
publication::putdata();
cout<<"Tape's playing time: "<<time1;
}
};

int main()
{
cout<<endl<<"Book data"<<endl;
book b("C++",330,300);
b.putdata();
cout<<endl<<"CD Data"<<endl;
Cd e("C++",100,120.5);
e.putdata();

cout<<"\nEnter New Details of book: \n";
b.getdata();
e.getdata();
cout<<"\n\nBook Data entered by user: \n";
b.putdata();
e.putdata();
return 0;
}

