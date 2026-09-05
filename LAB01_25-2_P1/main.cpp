#include <iomanip>
#include <iostream>
using namespace std;

#define N 8
#define M 8
#define MAXMOV 8

void inicializarTablero(int tablero[N][M]) {
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            tablero[i][j]=0;
        }
    }
}

void generamovimientos(int mov[8][2]) {
    //-1 arriba  izquierda
    //0 quieto
    //1 abajo derecha
    mov[0][0]=-1;    mov[0][1]=-1;
    mov[1][0]=-1;    mov[1][1]=0;
    mov[2][0]=-1;     mov[2][1]=1;
    mov[3][0]=0;     mov[3][1]=1;
    mov[4][0]=1;     mov[4][1]=1;
    mov[5][0]=1;     mov[5][1]=0;
    mov[6][0]=1;     mov[6][1]=-1;
    mov[7][0]=0;    mov[7][1]=-1;
}

int verificamovimiento(int tablero[N][M],int x,int y,int n,int m) {
    if (x>=0 and x<n and y>=0 and y<m and tablero[x][y]==0) return 1;
    return 0;
}

int marca(int tablero[N][M],int mov[8][2],int x,int y,int n,int m,int nmov) {
    if (nmov==65) return 1;
    int nx,ny;
    for (int i=0;i<MAXMOV;i++) {
        nx=x+mov[i][0];
        ny=y+mov[i][1];
        if (verificamovimiento(tablero,nx,ny,n,m)) {
            tablero[nx][ny]=nmov;
            if (marca(tablero,mov,nx,ny,n,m,nmov+1)) return 1;
            tablero[nx][ny]=0;
        }
    }
    return 0;
}

void imprime(int tablero[N][M]) {
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            cout<<setw(2)<<right<<tablero[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(int argc, char **argv) {
    int f=3,c=3,tablero[N][M],mov[8][2];
    inicializarTablero(tablero);
    generamovimientos(mov);
    tablero[f][c]=1;
    marca(tablero,mov,f,c,N,M,2);
    imprime(tablero);
    return 0;
}

