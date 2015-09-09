#include <project.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 64
#define MAX_ITERATIONS 100

uint interleaveBits(uint x, uint y){
    int z = 0; // z gets the resulting 32-bit Morton Number.
    int i = 0;
    for (i = 0; i < sizeof(x) * 8; i++){
        z |= (x & 1 << i) << i | (y & 1 << i) << (i + 1);
    }
    
    return z;
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
    
    uint x = 0x55;
    uint y = 0xaa;
    uint z = interleaveBits(x, y);
    
    // print result
    // integer to string to be printed
    sprintf(buf, "%X", z);
    strcat(buf, "\n \r");
    UART_1_UartPutString(buf);
    
    
    for(;;){}
}