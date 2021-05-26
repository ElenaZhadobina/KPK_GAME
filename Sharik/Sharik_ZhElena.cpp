
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
    int x  = 50, y  = 50,
        vx = 5,  vy = 3,
        r  = 20;

    int dt = 1;

    txSetColor     (RGB (x,   y,   100), 2);
    txSetFillColor (RGB (x/2, y/2, 100));

    while (! txGetAsyncKeyState (VK_ESCAPE))
        {
        txCircle (x, y, r);

        x += vx * dt;
        y += vy * dt;

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

        if (txGetAsyncKeyState (VK_RIGHT)) vx++;
        if (txGetAsyncKeyState (VK_LEFT))  vx--;
        if (txGetAsyncKeyState (VK_UP))    vy++;
        if (txGetAsyncKeyState (VK_DOWN))  vy--;

        txSleep (5);
        }
    }

