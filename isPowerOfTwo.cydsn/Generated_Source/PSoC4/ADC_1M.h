/*******************************************************************************
* File Name: ADC_1M.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_ADC_1M_H) /* Pins ADC_1M_H */
#define CY_PINS_ADC_1M_H

#include "cytypes.h"
#include "cyfitter.h"
#include "ADC_1M_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    ADC_1M_Write(uint8 value) ;
void    ADC_1M_SetDriveMode(uint8 mode) ;
uint8   ADC_1M_ReadDataReg(void) ;
uint8   ADC_1M_Read(void) ;
uint8   ADC_1M_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ADC_1M_DRIVE_MODE_BITS        (3)
#define ADC_1M_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - ADC_1M_DRIVE_MODE_BITS))

#define ADC_1M_DM_ALG_HIZ         (0x00u)
#define ADC_1M_DM_DIG_HIZ         (0x01u)
#define ADC_1M_DM_RES_UP          (0x02u)
#define ADC_1M_DM_RES_DWN         (0x03u)
#define ADC_1M_DM_OD_LO           (0x04u)
#define ADC_1M_DM_OD_HI           (0x05u)
#define ADC_1M_DM_STRONG          (0x06u)
#define ADC_1M_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define ADC_1M_MASK               ADC_1M__MASK
#define ADC_1M_SHIFT              ADC_1M__SHIFT
#define ADC_1M_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ADC_1M_PS                     (* (reg32 *) ADC_1M__PS)
/* Port Configuration */
#define ADC_1M_PC                     (* (reg32 *) ADC_1M__PC)
/* Data Register */
#define ADC_1M_DR                     (* (reg32 *) ADC_1M__DR)
/* Input Buffer Disable Override */
#define ADC_1M_INP_DIS                (* (reg32 *) ADC_1M__PC2)


#if defined(ADC_1M__INTSTAT)  /* Interrupt Registers */

    #define ADC_1M_INTSTAT                (* (reg32 *) ADC_1M__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define ADC_1M_DRIVE_MODE_SHIFT       (0x00u)
#define ADC_1M_DRIVE_MODE_MASK        (0x07u << ADC_1M_DRIVE_MODE_SHIFT)


#endif /* End Pins ADC_1M_H */


/* [] END OF FILE */
