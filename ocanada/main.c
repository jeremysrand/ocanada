/*
 * main.c
 * ocanada
 *
 * Created by Jeremy Rand on 2017-07-01.
 * Copyright (c) 2017 Jeremy Rand. All rights reserved.
 *
 */


#include <apple2.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "flag.h"
#include "mockingboard.h"
#include "song.h"


void showTitleScreen(void)
{
    clrscr();
    printf("%s",
           //0000000001111111111222222222233333333334
           //1234567890123456789012345678901234567890
           "            HAPPY CANADA DAY\n"
           "              JULY 1, 2017\n"
           "                   BY\n"
           "               JEREMY RAND\n"
           "\n"
           "THIS PROGRAM REQUIRES A MOCKINGBOARD TO\n"
           "PLAY THE SONG\n"
           "\n");
}


tSlot getSlotNum(void)
{
    printf("MOCKINGBOARD SLOT NUMBER [1-7]?");
    while (true) {
        char ch = cgetc();
        if ((ch >= '1') &&
            (ch <= '7'))
            return (ch - '0');
        
        if ((ch == '0') ||
            (ch == 'q') ||
            (ch == 'Q') ||
            (ch == CH_ESC))
            exit(0);
        
        printf("\007");
    }
}

int main(void)
{
    showTitleScreen();
    mockingBoardInit(getSlotNum(), false);
    drawFlag();
    playSong();
    return 0;
}
