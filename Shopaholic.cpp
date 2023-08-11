#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct actividades {
    int inicio;
    int fin;
    int ordenOriginal;
};

int maxi(vector<actividades> &vActs, int quemax){
    int maximo = 0;
    if(quemax == 1){
        for(int i =0 ; i < vActs.size(); i++){
            if (maximo < vActs[i].inicio){
                maximo = vActs[i].inicio;
            }
        }
    }
    if(quemax == 2){
        for(int i =0 ; i < vActs.size(); i++){
            if (maximo < vActs[i].fin){
                maximo = vActs[i].fin;
            }
        }
}
return maximo;
}

void sort(vector<actividades> &vActs, int queOrdeno){
    if(queOrdeno == 1){
        int maxo = maxi(vActs,1);
        vector<vector<actividades>> vOrdenado (maxo+1);
        for(int i = 0; i < vActs.size(); i++){
            vOrdenado[vActs[i].inicio].push_back(vActs[i]);
        }
        int k = 0;
        for(int i = 0; i < vOrdenado.size(); i++){
            for(int j = 0; j < vOrdenado[i].size(); j++){
                vActs[k]=vOrdenado[i][j];
                k++;
            }
        }
    }
    if(queOrdeno==2){
        int maxo = maxi(vActs,2);
        vector<vector<actividades>> vOrdenado (maxo+1);
        for(int i = 0; i < vActs.size(); i++){
            vOrdenado[vActs[i].fin].push_back(vActs[i]);
        }
        int k = 0;
        for(int i = 0; i < vOrdenado.size(); i++){
            for(int j = 0; j < vOrdenado[i].size(); j++){
                vActs[k]=vOrdenado[i][j];
                k++;
            }
        }
    }
}

vector<int> greedy(vector<actividades> &vActs){
    //Asumimos orden
    vector<int> res;
    res.push_back(vActs[0].ordenOriginal);
    int i = 0;
    int j = 0;
    while(j<vActs.size()){
        if(vActs[i].fin > vActs[j].inicio){
            j++;
        } else {
            res.push_back(vActs[j].ordenOriginal);
            i = j;
        }
    }
    return res;
}

void printVector(std::vector<int> const &input)
{
    for (int i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}

int main(){
    int cantAct;
    cin >> cantAct;
    vector<actividades> vActs;
    actividades act;
    for(int i=0; i< cantAct; i++){
        cin >> act.inicio >> act.fin;
        act.ordenOriginal = i+1;
        vActs.push_back(act);
    }
    //TODO:Hacer radix
    sort(vActs,2);
    //Ordenar el vector con radix para que este ordenado como mas fuerte el primer elemento
    //y si hay empate de este, ordena por el segundo
    vector<int> resGreedy = greedy(vActs);
    cout << resGreedy.size() << endl;
    printVector(resGreedy);
}
