#include<iostream.h>
#include<conio.h>
#include<dos.h>

float error,prerror=0,der,pout,integ=0,setpoint,provar;
float kp=0.5,kd=0.5,ki=0.1; //kp,kd,ki are the constants//


void pid()             //pid function calculates error & output for every second//
{
for(int t=0;;t++)     //loop uses variable t which is assumed as the time in seconds//
{
error=setpoint-provar;
integ=integ+ki*t;      //integ is used for calculating the integral values
if(t>0)
der=error-prerror/t;   //der is used only for calculating derivative values after the 1st second//
pout=kp*error+ki*integ+kd*der; //pout is the output at every second
prerror=error;        //the error from the current iteration is noted so that it can be used later//
provar=provar+pout;

cout<<"error at "<<t+1<<" secs "<<"= "<<error<<endl;
cout<<"output at "<<t+1<<" secs "<<"= "<<pout<<endl<<endl;

sleep(1);

if(error>0)
{
if((error==0)||(error<1))  //condition to display final position when error is less than 1 and +ve//
{
cout<<"error approximately corrected"<<endl<<"auv at "<<provar<<endl;
break;}}
else
{
if((error==0)||(error>-1)) //condition to display final position when error is greater than -1 and -ve//
{
cout<<"error approximately corrected"<<endl<<"auv at "<<provar<<endl;
break;}
}

}}



void main()
{clrscr();

cout<<"enter current depth"<<endl;
cin>>provar;                         //accepting current depth//
cout<<"enter desired depth"<<endl;
cin>>setpoint;                       //accepting desired depth//

pid();  //calling pid function//

getch();}