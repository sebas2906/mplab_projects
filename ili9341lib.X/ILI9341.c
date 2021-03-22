///////////////////////////////////////////////////////////////////////////
////                                                                   ////
////                              ILI9341.c                            ////
////                                                                   ////
////               ILI9341 display driver for CCS C compiler           ////
////                                                                   ////
///////////////////////////////////////////////////////////////////////////
////                                                                   ////
////               This is a free software with NO WARRANTY.           ////
////                     https://simple-circuit.com/                   ////
////                                                                   ////
///////////////////////////////////////////////////////////////////////////
/*
* This library works with the Adafruit 2.8" Touch Shield V2 (SPI)
*    http://www.adafruit.com/products/1651
* Adafruit 2.4" TFT LCD with Touchscreen Breakout w/MicroSD Socket - ILI9341
*    https://www.adafruit.com/product/2478
* 2.8" TFT LCD with Touchscreen Breakout Board w/MicroSD Socket - ILI9341
*    https://www.adafruit.com/product/1770
* 2.2" 18-bit color TFT LCD display with microSD card breakout - ILI9340
*    https://www.adafruit.com/product/1770
* TFT FeatherWing - 2.4" 320x240 Touchscreen For All Feathers
*    https://www.adafruit.com/product/3315
*
* These displays use SPI to communicate, 4 or 5 pins are required
* to interface (RST is optional).
*
* Adafruit invests time and resources providing this open source code,
* please support Adafruit and open-source hardware by purchasing
* products from Adafruit!
*
*
* This library depends on <a href="https://github.com/adafruit/Adafruit_GFX">
* Adafruit_GFX</a> being present on your system. Please make sure you have
* installed the latest version before using this library.
*
* Written by Limor "ladyada" Fried for Adafruit Industries.
*
* BSD license, all text here must be included in any redistribution.
*
*/

#include <stdint.h>
#include "ILI9341.h"
#define TFT_RST RST_LAT
/**************************************************************************/
/*!
    @brief  Call before issuing command(s) or data to display. Performs
            chip-select (if required). Required
            for all display types; not an SPI-specific function.
*/
/**************************************************************************/
void startWrite(void) {
    //output_low(TFT_CS);
    CS_SetLow(); 
}

/**************************************************************************/
/*!
    @brief  Call after issuing command(s) or data to display. Performs
            chip-deselect (if required). Required
            for all display types; not an SPI-specific function.
*/
/**************************************************************************/
void endWrite(void) {
    PORTAbits.RA0=1;
    CS_SetHigh(); 
}

/**************************************************************************/
/*!
    @brief  Write a single command byte to the display. Chip-select and
            transaction must have been previously set -- this ONLY sets
            the device to COMMAND mode, issues the byte and then restores
            DATA mode. There is no corresponding explicit writeData()
            function -- just use ILI9341_SPI_XFER().
    @param  cmd  8-bit command to write.
*/
/**************************************************************************/
void writeCommand(uint8_t cmd) {
  PORTAbits.RA0=0;//DC
  ILI9341_SPI_XFER(cmd);
  PORTAbits.RA0=1;//DC
}

/**************************************************************************/
/*!
    @brief   Initialize ILI9341 chip
    Connects to the ILI9341 over SPI and sends initialization procedure commands
    @param    freq  Desired SPI clock frequency
*/
/**************************************************************************/
void tft_begin(void) {

    #ifdef TFT_RST

      DC_SetHigh();
    //  RST_SetHigh();
     // RST_SetLow();
     // output_high(TFT_RST);
     // output_drive(TFT_RST);
      __delay_ms(100);
      DC_SetLow(); 
     // RST_SetLow();
      //output_low(TFT_RST);
      __delay_ms(100);
      DC_SetHigh(); 
     // RST_SetHigh();
    //  output_high(TFT_RST);
      __delay_ms(200);
    #else                           // If no hardware reset pin...
      writeCommand(ILI9341_SWRESET);  // Engage software reset
      __delay_ms(150);
    #endif
     CS_SetHigh();
   // output_high(TFT_CS);
     //******************Definido en MCC
    //output_drive(TFT_CS);
    //output_drive(TFT_DC);

    startWrite();

    uint8_t     cmd, x, numArgs;
    const uint8_t *addr = &initcmd;
    cmd = *addr++;
    while( cmd > 0 ) {
        writeCommand(cmd);
        x       = *addr++;
        numArgs = x & 0x7F;
        while(numArgs--) ILI9341_SPI_XFER(*addr++);
        
        if(x & 0x80) __delay_ms(150);
        cmd = *addr++;
    }

    endWrite();

    _width  = ILI9341_TFTWIDTH;
    _height = ILI9341_TFTHEIGHT;
    rotation = 0;
}

/**************************************************************************/
/*!
    @brief   Set the "address window" - the rectangle we will write to RAM with the next chunk of SPI data writes. The ILI9341 will automatically wrap the data as each row is filled
    @param   x1  TFT memory 'x' origin
    @param   y1  TFT memory 'y' origin
    @param   w   Width of rectangle
    @param   h   Height of rectangle
*/
/**************************************************************************/
void setAddrWindow(uint16_t x1, uint16_t y1, uint16_t w, uint16_t h) {
    uint16_t x2 = (x1 + w - 1),
             y2 = (y1 + h - 1);
    writeCommand(ILI9341_CASET); // Column address set
    ILI9341_SPI_XFER(x1 >> 8);
    ILI9341_SPI_XFER(x1);
    ILI9341_SPI_XFER(x2 >> 8);
    ILI9341_SPI_XFER(x2);
    writeCommand(ILI9341_PASET); // Row address set
    ILI9341_SPI_XFER(y1 >> 8);
    ILI9341_SPI_XFER(y1);
    ILI9341_SPI_XFER(y2 >> 8);
    ILI9341_SPI_XFER(y2);
    writeCommand(ILI9341_RAMWR); // Write to RAM
}

/**************************************************************************/
/*!
    @brief  Set origin of (0,0) and orientation of TFT display
    @param  m  The index for rotation, from 0-3 inclusive
*/
/**************************************************************************/
void setRotation(uint8_t m) {
  rotation = m % 4; // can't be higher than 3
    switch (rotation) {
        case 0:
            m = (MADCTL_MX | MADCTL_BGR);
            _width  = ILI9341_TFTWIDTH;
            _height = ILI9341_TFTHEIGHT;
            break;
        case 1:
            m = (MADCTL_MV | MADCTL_BGR);
            _width  = ILI9341_TFTHEIGHT;
            _height = ILI9341_TFTWIDTH;
            break;
        case 2:
            m = (MADCTL_MY | MADCTL_BGR);
            _width  = ILI9341_TFTWIDTH;
            _height = ILI9341_TFTHEIGHT;
            break;
        case 3:
            m = (MADCTL_MX | MADCTL_MY | MADCTL_MV | MADCTL_BGR);
            _width  = ILI9341_TFTHEIGHT;
            _height = ILI9341_TFTWIDTH;
            break;
    }

    startWrite();
    writeCommand(ILI9341_MADCTL);
    ILI9341_SPI_XFER(m);
    endWrite();
}

void drawPixel(uint16_t x, uint16_t y, uint16_t color) {
  if((x < _width) && (y < _height)) {
    startWrite();
    setAddrWindow(x, y, 1, 1);
    ILI9341_SPI_XFER(color >> 8);
    ILI9341_SPI_XFER(color & 0xFF);
    endWrite();
  }
}

/**************************************************************************/
/*!
   @brief    Draw a perfectly horizontal line (this is often optimized in a subclass!)
    @param    x   Left-most x coordinate
    @param    y   Left-most y coordinate
    @param    w   Width in pixels
   @param    color 16-bit 5-6-5 Color to fill with
*/
/**************************************************************************/
void drawHLine(uint16_t x, uint16_t y, uint16_t w, uint16_t color) {
  if( (x < _width) && (y < _height) && w) {   
    uint8_t hi = color >> 8, lo = color;

    if((x + w - 1) >= _width)  
      w = _width  - x;
    startWrite();
    setAddrWindow(x, y, w, 1);
    while (w--) {
      ILI9341_SPI_XFER(hi);
      ILI9341_SPI_XFER(lo);
    }
    endWrite();
  }
}

/**************************************************************************/
/*!
   @brief    Draw a perfectly vertical line (this is often optimized in a subclass!)
    @param    x   Top-most x coordinate
    @param    y   Top-most y coordinate
    @param    h   Height in pixels
   @param    color 16-bit 5-6-5 Color to fill with
*/
/**************************************************************************/
void drawVLine(uint16_t x, uint16_t y, uint16_t h, uint16_t color) {
  if( (x < _width) && (y < _height) && h) {  
    uint8_t hi = color >> 8, lo = color;
    if((y + h - 1) >= _height) 
      h = _height - y;
    startWrite();
    setAddrWindow(x, y, 1, h);
    while (h--) {
      ILI9341_SPI_XFER(hi);
      ILI9341_SPI_XFER(lo);
    }
    endWrite();
  }
}

/**************************************************************************/
/*!
   @brief    Fill a rectangle completely with one color. Update in subclasses if desired!
    @param    x   Top left corner x coordinate
    @param    y   Top left corner y coordinate
    @param    w   Width in pixels
    @param    h   Height in pixels
   @param    color 16-bit 5-6-5 Color to fill with
*/
/**************************************************************************/
void fillRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color) {
  if(w && h) {                            // Nonzero width and height?  
    uint8_t hi = color >> 8, lo = color;
    if((x >= _width) || (y >= _height))
      return;
    if((x + w - 1) >= _width)  
      w = _width  - x;
    if((y + h - 1) >= _height) 
      h = _height - y;
    startWrite();
    setAddrWindow(x, y, w, h);
    uint32_t px = (uint32_t)w * h;
    while (px--) {
      ILI9341_SPI_XFER(hi);
      ILI9341_SPI_XFER(lo);
    }
    endWrite();
  }
}

/**************************************************************************/
/*!
   @brief    Fill the screen completely with one color. Update in subclasses if desired!
    @param    color 16-bit 5-6-5 Color to fill with
*/
/**************************************************************************/
void fillScreen(uint16_t color) {
    fillRect(0, 0, _width, _height, color);
}

/**************************************************************************/
/*!
    @brief  Invert the colors of the display (if supported by hardware).
            Self-contained, no transaction setup required.
    @param  i  true = inverted display, false = normal display.
*/
/**************************************************************************/
//void invertDisplay(bool i) {
//    startWrite();
//    writeCommand(i ? ILI9341_INVON : ILI9341_INVOFF);
//    endWrite();
//}

/**************************************************************************/
/*!
    @brief   Scroll display memory
    @param   y How many pixels to scroll display by
*/
/**************************************************************************/
//void tft_scrollTo(uint16_t y) {
//    startWrite();
//    writeCommand(ILI9341_VSCRSADD);
//    ILI9341_SPI_XFER(y >> 8);
//    ILI9341_SPI_XFER(y);
//    endWrite();
//}

/**************************************************************************/
/*!
   @brief  Read 8 bits of data from ILI9341 configuration memory. NOT from RAM!
           This is highly undocumented/supported, it's really a hack but kinda works?
    @param    command  The command register to read data from
    @param    index  The byte index into the command to read from
    @return   Unsigned 8-bit data read from ILI9341 register
*/
/**************************************************************************/
//uint8_t tft_readcommand8(uint8_t command, uint8_t index) {
//    startWrite();
//    writeCommand(0xD9);  // woo sekret command?
//    ILI9341_SPI_XFER(0x10 + index);
//    writeCommand(command);
//    uint8_t r = ILI9341_SPI_XFER(0xFF);
//    endWrite();
//    return r;
//}

/*!
    @brief  Essentially writePixel() with a transaction around it. I don't
            think this is in use by any of our code anymore (believe it was
            for some older BMP-reading examples), but is kept here in case
            any user code relies on it. Consider it DEPRECATED.
    @param  color  16-bit pixel color in '565' RGB format.
*/
//void pushColor(uint16_t color) {
//    uint8_t hi = color >> 8, lo = color;
//    startWrite();
//    ILI9341_SPI_XFER(hi);
//    ILI9341_SPI_XFER(lo);
//    endWrite();
//}

// end of code.
