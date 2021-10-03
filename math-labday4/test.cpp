float phanra(float **a, float **l, float **u, int n)
{
    for(int k = 1; k <= n; k++)
    {
       u[k][k] = 1;
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