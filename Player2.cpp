#include "Player2.h"

Player2::Player2(){}

Player2::~Player2(){}

void Player2 :: Setfichas2(int _fichas){
    fichas2 = _fichas;
}

int Player2:: Getfichas2(){
    return fichas2;
}

int Player2 :: PonerFichas2(){
    cout<<"Player 2 ¿En que posicion deseas jugar?"<<endl;
    cout<<"Seleccione un numero: "; cin>>PosicionP2;
    return PosicionP2;
}

string Player2 :: complemento_mover_fichas2(){
    cout<<"Digite la posicion en que desea mover esta ficha: "; cin>>PosicionP2;
    return to_string(PosicionP2);
}
string Player2 :: MoverFichas2(){
    string posicion_nueva;
    cout<<"Player 2 ¿Que ficha deseas mover? : ";cin>>posicion_nueva;
    return posicion_nueva ;
}

void Player2 :: jugada_libre2(string matriz[7][7], string matriz2[7][7],string disponibles[24],int &jugada_x,int &jugada_y){
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
                                    jugada_x = m; jugada_y=s;
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
void Player2 :: verificar_disponibles2(string matriz[7][7],string disponibles[24]){
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            if((matriz[i][j] != "O") && (matriz[i][j] != "*") &&(matriz[i][j] != "F1") &&(matriz[i][j] != "F5")
            &&(matriz[i][j] != "F2")&&(matriz[i][j] != "F3")&&(matriz[i][j] != "F4")&&(matriz[i][j] != "F6")
            &&(matriz[i][j] != "F7")&&(matriz[i][j] != "F8")&&(matriz[i][j] != "F9")){
                bool val = false;
                for(int d=0; d<24;d++){
                    if(disponibles[d] != " "){
                        if(matriz[i][j] != disponibles[d]){val = true;}
                        else{val = false;break;}
                    }
                }
                
                if(val == true){
                    fichas_posX2[contador_posiciones_fichas2]= i;
                    fichas_posy2[contador_posiciones_fichas2] = j;
                    contador_posiciones_fichas2++;
                }
                  
            }
            for(int l=0; l<24;l++){
                    if(matriz[i][j] == disponibles[l]){
                        disponibles_posX2[contador_posiciones_disponibles2] = i;
                        disponibles_posy2[contador_posiciones_disponibles2] = j;
                        contador_posiciones_disponibles2++;
                    }
                }
        }
    }
}

void Player2 :: posibles_jugadas2(string matriz[7][7]){
    for(int i=0; i<7;i++){
        for(int j=0; j<7;j++){
            if(i==0){
                for(int z=0; z<22;z++){
                    if((disponibles_posX2[z] == 0) || (disponibles_posX2[z] == 3)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy2[k] == 0) ){
                                if((fichas_posX2[k] ==0)){
                                    if(((fichas_posX2[k]-disponibles_posX2[z] == 0) 
                                    || (fichas_posX2[k]-disponibles_posX2[z] == -3) )&& 
                                    ((fichas_posy2[k]-disponibles_posy2[z] == 0) 
                                    || (fichas_posy2[k]-disponibles_posy2[z] == -3))){
                                        evitar_repeticion2(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }
                    if((disponibles_posX2[z] == 0) || (disponibles_posX2[z] == 1)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy2[k] == 3) ){
                                if((fichas_posX2[k] ==0)){
                                    if(((fichas_posX2[k]-disponibles_posX2[z] == 0) 
                                    || (fichas_posX2[k]-disponibles_posX2[z] == -1) )&& 
                                    ((fichas_posy2[k]-disponibles_posy2[z] == 0) 
                                    || (fichas_posy2[k]-disponibles_posy2[z] == -3)
                                    || (fichas_posy2[k]-disponibles_posy2[z] == 3))){
                                        evitar_repeticion2(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }
                    if((disponibles_posX2[z] == 0) || (disponibles_posX2[z] == 3)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy2[k] == 6) ){
                                if((fichas_posX2[k] ==0)){
                                    if(((fichas_posX2[k]-disponibles_posX2[z] == 0) 
                                    || (fichas_posX2[k]-disponibles_posX2[z] == -3) )&& 
                                    ((fichas_posy2[k]-disponibles_posy2[z] == 0) 
                                    || (fichas_posy2[k]-disponibles_posy2[z] == 3))){
                                        evitar_repeticion2(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }    
                }
            }
            else if(i==1){
                for(int z=0; z<22;z++){
                    if((disponibles_posX2[z] == 1) || (disponibles_posX2[z] == 3)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy2[k] == 1) ){
                                if((fichas_posX2[k] ==1)){
                                    if(((fichas_posX2[k]-disponibles_posX2[z] == 0) 
                                    || (fichas_posX2[k]-disponibles_posX2[z] == -2) )&& 
                                    ((fichas_posy2[k]-disponibles_posy2[z] == 0) 
                                    || (fichas_posy2[k]-disponibles_posy2[z] == -2))){
                                        evitar_repeticion2(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }
                    if((disponibles_posX2[z] == 1) || (disponibles_posX2[z] == 2) || (disponibles_posX2[z] == 0)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy2[k] == 3) ){
                                if((fichas_posX2[k] ==1)){
                                    if(((fichas_posX2[k]-disponibles_posX2[z] == 0) 
                                    || (fichas_posX2[k]-disponibles_posX2[z] == -1)
                                    || (fichas_posX2[k]-disponibles_posX2[z] == 1) )&& 
                                    ((fichas_posy2[k]-disponibles_posy2[z] == 0) 
                                    || (fichas_posy2[k]-disponibles_posy2[z] == -2)
                                    || (fichas_posy2[k]-disponibles_posy2[z] == 2))){
                                        evitar_repeticion2(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }
                    if((disponibles_posX2[z] == 1) || (disponibles_posX2[z] == 3)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy2[k] == 5) ){
                                if((fichas_posX2[k] ==1)){
                                    if(((fichas_posX2[k]-disponibles_posX2[z] == 0) 
                                    || (fichas_posX2[k]-disponibles_posX2[z] == -2) )&& 
                                    ((fichas_posy2[k]-disponibles_posy2[z] == 0) 
                                    || (fichas_posy2[k]-disponibles_posy2[z] == 2))){
                                        evitar_repeticion2(matriz,k,z);
                                    }
                                }
                            }
                        }
                    } 
                }
            }else if(i==2){
                for(int z=0; z<22;z++){
                    if((disponibles_posX2[z] == 2) || (disponibles_posX2[z] == 3)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy2[k] == 2) ){
                                if((fichas_posX2[k] ==2)){
                                    if(((fichas_posX2[k]-disponibles_posX2[z] == 0) 
                                    || (fichas_posX2[k]-disponibles_posX2[z] == -1) )&& 
                                    ((fichas_posy2[k]-disponibles_posy2[z] == 0) 
                                    || (fichas_posy2[k]-disponibles_posy2[z] == -1))){
                                        evitar_repeticion2(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }
                    if((disponibles_posX2[z] == 2) || (disponibles_posX2[z] == 1)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy2[k] == 3) ){
                                if((fichas_posX2[k] ==2)){
                                    if(((fichas_posX2[k]-disponibles_posX2[z] == 0) 
                                    || (fichas_posX2[k]-disponibles_posX2[z] == 1) )&& 
                                    ((fichas_posy2[k]-disponibles_posy2[z] == 1) 
                                    || (fichas_posy2[k]-disponibles_posy2[z] == -1)
                                    || (fichas_posy2[k]-disponibles_posy2[z] == 0))){
                                        evitar_repeticion2(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }
                    if((disponibles_posX2[z] == 2) || (disponibles_posX2[z] == 3)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy2[k] == 4) ){
                                if((fichas_posX2[k] ==2)){
                                    if(((fichas_posX2[k]-disponibles_posX2[z] == 0) 
                                    || (fichas_posX2[k]-disponibles_posX2[z] == -1) )&& 
                                    ((fichas_posy2[k]-disponibles_posy2[z] == 0) 
                                    || (fichas_posy2[k]-disponibles_posy2[z] == 1))){
                                        evitar_repeticion2(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }
                }
            }
            else if(i==3){
                for(int z=0; z<22;z++){
                    if((disponibles_posX2[z] == 0) || (disponibles_posX2[z] == 3) || (disponibles_posX2[z] == 6)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy2[k] == 0) ){
                                if((fichas_posX2[k] ==3)){
                                    if(((fichas_posX2[k]-disponibles_posX2[z] == 0) 
                                    || (fichas_posX2[k]-disponibles_posX2[z] == -3) 
                                    || (fichas_posX2[k]-disponibles_posX2[z] == 3) )&& 
                                    ((fichas_posy2[k]-disponibles_posy2[z] == 0) 
                                    || (fichas_posy2[k]-disponibles_posy2[z] == -1))){
                                       evitar_repeticion2(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }
                    if((disponibles_posX2[z] == 3) || (disponibles_posX2[z] == 1)|| (disponibles_posX2[z] == 5)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy2[k] == 1) ){
                                if((fichas_posX2[k] ==3)){
                                    if(((fichas_posX2[k]-disponibles_posX2[z] == 0) 
                                    || (fichas_posX2[k]-disponibles_posX2[z] == 2)
                                    || (fichas_posX2[k]-disponibles_posX2[z] == -2) )&& 
                                    ((fichas_posy2[k]-disponibles_posy2[z] == 1) 
                                    || (fichas_posy2[k]-disponibles_posy2[z] == -1)
                                    || (fichas_posy2[k]-disponibles_posy2[z] == 0))){
                                       evitar_repeticion2(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }
                    if((disponibles_posX2[z] == 2) || (disponibles_posX2[z] == 3)|| (disponibles_posX2[z] == 4)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy2[k] == 2) ){
                                if((fichas_posX2[k] ==3)){
                                    if(((fichas_posX2[k]-disponibles_posX2[z] == 0) 
                                    || (fichas_posX2[k]-disponibles_posX2[z] == -1) 
                                    || (fichas_posX2[k]-disponibles_posX2[z] == 1) )&& 
                                    ((fichas_posy2[k]-disponibles_posy2[z] == 0) 
                                    || (fichas_posy2[k]-disponibles_posy2[z] == 1))){
                                        evitar_repeticion2(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }
                    if((disponibles_posX2[z] == 2) || (disponibles_posX2[z] == 3)|| (disponibles_posX2[z] == 4)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy2[k] == 4) ){
                                if((fichas_posX2[k] ==3)){
                                    if(((fichas_posX2[k]-disponibles_posX2[z] == 0) 
                                    || (fichas_posX2[k]-disponibles_posX2[z] == -1) 
                                    || (fichas_posX2[k]-disponibles_posX2[z] == 1) )&& 
                                    ((fichas_posy2[k]-disponibles_posy2[z] == 0) 
                                    || (fichas_posy2[k]-disponibles_posy2[z] == -1))){
                                        evitar_repeticion2(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }
                    if((disponibles_posX2[z] == 1) || (disponibles_posX2[z] == 3)|| (disponibles_posX2[z] == 5)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy2[k] == 5) ){
                                if((fichas_posX2[k] ==3)){
                                    if(((fichas_posX2[k]-disponibles_posX2[z] == 0) 
                                    || (fichas_posX2[k]-disponibles_posX2[z] == -2) 
                                    || (fichas_posX2[k]-disponibles_posX2[z] == 2) )&& 
                                    ((fichas_posy2[k]-disponibles_posy2[z] == 0) 
                                    || (fichas_posy2[k]-disponibles_posy2[z] == 1)
                                    || (fichas_posy2[k]-disponibles_posy2[z] == -1))){
                                       evitar_repeticion2(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }
                    if((disponibles_posX2[z] == 0) || (disponibles_posX2[z] == 3)|| (disponibles_posX2[z] == 6)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy2[k] == 6) ){
                                if((fichas_posX2[k] ==3)){
                                    if(((fichas_posX2[k]-disponibles_posX2[z] == 0) 
                                    || (fichas_posX2[k]-disponibles_posX2[z] == -3) 
                                    || (fichas_posX2[k]-disponibles_posX2[z] == 3) )&& 
                                    ((fichas_posy2[k]-disponibles_posy2[z] == 0) 
                                    || (fichas_posy2[k]-disponibles_posy2[z] == 1))){
                                        evitar_repeticion2(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }
                }
            }else if(i==4){
                for(int z=0; z<22;z++){
                    if((disponibles_posX2[z] == 4) || (disponibles_posX2[z] == 3)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy2[k] == 2) ){
                                if((fichas_posX2[k] ==4)){
                                    if(((fichas_posX2[k]-disponibles_posX2[z] == 0) 
                                    || (fichas_posX2[k]-disponibles_posX2[z] == 1) )&& 
                                    ((fichas_posy2[k]-disponibles_posy2[z] == 0) 
                                    || (fichas_posy2[k]-disponibles_posy2[z] == -1))){
                                        evitar_repeticion2(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }
                    if((disponibles_posX2[z] == 4) || (disponibles_posX2[z] == 5)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy2[k] == 3) ){
                                if((fichas_posX2[k] ==4)){
                                    if(((fichas_posX2[k]-disponibles_posX2[z] == 0) 
                                    || (fichas_posX2[k]-disponibles_posX2[z] == -1) )&& 
                                    ((fichas_posy2[k]-disponibles_posy2[z] == 1) 
                                    || (fichas_posy2[k]-disponibles_posy2[z] == -1)
                                    || (fichas_posy2[k]-disponibles_posy2[z] == 0))){
                                        evitar_repeticion2(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }
                    if((disponibles_posX2[z] == 4) || (disponibles_posX2[z] == 3)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy2[k] == 4) ){
                                if((fichas_posX2[k] ==4)){
                                    if(((fichas_posX2[k]-disponibles_posX2[z] == 0) 
                                    || (fichas_posX2[k]-disponibles_posX2[z] == 1) )&& 
                                    ((fichas_posy2[k]-disponibles_posy2[z] == 0) 
                                    || (fichas_posy2[k]-disponibles_posy2[z] == 1))){
                                        evitar_repeticion2(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }
                }
            }else if(i==5){
                for(int z=0; z<22;z++){
                    if((disponibles_posX2[z] == 3) || (disponibles_posX2[z] == 5)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy2[k] == 1) ){
                                if((fichas_posX2[k] ==5)){
                                    if(((fichas_posX2[k]-disponibles_posX2[z] == 0) 
                                    || (fichas_posX2[k]-disponibles_posX2[z] == 2) )&& 
                                    ((fichas_posy2[k]-disponibles_posy2[z] == 0) 
                                    || (fichas_posy2[k]-disponibles_posy2[z] == -2))){
                                        evitar_repeticion2(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }
                    if((disponibles_posX2[z] == 5) || (disponibles_posX2[z] == 4) || (disponibles_posX2[z] == 6)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy2[k] == 3) ){
                                if((fichas_posX2[k] ==5)){
                                    if(((fichas_posX2[k]-disponibles_posX2[z] == 0) 
                                    || (fichas_posX2[k]-disponibles_posX2[z] == 1)
                                    || (fichas_posX2[k]-disponibles_posX2[z] == -1) )&& 
                                    ((fichas_posy2[k]-disponibles_posy2[z] == -2)
                                    || (fichas_posy2[k]-disponibles_posy2[z] == 0)
                                    || (fichas_posy2[k]-disponibles_posy2[z] == 2))){
                                        evitar_repeticion2(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }
                    if((disponibles_posX2[z] == 5) || (disponibles_posX2[z] == 3)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy2[k] == 5) ){
                                if((fichas_posX2[k] ==5)){
                                    if(((fichas_posX2[k]-disponibles_posX2[z] == 0) 
                                    || (fichas_posX2[k]-disponibles_posX2[z] == 2) )&& 
                                    ((fichas_posy2[k]-disponibles_posy2[z] == 0) 
                                    || (fichas_posy2[k]-disponibles_posy2[z] == 2))){
                                        evitar_repeticion2(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }   
                }
            }else if(i==6){
                for(int z=0; z<22;z++){
                    if((disponibles_posX2[z] == 6) || (disponibles_posX2[z] == 3)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy2[k] == 0) ){
                                if((fichas_posX2[k] ==6)){
                                    if(((fichas_posX2[k]-disponibles_posX2[z] == 0) 
                                    || (fichas_posX2[k]-disponibles_posX2[z] == 3) )&& 
                                    ((fichas_posy2[k]-disponibles_posy2[z] == 0) 
                                    || (fichas_posy2[k]-disponibles_posy2[z] == -3))){
                                        evitar_repeticion2(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }
                    if((disponibles_posX2[z] == 6) || (disponibles_posX2[z] == 5)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy2[k] == 3) ){
                                if((fichas_posX2[k] ==6)){
                                    if(((fichas_posX2[k]-disponibles_posX2[z] == 0) 
                                    || (fichas_posX2[k]-disponibles_posX2[z] == 1) )&& 
                                    ((fichas_posy2[k]-disponibles_posy2[z] == 3) 
                                    || (fichas_posy2[k]-disponibles_posy2[z] == -3)
                                    || (fichas_posy2[k]-disponibles_posy2[z] == 0))){
                                        evitar_repeticion2(matriz,k,z);
                                    }
                                }
                            }
                        }
                    }
                    if((disponibles_posX2[z] == 6) || (disponibles_posX2[z] == 3)){
                        for(int k=0;k<9;k++){
                            if((fichas_posy2[k] == 6) ){
                                if((fichas_posX2[k] ==6)){
                                    if(((fichas_posX2[k]-disponibles_posX2[z] == 0) 
                                    || (fichas_posX2[k]-disponibles_posX2[z] == 3) )&& 
                                    ((fichas_posy2[k]-disponibles_posy2[z] == 0) 
                                    || (fichas_posy2[k]-disponibles_posy2[z] == 3))){
                                        evitar_repeticion2(matriz,k,z);
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

void Player2 :: evitar_repeticion2(string matriz[7][7],int &k,int &z){
    repite2 = "La ficha "+matriz[fichas_posX2[k]][fichas_posy2[k]]
    +" tiene posibles movimientos en la posicion "+matriz[disponibles_posX2[z]][disponibles_posy2[z]];
    bool val = true;
    for(int m=0; m<contador2; m++){
        if(repite2 != noRepite2[m]){val = true;}
        else{val = false;break;}
    }
    if (val == true){
        noRepite2[contador2] = repite2; contador2++;
        cout<<repite2<<endl;
    }
}

void Player2 :: eliminar2(string matriz[7][7],string matriz2[7][7],int &jugada_X,int &jugada_y,int &rival,string disponibles[24]){
    int eliminar;
    bool val= false;
    if(jugada_X ==0){
            if(jugada_y == 0){
                if(((matriz[0][3] == "P1") || (matriz[0][3] == "P2")|| (matriz[0][3] == "P3") ||(matriz[0][3] == "P5")
                ||(matriz[0][3] == "P4") || (matriz[0][3] == "P6")||(matriz[0][3] == "P7") ||(matriz[0][3] == "P8")
                || (matriz[0][3] == "P9")) &&

                ((matriz[0][6] == "P1") || (matriz[0][6] == "P2")|| (matriz[0][6] == "P3")||(matriz[0][6] == "P5")
                ||(matriz[0][6] == "P4") || (matriz[0][6] == "P6")||(matriz[0][6] == "P7") ||(matriz[0][6] == "P8")
                || (matriz[0][6] == "P9"))){
                    val= true;
                }
                if(((matriz[3][0] == "P1") || (matriz[3][0] == "P2")|| (matriz[3][0] == "P3") ||(matriz[3][0] == "P5")
                ||(matriz[3][0] == "P4") || (matriz[3][0] == "P6")||(matriz[3][0] == "P7") ||(matriz[3][0] == "P8")
                || (matriz[3][0] == "P9")) &&

                ((matriz[6][0] == "P1") || (matriz[6][0] == "P2")|| (matriz[6][0] == "P3")||(matriz[6][0] == "P5")
                ||(matriz[6][0] == "P4") || (matriz[6][0] == "P6")||(matriz[6][0] == "P7") ||(matriz[6][0] == "P8")
                || (matriz[6][0] == "P9"))){
                    val= true;
                }
            }
            if(jugada_y == 3){
                if(((matriz[0][0] == "P1") || (matriz[0][0] == "P2")|| (matriz[0][0] == "P3") ||(matriz[0][0] == "P5")
                ||(matriz[0][0] == "P4") || (matriz[0][0] == "P6")||(matriz[0][0] == "P7") ||(matriz[0][0] == "P8")
                || (matriz[0][0] == "P9")) &&

                ((matriz[0][6] == "P1") || (matriz[0][6] == "P2")|| (matriz[0][6] == "P3")||(matriz[0][6] == "P5")
                ||(matriz[0][6] == "P4") || (matriz[0][6] == "P6")||(matriz[0][6] == "P7") ||(matriz[0][6] == "P8")
                || (matriz[0][6] == "P9"))){
                    val= true;
                }
                 if(((matriz[1][3] == "P1") || (matriz[1][3] == "P2")|| (matriz[1][3] == "P3") ||(matriz[1][3] == "P5")
                ||(matriz[1][3] == "P4") || (matriz[1][3] == "P6")||(matriz[1][3] == "P7") ||(matriz[1][3] == "P8")
                || (matriz[1][3] == "P9")) &&

                ((matriz[2][3] == "P1") || (matriz[2][3] == "P2")|| (matriz[2][3] == "P3")||(matriz[2][3] == "P5")
                ||(matriz[2][3] == "P4") || (matriz[2][3] == "P6")||(matriz[2][3] == "P7") ||(matriz[2][3] == "P8")
                || (matriz[2][3] == "P9"))){
                    val= true;
                }

            }
            if(jugada_y == 6){
                if(((matriz[0][0] == "P1") || (matriz[0][0] == "P2")|| (matriz[0][0] == "P3") ||(matriz[0][0] == "P5")
                ||(matriz[0][0] == "P4") || (matriz[0][0] == "P6")||(matriz[0][0] == "P7") ||(matriz[0][0] == "P8")
                || (matriz[0][0] == "P9")) &&

                ((matriz[0][3] == "P1") || (matriz[0][3] == "P2")|| (matriz[0][3] == "P3")||(matriz[0][3] == "P5")
                ||(matriz[0][3] == "P4") || (matriz[0][3] == "P6")||(matriz[0][3] == "P7") ||(matriz[0][3] == "P8")
                || (matriz[0][3] == "P9"))){
                    val= true;
                }
                 if(((matriz[3][6] == "P1") || (matriz[3][6] == "P2")|| (matriz[3][6] == "P3") ||(matriz[3][6] == "P5")
                ||(matriz[3][6] == "P4") || (matriz[3][6] == "P6")||(matriz[3][6] == "P7") ||(matriz[3][6] == "P8")
                || (matriz[3][6] == "P9")) &&

                ((matriz[6][6] == "P1") || (matriz[6][6] == "P2")|| (matriz[6][6] == "P3")||(matriz[6][6] == "P5")
                ||(matriz[6][6] == "P4") || (matriz[6][6] == "P6")||(matriz[6][6] == "P7") ||(matriz[6][6] == "P8")
                || (matriz[6][6] == "P9"))){
                    val= true;
                }

            }
        }
        if(jugada_X ==1){
            if(jugada_y == 1){
                if(((matriz[1][3] == "P1") || (matriz[1][3] == "P2")|| (matriz[1][3] == "P3") ||(matriz[1][3] == "P5")
                ||(matriz[1][3] == "P4") || (matriz[1][3] == "P6")||(matriz[1][3] == "P7") ||(matriz[1][3] == "P8")
                || (matriz[1][3] == "P9")) &&

                ((matriz[1][5] == "P1") || (matriz[1][5] == "P2")|| (matriz[1][5] == "P3")||(matriz[1][5] == "P5")
                ||(matriz[1][5] == "P4") || (matriz[1][5] == "P6")||(matriz[1][5] == "P7") ||(matriz[1][5] == "P8")
                || (matriz[1][5] == "P9"))){
                    val= true;
                }
                if(((matriz[3][1] == "P1") || (matriz[3][1] == "P2")|| (matriz[3][1] == "P3") ||(matriz[3][1] == "P5")
                ||(matriz[3][1] == "P4") || (matriz[3][1] == "P6")||(matriz[3][1] == "P7") ||(matriz[3][1] == "P8")
                || (matriz[3][1] == "P9")) &&

                ((matriz[5][1] == "P1") || (matriz[5][1] == "P2")|| (matriz[5][1] == "P3")||(matriz[5][1] == "P5")
                ||(matriz[5][1] == "P4") || (matriz[5][1] == "P6")||(matriz[5][1] == "P7") ||(matriz[5][1] == "P8")
                || (matriz[5][1] == "P9"))){
                    val= true;
                }
            }
            if(jugada_y == 3){
                if(((matriz[1][1] == "P1") || (matriz[1][1] == "P2")|| (matriz[1][1] == "P3") ||(matriz[1][1] == "P5")
                ||(matriz[1][1] == "P4") || (matriz[1][1] == "P6")||(matriz[1][1] == "P7") ||(matriz[1][1] == "P8")
                || (matriz[1][1] == "P9")) &&

               ((matriz[1][5] == "P1") || (matriz[1][5] == "P2")|| (matriz[1][5] == "P3")||(matriz[1][5] == "P5")
                ||(matriz[1][5] == "P4") || (matriz[1][5] == "P6")||(matriz[1][5] == "P7") ||(matriz[1][5] == "P8")
                || (matriz[1][5] == "P9"))){
                    val= true;
                }
                if(((matriz[0][3] == "P1") || (matriz[0][3] == "P2")|| (matriz[0][3] == "P3") ||(matriz[0][3] == "P5")
                ||(matriz[0][3] == "P4") || (matriz[0][3] == "P6")||(matriz[0][3] == "P7") ||(matriz[0][3] == "P8")
                || (matriz[0][3] == "P9")) &&

                ((matriz[2][3] == "P1") || (matriz[2][3] == "P2")|| (matriz[2][3] == "P3")||(matriz[2][3] == "P5")
                ||(matriz[2][3] == "P4") || (matriz[2][3] == "P6")||(matriz[2][3] == "P7") ||(matriz[2][3] == "P8")
                || (matriz[2][3] == "P9"))){
                    val= true;
                }
            }
            if(jugada_y == 5){
                if(((matriz[1][1] == "P1") || (matriz[1][1] == "P2")|| (matriz[1][1] == "P3") ||(matriz[1][1] == "P5")
                ||(matriz[1][1] == "P4") || (matriz[1][1] == "P6")||(matriz[1][1] == "P7") ||(matriz[1][1] == "P8")
                || (matriz[1][1] == "P9")) &&
                
                ((matriz[1][3] == "P1") || (matriz[1][3] == "P2")|| (matriz[1][3] == "P3") ||(matriz[1][3] == "P5")
                ||(matriz[1][3] == "P4") || (matriz[1][3] == "P6")||(matriz[1][3] == "P7") ||(matriz[1][3] == "P8")
                || (matriz[1][3] == "P9"))){
                    val= true;
                }
                if(((matriz[3][5] == "P1") || (matriz[3][5] == "P2")|| (matriz[3][5] == "P3") ||(matriz[3][5] == "P5")
                ||(matriz[3][5] == "P4") || (matriz[3][5] == "P6")||(matriz[3][5] == "P7") ||(matriz[3][5] == "P8")
                || (matriz[3][5] == "P9")) &&

                ((matriz[5][5] == "P1") || (matriz[5][5] == "P2")|| (matriz[5][5] == "P3")||(matriz[5][5] == "P5")
                ||(matriz[5][5] == "P4") || (matriz[5][5] == "P6")||(matriz[5][5] == "P7") ||(matriz[5][5] == "P8")
                || (matriz[5][5] == "P9"))){
                    val= true;
                }
            }
        }
        if(jugada_X ==2){
            if(jugada_y == 2){
                if(((matriz[2][3] == "P1") || (matriz[2][3] == "P2")|| (matriz[2][3] == "P3") ||(matriz[2][3] == "P5")
                ||(matriz[2][3] == "P4") || (matriz[2][3] == "P6")||(matriz[2][3] == "P7") ||(matriz[2][3] == "P8")
                || (matriz[2][3] == "P9")) &&

                ((matriz[2][4] == "P1") || (matriz[2][4] == "P2")|| (matriz[2][4] == "P3")||(matriz[2][4] == "P5")
                ||(matriz[2][4] == "P4") || (matriz[2][4] == "P6")||(matriz[2][4] == "P7") ||(matriz[2][4] == "P8")
                || (matriz[2][4] == "P9"))){
                    val= true;
                }
                if(((matriz[3][2] == "P1") || (matriz[3][2] == "P2")|| (matriz[3][2] == "P3") ||(matriz[3][2] == "P5")
                ||(matriz[3][2] == "P4") || (matriz[3][2] == "P6")||(matriz[3][2] == "P7") ||(matriz[3][2] == "P8")
                || (matriz[3][2] == "P9")) &&

                ((matriz[4][2] == "P1") || (matriz[4][2] == "P2")|| (matriz[4][2] == "P3")||(matriz[4][2] == "P5")
                ||(matriz[4][2] == "P4") || (matriz[4][2] == "P6")||(matriz[4][2] == "P7") ||(matriz[4][2] == "P8")
                || (matriz[4][2] == "P9"))){
                    val= true;
                }
            }
            if(jugada_y == 3){
                if(((matriz[2][2] == "P1") || (matriz[2][2] == "P2")|| (matriz[2][2] == "P3") ||(matriz[2][2] == "P5")
                ||(matriz[2][2] == "P4") || (matriz[2][2] == "P6")||(matriz[2][2] == "P7") ||(matriz[2][2] == "P8")
                || (matriz[2][2] == "P9")) &&

               ((matriz[2][4] == "P1") || (matriz[2][4] == "P2")|| (matriz[2][4] == "P3")||(matriz[2][4] == "P5")
                ||(matriz[2][4] == "P4") || (matriz[2][4] == "P6")||(matriz[2][4] == "P7") ||(matriz[2][4] == "P8")
                || (matriz[2][4] == "P9"))){
                    val= true;
                }
                if(((matriz[0][3] == "P1") || (matriz[0][3] == "P2")|| (matriz[0][3] == "P3") ||(matriz[0][3] == "P5")
                ||(matriz[0][3] == "P4") || (matriz[0][3] == "P6")||(matriz[0][3] == "P7") ||(matriz[0][3] == "P8")
                || (matriz[0][3] == "P9")) &&

                ((matriz[1][3] == "P1") || (matriz[1][3] == "P2")|| (matriz[1][3] == "P3") ||(matriz[1][3] == "P5")
                ||(matriz[1][3] == "P4") || (matriz[1][3] == "P6")||(matriz[1][3] == "P7") ||(matriz[1][3] == "P8")
                || (matriz[1][3] == "P9"))){
                    val= true;
                }
            }
            if(jugada_y == 4){
                if(((matriz[2][2] == "P1") || (matriz[2][2] == "P2")|| (matriz[2][2] == "P3") ||(matriz[2][2] == "P5")
                ||(matriz[2][2] == "P4") || (matriz[2][2] == "P6")||(matriz[2][2] == "P7") ||(matriz[2][2] == "P8")
                || (matriz[2][2] == "P9")) &&
                
                ((matriz[2][3] == "P1") || (matriz[2][3] == "P2")|| (matriz[2][3] == "P3") ||(matriz[2][3] == "P5")
                ||(matriz[2][3] == "P4") || (matriz[2][3] == "P6")||(matriz[2][3] == "P7") ||(matriz[2][3] == "P8")
                || (matriz[2][3] == "P9"))){
                    val= true;
                }
                if(((matriz[3][4] == "P1") || (matriz[3][4] == "P2")|| (matriz[3][4] == "P3") ||(matriz[3][4] == "P5")
                ||(matriz[3][4] == "P4") || (matriz[3][4] == "P6")||(matriz[3][4] == "P7") ||(matriz[3][4] == "P8")
                || (matriz[3][4] == "P9")) &&

                ((matriz[4][4] == "P1") || (matriz[4][4] == "P2")|| (matriz[4][4] == "P3")||(matriz[4][4] == "P5")
                ||(matriz[4][4] == "P4") || (matriz[4][4] == "P6")||(matriz[4][4] == "P7") ||(matriz[4][4] == "P8")
                || (matriz[4][4] == "P9"))){
                    val= true;
                }
            }
        }
        if(jugada_X ==3){
            if(jugada_y == 0){
                if(((matriz[0][0] == "P1") || (matriz[0][0] == "P2")|| (matriz[0][0] == "P3") ||(matriz[0][0] == "P5")
                ||(matriz[0][0] == "P4") || (matriz[0][0] == "P6")||(matriz[0][0] == "P7") ||(matriz[0][0] == "P8")
                || (matriz[0][0] == "P9")) &&

                ((matriz[6][0] == "P1") || (matriz[6][0] == "P2")|| (matriz[6][0] == "P3")||(matriz[6][0] == "P5")
                ||(matriz[6][0] == "P4") || (matriz[6][0] == "P6")||(matriz[6][0] == "P7") ||(matriz[6][0] == "P8")
                || (matriz[6][0] == "P9"))){
                    val= true;
                }
                if(((matriz[3][1] == "P1") || (matriz[3][1] == "P2")|| (matriz[3][1] == "P3") ||(matriz[3][1] == "P5")
                ||(matriz[3][1] == "P4") || (matriz[3][1] == "P6")||(matriz[3][1] == "P7") ||(matriz[3][1] == "P8")
                || (matriz[3][1] == "P9")) &&

                ((matriz[3][2] == "P1") || (matriz[3][2] == "P2")|| (matriz[3][2] == "P3") ||(matriz[3][2] == "P5")
                ||(matriz[3][2] == "P4") || (matriz[3][2] == "P6")||(matriz[3][2] == "P7") ||(matriz[3][2] == "P8")
                || (matriz[3][2] == "P9"))){
                    val= true;
                }
            }
            if(jugada_y == 1){
                if(((matriz[1][1] == "P1") || (matriz[1][1] == "P2")|| (matriz[1][1] == "P3") ||(matriz[1][1] == "P5")
                ||(matriz[1][1] == "P4") || (matriz[1][1] == "P6")||(matriz[1][1] == "P7") ||(matriz[1][1] == "P8")
                || (matriz[1][1] == "P9")) &&

               ((matriz[5][1] == "P1") || (matriz[5][1] == "P2")|| (matriz[5][1] == "P3")||(matriz[5][1] == "P5")
                ||(matriz[5][1] == "P4") || (matriz[5][1] == "P6")||(matriz[5][1] == "P7") ||(matriz[5][1] == "P8")
                || (matriz[5][1] == "P9"))){
                    val= true;
                }
                if(((matriz[3][2] == "P1") || (matriz[3][2] == "P2")|| (matriz[3][2] == "P3") ||(matriz[3][2] == "P5")
                ||(matriz[3][2] == "P4") || (matriz[3][2] == "P6")||(matriz[3][2] == "P7") ||(matriz[3][2] == "P8")
                || (matriz[3][2] == "P9")) &&

                ((matriz[3][0] == "P1") || (matriz[3][0] == "P2")|| (matriz[3][0] == "P3") ||(matriz[3][0] == "P5")
                ||(matriz[3][0] == "P4") || (matriz[3][0] == "P6")||(matriz[3][0] == "P7") ||(matriz[3][0] == "P8")
                || (matriz[3][0] == "P9"))){
                    val= true;
                }
            }
            if(jugada_y == 2){
                if(((matriz[2][2] == "P1") || (matriz[2][2] == "P2")|| (matriz[2][2] == "P3") ||(matriz[2][2] == "P5")
                ||(matriz[2][2] == "P4") || (matriz[2][2] == "P6")||(matriz[2][2] == "P7") ||(matriz[2][2] == "P8")
                || (matriz[2][2] == "P9")) &&
                
                ((matriz[4][2] == "P1") || (matriz[4][2] == "P2")|| (matriz[4][2] == "P3")||(matriz[4][2] == "P5")
                ||(matriz[4][2] == "P4") || (matriz[4][2] == "P6")||(matriz[4][2] == "P7") ||(matriz[4][2] == "P8")
                || (matriz[4][2] == "P9"))){
                    val= true;
                }
                if(((matriz[3][1] == "P1") || (matriz[3][1] == "P2")|| (matriz[3][1] == "P3") ||(matriz[3][1] == "P5")
                ||(matriz[3][1] == "P4") || (matriz[3][1] == "P6")||(matriz[3][1] == "P7") ||(matriz[3][1] == "P8")
                || (matriz[3][1] == "P9")) &&

                ((matriz[3][0] == "P1") || (matriz[3][0] == "P2")|| (matriz[3][0] == "P3") ||(matriz[3][0] == "P5")
                ||(matriz[3][0] == "P4") || (matriz[3][0] == "P6")||(matriz[3][0] == "P7") ||(matriz[3][0] == "P8")
                || (matriz[3][0] == "P9"))){
                    val= true;
                }

            }
            if(jugada_y == 4){
                if(((matriz[4][4] == "P1") || (matriz[4][4] == "P2")|| (matriz[4][4] == "P3")||(matriz[4][4] == "P5")
                ||(matriz[4][4] == "P4") || (matriz[4][4] == "P6")||(matriz[4][4] == "P7") ||(matriz[4][4] == "P8")
                || (matriz[4][4] == "P9")) &&

                ((matriz[2][4] == "P1") || (matriz[2][4] == "P2")|| (matriz[2][4] == "P3")||(matriz[2][4] == "P5")
                ||(matriz[2][4] == "P4") || (matriz[2][4] == "P6")||(matriz[2][4] == "P7") ||(matriz[2][4] == "P8")
                || (matriz[2][4] == "P9"))){
                    val= true;
                }
                if(((matriz[3][5] == "P1") || (matriz[3][5] == "P2")|| (matriz[3][5] == "P3") ||(matriz[3][5] == "P5")
                ||(matriz[3][5] == "P4") || (matriz[3][5] == "P6")||(matriz[3][5] == "P7") ||(matriz[3][5] == "P8")
                || (matriz[3][5] == "P9")) &&

                ((matriz[3][6] == "P1") || (matriz[3][6] == "P2")|| (matriz[3][6] == "P3") ||(matriz[3][6] == "P5")
                ||(matriz[3][6] == "P4") || (matriz[3][6] == "P6")||(matriz[3][6] == "P7") ||(matriz[3][6] == "P8")
                || (matriz[3][6] == "P9"))){
                    val= true;
                }
            }
            if(jugada_y == 5){
                if(((matriz[3][4] == "P1") || (matriz[3][4] == "P2")|| (matriz[3][4] == "P3") ||(matriz[3][4] == "P5")
                ||(matriz[3][4] == "P4") || (matriz[3][4] == "P6")||(matriz[3][4] == "P7") ||(matriz[3][4] == "P8")
                || (matriz[3][4] == "P9")) &&

               ((matriz[3][6] == "P1") || (matriz[3][6] == "P2")|| (matriz[3][6] == "P3") ||(matriz[3][6] == "P5")
                ||(matriz[3][6] == "P4") || (matriz[3][6] == "P6")||(matriz[3][6] == "P7") ||(matriz[3][6] == "P8")
                || (matriz[3][6] == "P9"))){
                    val= true;
                }
                if(((matriz[5][5] == "P1") || (matriz[5][5] == "P2")|| (matriz[5][5] == "P3")||(matriz[5][5] == "P5")
                ||(matriz[5][5] == "P4") || (matriz[5][5] == "P6")||(matriz[5][5] == "P7") ||(matriz[5][5] == "P8")
                || (matriz[5][5] == "P9")) &&

                ((matriz[1][5] == "P1") || (matriz[1][5] == "P2")|| (matriz[1][5] == "P3")||(matriz[1][5] == "P5")
                ||(matriz[1][5] == "P4") || (matriz[1][5] == "P6")||(matriz[1][5] == "P7") ||(matriz[1][5] == "P8")
                || (matriz[1][5] == "P9"))){
                    val= true;
                }
            }
            if(jugada_y == 6){
                if(((matriz[3][4] == "P1") || (matriz[3][4] == "P2")|| (matriz[3][4] == "P3") ||(matriz[3][4] == "P5")
                ||(matriz[3][4] == "P4") || (matriz[3][4] == "P6")||(matriz[3][4] == "P7") ||(matriz[3][4] == "P8")
                || (matriz[3][4] == "P9")) &&
                
                ((matriz[3][5] == "P1") || (matriz[3][5] == "P2")|| (matriz[3][5] == "P3") ||(matriz[3][5] == "P5")
                ||(matriz[3][5] == "P4") || (matriz[3][5] == "P6")||(matriz[3][5] == "P7") ||(matriz[3][5] == "P8")
                || (matriz[3][5] == "P9"))){
                    val= true;
                }
                if(((matriz[6][6] == "P1") || (matriz[6][6] == "P2")|| (matriz[6][6] == "P3")||(matriz[6][6] == "P5")
                ||(matriz[6][6] == "P4") || (matriz[6][6] == "P6")||(matriz[6][6] == "P7") ||(matriz[6][6] == "P8")
                || (matriz[6][6] == "P9")) &&

                ((matriz[0][6] == "P1") || (matriz[0][6] == "P2")|| (matriz[0][6] == "P3")||(matriz[0][6] == "P5")
                ||(matriz[0][6] == "P4") || (matriz[0][6] == "P6")||(matriz[0][6] == "P7") ||(matriz[0][6] == "P8")
                || (matriz[0][6] == "P9"))){
                    val= true;
                }
            }
        }
        if(jugada_X ==4){
            if(jugada_y == 2){
                if(((matriz[2][2] == "P1") || (matriz[2][2] == "P2")|| (matriz[2][2] == "P3") ||(matriz[2][2] == "P5")
                ||(matriz[2][2] == "P4") || (matriz[2][2] == "P6")||(matriz[2][2] == "P7") ||(matriz[2][2] == "P8")
                || (matriz[2][2] == "P9")) &&

               ((matriz[3][2] == "P1") || (matriz[3][2] == "P2")|| (matriz[3][2] == "P3") ||(matriz[3][2] == "P5")
                ||(matriz[3][2] == "P4") || (matriz[3][2] == "P6")||(matriz[3][2] == "P7") ||(matriz[3][2] == "P8")
                || (matriz[3][2] == "P9"))){
                    val= true;
                }
                if(((matriz[4][4] == "P1") || (matriz[4][4] == "P2")|| (matriz[4][4] == "P3")||(matriz[4][4] == "P5")
                ||(matriz[4][4] == "P4") || (matriz[4][4] == "P6")||(matriz[4][4] == "P7") ||(matriz[4][4] == "P8")
                || (matriz[4][4] == "P9")) &&

                ((matriz[4][3] == "P1") || (matriz[4][3] == "P2")|| (matriz[4][3] == "P3")||(matriz[4][3] == "P5")
                ||(matriz[4][3] == "P4") || (matriz[4][3] == "P6")||(matriz[4][3] == "P7") ||(matriz[4][3] == "P8")
                || (matriz[4][3] == "P9"))){
                    val= true;
                }
            }
            if(jugada_y == 3){
                if(((matriz[4][2] == "P1") || (matriz[4][2] == "P2")|| (matriz[4][2] == "P3")||(matriz[4][2] == "P5")
                ||(matriz[4][2] == "P4") || (matriz[4][2] == "P6")||(matriz[4][2] == "P7") ||(matriz[4][2] == "P8")
                || (matriz[4][2] == "P9")) &&

               (((matriz[4][4] == "P1") || (matriz[4][4] == "P2")|| (matriz[4][4] == "P3")||(matriz[4][4] == "P5")
                ||(matriz[4][4] == "P4") || (matriz[4][4] == "P6")||(matriz[4][4] == "P7") ||(matriz[4][4] == "P8")
                || (matriz[4][4] == "P9")))){
                    val= true;
                }
                if(((matriz[5][3] == "P1") || (matriz[5][3] == "P2")|| (matriz[5][3] == "P3") ||(matriz[5][3] == "P5")
                ||(matriz[5][3] == "P4") || (matriz[5][3] == "P6")||(matriz[5][3] == "P7") ||(matriz[5][3] == "P8")
                || (matriz[5][3] == "P9")) &&

                ((matriz[6][3] == "P1") || (matriz[6][3] == "P2")|| (matriz[6][3] == "P3") ||(matriz[6][3] == "P5")
                ||(matriz[6][3] == "P4") || (matriz[6][3] == "P6")||(matriz[6][3] == "P7") ||(matriz[6][3] == "P8")
                || (matriz[6][3] == "P9"))){
                    val= true;
                }
            }
            if(jugada_y == 4){
                if(((matriz[2][4] == "P1") || (matriz[2][4] == "P2")|| (matriz[2][4] == "P3")||(matriz[2][4] == "P5")
                ||(matriz[2][4] == "P4") || (matriz[2][4] == "P6")||(matriz[2][4] == "P7") ||(matriz[2][4] == "P8")
                || (matriz[2][4] == "P9")) &&
                
                ((matriz[3][4] == "P1") || (matriz[3][4] == "P2")|| (matriz[3][4] == "P3") ||(matriz[3][4] == "P5")
                ||(matriz[3][4] == "P4") || (matriz[3][4] == "P6")||(matriz[3][4] == "P7") ||(matriz[3][4] == "P8")
                || (matriz[3][4] == "P9"))){
                    val= true;
                }
                if(((matriz[4][2] == "P1") || (matriz[4][2] == "P2")|| (matriz[4][2] == "P3")||(matriz[4][2] == "P5")
                ||(matriz[4][2] == "P4") || (matriz[4][2] == "P6")||(matriz[4][2] == "P7") ||(matriz[4][2] == "P8")
                || (matriz[4][2] == "P9")) &&

                ((matriz[4][3] == "P1") || (matriz[4][3] == "P2")|| (matriz[4][3] == "P3")||(matriz[4][3] == "P5")
                ||(matriz[4][3] == "P4") || (matriz[4][3] == "P6")||(matriz[4][3] == "P7") ||(matriz[4][3] == "P8")
                || (matriz[4][3] == "P9"))){
                    val= true;
                }
            }
        }
        if(jugada_X ==5){
            if(jugada_y == 1){
                if(((matriz[1][1] == "P1") || (matriz[1][1] == "P2")|| (matriz[1][1] == "P3") ||(matriz[1][1] == "P5")
                ||(matriz[1][1] == "P4") || (matriz[1][1] == "P6")||(matriz[1][1] == "P7") ||(matriz[1][1] == "P8")
                || (matriz[1][1] == "P9")) &&

                ((matriz[3][1] == "P1") || (matriz[3][1] == "P2")|| (matriz[3][1] == "P3") ||(matriz[3][1] == "P5")
                ||(matriz[3][1] == "P4") || (matriz[3][1] == "P6")||(matriz[3][1] == "P7") ||(matriz[3][1] == "P8")
                || (matriz[3][1] == "P9"))){
                    val= true;
                }
                if(((matriz[5][3] == "P1") || (matriz[5][3] == "P2")|| (matriz[5][3] == "P3") ||(matriz[5][3] == "P5")
                ||(matriz[5][3] == "P4") || (matriz[5][3] == "P6")||(matriz[5][3] == "P7") ||(matriz[5][3] == "P8")
                || (matriz[5][3] == "P9")) &&

                ((matriz[5][5] == "P1") || (matriz[5][5] == "P2")|| (matriz[5][5] == "P3")||(matriz[5][5] == "P5")
                ||(matriz[5][5] == "P4") || (matriz[5][5] == "P6")||(matriz[5][5] == "P7") ||(matriz[5][5] == "P8")
                || (matriz[5][5] == "P9"))){
                    val= true;
                }
            }
            if(jugada_y == 3){
                if(((matriz[5][1] == "P1") || (matriz[5][1] == "P2")|| (matriz[5][1] == "P3")||(matriz[5][1] == "P5")
                ||(matriz[5][1] == "P4") || (matriz[5][1] == "P6")||(matriz[5][1] == "P7") ||(matriz[5][1] == "P8")
                || (matriz[5][1] == "P9")) &&

               ((matriz[5][5] == "P1") || (matriz[5][5] == "P2")|| (matriz[5][5] == "P3")||(matriz[5][5] == "P5")
                ||(matriz[5][5] == "P4") || (matriz[5][5] == "P6")||(matriz[5][5] == "P7") ||(matriz[5][5] == "P8")
                || (matriz[5][5] == "P9"))){
                    val= true;
                }
                if(((matriz[6][3] == "P1") || (matriz[6][3] == "P2")|| (matriz[6][3] == "P3") ||(matriz[6][3] == "P5")
                ||(matriz[6][3] == "P4") || (matriz[6][3] == "P6")||(matriz[6][3] == "P7") ||(matriz[6][3] == "P8")
                || (matriz[6][3] == "P9")) &&

                ((matriz[4][3] == "P1") || (matriz[4][3] == "P2")|| (matriz[4][3] == "P3")||(matriz[4][3] == "P5")
                ||(matriz[4][3] == "P4") || (matriz[4][3] == "P6")||(matriz[4][3] == "P7") ||(matriz[4][3] == "P8")
                || (matriz[4][3] == "P9"))){
                    val= true;
                }
            }
            if(jugada_y == 5){
                if(((matriz[5][3] == "P1") || (matriz[5][3] == "P2")|| (matriz[5][3] == "P3") ||(matriz[5][3] == "P5")
                ||(matriz[5][3] == "P4") || (matriz[5][3] == "P6")||(matriz[5][3] == "P7") ||(matriz[5][3] == "P8")
                || (matriz[5][3] == "P9")) &&
                
                ((matriz[5][1] == "P1") || (matriz[5][1] == "P2")|| (matriz[5][1] == "P3")||(matriz[5][1] == "P5")
                ||(matriz[5][1] == "P4") || (matriz[5][1] == "P6")||(matriz[5][1] == "P7") ||(matriz[5][1] == "P8")
                || (matriz[5][1] == "P9"))){
                    val= true;
                }
               if(((matriz[3][5] == "P1") || (matriz[3][5] == "P2")|| (matriz[3][5] == "P3") ||(matriz[3][5] == "P5")
                ||(matriz[3][5] == "P4") || (matriz[3][5] == "P6")||(matriz[3][5] == "P7") ||(matriz[3][5] == "P8")
                || (matriz[3][5] == "P9")) &&

               ((matriz[1][5] == "P1") || (matriz[1][5] == "P2")|| (matriz[1][5] == "P3")||(matriz[1][5] == "P5")
                ||(matriz[1][5] == "P4") || (matriz[1][5] == "P6")||(matriz[1][5] == "P7") ||(matriz[1][5] == "P8")
                || (matriz[1][5] == "P9"))){
                    val= true;
                }
            }
        }        
        if(jugada_X ==6){
            if(jugada_y == 0){
                if(((matriz[6][3] == "P1") || (matriz[6][3] == "P2")|| (matriz[6][3] == "P3") ||(matriz[6][3] == "P5")
                ||(matriz[6][3] == "P4") || (matriz[6][3] == "P6")||(matriz[6][3] == "P7") ||(matriz[6][3] == "P8")
                || (matriz[6][3] == "P9")) &&

               ((matriz[6][6] == "P1") || (matriz[6][6] == "P2")|| (matriz[6][6] == "P3")||(matriz[6][6] == "P5")
                ||(matriz[6][6] == "P4") || (matriz[6][6] == "P6")||(matriz[6][6] == "P7") ||(matriz[6][6] == "P8")
                || (matriz[6][6] == "P9"))){
                    val= true;
                }
                if(((matriz[3][0] == "P1") || (matriz[3][0] == "P2")|| (matriz[3][0] == "P3") ||(matriz[3][0] == "P5")
                ||(matriz[3][0] == "P4") || (matriz[3][0] == "P6")||(matriz[3][0] == "P7") ||(matriz[3][0] == "P8")
                || (matriz[3][0] == "P9")) &&

                ((matriz[0][0] == "P1") || (matriz[0][0] == "P2")|| (matriz[0][0] == "P3") ||(matriz[0][0] == "P5")
                ||(matriz[0][0] == "P4") || (matriz[0][0] == "P6")||(matriz[0][0] == "P7") ||(matriz[0][0] == "P8")
                || (matriz[0][0] == "P9"))){
                    val= true;
                }
            }
            if(jugada_y == 3){
                if(((matriz[6][6] == "P1") || (matriz[6][6] == "P2")|| (matriz[6][6] == "P3")||(matriz[6][6] == "P5")
                ||(matriz[6][6] == "P4") || (matriz[6][6] == "P6")||(matriz[6][6] == "P7") ||(matriz[6][6] == "P8")
                || (matriz[6][6] == "P9")) &&

               ((matriz[6][0] == "P1") || (matriz[6][0] == "P2")|| (matriz[6][0] == "P3")||(matriz[6][0] == "P5")
                ||(matriz[6][0] == "P4") || (matriz[6][0] == "P6")||(matriz[6][0] == "P7") ||(matriz[6][0] == "P8")
                || (matriz[6][0] == "P9"))){
                    val= true;
                }
                if(((matriz[5][3] == "P1") || (matriz[5][3] == "P2")|| (matriz[5][3] == "P3") ||(matriz[5][3] == "P5")
                ||(matriz[5][3] == "P4") || (matriz[5][3] == "P6")||(matriz[5][3] == "P7") ||(matriz[5][3] == "P8")
                || (matriz[5][3] == "P9")) &&

                ((matriz[4][3] == "P1") || (matriz[4][3] == "P2")|| (matriz[4][3] == "P3")||(matriz[4][3] == "P5")
                ||(matriz[4][3] == "P4") || (matriz[4][3] == "P6")||(matriz[4][3] == "P7") ||(matriz[4][3] == "P8")
                || (matriz[4][3] == "P9"))){
                    val= true;
                }
            }
            if(jugada_y == 6){
                 if(((matriz[6][3] == "P1") || (matriz[6][3] == "P2")|| (matriz[6][3] == "P3") ||(matriz[6][3] == "P5")
                ||(matriz[6][3] == "P4") || (matriz[6][3] == "P6")||(matriz[6][3] == "P7") ||(matriz[6][3] == "P8")
                || (matriz[6][3] == "P9")) &&
                
                ((matriz[6][0] == "P1") || (matriz[6][0] == "P2")|| (matriz[6][0] == "P3")||(matriz[6][0] == "P5")
                ||(matriz[6][0] == "P4") || (matriz[6][0] == "P6")||(matriz[6][0] == "P7") ||(matriz[6][0] == "P8")
                || (matriz[6][0] == "P9"))){
                    val= true;
                }
                if(((matriz[0][6] == "P1") || (matriz[0][6] == "P2")|| (matriz[0][6] == "P3")||(matriz[0][6] == "P5")
                ||(matriz[0][6] == "P4") || (matriz[0][6] == "P6")||(matriz[0][6] == "P7") ||(matriz[0][6] == "P8")
                || (matriz[0][6] == "P9")) &&

                ((matriz[3][6] == "P1") || (matriz[3][6] == "P2")|| (matriz[3][6] == "P3") ||(matriz[3][6] == "P5")
                ||(matriz[3][6] == "P4") || (matriz[3][6] == "P6")||(matriz[3][6] == "P7") ||(matriz[3][6] == "P8")
                || (matriz[3][6] == "P9"))){
                    val= true;
                }
            }
        }
    if(val == true){
        cout<<"\nHORA DE ELIMINAR UNA FICHA PLAYER 2\n";
        Player p1;
        p1.verificar_disponibles(matriz,disponibles);
        for(int k=0;k<rival;k++){
        cout<<"Ficha "<<matriz[p1.fichas_posX[k]][p1.fichas_posy[k]] <<" #"<<k+1<<endl;
        }
        cout<<"\nDigte el numero de la ficha a eliminar: ";cin>>eliminar;
        rival-=1;
        jugada_X = 99; jugada_y = 99;
        bool por_fin = false;
        for(int i=0; i<7;i++){
            if(por_fin == true){break;}
            for(int j=0; j<7;j++){
                 if(por_fin == true){break;}
                if(i == p1.fichas_posX[eliminar-1] && j== p1.fichas_posy[eliminar-1]){
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