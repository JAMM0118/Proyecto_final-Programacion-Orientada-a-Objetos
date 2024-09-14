#ifndef MACHINE_H
#define MACHINE_H


#include<iostream>
#include"player.h"

#include"Machine2.h"
#include<unistd.h>
using namespace std;

class Machine{
    public:

        Machine();
        virtual ~Machine();

        void SetFicha(int ficha);
        int PonerMaquina();
        int Get_Ficha_maquina_y();
        int Get_disponible_maquina_X();
        int Get_Ficha_maquina_X();
        int Get_disponible_maquina_y();
        void Set_Ficha_maquina_y(int&);
        void Set_Ficha_maquina_X(int&);
        void Set_disponible_maquina_X(int&);
        void Set_disponible_maquina_y(int&);
        void jugada_maquina(string n[7][7]);
        void verificar_posiciones(string m[7][7],string n[24]);
        void set_contadore(int);
        void eliminar(string m[7][7],string b[7][7],int&,int&,int&,int&,string disponibles[24]);
        void mandar_datos(int &k, int &Posicion);
        void set_salvador(int);
        void jugada_libre(string matriz[7][7], string matriz2[7][7],string disponibles[24]);
        bool complemento_de_eliminar(int&,int&,string m[7][7]);


        int fichas_maquina_x[9]= { 256, 256, 256, 256, 256, 256, 256, 256, 256};
        int fichas_maquina_y[9]= { 256, 256, 256, 256, 256, 256, 256, 256, 256 };
        int fichas_Maquina = 0;

    protected:

    private:

        int salvador = 0;
        int salvatore = 0;
        int Ficha_maquina_X=0;
        int Ficha_maquina_y=0;
        int disponible_maquina_X=0;
        int disponible_maquina_y=0;
        int disponibles_pos_maquina_X[22]= { 256, 256, 256, 256, 256, 256, 256, 256, 256,
        256, 256, 256, 256, 256, 256, 256, 256, 256,256, 256, 256, 256 };
        int disponibles_pos_maquina_y[22] = { 256, 256, 256, 256, 256, 256, 256, 256, 256,
        256, 256, 256, 256, 256, 256, 256, 256, 256,256, 256, 256, 256 };
        int contador_posiciones_libres=0;
        int contador_posiciones_fichas_maquina=0;
        int Pos_Maquina = 0;
        int contadore = 0;

};

#endif
