//3. Viết CT tính A^-1 của ma trận A

#include<iostream>
#include<iomanip>
using namespace std;
void nhap(float a[][100],int &n);
void xuat(float a[][100],int n);
float det(float a[][100],int n);
float con(float a[][100],int n,int h,int c);
void nghichdao(float a[][100],int n);
int main()
{
 
 	int n=2;
	float a[100][100];
    for(int i=0;i<n;i++)
    {
    for(int j=0;j<n;j++)
      {
        a[i][j] = rand()%(15);
      }
 	}
 xuat(a,n);
 cout<<"\n-------------------------------\nma tran nghich dao:\n";
 nghichdao(a,n);
 system("pause");
}

void xuat(float a[][100],int n)
{
 for(int i=0;i<n;i++)
 {
  cout<<"\n\n";
  for(int j=0;j<n;j++)
   cout<<setw(6)<<a[i][j];
 }
}
float det(float a[][100],int n)
{
 int i,j,k,dem=0,kt;
 float b[100],h,kq=1;
 for(i=0;i<n-1;i++)
 {
  if(a[i][i]==0)
  {
   kt=0;
   for(j=i+1;j<n;j++)
   {
    if(a[i][j]!=0)
    {
     for(k=0;k<n;k++)
     {
      float t=a[k][i];
      a[k][i]=a[k][j];
      a[k][j]=t;
     }
     dem++;kt++;
     break;
    }
   }
   if(kt==0) return 0;
  }
  b[i]=a[i][i];
  for(j=0;j<n;j++) a[i][j]/=b[i];
  for(j=i+1;j<n;j++)
  {
   h=a[j][i];
   for(k=0;k<n;k++) a[j][k]=a[j][k]-h*a[i][k];
  }
 }
 b[n-1]=a[n-1][n-1];
 for(i=0;i<n;i++) kq*=b[i];
 if(dem%2==0) return kq;
 return -kq;
}
float con(float a[][100],int n,int h,int c)
{
 float b[100][100];
 int i,j,x=-1,y;
 for(i=0;i<n;i++)
 {
  if(i==h) continue;
  x++;y=-1;
  for(j=0;j<n;j++)
  {
   if(j==c)continue;
   y++;
   b[x][y]=a[i][j];
  }
 }
 if((h+c)%2==0) return det(b,n-1);
 return -det(b,n-1);
}
void nghichdao(float a[][100],int n)
{
 float b[100][100];
 for(int i=0;i<n;i++)
 {
  for(int j=0;j<n;j++)
  {
   b[i][j]=con(a,n,i,j);
  }
 }
 for(int i=0;i<n-1;i++)
  for(int j=i+1;j<n;j++)
  {
   float t=b[i][j];
   b[i][j]=b[j][i];
   b[j][i]=t;
  }
 float k=det(a,n);
 for(int i=0;i<n;i++)
  for(int j=0;j<n;j++)
   b[i][j]/=k;
 if(k==0) cout<<"\nkhong co ma tran nghich dao!";
 else xuat(b,n);
}