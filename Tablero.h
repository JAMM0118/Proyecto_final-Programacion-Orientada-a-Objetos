#ifndef TABLERO_H
#define TABLERO_H

#include<windows.h>
#include<stdlib.h>
#include<iostream>
#include"Player.h"
#include"Machine.h"
#include"Player2.h"
#include"Machine2.h"
#include<iomanip>
#include<unistd.h>

#define color(c) SetConsoleTextAttribute(GetStdHandle( STD_OUTPUT_HANDLE),c);

using namespace std;

class Tablero{
    public:

        Tablero();
        virtual ~Tablero();

        void Maquina();
        void Jugador();
        void Maquina2();
        void Jugador2();
        void Inicio_de_partida();
        void Visualizar_Matriz();
        void Verificar_Movimiento_Jugador_1();
        void verificar_movimiento_maquina_1();
        void Verificar_Movimiento_Jugador_2();
        void verificar_movimiento_maquina_2();
        void Actualizar_Matriz();
        void partida();
        void Ganador();
        void eliminar_ficha();
        void menu();
        void instruciones();
        void modos_juego();

    protected:

    private:
        int contador = 1;
        int contador2 = 1;
        int opcion;
        string matriz[7][7];
        string matriz2[7][7] = { " " };
        string disponibles[24] = {"1","2","3","4","5","6","7","8","9","10","11","12","13","14",
        "15","16","17","18","19","20","21","22","23","24"};
        int cantidad_de_fichas = 18;
        int contador_J= 0;
        int contador_M = 0;
        int contador_J2= 0;
        int contador_M2 = 0;
        int j1_x = 0;
        int j1_y = 0;
        int j2_x = 0;
        int j2_y = 0;
        int m1_x = 0;
        int m1_y = 0;
        int m2_x = 0;
        int m2_y = 0;
        bool turno_libre= false;
        int ayuda_j1 =0;
        int ayuda_j2 =0;
};

#endif
