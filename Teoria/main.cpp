#include <iostream>
using namespace std;

int mochilaback(int *arreglo,int n,int pos,int peso) {
    if (pos==n or peso<0) return 0;
    if (arreglo[pos]==peso) return 1;
    if (mochilaback(arreglo,n,pos+1,peso-arreglo[pos])) return 1;
    else
        return mochilaback(arreglo,n,pos+1,peso);
}

int main(int argc, char **argv) {
    int arreglo[]={2,1,4,1,12};
    int peso=15;
    int n=sizeof(arreglo)/sizeof(arreglo[0]);
    cout<<mochilaback(arreglo,n,0,peso);
    return 0;
}

