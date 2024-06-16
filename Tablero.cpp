#include"Tablero.h"

Tablero :: Tablero(){}
Tablero :: ~Tablero(){}

void Tablero :: Maquina(){
    
    Machine M1;
    do{
        int posM = M1.MoverMaquina();
        for(int i=0; i<7; i++){
            for(int j=0; j<7; j++){
                if(matriz[i][j] == to_string(posM) ){
                    matriz[i][j] = "O";
                    contador_M++;
                    M1.SetFicha(contador_M);
                }
            }
        }
    }while(contador_M != contador_J) ;
    
    sleep(2);
    Actualizar_Matriz();
}

void Tablero :: Jugador(){
       
    Player J1;
    int pos = J1.MoverFichas();

    for(int i=0; i<7; i++){
        for(int j=0; j<7; j++){
            if(matriz[i][j] == to_string(pos)){
                matriz[i][j] = "F" + to_string(contador_J+1);
                contador_J++;
                J1.Setfichas(contador_J);
                
            }
        }
    }
    Actualizar_Matriz();
}

void Tablero :: Inicio_de_partida(){
    cout<<"\tINICIO DE PARTIDA\n"<<endl;
    do{
        if(((cantidad_de_fichas) %2) == 0){
            cout<<"Es tu turno"<<endl;
            Jugador();

        }
        else{
            cout<<"Es el turno de la maquina"<<endl;
            Maquina();
        }
        cantidad_de_fichas--;
    }while(cantidad_de_fichas >0);
}

void Tablero :: Visualizar_Matriz(){
    system("cls");
    matriz[0][0] = "1";
    matriz[0][3] = "2";
    matriz[0][6] = "3";
    matriz[1][1]= "4";
    matriz[1][3]= "5";
    matriz[1][5]= "6";
    matriz[2][2]= "7";
    matriz[2][3]= "8";
    matriz[2][4]= "9";
    matriz[3][0] = "10";
    matriz[3][1] = "11";
    matriz[3][2] = "12";
    matriz[3][4]= "13";
    matriz[3][5]= "14";
    matriz[3][6]= "15";
    matriz[4][2]= "16";
    matriz[4][3]= "17";
    matriz[4][4]= "18";
    matriz[5][1]= "19";
    matriz[5][3]= "20";
    matriz[5][5]= "21";
    matriz[6][0]= "22";
    matriz[6][3]= "23";
    matriz[6][6]= "24";

    for(int i=0; i<7; i++){
        for(int j=0; j<7; j++){
            if(matriz[i][j] == ""){
                matriz[i][j] = "*";
            }
            cout<<setw(3.6)<<matriz[i][j]<<"  ";
        }
        cout<<"\n"<<endl;
    }
}

void Tablero :: Verificar_Movimiento(){
    if(matriz[0][0] == "F1"){
        if(matriz[0][3] == "2"){
            cout<<"F1 tiene cancer en 2"<<endl;
        }
        if(matriz[3][0] == "10"){
            cout<<"F1 tiene cancer en 10"<<endl;
        }
    }
}

void Tablero :: Ganador(){}

void Tablero :: Actualizar_Matriz(){
    system("cls");
    for(int i=0; i<7; i++){
        for(int j=0; j<7; j++){
            cout<<setw(3.6)<<matriz[i][j]<<"  ";
        }
        cout<<"\n"<<endl;
    }
}
