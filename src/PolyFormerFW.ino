#include "PolyFormerFW_menu.h"

#include <Wire.h>

void setup() {
    setupMenu();
    Wire.setClock(400000);      // Set the I2C SCL to 400kHz

}

void loop() {
    taskManager.runLoop();

}


void CALLBACK_FUNCTION onPidChange(int id) {
    // TODO - your menu change code
}



void CALLBACK_FUNCTION onGearboxChange(int id) {
    // TODO - your menu change code
}


void CALLBACK_FUNCTION onStart(int id) {
    // TODO - your menu change code
}


void CALLBACK_FUNCTION onTemperatureChange(int id) {
    // TODO - your menu change code
}


void CALLBACK_FUNCTION onSaveSettings(int id) {
    // TODO - your menu change code
}


void CALLBACK_FUNCTION onNameChanged(int id) {
    // TODO - your menu change code
}


void CALLBACK_FUNCTION onPIDTune(int id) {
    // TODO - your menu change code
}


void CALLBACK_FUNCTION onMotorCurrent(int id) {
    // TODO - your menu change code
}
