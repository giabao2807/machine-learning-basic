
#include <iostream>
#include <cmath>
using namespace std;

int main() { 
   int i,j,m,n,a[10][10],sum=0,trace=0;
   float norm;
   cout << "Number of rows:" ;
   cin>>m;
   cout<<"Number of columns:";
   cin>>n;

   for ( int i = 0; i < m; i++ ) {
	for ( int j = 0; j < n; j++ ) {
	   cout<<"Element["<<i<<"]["<<j<<"]: ";
	   cin>>a[i][j];
   }} 
       for ( int i = 0; i < m; i++ ) {
	     for ( int j = 0; j < n; j++ ) {
	   sum=sum+(a[i][j]^2);
	   if(i==j)
	   trace=trace+a[i][j];
}
}
norm=sqrt(sum);
cout<<""<<norm<<"";
}