#ifndef Player_H
#define Player_H

#include<iostream>

using namespace std;

class Player{

    private:
        int PosicionP1 = 0;
        int fichas = 0;
        
    public:
        Player();
        virtual ~Player();
        
        void Setfichas(int _fichas);
        int Getfichas();
        int MoverFichas();
        
    protected:
        
};

#endif