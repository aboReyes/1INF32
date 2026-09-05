

#include <iostream>
using namespace std;



bool validarX(int x,int s) {
    return (x<=s);
}

bool validarY(int y,int s) {
    return (y<=s);
}

bool validarZ(int z,int s) {
    return (z<=s);
}

bool validarOpcionS(int x,int y,int z,int s) {
    return (s==x+y+z and x!=0 and y!=0 and z!=0
            and x!=y and x!=z and y!=z
            and validarX(x,s) and validarY(y,s) and validarZ(z,s));
}

void imprimirResultado(int x,int y,int z) {
    cout<<x<<" "<<y<<" "<<z<<endl;
}

int buscarContraseña(int x,int y,int z,int s) {
    // cout<<"Intento"<<endl;
    // imprimirResultado(x,y,z);
    if (validarX(x,s)) {
        if (validarY(y,s)) {
            if (validarZ(z,s)) {
                if (validarOpcionS(x,y,z,s)) {
                    cout<<"Opcion valida"<<endl;
                    imprimirResultado(x,y,z);
                }
                return buscarContraseña(x,y,z+1,s);
            }else {
                return buscarContraseña(x,y+1,1,s);
            }
        }else {
            return buscarContraseña(x+1,1,1,s);
        }
    }
    return 0;
}



int main(int argc, char **argv) {
    int s=8;
    buscarContraseña(1,1,1,s);
    return 0;
}

