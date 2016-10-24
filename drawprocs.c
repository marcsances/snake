// SNAKE++
// Copyright (c) 2013-2016, Marc Sances
// Procediments de dibuixat de SNAKE++.

/*
Copyright (c) 2016, Marc Sances
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/ 
#include "cutils.h"

void borrapuntsnake(int x, int y) {
gotoxy(21+x,1+y);
setformat(CL_CYAN,CL_CYAN,0);
printf(" ");
setformat(CL_BLUE,CL_BLUE,0);
gotoxy(30,24);
fflush(stdout);
}

void posapuntsnake(int x, int y) {
gotoxy(21+x,1+y);
setformat(CL_RED,CL_RED,0);
printf("█");
setformat(CL_BLUE,CL_BLUE,0);
gotoxy(30,24);
fflush(stdout);
}

void posacuc(int x, int y) {
gotoxy(21+x,1+y);
setformat(CL_BLACK,CL_CYAN,0);
printf("◉");
gotoxy(30,24);
fflush(stdout);
}

void actualitzardades(int score, int best, int level, int remaining) {
gotoxy(0,0);
drawrect(0,21,80,5,CL_BLUE);
setformat(CL_WHITE,CL_BLUE,0);
gotoxy(0,21);
printf("Score: %d",score);
gotoxy(0,22);
printf("Level: %d",level);
gotoxy(0,23);
printf("%d remaining for next level",remaining);
setformat(CL_BLUE,CL_BLUE,0);
gotoxy(30,24);
}

void drawui(int score, int best, int level, int remaining) {
// Dibuixar l'esquelet de la interfície
gotohome();
drawrect(0,0,80,24,CL_BLACK);
drawrect(21,1,40,19,CL_CYAN);
actualitzardades(score,best,level,remaining);
}


