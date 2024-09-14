#ifndef Player_H
#define Player_H

#include<windows.h>
#include<iostream>
#include"Machine.h"
#include<unistd.h>
#include"Player2.h"

using namespace std;

class Player{
    public:

        Player();
        virtual ~Player();

        void Setfichas(int _fichas);
        int Getfichas();
        int PonerFichas();
        string MoverFichas();
        string complemento_mover_fichas();
        void verificar_disponibles(string m[7][7],string n[24]);
        void posibles_jugadas(string mat[7][7]);
        void evitar_repeticion(string matriz[7][7],int &k,int &z);
        void eliminar(string m[7][7],string b[7][7],int&,int&,int&,int&,string disponibles[24]);
        void jugada_libre(string m[7][7], string z2[7][7],string s[24],int&,int&);
        bool complemento_de_eliminar(int&,int&,string m[7][7]);

        int fichas_posX[9]= { 256, 256, 256, 256, 256, 256, 256, 256, 256 };
        int fichas_posy[9]= { 256, 256, 256, 256, 256, 256, 256, 256, 256 };
        int fichas = 0;
       
        

    protected:

    private:
        int disponibles_posX[22]= {256, 256, 256, 256, 256, 256, 256, 256, 256,
        256, 256, 256, 256, 256, 256, 256, 256, 256,256, 256, 256, 256};
        int disponibles_posy[22] = {256, 256, 256, 256, 256, 256, 256, 256, 256,
        256, 256, 256, 256, 256, 256, 256, 256, 256,256, 256, 256, 256 };
        int contador_posiciones_disponibles=0;
        int contador_posiciones_fichas=0;
        int PosicionP1 = 0;
        string repite = "";
        string noRepite1[100] = { " " };
        int contador = 0;
};

#endif