#include "PlatformioCICD_menu.h"

// This variable is the RAM data for scroll choice item Scroll
char* ramDataSet = "1\0        2\0        3\0        4\0        5\0        ~";


void setup() {
    setupMenu();

}

void loop() {
    taskManager.runLoop();

}


void CALLBACK_FUNCTION onDecimalStepChange(int id) {
    // TODO - your menu change code
}



void CALLBACK_FUNCTION decimalDidChange(int id) {
    // TODO - your menu change code
}

// see tcMenu list documentation on thecoderscorner.com
int CALLBACK_FUNCTION fnRuntimesCustomListRtCall(RuntimeMenuItem* item, uint8_t row, RenderFnMode mode, char* buffer, int bufferSize) {
   switch(mode) {
    case RENDERFN_INVOKE:
        // TODO - your code to invoke goes here - row is the index of the item
        return true;
    case RENDERFN_NAME:
        // TODO - each row has it's own name - 0xff is the parent item
        ltoaClrBuff(buffer, row, 3, NOT_PADDED, bufferSize);
        return true;
    case RENDERFN_VALUE:
        // TODO - each row can has its own value - 0xff is the parent item
        buffer[0] = 'V'; buffer[1]=0;
        fastltoa(buffer, row, 3, NOT_PADDED, bufferSize);
        return true;
    case RENDERFN_EEPROM_POS: return 0xffff; // lists are generally not saved to EEPROM
    default: return false;
    }
}


void CALLBACK_FUNCTION saveWasPressed(int id) {
    // TODO - your menu change code
}


void CALLBACK_FUNCTION largeNumDidChange(int id) {
    // TODO - your menu change code
}
