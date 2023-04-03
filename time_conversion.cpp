#include <iostream>
#include<string>
#include <iomanip>
#include<math.h>
#include<stdio.h> 
using namespace std;
// 格里高利日期转换为儒略日 
double def1(double a[6])
{double s1,s2,s3,jd;
	s1=(int ) (1461*(a[0]+4800+(int) ((a[1]-14)/12 ))/4 );
	s2= (int) (367*(a[1]-2-(int) ((a[1]-14)/12 )*12)/12 );
	s3=(int) (3*(int)((a[0]+4900+(int) ((a[1]-14)/12) )/100 )/4 );
	jd= a[2]-32075+s1+s2-s3-0.5+a[3]/24+a[4]/1440+a[5]/86400;
	 return jd; 
	 	  }
//儒略日转换为格里高利日期 
double *def2(double jd)
{
	
	double  j,n,l1,l2,l3,y1,m1,t,t1;
//定义静态变量，防止返回地址在函数结束时被销毁 
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
//年+年积日+天内秒转换为儒略日 
void  def3(double a[3])
{
	double jd1,jd2,jd,b[6];
b[0]=a[0],b[1]=1,b[2]=1,b[3]=b[4]=b[5]=0;
	jd1=def1(b);
	jd2=a[1]+jd1-1,jd=jd2+a[2]/86400;
	printf("儒略日为 %lf",jd);
	
}
//儒略日转换为年+年积日+天内秒 
void  def4(double jd)
{
	double *a,b[6],c1;
	a=def2(jd);
	b[0]=a[0],b[1]=b[2]=1,b[3]=b[4]=b[5]=0;
	c1=def1(b),a[1]=jd-c1+1,a[2]=a[3]*3600+a[4]*60+a[5];
	cout<<a[0]<<"年 "<<a[1]<<"年积日 "<<a[2]<<" 天内秒"; 
}

//GPS周+周内秒转换为儒略日 
void def5()
{
	cout<<"请输入GPS周+周内秒";
	 double a[2],jd;
	 cin>>a[0]>>a[1];
	 jd=2444244.5+a[0]*7+a[1]/86400;
	 printf("儒略日为%lf",jd);
}
//儒略日转换为GPS周+周内秒 
void  def6()
{
	double m,jd;
	cout<<"请输入儒略日"<<endl;
	 cin>>jd;
	 int z;
	 z=(int) ((jd-2444244.5)/7);
	 m=( (jd-2444244.5)/7-z)*604800;
	 cout<<z<<"周"<<m<<"周内秒"; 
}
/*根据BD周+周内秒得到的儒略日具有如下约束条件：jd对应的儒略日大于(1980,1,6,0,0,0.0)对应的儒略日，即jd≥2444244.5。
//BD周+周内秒转为儒略日 */
void  def7()
{
	cout<<"请输入BD周+周内秒";
	double a[2],jd;
	cin>>a[0]>>a[1];
	jd=2453736.5+a[0]*7+a[1]/86400; 
	printf("儒略日为%lf",jd);
}

//儒略日转为BD周+周内秒 
void  def8()
{
	cout<<"请输入儒略日"<<endl;
	double jd,m;
	int z;
	cin>>jd;
z=int((jd-2453736.5)/7);
m=((jd-2453736.5)/7-z)*604800;	
cout<<z<<"BD周"<<m<<"周内秒";
}

//儒略日转换为Galileo周+周内秒 
void  def9()
{
	cout<<"请输入Galileo周+周内秒";
	double a[2],jd;
	cin>>a[0]>>a[1];
	jd=2451412.5+a[0]*7+a[1]/86400;
	printf("儒略日为%lf",jd);
}
//儒略日转换为Galileo周+周内秒 
void  def10()
{cout<<"请输入儒略日";
double jd,m;
int z;
cin>>jd;
z= ((jd-2451412.5)/7);
m=( (jd-2451412.50 )/7-z)*604800;
printf("%dGalileo周+%lf周内秒",z,m); 
}
/* 
Galileo周+周内秒时间标示法具有如下约束条件
周:z≥0.
周内秒(Time of Week)：0≤m<604800
根据GPS周+周内秒得到的儒略日具有如下约束条件：jd对应的儒略日大于(1999,8,22,0,0,0.0)对应的儒略日，即jd≥2451412.5
*/

//glonasst计时转换为儒略日
void  def11()
{
	cout<<"请输入glonasst计时N4+Nt+h+m+s";
	double Nt,N4,a[6],Jdn,jd,h,m,s;
	cin>>N4>>Nt>>h>>m>>s;
	a[0]=1996+4*(N4-1),a[1]=a[2]=1,a[3]=a[4]=a[5]=0;
	 Jdn=def1(a);
	 jd=Nt-1+Jdn+h/24+m/1440+s/86400;
	 printf("儒略日为%lf,jd");
}
//儒略日转换为glonasst 
void  def12()
{
	cout<<"请输入儒略日";
	double jd,*a,b[6],JDn,Nt;
	int N4;
	cin>>jd;
	a=def2(jd);
	N4=(int) ((a[0]-1996)/4)+1;
	b[0]=1996+4*(N4-1),b[1]=b[2]=1,b[3]=b[4]=b[5]=0;
	JDn=def1(b);
	Nt=jd-JDn+1;
	cout<<"GLONASST计时为"<<"N4 "<<N4<<" Nt "<<Nt;
}


int main()
{
cout<<"格里高利历日期转换为儒略日请输入1        "<<"儒略日转换成格里高利日期请输入2"<<endl;
cout<<"年+年积日+天内秒转换为儒略日请输入3      "<<"儒略日转换为年+年积日+天内秒请输入4"<<endl; 
cout<<"GPS周+周内秒转为儒略日请输入5            "<<"儒略日转换到GPS周+周内秒请输入6"<<endl;
cout<<"BD周+周内秒转为儒略日请输入7             "<<"儒略日转换到BD周+周内秒请输入8"<<endl;
cout<<"Galileo周+周内秒转为儒略日请输入9        "<<"儒略日转换到Galileo周+周内秒请输入 10"<<endl;
cout<<"GLONASST计时转换到儒略日请输入11         "<<"儒略日转换到GLONASST计时请输入12"<<endl<<"请输入选项（数字）";

int i;
cin>>i;
  switch(i)
{ case 1:
	int i;
	cout<<"请输入格里高利日期年+月+日+时+分+秒";
	double a[6],jd1;
		 for(i=0;i<6;i++){
	 	cin>>a[i];
	 }
jd1=def1(a);
printf("儒略日日期为%lf",jd1);
  break;
  
  case 2:
  	double jd;
  	double *p;
  		cout<<"请输入儒略日 ";
	cin>>jd;
    p= def2(jd);
cout<<"格里高利日期为"<< (int) p[0]<<"year"<<(int) p[1]<<"month"<<(int) p[2]<<"day"<<(int) p[3]<<"hour"<<(int) p[4]<<"minute"<<(int) p[5]<<"second";
     break;
     
  case 3:
  		int j;
		  double b[3];
	cout<<"请输入年+年积日+天内秒  "<<endl;
	for(j=0;j<3;j++)  cin>>b[j];
    def3(b);
    break;
    
  case 4:
  	double jd2;
  	cout<<"请输入儒略日  "<<endl;
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
