#include"Machine.h"

Machine :: Machine(){}
Machine :: ~Machine(){}

int Machine :: PonerMaquina(){
    if(salvador>24){salvador=1;}
    Pos_Maquina = salvador;
    salvador++;
    return Pos_Maquina;
}

void Machine :: jugada_libre(string matriz[7][7], string matriz2[7][7],string disponibles[24]){
    bool val = false;
    for(int i=0;i<7;i++){
        if(val == true){break;}
        for(int j=0;j<7;j++){
            if(val == true){break;}
            if(matriz[i][j] == "O"){
                for(int k=0;k<24;k++){
                    if(val == true){break;}
                    for(int nz=0;nz<24;nz++){
                        if(val == true){break;}
                        if(disponibles[k]== to_string(disponibles_pos_maquina_X[nz])+to_string(disponibles_pos_maquina_y[nz])){
                            for(int m=0;m<7;m++){
                                if(val == true){break;}
                                for(int s=0;s<7;s++){
                                    if(matriz[m][s] == disponibles[k]){
                                        matriz[m][s] = "O";
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

void Machine :: SetFicha(int ficha){
    fichas_Maquina = ficha;
}

void Machine :: set_salvador(int ayuda){
    salvador = ayuda;
}

void Machine:: verificar_posiciones(string matriz[7][7],string disponibles[24]){
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            if(matriz[i][j] == "O"){
                bool val = false;
                for(int d=0; d<24;d++){
                    if(disponibles[d] != " "){
                        if(matriz[i][j] != disponibles[d]){val = true;}
                        else{val = false;break;}
                    }
                }
                if(val == true){
                    fichas_maquina_x[contador_posiciones_fichas_maquina]= i;
                    fichas_maquina_y[contador_posiciones_fichas_maquina] = j;
                    contador_posiciones_fichas_maquina++;
                }
            }
            for(int l=0; l<24;l++){
                if(matriz[i][j] == disponibles[l]){
                    disponibles_pos_maquina_X[contador_posiciones_libres] = i;
                    disponibles_pos_maquina_y[contador_posiciones_libres] = j;
                    contador_posiciones_libres++;
                }
            }
        }
    }
}

void Machine :: Set_Ficha_maquina_X(int &pos_x){
    Ficha_maquina_X= pos_x;
}

void Machine :: Set_Ficha_maquina_y(int &pos_y){
    Ficha_maquina_y= pos_y;
}

void Machine :: Set_disponible_maquina_X(int &pos_x){
    disponible_maquina_X= pos_x;
}

void Machine :: Set_disponible_maquina_y(int &pos_Y){
    disponible_maquina_y= pos_Y;
}

int Machine :: Get_Ficha_maquina_X(){
    return Ficha_maquina_X;
}

int Machine :: Get_Ficha_maquina_y(){
    return Ficha_maquina_y;
}

int Machine :: Get_disponible_maquina_X(){
    return disponible_maquina_X;
}

int Machine :: Get_disponible_maquina_y(){
    return disponible_maquina_y;
}

void Machine :: set_contadore(int n){
    contadore = n;
}

void Machine :: jugada_maquina(string matriz[7][7]){
    bool val = false;
    if(salvatore >8){salvatore=0;}
    int Posicion = salvatore;
    salvatore++;
    for(int i=0;i<7;i++){
        if(fichas_maquina_x[Posicion] == 99){val = true;}
        if(val == true){break;}
        for(int j=0; j<7;j++){
            if(val == true){break;}
            else if((i == fichas_maquina_x[Posicion]) && (j == fichas_maquina_y[Posicion])){
                if(i==0){
                    for(int k=0;k<22;k++){
                        if(j==0){
                            if((disponibles_pos_maquina_X[k] == 0) || (disponibles_pos_maquina_X[k] == 3)){
                                if(((fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == 0) ||
                                (fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == -3))&&
                                ((fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == 0) ||
                                (fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == -3))){
                                    mandar_datos(k,Posicion);val = true;break;
                                }
                            }
                        }
                        else if(j==3){
                            if((disponibles_pos_maquina_X[k] == 0) || (disponibles_pos_maquina_X[k] == 1)){
                                if(((fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == 0) ||
                                (fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == -1))&&
                                ((fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == 0) ||
                                (fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == -3)||
                                (fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == 3))){
                                    mandar_datos(k,Posicion);val = true;break;
                                }
                            }
                        }
                        else if(j==6){
                            if((disponibles_pos_maquina_X[k] == 0) || (disponibles_pos_maquina_X[k] == 3)){
                                if(((fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == 0) ||
                                (fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == -3))&&
                                ((fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == 0) ||
                                (fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == 3))){
                                    mandar_datos(k,Posicion);val = true;break;
                                }
                            }
                        }
                    }
                }
                else if(i==1){
                    for(int k=0;k<22;k++){
                        if(j==1){
                            if((disponibles_pos_maquina_X[k] == 1) || (disponibles_pos_maquina_X[k] == 3)){
                                if(((fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == 0) ||
                                (fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == -2))&&
                                ((fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == 0) ||
                                (fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == -2))){
                                    mandar_datos(k,Posicion);val = true;break;
                                }
                            }
                        }
                        else if(j==3){
                            if((disponibles_pos_maquina_X[k] == 0) || (disponibles_pos_maquina_X[k] == 1)
                            || (disponibles_pos_maquina_X[k] == 2)){
                                if(((fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == 0) ||
                                (fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == -1)||
                                (fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == 1))&&
                                ((fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == 0) ||
                                (fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == -2)||
                                (fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == 2))){
                                    mandar_datos(k,Posicion);val = true;break;
                                }
                            }
                        }
                        else if(j==5){
                            if((disponibles_pos_maquina_X[k] == 1) || (disponibles_pos_maquina_X[k] == 3)){
                                if(((fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == 0) ||
                                (fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == -2))&&
                                ((fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == 0) ||
                                (fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == 2))){
                                    mandar_datos(k,Posicion);val = true;break;
                                }
                            }
                        }
                    }
                }else if(i==2){
                    for(int k=0;k<22;k++){
                        if(j==2){
                            if((disponibles_pos_maquina_X[k] == 2) || (disponibles_pos_maquina_X[k] == 3)){
                                if(((fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == 0) ||
                                (fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == -1))&&
                                ((fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == 0) ||
                                (fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == -1))){
                                    mandar_datos(k,Posicion);val = true;break;
                                }
                            }
                        }
                        else if(j==3){
                            if((disponibles_pos_maquina_X[k] == 2) || (disponibles_pos_maquina_X[k] == 1)){
                                if(((fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == 0) ||
                                (fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == 1))&&
                                ((fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == 0) ||
                                (fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == -1)||
                                (fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == 1))){
                                    mandar_datos(k,Posicion);val = true;break;
                                }
                            }
                        }
                        else if(j==4){
                            if((disponibles_pos_maquina_X[k] == 2) || (disponibles_pos_maquina_X[k] == 3)){
                                if(((fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == 0) ||
                                (fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == -1))&&
                                ((fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == 0) ||
                                (fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == 1))){
                                    mandar_datos(k,Posicion);val = true;break;
                                }
                            }
                        }
                    }
                }else if(i==3){
                    for(int k=0;k<22;k++){
                        if(j==0){
                            if((disponibles_pos_maquina_X[k] == 0) || (disponibles_pos_maquina_X[k] == 3)
                            || (disponibles_pos_maquina_X[k] == 6)){
                                if(((fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == 0) ||
                                (fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == -3)
                                || (fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == 3))&&
                                ((fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == 0) ||
                                (fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == -1))){
                                    mandar_datos(k,Posicion);val = true;break;
                                }
                            }
                        }
                        else if(j==1){
                            if((disponibles_pos_maquina_X[k] == 1) || (disponibles_pos_maquina_X[k] == 3)
                            || (disponibles_pos_maquina_X[k] == 5)){
                                if(((fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == 0) ||
                                (fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == 2)
                                ||(fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == -2))&&
                                ((fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == 0) ||
                                (fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == -1)||
                                (fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == 1))){
                                    mandar_datos(k,Posicion);val = true;break;
                                }
                            }
                        }
                        else if(j==2){
                            if((disponibles_pos_maquina_X[k] == 2) || (disponibles_pos_maquina_X[k] == 3)
                            || (disponibles_pos_maquina_X[k] == 4)){
                                if(((fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == 0) ||
                                (fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == 1)||
                                (fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == -1))&&
                                ((fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == 0) ||
                                (fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == 1))){
                                    mandar_datos(k,Posicion);val = true;break;
                                }
                            }
                        }
                        else if(j==4){
                            if((disponibles_pos_maquina_X[k] == 2) || (disponibles_pos_maquina_X[k] == 3)
                            || (disponibles_pos_maquina_X[k] == 4)){
                                if(((fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == 0) ||
                                (fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == 1)||
                                (fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == -1))&&
                                ((fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == 0) ||
                                (fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == -1))){
                                    mandar_datos(k,Posicion);val = true;break;
                                }
                            }
                        }
                        else if(j==5){
                            if((disponibles_pos_maquina_X[k] == 1) || (disponibles_pos_maquina_X[k] == 3)
                            || (disponibles_pos_maquina_X[k] == 5)){
                                if(((fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == 0) ||
                                (fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == 2)||
                                (fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == -2))&&
                                ((fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == 0) ||
                                (fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == 1)||
                                (fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == -1))){
                                    mandar_datos(k,Posicion);val = true;break;
                                }
                            }
                        }
                        else if(j==6){
                            if((disponibles_pos_maquina_X[k] == 0) || (disponibles_pos_maquina_X[k] == 3)
                            || (disponibles_pos_maquina_X[k] == 6)){
                                if(((fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == 0) ||
                                (fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == 3)||
                                (fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == -3))&&
                                ((fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == 0) ||
                                (fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == 1))){
                                    mandar_datos(k,Posicion);val = true;break;
                                }
                            }
                        }
                    }
                }else if(i==4){
                    for(int k=0;k<22;k++){
                        if(j==2){
                            if((disponibles_pos_maquina_X[k] == 4) || (disponibles_pos_maquina_X[k] == 3)){
                                if(((fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == 0) ||
                                (fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == 1))&&
                                ((fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == 0) ||
                                (fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == -1))){
                                    mandar_datos(k,Posicion);val = true;break;
                                }
                            }
                        }
                        else if(j==3){
                            if((disponibles_pos_maquina_X[k] == 4) || (disponibles_pos_maquina_X[k] == 5)){
                                if(((fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == 0) ||
                                (fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == -1))&&
                                ((fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == 0) ||
                                (fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == -1)||
                                (fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == 1))){
                                    mandar_datos(k,Posicion);val = true;break;
                                }
                            }
                        }
                        else if(j==4){
                            if((disponibles_pos_maquina_X[k] == 4) || (disponibles_pos_maquina_X[k] == 3)){
                                if(((fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == 0) ||
                                (fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == 1))&&
                                ((fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == 0) ||
                                (fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == 1))){
                                    mandar_datos(k,Posicion);val = true;break;
                                }
                            }
                        }
                    }
                }else if(i==5){
                    for(int k=0;k<22;k++){
                        if(j==1){
                            if((disponibles_pos_maquina_X[k] == 5) || (disponibles_pos_maquina_X[k] == 3)){
                                if(((fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == 0) ||
                                (fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == 2))&&
                                ((fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == 0) ||
                                (fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == -2))){
                                   mandar_datos(k,Posicion);val = true;break;
                                }
                            }
                        }
                        else if(j==3){
                            if((disponibles_pos_maquina_X[k] == 5) || (disponibles_pos_maquina_X[k] == 4)
                            || (disponibles_pos_maquina_X[k] == 6)){
                                if(((fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == 0) ||
                                (fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == -1)||
                                (fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == 1))&&
                                ((fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == 0) ||
                                (fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == -2)||
                                (fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == 2))){
                                    mandar_datos(k,Posicion);val = true;break;
                                }
                            }
                        }
                        else if(j==5){
                            if((disponibles_pos_maquina_X[k] == 5) || (disponibles_pos_maquina_X[k] == 3)){
                                if(((fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == 0) ||
                                (fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == 2))&&
                                ((fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == 0) ||
                                (fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == 2))){
                                    mandar_datos(k,Posicion);val = true;break;
                                }
                            }
                        }
                    }
                }else if(i==6){
                    for(int k=0;k<22;k++){
                        if(j==0){
                            if((disponibles_pos_maquina_X[k] == 6) || (disponibles_pos_maquina_X[k] == 3)){
                                if(((fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == 0) ||
                                (fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == 3))&&
                                ((fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == 0) ||
                                (fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == -3))){
                                    mandar_datos(k,Posicion);val = true;break;
                                }
                            }
                        }
                        else if(j==3){
                            if((disponibles_pos_maquina_X[k] == 5) || (disponibles_pos_maquina_X[k] == 6)){
                                if(((fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == 0) ||
                                (fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == 1))&&
                                ((fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == 0) ||
                                (fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == -3)||
                                (fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == 3))){
                                    mandar_datos(k,Posicion);val = true;break;
                                }
                            }
                        }
                        else if(j==6){
                            if((disponibles_pos_maquina_X[k] == 6) || (disponibles_pos_maquina_X[k] == 3)){
                                if(((fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == 0) ||
                                (fichas_maquina_x[Posicion] - disponibles_pos_maquina_X[k] == 3))&&
                                ((fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == 0) ||
                                (fichas_maquina_y[Posicion] - disponibles_pos_maquina_y[k] == 3))){
                                    mandar_datos(k,Posicion);val = true;break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(contadore ==0){
        jugada_maquina(matriz);
    }
}

bool Machine :: complemento_de_eliminar(int &jugada_X,int &jugada_y,string matriz[7][7]){
    bool val = false;
    if(jugada_X ==0){
            if(jugada_y == 0){
                if((matriz[0][3] == "O")  && (matriz[0][6] == "O")){val= true;}

                if((matriz[3][0] == "O")  &&  (matriz[6][0] == "O")){val= true;}
            }
            if(jugada_y == 3){
                if((matriz[0][0] == "O") && (matriz[0][6] == "O")){val= true;}

                if((matriz[1][3] == "O") && (matriz[2][3] == "O")){val= true;}
            }
            if(jugada_y == 6){
                if((matriz[0][0] == "O") && (matriz[0][3] == "O") ){val= true;}

                if((matriz[3][6] == "O") && (matriz[6][6] == "O")){val= true;}
            }
        }
        if(jugada_X ==1){
            if(jugada_y == 1){
                if((matriz[1][3] == "O") && (matriz[1][5] == "O")){val= true;}

                if((matriz[3][1] == "O") && (matriz[5][1] == "O")){val= true;}
            }
            if(jugada_y == 3){
                if((matriz[1][1] == "O") && (matriz[1][5] == "O")){val= true;}

                if((matriz[0][3] == "O") &&  (matriz[2][3] == "O")){
                    val= true;
                }
            }
            if(jugada_y == 5){
                if((matriz[1][1] == "O")  && (matriz[1][3] == "O")){
                    val= true;
                }
                if((matriz[3][5] == "O")  && (matriz[5][5] == "O")){
                    val= true;
                }
            }
        }
        if(jugada_X ==2){
            if(jugada_y == 2){
                if((matriz[2][3] == "O")  &&  (matriz[2][4] == "O")){
                    val= true;
                }
                if((matriz[3][2] == "O") && (matriz[4][2] == "O")){
                    val= true;
                }
            }
            if(jugada_y == 3){
                if((matriz[2][2] == "O")  && (matriz[2][4] == "O")){
                    val= true;
                }
                if((matriz[0][3] == "O") &&(matriz[1][3] == "O")){
                    val= true;
                }
            }
            if(jugada_y == 4){
                if((matriz[2][2] == "O") &&(matriz[2][3] == "O")){
                    val= true;
                }
                if((matriz[3][4] == "O")  && (matriz[4][4] == "O")){
                    val= true;
                }
            }
        }
        if(jugada_X ==3){
            if(jugada_y == 0){
                if((matriz[0][0] == "O") && (matriz[6][0] == "O")){
                    val= true;
                }
                if((matriz[3][1] == "O")  && (matriz[3][2] == "O")){
                    val= true;
                }
            }
            if(jugada_y == 1){
                if((matriz[1][1] == "O") &&(matriz[5][1] == "O")){
                    val= true;
                }
                if((matriz[3][2] == "O") &&(matriz[3][0] == "O")){
                    val= true;
                }
            }
            if(jugada_y == 2){
                if((matriz[2][2] == "O") &&(matriz[4][2] == "O")){
                    val= true;
                }
                if((matriz[3][1] == "O")  && (matriz[3][0] == "O")){
                    val= true;
                }
            }
            if(jugada_y == 4){
                if((matriz[4][4] == "O")  &&(matriz[2][4] == "O")){
                    val= true;
                }
                if((matriz[3][5] == "O") && (matriz[3][6] == "O")){
                    val= true;
                }
            }
            if(jugada_y == 5){
                if((matriz[3][4] == "O") &&(matriz[3][6] == "O")){
                    val= true;
                }
                if((matriz[5][5] == "O") &&(matriz[1][5] == "O")){
                    val= true;
                }
            }
            if(jugada_y == 6){
                if((matriz[3][4] == "O") && (matriz[3][5] == "O")){
                    val= true;
                }
                if((matriz[6][6] == "O") &&(matriz[0][6] == "O")){
                    val= true;
                }
            }
        }
        if(jugada_X ==4){
            if(jugada_y == 2){
                if((matriz[2][2] == "O") &&(matriz[3][2] == "O")){
                    val= true;
                }
                if((matriz[4][4] == "O") &&(matriz[4][3] == "O")){
                    val= true;
                }
            }
            if(jugada_y == 3){
                if((matriz[4][2] == "O") &&(matriz[4][4] == "O")){
                    val= true;
                }
                if((matriz[5][3] == "O") && (matriz[6][3] == "O")){
                    val= true;
                }
            }
            if(jugada_y == 4){
                if((matriz[2][4] == "O")  &&(matriz[3][4] == "O")){
                    val= true;
                }
                if((matriz[4][2] == "O") &&(matriz[4][3] == "O")){
                    val= true;
                }
            }
        }
        if(jugada_X ==5){
            if(jugada_y == 1){
                if((matriz[1][1] == "O") &&(matriz[3][1] == "O")){
                    val= true;
                }
                if((matriz[5][3] == "O") &&(matriz[5][5] == "O")){
                    val= true;
                }
            }
            if(jugada_y == 3){
                if((matriz[5][1] == "O") && (matriz[5][5] == "O")){
                    val= true;
                }
                if((matriz[6][3] == "O") &&(matriz[4][3] == "O")){
                    val= true;
                }
            }
            if(jugada_y == 5){
                if((matriz[5][3] == "O") &&(matriz[5][1] == "O")){
                    val= true;
                }
               if((matriz[3][5] == "O")  && (matriz[1][5] == "O")){
                    val= true;
                }
            }
        }
           if(jugada_X ==6){
            if(jugada_y == 0){
                if((matriz[6][3] == "O") && (matriz[6][6] == "O")){
                    val= true;
                }
                if((matriz[3][0] == "O") &&(matriz[0][0] == "O")){
                    val= true;
                }
            }
            if(jugada_y == 3){
                if((matriz[6][6] == "O")  && (matriz[6][0] == "O") ){
                    val= true;
                }
                if((matriz[5][3] == "O")  && (matriz[4][3] == "O") ){
                    val= true;
                }
            }
            if(jugada_y == 6){
                 if((matriz[6][3] == "O") && (matriz[6][0] == "O")){
                    val= true;
                }
                if((matriz[0][6] == "O") && (matriz[3][6] == "O")){
                    val= true;
                }
            }
        }return val;

}
void Machine :: eliminar(string matriz[7][7],string matriz2[7][7],int &opcion,int &jugada_X,int &jugada_y,int &rival,string disponibles[24]){
    int eliminar=0;
    bool val= false;
    if(opcion == 2){
        val = complemento_de_eliminar(jugada_X,jugada_y,matriz);
        if(val == true){
            Player p1;
            p1.verificar_disponibles(matriz,disponibles);
            rival-=1;
            jugada_X = 99; jugada_y = 99;
            bool por_fin = false;
            for(int i=0; i<7;i++){
                if(por_fin == true){break;}
                for(int j=0; j<7;j++){
                    if(por_fin == true){break;}
                    if((i == p1.fichas_posX[eliminar]) && (j== p1.fichas_posy[eliminar])){
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
    else if(opcion == 3){
        Machine2 m2;
        val = complemento_de_eliminar(jugada_X,jugada_y,matriz);
        if(val == true){
            m2.verificar_posiciones2(matriz,disponibles);
            rival-=1;
            jugada_X = 99; jugada_y = 99;
            bool por_fin = false;
            for(int i=0; i<7;i++){
                if(por_fin == true){break;}
                for(int j=0; j<7;j++){
                    if(por_fin == true){break;}
                    if((i == m2.fichas_maquina_x2[eliminar]) && (j== m2.fichas_maquina_y2[eliminar])){
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
}


void Machine :: mandar_datos(int &k, int &Posicion){
    Set_disponible_maquina_X(disponibles_pos_maquina_X[k]);
    Set_disponible_maquina_y(disponibles_pos_maquina_y[k]);
    Set_Ficha_maquina_X(fichas_maquina_x[Posicion]);
    Set_Ficha_maquina_y(fichas_maquina_y[Posicion]);
    contadore++;
}
