

#include <iomanip>
#include <iostream>
using namespace std;

#define N 9

int contarFormas(int matriz[N][4],int n) {
    int dp[n+1];
    dp[0] = 1; //el bloque de no colocar nada
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;

    for (int i=4; i<=n; i++) {
        dp[i] = dp[i-1]+dp[i-4];
    }

    for (int i=0;i<=n; i++) cout<<setw(2)<<right<<i<<" ";
    cout<<endl;
    for (int i=0; i<=n; i++) {
        cout<<setw(2)<<right<<dp[i]<<" ";
    }
    cout<<endl;
    return dp[n];
}

int main(int argc, char **argv) {
    int matriz[N][4]={
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
    };
    contarFormas(matriz,N);
    return 0;
}

