/**********************************************************
filename: board.h
**********************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _BOARD_H
#define _BOARD_H
#include "misc.h"
#include "rs485Dev.h"
#include "uartdev.h"
#include "input.h"
#include "output.h"

/* output variables for extern function --------------------------------------*/
extern IWDG_HandleTypeDef hiwdg;
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern SPI_HandleTypeDef hspi2;

// gloable var
extern const char ABOUT[];
extern const char COMMON_HELP[];
extern char addrPre[4];
extern u8 boardAddr;
extern u8 baudHost;
extern u8 baud485;
extern u32 errorCode;

extern UartDev_t console;
extern Rs485Dev_t rs485;

extern INPUT_DEV_T inputDev;
extern OUTPUT_DEV_T outputDev;

extern const PIN_T RUNNING;
extern u8 initalDone;

// gloable method
void boardPreInit(void);
void boardInit(void);
u8 brdCmd(const char* CMD, u8 brdAddr, void (*xprint)(const char* FORMAT_ORG, ...));
void printHelp(u8 brdAddr, void (*xprint)(const char* FORMAT_ORG, ...));

void print(const char* FORMAT_ORG, ...);
void printS(const char* MSG);
void print485(const char* FORMAT_ORG, ...);
void printS485(const char* STRING);

s8 ioWrite(u16 addr, const u8 *pDat, u16 nBytes);
s8 ioRead(u16 addr, u8 *pDat, u16 nBytes);
s8 ioWriteReg(u16 addr, s32 val);
s8 ioReadReg(u16 addr, s32* val);

// board address adc, better to print to double check

#endif

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
