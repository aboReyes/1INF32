#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

struct Tarea {
    char tarea;
    double tiempoProcesamiento;
    double peso;
    double ratio;
    double completionTime;
    double costoPonderado;
};

void mostrarResultado(vector<Tarea>candidatos,double costoTotalPonderado) {
    cout<<"========================================"<<endl;
    cout<<"ORDENAMIENTO FINAL SEGUN REGLA DE SMITH"<<endl;
    cout<<"========================================"<<endl;
    cout<<fixed<<setprecision(2);
    for(int i=0;i<candidatos.size();i++) {
        cout<<"Tarea: "<<setw(4)<<right<<candidatos[i].tarea<<endl;
        cout<<"Tiempo procesamiento: "<<candidatos[i].tiempoProcesamiento<<endl;
        cout<<"Peso: "<<candidatos[i].peso<<endl;
        cout<<"Ratio: "<<candidatos[i].ratio<<endl;
        cout<<"Completion time: "<<candidatos[i].completionTime<<endl;
        cout<<"Costo ponderado: "<<candidatos[i].costoPonderado<<endl;
        cout<<"--------------------------------------"<<endl;
    }
    cout<<"COSTO TOTAL PONDERADO: "<<setw(4)<<right<<costoTotalPonderado<<endl;
}

bool reasignar(Tarea nuevo,Tarea existente) {
    //que el ratio nuevo > ratio existente
    //si los ratios son iguales entonces validamos el tiempo de procesamiento del nuevo sea menor que el existente
    return nuevo.ratio > existente.ratio ||
        (nuevo.ratio == existente.ratio &&
            nuevo.tiempoProcesamiento < existente.tiempoProcesamiento);
}


void scheduling(vector<Tarea>tareas,int n) {
    vector<Tarea> candidatos;

    for (int i=0;i<n;i++) {
        tareas[i].ratio=tareas[i].peso/tareas[i].tiempoProcesamiento;
        if (candidatos.empty()) candidatos.push_back(tareas[i]);
        else {
            int pos=candidatos.size();
            while (pos>0 and reasignar(tareas[i],candidatos[pos-1])) {
                pos--;
            }
            candidatos.insert(candidatos.begin()+pos,tareas[i]);
        }
    }
    double tiempoacum=0;
    double costototalPonderado=0;
    for (int j=0;j<n;j++) {
        tiempoacum+=candidatos[j].tiempoProcesamiento;
        candidatos[j].completionTime=tiempoacum;
        candidatos[j].costoPonderado=candidatos[j].peso*tiempoacum;
        costototalPonderado+=candidatos[j].costoPonderado;
    }
    mostrarResultado(candidatos,costototalPonderado);
}




int main(int argc, char **argv) {
    vector<Tarea> tareas={
        {'A',4,20},
        {'B',2,10},
        {'C',5,15},
        {'D',3,18},
    };

    int n=tareas.size();
    cout<<n<<endl;

    scheduling(tareas,n);
    return 0;
}

