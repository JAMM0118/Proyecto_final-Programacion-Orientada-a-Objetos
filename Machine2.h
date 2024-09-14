#ifndef MACHINE2_H
#define MACHINE2_H


#include<iostream>
#include"Machine.h"
#include<unistd.h>
using namespace std;

class Machine2{
    public:

        Machine2();
        virtual ~Machine2();

        void SetFicha2(int ficha);
        int PonerMaquina2();
        int Get_Ficha_maquina_y2();
        int Get_disponible_maquina_X2();
        int Get_Ficha_maquina_X2();
        int Get_disponible_maquina_y2();
        void Set_Ficha_maquina_y2(int&);
        void Set_Ficha_maquina_X2(int&);
        void Set_disponible_maquina_X2(int&);
        void Set_disponible_maquina_y2(int&);
        void jugada_maquina2(string n[7][7]);
        void verificar_posiciones2(string m[7][7],string n[24]);
        void set_contadore2(int);
        void eliminar2(string m[7][7],string b[7][7],int&,int&,int&,string disponibles[24]);
        void mandar_datos2(int &k, int &Posicion);
        void set_salvador2(int);
        void jugada_libre2(string matriz[7][7], string matriz2[7][7],string disponibles[24]);

        
        int fichas_maquina_x2[9]= { 256, 256, 256, 256, 256, 256, 256, 256, 256};
        int fichas_maquina_y2[9]= { 256, 256, 256, 256, 256, 256, 256, 256, 256 };
        int fichas_Maquina2 = 0;

    protected:

    private:
        
        int salvador2 = 0;
        int salvatore2 = 0;
        int Ficha_maquina_X2=0;
        int Ficha_maquina_y2=0;
        int disponible_maquina_X2=0;
        int disponible_maquina_y2=0;
        int disponibles_pos_maquina_X2[22]= { 256, 256, 256, 256, 256, 256, 256, 256, 256,
        256, 256, 256, 256, 256, 256, 256, 256, 256,256, 256, 256, 256 };
        int disponibles_pos_maquina_y2[22] = { 256, 256, 256, 256, 256, 256, 256, 256, 256,
        256, 256, 256, 256, 256, 256, 256, 256, 256,256, 256, 256, 256 };
        int contador_posiciones_libres2=0;
        int contador_posiciones_fichas_maquina2=0;
        int Pos_Maquina2 = 0;
        int contadore2 = 0;

};

#endif