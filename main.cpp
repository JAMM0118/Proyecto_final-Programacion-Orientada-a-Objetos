#include<iostream>
#include"Tablero.h"
#include"Tablero.cpp"

using namespace std;

int main(){
    Tablero Prueba;
    
    Prueba.Visualizar_Matriz();
    Prueba.Inicio_de_partida();
    Prueba.Verificar_Movimiento();
    
    return 0;
}