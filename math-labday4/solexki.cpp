float phanra(int[] a, int[] l, int n)
{
    for(int k = 1; k <= n; k++)
    {
       l[k][k] = a[k][k];
       if(l[k][k] == 0)
       return 0;
       else{
       for(int i = k+1; i <= n;i++)
       {
           l[i][k] = a[i][k];
           u[k][i] = a[k][i]/l[k][k];
           u[i][k] = 0;
           l[k][i] = 0;
       }
       for(int i = k+1; i <= n; i++)
       for(int j = k+1; j <= n; j++)
       a[i][j] = a[i][j] - l[i][k]*u[k][j];       
    }
  }
}

int main()
{
	int arr[10][10];
	int n = 2;
	int m = 3;
    for(int i=0;i<n;i++)
    {
    for(int j=0;j<m;j++)
      {
        arr[i][j] = rand()%(15);
      }
 	}
	for(int i=0;i<n;i++)
    {
    	for(int j=0;j<m;j++) cout<<arr[i][j]<< " " ;
    	cout<<"\n";
    }
	cout << Norm(arr, n, m, 3);
}