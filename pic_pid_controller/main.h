#include <16F887.h>
#device ADC=10
#use delay(crystal=16000000)
#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8,stream=PORT1)


#define LCD_ENABLE_PIN  PIN_C2                                   
#define LCD_RS_PIN      PIN_C3                                  
#define LCD_RW_PIN      PIN_C1                                   
#define LCD_DATA4       PIN_D0                                
#define LCD_DATA5       PIN_D1                                  
#define LCD_DATA6       PIN_D2                                   
#define LCD_DATA7       PIN_D3
#include <LCD.c>


#define LED PIN_E1
#define BUZZER PIN_B1
#define trig1 PIN_B4
#define echo1 PIN_B5

#define DELAY 500

float mesafe, zaman;

