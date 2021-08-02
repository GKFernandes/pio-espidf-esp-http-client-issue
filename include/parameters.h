/*
 ******************************************************************************
 * Circuits - Hardware & Firmware Design
 * www.circuits.com.br
 *
 * File: parameters.h
 * Brief: Parameter variables and functions for Solar-IoT operations.
 * Created on: Set 14, 2020
 * Author: Luccas Meller
 ******************************************************************************
 */

#ifndef _PARAMETERS_H_
#define _PARAMETERS_H_

#include <stdint.h>

#define PARAMS_EEPROM_START_ADDR 0
#define MAX_NUM_EVENTS 4
#define NUM_OCULT_PARAMS 4
#define NUM_PARAMETERS (TOTAL_PARAM - NUM_OCULT_PARAMS)

enum PARAMETERS_TABLE
{
    Npmode, /* Define the bump mode (relay 1): 0: Auto, 1: ON, 2: OFF */
    Namode, /* Define the aux mode (relay 2): 0: Auto, 1: ON, 2: OFF */
    NSETP, /*Aux auto mode setpoint*/
    Nr0, /* Differential thermal value to turn the main pump ON*/
    Nr1, /* Differential thermal value to turn the main pump OFF*/
    NP0, /* Protection thermal value to avoid freezing the colectors, turning the pump ON*/
    NP1, /* Protection thermal value to avoid overheat the colectors, turning the pump OFF*/
    NP2, /* Protection thermal value to avoid overheat the reservatory, turning the pump ON*/
    NP3, /* Protection thermal value to avoid overheat the reservatory, turning the pump OFF*/
    NP5, /* Delay to keep P0 case to guarantee water flowing over all path*/
    NP6, /* Re-flowing option, keep constantly water flowing through colectors, to get better T1 value. (For higher colectors distances) */
    NP7, /* Thermal value to cool the water on reservatory under P2 case (with T1-T2 < -3), turning the pump ON*/
    NP8, /* Max time for pump to be ON [1..999 minutes] */
    NAP0, /* Max time for aux (relay2) to be ON [1..600 minutes] */
    NAP1, /* Thermal value of histeresis under On/Off for aux (realy2) */
    NRc0, /* Define the aux (relay2) mode: 0- OFF; 1- Aux; 2- Filter */
    NFE1, NFE2, NFE3, NFE4, /* Day frequency for events: 0- OFF; 1- mon to fri; 2- mon to sat; 3- sat to sun;e 4- everyday */
    NFC1, NFC2, NFC3, NFC4, /* Event function: 0- Time interval to keep system OFF; 1- Hour to keep extra system ON; 2- Hour for filter ON*/
    NHN1, NHN2, NHN3, NHN4, /* Initial time for event (12:00 AM to 11:59 PM)*/
    NHF1, NHF2, NHF3, NHF4, /* End time for event (12:00 AM to 11:59 PM)*/
    NCA1, /*NTC 1 Thermal calibration value (thermal offset)*/
    NCA2, /*NTC 2 Thermal calibration value (thermal offset)*/
    NCA3, /*NTC 3 Thermal calibration value (thermal offset)*/
    //OCULT PARAMETER
    NSV, /*Byte to check if it has an saved parameter*/
    NTZ, /*Saved timezone*/
    NAWS, /*Byte to check if AWS registry is ready*/
    NWIFI,
    TOTAL_PARAM
};

enum PARAM_MODE{
    OFF_MODE,
    ON_MODE,
    AUTO_MODE,
    CAL_MODE,
    PROT_P0_MODE,
    PROT_P1_MODE,
    PROT_P2_MODE,
    PROT_P3_MODE,
    PROT_P6_MODE,
    PROT_P7_MODE,
    PROT_P8_MODE,
    ERR_E1E2_MODE,
    ERR_E3_MODE,
};

typedef struct{
        //params

} SOLAR_PARAMS;


typedef struct {
    const char* name;
    int16_t defval;
    int16_t minval;
    int16_t maxval;
	int16_t (*get)();
	void (*set)(int16_t value);
} Parameter;

extern const Parameter parameters_list[NUM_PARAMETERS+NUM_OCULT_PARAMS];

class Parameters
{

    public:
    Parameters();
    static void saveParameters();
    static void saveParameter(uint8_t param_index);
    static void loadParameters();
    void resetParameters();
    void setDefaults();
    Parameter getParam(uint8_t index);
    void setParam(SOLAR_PARAMS p);

    /********** GET / SET *********/

    static int16_t getPMode(void);
    static void setPMode(int16_t value);
    static int16_t getAMode(void);
    static void setAMode(int16_t value);
    static int16_t getSETP(void);
    static void setSETP(int16_t value);
    static int16_t getr0(void);
    static void setr0(int16_t value);
    static int16_t getr1(void);
    static void setr1(int16_t value);
    static int16_t getP0(void);
    static void setP0(int16_t value);
    static int16_t getP1(void);
    static void setP1(int16_t value);
    static int16_t getP2(void);
    static void setP2(int16_t value);
    static int16_t getP3(void);
    static void setP3(int16_t value);   
    static int16_t getP5(void);
    static void setP5(int16_t value); 
    static int16_t getP6(void);
    static void setP6(int16_t value); 
    static int16_t getP7(void);
    static void setP7(int16_t value); 
    static int16_t getP8(void);
    static void setP8(int16_t value); 
    static int16_t getAP0(void);
    static void setAP0(int16_t value);
    static int16_t getAP1(void);
    static void setAP1(int16_t value);        
    static int16_t getRc0(void);
    static void setRc0(int16_t value); 
    static int16_t getFE1(void);
    static void setFE1(int16_t value); 
    static int16_t getFE2(void);
    static void setFE2(int16_t value); 
    static int16_t getFE3(void);
    static void setFE3(int16_t value); 
    static int16_t getFE4(void);
    static void setFE4(int16_t value); 
    static int16_t getFC1(void);
    static void setFC1(int16_t value); 
    static int16_t getFC2(void);
    static void setFC2(int16_t value); 
    static int16_t getFC3(void);
    static void setFC3(int16_t value); 
    static int16_t getFC4(void);
    static void setFC4(int16_t value); 
    static int16_t getHN1(void);
    static void setHN1(int16_t value); 
    static int16_t getHN2(void);
    static void setHN2(int16_t value); 
    static int16_t getHN3(void);
    static void setHN3(int16_t value); 
    static int16_t getHN4(void);
    static void setHN4(int16_t value); 
    static int16_t getHF1(void);
    static void setHF1(int16_t value); 
    static int16_t getHF2(void);
    static void setHF2(int16_t value); 
    static int16_t getHF3(void);
    static void setHF3(int16_t value); 
    static int16_t getHF4(void);
    static void setHF4(int16_t value);     
    static int16_t getCA1(void);
    static void setCA1(int16_t value);  
    static int16_t getCA2(void);
    static void setCA2(int16_t value);  
    static int16_t getCA3(void);
    static void setCA3(int16_t value);  
    static int16_t getSV(void);
    static void setSV(int16_t value); 
    static int16_t getAWS(void);
    static void setAWS(int16_t value);     
    static int16_t getWIFI(void);
    static void setWIFI(int16_t value);                  
    static int16_t getTZ(void);
    static void setTZ(int16_t value);  

    void setProtPMode(int16_t value);
    void setProtAMode(int16_t value);


    void setAndSaveParam();

};

#endif //_PARAMETERS_H_