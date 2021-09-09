/**
  * @file   lcdDriverPort.c
  * @author  guoweilkd
  * @version V0.0.0
  * @date    2018/04/18
  * @brief  lkdGuiҺ����ʾ�������ӿڣ�����ֲ����亯���ľ������ݡ�
  */

#include "lkdGui.h"
#include "lcd128x64Driver.h"

/* Gui��ʾ������ */
static uint8_t  lkdGuiBuff[(GUIYMAX>>3) + 1][GUIXMAX];

/**
  *@brief LCD��ʼ��
  *@param  None
  *@retval None
  */
void LcdInit(void)
{
  Lcd128x64Init();
}

/**
  *@brief ��Gui������������ʾ��lcd��
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
  *@brief ��Guiָ��������������ʾ��lcd��
  *@param  beginx,beginy,endx,endy ����
  *@retval None
  */
void GuiRangeUpdateDisplay(lkdCoord beginx, lkdCoord beginy,lkdCoord endx, lkdCoord endy)
{
	/* ����û����� */
}

/**
  *@brief �򻺳�������
  *@param  x,y ����
  *@param  color ��ɫ <Ŀǰֻ�к�:CBLACK ��:CWHITLE>
  *@retval None
  */
void GuiDrawPoint(lkdCoord x, lkdCoord y, lkdColour color)
{
	if(color == CWHITLE){//��ɫ
		lkdGuiBuff[y>>3][x] &= ~(0x01<<(y&0x07));
	}
	else{//��ɫ
		lkdGuiBuff[y>>3][x] |= (0x01<<(y&0x07));
	}
}

/**
  *@brief ��ȡ��ǰ��ʾ�ĵ�
  *@param  x,y ����
  *@param  color ��ɫ <Ŀǰֻ�к�:CBLACK ��:CWHITLE>
  *@retval None
  */
void  GuiReadPoint(lkdCoord x, lkdCoord y, lkdColour *pColor)
{
  *pColor = ((lkdGuiBuff[y>>3][x] & (y&0x07)) > 0);
}

/**
  *@brief ����ʾ
  *@param  None
  *@retval None
  */
void CloseLcdDisplay(void)
{
  Lcd128x64CloseDisplay();
}

/**
  *@brief ����ʾ
  *@param  None
  *@retval None
  */
void OpenLcdDisplay(void)
{
  Lcd128x64OpenDisplay();
}