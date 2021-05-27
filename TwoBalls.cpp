#include "TXLib.h"

void MoveBall ();

int main()
    {
    txCreateWindow (1500, 800);

    MoveBall();

    return 0;
    }

void MoveBall()
    {
    int x   = 100, y   = 100,
        vx  =   5, vy  =   2,
        x1  = 500, y1  = 100,
        vx1 =   3, vy1 =   2;

    int dt = 1;



    while (!txGetAsyncKeyState (VK_ESCAPE))
        {
        txSetColor (TX_LIGHTCYAN, 3);
        txSetFillColor (RGB(255, 255, 0));
        txCircle ( x,  y, 30);

        txSetColor (TX_LIGHTCYAN, 3);
        txSetFillColor (TX_GREEN);
        txCircle (x1, y1, 20);

        x += vx * dt;
        y += vy * dt;

        x1 += vx1 * dt;
        y1 += vy1 * dt;

        if (x > 1500)
            {
            vx = -vx;
            x = 1500;
            }

        if (x1 > 1500)
            {
            vx1 = -vx1;
            x1 = 1500;
            }

        if (y > 800)
            {
            vy = -vy;
            y = 800;
            }

        if (y1 > 800)
            {
            vy1 = -vy1;
            y1 = 800;
            }

        if (x < 0)
            {
            vx = -vx;
            x = 0;
            }

        if (x1 < 0)
            {
            vx1 = -vx1;
            x1 = 0;
            }

        if (y < 0)
            {
            vy = -vy;
            y = 0;
            }

        if (y1 < 0)
            {
            vy1 = -vy1;
            y1 = 0;
            }

        if (txGetAsyncKeyState (VK_RIGHT)) vx++;
        if (txGetAsyncKeyState (VK_LEFT))  vx--;
        if (txGetAsyncKeyState (VK_UP))    vy++;
        if (txGetAsyncKeyState (VK_DOWN))  vy--;

        txSleep (10);
        }
    }

