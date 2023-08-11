#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <math.h>

using namespace std;
struct aspersor{
    double posicion;
    double radio;
};

double cubreHasta(aspersor aspersor,double ancho,double inicio){
    double largoCubre=sqrt(pow((2*aspersor.radio),2) - pow(ancho,2));
    double pos=aspersor.posicion;
    return pos + (largoCubre/2.0);
}

bool cubreMejor(aspersor mejor,aspersor aspersor,double ancho,double inicio){

    double largoCubre=sqrt(pow((2*aspersor.radio),2) - pow(ancho,2));
    double pos=aspersor.posicion;
    double inicio2=pos - (largoCubre/2.0);

    double h=cubreHasta(aspersor,ancho,inicio);
    double d;
    if(mejor.radio==0){
        d=0;
    }else{
        d=cubreHasta(mejor,ancho,inicio);
    }
    if(inicio2 <= inicio && h>d){
        return true;
    }else{
        return false;
    }
}



int fgolosa(vector<aspersor> aspersores, double largo, double ancho ){
    //Hacer una función que agarre el aspersor que este más lejos posible del inicio
    //tal que cubra el inicio
    int c=0;
    double inicio=0.0;
    int j=0;
    if(largo==0.0){
        return 0;
    }
    vector<aspersor> soluciones={};
    aspersor mejor;
    aspersor mejorAnt=mejor;
    mejorAnt.posicion=0;
    mejorAnt.radio=0;
    if(aspersores.size()==0){
        return -1;
    }else{
        mejor.posicion=-1;
        mejor.radio=0;
        while(inicio < largo && (mejor.posicion!=mejorAnt.posicion || mejor.radio!=mejorAnt.radio)){
            mejorAnt.posicion=mejor.posicion;
            mejorAnt.radio=mejor.radio;
            
            for(int i=0;i<aspersores.size();i++){

                if(cubreMejor(mejor,aspersores[i],ancho,inicio)){
                    mejor=aspersores[i];
                }
            }
            if(mejor.posicion==-1 && mejor.radio==0){
                inicio=0.0;
            }else{
                inicio=cubreHasta(mejor,ancho,inicio);  
            }
            c++;
            j++;      
        }

        if(inicio < largo){
            return -1;
        }else{
            return c;
        }
    }
    
}



int main() {
    
    int n; // cantidad de SPERSORES
    double l; // largo
    double m; // ancho 
    double p=0; //posicion
    double r=0; //radio
    
    int cont=0;
    while(scanf("%d %le %le",&n,&l,&m)==3){
       cont++;
        vector<aspersor> aspersores;
        for(int i=0;i<n;i++){
            cin >> p ;
            cin >> r ;
            aspersor aspersor;
            aspersor.posicion = p;
            aspersor.radio=r;
            // aca ya descarto cualquier aspersor que no cubra minimamente el ancho
            if(r*2 >= m){
                aspersores.push_back(aspersor);
            }
            
            
        }
        int r=fgolosa(aspersores,l,m);
        cout <<r<< endl;
    }

    return 0;
}
