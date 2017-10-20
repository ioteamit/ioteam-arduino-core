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


void initDust()
{
    pinMode(DUST_RESET_PIN, OUTPUT); 
    
    pinMode(DUST_TIM_EN_PIN, OUTPUT); 
    digitalWrite(DUST_TIM_EN_PIN, HIGH);
	
    resetComponent(DUST_RESET_PIN);
}


void initVariant() {
    
    initDust();
    
}
