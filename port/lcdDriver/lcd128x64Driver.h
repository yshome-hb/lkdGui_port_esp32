#ifndef __LCD128X64_DRIVER_H
#define	__LCD128X64_DRIVER_H

#include <stdint.h>

/* lcd��ʼ�� */	
void Lcd128x64Init(void);
/* д���� */
void Lcd128x64WriteCommand(uint8_t cmd);
/* д���� */
void Lcd128x64WriteData(void *data, uint16_t length);
/* ����ҳ��ַ */	
void Lcd128x64SetRow(uint8_t row);
/* �����е�ַ */
void Lcd128x64SetCol(uint8_t col);
/* ����ʾ */
void Lcd128x64OpenDisplay(void);
/* ����ʾ */
void Lcd128x64CloseDisplay(void);

#endif /* __LCD128X64_DRIVER_H */
/* END */
