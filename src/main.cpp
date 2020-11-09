//librerias
#include "../include/lib.h"

//variables a utilizar
int tamTablero;
float probTablero;
int cantGeneracion;
int ayuda;
float n_random;
int vivas;


int main(int argc,char *argv[]){
  srand(time(NULL));
  
  tamTablero=obtener_parametro(argv,argc,"-T");
  probTablero=obtener_parametro(argv,argc,"-P");
  cantGeneracion=obtener_parametro(argv,argc,"-G");
  ayuda=obtener_parametro(argv, argc, "-h");
 
  if(ayuda==1){
    cout<<"Parametros:\n"
									"\t-T   : Tamaño del tablero.\n"
									"\t-P   : Probabilidad inicial de que una celula esté viva.\n"
									"\t-G   : Cantidad de iteraciones.\n"
									"\t[-h] : muestra la ayuda de uso y termina.\n";
  }
  else if(probTablero<0 || probTablero>1){
    cout<<"\nProbabilidad no válida";
  }
  else if(cantGeneracion<0){
    cout<<"Las generacion no pueden ser negativas"<<endl;
  }
  else if(tamTablero<1){
    cout<<"Tamaño de tablero no válido"<<endl;
  }
  

  else{
    cout<<tamTablero<<":"<<probTablero<<":"<<cantGeneracion<<"\n";
    int matriz[tamTablero][maxCol];
    int matriz_aux[tamTablero][maxCol];
    int matriz_aux2[tamTablero][maxCol];
    limpiarMatriz(matriz,tamTablero);
    limpiarMatriz(matriz_aux, tamTablero);
    limpiarMatriz(matriz_aux2, tamTablero);
    for(int i=0;i<tamTablero;i++){
      for(int j=0;j<tamTablero;j++){       
        n_random = (float)rand()/RAND_MAX;
        if(n_random<=probTablero){
          matriz[i][j]=1;
        }      
    } 
    }
 
    cout<<"Generacion 1 "<<endl;// se considera la primera generacion como la matriz que contiene los numeros generados randomicamente
    imprimirMatriz(matriz,tamTablero);
    usleep(750000);
    automata(1, matriz, cantGeneracion,tamTablero, matriz_aux, 0,matriz_aux2);
  }
  
return 0;
}