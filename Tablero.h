#ifndef Tablero_H
#define Tablero_H

#include<iostream>
#include"Player.h"
#include"Player.cpp"
#include"Machine.h"
#include"Machine.cpp"
#include<iomanip>
#include<ctime>
#include<unistd.h>

using namespace std;

class Tablero{

    private:
        string matriz[7][7];
        int cantidad_de_fichas = 18;
        int contador = 0;
        int contador_J= 0;
        int contador_M = 0; 
        bool turno;
        

    public:
        Tablero();
        virtual ~Tablero();

        void Maquina();
        void Jugador();
        void Inicio_de_partida();
        void Visualizar_Matriz();
        void Verificar_Movimiento();
        void Actualizar_Matriz();
        void Ganador();

    protected:

};

#endif
