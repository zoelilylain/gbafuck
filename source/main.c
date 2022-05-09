
#include <gba_console.h>
#include <gba_video.h>
#include <gba_interrupt.h>
#include <gba_systemcalls.h>
#include <gba_input.h>
#include <stdio.h>
#include <stdlib.h>

//---------------------------------------------------------------------------------
// Program entry point
//---------------------------------------------------------------------------------
int main(void) {
//---------------------------------------------------------------------------------


	// the vblank interrupt must be enabled for VBlankIntrWait() to work
	// since the default dispatcher handles the bios flags no vblank handler
	// is required
	irqInit();
	irqEnable(IRQ_VBLANK);
	//and here i create our cell array
	int bfvar[100];
	int curbfvar;
	curbfvar = 0;
	consoleDemoInit();

	// ansi escape sequence to set print co-ordinates
	// /x1b[line;columnH
	iprintf("\x1b[1;1HReady for input!\n");
do {
	int keys_pressed, keys_released;
	scanKeys();
	keys_pressed = keysDown();
	keys_released = keysUp();
	VBlankIntrWait();
	//key checking within, a increases, b decreses, select clears.
	//value updates everytime either a or b is released.
	if ( keys_pressed & KEY_A ) {
		bfvar[curbfvar] = bfvar[curbfvar] + 1;
	}
	if ( keys_released & KEY_A ) {
		iprintf("\x1b[2J");
		iprintf("\x1b[1;1HCurrent Value is: %d", bfvar[curbfvar]);
	}
	if ( keys_pressed & KEY_B ) {
		bfvar[curbfvar] = bfvar[curbfvar] - 1;
	}
	if ( keys_released & KEY_B ) {
		iprintf("\x1b[2J");
		iprintf("\x1b[1;1HCurrent Value is: %d", bfvar[curbfvar]);
	}
	if ( keys_pressed & KEY_SELECT ) {
		bfvar[curbfvar] = 0;
	}
	if ( keys_released & KEY_SELECT ) {
		iprintf("\x1b[2J");
                iprintf("\x1b[1;1HCurrent Value is: %d", bfvar[curbfvar]);
	}
	if ( keys_pressed & KEY_R ) {
		curbfvar = curbfvar + 1;
	}
	if (keys_released & KEY_R ) {
		iprintf("\x1b[2;1HCurrent Cell is Cell: %d", curbfvar);
	}
	if ( keys_pressed & KEY_L ) {
		curbfvar = curbfvar - 1;
	}
	if ( keys_released & KEY_L ) {
		iprintf("\x1b[2;1HCurrent Cell is Cell: %d", curbfvar);
	}

	} while (1);
}


