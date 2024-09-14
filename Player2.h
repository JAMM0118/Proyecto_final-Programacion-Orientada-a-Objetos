#ifndef Player2_H
#define Player2_H

#include<windows.h>
#include<iostream>
#include"Player.h"
#include<unistd.h>

using namespace std;

class Player2{
    public:

        Player2();
        virtual ~Player2();

        void Setfichas2(int _fichas);
        int Getfichas2();
        int PonerFichas2();
        string MoverFichas2();
        string complemento_mover_fichas2();
        void verificar_disponibles2(string m[7][7],string n[24]);
        void posibles_jugadas2(string mat[7][7]);
        void evitar_repeticion2(string matriz[7][7],int &k,int &z);
        void eliminar2(string m[7][7],string b[7][7],int&,int&,int&,string disponibles[24]);
        void jugada_libre2(string m[7][7], string z2[7][7],string s[24],int&,int&);
        
        int fichas_posX2[9]= { 256, 256, 256, 256, 256, 256, 256, 256, 256 };
        int fichas_posy2[9]= { 256, 256, 256, 256, 256, 256, 256, 256, 256 };
        int fichas2 = 0;
    
    protected:

    private:
        int disponibles_posX2[22]= { 256, 256, 256, 256, 256, 256, 256, 256, 256,
        256, 256, 256, 256, 256, 256, 256, 256, 256,256, 256, 256, 256 };
        int disponibles_posy2[22] = { 256, 256, 256, 256, 256, 256, 256, 256, 256,
        256, 256, 256, 256, 256, 256, 256, 256, 256,256, 256, 256, 256 };
        int contador_posiciones_disponibles2=0;
        int contador_posiciones_fichas2=0;
        int PosicionP2 = 0;
        string repite2 = "";
        string noRepite2[100] = { " " };
        int contador2 = 0;
};

#endif