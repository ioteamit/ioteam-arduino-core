/*
Copyright (c) 2014-2015 Arduino LLC.  All right reserved.
Copyright (c) 2015 Amel-Tech (a division of Amel Srl). All right reserved.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include <Arduino.h>

static const uint32_t TWI_CLOCK_SME = 100000;



void resetComponent(int pin) {
    digitalWrite(pin, LOW);
    delay(10); // wait 10 mSec.
    digitalWrite(pin, HIGH);
}

void initSigfox()
{
    pinMode(SIGFOX_SS_PIN, OUTPUT); 
    digitalWrite(SIGFOX_SS_PIN, HIGH);
    
    pinMode(SIGFOX_PWRON_PIN, OUTPUT); 
    digitalWrite(SIGFOX_PWRON_PIN, HIGH);

    pinMode(SIGFOX_RES_PIN, OUTPUT); 
    digitalWrite(SIGFOX_RES_PIN, HIGH);
  
    pinMode(SIGFOX_EVENT_PIN, INPUT);
    delay(10); // wait 10 mSec.
    resetComponent(SIGFOX_RES_PIN);
}

void initDust()
{
    pinMode(DUST_RESET_PIN, OUTPUT); 
    digitalWrite(DUST_RESET_PIN, HIGH);
    
    pinMode(DUST_TIM_EN_PIN, OUTPUT); 
    digitalWrite(DUST_TIM_EN_PIN, HIGH);
    delay(10); // wait 10 mSec.
    resetComponent(DUST_RESET_PIN);
}

void initWiFi()
{
    pinMode(WIFI_RES_PIN, OUTPUT); 
    digitalWrite(WIFI_RES_PIN, HIGH);
    
    pinMode(WIFI_SS_PIN, OUTPUT); 
    digitalWrite(WIFI_SS_PIN, HIGH);

    pinMode(WIFI_IRQN_PIN, INPUT);
    
    pinMode(WIFI_WAKE_PIN, OUTPUT); 
    digitalWrite(WIFI_WAKE_PIN, HIGH);

        
    pinMode(WIFI_CHIP_EN_PIN, OUTPUT); 
    digitalWrite(WIFI_CHIP_EN_PIN, HIGH);
    
    delay(10); // wait 10 mSec.
    resetComponent(WIFI_RES_PIN);
}


void initVariant() {
    
    // initialization the two Yellow Led
    LED_YELLOW_ONE_INIT;
    LED_YELLOW_TWO_INIT;

    // Light Led OFF
    ledYellowOneLight(LOW);
    ledYellowTwoLight(LOW);

    initSigfox();
    initDust();
    initWiFi();
    
    // initialize The EXT_PWR Pin as input
    // it will be HIGH when the battery is not connected
    pinMode(PIN_EXT_PWR, INPUT_PULLUP); 
    
    // initialize the battery monitor
    pinMode(PIN_BATT_MON, INPUT);
    pinMode(PIN_LIPO_MON, INPUT);
    pinMode(PIN_ENA_MON, OUTPUT);
    digitalWrite(PIN_ENA_MON, LOW);  // disable the battery monitor
    
    //initialize the reset pin   
    pinMode(PIN_RESET_COMPONENT, OUTPUT);
    digitalWrite(PIN_RESET_COMPONENT, HIGH);
    
    
    // reset the base component
    resetBaseComponent();
    
    // put GPS in stdby to save power
    setInitGPS();

    ioExtenderInit();
}
