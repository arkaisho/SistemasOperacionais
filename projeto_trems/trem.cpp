#include "trem.h"
#include <QtCore>

//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 0;
}

void Trem::setVelocidade(int value){
    if (value!=0) {
        this->velocidade = 1000/value;
    }else{
        this->velocidade = 0;
    }
}

//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
        if (velocidade!=0) {
            switch(ID){
            case 1:     //Trem 1
                if (y == 10 && x <130)
                    x+=10;
                else if (x == 130 && y < 130)
                    y+=10;
                else if (x > 10 && y == 130)
                    x-=10;
                else
                    y-=10;
                emit updateGUI(ID, x,y);
                break;
            case 2:     //Trem 1
                if (y == 10 && x <250)
                    x+=10;
                else if (x == 250 && y < 130)
                    y+=10;
                else if (x > 130 && y == 130)
                    x-=10;
                else
                    y-=10;
                emit updateGUI(ID, x,y);
                break;
            case 3:     //Trem 1
                if (y == 10 && x <370)
                    x+=10;
                else if (x == 370 && y < 130)
                    y+=10;
                else if (x > 250 && y == 130)
                    x-=10;
                else
                    y-=10;
                emit updateGUI(ID, x,y);
                break;
            case 4:     //Trem 1
                if (y == 130 && x <190)
                    x+=10;
                else if (x == 190 && y < 250)
                    y+=10;
                else if (x > 70 && y == 250)
                    x-=10;
                else
                    y-=10;
                emit updateGUI(ID, x,y);
                break;
            case 5:     //Trem 1
                if (y == 130 && x <310)
                    x+=10;
                else if (x == 310 && y < 250)
                    y+=10;
                else if (x > 190 && y == 250)
                    x-=10;
                else
                    y-=10;
                emit updateGUI(ID, x,y);
                break;
            default:
                break;
            }
            msleep(velocidade);
        }
    }
}




