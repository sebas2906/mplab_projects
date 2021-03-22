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



#endif // PIN_MANAGER_H
/**
 End of File
*/