#include "TXLib.h"

void MoveBall();

void DrawBall (int x, int y, int r, COLORREF color, COLORREF fillColor);
void ControlBall (int* x, int* y, int* vx, int* vy);
void PhysicsBall (int* x, int* y, int* vx, int* vy, int r, int dt);

int main()
    {
    txCreateWindow (800, 600);

    MoveBall();

    return 0;
    }

//----------------------------------------------------------------------

void MoveBall()
    {
    int  x1 = 50, y1 = 50,
        vx1 = 5, vy1 = 3,
         r1 = 20;

    int  x2 = 750, y2 = 550,
        vx2 = 5,  vy2 = 3,
         r2 = 20;

    int dt = 1;

    while (!txGetAsyncKeyState (VK_ESCAPE))
        {
        //txSetFillColor (TX_BLACK);
        //txClear();

        DrawBall (x1, y1, r1, RGB (x1, y1, 100), RGB (x1/2, y1/2, 100));
        DrawBall (x2, y2, r2, RGB (x2, y2, 100), RGB (x2/2, y2/2, 100));

        PhysicsBall (&x1, &y1, &vx1, &vy1, r1, dt);
        PhysicsBall (&x2, &y2, &vx2, &vy2, r2, dt);

        ControlBall (&x1, &y1, &vx1, &vy1);

        txSleep (10);
        }
    }

//----------------------------------------------------------------------

void DrawBall (int x, int y, int r, COLORREF color, COLORREF fillColor)
    {
    txSetColor (color, 2);
    txSetFillColor (fillColor);

    txCircle (x, y, r);
    }

//----------------------------------------------------------------------

void ControlBall (int* x, int* y, int* vx, int* vy)
    {
    if (txGetAsyncKeyState (VK_RIGHT)) *x += 10;
    if (txGetAsyncKeyState (VK_LEFT))  *x -= 10;
    if (txGetAsyncKeyState (VK_UP))    *y -= 10;
    if (txGetAsyncKeyState (VK_DOWN))  *y += 10;

    if (txGetAsyncKeyState (VK_SPACE)) *vx = *vy = 0;
    }

//----------------------------------------------------------------------

void PhysicsBall (int* x, int* y, int* vx, int* vy, int r, int dt)
    {
    *x = *x + *vx * dt;
    *y = *y + *vy * dt;

    if (*x > 800 - r)
        {
        *vx = - *vx;
        *x = 800 - r;
        }

    if (*y > 600 - r)
        {
        *vy = - *vy;
        *y = 600 - r;
        }

    if (*x < 0 + r)
        {
        *vx = - *vx;
        *x = 0 + r;
        }

    if (*y < 0 + r)
        {
        *vy = - *vy;
        *y = 0 + r;
        }
    }
