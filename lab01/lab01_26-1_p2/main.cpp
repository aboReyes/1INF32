

#include <iostream>
using namespace std;
#define N 10
#define M 10
#define MAX_MOV 8
#define MAX_DIR 4

void inicializatablero(int tablero[N][M],int n,int m) {
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            tablero[i][j]=0;
}

void imprime(int tablero[N][M],int n,int m) {
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++)
            cout<<tablero[i][j]<<" ";
        cout<<endl;  // ← mover el endl aquí dentro, al terminar cada fila
    }
}

void generaDirecciones(int dir[4][2],int largo) {
    largo--;
    dir[0][0]=-1*largo;     dir[0][1]=0;        //arriba
    dir[1][0]=0;            dir[1][1]=largo;    //derecha
    dir[2][0]=largo;        dir[2][1]=0;        //abajo
    dir[3][0]=0;            dir[3][1]=-1*largo; //izquierda
}

void generaMovimientos(int mov[8][2]) {
    mov[0][0]=-1;        mov[0][1]=0;
    mov[1][0]=-1;        mov[1][1]=1;
    mov[2][0]=0;         mov[2][1]=1;
    mov[3][0]=1;         mov[3][1]=1;
    mov[4][0]=1;         mov[4][1]=0;
    mov[5][0]=1;         mov[5][1]=-1;
    mov[6][0]=0;         mov[6][1]=-1;
    mov[7][0]=-1;        mov[7][1]=-1;
}

int validaposicion(int x,int y,int tablero[N][M],int n, int m) {
    //verifica que no se salga del tablero y que esté libre
    if (x>=0 and y>=0 and x<n and y<m and tablero[x][y]==0) return 1;
    return 0;
}

int validarecorrido(int xini,int yini,int xfin,int yfin,int n,int m,int tablero[N][M]) {
    int j,k;
    if(validaposicion(xfin,yfin,tablero,n,m)) {
        if(xini<xfin)
            for(j=xini;j<=xfin;j++){
                if(tablero[j][yini]!=0) return 0;
            }
        else
            for(j=xini;j>=xfin;j--)
                if(tablero[j][yini]!=0) return 0;
        if(yini<yfin)
            for(k=yini;k<=yfin;k++){
                if(tablero[xini][k]!=0) return 0;
            }
        else
            for(k=yini;k>=yfin;k--)
                if(tablero[xini][k]!=0) return 0;
        return 1;
    }
    return 0;
}

void marca(int xini,int yini,int xfin,int yfin,int n,int m,int nmov,int tablero[N][M]) {
    if (xini<xfin) {
        for (int i=xini;i<=xfin;i++) {
            tablero[i][yini]=nmov;
        }
    }
    else {
        for (int i=xini;i>=xfin;i--) {
            tablero[i][yini]=nmov;
        }
    }
    if (yini<yfin) {
        for (int j=yini;j<=yfin;j++) {
            tablero[xini][j]=nmov;
        }
    }
    else {
        for (int j=yini;j>=yfin;j--) {
            tablero[xini][j]=nmov;
        }
    }
}

int generacortes(int x,int y,int n,int m,int nmov,
                int tablero[N][M],int mov[8][2],int dir[4][2]) {
    int nx,ny;
    static  int maxmov=0;
    static int mejortablero[N][M];
    //este primer for evalúa las posiciones adyacentes
    for (int i=0;i<MAX_MOV;i++) {
        nx=x+mov[i][0];
        ny=y+mov[i][1];
        // si la propuesta de movimiento adyacente pasa el filtro de validaposicion,
        // continua con la verificacion del recorrido
        if (validaposicion(nx,ny,tablero,n,m)) {
            int nfinx,nfiny;
            for (int j=0;j<MAX_DIR;j++) {
                nfinx=nx+dir[j][0];
                nfiny=ny+dir[j][1];
                if (validarecorrido(nx,ny,nfinx,nfiny,n,m,tablero)) {
                    marca(nx,ny,nfinx,nfiny,n,m,nmov,tablero);
                    if (maxmov<nmov) {
                        maxmov=nmov;
                        for (int a=0;a<n;a++)
                            for (int b=0;b<m;b++)
                                mejortablero[a][b]=tablero[a][b];
                    }
                    if (generacortes(nfinx,nfiny,n,m,nmov+1,tablero,mov,dir)) return 1;
                    marca(nx,ny,nfinx,nfiny,n,m,0,tablero);
                }
            }
        }
    }
    if (nmov==1) {
        cout << "Total listones: " << maxmov << endl;
        imprime(mejortablero,n,m);
    }
    return 0;
}

int main(int argc, char **argv) {
    int n=5, m=5, c=3,x=-1,y=-1;
    int mov[8][2],dir[4][2],tablero[N][M];

    //inicializaciones de la matriz
    generaMovimientos(mov);
    generaDirecciones(dir,c);
    inicializatablero(tablero,n,m);
    //la función recursiva back
    generacortes(x,y,n,m,1,tablero,mov,dir);

    return 0;
}

