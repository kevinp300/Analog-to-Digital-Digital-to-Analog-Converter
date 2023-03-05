#include <xc.h>

#pragma config FOSC=INTOSC
#pragma config WDTE=OFF
#pragma config MCLRE=ON
#pragma config CP=OFF

main(){
    ANSELA=0b11111111;//Analog
    TRISA= 0b00000001;//  I/O
    ANSELC=0b11111111;//Analog
    TRISC= 0b00000000;//C ouput
    ANSELD=0b11111111;//Analog
    TRISD= 0b00000000;//D output
    
    ADCON0=0b00000001;
    ADCON1=0b10000000;
    PORTA=0;
    while(1){
        ADCON0=0b00000011;
        while((ADCON0 & 0b00000010)==1){}
            PORTC=ADRESH;
            PORTD=ADRESL;                    
    }
}
