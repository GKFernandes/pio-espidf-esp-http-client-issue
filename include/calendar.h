/*
 ******************************************************************************
 * Circuits - Hardware & Firmware Design
 * www.circuits.com.br
 *
 * File: calendar.h
 * Brief: Handle calendar events and clock
 * Created on: Nov 28, 2020
 * Author: Luccas Meller
 ******************************************************************************
 */

#define SYNC_TIMEOUT 3U

#include <Arduino.h>
#include <ezTime.h>
#include "parameters.h"


class SolarCalendar{

    private:
        static void setupEvents();


    public:
        static void syncTime(Parameters* gP);
        static void setSavedEvents(Parameters* gP);
        static void setup(int8_t timez);
        static void setCalEvent(uint8_t evt_num, int8_t FE, int8_t FC, uint16_t HN, uint16_t HF, int8_t timez);
        static void checkEvents();
        static void startEvent(uint8_t dFC);
        static void stopEvent(uint8_t dFC);
        static bool checkAnyEventSet();
        static bool checkAnyEventStarted();
        static bool checkEventStarted(uint8_t evt_function);
        static time_t getUTC();
        static void setUTC(time_t t);
        static bool isSynced();
        static void cancelEvents();
        static bool checkEventsPriority(uint8_t priority);
        static void resetEvent(uint8_t evt_num);
        static void resetPriorityEvent(uint8_t evt_num);
        static void setTimeZone(int8_t timez);

};
