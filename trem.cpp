#include "trem.h"
#include <QtCore>

//Construtor
Trem::Trem(int ID, int x, int y, QMutex *mutex)
{
    this->ID = ID;
    this->x = x;
    this->y = y;
    this->velocidade = 100;
    this->mutex = mutex;
    this->parado = true;
}

//Função a ser executada após executar trem->START
void Trem::run()
{
    while (true)
    {
        int a = 10;

        if (velocidade == 1000)
            a = 0;
        else
            a = 10;

        switch (ID)
        {
        case 1:
            if (x == 310 && y == 30)
            {
                bool mutex0 = mutex[0].try_lock();
                bool mutex2 = mutex[2].try_lock();

                if (mutex0 && mutex2)
                    x += a;
                else
                {
                    if (mutex0)
                        mutex[0].unlock();
                    if (mutex2)
                        mutex[2].unlock();
                }
            }
            else if (x < 330 && y == 30)
                x += a;
            else if (x == 330 && y < 150)
                y += a;
            else if (x == 310 && y == 150)
            {
                x -= a;
                mutex[0].unlock();
            }
            else if (x == 180 && y == 150)
            {
                x -= a;
                mutex[2].unlock();
            }
            else if (x > 60 && y == 150)
                x -= a;
            else
                y -= a;

            emit updateGUI(ID, x, y);
            break;
        case 2:
            if (x == 350 && y == 30)
            {
                x += a;
                mutex[0].unlock();
            }
            else if (x == 580 && y == 30)
            {
                bool mutex0 = mutex[0].try_lock();
                bool mutex1 = mutex[1].try_lock();
                bool mutex3 = mutex[3].try_lock();
                bool mutex4 = mutex[4].try_lock();

                if (mutex0 && mutex1 && mutex3 && mutex4)
                    x += a;
                else
                {
                    if (mutex0)
                        mutex[0].unlock();
                    if (mutex1)
                        mutex[1].unlock();
                    if (mutex3)
                        mutex[3].unlock();
                    if (mutex4)
                        mutex[4].unlock();
                }
            }
            else if (x == 330 && y == 130)
            {
                y -= a;
                mutex[3].unlock();
            }
            else if (x < 600 && y == 30)
                x += a;
            else if (x == 600 && y < 150)
                y += a;
            else if (x == 580 && y == 150)
            {
                x -= a;
                mutex[1].unlock();
            }
            else if (x == 450 && y == 150)
            {
                x -= a;
                mutex[4].unlock();
            }
            else if (x > 330 && y == 150)
                x -= a;
            else
                y -= a;

            emit updateGUI(ID, x, y);
            break;
        case 3:
            if (x == 620 && y == 30)
            {
                x += a;
                mutex[1].unlock();
            }
            else if (x < 870 && y == 30)
                x += a;
            else if (x == 870 && y < 150)
                y += a;
            else if (x == 760 && y == 150)
            {
                bool mutex1 = mutex[1].try_lock();
                bool mutex5 = mutex[5].try_lock();

                if (mutex1 && mutex5)
                    x -= a;
                else
                {
                    if (mutex1)
                        mutex[1].unlock();
                    if (mutex5)
                        mutex[5].unlock();
                }
            }
            else if (x > 600 && y == 150)
                x -= a;
            else if (x == 600 && y == 130)
            {
                mutex[5].unlock();
                y -= a;
            }
            else
                y -= a;

            emit updateGUI(ID, x, y);
            break;
        case 4:
            if (x == 490 && y == 280)
            {
                bool mutex4 = mutex[4].try_lock();
                bool mutex5 = mutex[5].try_lock();
                bool mutex6 = mutex[6].try_lock();

                if (mutex4 && mutex5 && mutex6)
                    x -= a;
                else
                {
                    if (mutex4)
                        mutex[4].unlock();
                    if (mutex5)
                        mutex[5].unlock();
                    if (mutex6)
                        mutex[6].unlock();
                }
            }
            else if (x > 470 && y == 280)
                x -= a;
            else if (x == 470 && y > 150)
                y -= a;
            else if (x == 490 && y == 150)
            {
                x += a;
                mutex[6].unlock();
            }
            else if (y == 150 && x == 620)
            {
                x += a;
                mutex[4].unlock();
            }
            else if (y == 150 && x < 740)
                x += a;
            else if (y == 170 && x == 740)
            {
                y += a;
                mutex[5].unlock();
            }
            else
                y += a;

            emit updateGUI(ID, x, y);
            break;
        case 5:
            if (x == 450 && y == 280)
            {
                x -= a;
                mutex[6].unlock();
            }
            else if (x > 200 && y == 280)
                x -= a;
            else if (x == 200 && y == 170)
            {
                bool mutex2 = mutex[2].try_lock();
                bool mutex3 = mutex[3].try_lock();
                bool mutex6 = mutex[6].try_lock();

                if (mutex2 && mutex3 && mutex6)
                    y -= a;
                else
                {
                    if (mutex2)
                        mutex[2].unlock();
                    if (mutex3)
                        mutex[3].unlock();
                    if (mutex6)
                        mutex[6].unlock();
                }
            }
            else if (x == 200 && y > 150)
                y -= a;
            else if (x == 350 && y == 150)
            {
                x += a;
                mutex[2].unlock();
            }
            else if (x < 470 && y == 150)
                x += a;
            else if (x == 470 && y == 170)
            {
                y += a;
                mutex[3].unlock();
            }
            else
                y += a;

            emit updateGUI(ID, x, y);
            break;
        default:
            break;
        }

        msleep(velocidade);
    }
}

void Trem::set_velocidade(int valor_slider)
{
    this->velocidade = 1000 - valor_slider;
}
