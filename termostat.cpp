#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/wdt.h> 
#include <avr/sleep.h>
#include <avr/eeprom.h>
#include <string.h>
#include <stdio.h>
#include "Mirf.h"
#include "Mirf_nRF24L01.h"

//DEVICE definition
#define DEV_ADDR 4 //1 is master, so it is not possible

#define TIMER_3_SEC_PERIOD 300
#define TIMER_60_SEC_PERIOD 6000

#include "onewire.h"
#include "ds18x20.h"