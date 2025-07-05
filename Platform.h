/*=============================================================================|
|  PROJECT SETTIMINO                                                     2.1.0 |
|==============================================================================|
|  Copyright (C) 2013, 2025 Davide Nardella                                    |
|  All rights reserved.                                                        |
|==============================================================================|
|  SETTIMINO is free software: you can redistribute it and/or modify           |
|  it under the terms of the Lesser GNU General Public License as published by |
|  the Free Software Foundation, either version 3 of the License, or           |
|  (at your option) any later version.                                         |
|                                                                              |
|  It means that you can distribute your commercial software linked with       |
|  SETTIMINO without the requirement to distribute the source code of your     |
|  application and without the requirement that your application be itself     |
|  distributed under LGPL.                                                     |
|                                                                              |
|  SETTIMINO is distributed in the hope that it will be useful,                |
|  but WITHOUT ANY WARRANTY; without even the implied warranty of              |
|  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the               |
|  Lesser GNU General Public License for more details.                         |
|                                                                              |
|  You should have received a copy of the GNU General Public License and a     |
|  copy of Lesser GNU General Public License along with Snap7.                 |
|  If not, see  http://www.gnu.org/licenses/                                   |
|------------------------------------------------------------------------------|
|                                                                              |
|  1.1.0 Added support for ESP8266 (Thanks to Geoffrey Hayward Piggot)         |
|  2.0.0 Added new hardware support                                            |
|        Added Read/Write consistent bit into the CPU                          |
|        Added new 18 helper functions                                         |
|        Small bugfixes (Thanks to Daniel Förstmann and Schöneberg Swen)       |
|  2.1.0 Added new hardware support                                            |
|        Arduino GIGA R1 WIFI with Ethernet Shield 2                           |
|        Arduino Portenta with Portenta Hat Carrier                            |
|        Waveshare ESP32-S3-ETH                                                |
|=============================================================================*/
#ifndef PLATFORM_H
#define PLATFORM_H

//*********************************************************************
//  PLATFORM AND MEDIA DEFINITION
//
//  Chose your platform and uncomment the related define
//  *ONLY* one line must be uncommented
//*********************************************************************
//  ARDUINO_LAN
//      Arduino UNO R3 + Ethernet Shield R3 or Ethernet Shield 2
//      Arduino MEGA 2560 R3 + Ethernet Shield R3 or Ethernet Shield 2
//  ESP8266_FAMILY (WiFi)
//      NodeMCU
//      Wemos
//      Lolin V3
//      (Other 7 modules based onto ESP8266 chip)
//  ESP32_WIFI
//      ESP32-WROOM-32 / 32D
//      ESP32 DevModule
//  M5STACK_WIFI (only core)
//      Basic, Gray, Red
//  M5STACK_LAN
//      Core + LAN MODULE (W5500)
//  ARDUINO_PORTENTA
//      Portenta + Hat Carrier
//  ARDUINO_GIGA
//      Arduino GIGA R1 WIFI + Ethernet Shield 2
//  ESP32_S3_ETH
//      Waveshare ESP32-S3-ETH board
//      https://www.waveshare.com/wiki/ESP32-S3-ETH
//*********************************************************************
//  Notes of external libraries needed.
//  If you already use that boards, you should have already installed
//*********************************************************************
//  ESP8266_FAMILY
//  	https://github.com/esp8266/Arduino
//  ESP32
//  	https://github.com/espressif/arduino-esp32
//  M5STACK (*)
//      https://docs.m5stack.com/#/en/quick_start/m5core/m5stack_core_get_started_Arduino_Windows
//  	https://github.com/m5stack/M5Stack
// 
//  (*) Need also to install Ethernet2 library to use the LAN MODULE.
//      Use the Arduino IDE Library Manager. 
//
//*********************************************************************

#define ARDUINO_LAN    
//#define ESP8266_FAMILY  
//#define ESP32_WIFI
//#define M5STACK_WIFI
//#define M5STACK_LAN
//#define PORTENTA
//#define GIGA_R1_LAN
//#define ESP32_S3_ETH

#include <SPI.h>

// Platforms 

#ifdef ARDUINO_LAN
  #include <Ethernet.h>
  #define S7WIRED
#endif

#ifdef ESP8266_FAMILY
  #include <ESP8266WiFi.h> 
  #include <Ethernet.h>
  #define S7WIFI
#endif

#ifdef ESP32_WIFI
  #include <Ethernet.h>
  #include <WiFi.h>
  #define S7WIFI
#endif

#ifdef M5STACK_WIFI
  #include <M5Stack.h>
  #include <Ethernet.h>
  #include <WiFi.h>
  #define S7WIFI
#endif

#ifdef M5STACK_LAN
  #include <M5Stack.h>
  #include <Ethernet2.h>
  #define S7WIRED
#endif

#ifdef PORTENTA
  #include <Ethernet.h>
  #define S7WIRED
#endif

#ifdef GIGA_R1_LAN
  #include <Ethernet.h>
  #define S7WIRED
#endif

#ifdef ESP32_S3_ETH
  #include <ETH.h>

  #ifndef ETH_PHY_CS
  #define ETH_PHY_TYPE ETH_PHY_W5500
  #define ETH_PHY_ADDR 1
  #define ETH_PHY_CS   14
  #define ETH_PHY_IRQ  10
  #define ETH_PHY_RST  9
  #endif
  #define ETH_SPI_SCK  13
  #define ETH_SPI_MISO 12
  #define ETH_SPI_MOSI 11

  #define S7WIRED
#endif

#ifdef S7WIRED
  #ifndef ESP32_S3_ETH    
    #include "EthernetClient.h"  
  #endif
#else
  #include "WiFiClient.h"
#endif

#endif //PLATFORM_H
