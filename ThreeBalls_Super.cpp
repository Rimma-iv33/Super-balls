#include "TXLib.h"

void MoveBall ();

void DrawBall (int x, int y, int vx, int vy, COLORREF color, COLORREF fillcolor);
void ControlBall (int* vx, int* vy);
void PhysicsBall (int* x, int* y, int* vx, int* vy, int ax, int ay, int dt);

int main()
    {
    txCreateWindow (1500, 800);

    MoveBall();

    return 0;
    }

void MoveBall()
    {
    int x1  = 100, y1  = 100,
        vx1 = 3,   vy1 = 2,
        ax1 = 0,   ay1 = 1;

    int x2  = 500, y2  = 100,
        vx2 = 5,   vy2 = 2,
        ax2 = 0,   ay2 = 1;

    int x3  = 300, y3  = 300,
        vx3 = 5,   vy3 = 2,
        ax3 = 0,   ay3 = 1;

    int dt = 1;

    while (!txGetAsyncKeyState (VK_ESCAPE))
        {
        DrawBall (x1, y1, vx1, vy1, TX_LIGHTRED, TX_BLUE);
        DrawBall (x2, y2, vx2, vy2, TX_LIGHTRED, TX_PINK);
        DrawBall (x3, y3, vx3, vy3, TX_LIGHTRED, TX_YELLOW);

        PhysicsBall (&x1, &y1, &vx1, &vy1, ax1, ay1, dt);
        PhysicsBall (&x2, &y2, &vx2, &vy2, ax2, ay2, dt);
        PhysicsBall (&x3, &y3, &vx3, &vy3, ax3, ay3, dt);

        ControlBall (&vx1, &vy1);

        txSleep (10);
        }
    }

void DrawBall (int x, int y, int vx, int vy, COLORREF color, COLORREF fillcolor)
    {
    txSetColor (color, 3);
    txSetFillColor (fillcolor);

    txCircle (x, y, 30);
    txLine   (x, y, x + vx*5, y + vy*5);
    txCircle (x + vx*5, y + vy*5, 3);
    }

void ControlBall (int* vx, int* vy)
    {
    if (txGetAsyncKeyState (VK_RIGHT)) (*vx)++;
    if (txGetAsyncKeyState (VK_LEFT))  (*vx)--;
    if (txGetAsyncKeyState (VK_UP))    (*vy)++;
    if (txGetAsyncKeyState (VK_DOWN))  (*vy)--;

    if (txGetAsyncKeyState (VK_SPACE)) *vx = *vy = 0;
    }

void PhysicsBall (int* x, int* y, int* vx, int* vy, int ax, int ay, int dt)
    {
    *vx = *vx + ax * dt;
    *vy = *vy + ay * dt;

    *x  = *x + *vx * dt;
    *y  = *y + *vy * dt;

    if (*x > 1500)
        {
        *vx = - *vx;
        *x = 1500;
        }

    if (*y > 800)
        {
        *vy = - *vy;
        *y = 800;
        }

    if (*x < 0)
        {
        *vx = - *vx;
        *x = 0;
        }

    if (*y < 0)
        {
        *vy = - *vy;
        *y = 0;
        }
    }
