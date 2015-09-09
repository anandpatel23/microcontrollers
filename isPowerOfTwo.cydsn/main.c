#include <project.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_BUFFER_SIZE 64

int isPowerOfTwo(uint v){
    // computes each power of two incrementally, 
    // quitting when x is less than or equal to the current power of two.
   
    unsigned int powerOfTwo = 1;
    
    while(powerOfTwo < v)
        powerOfTwo = powerOfTwo * 2;
    
    return (v == powerOfTwo);
}

int main()
{
    // allocate buffer size for input
    char buf[MAX_BUFFER_SIZE];
    CyGlobalIntEnable;
    UART_1_Start();
    
    // print line
    strcpy(buf, "Established Communication \n \r");
    UART_1_UartPutString(buf);
    
    uint v3 = 0xB;
    int flag = isPowerOfTwo(v3);
    
    // print result
    // integer to string to be printed
    sprintf(buf, "%d", flag);
    strcat(buf, "\n \r");
    UART_1_UartPutString(buf);
    
    for(;;){}
}

