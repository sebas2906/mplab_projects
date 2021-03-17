/**
   PONG 

  Autor:
   sebas2906

  File Name:
    main.c

  Summary:
 Juego de Pong para pic16f18875
  Description:
 Juego de Pong adaptando la libreria de ILI9341 de Adafruit y SPI de MCC a 8Mhz.
 Se usa el PIC16f18875 a 32Mhz con clock interno HFINTOSC/1
 PINOUT:
 * A0->DC
 * A1->ctr_der jugador2
 * A2->ctr_izq jugador2
 * C0->CS
 * C1->RST
 * C3->SCK1
 * C6->SDO
 * C4->SDI
 * B4->ctr_izq jugador1
 * C5->ctr_der jugador1
 */
#include "mcc_generated_files/mcc.h"
#include "ILI9341.h"
#include "GFX_Library.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    uint8_t sentido;//0->izquierda
    uint8_t velocidad;//velocidad de desplazamiento del jugador
    uint8_t escala;//cantidad de px por unidad
    uint8_t id;//0,1
    uint8_t forma[5];//arreglo de bits del caracter
    uint8_t posicion;//posicion horizontal
}Jugador_t;

typedef struct{
    uint8_t sentidox;
    uint8_t sentidoy;
    uint8_t velocidad;
    uint8_t escala;
    uint8_t forma[5];
    uint8_t posicionx;
    uint16_t posiciony;
}Objeto_t;

enum Interrupciones{
    inactivo,
    izquierda,
    derecha
};

Jugador_t jugador1={0,30,13,0,{0x01, 0x01, 0x01, 0x01, 0x01},0};
Jugador_t jugador2={0,30,13,1,{0x80, 0x80, 0x80, 0x80, 0x80},0};;
Objeto_t bolita={0,0,6,2,{0x3c,0x7e, 0x7e, 0x7e, 0x3c},(ILI9341_TFTWIDTH-(2 * 5)) / 2,(ILI9341_TFTHEIGHT-(2 * 8)) / 2};

uint8_t movimiento_jugador1, movimiento_jugador2 = 0;
uint8_t marcador[3];
uint8_t puntaje1=0;
uint8_t puntaje2=0;

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
void dibujarMarcador(uint8_t puntaje1,uint8_t puntaje2);
//interrupciones
//jugador1
void ctrl_izq(void);
void ctrl_der(void);
//jugador2
void ctrl_izq2(void);
void ctrl_der2(void);
//control
void moverJugador(Jugador_t *jugador);

void main(void) {
    PORTAbits.RA0=0;
    // initialize the device
    SYSTEM_Initialize();
    SPI1_Open(SPI1_DEFAULT);
    //Interrupciones
    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();
    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    //jugador1
    IOCCF5_SetInterruptHandler(ctrl_der);
    IOCBF4_SetInterruptHandler(ctrl_izq);
    //jugador2
    IOCAF1_SetInterruptHandler(ctrl_izq2);
    IOCAF2_SetInterruptHandler(ctrl_der2);
    //***RESOLUCION 240X320
    //inicializacion de los jugadores
    tft_begin();   
    // init done!
   // __delay_ms(10);
    fillScreen(ILI9341_BLACK);
    //predibujar a los jugadores
    display_drawCustomChar(0, 0, jugador1.forma, ILI9341_GREEN, ILI9341_BLACK,jugador1.escala);
    display_drawCustomChar(0, ILI9341_TFTHEIGHT-(jugador2.escala * 8), jugador2.forma, ILI9341_GREEN, ILI9341_BLACK,jugador2.escala);
    //dibujar a la bolita
    display_drawCustomChar(bolita.posicionx,bolita.posiciony,bolita.forma,ILI9341_WHITE, ILI9341_BLACK,bolita.escala);
    dibujarMarcador(0,0);
    while (1) {
        //Movimiento de los jugadores
        if (movimiento_jugador1 == izquierda) {
            jugador1.sentido=0;
        } else if (movimiento_jugador1 == derecha) {
            jugador1.sentido=1;
        }
        if (movimiento_jugador2 == izquierda) {
            jugador2.sentido=0;
        } else if (movimiento_jugador2 == derecha) {
            jugador2.sentido=1;
        }
 
        if (!(movimiento_jugador1 || movimiento_jugador2)) {
            __delay_ms(65);//65
        } else if(movimiento_jugador1) {
            moverJugador(&jugador1);
            movimiento_jugador1 = inactivo;
            dibujarMarcador(puntaje1,puntaje2);
        }else{
            moverJugador(&jugador2);
            movimiento_jugador2 = inactivo;
            dibujarMarcador(puntaje1,puntaje2);
        }
        
        //Trayectoria de la bola
        display_drawCustomChar(bolita.posicionx,bolita.posiciony,bolita.forma,ILI9341_BLACK,ILI9341_BLACK,bolita.escala);
        if (bolita.posicionx >= (ILI9341_TFTWIDTH-(2 * 5))) {
            bolita.sentidox = 1;
        } else if (bolita.posicionx <= 10) {
            bolita.sentidox = 0;
        }
 
        if (bolita.posiciony >= ((ILI9341_TFTHEIGHT-(2 * 8))-16)) {
            //lado del jugador 2
            if ((bolita.posicionx >= jugador2.posicion)&&(bolita.posicionx <= (jugador2.posicion+((5 * 13) / 2)) + 30)) {
                bolita.sentidoy = 1;
            }else{
                puntaje1++;
                dibujarMarcador(puntaje1,puntaje2);
                bolita.posicionx=(ILI9341_TFTWIDTH-(2 * 5)) / 2;
                bolita.posiciony=(ILI9341_TFTHEIGHT-(2 * 8)) / 2;
            }
            //lado del jugador 1
        } else if (bolita.posiciony <= 18) {
            if ((bolita.posicionx >= jugador1.posicion)&&(bolita.posicionx <= (jugador1.posicion+((5 * 13) / 2)) + 30)) {
                bolita.sentidoy = 0;
            }else{
                puntaje2++;
                dibujarMarcador(puntaje1,puntaje2);
                bolita.posicionx=(ILI9341_TFTWIDTH-(2 * 5)) / 2;
                bolita.posiciony=(ILI9341_TFTHEIGHT-(2 * 8)) / 2;
            }
        }

        if (bolita.sentidox) {
            bolita.posicionx -= bolita.velocidad;
        } else {
            bolita.posicionx += bolita.velocidad;
        }

        if (bolita.sentidoy) {
            bolita.posiciony -= bolita.velocidad;
        } else {
            bolita.posiciony += bolita.velocidad;
        }
        display_drawCustomChar(bolita.posicionx, bolita.posiciony, bolita.forma, ILI9341_GREEN, ILI9341_BLACK,bolita.escala);
        
    }
}

//jugador1
void ctrl_izq() {
    movimiento_jugador1 = izquierda;
}

void ctrl_der() {
    movimiento_jugador1 = derecha;
}
//jugador2

void ctrl_izq2() {
    movimiento_jugador2 = izquierda;
}

void ctrl_der2() {
    movimiento_jugador2 = derecha;
}

void dibujarMarcador(uint8_t puntaje1,uint8_t puntaje2){
    setRotation(1);
    display_setCursor((ILI9341_TFTHEIGHT/2)-10,0);
    display_setTextSize(2);
    display_setTextColor(ILI9341_BLACK,ILI9341_BLACK);
    disp_texto(marcador);
    display_setCursor((ILI9341_TFTHEIGHT/2)-10,0);
    display_setTextColor2(ILI9341_GREEN);
    sprintf(marcador,"%i:%i",puntaje1,puntaje2);
    disp_texto(marcador);
    setRotation(0);
}


void moverJugador(Jugador_t *jugador) {
    uint8_t y = 0;
    if (jugador->id) {
        y = ILI9341_TFTHEIGHT-(jugador->escala * 8);
    }
    //elimino el caracter de la posicion anterior
    display_drawCustomChar(jugador->posicion, y, jugador->forma, ILI9341_BLACK, ILI9341_BLACK, jugador->escala);
    if (jugador->sentido) {
        jugador->posicion += jugador->velocidad;
    } else {
        jugador->posicion -= jugador->velocidad;
    }
    display_drawCustomChar(jugador->posicion, y, jugador->forma, ILI9341_GREEN, ILI9341_BLACK, jugador->escala);
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