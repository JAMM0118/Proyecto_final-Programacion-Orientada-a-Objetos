#include"Machine.h"

Machine :: Machine(){}
Machine :: ~Machine(){}

int Machine :: MoverMaquina(){
    srand(time(NULL));
    Pos_Maquina = 1 + rand()%(24);
    return Pos_Maquina;

}

void Machine :: SetFicha(int ficha){
    fichas_Maquina = ficha;
}
