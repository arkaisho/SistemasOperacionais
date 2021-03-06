#include "trem.h"
#include <QtCore>

QMutex region1,region2,region3,region4,region5,region6,region7;//basicos
QSemaphore semaphore1(2),semaphore2(2),semaphore3(2);//deadlock triplo
QSemaphore semaphore4(3),semaphore5(3);//deadlock quadruplo
QSemaphore semaphore6(4);//deadlock quintuplo

Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 0;
}

void Trem::setVelocidade(int value){
    if(value!=0){
        this->velocidade = 1001-value;
    }else{
        velocidade=0;
    }
}

//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
        if (velocidade!=0) {
            switch(ID){
            case 1:

                if(x==100 && y==10){
                    semaphore6.acquire(1);
                    semaphore4.acquire(1);
                    semaphore1.acquire(1);
                    region1.lock();
                }
                if(x==100 && y==130){
                    semaphore6.release(1);
                    semaphore4.release(1);
                    semaphore1.release(1);
                    region1.unlock();
                }
                if(x==130 && y==100){
                    region3.lock();
                }
                if(x==40 && y==130){
                    region3.unlock();
                }

                if (x <130 && y == 10 )
                    x+=10;
                else if (x == 130 && y < 130)
                    y+=10;
                else if (x > 10 && y == 130)
                    x-=10;
                else
                    y-=10;
                emit updateGUI(ID, x,y);
                break;
            case 2:

                if(x==220 && y==10){
                    semaphore6.acquire(1);
                    semaphore5.acquire(1);
                    semaphore3.acquire(1);
                    region2.lock();
                }
                if(x==220 && y==130){
                    semaphore6.release(1);
                    semaphore5.release(1);
                    semaphore3.release(1);
                    region2.unlock();
                }
                if(x==250 && y==100){
                    semaphore4.acquire(1);
                    semaphore2.acquire(1);
                    region5.lock();
                }
                if(x==160 && y==130){
                    semaphore4.release(1);
                    semaphore2.release(1);
                    region5.unlock();
                }
                if(x==220 && y==130){
                    semaphore1.acquire(1);
                    region4.lock();
                }
                if(x==130 && y==100){
                    semaphore1.release(1);
                    region4.unlock();
                }
                if(x==160 && y==130){
                    region1.lock();
                }
                if(x==160 && y==10){
                    region1.unlock();
                }

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
            case 3:

                if(x==340 && y==130){
                    semaphore6.acquire(1);
                    semaphore5.acquire(1);
                    semaphore3.acquire(1);
                    region6.lock();
                }
                if(x==250 && y==100){
                    semaphore6.release(1);
                    semaphore5.release(1);
                    semaphore3.release(1);
                    region6.unlock();
                }
                if(x==280 && y==130){
                    region2.lock();
                }
                if(x==280 && y==10){
                    region2.unlock();
                }

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
            case 4:
                if(x==70 && y==160){
                    semaphore6.acquire(1);
                    semaphore4.acquire(1);
                    semaphore1.acquire(1);
                    region3.lock();
                }
                if(x==160 && y==130){
                    semaphore6.release(1);
                    semaphore4.release(1);
                    semaphore1.release(1);
                    region3.unlock();
                }
                if(x==100 && y==130){
                    semaphore5.acquire(1);
                    semaphore2.acquire(1);
                    region4.lock();
                }
                if(x==190 && y==160){
                    semaphore5.release(1);
                    semaphore2.release(1);
                    region4.unlock();
                }
                if(x==160 && y==130){
                    region7.lock();
                }
                if(x==160 && y==250){
                    region7.unlock();
                }

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
            case 5:

                if(x==220 && y==250){
                    semaphore6.acquire(1);
                    semaphore4.acquire(1);
                    semaphore5.acquire(1);
                    semaphore2.acquire(1);
                    region7.lock();
                }
                if(x==220 && y==130){
                    semaphore6.release(1);
                    semaphore4.release(1);
                    semaphore5.release(1);
                    semaphore2.release(1);
                    region7.unlock();
                }
                if(x==190 && y==160){
                    semaphore3.acquire(1);
                    region5.lock();
                }
                if(x==280 && y==130){
                    semaphore3.release(1);
                    region5.unlock();
                }
                if(x==220 && y==130){
                    region6.lock();
                }
                if(x==310 && y==160){
                    region6.unlock();
                }

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




