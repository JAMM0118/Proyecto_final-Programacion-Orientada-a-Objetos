#include"Player.h"

Player :: Player(){}
Player :: ~Player(){}

void Player :: Setfichas(int _fichas){
    fichas = _fichas;
}

int Player:: Getfichas(){
    return fichas;
}

int Player :: MoverFichas(){
    cout<<"Player 1 ¿en que posicion deseas jugar?"<<endl;
    cout<<"Seleccion un numero: "; cin>>PosicionP1;
    return PosicionP1; 
}