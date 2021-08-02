/*
 ******************************************************************************
 * Circuits - Hardware & Firmware Design
 * www.circuits.com.br
 *
 * File: process.h
 * Brief: Komeco Solar main process functions.
 * Created on: Set 14, 2020
 * Author: Luccas Meller
 ******************************************************************************
 */

/**
    @brief Process the main control functions using all the temperature values and parameters.  

    @return None
*/

#include <stdint.h>

void processInit();
bool getAuxStatus();
bool getPumpStatus();
void pumpWrite(uint8_t state);
void auxWrite(uint8_t state);
void process(float NTC1_val, float NTC2_val, float NTC3_val);
void eventFired(uint8_t FC);
void processTimers();
void checkProtections(float NTC1_val, float NTC2_val, float NTC3_val);