#include "drawprocs.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "iqueue.h"

#define true 1
#define false 0

int *ti(int val)
{
    int *v = malloc(sizeof(int));
    *v = val;
    return v;
}

int gi(void *val)
{
    int *v = (int *)val;
    return *v;
}

void quitproc(int score, int level)
{
    char k;
    // Escape premut
    reset_terminal_mode();
    formatreset();
    clrscr();
    printf("Game over. You've scored %d points at level %d!.\n", score, level);
    printf("Press Enter to quit the game.\n");
    k = getch();
    while (k != 11 && k != 13)
    {
	k = getch();
    }
    reset_terminal_mode();
    formatreset();
    clrscr();
    printf("\033[?1049l"); //get back to standard terminal world
    exit(0);
}

int main()
{
    // DECLARACIONS DE VARIABLES GLOBALS
    void *posicionsx, *posicionsy;
    int cucx, cucy, direction = 0, quitting = false, midaserp = 6, totesx[128], totesy[128];
    int score = 0, level = 0, cucs = 9, posarcuc = false, i, iniposx, iniposy, f, novax, novay, repetir;
    double coef = 0.6;
    char k;
    clock_t init, final;
    // --
    printf("\033[?1049h\033[H"); // switch to magical terminal world
    clrscr();
    setformat(CL_GREEN, CL_BLACK, 0);
    srand(time(NULL));
    printf("********************************************************************************\n");
    printf("*                ******** *      * ******** *      * ********                  *\n");
    printf("*                *        **     * *      * *    **  *                         *\n");
    printf("*                *        * *    * *      * *  **    *                         *\n");
    printf("*                ******** *  *   * ******** ***      ********                  *\n");
    printf("*                       * *   *  * *      * * **     *                         *\n");
    printf("*                       * *    * * *      * *  **    *                         *\n");
    printf("*                ******** *     ** *      * *   **   ********                  *\n");
    printf("*                (c) 2016 *      * *      * *    **  by MarcS                  *\n");
    printf("********************************************************************************\n");
    printf("                                                                                \n");
    printf("                                                                                \n");
    printf("                               Press ENTER to play                              \n");
    k = getch();
    while (k != 11 && k != 13 && k != 27)
    {
	if (k == 27 && kbhit() && getch() == '[')
	{
	    getch();
	}
	k = getch();
    }
    if (k != 27)
    {
	clrscr();
	drawui(score, 0, level, cucs);
	iniposx = rand() % 33 + 1;
	iniposy = rand() % 18 + 1;
	cucx = rand() % 33 + 1;
	cucy = rand() % 18 + 1;
	while ((iniposx - cucx) <= 5 && (iniposx - cucx) >= 0 && cucy == iniposy)
	{
	    // hem de dur-lo a un altre lloc
	    cucx = rand() % 33 + 1;
	    cucy = rand() % 18 + 1;
	}
	posacuc(cucx, cucy);
	posicionsx = qalloc(sizeof(int));
	posicionsy = qalloc(sizeof(int));
	for (i = iniposx; i <= iniposx + 5; i++)
	{
	    qpush(posicionsx, ti(i));
	    qpush(posicionsy, ti(iniposy));
	    posapuntsnake(i, iniposy);
	    totesx[i - iniposx] = i;
	    totesy[i - iniposx] = iniposy;
	}

	while (!quitting)
	{
	    // bucle principal

	    fflush(stdout);
	    // No s'ha premut cap tecla, ens dediquem a esperar i moure la serp
	    init = clock();
	    f = kbhit();
	    while (((double)(clock() - init) / ((double)CLOCKS_PER_SEC) < coef) && f == false)
	    {
		f = kbhit();
	    }
	    if (f)
	    {
		// S'ha premut una tecla.
		k = getch();
		if (k == 27 && !kbhit())
		{
		    quitproc(score, level);
		}
		else if (k == 27 && kbhit())
		{
		    getch();
		    k = getch();
		    if (k == 'A')
		    {
			if (direction != 3)
			{
			    direction = 1;
			}
		    }
		    else if (k == 'B')
		    {
			if (direction != 1)
			{
			    direction = 3;
			}
		    }
		    else if (k == 'D')
		    {
			if (direction != 0)
			{
			    direction = 2;
			}
		    }
		    else if (k == 'C')
		    {
			if (direction != 2)
			{
			    direction = 0;
			}
		    }
		}
	    }
	    // Moure la serp
	    switch (direction)
	    {
	    case 0:
		if (gi(qback(posicionsx)) < 39)
		{
		    novax = gi(qback(posicionsx)) + 1;
		    novay = gi(qback(posicionsy));
		}
		else
		{
		    quitproc(score, level);
		}
		break;
	    case 1:
		if (gi(qback(posicionsy)) > 0)
		{
		    novax = gi(qback(posicionsx));
		    novay = gi(qback(posicionsy)) - 1;
		}
		else
		{
		    quitproc(score, level);
		}
		break;
	    case 2:
		if (gi(qback(posicionsx)) > 0)
		{
		    novax = gi(qback(posicionsx)) - 1;
		    novay = gi(qback(posicionsy));
		}
		else
		{
		    quitproc(score, level);
		}
		break;
	    case 3:
		if (gi(qback(posicionsy)) < 18)
		{
		    novax = gi(qback(posicionsx));
		    novay = gi(qback(posicionsy)) + 1;
		}
		else
		{
		    quitproc(score, level);
		}
		break;
	    }
	    posapuntsnake(novax, novay);
	    if (cucx != novax || cucy != novay)
	    {
		borrapuntsnake(gi(qpop(posicionsx)), gi(qpop(posicionsy)));
		// Les posicions velles només s'esborren si la serp no ha menjat el cuc.
	    }
	    else
	    {
		midaserp += 1;
		cucs -= 1;
		score += 1;
		if (cucs == 0)
		{
		    level += 1;
		    coef = coef / 1.3;
		    cucs = 9 + (2 * level);
		}
		actualitzardades(score, 0, level, cucs);
		cucx = 100; // invalidem la posició del cuc.
		cucy = 100;
		posarcuc = true;
	    }
	    qpush(posicionsx, ti(novax));
	    qpush(posicionsy, ti(novay));
	    fflush(stdout);
	    // Detectar colisions
	    for (i = 0; i < midaserp; i++)
	    {
		if (totesx[i] == novax && totesy[i] == novay)
		{
		    quitproc(score, level);
		}
		totesx[i] = totesx[i + 1];
		totesy[i] = totesy[i + 1];
	    }
	    totesx[midaserp - 1] = novax;
	    totesy[midaserp - 1] = novay;
	    repetir = true;
	    if (posarcuc)
	    {
		// posem un nou cuc
		while (repetir)
		{
		    repetir = false;
		    cucx = rand() % 33 + 1;
		    cucy = rand() % 18 + 1;
		    for (i = 0; i < midaserp; i++)
		    {
			if (cucx == totesx[i] && cucy == totesy[i])
			{
			    repetir = true; // cal generar un nou cuc...
			}
		    }
		}
		posacuc(cucx, cucy);
		fflush(stdout);
		posarcuc = false;
	    }
	}
    }
    reset_terminal_mode();
    formatreset();
    clrscr();
}
