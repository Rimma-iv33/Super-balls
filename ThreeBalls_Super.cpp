#include "TXLib.h"

void MoveBall ();

struct Ball
    {
    int x,  y,
        vx, vy;
    int r;

    COLORREF color;
    COLORREF fillcolor;
    };

void DrawBall    (struct Ball  ball);
void PhysicsBall (struct Ball* ball, int ax, int ay, int dt);
void ControlBall (struct Ball* ball1);
void BoomBalls (struct Ball* ball1, struct Ball* ball2);
void DrawScore (int score1, int score2);

bool LeftGoal  (struct Ball ball);
bool RightGoal (struct Ball ball);

double Distance (struct Ball ball1, struct Ball ball2);

//-------------------------------------------------------------

int main()
    {
    txCreateWindow (1500, 800);

    MoveBall();

    return 0;
    }

//-------------------------------------------------------------

void MoveBall()
    {
    HDC fon = txLoadImage("fonsuper.bmp");

    Ball ball1 = {100, 100, 3, 2, 17, TX_LIGHTRED, TX_BLUE};
    Ball ball2 = {500, 100, 5, 2, 27, TX_LIGHTRED, TX_PINK};
    Ball ball3 = {300, 100, 5, 2, 21, TX_LIGHTRED, TX_YELLOW};

    int ax = 0, ay = 1;

    int dt = 1;

    int score1 = 0;
    int score2 = 0;

    while (!txGetAsyncKeyState (VK_ESCAPE))
        {
        txBegin ();

        txBitBlt  (txDC(), 0, 0, 1500, 800, fon, 0, 0);

        DrawScore (score1, score2);

        DrawBall (ball1);
        DrawBall (ball2);
        DrawBall (ball3);

        PhysicsBall (&ball1, ax, ay, dt);
        PhysicsBall (&ball2, ax, ay, dt);
        PhysicsBall (&ball3, ax, ay, dt);

        double dist = Distance (ball1, ball2);

        if (dist <= ball1.r + ball2.r)
            {
            BoomBalls (&ball1, &ball2);
            }

        if (LeftGoal  (ball1)) score1++;
        if (RightGoal (ball1)) score2++;

        ControlBall (&ball1);

        txEnd ();

        txSleep (10);
        }
    txDeleteDC (fon);
    }

//-------------------------------------------------------------

void BoomBalls (struct Ball* ball1, struct Ball* ball2)
    {
    (*ball1).vx = -(*ball1).vx;
    (*ball1).vy = -(*ball1).vy;
    (*ball2).vx = -(*ball2).vx;
    (*ball2).vy = -(*ball2).vy;
    }

//-------------------------------------------------------------

double Distance (struct Ball ball1, struct Ball ball2)
    {
    return sqrt ((ball1.x - ball2.x)*(ball1.x - ball2.x) + (ball1.y - ball2.y)*(ball1.y - ball2.y));
    }

//-------------------------------------------------------------

void DrawBall (struct Ball ball)
    {
    txBegin ();
    txSetColor (ball.color, 2);
    txSetFillColor (ball.fillcolor);

    txCircle (ball.x, ball.y, ball.r);
    txLine   (ball.x, ball.y, ball.x + ball.vx*5, ball.y + ball.vy*5);
    txCircle (ball.x + ball.vx*5, ball.y + ball.vy*5, 3);
    txEnd ();
    }

//-------------------------------------------------------------

void ControlBall (struct Ball* ball1)
    {
    if (txGetAsyncKeyState (VK_RIGHT)) (*ball1).vx = (*ball1).vx + 1;
    if (txGetAsyncKeyState (VK_LEFT))  (*ball1).vx = (*ball1).vx - 1;
    if (txGetAsyncKeyState (VK_UP))    (*ball1).vy = (*ball1).vy - 1;
    if (txGetAsyncKeyState (VK_DOWN))  (*ball1).vy = (*ball1).vy + 1;

    if (txGetAsyncKeyState (VK_SPACE)) (*ball1).vx = (*ball1).vy = 0;
    }

//-------------------------------------------------------------

void PhysicsBall (struct Ball* ball, int ax, int ay, int dt)
    {
    (*ball).vx = (*ball).vx + ax * dt;
    (*ball).vy = (*ball).vy + ay * dt;

    (*ball).x  = (*ball).x + (*ball).vx * dt;
    (*ball).y  = (*ball).y + (*ball).vy * dt;

    if ((*ball).x > 1500 - (*ball).r)
        {
        (*ball).vx = -(*ball).vx;
        (*ball).x  = 1500 - (*ball).r;
        }

    if ((*ball).y > 800 - (*ball).r)
        {
        (*ball).vy = -(*ball).vy;
        (*ball).y  = 800 - (*ball).r;
        }

    if ((*ball).x < 0 + (*ball).r)
        {
        (*ball).vx = -(*ball).vx;
        (*ball).x  = 0 + (*ball).r;
        }

    if ((*ball).y < 0 + (*ball).r)
        {
        (*ball).vy = -(*ball).vy;
        (*ball).y  = 0 + (*ball).r;
        }
    }

//-------------------------------------------------------------

void DrawScore (int score1, int score2)
    {
    txBegin ();
    txSelectFont ("TimesNewRoman", 60);
    char str[10] = "";
    sprintf (str, "%d : %d", score1, score2);

    int centerX = txGetExtentX()/2;

    int textSizeX = txGetTextExtentX ("------"),
        textSizeY = txGetTextExtentY ("------");

    txSetFillColor (TX_BLACK);
    txRectangle (centerX - textSizeX, 0,
                 centerX + textSizeX, textSizeY);
    txTextOut   (centerX - textSizeX/2, 0, str);
    txEnd ();
    }


//-------------------------------------------------------------

bool LeftGoal (struct Ball ball)
    {
    return (ball.y > 430) && (ball.y < 560) && (ball.x - ball.r <= 0);
    }

//-------------------------------------------------------------

bool RightGoal (struct Ball ball)
    {
    return (ball.y > 430) && (ball.y < 560) && (ball.x + ball.r >= 1500);
    }

