#include "TXLib.h"

void MoveBallCrazy();
void MoveBall ();
void TowBalls ();


int main()
    {
    txCreateWindow (1500, 800);

    TowBalls ();

    return 0;
    }

void TowBalls ()
    {
    MoveBallCrazy();
    MoveBall ();
    }

void MoveBallCrazy()
    {
    int x  = 100, y  = 100,
        vx = 5,   vy = 2;

    int dt = 1;

    txSetColor (TX_LIGHTCYAN, 3);
    txSetFillColor (RGB(255, 255, 0));

    while (!txGetAsyncKeyState (VK_ESCAPE))
        {
        txCircle (x, y, 30);

        x += vx * dt;
        y += vy * dt;

        if (x > 1500)
            {
            vx = -vx;
            x = 1500;
            }

        if (y > 800)
            {
            vy = -vy;
            y = 800;
            }

        if (x < 0)
            {
            vx = -vx;
            x = 0;
            }

        if (y < 0)
            {
            vy = -vy;
            y = 0;
            }

        if (txGetAsyncKeyState (VK_RIGHT)) vx++;
        if (txGetAsyncKeyState (VK_LEFT))  vx--;
        if (txGetAsyncKeyState (VK_UP))    vy++;
        if (txGetAsyncKeyState (VK_DOWN))  vy--;
        if (txGetAsyncKeyState (VK_SPACE)) vx = vy = 0;

        txSleep (10);
        }
    }

void MoveBall()
    {
    int x  = 50, y  = 50,
        vx = 5,   vy = 2;

    int dt = 1;

    txSetColor (TX_LIGHTGREEN, 3);
    txSetFillColor (TX_GREEN);

    while (!txGetAsyncKeyState (VK_ESCAPE))
        {
        txCircle (x, y, 50);

        x += vx * dt;
        y += vy * dt;

        if (x > 1500)
            {
            vx = -vx;
            x = 1500;
            }

        if (y > 800)
            {
            vy = -vy;
            y = 800;
            }

        if (x < 0)
            {
            vx = -vx;
            x = 0;
            }

        if (y < 0)
            {
            vy = -vy;
            y = 0;
            }

        if (txGetAsyncKeyState (VK_RIGHT)) vx++;
        if (txGetAsyncKeyState (VK_LEFT))  vx--;
        if (txGetAsyncKeyState (VK_UP))    vy++;
        if (txGetAsyncKeyState (VK_DOWN))  vy--;

        txSleep (10);
        }
    }


