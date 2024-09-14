#include "Tablero.h"

Tablero::Tablero(){}

Tablero::~Tablero(){}

void Tablero :: modos_juego(){
    system("cls");
    cout<<"\tTENEMOS TRES MODOS DE JUEGO SELECCIONA UNO!\n"<<endl;
    cout<<"  1. JUGADOR 1 - JUGADOR 2"<<endl;
    cout<<"  2. JUGADOR - MAQUINA"<<endl;
    cout<<"  3. MAQUINA - MAQUINA"<<endl;
    cout<<"  Seleccione una opcion: "; cin>>opcion;

    switch(opcion){  
        case 1: Visualizar_Matriz();break;
        case 2: Visualizar_Matriz();break;
        case 3: Visualizar_Matriz();break;
        default: cout<<"\n  Digite una opcion valida"; sleep(3); modos_juego();break;
        }
}

void Tablero :: instruciones(){
    system("cls");
    cout<<"Descripcion:\n\nEl tablero de juego consta de tres cuadrados cada uno compuesto por 8 intersecciones de lineas. (24 en total)"<<endl;
    cout<<"El objetivo de los jugadores sera llevar a su oponente a tener menos de tres piezas o en su defecto, sin movimientos de fichas posibles.\n"<< endl;
    cout<<"Inicio del juego:\n\nPara dar el inicio del juego, en turnos de uno a uno, los jugadores ubicaran sus fichas en las intersecciones vacias."<<endl;
    cout<<"con el objetivo de formar una fila de tres piezas a lo largo de una de las lineas del tablero\n"<<endl;
    cout<<"Cuando esto ocurre, el jugador ha conseguido un molino.\n"<<endl;
    system("pause");
    cout<<"\nAl haber obtenido un molino el jugador tiene la posibilidad de eliminar una de las fichas del oponente,\n sin posibilidad de volver al juego."<<endl;
    cout<<"Si los jugadores han ubicado las 18 fichas en total, el juego continua por turnos."<<endl;
    cout<<"\nMovimiento y algunas reglas del juego:\n\nEl movimiento de las fichas se realizara a posiciones adyacentes."<<endl;
    cout<<"Es decir, una ficha que se encuentra en una de las intersecciones solo se podra mover un paso a otra posicion adyacente."<<endl;
    cout<<"En caso de no ser posible con ninguna ficha (sea porque no hay posiciones adyacentes vacias) este jugador ha perdido el juego\n"<<endl;
    system("pause");
    cout<<"\nAl momento de eliminar una ficha del oponente al haber completado un molino:\n"<<endl;
    cout<<"Como ficha a eliminar se debera seleccionar unicamente aquellas fichas que no hagan parte de algun molino."<<endl;
    cout<<"en caso de que todas pertenezcan a un molino, se podra elegir libremente entre todas ellas."<<endl;
    cout<<"Aquel jugador que posea menos de tres fichas no tendra la posibilidad de formar molinos, por ende, perdera la partida.\n"<<endl;
    cout<<"Se debe tener en cuenta la siguiente excepcion:\n\nEn el momento en el que uno de los jugadores cuenta con tan solo 3 fichas en el tablero"<<endl;
    cout<<"El jugador tiene la posibilidad de mover sus fichas en la posicion que prefiera sin respetar las reglas de movimiento iniciales.\n"<<endl;
    system("pause");
    menu();
}

void Tablero :: menu(){
    system("cls");
    int opcion1;
    cout<<"\tBienvenido al juego Nine Men's Morris!\n"<<endl;
    cout<<"   1. Leer instrucciones del juego"<<endl;
    cout<<"   2. Iniciar juego"<<endl;
    cout<<"   Seleccione una opcion: "; cin>>opcion1;

    switch(opcion1){  
        case 1: instruciones();break;
        case 2: modos_juego();break;
        default: cout<<"\n  Digite una opcion valida";sleep(3); menu();break;
        }
}

void Tablero :: Maquina(){
    bool val = false;
    Machine M1;
    M1.set_salvador(contador_M+contador);
    int posM = M1.PonerMaquina();
    for(int i=0; i<7; i++){
        if(val == true){break;}
        for(int j=0; j<7; j++){
            if(val == true){break;}
            if(matriz[i][j] == to_string(posM)){
                for(int k=0; k<24;k++){
                    if(matriz[i][j] == disponibles[k]){
                        disponibles[k] = " ";
                        break;
                    }
                } 
                matriz[i][j] = "O";
                m1_x = i; m1_y = j;
                contador_M++;
                M1.SetFicha(contador_M);
                val = true;
            }
             
        }     
    }
    if(val == false){
        contador++;
        M1.~Machine();
        Maquina();  
    }
    eliminar_ficha();
    
    M1.~Machine();
    
    
}

void Tablero :: Jugador(){
    Player J1;
    int pos = J1.PonerFichas();

    for(int i=0; i<7; i++){
        for(int j=0; j<7; j++){
            if(matriz[i][j] == to_string(pos)){
                for(int k=0; k<24;k++){
                    if(matriz[i][j] == disponibles[k]){
                        disponibles[k] = " ";
                    }
                }
                matriz[i][j] = "F" + to_string(ayuda_j1+1);
                j1_x = i; j1_y = j;
                contador_J++;
                ayuda_j1++;
                J1.Setfichas(contador_J);

            }
        }
    }
    J1.~Player();
    eliminar_ficha();
}

void Tablero :: Maquina2(){
    bool val = false;
    Machine2 M2;
    M2.set_salvador2(contador_M2+contador2);
    int posM = M2.PonerMaquina2();
    for(int i=0; i<7; i++){
        if(val == true){break;}
        for(int j=0; j<7; j++){
            if(val == true){break;}
            if(matriz[i][j] == to_string(posM)){
                for(int k=0; k<24;k++){
                    if(matriz[i][j] == disponibles[k]){
                        disponibles[k] = " ";
                        break;
                    }
                } 
                matriz[i][j] = "X";
                m2_x = i; m2_y = j;
                contador_M2++;
                M2.SetFicha2(contador_M2);
                val = true;
            }
             
        }     
    }
    if(val == false){
        contador2++;
        M2.~Machine2();
        Maquina2();  
    }
    eliminar_ficha();
    
    M2.~Machine2();
}

void Tablero :: Jugador2(){
    Player2 J2;
    int pos = J2.PonerFichas2();

    for(int i=0; i<7; i++){
        for(int j=0; j<7; j++){
            if(matriz[i][j] == to_string(pos)){
                for(int k=0; k<24;k++){
                    if(matriz[i][j] == disponibles[k]){
                        disponibles[k] = " ";
                    }
                }
                matriz[i][j] = "P" + to_string(ayuda_j2+1);
                j2_x = i; j2_y = j;
                contador_J2++;
                ayuda_j2++;
                J2.Setfichas2(contador_J2);

            }
        }
    }
    J2.~Player2();
    eliminar_ficha();
}

void Tablero :: Inicio_de_partida(){
    matriz2[0][0] = "1"; matriz2[0][3] = "2"; matriz2[0][6] = "3"; matriz2[1][1]= "4"; matriz2[1][3]= "5"; 
    matriz2[1][5]= "6"; matriz2[2][2]= "7"; matriz2[2][3]= "8"; matriz2[2][4]= "9"; matriz2[3][0] = "10"; 
    matriz2[3][1] = "11"; matriz2[3][2] = "12"; matriz2[3][4]= "13"; matriz2[3][5]= "14"; matriz2[3][6]= "15"; 
    matriz2[4][2]= "16"; matriz2[4][3]= "17"; matriz2[4][4]= "18"; matriz2[5][1]= "19"; matriz2[5][3]= "20"; 
    matriz2[5][5]= "21"; matriz2[6][0]= "22"; matriz2[6][3]= "23"; matriz2[6][6]= "24";
    
    cout<<"\tINICIO DE PARTIDA\n"<<endl;
    if(opcion ==2){
        do{
            if(((cantidad_de_fichas) %2) == 0){
                cout<<"Es tu turno"<<endl;
                Jugador();
            }
            else{
                cout<<"Es el turno de la maquina"<<endl;
                sleep(1);
                Maquina();
            }
            cantidad_de_fichas--;
        }while(cantidad_de_fichas >0);
        
        turno_libre = true;

        Verificar_Movimiento_Jugador_1();
    }
    
    else if(opcion == 1){
        do{
            if(((cantidad_de_fichas) %2) == 0){
                cout<<"Es el turno del jugador 1"<<endl;
                Jugador();
            }
            else{
                cout<<"Es el turno del jugador 2"<<endl;
                Jugador2();
            }
            cantidad_de_fichas--;
        }while(cantidad_de_fichas >0);
        turno_libre = true;
        Verificar_Movimiento_Jugador_1();
    }
    else if(opcion == 3){
        do{
            if(((cantidad_de_fichas) %2) == 0){
                cout<<"Es el turno de la maquina 1"<<endl;
                sleep(2);
                Maquina();
            }
            else{
                cout<<"Es el turno de la maquina 2"<<endl;
                sleep(2);
                Maquina2();
            }
            cantidad_de_fichas--;
        }while(cantidad_de_fichas >0);
        turno_libre = true;
        verificar_movimiento_maquina_1();
    }
}

void Tablero :: Visualizar_Matriz(){
    system("cls");
    matriz[0][0] = "1"; matriz[0][3] = "2"; matriz[0][6] = "3"; matriz[1][1]= "4"; matriz[1][3]= "5"; 
    matriz[1][5]= "6"; matriz[2][2]= "7"; matriz[2][3]= "8"; matriz[2][4]= "9"; matriz[3][0] = "10"; 
    matriz[3][1] = "11"; matriz[3][2] = "12"; matriz[3][4]= "13"; matriz[3][5]= "14"; matriz[3][6]= "15"; 
    matriz[4][2]= "16"; matriz[4][3]= "17"; matriz[4][4]= "18"; matriz[5][1]= "19"; matriz[5][3]= "20"; 
    matriz[5][5]= "21"; matriz[6][0]= "22"; matriz[6][3]= "23"; matriz[6][6]= "24";
    
    for(int i=0; i<7; i++){
        for(int j=0; j<7; j++){
            if(matriz[i][j] == ""){
                matriz[i][j] = "*";
            }
            cout<<setw(3.6)<<matriz[i][j]<<"  ";
        }
        cout<<"\n"<<endl;
    }
    Inicio_de_partida();
}

void Tablero :: Verificar_Movimiento_Jugador_1(){
    cout<<"\nEs el turno del jugador 1\n"<<endl;
    Player p1;
    p1.verificar_disponibles(matriz,disponibles);
    if((turno_libre == false) || (contador_J>3)){
        p1.posibles_jugadas(matriz);
        cout<<"\n";
        p1.~Player();
        partida();
    }else{
        Ganador();
        cout<<"\nAHORA TIENES MOVIMIENTOS LIBRES JUGADOR 1";
        sleep(1.8);
        p1.jugada_libre(matriz,matriz2,disponibles,j1_x,j1_y);
        eliminar_ficha();
        if(opcion == 2){
            verificar_movimiento_maquina_1();
    
        }else if(opcion == 1){
            Verificar_Movimiento_Jugador_2();
        }
    }
    
}

void Tablero :: Verificar_Movimiento_Jugador_2(){
    cout<<"\nEs el turno del jugador 2\n"<<endl;
    Player2 p2;
    p2.verificar_disponibles2(matriz,disponibles);
    if((turno_libre == false) || (contador_J2>3)){
    p2.posibles_jugadas2(matriz);
    cout<<"\n";
    bool val = false;
    string cambio_ficha = p2.MoverFichas2();
    string cambio_pos = p2.complemento_mover_fichas2(); 
    for(int i=0;i<7;i++){
        if(val == true){break;}
        for(int j=0; j<7; j++){
            if(val == true){break;}
            if(matriz[i][j] == cambio_ficha){
                for(int k=0;k<7;k++){
                    if(val == true){break;}
                    for(int l=0; l<7;l++){
                        if(val == true){break;}
                        if(matriz[k][l] == cambio_pos){
                            matriz[k][l] = cambio_ficha;
                            j2_x = k; j2_y = l;
                            matriz[i][j] = matriz2[i][j];
                            for(int m=0;m<24;m++){
                                if(cambio_pos == disponibles[m]){
                                    disponibles[m] = matriz2[i][j];
                                    val =true;break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }  
    p2.~Player2();
    eliminar_ficha();
    Actualizar_Matriz();
    Verificar_Movimiento_Jugador_1();
    }
    else{
        Ganador();
        cout<<"\nAHORA TIENES MOVIMIENTOS LIBRES JUGADOR 2";
        sleep(1.8);
        p2.jugada_libre2(matriz,matriz2,disponibles,j2_x,j2_y);
        p2.~Player2();
        eliminar_ficha();
        Verificar_Movimiento_Jugador_1();
    }

}

void Tablero :: verificar_movimiento_maquina_2(){
    Machine2 m2;
        m2.verificar_posiciones2(matriz,disponibles);
        if((turno_libre == false) || (contador_M2>3)){
            m2.jugada_maquina2(matriz);
            bool val = false;
            m2.set_contadore2(0);
            int cambio_ficha_maquina_x = m2.Get_Ficha_maquina_X2();
            int cambio_ficha_maquina_y = m2.Get_Ficha_maquina_y2();
            int cambio_pos_maquina_y = m2.Get_disponible_maquina_y2();
            int cambio_pos_maquina_X = m2.Get_disponible_maquina_X2();
            for(int i=0;i<7;i++){
                if(val == true){break;}
                for(int j=0; j<7; j++){
                    if(val == true){break;}
                    if((i == cambio_ficha_maquina_x) && (j == cambio_ficha_maquina_y)){
                        for(int k=0;k<7;k++){
                            if(val == true){break;}
                            for(int l=0; l<7;l++){
                                if(val == true){break;}
                                if(matriz[k][l] == matriz[cambio_pos_maquina_X][cambio_pos_maquina_y]){
                                    matriz[k][l] = matriz[cambio_ficha_maquina_x][cambio_ficha_maquina_y];
                                    m1_x = i; m1_y = j;
                                    matriz[i][j] = matriz2[i][j];
                                    for(int m=0;m<24;m++){
                                        if(matriz2[cambio_pos_maquina_X][cambio_pos_maquina_y] == disponibles[m]){
                                            disponibles[m] = matriz2[i][j];
                                             m2_x = i; m2_y = j;
                                            sleep(1);
                                            Actualizar_Matriz();val =true;break;

                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            m2.~Machine2();
            eliminar_ficha(); 

}
}
void Tablero :: verificar_movimiento_maquina_1(){
    Machine m1;
        m1.verificar_posiciones(matriz,disponibles);
        if((turno_libre == false) || (contador_M>3)){
            m1.jugada_maquina(matriz);
            bool val = false;
            m1.set_contadore(0);
            int cambio_ficha_maquina_x = m1.Get_Ficha_maquina_X();
            int cambio_ficha_maquina_y = m1.Get_Ficha_maquina_y();
            int cambio_pos_maquina_y = m1.Get_disponible_maquina_y();
            int cambio_pos_maquina_X = m1.Get_disponible_maquina_X();
            for(int i=0;i<7;i++){
                if(val == true){break;}
                for(int j=0; j<7; j++){
                    if(val == true){break;}
                    if((i == cambio_ficha_maquina_x) && (j == cambio_ficha_maquina_y)){
                        for(int k=0;k<7;k++){
                            if(val == true){break;}
                            for(int l=0; l<7;l++){
                                if(val == true){break;}
                                if(matriz[k][l] == matriz[cambio_pos_maquina_X][cambio_pos_maquina_y]){
                                    matriz[k][l] = matriz[cambio_ficha_maquina_x][cambio_ficha_maquina_y];
                                    m1_x = i; m1_y = j;
                                    matriz[i][j] = matriz2[i][j];
                                    for(int m=0;m<24;m++){
                                        if(matriz2[cambio_pos_maquina_X][cambio_pos_maquina_y] == disponibles[m]){
                                            disponibles[m] = matriz2[i][j];
                                            sleep(1);
                                            Actualizar_Matriz();val =true;break;

                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            m1.~Machine();
            eliminar_ficha(); 
            if(opcion == 2){
            Verificar_Movimiento_Jugador_1();}
            else if (opcion == 3){
                verificar_movimiento_maquina_2();
            }
        }
        else{
            Ganador();
            cout<<"\nAHORA LA MAQUINA TIENE MOVIMIENTOS LIBRES";
            m1.jugada_libre(matriz,matriz2,disponibles);
            sleep(1);
            eliminar_ficha();
            if(opcion == 2){
            Verificar_Movimiento_Jugador_1();}
            else if (opcion == 3){
                verificar_movimiento_maquina_2();
            }

        }     
    }


void Tablero:: partida(){
    Player p1;
    bool val = false;
    string cambio_ficha = p1.MoverFichas();
    string cambio_pos = p1.complemento_mover_fichas(); 
    for(int i=0;i<7;i++){
        if(val == true){break;}
        for(int j=0; j<7; j++){
            if(val == true){break;}
            if(matriz[i][j] == cambio_ficha){
                for(int k=0;k<7;k++){
                    if(val == true){break;}
                    for(int l=0; l<7;l++){
                        if(val == true){break;}
                        if(matriz[k][l] == cambio_pos){
                            matriz[k][l] = cambio_ficha;
                            j1_x = k; j1_y = l;
                            matriz[i][j] = matriz2[i][j];
                            for(int m=0;m<24;m++){
                                if(cambio_pos == disponibles[m]){
                                    disponibles[m] = matriz2[i][j];
                                    val =true;break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }  
    eliminar_ficha();
    p1.~Player();
    if(opcion == 2){
        cout<<"\nEs el turno de la maquina :v"<<endl;
        verificar_movimiento_maquina_1();
    }
    else if(opcion == 1){
        Actualizar_Matriz();
        Verificar_Movimiento_Jugador_2();
    }
    
}

void Tablero :: eliminar_ficha(){
    Actualizar_Matriz();
    if(opcion == 1){
        Player p1;
        Player2 p2;
        p1.eliminar(matriz,matriz2,opcion,j1_x,j1_y,contador_J2,disponibles);
        p2.eliminar2(matriz,matriz2,j2_x,j2_y,contador_J,disponibles);
    }
    else if(opcion == 2){
        Player p1;
        Machine m1;
        p1.eliminar(matriz,matriz2,opcion,j1_x,j1_y,contador_M,disponibles);
        m1.eliminar(matriz,matriz2,opcion,m1_x,m1_y,contador_J,disponibles);
    }else if(opcion == 3){
        Machine2 m2;
        Machine m1;
        m2.eliminar2(matriz,matriz2,m2_x,m2_y,contador_M,disponibles);
        m1.eliminar(matriz,matriz2,opcion,m1_x,m1_y,contador_M2,disponibles);
        m2.~Machine2();
        m1.~Machine();
    }
    if(turno_libre == false){
        Actualizar_Matriz();
    }    
}

void Tablero :: Ganador(){
    if(opcion == 2){
        if(contador_M <3){
        cout<<"\nHas ganado :D\n";exit(0);
        }
        if(contador_J<3){
        cout<<"\nLa maquina ha ganado\n ";exit(0);
        }
    }
    else if(opcion == 1){
        if(contador_J2 <3){
        cout<<"\nHa ganado el jugador 1 :D\n";exit(0);
        }
        if(contador_J<3){
        cout<<"\nHa ganado el jugador 2\n ";exit(0);
        }
    }
    else if(opcion == 3){
        if(contador_M2 <3){
        cout<<"\nHa ganado la maquina 1 :D\n";exit(0);
        }
        if(contador_M<3){
        cout<<"\nHa ganado la maquina 2\n ";exit(0);
        }
    }
    
}

void Tablero :: Actualizar_Matriz(){
    system("cls");
    for(int i=0; i<7; i++){
        for(int j=0; j<7; j++){
            if((matriz[i][j] == "F1") ||(matriz[i][j] == "F2") || (matriz[i][j] == "F3")
            || (matriz[i][j] == "F4") || (matriz[i][j] == "F5") || (matriz[i][j] == "F6")
            || (matriz[i][j] == "F7") || (matriz[i][j] == "F8") || (matriz[i][j] == "F9")){
                color(3);
            }
            if(matriz[i][j] == "O"){color(4);}
            if(matriz[i][j] == "X"){color(5);}
            if((matriz[i][j] == "P1") ||(matriz[i][j] == "P2") || (matriz[i][j] == "P3")
            || (matriz[i][j] == "P4") || (matriz[i][j] == "P5") || (matriz[i][j] == "P6")
            || (matriz[i][j] == "P7") || (matriz[i][j] == "P8") || (matriz[i][j] == "P9")){
                color(6);
            }            
            cout<<setw(3.6)<<matriz[i][j]<<"  ";
            color(7);
            
        }
        cout<<"\n"<<endl;
    }
}