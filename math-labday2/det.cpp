#include <iostream>
using namespace std;

float det(float a[][100],int n);
int main(){
	int n=2;
	float a[100][100];
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
    cout << "Det matrix: " << det(a,n)<< "\n";
    return 0;
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