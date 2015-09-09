#include <project.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 64
#define MAX_ITERATIONS 100

int countBits(int v){
    int i = 0;
  
    while(v){
        i = i + (v & 1);
        v = v >> 1;
    }
    
    return i;
}


int main()
{
    // allocate buffer size for input
    char buf[MAX_BUFFER_SIZE];
    CyGlobalIntEnable;      /* Enable global interrupts */
    
    // start UART
    UART_1_Start();
    
    // print line
    strcpy(buf, "Established Communication \n \r");
    UART_1_UartPutString(buf);
    
    int v = 0x8; // hex representation of the integer
    int count = countBits(v);
    
    // print result
    // integer to string to be printed
    sprintf(buf, "%d", count);
    strcat(buf, "\n \r");
    UART_1_UartPutString(buf);
    
    for(;;){}
}

