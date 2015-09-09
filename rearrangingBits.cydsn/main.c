#include <project.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_BUFFER_SIZE 64

int rearrangeBits(int8 v){
    int count = 0;
    int i;
    
    // count # of 1s, shift to the right to iterate
    while (v){
        if ((v & 1) == 1){
          count++;  
        }
        v = v>>1;
    }
    
    uint8 num = v << 8;
    
    for(i = count; i >= 0; i--){
        uint mask = i;
        num = ((1 << (8-mask)) | num);  
    }
        
    return num;                
}
int main(){
    char buffer[MAX_BUFFER_SIZE];
    CyGlobalIntEnable;      /* Enable global interrupts */
    
    UART_1_Start();
    
    strcpy(buffer, "Established Communication \n \r");   // Copy String Contents into buffer
    UART_1_UartPutString(buffer);
    
    int v = 0x56;
    int flag = rearrangeBits(v);
    sprintf(buffer, "%04x", flag); /* Write the count value as a string. */
    UART_1_UartPutString(buffer); /* Concatenate the new line and carriage return characters.*/
    
    for(;;){}
}