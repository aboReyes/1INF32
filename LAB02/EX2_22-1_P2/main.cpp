

#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;

#define R 3 //robots
#define N 5 //tareas


int calcularTiempoMaximo(int *tareas,int n,int r) {
    int dp[r+1][n+1];

    //fila 0 y columna 0
    for (int i=0;i<=r;i++) dp[i][0] = 0;
    for (int j=1;j<=n;j++) dp[0][j] = INT_MAX;

    //fila 1 y columna 1
    for (int j=1;j<=n;j++) dp[1][j]=dp[1][j-1]+tareas[j-1];

    for (int i=2;i<=r;i++) { //robots
        for (int j=1;j<=n;j++) { //tareas
            int mintiempo=9999;
            for (int k=1;k<=j;k++) { //procesamiento
                int tiempoUltimoRobot=dp[1][j]-dp[1][j-k];
                int tiempoRestante=dp[i-1][j-k];
                int maxtemporal=max(tiempoUltimoRobot,tiempoRestante);
                if (maxtemporal<mintiempo) {
                    mintiempo=maxtemporal;
                }
            }
            dp[i][j]=mintiempo;
        }
    }
    for (int i=0;i<=r;i++) {
        for (int j=0;j<=n;j++) {
            cout<<setw(4)<<right<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[r][n];
}

int main(int argc, char **argv) {
    int tareas[]={15,30,60,45,10};
    int n=sizeof(tareas)/sizeof(tareas[0]);
    sort(tareas,tareas+n);
    calcularTiempoMaximo(tareas,5,3);
    return 0;
}

