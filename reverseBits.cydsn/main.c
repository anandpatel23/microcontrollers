#include <project.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 64
#define MAX_ITERATIONS 100

uint reverseBits(uint v){
        // input bits to be reversed
    unsigned int r = v; // r will be reversed bits of v; first get LSB of v
    int s = sizeof(v) * 8-1; // extra shift needed at end

    for (v >>= 1; v; v >>= 1){   
        r <<= 1;
        r |= v & 1;
        s--;
    }
    
    r <<= s; // shift when v's highest bits are zero

    return r;
}

int main(){

    // allocate buffer size for input
    char buf[MAX_BUFFER_SIZE];
    CyGlobalIntEnable;      /* Enable global interrupts */
    
    // start UART
    UART_1_Start();
    
    // print line
    strcpy(buf, "Established Communication \n \r");
    UART_1_UartPutString(buf);
    
    uint v4 = 0x56; // hex representation of the integer
    uint vv4 = reverseBits(v4);
    
    // print result
    // integer to string to be printed
    sprintf(buf, "%X", vv4);
    strcat(buf, "\n \r");
    UART_1_UartPutString(buf);
    
    
    for(;;){}
}