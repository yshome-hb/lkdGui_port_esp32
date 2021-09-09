/**
  * @file   lcdDriverPort.c
  * @author  guoweilkd
  * @version V0.0.0
  * @date    2018/04/18
  * @brief  lkdGui液晶显示屏驱动接口，由移植者填充函数的具体内容。
  */

#include "lkdGui.h"
#include "lcd128x64Driver.h"

/* Gui显示缓冲区 */
static uint8_t  lkdGuiBuff[(GUIYMAX>>3) + 1][GUIXMAX];

/**
  *@brief LCD初始化
  *@param  None
  *@retval None
  */
void LcdInit(void)
{
  Lcd128x64Init();
}

/**
  *@brief 将Gui缓冲区数据显示到lcd上
  *@param  None
  *@retval None
  */
void GuiUpdateDisplayAll(void)
{
	uint32_t y;
	for(y = 0; y < GUIYMAX; y+=8){
	  Lcd128x64SetRow(y>>3);
	  Lcd128x64SetCol(0);	
		Lcd128x64WriteData(lkdGuiBuff[y>>3], GUIXMAX);
	}
}

/**
  *@brief 将Gui指定缓冲区数据显示到lcd上
  *@param  beginx,beginy,endx,endy 坐标
  *@retval None
  */
void GuiRangeUpdateDisplay(lkdCoord beginx, lkdCoord beginy,lkdCoord endx, lkdCoord endy)
{
	/* 添加用户代码 */
}

/**
  *@brief 向缓冲区画点
  *@param  x,y 坐标
  *@param  color 颜色 <目前只有黑:CBLACK 白:CWHITLE>
  *@retval None
  */
void GuiDrawPoint(lkdCoord x, lkdCoord y, lkdColour color)
{
	if(color == CWHITLE){//白色
		lkdGuiBuff[y>>3][x] &= ~(0x01<<(y&0x07));
	}
	else{//黑色
		lkdGuiBuff[y>>3][x] |= (0x01<<(y&0x07));
	}
}

/**
  *@brief 读取当前显示的点
  *@param  x,y 坐标
  *@param  color 颜色 <目前只有黑:CBLACK 白:CWHITLE>
  *@retval None
  */
void  GuiReadPoint(lkdCoord x, lkdCoord y, lkdColour *pColor)
{
  *pColor = ((lkdGuiBuff[y>>3][x] & (y&0x07)) > 0);
}

/**
  *@brief 关显示
  *@param  None
  *@retval None
  */
void CloseLcdDisplay(void)
{
  Lcd128x64CloseDisplay();
}

/**
  *@brief 开显示
  *@param  None
  *@retval None
  */
void OpenLcdDisplay(void)
{
  Lcd128x64OpenDisplay();
}