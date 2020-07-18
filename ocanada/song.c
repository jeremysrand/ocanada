//
//  song.c
//  ocanada
//
//  Created by Jeremy Rand on 2017-07-01.
//  Copyright © 2017 Jeremy Rand. All rights reserved.
//

#include <conio.h>
#include <stdint.h>
#include <stdio.h>

#include "mockingboard.h"
#include "song.h"



typedef struct tSongNote {
    uint16_t mainTone;
    uint16_t bassTone;
    uint8_t duration;
    char *words;
} tSongNote;


static tSongNote notes[] = {
    { TONE_PERIOD_E(4), TONE_PERIOD_C(2), 8, "\n\nO" },
    { TONE_PERIOD_G(4), TONE_PERIOD_G(2), 6, " CAN" },
    { TONE_PERIOD_G(4), TONE_PERIOD_G(2), 2, "A" },
    { TONE_PERIOD_C(4), TONE_PERIOD_A(2), 12, "DA" },
    { TONE_PERIOD_D(4), TONE_PERIOD_A(2), 4, "\nOUR" },
    { TONE_PERIOD_E(4), TONE_PERIOD_C(2), 4, " HOME" },
    { TONE_PERIOD_F(4), TONE_PERIOD_C(2), 4, " AND" },
    { TONE_PERIOD_G(4), TONE_PERIOD_C(2), 4, " NA" },
    { TONE_PERIOD_A(4), TONE_PERIOD_C(2), 4, "TIVE" },
    { TONE_PERIOD_D(4), TONE_PERIOD_G(2), 16, " LAND" },
    { TONE_PERIOD_E(4), TONE_PERIOD_C(2), 8, "\nTRUE" },
    { TONE_PERIOD_F_SHARP(4), TONE_PERIOD_D(2), 6, " PA" },
    { TONE_PERIOD_F_SHARP(4), TONE_PERIOD_D(2), 2, "TRIOT" },
    { TONE_PERIOD_G(4), TONE_PERIOD_G(2), 12, " LOVE" },
    { TONE_PERIOD_A(4), TONE_PERIOD_G(2), 4, " IN" },
    { TONE_PERIOD_B(4), TONE_PERIOD_G(2), 4, "\nALL" },
    { TONE_PERIOD_B(4), TONE_PERIOD_G(2), 4, " OF" },
    { TONE_PERIOD_A(4), TONE_PERIOD_D(2), 4, " US" },
    { TONE_PERIOD_A(4), TONE_PERIOD_D(2), 4, " COM" },
    { TONE_PERIOD_G(4), TONE_PERIOD_G(2), 12, "MAND" },
    { TONE_PERIOD_D(4), TONE_PERIOD_G(2), 3, "\nWITH" },
    { TONE_PERIOD_E(4), TONE_PERIOD_G(2), 1, "" },
    { TONE_PERIOD_F(4), TONE_PERIOD_G(2), 6, " GLOW" },
    { TONE_PERIOD_E(4), TONE_PERIOD_G(2), 2, "ING" },
    { TONE_PERIOD_D(4), TONE_PERIOD_G(2), 4, " HEARTS" },
    { TONE_PERIOD_E(4), TONE_PERIOD_G(2), 3, " WE" },
    { TONE_PERIOD_F(4), TONE_PERIOD_G(2), 1, "" },
    { TONE_PERIOD_G(4), TONE_PERIOD_C(2), 6, " SEE" },
    { TONE_PERIOD_F(4), TONE_PERIOD_C(2), 2, " THEE" },
    { TONE_PERIOD_E(4), TONE_PERIOD_C(2), 4, " RISE" },
    { TONE_PERIOD_F(4), TONE_PERIOD_C(2), 3, "\nTHE" },
    { TONE_PERIOD_G(4), TONE_PERIOD_C(2), 1, "" },
    { TONE_PERIOD_A(4), TONE_PERIOD_F(2), 4, " TRUE" },
    { TONE_PERIOD_G(4), TONE_PERIOD_F(2), 4, " NORTH" },
    { TONE_PERIOD_F(4), TONE_PERIOD_F(2), 4, " STRONG" },
    { TONE_PERIOD_E(4), TONE_PERIOD_F(2), 4, " AND" },
    { TONE_PERIOD_D(4), TONE_PERIOD_G(2), 12, " FREE" },
    { TONE_PERIOD_D(4), TONE_PERIOD_G(2), 3, "\nFROM" },
    { TONE_PERIOD_E(4), TONE_PERIOD_G(2), 1, "" },
    { TONE_PERIOD_F(4), TONE_PERIOD_G(2), 6, " FAR" },
    { TONE_PERIOD_E(4), TONE_PERIOD_G(2), 2, " AND" },
    { TONE_PERIOD_D(4), TONE_PERIOD_G(2), 4, " WIDE" },
    { TONE_PERIOD_E(4), TONE_PERIOD_G(2), 3, ", O" },
    { TONE_PERIOD_F(4), TONE_PERIOD_G(2), 1, "" },
    { TONE_PERIOD_G(4), TONE_PERIOD_C(2), 6, " CAN" },
    { TONE_PERIOD_F(4), TONE_PERIOD_C(2), 2, "A" },
    { TONE_PERIOD_E(4), TONE_PERIOD_C(2), 4, "DA" },
    { TONE_PERIOD_E(4), TONE_PERIOD_C(2), 4, "\nWE" },
    { TONE_PERIOD_D(4), TONE_PERIOD_G(2), 4, " STAND" },
    { TONE_PERIOD_G(4), TONE_PERIOD_G(2), 4, " ON" },
    { TONE_PERIOD_G(4), TONE_PERIOD_D(2), 2, " GUARD" },
    { TONE_PERIOD_F_SHARP(4), TONE_PERIOD_D(2), 2, "" },
    { TONE_PERIOD_E(4), TONE_PERIOD_D(2), 2, " FOR" },
    { TONE_PERIOD_F_SHARP(4), TONE_PERIOD_D(2), 2, "" },
    { TONE_PERIOD_G(4), TONE_PERIOD_G(2), 16, " THEE" },
    { TONE_PERIOD_E(4), TONE_PERIOD_C(2), 8, "\nGOD" },
    { TONE_PERIOD_G(4), TONE_PERIOD_G(2), 6, " KEEP" },
    { TONE_PERIOD_G(4), TONE_PERIOD_G(2), 2, " OUR" },
    { TONE_PERIOD_C(4), TONE_PERIOD_A(2), 16, " LAND" },
    { TONE_PERIOD_F(4), TONE_PERIOD_D(2), 8, ", GLO" },
    { TONE_PERIOD_A(4), TONE_PERIOD_D(2), 6, "RIOUS" },
    { TONE_PERIOD_A(4), TONE_PERIOD_D(2), 2, " AND" },
    { TONE_PERIOD_D(4), TONE_PERIOD_G(2), 16, " FREE" },
    { TONE_PERIOD_G(4), TONE_PERIOD_C(2), 8, "\nO" },
    { TONE_PERIOD_G_SHARP(4), TONE_PERIOD_E(2), 6, " CAN" },
    { TONE_PERIOD_G_SHARP(4), TONE_PERIOD_E(2), 2, "A" },
    { TONE_PERIOD_A(4), TONE_PERIOD_F(2), 4, "DA" },
    { TONE_PERIOD_F(4), TONE_PERIOD_F(2), 4, ", WE" },
    { TONE_PERIOD_E(4), TONE_PERIOD_C(2), 4, " STAND" },
    { TONE_PERIOD_D(4), TONE_PERIOD_C(2), 4, " ON" },
    { TONE_PERIOD_C(4), TONE_PERIOD_A(2), 8, " GUARD" },
    { TONE_PERIOD_D(4), TONE_PERIOD_D(2), 8, " FOR" },
    { TONE_PERIOD_E(4), TONE_PERIOD_E(2), 16, " THEE" },
    { TONE_PERIOD_G(4), TONE_PERIOD_C(2), 8, "\nO" },
    { TONE_PERIOD_C(5), TONE_PERIOD_C(2), 6, " CAN" },
    { TONE_PERIOD_C(5), TONE_PERIOD_C(2), 2, "A" },
    { TONE_PERIOD_A(4), TONE_PERIOD_F(2), 4, "DA" },
    { TONE_PERIOD_F(4), TONE_PERIOD_F(2), 4, ", WE" },
    { TONE_PERIOD_E(4), TONE_PERIOD_C(2), 4, " STAND" },
    { TONE_PERIOD_D(4), TONE_PERIOD_C(2), 4, " ON" },
    { TONE_PERIOD_G(4), TONE_PERIOD_C(2), 8, " GUARD" },
    { TONE_PERIOD_B(4), TONE_PERIOD_G(2), 8, " FOR" },
    { TONE_PERIOD_C(5), TONE_PERIOD_C(2), 16, " THEE!" },
};


void delay(uint8_t duration)
{
    uint8_t count;
    
    for (count = 0; count < duration; count++) {
        uint16_t insideCount = 0;
        do {
            insideCount++;
        } while (insideCount != 768);
    }
}


void playSong(void)
{
    uint16_t noteNum;
    static tMockingSoundRegisters regs;
    
    regs.noisePeriod = MIN_NOISE_PERIOD;
    regs.enable = ENABLE_ALL_TONE_CHANNELS;
    regs.amplitude[0] = MAX_AMPLITUDE;
    regs.amplitude[1] = MAX_AMPLITUDE;
    regs.amplitude[2] = MAX_AMPLITUDE;
    regs.envelopePeriod = MIN_ENVELOPE_PERIOD;
    regs.envelopeShape = ENVELOPE_SHAPE_CONT_ATTACK_HOLD;
    
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    for (noteNum = 0; noteNum < (sizeof(notes) / sizeof(notes[0])); noteNum++) {
        regs.tonePeriod[0] = notes[noteNum].mainTone;
        regs.tonePeriod[1] = notes[noteNum].mainTone;
        regs.tonePeriod[2] = notes[noteNum].bassTone;
        
        mockingBoardPlaySound(SPEAKER_BOTH, &regs);
        printf("%s", notes[noteNum].words);
        delay(notes[noteNum].duration);
    }
    mockingBoardStopSound(SPEAKER_BOTH);
    cgetc();
}
