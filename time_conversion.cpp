#include <iostream>
#include<string>
#include <iomanip>
#include<math.h>
#include<stdio.h> 
using namespace std;
// �����������ת��Ϊ������ 
double def1(double a[6])
{double s1,s2,s3,jd;
	s1=(int ) (1461*(a[0]+4800+(int) ((a[1]-14)/12 ))/4 );
	s2= (int) (367*(a[1]-2-(int) ((a[1]-14)/12 )*12)/12 );
	s3=(int) (3*(int)((a[0]+4900+(int) ((a[1]-14)/12) )/100 )/4 );
	jd= a[2]-32075+s1+s2-s3-0.5+a[3]/24+a[4]/1440+a[5]/86400;
	 return jd; 
	 	  }
//������ת��Ϊ����������� 
double *def2(double jd)
{
	
	double  j,n,l1,l2,l3,y1,m1,t,t1;
//���徲̬��������ֹ���ص�ַ�ں�������ʱ������ 
static	double a[6]; 

	j=(int) (jd+0.5 ),n=(int) (4*(j+68569)/146097);
	 l1=j+68569-(int) ((n*146097+3)/4 ), y1=(int) ((4000*(l1+1)/1461001) );
	l2=l1-(int) ((1461*y1/4))+31,m1=(int) (80*l2/2447 );
	a[2]=l2-(int) (2447*m1/80 ),l3= (int) (m1/11 );
	a[1]=m1+2-12*l3,a[0]=(int) (100*(n-49)+y1+l3 );
	t=fmod(((jd+0.5-(int) jd )*24),24 ); 
	a[3]=(int) t;
	t1=fmod((t-a[3])*60,60),a[4]=(int) t1,a[5]=fmod((t1-a[1])*60,60 );
	
	 return a;
}
//��+�����+������ת��Ϊ������ 
void  def3(double a[3])
{
	double jd1,jd2,jd,b[6];
b[0]=a[0],b[1]=1,b[2]=1,b[3]=b[4]=b[5]=0;
	jd1=def1(b);
	jd2=a[1]+jd1-1,jd=jd2+a[2]/86400;
	printf("������Ϊ %lf",jd);
	
}
//������ת��Ϊ��+�����+������ 
void  def4(double jd)
{
	double *a,b[6],c1;
	a=def2(jd);
	b[0]=a[0],b[1]=b[2]=1,b[3]=b[4]=b[5]=0;
	c1=def1(b),a[1]=jd-c1+1,a[2]=a[3]*3600+a[4]*60+a[5];
	cout<<a[0]<<"�� "<<a[1]<<"����� "<<a[2]<<" ������"; 
}

//GPS��+������ת��Ϊ������ 
void def5()
{
	cout<<"������GPS��+������";
	 double a[2],jd;
	 cin>>a[0]>>a[1];
	 jd=2444244.5+a[0]*7+a[1]/86400;
	 printf("������Ϊ%lf",jd);
}
//������ת��ΪGPS��+������ 
void  def6()
{
	double m,jd;
	cout<<"������������"<<endl;
	 cin>>jd;
	 int z;
	 z=(int) ((jd-2444244.5)/7);
	 m=( (jd-2444244.5)/7-z)*604800;
	 cout<<z<<"��"<<m<<"������"; 
}
/*����BD��+������õ��������վ�������Լ��������jd��Ӧ�������մ���(1980,1,6,0,0,0.0)��Ӧ�������գ���jd��2444244.5��
//BD��+������תΪ������ */
void  def7()
{
	cout<<"������BD��+������";
	double a[2],jd;
	cin>>a[0]>>a[1];
	jd=2453736.5+a[0]*7+a[1]/86400; 
	printf("������Ϊ%lf",jd);
}

//������תΪBD��+������ 
void  def8()
{
	cout<<"������������"<<endl;
	double jd,m;
	int z;
	cin>>jd;
z=int((jd-2453736.5)/7);
m=((jd-2453736.5)/7-z)*604800;	
cout<<z<<"BD��"<<m<<"������";
}

//������ת��ΪGalileo��+������ 
void  def9()
{
	cout<<"������Galileo��+������";
	double a[2],jd;
	cin>>a[0]>>a[1];
	jd=2451412.5+a[0]*7+a[1]/86400;
	printf("������Ϊ%lf",jd);
}
//������ת��ΪGalileo��+������ 
void  def10()
{cout<<"������������";
double jd,m;
int z;
cin>>jd;
z= ((jd-2451412.5)/7);
m=( (jd-2451412.50 )/7-z)*604800;
printf("%dGalileo��+%lf������",z,m); 
}
/* 
Galileo��+������ʱ���ʾ����������Լ������
��:z��0.
������(Time of Week)��0��m<604800
����GPS��+������õ��������վ�������Լ��������jd��Ӧ�������մ���(1999,8,22,0,0,0.0)��Ӧ�������գ���jd��2451412.5
*/

//glonasst��ʱת��Ϊ������
void  def11()
{
	cout<<"������glonasst��ʱN4+Nt+h+m+s";
	double Nt,N4,a[6],Jdn,jd,h,m,s;
	cin>>N4>>Nt>>h>>m>>s;
	a[0]=1996+4*(N4-1),a[1]=a[2]=1,a[3]=a[4]=a[5]=0;
	 Jdn=def1(a);
	 jd=Nt-1+Jdn+h/24+m/1440+s/86400;
	 printf("������Ϊ%lf,jd");
}
//������ת��Ϊglonasst 
void  def12()
{
	cout<<"������������";
	double jd,*a,b[6],JDn,Nt;
	int N4;
	cin>>jd;
	a=def2(jd);
	N4=(int) ((a[0]-1996)/4)+1;
	b[0]=1996+4*(N4-1),b[1]=b[2]=1,b[3]=b[4]=b[5]=0;
	JDn=def1(b);
	Nt=jd-JDn+1;
	cout<<"GLONASST��ʱΪ"<<"N4 "<<N4<<" Nt "<<Nt;
}


int main()
{
cout<<"�������������ת��Ϊ������������1        "<<"������ת���ɸ����������������2"<<endl;
cout<<"��+�����+������ת��Ϊ������������3      "<<"������ת��Ϊ��+�����+������������4"<<endl; 
cout<<"GPS��+������תΪ������������5            "<<"������ת����GPS��+������������6"<<endl;
cout<<"BD��+������תΪ������������7             "<<"������ת����BD��+������������8"<<endl;
cout<<"Galileo��+������תΪ������������9        "<<"������ת����Galileo��+������������ 10"<<endl;
cout<<"GLONASST��ʱת����������������11         "<<"������ת����GLONASST��ʱ������12"<<endl<<"������ѡ����֣�";

int i;
cin>>i;
  switch(i)
{ case 1:
	int i;
	cout<<"������������������+��+��+ʱ+��+��";
	double a[6],jd1;
		 for(i=0;i<6;i++){
	 	cin>>a[i];
	 }
jd1=def1(a);
printf("����������Ϊ%lf",jd1);
  break;
  
  case 2:
  	double jd;
  	double *p;
  		cout<<"������������ ";
	cin>>jd;
    p= def2(jd);
cout<<"�����������Ϊ"<< (int) p[0]<<"year"<<(int) p[1]<<"month"<<(int) p[2]<<"day"<<(int) p[3]<<"hour"<<(int) p[4]<<"minute"<<(int) p[5]<<"second";
     break;
     
  case 3:
  		int j;
		  double b[3];
	cout<<"��������+�����+������  "<<endl;
	for(j=0;j<3;j++)  cin>>b[j];
    def3(b);
    break;
    
  case 4:
  	double jd2;
  	cout<<"������������  "<<endl;
	cin>>jd2;
    def4(jd2);
    break;
    
  case 5:
    def5();
    break;
      
  case 6:
    def6();
    break;
  case 7:
    def7();		 
	break;	
  case 8:
    def8();
    break;
  case 9:
    def9();
    break;
  case 10:
    def10();
    break;
    
  case 11:
    def11();
  break;
  case 12 :
    def12();
	break;			
}
    return 0;
}
