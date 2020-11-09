
#include "../include/lib.h"

float obtener_parametro(char *argv[] ,int argc,string parametro){
  for(int i=0;i<argc;i++){
    if(parametro.compare(argv[i])==0){
      if(parametro.compare("-P")==0){
        return (float)strtod(argv[i+1],NULL);
      }
      else if(parametro.compare("-h")==0){
      return 1;
    }
      return atoi(argv[i+1]);      
    }
    
  }
  return 0;
}
void imprimirMatriz(int matriz[][maxCol],int tamTablero){
  for(int i=0;i<tamTablero;i++){//se imprime la matriz
    for(int j=0;j<tamTablero;j++){
      if(matriz[i][j]==1){
		  
        cout<<"\033[1;31m■"<<" ";
      }
      else{
		  cout<<"\033[1;37m■"<<" ";
      }   
  } 
  cout<<"\n";
}
cout<<"\n"<<"\n";
}
void automata(int generacion, int matriz[][maxCol],int cantGeneracion,int tamTablero,int matriz_aux[][maxCol],int aux,int matriz_aux2[][maxCol]){
  if(generacion<cantGeneracion){
      for(int i=0;i<tamTablero;i++){
        for(int j=0;j<tamTablero;j++){
          if(matriz_aux[i][j]==1){
            matriz_aux2[i][j]=matriz_aux[i][j];
            continue;
          }
           if (i == 0 && j == 0) {//esquina superior izquierda
						if (matriz[tamTablero - 1][tamTablero - 1])aux++;
						if (matriz[tamTablero - 1][j])aux++;
						if (matriz[i][tamTablero - 1])aux++;
						if (matriz[i][j + 1])aux++;
						if (matriz[i + 1][tamTablero - 1])aux++;
						if (matriz[i + 1][j])aux++;
            if (matriz[tamTablero - 1][j + 1])aux++;
						if (matriz[i + 1][j + 1])aux++;
					} else if (i == 0 && j == tamTablero - 1) {//esquina superior derecha
						if (matriz[tamTablero - 1][j - 1])aux++;
						if (matriz[tamTablero - 1][j])aux++;
						if (matriz[tamTablero - 1][0])aux++;
						if (matriz[i][j - 1])aux++;
						if (matriz[i][0])aux++;
						if (matriz[i + 1][j - 1])aux++;
						if (matriz[i + 1][j])aux++;
						if (matriz[i + 1][0])aux++;
					} else if (i == tamTablero - 1 && j == 0) {//esquina inferior izquierda
						if (matriz[i - 1][tamTablero - 1])aux++;
						if (matriz[i - 1][j])aux++;
						if (matriz[i - 1][j + 1])aux++;
						if (matriz[i][tamTablero - 1])aux++;
						if (matriz[i][j + 1])aux++;
						if (matriz[0][tamTablero - 1])aux++;
						if (matriz[0][j])aux++;
						if (matriz[0][j + 1])aux++;
					} else if (i == tamTablero - 1 && j == tamTablero - 1) {//esqiuna inferior derecha
						if (matriz[i - 1][j - 1])aux++;
						if (matriz[i - 1][j])aux++;
						if (matriz[i - 1][0])aux++;
						if (matriz[i][j - 1])aux++;
						if (matriz[i][0])aux++;
						if (matriz[0][j - 1])aux++;
						if (matriz[0][j])aux++;
						if (matriz[0][0])aux++;
					} else if (i == 0 && j != tamTablero - 1 && j != 0) {//borde superior
						if (matriz[tamTablero - 1][j - 1])aux++;
						if (matriz[tamTablero - 1][j])aux++;
						if (matriz[tamTablero - 1][j + 1])aux++;
						if (matriz[i][j - 1])aux++;
						if (matriz[i][j + 1])aux++;
						if (matriz[i + 1][j - 1])aux++;
						if (matriz[i + 1][j])aux++;
						if (matriz[i + 1][j + 1])aux++;
					} else if (i == tamTablero - 1 && j != tamTablero - 1 && j != 0) {//borde inferior
						if (matriz[i - 1][j - 1])aux++;
						if (matriz[i - 1][j])aux++;
						if (matriz[i - 1][j + 1])aux++;
						if (matriz[i][j - 1])aux++;
						if (matriz[i][j + 1])aux++;
						if (matriz[0][j - 1])aux++;
						if (matriz[0][j])aux++;
						if (matriz[0][j + 1])aux++;
					} else if (i != tamTablero - 1 && i != 0 && j == 0) {//borde izquierdo
						if (matriz[i - 1][tamTablero - 1])aux++;
						if (matriz[i - 1][j])aux++;
						if (matriz[i - 1][j + 1])aux++;
						if (matriz[i][tamTablero - 1])aux++;
						if (matriz[i][j + 1])aux++;
						if (matriz[i + 1][tamTablero - 1])aux++;
						if (matriz[i + 1][j])aux++;
						if (matriz[i + 1][j + 1])aux++;
					} else if (i != tamTablero - 1 && i != 0 && j == tamTablero - 1) {// borde derecho
						if (matriz[i - 1][j - 1])aux++;
						if (matriz[i - 1][j])aux++;
						if (matriz[i - 1][0])aux++;
						if (matriz[i][j - 1])aux++;
						if (matriz[i][0])aux++;
						if (matriz[i + 1][j - 1])aux++;
						if (matriz[i + 1][j])aux++;
						if (matriz[i + 1][0])aux++;
					} else {//todo lo que este en el centro del trablero sin incluir los bordes ni esquinas
						if (matriz[i - 1][j - 1])aux++;
						if (matriz[i - 1][j])aux++;
						if (matriz[i - 1][j + 1])aux++;
						if (matriz[i][j - 1])aux++;
						if (matriz[i][j + 1])aux++;
						if (matriz[i + 1][j - 1])aux++;
						if (matriz[i + 1][j])aux++;
						if (matriz[i + 1][j + 1])aux++;
					}      
        if((aux<2 || aux>3)&& matriz[i][j]==1){
          matriz_aux2[i][j]=0;
        }
        else if((aux>=2 && aux<=3) && matriz[i][j]==1){
          matriz_aux[i][j]=1;
        }
        else if(aux==3 && matriz[i][j]==0){
          matriz_aux2[i][j]=1;
        }
       aux=0;
        }        
        }
        for(int i =0;i<tamTablero;i++){// crear funcion que deje la matriz llena de 0
         for(int j =0;j<tamTablero;j++){
          if(matriz_aux2[i][j]==0 && matriz_aux[i][j]==1){
            matriz_aux2[i][j]=1;
            matriz_aux[i][j]=0;
          }
        } 
        }
        for(int i =0;i<tamTablero;i++){
         for(int j =0;j<tamTablero;j++){
          matriz[i][j]=matriz_aux2[i][j];
          }
        }
        limpiarMatriz(matriz_aux, tamTablero);
        limpiarMatriz(matriz_aux2, tamTablero);
        system("clear"); //para ver todas las generaciones comente esta linea
        cout<<"Generacion "<<generacion+1<<endl;
        imprimirMatriz(matriz,tamTablero);
        
       usleep(750000);
      generacion=generacion+1;
    automata(generacion, matriz, cantGeneracion, tamTablero, matriz_aux, aux,matriz_aux2);
      }    
  }
  void limpiarMatriz(int matriz[][maxCol],int tamTablero){
    for(int i=0;i<tamTablero;i++){
      for(int j=0;j<tamTablero;j++){
        matriz[i][j]=0;
    }
    }
  }
