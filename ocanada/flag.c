//
//  flag.c
//  ocanada
//
//  Created by Jeremy Rand on 2017-07-01.
//  Copyright © 2017 Jeremy Rand. All rights reserved.
//

#include <apple2.h>
#include <stdbool.h>
#include <tgi.h>

#include "drivers/a2_lores_drv.h"
#include "flag.h"


void initGraphics(void)
{
    static bool tgi_inited = false;
    
    if (tgi_inited)
        return;
    
    // Install drivers
    tgi_install(&a2_lores_drv);
    
    tgi_init();
    
    // Mixed text and graphics mode
    tgi_apple2_mix(1);
    
    tgi_inited = true;
}


void drawFlag(void)
{
    initGraphics();
    
    tgi_setcolor(TGI_COLOR_MAGENTA);
    tgi_bar(0,0,9,39);
    tgi_bar(30,0,39,39);
    
    tgi_setcolor(TGI_COLOR_WHITE);
    tgi_bar(10,0,29,39);
    
    tgi_setcolor(TGI_COLOR_MAGENTA);
    tgi_bar(19,4,20,34);
    tgi_line(18,7,18,26);
    tgi_line(21,7,21,26);
    
    tgi_line(17,6,17,26);
    tgi_line(22,6,22,26);
    
    tgi_line(16,14,16,27);
    tgi_line(23,14,23,27);
    
    tgi_line(15,13,15,27);
    tgi_line(24,13,24,27);
    
    tgi_line(14,12,14,28);
    tgi_line(25,12,25,28);
    
    tgi_line(13,14,13,26);
    tgi_line(26,14,26,26);
    
    tgi_line(12,13,12,23);
    tgi_line(27,13,27,23);
    
    tgi_line(11,16,11,20);
    tgi_line(28,16,28,20);
}
