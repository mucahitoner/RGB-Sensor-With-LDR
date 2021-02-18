/*char txt[14],giris;*/
float adc_val;
init(){
ADCON0=0b00000001;
TRISD=0Xf0;
PORTD=0;
}
void main() {
     UART1_Init(9600);
     Delay_ms(100);
     UART1_Write_Text("renk algilama");
     UART1_Write(10);
     UART1_Write(13);
     init();
     while(1)
     {
     r:
             if(PORTD==1)
                      {
 adc_val=ADC_Read(0);
                      if(920<=adc_val && adc_val<=940)
                      {
                          UART1_Write_Text("-red-");
                          goto r;
                      }
                      /*IntToStr(adc_val,txt);
                      UART1_Write_Text("KIRMIZI");
                      UART1_Write_Text(txt);*/
                      PORTD=2;
                      delay_ms(1000);
                      }
             else if(PORTD==2)
                      {
 adc_val=ADC_Read(0);
                      if(1008<=adc_val && adc_val<=1012)
                      {
                          UART1_Write_Text("-green-");
                          goto r;
                      }
 /*IntToStr(adc_val,txt);
                      UART1_Write_Text("ye?il");
                      UART1_Write_Text(txt); */
                      PORTD=4;
                      delay_ms(1000);
                      }
             else if(PORTD==4)
                      {
                      adc_val=ADC_Read(0);
                      if(950<=adc_val && adc_val<=970)
                      {
                          UART1_Write_Text("-blue-");
                          goto r;
                      }
                      /*IntToStr(adc_val,txt);
                      UART1_Write_Text("mavi");
                      UART1_Write_Text(txt);   */
                      PORTD=1;
                      delay_ms(1000);
                      }
              else{
                   PORTD=1;
              }
}
}
