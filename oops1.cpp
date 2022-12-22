#include<iostream>
using namespace std;
class complex{
	int real;
	int img;
	public:complex(){
		real=0;
		img=0;
	}
	complex(int r, int i){
		real=r;
		img=i;
	}
int getReal(){
	return real;
}
int getImg(){
	return img;
}
void setReal(int r){
	real=r;
}
void setImg(int i){
	img=i;
}
friend ostream &operator<<(ostream &os,complex obj);
friend istream &operator>>(istream &is,complex &obj);
complex operator + (complex c){
	int r=real+c.getReal();
	int i=img+c.getImg();
	complex co(r,i);
	return co;
}
complex operator*(complex c){
	int r=real*c.getReal()-img*c.getImg();
	int i=real*c.getImg()+img*c.getReal();
	complex co(r,i);
	return co;
}
};
ostream & operator<<(ostream &os,complex obj){
	os<<"\n"<<obj.getReal()<<"+"<<obj.getImg()<<"i\n";
	return os;
}
istream & operator>>(istream &is,complex &obj){
	int t1,t2;
	cout<<"Enter real part:";
	is>>t1;
	cout<<"Enter imaginary part:";
	is>>t2;
	obj.setReal(t1);
	obj.setImg(t2);
	return is;
}
int main(){
	complex x1;
	cin>>x1;
	cout<<x1;
	complex x2;
	cin>>x2;
	cout<<x2;
	complex x3=x1+x2;
	cout<<"Addition is \n";
	cout<<x3;
	x3=x1*x2;
	cout<<"multiplication is\n";
	cout<<x3;
}
	
		
	
	


