#ifndef __SERIAL_H__
#define __SERIAL_H__

#include <stdio.h>
#include <stdint.h>

void Serial_Init(void);
void Serial_SendByte(uint8_t byte);
void Serial_SendArray(uint8_t *Array, uint16_t Length);
void Serial_SendString(char *String);
void Serial_SendNum(uint32_t Number, uint8_t Length);
void Serial_Printf(char *format, ...);
	
#endif
