#include "Player.h"

Player::Player(){}

Player::~Player(){}

void Player :: Setfichas(int _fichas){
    fichas = _fichas;
}

int Player:: Getfichas(){
    return fichas;
}

int Player :: PonerFichas(){
    cout<<"Player 1 ¿En que posicion deseas jugar?"<<endl;
    cout<<"Seleccione un numero: "; cin>>PosicionP1;
    return PosicionP1;
}

string Player :: complemento_mover_fichas(){
    cout<<"Digite la posicion en que desea mover esta ficha: "; cin>>PosicionP1;
    return to_string(PosicionP1);
}
string Player :: MoverFichas(){
    string posicion_nueva;
    cout<<"Player 1 ¿Que ficha deseas mover? : ";cin>>posicion_nueva;
    return posicion_nueva ;
}

void Player:: verificar_disponibles(string matriz[7][7],string disponibles[24]){
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            if((matriz[i][j] != "O") && (matriz[i][j] != "*")&&(matriz[i][j] != "P1") &&(matriz[i][j] != "P5")
            &&(matriz[i][j] != "P2")&&(matriz[i][j] != "P3")&&(matriz[i][j] != "P4")&&(matriz[i][j] != "P6")
            &&(matriz[i][j] != "P7")&&(matriz[i][j] != "P8")&&(matriz[i][j] != "P9")){
                bool val = false;
                for(int d=0; d<24;d++){
                    if(disponibles[d] != " "){
                        if(matriz[i][j] != disponibles[d]){val = true;}
                        else{val = false;break;}
                    }
                }

                if(val == true){
                    fichas_posX[contador_posiciones_fichas]= i;
                    fichas_posy[contador_posiciones_fichas] = j;
                    contador_posiciones_fichas++;
                }
            }
            for(int l=0; l<24;l++){
                if(matriz[i][j] == disponibles[l]){
                    disponibles_posX[contador_posiciones_disponibles] = i;
                    disponibles_posy[contador_posiciones_disponibles] = j;
                    contador_posiciones_disponibles++;
                }
            }
        }
    }
}

void Player :: posibles_jugadas(string matriz[7][7]){
    for(int i=0; i<7;i++){
        for(int j=0; j<7;j++){
            if(i==0){
                for(int z=0; z<22;z++){
                    if((disponibles_posX[z] == 0) || (disponibles_posX[z] == 3)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy[k] == 0) ){
                                if((fichas_posX[k] ==0)){
                                    if(((fichas_posX[k]-disponibles_posX[z] == 0)
                                    || (fichas_posX[k]-disponibles_posX[z] == -3) )&&
                                    ((fichas_posy[k]-disponibles_posy[z] == 0)
                                    || (fichas_posy[k]-disponibles_posy[z] == -3))){
                                        evitar_repeticion(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }
                    if((disponibles_posX[z] == 0) || (disponibles_posX[z] == 1)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy[k] == 3) ){
                                if((fichas_posX[k] ==0)){
                                    if(((fichas_posX[k]-disponibles_posX[z] == 0)
                                    || (fichas_posX[k]-disponibles_posX[z] == -1) )&&
                                    ((fichas_posy[k]-disponibles_posy[z] == 0)
                                    || (fichas_posy[k]-disponibles_posy[z] == -3)
                                    || (fichas_posy[k]-disponibles_posy[z] == 3))){
                                        evitar_repeticion(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }
                    if((disponibles_posX[z] == 0) || (disponibles_posX[z] == 3)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy[k] == 6) ){
                                if((fichas_posX[k] ==0)){
                                    if(((fichas_posX[k]-disponibles_posX[z] == 0)
                                    || (fichas_posX[k]-disponibles_posX[z] == -3) )&&
                                    ((fichas_posy[k]-disponibles_posy[z] == 0)
                                    || (fichas_posy[k]-disponibles_posy[z] == 3))){
                                        evitar_repeticion(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }
                }
            }
            else if(i==1){
                for(int z=0; z<22;z++){
                    if((disponibles_posX[z] == 1) || (disponibles_posX[z] == 3)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy[k] == 1) ){
                                if((fichas_posX[k] ==1)){
                                    if(((fichas_posX[k]-disponibles_posX[z] == 0)
                                    || (fichas_posX[k]-disponibles_posX[z] == -2) )&&
                                    ((fichas_posy[k]-disponibles_posy[z] == 0)
                                    || (fichas_posy[k]-disponibles_posy[z] == -2))){
                                        evitar_repeticion(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }
                    if((disponibles_posX[z] == 1) || (disponibles_posX[z] == 2) || (disponibles_posX[z] == 0)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy[k] == 3) ){
                                if((fichas_posX[k] ==1)){
                                    if(((fichas_posX[k]-disponibles_posX[z] == 0)
                                    || (fichas_posX[k]-disponibles_posX[z] == -1)
                                    || (fichas_posX[k]-disponibles_posX[z] == 1) )&&
                                    ((fichas_posy[k]-disponibles_posy[z] == 0)
                                    || (fichas_posy[k]-disponibles_posy[z] == -2)
                                    || (fichas_posy[k]-disponibles_posy[z] == 2))){
                                        evitar_repeticion(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }
                    if((disponibles_posX[z] == 1) || (disponibles_posX[z] == 3)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy[k] == 5) ){
                                if((fichas_posX[k] ==1)){
                                    if(((fichas_posX[k]-disponibles_posX[z] == 0)
                                    || (fichas_posX[k]-disponibles_posX[z] == -2) )&&
                                    ((fichas_posy[k]-disponibles_posy[z] == 0)
                                    || (fichas_posy[k]-disponibles_posy[z] == 2))){
                                        evitar_repeticion(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }
                }
            }else if(i==2){
                for(int z=0; z<22;z++){
                    if((disponibles_posX[z] == 2) || (disponibles_posX[z] == 3)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy[k] == 2) ){
                                if((fichas_posX[k] ==2)){
                                    if(((fichas_posX[k]-disponibles_posX[z] == 0)
                                    || (fichas_posX[k]-disponibles_posX[z] == -1) )&&
                                    ((fichas_posy[k]-disponibles_posy[z] == 0)
                                    || (fichas_posy[k]-disponibles_posy[z] == -1))){
                                        evitar_repeticion(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }
                    if((disponibles_posX[z] == 2) || (disponibles_posX[z] == 1)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy[k] == 3) ){
                                if((fichas_posX[k] ==2)){
                                    if(((fichas_posX[k]-disponibles_posX[z] == 0)
                                    || (fichas_posX[k]-disponibles_posX[z] == 1) )&&
                                    ((fichas_posy[k]-disponibles_posy[z] == 1)
                                    || (fichas_posy[k]-disponibles_posy[z] == -1)
                                    || (fichas_posy[k]-disponibles_posy[z] == 0))){
                                        evitar_repeticion(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }
                    if((disponibles_posX[z] == 2) || (disponibles_posX[z] == 3)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy[k] == 4) ){
                                if((fichas_posX[k] ==2)){
                                    if(((fichas_posX[k]-disponibles_posX[z] == 0)
                                    || (fichas_posX[k]-disponibles_posX[z] == -1) )&&
                                    ((fichas_posy[k]-disponibles_posy[z] == 0)
                                    || (fichas_posy[k]-disponibles_posy[z] == 1))){
                                        evitar_repeticion(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }
                }
            }
            else if(i==3){
                for(int z=0; z<22;z++){
                    if((disponibles_posX[z] == 0) || (disponibles_posX[z] == 3) || (disponibles_posX[z] == 6)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy[k] == 0) ){
                                if((fichas_posX[k] ==3)){
                                    if(((fichas_posX[k]-disponibles_posX[z] == 0)
                                    || (fichas_posX[k]-disponibles_posX[z] == -3)
                                    || (fichas_posX[k]-disponibles_posX[z] == 3) )&&
                                    ((fichas_posy[k]-disponibles_posy[z] == 0)
                                    || (fichas_posy[k]-disponibles_posy[z] == -1))){
                                       evitar_repeticion(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }
                    if((disponibles_posX[z] == 3) || (disponibles_posX[z] == 1)|| (disponibles_posX[z] == 5)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy[k] == 1) ){
                                if((fichas_posX[k] ==3)){
                                    if(((fichas_posX[k]-disponibles_posX[z] == 0)
                                    || (fichas_posX[k]-disponibles_posX[z] == 2)
                                    || (fichas_posX[k]-disponibles_posX[z] == -2) )&&
                                    ((fichas_posy[k]-disponibles_posy[z] == 1)
                                    || (fichas_posy[k]-disponibles_posy[z] == -1)
                                    || (fichas_posy[k]-disponibles_posy[z] == 0))){
                                       evitar_repeticion(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }
                    if((disponibles_posX[z] == 2) || (disponibles_posX[z] == 3)|| (disponibles_posX[z] == 4)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy[k] == 2) ){
                                if((fichas_posX[k] ==3)){
                                    if(((fichas_posX[k]-disponibles_posX[z] == 0)
                                    || (fichas_posX[k]-disponibles_posX[z] == -1)
                                    || (fichas_posX[k]-disponibles_posX[z] == 1) )&&
                                    ((fichas_posy[k]-disponibles_posy[z] == 0)
                                    || (fichas_posy[k]-disponibles_posy[z] == 1))){
                                        evitar_repeticion(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }
                    if((disponibles_posX[z] == 2) || (disponibles_posX[z] == 3)|| (disponibles_posX[z] == 4)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy[k] == 4) ){
                                if((fichas_posX[k] ==3)){
                                    if(((fichas_posX[k]-disponibles_posX[z] == 0)
                                    || (fichas_posX[k]-disponibles_posX[z] == -1)
                                    || (fichas_posX[k]-disponibles_posX[z] == 1) )&&
                                    ((fichas_posy[k]-disponibles_posy[z] == 0)
                                    || (fichas_posy[k]-disponibles_posy[z] == -1))){
                                        evitar_repeticion(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }
                    if((disponibles_posX[z] == 1) || (disponibles_posX[z] == 3)|| (disponibles_posX[z] == 5)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy[k] == 5) ){
                                if((fichas_posX[k] ==3)){
                                    if(((fichas_posX[k]-disponibles_posX[z] == 0)
                                    || (fichas_posX[k]-disponibles_posX[z] == -2)
                                    || (fichas_posX[k]-disponibles_posX[z] == 2) )&&
                                    ((fichas_posy[k]-disponibles_posy[z] == 0)
                                    || (fichas_posy[k]-disponibles_posy[z] == 1)
                                    || (fichas_posy[k]-disponibles_posy[z] == -1))){
                                       evitar_repeticion(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }
                    if((disponibles_posX[z] == 0) || (disponibles_posX[z] == 3)|| (disponibles_posX[z] == 6)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy[k] == 6) ){
                                if((fichas_posX[k] ==3)){
                                    if(((fichas_posX[k]-disponibles_posX[z] == 0)
                                    || (fichas_posX[k]-disponibles_posX[z] == -3)
                                    || (fichas_posX[k]-disponibles_posX[z] == 3) )&&
                                    ((fichas_posy[k]-disponibles_posy[z] == 0)
                                    || (fichas_posy[k]-disponibles_posy[z] == 1))){
                                        evitar_repeticion(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }
                }
            }else if(i==4){
                for(int z=0; z<22;z++){
                    if((disponibles_posX[z] == 4) || (disponibles_posX[z] == 3)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy[k] == 2) ){
                                if((fichas_posX[k] ==4)){
                                    if(((fichas_posX[k]-disponibles_posX[z] == 0)
                                    || (fichas_posX[k]-disponibles_posX[z] == 1) )&&
                                    ((fichas_posy[k]-disponibles_posy[z] == 0)
                                    || (fichas_posy[k]-disponibles_posy[z] == -1))){
                                        evitar_repeticion(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }
                    if((disponibles_posX[z] == 4) || (disponibles_posX[z] == 5)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy[k] == 3) ){
                                if((fichas_posX[k] ==4)){
                                    if(((fichas_posX[k]-disponibles_posX[z] == 0)
                                    || (fichas_posX[k]-disponibles_posX[z] == -1) )&&
                                    ((fichas_posy[k]-disponibles_posy[z] == 1)
                                    || (fichas_posy[k]-disponibles_posy[z] == -1)
                                    || (fichas_posy[k]-disponibles_posy[z] == 0))){
                                        evitar_repeticion(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }
                    if((disponibles_posX[z] == 4) || (disponibles_posX[z] == 3)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy[k] == 4) ){
                                if((fichas_posX[k] ==4)){
                                    if(((fichas_posX[k]-disponibles_posX[z] == 0)
                                    || (fichas_posX[k]-disponibles_posX[z] == 1) )&&
                                    ((fichas_posy[k]-disponibles_posy[z] == 0)
                                    || (fichas_posy[k]-disponibles_posy[z] == 1))){
                                        evitar_repeticion(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }
                }
            }else if(i==5){
                for(int z=0; z<22;z++){
                    if((disponibles_posX[z] == 3) || (disponibles_posX[z] == 5)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy[k] == 1) ){
                                if((fichas_posX[k] ==5)){
                                    if(((fichas_posX[k]-disponibles_posX[z] == 0)
                                    || (fichas_posX[k]-disponibles_posX[z] == 2) )&&
                                    ((fichas_posy[k]-disponibles_posy[z] == 0)
                                    || (fichas_posy[k]-disponibles_posy[z] == -2))){
                                        evitar_repeticion(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }
                    if((disponibles_posX[z] == 5) || (disponibles_posX[z] == 4) || (disponibles_posX[z] == 6)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy[k] == 3) ){
                                if((fichas_posX[k] ==5)){
                                    if(((fichas_posX[k]-disponibles_posX[z] == 0)
                                    || (fichas_posX[k]-disponibles_posX[z] == 1)
                                    || (fichas_posX[k]-disponibles_posX[z] == -1) )&&
                                    ((fichas_posy[k]-disponibles_posy[z] == -2)
                                    || (fichas_posy[k]-disponibles_posy[z] == 0)
                                    || (fichas_posy[k]-disponibles_posy[z] == 2))){
                                        evitar_repeticion(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }
                    if((disponibles_posX[z] == 5) || (disponibles_posX[z] == 3)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy[k] == 5) ){
                                if((fichas_posX[k] ==5)){
                                    if(((fichas_posX[k]-disponibles_posX[z] == 0)
                                    || (fichas_posX[k]-disponibles_posX[z] == 2) )&&
                                    ((fichas_posy[k]-disponibles_posy[z] == 0)
                                    || (fichas_posy[k]-disponibles_posy[z] == 2))){
                                        evitar_repeticion(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }
                }
            }else if(i==6){
                for(int z=0; z<22;z++){
                    if((disponibles_posX[z] == 6) || (disponibles_posX[z] == 3)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy[k] == 0) ){
                                if((fichas_posX[k] ==6)){
                                    if(((fichas_posX[k]-disponibles_posX[z] == 0)
                                    || (fichas_posX[k]-disponibles_posX[z] == 3) )&&
                                    ((fichas_posy[k]-disponibles_posy[z] == 0)
                                    || (fichas_posy[k]-disponibles_posy[z] == -3))){
                                        evitar_repeticion(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }
                    if((disponibles_posX[z] == 6) || (disponibles_posX[z] == 5)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy[k] == 3) ){
                                if((fichas_posX[k] ==6)){
                                    if(((fichas_posX[k]-disponibles_posX[z] == 0)
                                    || (fichas_posX[k]-disponibles_posX[z] == 1) )&&
                                    ((fichas_posy[k]-disponibles_posy[z] == 3)
                                    || (fichas_posy[k]-disponibles_posy[z] == -3)
                                    || (fichas_posy[k]-disponibles_posy[z] == 0))){
                                        evitar_repeticion(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }
                    if((disponibles_posX[z] == 6) || (disponibles_posX[z] == 3)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy[k] == 6) ){
                                if((fichas_posX[k] ==6)){
                                    if(((fichas_posX[k]-disponibles_posX[z] == 0)
                                    || (fichas_posX[k]-disponibles_posX[z] == 3) )&&
                                    ((fichas_posy[k]-disponibles_posy[z] == 0)
                                    || (fichas_posy[k]-disponibles_posy[z] == 3))){
                                        evitar_repeticion(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

}

void Player :: evitar_repeticion(string matriz[7][7],int &k,int &z){
    repite = "La ficha "+matriz[fichas_posX[k]][fichas_posy[k]]
    +" tiene posibles movimientos en la posicion "+matriz[disponibles_posX[z]][disponibles_posy[z]];
    bool val = true;
    for(int m=0; m<contador; m++){
        if(repite != noRepite1[m]){val = true;}
        else{val = false;break;}
    }
    if (val == true){
        noRepite1[contador] = repite; contador++;
        cout<<repite<<endl;
    }
}

void Player:: jugada_libre(string matriz[7][7], string matriz2[7][7],string disponibles[24],int &jugada_x,int &jugada_y){
    bool val = false;
    int movimiento;
    string ficha;
    cout<<"\nDigite la ficha que desea mover: ";cin>>ficha;
    cout<<"\nDigite la posicion donde se quiere mover: "; cin>>movimiento;
    for(int i=0;i<7;i++){
        if(val == true){break;}
        for(int j=0;j<7;j++){
            if(val == true){break;}
            if(matriz[i][j] == ficha){
                for(int k=0;k<24;k++){
                    if(val == true){break;}
                    if(disponibles[k]== to_string(movimiento)){
                        for(int m=0;m<7;m++){
                            if(val == true){break;}
                            for(int s=0;s<7;s++){
                                if(matriz[m][s] == disponibles[k]){
                                    matriz[m][s] = ficha;
                                    jugada_x = m; jugada_y= s;
                                    matriz[i][j] = matriz2[i][j];
                                    disponibles[k] = matriz2[i][j]; val=true;break;
                                }
                            }
                        }
                    }
                }   
            }

        }
    }
}

bool Player :: complemento_de_eliminar(int &jugada_X,int &jugada_y,string matriz[7][7]){
    bool val = false;
    if(jugada_X ==0){
            if(jugada_y == 0){
                if(((matriz[0][3] == "F1") || (matriz[0][3] == "F2")|| (matriz[0][3] == "F3") ||(matriz[0][3] == "F5")
                ||(matriz[0][3] == "F4") || (matriz[0][3] == "F6")||(matriz[0][3] == "F7") ||(matriz[0][3] == "F8")
                || (matriz[0][3] == "F9")) &&

                ((matriz[0][6] == "F1") || (matriz[0][6] == "F2")|| (matriz[0][6] == "F3")||(matriz[0][6] == "F5")
                ||(matriz[0][6] == "F4") || (matriz[0][6] == "F6")||(matriz[0][6] == "F7") ||(matriz[0][6] == "F8")
                || (matriz[0][6] == "F9"))){
                    val= true;
                }
                if(((matriz[3][0] == "F1") || (matriz[3][0] == "F2")|| (matriz[3][0] == "F3") ||(matriz[3][0] == "F5")
                ||(matriz[3][0] == "F4") || (matriz[3][0] == "F6")||(matriz[3][0] == "F7") ||(matriz[3][0] == "F8")
                || (matriz[3][0] == "F9")) &&

                ((matriz[6][0] == "F1") || (matriz[6][0] == "F2")|| (matriz[6][0] == "F3")||(matriz[6][0] == "F5")
                ||(matriz[6][0] == "F4") || (matriz[6][0] == "F6")||(matriz[6][0] == "F7") ||(matriz[6][0] == "F8")
                || (matriz[6][0] == "F9"))){
                    val= true;
                }
            }
            if(jugada_y == 3){
                if(((matriz[0][0] == "F1") || (matriz[0][0] == "F2")|| (matriz[0][0] == "F3") ||(matriz[0][0] == "F5")
                ||(matriz[0][0] == "F4") || (matriz[0][0] == "F6")||(matriz[0][0] == "F7") ||(matriz[0][0] == "F8")
                || (matriz[0][0] == "F9")) &&

                ((matriz[0][6] == "F1") || (matriz[0][6] == "F2")|| (matriz[0][6] == "F3")||(matriz[0][6] == "F5")
                ||(matriz[0][6] == "F4") || (matriz[0][6] == "F6")||(matriz[0][6] == "F7") ||(matriz[0][6] == "F8")
                || (matriz[0][6] == "F9"))){
                    val= true;
                }
                 if(((matriz[1][3] == "F1") || (matriz[1][3] == "F2")|| (matriz[1][3] == "F3") ||(matriz[1][3] == "F5")
                ||(matriz[1][3] == "F4") || (matriz[1][3] == "F6")||(matriz[1][3] == "F7") ||(matriz[1][3] == "F8")
                || (matriz[1][3] == "F9")) &&

                ((matriz[2][3] == "F1") || (matriz[2][3] == "F2")|| (matriz[2][3] == "F3")||(matriz[2][3] == "F5")
                ||(matriz[2][3] == "F4") || (matriz[2][3] == "F6")||(matriz[2][3] == "F7") ||(matriz[2][3] == "F8")
                || (matriz[2][3] == "F9"))){
                    val= true;
                }

            }
            if(jugada_y == 6){
                if(((matriz[0][0] == "F1") || (matriz[0][0] == "F2")|| (matriz[0][0] == "F3") ||(matriz[0][0] == "F5")
                ||(matriz[0][0] == "F4") || (matriz[0][0] == "F6")||(matriz[0][0] == "F7") ||(matriz[0][0] == "F8")
                || (matriz[0][0] == "F9")) &&

                ((matriz[0][3] == "F1") || (matriz[0][3] == "F2")|| (matriz[0][3] == "F3")||(matriz[0][3] == "F5")
                ||(matriz[0][3] == "F4") || (matriz[0][3] == "F6")||(matriz[0][3] == "F7") ||(matriz[0][3] == "F8")
                || (matriz[0][3] == "F9"))){
                    val= true;
                }
                 if(((matriz[3][6] == "F1") || (matriz[3][6] == "F2")|| (matriz[3][6] == "F3") ||(matriz[3][6] == "F5")
                ||(matriz[3][6] == "F4") || (matriz[3][6] == "F6")||(matriz[3][6] == "F7") ||(matriz[3][6] == "F8")
                || (matriz[3][6] == "F9")) &&

                ((matriz[6][6] == "F1") || (matriz[6][6] == "F2")|| (matriz[6][6] == "F3")||(matriz[6][6] == "F5")
                ||(matriz[6][6] == "F4") || (matriz[6][6] == "F6")||(matriz[6][6] == "F7") ||(matriz[6][6] == "F8")
                || (matriz[6][6] == "F9"))){
                    val= true;
                }

            }
        }
        if(jugada_X ==1){
            if(jugada_y == 1){
                if(((matriz[1][3] == "F1") || (matriz[1][3] == "F2")|| (matriz[1][3] == "F3") ||(matriz[1][3] == "F5")
                ||(matriz[1][3] == "F4") || (matriz[1][3] == "F6")||(matriz[1][3] == "F7") ||(matriz[1][3] == "F8")
                || (matriz[1][3] == "F9")) &&

                ((matriz[1][5] == "F1") || (matriz[1][5] == "F2")|| (matriz[1][5] == "F3")||(matriz[1][5] == "F5")
                ||(matriz[1][5] == "F4") || (matriz[1][5] == "F6")||(matriz[1][5] == "F7") ||(matriz[1][5] == "F8")
                || (matriz[1][5] == "F9"))){
                    val= true;
                }
                if(((matriz[3][1] == "F1") || (matriz[3][1] == "F2")|| (matriz[3][1] == "F3") ||(matriz[3][1] == "F5")
                ||(matriz[3][1] == "F4") || (matriz[3][1] == "F6")||(matriz[3][1] == "F7") ||(matriz[3][1] == "F8")
                || (matriz[3][1] == "F9")) &&

                ((matriz[5][1] == "F1") || (matriz[5][1] == "F2")|| (matriz[5][1] == "F3")||(matriz[5][1] == "F5")
                ||(matriz[5][1] == "F4") || (matriz[5][1] == "F6")||(matriz[5][1] == "F7") ||(matriz[5][1] == "F8")
                || (matriz[5][1] == "F9"))){
                    val= true;
                }
            }
            if(jugada_y == 3){
                if(((matriz[1][1] == "F1") || (matriz[1][1] == "F2")|| (matriz[1][1] == "F3") ||(matriz[1][1] == "F5")
                ||(matriz[1][1] == "F4") || (matriz[1][1] == "F6")||(matriz[1][1] == "F7") ||(matriz[1][1] == "F8")
                || (matriz[1][1] == "F9")) &&

               ((matriz[1][5] == "F1") || (matriz[1][5] == "F2")|| (matriz[1][5] == "F3")||(matriz[1][5] == "F5")
                ||(matriz[1][5] == "F4") || (matriz[1][5] == "F6")||(matriz[1][5] == "F7") ||(matriz[1][5] == "F8")
                || (matriz[1][5] == "F9"))){
                    val= true;
                }
                if(((matriz[0][3] == "F1") || (matriz[0][3] == "F2")|| (matriz[0][3] == "F3") ||(matriz[0][3] == "F5")
                ||(matriz[0][3] == "F4") || (matriz[0][3] == "F6")||(matriz[0][3] == "F7") ||(matriz[0][3] == "F8")
                || (matriz[0][3] == "F9")) &&

                ((matriz[2][3] == "F1") || (matriz[2][3] == "F2")|| (matriz[2][3] == "F3")||(matriz[2][3] == "F5")
                ||(matriz[2][3] == "F4") || (matriz[2][3] == "F6")||(matriz[2][3] == "F7") ||(matriz[2][3] == "F8")
                || (matriz[2][3] == "F9"))){
                    val= true;
                }
            }
            if(jugada_y == 5){
                if(((matriz[1][1] == "F1") || (matriz[1][1] == "F2")|| (matriz[1][1] == "F3") ||(matriz[1][1] == "F5")
                ||(matriz[1][1] == "F4") || (matriz[1][1] == "F6")||(matriz[1][1] == "F7") ||(matriz[1][1] == "F8")
                || (matriz[1][1] == "F9")) &&
                
                ((matriz[1][3] == "F1") || (matriz[1][3] == "F2")|| (matriz[1][3] == "F3") ||(matriz[1][3] == "F5")
                ||(matriz[1][3] == "F4") || (matriz[1][3] == "F6")||(matriz[1][3] == "F7") ||(matriz[1][3] == "F8")
                || (matriz[1][3] == "F9"))){
                    val= true;
                }
                if(((matriz[3][5] == "F1") || (matriz[3][5] == "F2")|| (matriz[3][5] == "F3") ||(matriz[3][5] == "F5")
                ||(matriz[3][5] == "F4") || (matriz[3][5] == "F6")||(matriz[3][5] == "F7") ||(matriz[3][5] == "F8")
                || (matriz[3][5] == "F9")) &&

                ((matriz[5][5] == "F1") || (matriz[5][5] == "F2")|| (matriz[5][5] == "F3")||(matriz[5][5] == "F5")
                ||(matriz[5][5] == "F4") || (matriz[5][5] == "F6")||(matriz[5][5] == "F7") ||(matriz[5][5] == "F8")
                || (matriz[5][5] == "F9"))){
                    val= true;
                }
            }
        }
        if(jugada_X ==2){
            if(jugada_y == 2){
                if(((matriz[2][3] == "F1") || (matriz[2][3] == "F2")|| (matriz[2][3] == "F3") ||(matriz[2][3] == "F5")
                ||(matriz[2][3] == "F4") || (matriz[2][3] == "F6")||(matriz[2][3] == "F7") ||(matriz[2][3] == "F8")
                || (matriz[2][3] == "F9")) &&

                ((matriz[2][4] == "F1") || (matriz[2][4] == "F2")|| (matriz[2][4] == "F3")||(matriz[2][4] == "F5")
                ||(matriz[2][4] == "F4") || (matriz[2][4] == "F6")||(matriz[2][4] == "F7") ||(matriz[2][4] == "F8")
                || (matriz[2][4] == "F9"))){
                    val= true;
                }
                if(((matriz[3][2] == "F1") || (matriz[3][2] == "F2")|| (matriz[3][2] == "F3") ||(matriz[3][2] == "F5")
                ||(matriz[3][2] == "F4") || (matriz[3][2] == "F6")||(matriz[3][2] == "F7") ||(matriz[3][2] == "F8")
                || (matriz[3][2] == "F9")) &&

                ((matriz[4][2] == "F1") || (matriz[4][2] == "F2")|| (matriz[4][2] == "F3")||(matriz[4][2] == "F5")
                ||(matriz[4][2] == "F4") || (matriz[4][2] == "F6")||(matriz[4][2] == "F7") ||(matriz[4][2] == "F8")
                || (matriz[4][2] == "F9"))){
                    val= true;
                }
            }
            if(jugada_y == 3){
                if(((matriz[2][2] == "F1") || (matriz[2][2] == "F2")|| (matriz[2][2] == "F3") ||(matriz[2][2] == "F5")
                ||(matriz[2][2] == "F4") || (matriz[2][2] == "F6")||(matriz[2][2] == "F7") ||(matriz[2][2] == "F8")
                || (matriz[2][2] == "F9")) &&

               ((matriz[2][4] == "F1") || (matriz[2][4] == "F2")|| (matriz[2][4] == "F3")||(matriz[2][4] == "F5")
                ||(matriz[2][4] == "F4") || (matriz[2][4] == "F6")||(matriz[2][4] == "F7") ||(matriz[2][4] == "F8")
                || (matriz[2][4] == "F9"))){
                    val= true;
                }
                if(((matriz[0][3] == "F1") || (matriz[0][3] == "F2")|| (matriz[0][3] == "F3") ||(matriz[0][3] == "F5")
                ||(matriz[0][3] == "F4") || (matriz[0][3] == "F6")||(matriz[0][3] == "F7") ||(matriz[0][3] == "F8")
                || (matriz[0][3] == "F9")) &&

                ((matriz[1][3] == "F1") || (matriz[1][3] == "F2")|| (matriz[1][3] == "F3") ||(matriz[1][3] == "F5")
                ||(matriz[1][3] == "F4") || (matriz[1][3] == "F6")||(matriz[1][3] == "F7") ||(matriz[1][3] == "F8")
                || (matriz[1][3] == "F9"))){
                    val= true;
                }
            }
            if(jugada_y == 4){
                if(((matriz[2][2] == "F1") || (matriz[2][2] == "F2")|| (matriz[2][2] == "F3") ||(matriz[2][2] == "F5")
                ||(matriz[2][2] == "F4") || (matriz[2][2] == "F6")||(matriz[2][2] == "F7") ||(matriz[2][2] == "F8")
                || (matriz[2][2] == "F9")) &&
                
                ((matriz[2][3] == "F1") || (matriz[2][3] == "F2")|| (matriz[2][3] == "F3") ||(matriz[2][3] == "F5")
                ||(matriz[2][3] == "F4") || (matriz[2][3] == "F6")||(matriz[2][3] == "F7") ||(matriz[2][3] == "F8")
                || (matriz[2][3] == "F9"))){
                    val= true;
                }
                if(((matriz[3][4] == "F1") || (matriz[3][4] == "F2")|| (matriz[3][4] == "F3") ||(matriz[3][4] == "F5")
                ||(matriz[3][4] == "F4") || (matriz[3][4] == "F6")||(matriz[3][4] == "F7") ||(matriz[3][4] == "F8")
                || (matriz[3][4] == "F9")) &&

                ((matriz[4][4] == "F1") || (matriz[4][4] == "F2")|| (matriz[4][4] == "F3")||(matriz[4][4] == "F5")
                ||(matriz[4][4] == "F4") || (matriz[4][4] == "F6")||(matriz[4][4] == "F7") ||(matriz[4][4] == "F8")
                || (matriz[4][4] == "F9"))){
                    val= true;
                }

            }
        }
        if(jugada_X ==3){
            if(jugada_y == 0){
                if(((matriz[0][0] == "F1") || (matriz[0][0] == "F2")|| (matriz[0][0] == "F3") ||(matriz[0][0] == "F5")
                ||(matriz[0][0] == "F4") || (matriz[0][0] == "F6")||(matriz[0][0] == "F7") ||(matriz[0][0] == "F8")
                || (matriz[0][0] == "F9")) &&

                ((matriz[6][0] == "F1") || (matriz[6][0] == "F2")|| (matriz[6][0] == "F3")||(matriz[6][0] == "F5")
                ||(matriz[6][0] == "F4") || (matriz[6][0] == "F6")||(matriz[6][0] == "F7") ||(matriz[6][0] == "F8")
                || (matriz[6][0] == "F9"))){
                    val= true;
                }
                if(((matriz[3][1] == "F1") || (matriz[3][1] == "F2")|| (matriz[3][1] == "F3") ||(matriz[3][1] == "F5")
                ||(matriz[3][1] == "F4") || (matriz[3][1] == "F6")||(matriz[3][1] == "F7") ||(matriz[3][1] == "F8")
                || (matriz[3][1] == "F9")) &&

                ((matriz[3][2] == "F1") || (matriz[3][2] == "F2")|| (matriz[3][2] == "F3") ||(matriz[3][2] == "F5")
                ||(matriz[3][2] == "F4") || (matriz[3][2] == "F6")||(matriz[3][2] == "F7") ||(matriz[3][2] == "F8")
                || (matriz[3][2] == "F9"))){
                    val= true;
                }
            }
            if(jugada_y == 1){
                if(((matriz[1][1] == "F1") || (matriz[1][1] == "F2")|| (matriz[1][1] == "F3") ||(matriz[1][1] == "F5")
                ||(matriz[1][1] == "F4") || (matriz[1][1] == "F6")||(matriz[1][1] == "F7") ||(matriz[1][1] == "F8")
                || (matriz[1][1] == "F9")) &&

               ((matriz[5][1] == "F1") || (matriz[5][1] == "F2")|| (matriz[5][1] == "F3")||(matriz[5][1] == "F5")
                ||(matriz[5][1] == "F4") || (matriz[5][1] == "F6")||(matriz[5][1] == "F7") ||(matriz[5][1] == "F8")
                || (matriz[5][1] == "F9"))){
                    val= true;
                }
                if(((matriz[3][2] == "F1") || (matriz[3][2] == "F2")|| (matriz[3][2] == "F3") ||(matriz[3][2] == "F5")
                ||(matriz[3][2] == "F4") || (matriz[3][2] == "F6")||(matriz[3][2] == "F7") ||(matriz[3][2] == "F8")
                || (matriz[3][2] == "F9")) &&

                ((matriz[3][0] == "F1") || (matriz[3][0] == "F2")|| (matriz[3][0] == "F3") ||(matriz[3][0] == "F5")
                ||(matriz[3][0] == "F4") || (matriz[3][0] == "F6")||(matriz[3][0] == "F7") ||(matriz[3][0] == "F8")
                || (matriz[3][0] == "F9"))){
                    val= true;
                }
            }
            if(jugada_y == 2){
                if(((matriz[2][2] == "F1") || (matriz[2][2] == "F2")|| (matriz[2][2] == "F3") ||(matriz[2][2] == "F5")
                ||(matriz[2][2] == "F4") || (matriz[2][2] == "F6")||(matriz[2][2] == "F7") ||(matriz[2][2] == "F8")
                || (matriz[2][2] == "F9")) &&
                
                ((matriz[4][2] == "F1") || (matriz[4][2] == "F2")|| (matriz[4][2] == "F3")||(matriz[4][2] == "F5")
                ||(matriz[4][2] == "F4") || (matriz[4][2] == "F6")||(matriz[4][2] == "F7") ||(matriz[4][2] == "F8")
                || (matriz[4][2] == "F9"))){
                    val= true;
                }
                if(((matriz[3][1] == "F1") || (matriz[3][1] == "F2")|| (matriz[3][1] == "F3") ||(matriz[3][1] == "F5")
                ||(matriz[3][1] == "F4") || (matriz[3][1] == "F6")||(matriz[3][1] == "F7") ||(matriz[3][1] == "F8")
                || (matriz[3][1] == "F9")) &&

                ((matriz[3][0] == "F1") || (matriz[3][0] == "F2")|| (matriz[3][0] == "F3") ||(matriz[3][0] == "F5")
                ||(matriz[3][0] == "F4") || (matriz[3][0] == "F6")||(matriz[3][0] == "F7") ||(matriz[3][0] == "F8")
                || (matriz[3][0] == "F9"))){
                    val= true;
                }

            }
            if(jugada_y == 4){
                if(((matriz[4][4] == "F1") || (matriz[4][4] == "F2")|| (matriz[4][4] == "F3")||(matriz[4][4] == "F5")
                ||(matriz[4][4] == "F4") || (matriz[4][4] == "F6")||(matriz[4][4] == "F7") ||(matriz[4][4] == "F8")
                || (matriz[4][4] == "F9")) &&

                ((matriz[2][4] == "F1") || (matriz[2][4] == "F2")|| (matriz[2][4] == "F3")||(matriz[2][4] == "F5")
                ||(matriz[2][4] == "F4") || (matriz[2][4] == "F6")||(matriz[2][4] == "F7") ||(matriz[2][4] == "F8")
                || (matriz[2][4] == "F9"))){
                    val= true;
                }
                if(((matriz[3][5] == "F1") || (matriz[3][5] == "F2")|| (matriz[3][5] == "F3") ||(matriz[3][5] == "F5")
                ||(matriz[3][5] == "F4") || (matriz[3][5] == "F6")||(matriz[3][5] == "F7") ||(matriz[3][5] == "F8")
                || (matriz[3][5] == "F9")) &&

                ((matriz[3][6] == "F1") || (matriz[3][6] == "F2")|| (matriz[3][6] == "F3") ||(matriz[3][6] == "F5")
                ||(matriz[3][6] == "F4") || (matriz[3][6] == "F6")||(matriz[3][6] == "F7") ||(matriz[3][6] == "F8")
                || (matriz[3][6] == "F9"))){
                    val= true;
                }
            }
            if(jugada_y == 5){
                if(((matriz[3][4] == "F1") || (matriz[3][4] == "F2")|| (matriz[3][4] == "F3") ||(matriz[3][4] == "F5")
                ||(matriz[3][4] == "F4") || (matriz[3][4] == "F6")||(matriz[3][4] == "F7") ||(matriz[3][4] == "F8")
                || (matriz[3][4] == "F9")) &&

               ((matriz[3][6] == "F1") || (matriz[3][6] == "F2")|| (matriz[3][6] == "F3") ||(matriz[3][6] == "F5")
                ||(matriz[3][6] == "F4") || (matriz[3][6] == "F6")||(matriz[3][6] == "F7") ||(matriz[3][6] == "F8")
                || (matriz[3][6] == "F9"))){
                    val= true;
                }
                if(((matriz[5][5] == "F1") || (matriz[5][5] == "F2")|| (matriz[5][5] == "F3")||(matriz[5][5] == "F5")
                ||(matriz[5][5] == "F4") || (matriz[5][5] == "F6")||(matriz[5][5] == "F7") ||(matriz[5][5] == "F8")
                || (matriz[5][5] == "F9")) &&

                ((matriz[1][5] == "F1") || (matriz[1][5] == "F2")|| (matriz[1][5] == "F3")||(matriz[1][5] == "F5")
                ||(matriz[1][5] == "F4") || (matriz[1][5] == "F6")||(matriz[1][5] == "F7") ||(matriz[1][5] == "F8")
                || (matriz[1][5] == "F9"))){
                    val= true;
                }
            }
            if(jugada_y == 6){
                if(((matriz[3][4] == "F1") || (matriz[3][4] == "F2")|| (matriz[3][4] == "F3") ||(matriz[3][4] == "F5")
                ||(matriz[3][4] == "F4") || (matriz[3][4] == "F6")||(matriz[3][4] == "F7") ||(matriz[3][4] == "F8")
                || (matriz[3][4] == "F9")) &&
                
                ((matriz[3][5] == "F1") || (matriz[3][5] == "F2")|| (matriz[3][5] == "F3") ||(matriz[3][5] == "F5")
                ||(matriz[3][5] == "F4") || (matriz[3][5] == "F6")||(matriz[3][5] == "F7") ||(matriz[3][5] == "F8")
                || (matriz[3][5] == "F9"))){
                    val= true;
                }
                if(((matriz[6][6] == "F1") || (matriz[6][6] == "F2")|| (matriz[6][6] == "F3")||(matriz[6][6] == "F5")
                ||(matriz[6][6] == "F4") || (matriz[6][6] == "F6")||(matriz[6][6] == "F7") ||(matriz[6][6] == "F8")
                || (matriz[6][6] == "F9")) &&

                ((matriz[0][6] == "F1") || (matriz[0][6] == "F2")|| (matriz[0][6] == "F3")||(matriz[0][6] == "F5")
                ||(matriz[0][6] == "F4") || (matriz[0][6] == "F6")||(matriz[0][6] == "F7") ||(matriz[0][6] == "F8")
                || (matriz[0][6] == "F9"))){
                    val= true;
                }
            }
        }
        if(jugada_X ==4){
            if(jugada_y == 2){
                if(((matriz[2][2] == "F1") || (matriz[2][2] == "F2")|| (matriz[2][2] == "F3") ||(matriz[2][2] == "F5")
                ||(matriz[2][2] == "F4") || (matriz[2][2] == "F6")||(matriz[2][2] == "F7") ||(matriz[2][2] == "F8")
                || (matriz[2][2] == "F9")) &&

               ((matriz[3][2] == "F1") || (matriz[3][2] == "F2")|| (matriz[3][2] == "F3") ||(matriz[3][2] == "F5")
                ||(matriz[3][2] == "F4") || (matriz[3][2] == "F6")||(matriz[3][2] == "F7") ||(matriz[3][2] == "F8")
                || (matriz[3][2] == "F9"))){
                    val= true;
                }
                if(((matriz[4][4] == "F1") || (matriz[4][4] == "F2")|| (matriz[4][4] == "F3")||(matriz[4][4] == "F5")
                ||(matriz[4][4] == "F4") || (matriz[4][4] == "F6")||(matriz[4][4] == "F7") ||(matriz[4][4] == "F8")
                || (matriz[4][4] == "F9")) &&

                ((matriz[4][3] == "F1") || (matriz[4][3] == "F2")|| (matriz[4][3] == "F3")||(matriz[4][3] == "F5")
                ||(matriz[4][3] == "F4") || (matriz[4][3] == "F6")||(matriz[4][3] == "F7") ||(matriz[4][3] == "F8")
                || (matriz[4][3] == "F9"))){
                    val= true;
                }
            }
            if(jugada_y == 3){
                if(((matriz[4][2] == "F1") || (matriz[4][2] == "F2")|| (matriz[4][2] == "F3")||(matriz[4][2] == "F5")
                ||(matriz[4][2] == "F4") || (matriz[4][2] == "F6")||(matriz[4][2] == "F7") ||(matriz[4][2] == "F8")
                || (matriz[4][2] == "F9")) &&

               (((matriz[4][4] == "F1") || (matriz[4][4] == "F2")|| (matriz[4][4] == "F3")||(matriz[4][4] == "F5")
                ||(matriz[4][4] == "F4") || (matriz[4][4] == "F6")||(matriz[4][4] == "F7") ||(matriz[4][4] == "F8")
                || (matriz[4][4] == "F9")))){
                    val= true;
                }
                if(((matriz[5][3] == "F1") || (matriz[5][3] == "F2")|| (matriz[5][3] == "F3") ||(matriz[5][3] == "F5")
                ||(matriz[5][3] == "F4") || (matriz[5][3] == "F6")||(matriz[5][3] == "F7") ||(matriz[5][3] == "F8")
                || (matriz[5][3] == "F9")) &&

                ((matriz[6][3] == "F1") || (matriz[6][3] == "F2")|| (matriz[6][3] == "F3") ||(matriz[6][3] == "F5")
                ||(matriz[6][3] == "F4") || (matriz[6][3] == "F6")||(matriz[6][3] == "F7") ||(matriz[6][3] == "F8")
                || (matriz[6][3] == "F9"))){
                    val= true;
                }
            }
            if(jugada_y == 4){
                if(((matriz[2][4] == "F1") || (matriz[2][4] == "F2")|| (matriz[2][4] == "F3")||(matriz[2][4] == "F5")
                ||(matriz[2][4] == "F4") || (matriz[2][4] == "F6")||(matriz[2][4] == "F7") ||(matriz[2][4] == "F8")
                || (matriz[2][4] == "F9")) &&
                
                ((matriz[3][4] == "F1") || (matriz[3][4] == "F2")|| (matriz[3][4] == "F3") ||(matriz[3][4] == "F5")
                ||(matriz[3][4] == "F4") || (matriz[3][4] == "F6")||(matriz[3][4] == "F7") ||(matriz[3][4] == "F8")
                || (matriz[3][4] == "F9"))){
                    val= true;
                }
                if(((matriz[4][2] == "F1") || (matriz[4][2] == "F2")|| (matriz[4][2] == "F3")||(matriz[4][2] == "F5")
                ||(matriz[4][2] == "F4") || (matriz[4][2] == "F6")||(matriz[4][2] == "F7") ||(matriz[4][2] == "F8")
                || (matriz[4][2] == "F9")) &&

                ((matriz[4][3] == "F1") || (matriz[4][3] == "F2")|| (matriz[4][3] == "F3")||(matriz[4][3] == "F5")
                ||(matriz[4][3] == "F4") || (matriz[4][3] == "F6")||(matriz[4][3] == "F7") ||(matriz[4][3] == "F8")
                || (matriz[4][3] == "F9"))){
                    val= true;
                }
            }
        }
        if(jugada_X ==5){
            if(jugada_y == 1){
                if(((matriz[1][1] == "F1") || (matriz[1][1] == "F2")|| (matriz[1][1] == "F3") ||(matriz[1][1] == "F5")
                ||(matriz[1][1] == "F4") || (matriz[1][1] == "F6")||(matriz[1][1] == "F7") ||(matriz[1][1] == "F8")
                || (matriz[1][1] == "F9")) &&

                ((matriz[3][1] == "F1") || (matriz[3][1] == "F2")|| (matriz[3][1] == "F3") ||(matriz[3][1] == "F5")
                ||(matriz[3][1] == "F4") || (matriz[3][1] == "F6")||(matriz[3][1] == "F7") ||(matriz[3][1] == "F8")
                || (matriz[3][1] == "F9"))){
                    val= true;
                }
                if(((matriz[5][3] == "F1") || (matriz[5][3] == "F2")|| (matriz[5][3] == "F3") ||(matriz[5][3] == "F5")
                ||(matriz[5][3] == "F4") || (matriz[5][3] == "F6")||(matriz[5][3] == "F7") ||(matriz[5][3] == "F8")
                || (matriz[5][3] == "F9")) &&

                ((matriz[5][5] == "F1") || (matriz[5][5] == "F2")|| (matriz[5][5] == "F3")||(matriz[5][5] == "F5")
                ||(matriz[5][5] == "F4") || (matriz[5][5] == "F6")||(matriz[5][5] == "F7") ||(matriz[5][5] == "F8")
                || (matriz[5][5] == "F9"))){
                    val= true;
                }
            }
            if(jugada_y == 3){
                if(((matriz[5][1] == "F1") || (matriz[5][1] == "F2")|| (matriz[5][1] == "F3")||(matriz[5][1] == "F5")
                ||(matriz[5][1] == "F4") || (matriz[5][1] == "F6")||(matriz[5][1] == "F7") ||(matriz[5][1] == "F8")
                || (matriz[5][1] == "F9")) &&

               ((matriz[5][5] == "F1") || (matriz[5][5] == "F2")|| (matriz[5][5] == "F3")||(matriz[5][5] == "F5")
                ||(matriz[5][5] == "F4") || (matriz[5][5] == "F6")||(matriz[5][5] == "F7") ||(matriz[5][5] == "F8")
                || (matriz[5][5] == "F9"))){
                    val= true;
                }
                if(((matriz[6][3] == "F1") || (matriz[6][3] == "F2")|| (matriz[6][3] == "F3") ||(matriz[6][3] == "F5")
                ||(matriz[6][3] == "F4") || (matriz[6][3] == "F6")||(matriz[6][3] == "F7") ||(matriz[6][3] == "F8")
                || (matriz[6][3] == "F9")) &&

                ((matriz[4][3] == "F1") || (matriz[4][3] == "F2")|| (matriz[4][3] == "F3")||(matriz[4][3] == "F5")
                ||(matriz[4][3] == "F4") || (matriz[4][3] == "F6")||(matriz[4][3] == "F7") ||(matriz[4][3] == "F8")
                || (matriz[4][3] == "F9"))){
                    val= true;
                }
            }
            if(jugada_y == 5){
                if(((matriz[5][3] == "F1") || (matriz[5][3] == "F2")|| (matriz[5][3] == "F3") ||(matriz[5][3] == "F5")
                ||(matriz[5][3] == "F4") || (matriz[5][3] == "F6")||(matriz[5][3] == "F7") ||(matriz[5][3] == "F8")
                || (matriz[5][3] == "F9")) &&
                
                ((matriz[5][1] == "F1") || (matriz[5][1] == "F2")|| (matriz[5][1] == "F3")||(matriz[5][1] == "F5")
                ||(matriz[5][1] == "F4") || (matriz[5][1] == "F6")||(matriz[5][1] == "F7") ||(matriz[5][1] == "F8")
                || (matriz[5][1] == "F9"))){
                    val= true;
                }
               if(((matriz[3][5] == "F1") || (matriz[3][5] == "F2")|| (matriz[3][5] == "F3") ||(matriz[3][5] == "F5")
                ||(matriz[3][5] == "F4") || (matriz[3][5] == "F6")||(matriz[3][5] == "F7") ||(matriz[3][5] == "F8")
                || (matriz[3][5] == "F9")) &&

               ((matriz[1][5] == "F1") || (matriz[1][5] == "F2")|| (matriz[1][5] == "F3")||(matriz[1][5] == "F5")
                ||(matriz[1][5] == "F4") || (matriz[1][5] == "F6")||(matriz[1][5] == "F7") ||(matriz[1][5] == "F8")
                || (matriz[1][5] == "F9"))){
                    val= true;
                }
            }
        }        
        if(jugada_X ==6){
            if(jugada_y == 0){
                if(((matriz[6][3] == "F1") || (matriz[6][3] == "F2")|| (matriz[6][3] == "F3") ||(matriz[6][3] == "F5")
                ||(matriz[6][3] == "F4") || (matriz[6][3] == "F6")||(matriz[6][3] == "F7") ||(matriz[6][3] == "F8")
                || (matriz[6][3] == "F9")) &&

               ((matriz[6][6] == "F1") || (matriz[6][6] == "F2")|| (matriz[6][6] == "F3")||(matriz[6][6] == "F5")
                ||(matriz[6][6] == "F4") || (matriz[6][6] == "F6")||(matriz[6][6] == "F7") ||(matriz[6][6] == "F8")
                || (matriz[6][6] == "F9"))){
                    val= true;
                }
                if(((matriz[3][0] == "F1") || (matriz[3][0] == "F2")|| (matriz[3][0] == "F3") ||(matriz[3][0] == "F5")
                ||(matriz[3][0] == "F4") || (matriz[3][0] == "F6")||(matriz[3][0] == "F7") ||(matriz[3][0] == "F8")
                || (matriz[3][0] == "F9")) &&

                ((matriz[0][0] == "F1") || (matriz[0][0] == "F2")|| (matriz[0][0] == "F3") ||(matriz[0][0] == "F5")
                ||(matriz[0][0] == "F4") || (matriz[0][0] == "F6")||(matriz[0][0] == "F7") ||(matriz[0][0] == "F8")
                || (matriz[0][0] == "F9"))){
                    val= true;
                }
            }
            if(jugada_y == 3){
                if(((matriz[6][6] == "F1") || (matriz[6][6] == "F2")|| (matriz[6][6] == "F3")||(matriz[6][6] == "F5")
                ||(matriz[6][6] == "F4") || (matriz[6][6] == "F6")||(matriz[6][6] == "F7") ||(matriz[6][6] == "F8")
                || (matriz[6][6] == "F9")) &&

               ((matriz[6][0] == "F1") || (matriz[6][0] == "F2")|| (matriz[6][0] == "F3")||(matriz[6][0] == "F5")
                ||(matriz[6][0] == "F4") || (matriz[6][0] == "F6")||(matriz[6][0] == "F7") ||(matriz[6][0] == "F8")
                || (matriz[6][0] == "F9"))){
                    val= true;
                }
                if(((matriz[5][3] == "F1") || (matriz[5][3] == "F2")|| (matriz[5][3] == "F3") ||(matriz[5][3] == "F5")
                ||(matriz[5][3] == "F4") || (matriz[5][3] == "F6")||(matriz[5][3] == "F7") ||(matriz[5][3] == "F8")
                || (matriz[5][3] == "F9")) &&

                ((matriz[4][3] == "F1") || (matriz[4][3] == "F2")|| (matriz[4][3] == "F3")||(matriz[4][3] == "F5")
                ||(matriz[4][3] == "F4") || (matriz[4][3] == "F6")||(matriz[4][3] == "F7") ||(matriz[4][3] == "F8")
                || (matriz[4][3] == "F9"))){
                    val= true;
                }
            }
            if(jugada_y == 6){
                 if(((matriz[6][3] == "F1") || (matriz[6][3] == "F2")|| (matriz[6][3] == "F3") ||(matriz[6][3] == "F5")
                ||(matriz[6][3] == "F4") || (matriz[6][3] == "F6")||(matriz[6][3] == "F7") ||(matriz[6][3] == "F8")
                || (matriz[6][3] == "F9")) &&
                
                ((matriz[6][0] == "F1") || (matriz[6][0] == "F2")|| (matriz[6][0] == "F3")||(matriz[6][0] == "F5")
                ||(matriz[6][0] == "F4") || (matriz[6][0] == "F6")||(matriz[6][0] == "F7") ||(matriz[6][0] == "F8")
                || (matriz[6][0] == "F9"))){
                    val= true;
                }
                if(((matriz[0][6] == "F1") || (matriz[0][6] == "F2")|| (matriz[0][6] == "F3")||(matriz[0][6] == "F5")
                ||(matriz[0][6] == "F4") || (matriz[0][6] == "F6")||(matriz[0][6] == "F7") ||(matriz[0][6] == "F8")
                || (matriz[0][6] == "F9")) &&

                ((matriz[3][6] == "F1") || (matriz[3][6] == "F2")|| (matriz[3][6] == "F3") ||(matriz[3][6] == "F5")
                ||(matriz[3][6] == "F4") || (matriz[3][6] == "F6")||(matriz[3][6] == "F7") ||(matriz[3][6] == "F8")
                || (matriz[3][6] == "F9"))){
                    val= true;
                }
            }
        }return val;
}

void Player :: eliminar(string matriz[7][7],string matriz2[7][7],int &opcion,int &jugada_X,int &jugada_y,int &rival,string disponibles[24]){
    int eliminar;
    bool val= false;
    if(opcion == 2){
        val = complemento_de_eliminar(jugada_X,jugada_y,matriz);
        if(val == true){
            cout<<"\nHORA DE ELIMINAR UNA FICHA PLAYER 1\n";
            Machine m1;
            m1.verificar_posiciones(matriz,disponibles);
            for(int k=0;k<rival;k++){
            cout<<"Ficha "<<matriz[m1.fichas_maquina_x[k]][m1.fichas_maquina_y[k]] <<" #"<<k+1<<endl;
            }
            cout<<"\nDigte el numero de la ficha a eliminar: ";cin>>eliminar;
            rival-=1;
            jugada_X = 99; jugada_y = 99;
            bool por_fin = false;
            for(int i=0; i<7;i++){
                if(por_fin == true){break;}
                for(int j=0; j<7;j++){
                     if(por_fin == true){break;}
                    if(i == m1.fichas_maquina_x[eliminar-1] && j== m1.fichas_maquina_y[eliminar-1]){
                        matriz[i][j] = matriz2[i][j];
                        for(int s=0;s<24;s++){
                            if(disponibles[s] == " "){
                                disponibles[s] =matriz2[i][j];por_fin = true;break;
                            }
                        }
                    }
                }
            }
        }
    }
    else if(opcion == 1){
        val = complemento_de_eliminar(jugada_X,jugada_y,matriz);
        if(val == true){
            cout<<"\nHORA DE ELIMINAR UNA FICHA PLAYER 1\n";
            Player2 p2;
            p2.verificar_disponibles2(matriz,disponibles);
            for(int k=0;k<rival;k++){
            cout<<"Ficha "<<matriz[p2.fichas_posX2[k]][p2.fichas_posy2[k]] <<" #"<<k+1<<endl;
            }
            cout<<"\nDigte el numero de la ficha a eliminar: ";cin>>eliminar;
            rival-=1;
            jugada_X = 99; jugada_y = 99;
            bool por_fin = false;
            for(int i=0; i<7;i++){
                if(por_fin == true){break;}
                for(int j=0; j<7;j++){
                     if(por_fin == true){break;}
                    if(i == p2.fichas_posX2[eliminar-1] && j== p2.fichas_posy2[eliminar-1]){
                        matriz[i][j] = matriz2[i][j];
                        for(int s=0;s<24;s++){
                            if(disponibles[s] == " "){
                                disponibles[s] =matriz2[i][j];por_fin = true;break;
                            }
                        }
                    }
                }
            }
        }
    }
}