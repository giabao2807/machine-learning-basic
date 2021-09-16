#include<iostream>
#include<stdio.h>
using namespace std;

int i,j,na,n;
double a[10][10],b[10][10];

void doicho(int i1,int i2);
void cong(int i1,int i2,double x);
void matran();

void doicho(int i1,int i2)
{ int j;
double tg;
for(j=1;j<=na;j++)
{ tg=a[i1][j];
a[i1][j]=a[i2][j];
a[i2][j]=tg;
}
}
// ham dung de nhan hang i1 voi x roi cong vao hang i2 trong ma tran.
void cong(int i1,int i2,double x)
{ int j;
for(j=1;j<=na;j++) a[i2][j]=a[i2][j]+a[i1][j]*x;
}
// ham dung giai phuong trinh.
void matran()
{ int i,j,k;
double x,det;

for(j=1;j<=n;j++)
{
for(i=n;i>=j;i--)
{ if(a[i][j]==0) continue;
if((i>j)&&(a[i][j]!=0))
{ k=i-1;
while((k>=j)&&(a[k][j]==0)) k--;
if(k<j) doicho(i,j);
if((k>=j)&&(k>=1))
{ x=-a[i][j]/a[k][j];
cong(k,i,x);
}
}
}
}
for(j=n;j>=1;j--)
{
for(i=1;i<=j;i++)
{ if(a[i][j]==0) continue;
if((i<j)&&(a[i][j]!=0))
{ k=i+1;
while((k<=j)&&(a[k][j]==0)) k++;
if((k<=j)&&(k<=na))
{ x=-a[i][j]/a[k][j];
cong(k,i,x);
}
}
}
}
// tinh dinh thuc
det=1;
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
if(i==j) det=det*a[i][j];
cout<<"\n "<<"dinh thuc cua ma tran la :"<<det; // printf("\n det=%f",det);

}


int main()
{ 
	int n =2;
    for(int i=0;i<n;i++)
    {
    for(int j=0;j<n;j++)
      {
        a[i][j] = rand()%(15);
      }
 	}
 	for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++) cout<<a[i][j]<< " " ;
    	cout<<"\n";
    }

// tao ma tran lien ket
for(i=1;i<=n;i++)
for(j=n+1;j<=na;j++)
{
if(i==(j-n)) a[i][j]=1;
else a[i][j]=0;
}

matran();

return 0;



}