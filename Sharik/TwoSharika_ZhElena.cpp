
#include "TXLib.h"

void MoveBall();

int main()
    {
    txCreateWindow (800, 600);

    MoveBall();

    return 0;
    }

void MoveBall()
    {
    int x  = 50, y  = 50, x1 = 750, y1 = 550,
        vx = 5,  vy = 3, vx1 = 5,  vy1 = 3,
        r  = 20;

    int dt = 1;

    txSetColor     (RGB (x,   y,   100), 2);
    txSetFillColor (RGB (x/2, y/2, 100));

    while (! txGetAsyncKeyState (VK_ESCAPE))
        {
        //txSetFillColor (TX_BLACK);
        //txClear();
        txCircle (x,  y,  r);
        txCircle (x1, y1, r);

        x  += vx  * dt;
        y  += vy  * dt;
        x1 += vx1 * dt;
        y1 += vy1 * dt;

        if (x > 800-r)
            {
            vx = -vx;
            x = 800-r;

            txSetColor     (RGB (x,   y,   50), 2);
            txSetFillColor (RGB (x/2, y/2, 50));
            }

        if (y > 600-r)
            {
            vy = -vy;
            y = 600-r;

            txSetColor     (RGB (x,   y,   100), 2);
            txSetFillColor (RGB (x/2, y/2, 100));
            }

        if (x < 0 + r)
            {
            vx = -vx;
            x = 0 + r;

            txSetColor     (RGB (x,   y,   150), 2);
            txSetFillColor (RGB (x/2, y/2, 150));
            }

        if (y < 0 + r)
            {
            vy = -vy;
            y = 0 + r;

            txSetColor     (RGB (x,   y,   200), 2);
            txSetFillColor (RGB (x/2, y/2, 200));
            }

        if (txGetAsyncKeyState (VK_RIGHT)) x +=10;
        if (txGetAsyncKeyState (VK_LEFT))  x -=10;
        if (txGetAsyncKeyState (VK_UP))    y -=10;
        if (txGetAsyncKeyState (VK_DOWN))  y +=10;

        if (x1 > 800-r)
            {
            vx1 = -vx1;
            x1 = 800-r;

            txSetColor     (RGB (x1,   y1,   50), 2);
            txSetFillColor (RGB (x1/2, y1/2, 50));
            }

        if (y1 > 600-r)
            {
            vy1 = -vy1;
            y1 = 600-r;

            txSetColor     (RGB (x1,   y1,   100), 2);
            txSetFillColor (RGB (x1/2, y1/2, 100));
            }

        if (x1 < 0 + r)
            {
            vx1 = -vx1;
            x1 = 0 + r;

            txSetColor     (RGB (x1,   y1,   150), 2);
            txSetFillColor (RGB (x1/2, y1/2, 150));
            }

        if (y1 < 0 + r)
            {
            vy1 = -vy1;
            y1 = 0 + r;

            txSetColor     (RGB (x1,   y1,   200), 2);
            txSetFillColor (RGB (x1/2, y1/2, 200));
            }

        txSleep (5);
        }
    }

