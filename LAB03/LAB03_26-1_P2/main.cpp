#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;
#define N 5
#define M 6
#define CAP_MAXIMA 10

void algoritmoVoraz(int matriz[N][N],int origen,int destino) {
    int tanque=CAP_MAXIMA;
    int nodoActual=origen;
    vector<int> candidatos;
    vector<bool> visitados (N, false);
    visitados[origen] = true; //caso base
    vector<int> ruta;
    ruta.push_back(origen);

    bool tienegrifo[N]={true,false,true,false,false};

    while (ruta.back()!=destino) {
        //Limpiar cada iteración para los nuevos candidatos de la nueva ruta
        candidatos.clear();
        //verificar los candidatos para avanzar en la ruta
        for (int vecino=0; vecino<N; vecino++) {
            if (matriz[nodoActual][vecino]>0 and !visitados[vecino] and matriz[nodoActual][vecino]<=tanque) {
                candidatos.push_back({vecino});
            }
        }

        int mejorCosto=INT_MIN,mejorCandidato=INT_MIN;
        for (int m=0;m<candidatos.size();m++) {
            int costo=matriz[nodoActual][candidatos[m]];
            if (costo>mejorCosto) {
                mejorCosto=costo;
                mejorCandidato=candidatos[m];
            }
        }
        if (candidatos.empty()) {
            cout<<"No hay solucion "<<endl;
            break;
        }

        nodoActual=mejorCandidato;
        tanque=tanque-mejorCosto;
        ruta.push_back(nodoActual);
        visitados[nodoActual]=true;
        if (tienegrifo[nodoActual]) tanque=CAP_MAXIMA;
    }

    for (int n=0;n<ruta.size();n++) {
        cout<<ruta[n]<<" ";
    }
    cout<<endl;
}

int main(int argc, char **argv) {
    int matrizAdyacencia1[N][N]={
        {0,4,7,5,0},
        {4,0,3,0,6},
        {7,3,0,4,7},
        {5,0,4,0,3},
        {0,6,7,3,0},
    };

    int matrizAdyacencia2[M][M]={
        {0,4,8,5,0,0},
        {4,0,3,2,6,0},
        {8,3,0,4,7,0},
        {5,2,4,0,3,4},
        {0,6,7,3,0,9},
        {0,0,0,4,9,0}
    };

    algoritmoVoraz(matrizAdyacencia1,0,N-1);
    return 0;
}

