/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F18875
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set DC aliases
#define DC_TRIS                 TRISAbits.TRISA0
#define DC_LAT                  LATAbits.LATA0
#define DC_PORT                 PORTAbits.RA0
#define DC_WPU                  WPUAbits.WPUA0
#define DC_OD                   ODCONAbits.ODCA0
#define DC_ANS                  ANSELAbits.ANSA0
#define DC_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define DC_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define DC_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define DC_GetValue()           PORTAbits.RA0
#define DC_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define DC_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define DC_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define DC_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define DC_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define DC_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define DC_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define DC_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set boton1p aliases
#define boton1p_TRIS                 TRISAbits.TRISA1
#define boton1p_LAT                  LATAbits.LATA1
#define boton1p_PORT                 PORTAbits.RA1
#define boton1p_WPU                  WPUAbits.WPUA1
#define boton1p_OD                   ODCONAbits.ODCA1
#define boton1p_ANS                  ANSELAbits.ANSA1
#define boton1p_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define boton1p_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define boton1p_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define boton1p_GetValue()           PORTAbits.RA1
#define boton1p_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define boton1p_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define boton1p_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define boton1p_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define boton1p_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define boton1p_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define boton1p_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define boton1p_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set boton2p aliases
#define boton2p_TRIS                 TRISAbits.TRISA2
#define boton2p_LAT                  LATAbits.LATA2
#define boton2p_PORT                 PORTAbits.RA2
#define boton2p_WPU                  WPUAbits.WPUA2
#define boton2p_OD                   ODCONAbits.ODCA2
#define boton2p_ANS                  ANSELAbits.ANSA2
#define boton2p_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define boton2p_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define boton2p_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define boton2p_GetValue()           PORTAbits.RA2
#define boton2p_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define boton2p_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define boton2p_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define boton2p_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define boton2p_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define boton2p_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define boton2p_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define boton2p_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set boton1 aliases
#define boton1_TRIS                 TRISBbits.TRISB4
#define boton1_LAT                  LATBbits.LATB4
#define boton1_PORT                 PORTBbits.RB4
#define boton1_WPU                  WPUBbits.WPUB4
#define boton1_OD                   ODCONBbits.ODCB4
#define boton1_ANS                  ANSELBbits.ANSB4
#define boton1_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define boton1_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define boton1_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define boton1_GetValue()           PORTBbits.RB4
#define boton1_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define boton1_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define boton1_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define boton1_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define boton1_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define boton1_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define boton1_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define boton1_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set CS aliases
#define CS_TRIS                 TRISCbits.TRISC0
#define CS_LAT                  LATCbits.LATC0
#define CS_PORT                 PORTCbits.RC0
#define CS_WPU                  WPUCbits.WPUC0
#define CS_OD                   ODCONCbits.ODCC0
#define CS_ANS                  ANSELCbits.ANSC0
#define CS_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define CS_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define CS_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define CS_GetValue()           PORTCbits.RC0
#define CS_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define CS_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define CS_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define CS_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define CS_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define CS_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define CS_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define CS_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set RST aliases
#define RST_TRIS                 TRISCbits.TRISC1
#define RST_LAT                  LATCbits.LATC1
#define RST_PORT                 PORTCbits.RC1
#define RST_WPU                  WPUCbits.WPUC1
#define RST_OD                   ODCONCbits.ODCC1
#define RST_ANS                  ANSELCbits.ANSC1
#define RST_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RST_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RST_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RST_GetValue()           PORTCbits.RC1
#define RST_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RST_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define RST_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define RST_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define RST_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define RST_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define RST_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define RST_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()             do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()           do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode()         do { ANSELCbits.ANSC3 = 1; } while(0)
#define RC3_SetDigitalMode()        do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()             do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()           do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set boton2 aliases
#define boton2_TRIS                 TRISCbits.TRISC5
#define boton2_LAT                  LATCbits.LATC5
#define boton2_PORT                 PORTCbits.RC5
#define boton2_WPU                  WPUCbits.WPUC5
#define boton2_OD                   ODCONCbits.ODCC5
#define boton2_ANS                  ANSELCbits.ANSC5
#define boton2_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define boton2_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define boton2_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define boton2_GetValue()           PORTCbits.RC5
#define boton2_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define boton2_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define boton2_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define boton2_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define boton2_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define boton2_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define boton2_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define boton2_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSC6 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCAF1 pin functionality
 * @Example
    IOCAF1_ISR();
 */
void IOCAF1_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAF1 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAF1 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF1_SetInterruptHandler(MyInterruptHandler);

*/
void IOCAF1_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCAF1 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAF1_SetInterruptHandler() method.
    This handler is called every time the IOCAF1 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF1_SetInterruptHandler(IOCAF1_InterruptHandler);

*/
extern void (*IOCAF1_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAF1 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAF1_SetInterruptHandler() method.
    This handler is called every time the IOCAF1 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF1_SetInterruptHandler(IOCAF1_DefaultInterruptHandler);

*/
void IOCAF1_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCAF2 pin functionality
 * @Example
    IOCAF2_ISR();
 */
void IOCAF2_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAF2 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAF2 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF2_SetInterruptHandler(MyInterruptHandler);

*/
void IOCAF2_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCAF2 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAF2_SetInterruptHandler() method.
    This handler is called every time the IOCAF2 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF2_SetInterruptHandler(IOCAF2_InterruptHandler);

*/
extern void (*IOCAF2_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAF2 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAF2_SetInterruptHandler() method.
    This handler is called every time the IOCAF2 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF2_SetInterruptHandler(IOCAF2_DefaultInterruptHandler);

*/
void IOCAF2_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCBF4 pin functionality
 * @Example
    IOCBF4_ISR();
 */
void IOCBF4_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF4 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF4 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF4_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF4_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF4 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF4_SetInterruptHandler() method.
    This handler is called every time the IOCBF4 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF4_SetInterruptHandler(IOCBF4_InterruptHandler);

*/
extern void (*IOCBF4_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF4 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF4_SetInterruptHandler() method.
    This handler is called every time the IOCBF4 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF4_SetInterruptHandler(IOCBF4_DefaultInterruptHandler);

*/
void IOCBF4_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF5 pin functionality
 * @Example
    IOCCF5_ISR();
 */
void IOCCF5_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF5 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF5 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF5_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF5_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF5 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF5_SetInterruptHandler() method.
    This handler is called every time the IOCCF5 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF5_SetInterruptHandler(IOCCF5_InterruptHandler);

*/
extern void (*IOCCF5_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF5 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF5_SetInterruptHandler() method.
    This handler is called every time the IOCCF5 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF5_SetInterruptHandler(IOCCF5_DefaultInterruptHandler);

*/
void IOCCF5_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/