#include <iostream>
#include <unistd.h>
using namespace std;
const int maxCol=1000;//se define un limite para las columnas, ya que el lenguaje lo requiere, se,podria llegar a cambiar si se quiere

void imprimirMatriz(int matriz[][maxCol],int tamTablero);

float obtener_parametro(char *argv[] ,int argc, string parametro);

void automata(int cont, int matriz[][maxCol],int cantGeneracion,int tamTablero,int matriz_aux[][maxCol],int aux,int matriz_aux2[][maxCol]);
void limpiarMatriz(int matriz[][maxCol],int tamTablero);