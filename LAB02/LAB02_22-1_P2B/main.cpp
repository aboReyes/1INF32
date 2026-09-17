#include <iostream>
#include <iomanip>
using namespace std;
#define K 4

int maximizarGanancia(int *precios,int n,int k) {
    int dp[k+1][n+1];
    for (int i=0;i<=k;i++) dp[i][0] = 0;
    for (int i=0;i<=n;i++) dp[0][i] = 0;
    for(int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            int maximotemporal=INT_MIN;
            for (int m=1; m<j; m++) {
                int valor=precios[j-1]-precios[m-1]+dp[i-1][m];
                if (valor>maximotemporal) maximotemporal=valor;
            }
            dp[i][j]=max(maximotemporal,dp[i][j-1]);
        }
    }
    for (int i=0;i<=k;i++) {
        for (int j=0;j<=n;j++) {
            cout<<setw(2)<<right<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[k][n];
}

int main(int argc, char **argv) {
    int precios[]={315,322,385,375,365,380};
    int n=sizeof(precios)/sizeof(precios[0]);

    maximizarGanancia(precios,n,K);

    return 0;
}

