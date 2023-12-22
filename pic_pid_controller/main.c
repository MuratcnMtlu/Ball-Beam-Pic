#include <main.h>

float mesafe_array[10];

void blink_led()
{
   output_toggle(LED);
}

void read_hcsr04()
{
   setup_timer_1(t1_internal | t1_div_by_1);
    for(int i =  0; i < 10; i++)
    {
           output_high(trig1);
       delay_ms(10);
       output_low(trig1);
      
       while(!input(echo1))
       { }
       
       set_timer1(0);
       
       while(input(echo1))
       { }
       
       zaman = get_timer1();
       
       mesafe = zaman * 0.0037;
       mesafe_array[i] = mesafe;
       
      
    }
     
   printf("mesafe = %f\r\n", mesafe);
}


void main()
{

   output_b(0xFF);
   set_tris_b(0xFF);
   set_tris_d(0x00);
   output_d(0x00);
   
   lcd_init();
    lcd_gotoxy(1,1); printf(lcd_putc,"Selcuk Fuckin");
    lcd_gotoxy(1,2); printf(lcd_putc,"KIZIR");
    
  
   while(TRUE)
   {
      blink_led();
      read_hcsr04();
        
      delay_ms(200);
    
   }

}
