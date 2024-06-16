#ifndef Machine_H
#define Machine_H

#include<iostream>

using namespace std;

class Machine{

    private:
        int Pos_Maquina = 0;
        int fichas_Maquina = 0;
        
    public:
        Machine();
        virtual ~Machine();

        void SetFicha(int ficha);
        int MoverMaquina();

    protected:

};

#endif
