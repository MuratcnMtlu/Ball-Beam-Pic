#include <16F887.h>
#device adc = 10
#use delay(clock = 16000000)
#fuses HS, NOWDT, NOLVP
#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8,stream=PORT1) 
 
 #define BIR_BAS PIN_E1 
#define ON_BAS PIN_E0
 
 float ang_bilgi = 0; 
 int sayi = 0;
 int8 sayac = -1;
  
 int8 led_tablo[8] = { 
   0x01, 0x02, 0x04, 0x08, 
   0x10, 0x20, 0x40, 0x80 }; 
   
  int8 seg_tablo[16] = { 
   0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07, 
   0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};
   
 
 void led_sirala()
   {
      output_b(led_tablo[sayac]);
      sayac++;
      if(sayac == 7)
     sayac = 0;
   }
   
   
   void multiplex(int sayi)
   {
      int i;
      int birler = 0;
      int onlar = 0;
       birler = sayi % 10; 
      onlar = (sayi / 10) % 10;
      
      for(i=0; i<40; i++) 
      {
    output_d(seg_tablo[onlar]); 
    output_high(ON_BAS); 
    delay_ms(10);
    output_low(ON_BAS); 
 
    output_d(seg_tablo[birler]); 
    output_high(BIR_BAS); 
    delay_ms(10);
    output_low(BIR_BAS);
      } 
   }


void main(void)
{
  setup_adc_ports(sAN0, VSS_VDD);
   setup_adc(ADC_CLOCK_INTERNAL);
   
   set_tris_b(0x00);
   set_tris_d(0x00);
   
   output_b(0x00); 
   output_d(0x00);
    
   while(1)
   {
      set_adc_channel(0); 
      delay_us(10);
      ang_bilgi = (float)read_adc();
      
      ang_bilgi /= 50.22;
      printf(" adc : %f\r\n", ang_bilgi);
      
     // multiplex(ang_bilgi / 10);
      //led_sirala();
      delay_ms(200);
      
   }
   
   }
