/**
 ILI9341 FOR PIC16F18875

  Autor:
   sebas2906

  File Name:
    main.c

  Summary:
 This is a DEMO for the ILI9341 Library
 */
#include "mcc_generated_files/mcc.h"
#include "ILI9341.h"
#include "GFX_Library.h"
#include <stdio.h>
#include <stdlib.h>


void disp_texto(uint8_t *cadena);
void testFillScreen(void);
void testText(void);
void testLines(uint16_t color);
void testFastLines(uint16_t color1, uint16_t color2);
void testRects(uint16_t color);
void testFilledRects(uint16_t color1, uint16_t color2);
void testFilledCircles(uint8_t radius, uint16_t color);
void testCircles(uint8_t radius, uint16_t color);
void testTriangles(void);
void testFilledTriangles(void);
void testRoundRects(void);
void testFilledRoundRects(void);

//control


void main(void) {
    //PORTAbits.RA0=0;
    SYSTEM_Initialize();
    SPI1_Open(SPI1_DEFAULT);
    tft_begin();   
    fillScreen(ILI9341_BLACK);
    testFillScreen();
    
    testText();
    __delay_ms(2000);
    //testFilledCircles(12,ILI9341_RED);
    //testFilledTriangles();
    while (1) {
        for (uint8_t i = 0; i < 4; i++) {
            __delay_ms(1000);
            setRotation(i);
            testText();
        }

    }
}

void disp_texto(uint8_t *cadena) {
    uint8_t i = -1;
    while (cadena[i++] != '\0') {
        display_print(cadena[i]);
    }
}

void testFillScreen() {
    fillScreen(ILI9341_BLACK);
    fillScreen(ILI9341_RED);
    fillScreen(ILI9341_GREEN);
    fillScreen(ILI9341_BLUE);
    fillScreen(ILI9341_BLACK);
}

void testText() {
  
    fillScreen(ILI9341_BLACK);
    display_setCursor(0, 0);
    display_setTextColor2(ILI9341_WHITE);
    display_setTextSize(1);
    disp_texto("Hello World!\r\n");
    //display_print("Hello World!\r\n");
    display_setTextColor2(ILI9341_YELLOW);
    display_setTextSize(2);
   
    disp_texto("1234.56\r\n");
    // printf(disp_texto, "%f\r\n", 1234.56);
    display_setTextColor2(ILI9341_RED);
    display_setTextSize(3);
    //printf(disp_texto, "%LX\r\n", 0xDEADBEEF);
    disp_texto("DEADBEEF\r\n");
    disp_texto("\r\n"); // start a new line
    display_setTextColor2(ILI9341_GREEN);
    display_setTextSize(5);
    disp_texto("Groop\r\n");
    display_setTextSize(2);
    disp_texto("I implore thee,\r\n");
    display_setTextSize(1);
    disp_texto("my foonting turlingdromes.\r\n");
    disp_texto("And hooptiously drangle me\r\n");
    disp_texto("with crinkly bindlewurdles,\r\n");
    disp_texto("Or I will rend thee\r\n");
    disp_texto("in the gobberwarts\r\n");
    disp_texto("with my blurglecruncheon,\r\n");
    disp_texto("see if I don't!\r\n");
}

void testLines(uint16_t color) {
    int16_t x1, y1, x2, y2,
            w = _width,
            h = _height;

    fillScreen(ILI9341_BLACK);

    x1 = y1 = 0;
    y2 = h - 1;

    for (x2 = 0; x2 < w; x2 += 6) display_drawLine(x1, y1, x2, y2, color);
    x2 = w - 1;
    for (y2 = 0; y2 < h; y2 += 6) display_drawLine(x1, y1, x2, y2, color);

    fillScreen(ILI9341_BLACK);

    x1 = w - 1;
    y1 = 0;
    y2 = h - 1;

    for (x2 = 0; x2 < w; x2 += 6) display_drawLine(x1, y1, x2, y2, color);
    x2 = 0;
    for (y2 = 0; y2 < h; y2 += 6) display_drawLine(x1, y1, x2, y2, color);

    fillScreen(ILI9341_BLACK);

    x1 = 0;
    y1 = h - 1;
    y2 = 0;

    for (x2 = 0; x2 < w; x2 += 6) display_drawLine(x1, y1, x2, y2, color);
    x2 = w - 1;
    for (y2 = 0; y2 < h; y2 += 6) display_drawLine(x1, y1, x2, y2, color);

    fillScreen(ILI9341_BLACK);

    x1 = w - 1;
    y1 = h - 1;
    y2 = 0;

    for (x2 = 0; x2 < w; x2 += 6) display_drawLine(x1, y1, x2, y2, color);
    x2 = 0;
    for (y2 = 0; y2 < h; y2 += 6) display_drawLine(x1, y1, x2, y2, color);
}

void testFastLines(uint16_t color1, uint16_t color2) {
    int16_t x, y, w = _width, h = _height;

    fillScreen(ILI9341_BLACK);

    for (y = 0; y < h; y += 5) drawHLine(0, y, w, color1);
    for (x = 0; x < w; x += 5) drawVLine(x, 0, h, color2);
}

void testRects(uint16_t color) {
    int16_t n, i, i2,
            cx = _width / 2,
            cy = _height / 2;

    fillScreen(ILI9341_BLACK);
    n = min(_width, _height);

    for (i = 2; i < n; i += 6) {
        i2 = i / 2;
        display_drawRect(cx - i2, cy - i2, i, i, color);
    }
}

void testFilledRects(uint16_t color1, uint16_t color2) {
    int16_t n, i, i2,
            cx = _width / 2 - 1,
            cy = _height / 2 - 1;

    fillScreen(ILI9341_BLACK);
    n = min(_width, _height);
    for (i = n; i > 0; i -= 6) {
        i2 = i / 2 - 1;

        fillRect(cx - i2, cy - i2, i, i, color1);

        // Outlines are not included in timing results
        display_drawRect(cx - i2, cy - i2, i, i, color2);
    }
}

void testFilledCircles(uint8_t radius, uint16_t color) {
    int16_t x, y, w = _width, h = _height, r2 = radius * 2;

    fillScreen(ILI9341_BLACK);

    for (x = radius; x < w; x += r2) {
        for (y = radius; y < h; y += r2) {
            display_fillCircle(x, y, radius, color);
        }
    }
}

void testCircles(uint8_t radius, uint16_t color) {
    int16_t x, y, r2 = radius * 2,
            w = _width + radius,
            h = _height + radius;

    for (x = 0; x < w; x += r2) {
        for (y = 0; y < h; y += r2) {
            display_drawCircle(x, y, radius, color);
        }
    }
}

void testTriangles() {
    int16_t n, i, cx = _width / 2 - 1,
            cy = _height / 2 - 1;
    uint16_t color = 0xF600;
    fillScreen(ILI9341_BLACK);
    n = min(cx, cy);

    for (i = 0; i < n; i += 5) {
        display_drawTriangle(
                cx, cy - i, // peak
                cx - i, cy + i, // bottom left
                cx + i, cy + i, // bottom right
                color);
        color += 100;
    }
}

void testFilledTriangles() {
    int16_t i, cx = _width / 2 - 1,
            cy = _height / 2 - 1;

    fillScreen(ILI9341_BLACK);

    for (i = min(cx, cy); i > 10; i -= 5) {
        display_fillTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i,
                display_color565(0, i * 2, i * 2));
        display_drawTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i,
                display_color565(i * 2, i * 2, 0));
    }
}

void testRoundRects() {
    int16_t w, i, i2,
            cx = _width / 2 - 1,
            cy = _height / 2 - 1;

    fillScreen(ILI9341_BLACK);
    w = min(_width, _height);

    for (i = 0; i < w; i += 6) {
        i2 = i / 2;
        display_drawRoundRect(cx - i2, cy - i2, i, i, i / 8, display_color565(i, 0, 0));
    }
}

void testFilledRoundRects() {
    int16_t i, i2,
            cx = _width / 2 - 1,
            cy = _height / 2 - 1;

    fillScreen(ILI9341_BLACK);

    for (i = min(_width, _height); i > 20; i -= 6) {
        i2 = i / 2;
        display_fillRoundRect(cx - i2, cy - i2, i, i, i / 8, display_color565(0, i, 0));
    }
}



/**
 End of File
 */