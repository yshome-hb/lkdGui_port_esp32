#ifndef __LCD128X64_DRIVER_H
#define	__LCD128X64_DRIVER_H

#include <stdint.h>

/* lcd初始化 */	
void Lcd128x64Init(void);
/* 写命令 */
void Lcd128x64WriteCommand(uint8_t cmd);
/* 写数据 */
void Lcd128x64WriteData(void *data, uint16_t length);
/* 设置页地址 */	
void Lcd128x64SetRow(uint8_t row);
/* 设置列地址 */
void Lcd128x64SetCol(uint8_t col);
/* 开显示 */
void Lcd128x64OpenDisplay(void);
/* 关显示 */
void Lcd128x64CloseDisplay(void);

#endif /* __LCD128X64_DRIVER_H */
/* END */
