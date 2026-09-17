
#include <iomanip>
#include <iostream>
using namespace std;

int maximizarGanancia(int *compras,int *fechas,int k,int n) {
    int dp[k+1][n];
    for (int i=0;i<=k;i++) dp[i][0]=0;
    for (int i=0;i<n;i++) dp[0][i]=0;

    for (int i=1;i<=k;i++) {
        for (int j=1;j<n;j++) {
            int maximo=INT_MIN;
            for (int m=0;m<j;m++) {
                maximo=max(maximo,fechas[j]-fechas[m]+dp[i-1][m]);
            }
            dp[i][j]=max(maximo,dp[i][j-1]);
        }
    }

    for (int i=0;i<=k;i++) {
        for (int j=0;j<n;j++) {
            cout<<setw(2)<<right<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return dp[k][n];
}

int main(int argc, char **argv) {
    int compras[]={1,2,3};
    int fechas[]={315,322,385,375,365,380};
    int k=sizeof(compras)/sizeof(compras[0]);
    int n=sizeof(fechas)/sizeof(fechas[0]);
    maximizarGanancia(compras,fechas,k,n);
    return 0;
}

