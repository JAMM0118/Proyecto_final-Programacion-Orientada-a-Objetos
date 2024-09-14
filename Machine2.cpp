#include"Machine2.h"

Machine2 :: Machine2(){}
Machine2 :: ~Machine2(){}

int Machine2:: PonerMaquina2(){
    if(salvador2>24){salvador2=1;}
    Pos_Maquina2 = salvador2;
    salvador2++;
    return Pos_Maquina2;
}

void Machine2 :: jugada_libre2(string matriz[7][7], string matriz2[7][7],string disponibles[24]){
    bool val = false;
    for(int i=0;i<7;i++){
        if(val == true){break;}
        for(int j=0;j<7;j++){
            if(val == true){break;}
            if(matriz[i][j] =="X"){
                for(int k=0;k<24;k++){
                    if(val == true){break;}
                    for(int nz=0;nz<24;nz++){
                        if(val == true){break;}
                        if(disponibles[k]== to_string(disponibles_pos_maquina_X2[nz])+to_string(disponibles_pos_maquina_y2[nz])){
                            for(int m=0;m<7;m++){
                                if(val == true){break;}
                                for(int s=0;s<7;s++){
                                    if(matriz[m][s] == disponibles[k]){
                                        matriz[m][s] ="X";
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
}

void Machine2 :: SetFicha2(int ficha){
    fichas_Maquina2 = ficha;
}

void Machine2 :: set_salvador2(int ayuda){
    salvador2 = ayuda;
}

void Machine2:: verificar_posiciones2(string matriz[7][7],string disponibles[24]){
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            if(matriz[i][j] =="X"){
                bool val = false;
                for(int d=0; d<24;d++){
                    if(disponibles[d] != " "){
                        if(matriz[i][j] != disponibles[d]){val = true;}
                        else{val = false;break;}
                    }
                }
                if(val == true){
                    fichas_maquina_x2[contador_posiciones_fichas_maquina2]= i;
                    fichas_maquina_y2[contador_posiciones_fichas_maquina2] = j;
                    contador_posiciones_fichas_maquina2++;
                }  
            }
            for(int l=0; l<24;l++){
                if(matriz[i][j] == disponibles[l]){
                    disponibles_pos_maquina_X2[contador_posiciones_libres2] = i;
                    disponibles_pos_maquina_y2[contador_posiciones_libres2] = j;
                    contador_posiciones_libres2++;
                }
            }
        }
    }
}

void Machine2 :: Set_Ficha_maquina_X2(int &pos_x){
    Ficha_maquina_X2= pos_x;   
}

void Machine2 :: Set_Ficha_maquina_y2(int &pos_y){
    Ficha_maquina_y2= pos_y;   
}

void Machine2 :: Set_disponible_maquina_X2(int &pos_x){
    disponible_maquina_X2= pos_x;
}

void Machine2 :: Set_disponible_maquina_y2(int &pos_Y){
    disponible_maquina_y2= pos_Y;
}

int Machine2 :: Get_Ficha_maquina_X2(){
    return Ficha_maquina_X2;
}

int Machine2 :: Get_Ficha_maquina_y2(){
    return Ficha_maquina_y2;
}

int Machine2 :: Get_disponible_maquina_X2(){
    return disponible_maquina_X2;
}

int Machine2 :: Get_disponible_maquina_y2(){
    return disponible_maquina_y2;
}

void Machine2 :: set_contadore2(int n){
    contadore2 = n;
}

void Machine2 :: jugada_maquina2(string matriz[7][7]){
    bool val = false;
    if(salvatore2 >8){salvatore2=0;}
    int Posicion = salvatore2;
    salvatore2++;
    for(int i=0;i<7;i++){
        if(fichas_maquina_x2[Posicion] == 99){val = true;}
        if(val == true){break;}
        for(int j=0; j<7;j++){
            if(val == true){break;}
            else if((i == fichas_maquina_x2[Posicion]) && (j == fichas_maquina_y2[Posicion])){
                if(i==0){
                    for(int k=0;k<22;k++){
                        if(j==0){
                            if((disponibles_pos_maquina_X2[k] == 0) || (disponibles_pos_maquina_X2[k] == 3)){
                                if(((fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == 0) ||
                                (fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == -3))&&
                                ((fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == 0) ||
                                (fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == -3))){
                                    mandar_datos2(k,Posicion);val = true;break;
                                }
                            }
                        }
                        else if(j==3){
                            if((disponibles_pos_maquina_X2[k] == 0) || (disponibles_pos_maquina_X2[k] == 1)){
                                if(((fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == 0) ||
                                (fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == -1))&&
                                ((fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == 0) ||
                                (fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == -3)||
                                (fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == 3))){
                                    mandar_datos2(k,Posicion);val = true;break;
                                }
                            }
                        }
                        else if(j==6){
                            if((disponibles_pos_maquina_X2[k] == 0) || (disponibles_pos_maquina_X2[k] == 3)){
                                if(((fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == 0) ||
                                (fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == -3))&&
                                ((fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == 0) ||
                                (fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == 3))){
                                    mandar_datos2(k,Posicion);val = true;break;
                                }
                            }
                        }   
                    }
                }
                else if(i==1){
                    for(int k=0;k<22;k++){
                        if(j==1){
                            if((disponibles_pos_maquina_X2[k] == 1) || (disponibles_pos_maquina_X2[k] == 3)){
                                if(((fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == 0) ||
                                (fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == -2))&&
                                ((fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == 0) ||
                                (fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == -2))){
                                    mandar_datos2(k,Posicion);val = true;break;
                                }
                            }
                        }
                        else if(j==3){
                            if((disponibles_pos_maquina_X2[k] == 0) || (disponibles_pos_maquina_X2[k] == 1)
                            || (disponibles_pos_maquina_X2[k] == 2)){
                                if(((fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == 0) ||
                                (fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == -1)||
                                (fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == 1))&&
                                ((fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == 0) ||
                                (fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == -2)||
                                (fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == 2))){
                                    mandar_datos2(k,Posicion);val = true;break;
                                }
                            }
                        }
                        else if(j==5){
                            if((disponibles_pos_maquina_X2[k] == 1) || (disponibles_pos_maquina_X2[k] == 3)){
                                if(((fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == 0) ||
                                (fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == -2))&&
                                ((fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == 0) ||
                                (fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == 2))){
                                    mandar_datos2(k,Posicion);val = true;break;
                                }
                            }
                        }   
                    }
                }else if(i==2){
                    for(int k=0;k<22;k++){
                        if(j==2){
                            if((disponibles_pos_maquina_X2[k] == 2) || (disponibles_pos_maquina_X2[k] == 3)){
                                if(((fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == 0) ||
                                (fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == -1))&&
                                ((fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == 0) ||
                                (fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == -1))){
                                    mandar_datos2(k,Posicion);val = true;break;
                                }
                            }
                        }
                        else if(j==3){
                            if((disponibles_pos_maquina_X2[k] == 2) || (disponibles_pos_maquina_X2[k] == 1)){
                                if(((fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == 0) ||
                                (fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == 1))&&
                                ((fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == 0) ||
                                (fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == -1)||
                                (fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == 1))){
                                    mandar_datos2(k,Posicion);val = true;break;
                                }
                            }
                        }
                        else if(j==4){
                            if((disponibles_pos_maquina_X2[k] == 2) || (disponibles_pos_maquina_X2[k] == 3)){
                                if(((fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == 0) ||
                                (fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == -1))&&
                                ((fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == 0) ||
                                (fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == 1))){
                                    mandar_datos2(k,Posicion);val = true;break;
                                }
                            }
                        }   
                    }
                }else if(i==3){
                    for(int k=0;k<22;k++){
                        if(j==0){
                            if((disponibles_pos_maquina_X2[k] == 0) || (disponibles_pos_maquina_X2[k] == 3)
                            || (disponibles_pos_maquina_X2[k] == 6)){
                                if(((fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == 0) ||
                                (fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == -3)
                                || (fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == 3))&&
                                ((fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == 0) ||
                                (fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == -1))){
                                    mandar_datos2(k,Posicion);val = true;break;
                                }
                            }
                        }
                        else if(j==1){
                            if((disponibles_pos_maquina_X2[k] == 1) || (disponibles_pos_maquina_X2[k] == 3)
                            || (disponibles_pos_maquina_X2[k] == 5)){
                                if(((fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == 0) ||
                                (fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == 2)
                                ||(fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == -2))&&
                                ((fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == 0) ||
                                (fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == -1)||
                                (fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == 1))){
                                    mandar_datos2(k,Posicion);val = true;break;
                                }
                            }
                        }
                        else if(j==2){
                            if((disponibles_pos_maquina_X2[k] == 2) || (disponibles_pos_maquina_X2[k] == 3)
                            || (disponibles_pos_maquina_X2[k] == 4)){
                                if(((fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == 0) ||
                                (fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == 1)||
                                (fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == -1))&&
                                ((fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == 0) ||
                                (fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == 1))){
                                    mandar_datos2(k,Posicion);val = true;break;
                                }
                            }
                        }
                        else if(j==4){
                            if((disponibles_pos_maquina_X2[k] == 2) || (disponibles_pos_maquina_X2[k] == 3)
                            || (disponibles_pos_maquina_X2[k] == 4)){
                                if(((fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == 0) ||
                                (fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == 1)||
                                (fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == -1))&&
                                ((fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == 0) ||
                                (fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == -1))){
                                    mandar_datos2(k,Posicion);val = true;break;
                                }
                            }
                        }
                        else if(j==5){
                            if((disponibles_pos_maquina_X2[k] == 1) || (disponibles_pos_maquina_X2[k] == 3)
                            || (disponibles_pos_maquina_X2[k] == 5)){
                                if(((fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == 0) ||
                                (fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == 2)||
                                (fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == -2))&&
                                ((fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == 0) ||
                                (fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == 1)||
                                (fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == -1))){
                                    mandar_datos2(k,Posicion);val = true;break;
                                }
                            }
                        }
                        else if(j==6){
                            if((disponibles_pos_maquina_X2[k] == 0) || (disponibles_pos_maquina_X2[k] == 3)
                            || (disponibles_pos_maquina_X2[k] == 6)){
                                if(((fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == 0) ||
                                (fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == 3)||
                                (fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == -3))&&
                                ((fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == 0) ||
                                (fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == 1))){
                                    mandar_datos2(k,Posicion);val = true;break;
                                }
                            }
                        }   
                    }
                }else if(i==4){
                    for(int k=0;k<22;k++){
                        if(j==2){
                            if((disponibles_pos_maquina_X2[k] == 4) || (disponibles_pos_maquina_X2[k] == 3)){
                                if(((fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == 0) ||
                                (fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == 1))&&
                                ((fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == 0) ||
                                (fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == -1))){
                                    mandar_datos2(k,Posicion);val = true;break;
                                }
                            }
                        }
                        else if(j==3){
                            if((disponibles_pos_maquina_X2[k] == 4) || (disponibles_pos_maquina_X2[k] == 5)){
                                if(((fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == 0) ||
                                (fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == -1))&&
                                ((fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == 0) ||
                                (fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == -1)||
                                (fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == 1))){  
                                    mandar_datos2(k,Posicion);val = true;break;
                                }
                            }
                        }
                        else if(j==4){
                            if((disponibles_pos_maquina_X2[k] == 4) || (disponibles_pos_maquina_X2[k] == 3)){
                                if(((fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == 0) ||
                                (fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == 1))&&
                                ((fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == 0) ||
                                (fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == 1))){
                                    mandar_datos2(k,Posicion);val = true;break;
                                }
                            }
                        }   
                    }
                }else if(i==5){
                    for(int k=0;k<22;k++){
                        if(j==1){
                            if((disponibles_pos_maquina_X2[k] == 5) || (disponibles_pos_maquina_X2[k] == 3)){
                                if(((fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == 0) ||
                                (fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == 2))&&
                                ((fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == 0) ||
                                (fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == -2))){
                                   mandar_datos2(k,Posicion);val = true;break;
                                }
                            }
                        }
                        else if(j==3){
                            if((disponibles_pos_maquina_X2[k] == 5) || (disponibles_pos_maquina_X2[k] == 4)
                            || (disponibles_pos_maquina_X2[k] == 6)){
                                if(((fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == 0) ||
                                (fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == -1)||
                                (fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == 1))&&
                                ((fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == 0) ||
                                (fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == -2)||
                                (fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == 2))){
                                    mandar_datos2(k,Posicion);val = true;break;
                                }
                            }
                        }
                        else if(j==5){
                            if((disponibles_pos_maquina_X2[k] == 5) || (disponibles_pos_maquina_X2[k] == 3)){
                                if(((fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == 0) ||
                                (fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == 2))&&
                                ((fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == 0) ||
                                (fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == 2))){
                                    mandar_datos2(k,Posicion);val = true;break;
                                }
                            }
                        }   
                    }
                }else if(i==6){
                    for(int k=0;k<22;k++){
                        if(j==0){
                            if((disponibles_pos_maquina_X2[k] == 6) || (disponibles_pos_maquina_X2[k] == 3)){
                                if(((fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == 0) ||
                                (fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == 3))&&
                                ((fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == 0) ||
                                (fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == -3))){
                                    mandar_datos2(k,Posicion);val = true;break;
                                }
                            }
                        }
                        else if(j==3){
                            if((disponibles_pos_maquina_X2[k] == 5) || (disponibles_pos_maquina_X2[k] == 6)){
                                if(((fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == 0) ||
                                (fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == 1))&&
                                ((fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == 0) ||
                                (fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == -3)||
                                (fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == 3))){
                                    mandar_datos2(k,Posicion);val = true;break;
                                }
                            }
                        }
                        else if(j==6){
                            if((disponibles_pos_maquina_X2[k] == 6) || (disponibles_pos_maquina_X2[k] == 3)){
                                if(((fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == 0) ||
                                (fichas_maquina_x2[Posicion] - disponibles_pos_maquina_X2[k] == 3))&&
                                ((fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == 0) ||
                                (fichas_maquina_y2[Posicion] - disponibles_pos_maquina_y2[k] == 3))){
                                    mandar_datos2(k,Posicion);val = true;break;
                                }
                            }
                        }   
                    }
                }
            }
        }
    }
    if(contadore2 ==0){
        jugada_maquina2(matriz);
    }
}

void Machine2 :: eliminar2(string matriz[7][7],string matriz2[7][7],int &jugada_X,int &jugada_y,int &rival,string disponibles[24]){
    int eliminar=0;
    bool val= false;
        if(jugada_X ==0){
            if(jugada_y == 0){
                if((matriz[0][3] =="X")  && (matriz[0][6] =="X")){val= true;}

                if((matriz[3][0] =="X")  &&  (matriz[6][0] =="X")){val= true;}
            }
            if(jugada_y == 3){
                if((matriz[0][0] =="X") && (matriz[0][6] =="X")){val= true;}
                
                if((matriz[1][3] =="X") && (matriz[2][3] =="X")){val= true;}
            }
            if(jugada_y == 6){
                if((matriz[0][0] =="X") && (matriz[0][3] =="X") ){val= true;}
                
                if((matriz[3][6] =="X") && (matriz[6][6] =="X")){val= true;}
            }
        }
        if(jugada_X ==1){
            if(jugada_y == 1){
                if((matriz[1][3] =="X") && (matriz[1][5] =="X")){val= true;}

                if((matriz[3][1] =="X") && (matriz[5][1] =="X")){val= true;}
            }
            if(jugada_y == 3){
                if((matriz[1][1] =="X") && (matriz[1][5] =="X")){val= true;}

                if((matriz[0][3] =="X") &&  (matriz[2][3] =="X")){
                    val= true;
                }
            }
            if(jugada_y == 5){
                if((matriz[1][1] =="X")  && (matriz[1][3] =="X")){
                    val= true;
                }
                if((matriz[3][5] =="X")  && (matriz[5][5] =="X")){
                    val= true;
                }
            }
        }
        if(jugada_X ==2){
            if(jugada_y == 2){
                if((matriz[2][3] =="X")  &&  (matriz[2][4] =="X")){
                    val= true;
                }
                if((matriz[3][2] =="X") && (matriz[4][2] =="X")){
                    val= true;
                }
            }
            if(jugada_y == 3){
                if((matriz[2][2] =="X")  && (matriz[2][4] =="X")){
                    val= true;
                }
                if((matriz[0][3] =="X") &&(matriz[1][3] =="X")){
                    val= true;
                }
            }
            if(jugada_y == 4){
                if((matriz[2][2] =="X") &&(matriz[2][3] =="X")){
                    val= true;
                }
                if((matriz[3][4] =="X")  && (matriz[4][4] =="X")){
                    val= true;
                }
            }
        }
        if(jugada_X ==3){
            if(jugada_y == 0){
                if((matriz[0][0] =="X") && (matriz[6][0] =="X")){
                    val= true;
                }
                if((matriz[3][1] =="X")  && (matriz[3][2] =="X")){
                    val= true;
                }
            }
            if(jugada_y == 1){
                if((matriz[1][1] =="X") &&(matriz[5][1] =="X")){
                    val= true;
                }
                if((matriz[3][2] =="X") &&(matriz[3][0] =="X")){
                    val= true;
                }
            }
            if(jugada_y == 2){
                if((matriz[2][2] =="X") &&(matriz[4][2] =="X")){
                    val= true;
                }
                if((matriz[3][1] =="X")  && (matriz[3][0] =="X")){
                    val= true;
                }
            }
            if(jugada_y == 4){
                if((matriz[4][4] =="X")  &&(matriz[2][4] =="X")){
                    val= true;
                }
                if((matriz[3][5] =="X") && (matriz[3][6] =="X")){
                    val= true;
                }
            }
            if(jugada_y == 5){
                if((matriz[3][4] =="X") &&(matriz[3][6] =="X")){
                    val= true;
                }
                if((matriz[5][5] =="X") &&(matriz[1][5] =="X")){
                    val= true;
                }
            }
            if(jugada_y == 6){
                if((matriz[3][4] =="X") && (matriz[3][5] =="X")){
                    val= true;
                }
                if((matriz[6][6] =="X") &&(matriz[0][6] =="X")){
                    val= true;
                }
            }
        }
        if(jugada_X ==4){
            if(jugada_y == 2){
                if((matriz[2][2] =="X") &&(matriz[3][2] =="X")){
                    val= true;
                }
                if((matriz[4][4] =="X") &&(matriz[4][3] =="X")){
                    val= true;
                }
            }
            if(jugada_y == 3){
                if((matriz[4][2] =="X") &&(matriz[4][4] =="X")){
                    val= true;
                }
                if((matriz[5][3] =="X") && (matriz[6][3] =="X")){
                    val= true;
                }
            }
            if(jugada_y == 4){
                if((matriz[2][4] =="X")  &&(matriz[3][4] =="X")){
                    val= true;
                }
                if((matriz[4][2] =="X") &&(matriz[4][3] =="X")){
                    val= true;
                }
            }
        }
        if(jugada_X ==5){
            if(jugada_y == 1){
                if((matriz[1][1] =="X") &&(matriz[3][1] =="X")){
                    val= true;
                }
                if((matriz[5][3] =="X") &&(matriz[5][5] =="X")){
                    val= true;
                }
            }
            if(jugada_y == 3){
                if((matriz[5][1] =="X") && (matriz[5][5] =="X")){
                    val= true;
                }
                if((matriz[6][3] =="X") &&(matriz[4][3] =="X")){
                    val= true;
                }
            }
            if(jugada_y == 5){
                if((matriz[5][3] =="X") &&(matriz[5][1] =="X")){
                    val= true;
                }
               if((matriz[3][5] =="X")  && (matriz[1][5] =="X")){
                    val= true;
                }
            }
        }
           if(jugada_X ==6){
            if(jugada_y == 0){
                if((matriz[6][3] =="X") && (matriz[6][6] =="X")){
                    val= true;
                }
                if((matriz[3][0] =="X") &&(matriz[0][0] =="X")){
                    val= true;
                }
            }
            if(jugada_y == 3){
                if((matriz[6][6] =="X")  && (matriz[6][0] =="X") ){
                    val= true;
                }
                if((matriz[5][3] =="X")  && (matriz[4][3] =="X") ){
                    val= true;
                }
            }
            if(jugada_y == 6){
                 if((matriz[6][3] =="X") && (matriz[6][0] =="X")){
                    val= true;
                }
                if((matriz[0][6] =="X") && (matriz[3][6] =="X")){
                    val= true;
                }
            }
        }
        if(val == true){
            Machine m1;
            m1.verificar_posiciones(matriz,disponibles);
            rival-=1;
            jugada_X = 99; jugada_y = 99;
            bool por_fin = false;
            for(int i=0; i<7;i++){
                if(por_fin == true){break;}
                for(int j=0; j<7;j++){
                    if(por_fin == true){break;}
                    if((i == m1.fichas_maquina_x[eliminar]) && (j== m1.fichas_maquina_y[eliminar])){
                        matriz[i][j] = matriz2[i][j];
                        for(int s=0;s<24;s++){
                            if(disponibles[s] == " "){
                                disponibles[s] =matriz2[i][j];por_fin = true;break;
                            }
                        }
                    }
                }
            }
            cout<<"\nES EL TURNO DE LA MAQUINA DE ELIMINAR UNA FICHA :'V\n";
            sleep(1.4);   
        }
    }


void Machine2 :: mandar_datos2(int &k, int &Posicion){
    Set_disponible_maquina_X2(disponibles_pos_maquina_X2[k]); 
    Set_disponible_maquina_y2(disponibles_pos_maquina_y2[k]); 
    Set_Ficha_maquina_X2(fichas_maquina_x2[Posicion]);
    Set_Ficha_maquina_y2(fichas_maquina_y2[Posicion]);
    contadore2++;
}