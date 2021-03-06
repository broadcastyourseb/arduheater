/**
 * Arduheater - An intelligent dew buster for astronomy
 * Copyright (C) 2016-2018 João Brázio [joao@brazio.org]
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef __ASSERT_H__
#define __ASSERT_H__

#include <stdint.h>
#include <stdlib.h>

#include "version.h"
#include "config.h"

#include <avr/pgmspace.h>
#include "type.h"

#if ! defined (__AVR_ATmega328P__) && ! defined (__AVR_ATmega168__) && ! defined (__AVR_ATmega168P__)
  #error Supported platforms: Arduino UNO, NANO, PRO (AVR ATmega 328P)
#endif

#ifndef AMBIENT_SENSOR_TYPE
  #error Please select the type of ambient sensor used
#else
  #if AMBIENT_SENSOR_TYPE == DHT22
    #if AMBIENT_SENSOR_PIN != 2 && AMBIENT_SENSOR_PIN != 3
      #error The ambient sensor DHT22 must be connected to an interupt pin (D2 or D3)
    #endif
  #endif
#endif



#if !defined(CHANNEL1_OUTPUT) || !defined(CHANNEL2_OUTPUT) || !defined(CHANNEL3_OUTPUT) || !defined(CHANNEL4_OUTPUT)
  #error Missing the output pin configuration for one of the channels
#else
  #if CHANNEL1_OUTPUT != 5 && CHANNEL1_OUTPUT != 6 && CHANNEL1_OUTPUT != 11 && CHANNEL1_OUTPUT != 3
    #error The output pin for channel one must be PWM capable
  #endif

  #if CHANNEL2_OUTPUT != 5 && CHANNEL2_OUTPUT != 6 && CHANNEL2_OUTPUT != 11 && CHANNEL2_OUTPUT != 3
    #error The output pin for channel two must be PWM capable
  #endif

  #if CHANNEL3_OUTPUT != 5 && CHANNEL3_OUTPUT != 6 && CHANNEL3_OUTPUT != 11 && CHANNEL3_OUTPUT != 3
    #error The output pin for channel three must be PWM capable
  #endif

  #if CHANNEL4_OUTPUT != 5 && CHANNEL4_OUTPUT != 6 && CHANNEL4_OUTPUT != 11 && CHANNEL4_OUTPUT != 3
    #error The output pin for channel four must be PWM capable
  #endif

  const pin_t heater_pins[] PROGMEM = {
    CHANNEL1_OUTPUT,
    CHANNEL2_OUTPUT,
    CHANNEL3_OUTPUT,
    CHANNEL4_OUTPUT
  };
#endif

#if !defined(CHANNEL1_SENSOR) || !defined(CHANNEL2_SENSOR) || !defined(CHANNEL3_SENSOR) || !defined(CHANNEL4_SENSOR)
  #error Missing the output pin configuration for one of the channels
#else
  const pin_t sensor_pins[] PROGMEM = {
    CHANNEL1_SENSOR,
    CHANNEL2_SENSOR,
    CHANNEL3_SENSOR,
    CHANNEL4_SENSOR
  };
#endif

#endif
