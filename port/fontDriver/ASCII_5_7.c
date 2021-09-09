#include <stdint.h>
#pragma GCC diagnostic ignored "-Wmissing-braces"

#define ASCII_NUM 96
#define ASCII_EACH_SIZE 7
/* 
 * ASCII 5_7 ��ģ��.ȥ����ǰ32�������ַ���
 * ɨ�跽ʽ�������ң����ϵ��¡����Ȱ��ֽڶ��롣
 * �洢��ʽ: ��λ��ǰ��
*/
const unsigned char ASCII_5_7[ASCII_NUM][ASCII_EACH_SIZE]={
0x00,0x00,0x00,0x00,0x00,0x00,0x00,//' '
0x04,0x04,0x04,0x04,0x04,0x00,0x04,//'!'
0x05,0x05,0x05,0x00,0x00,0x00,0x00,//'"'
0x0A,0x0A,0x1F,0x0A,0x1F,0x0A,0x0A,//'#'
0x04,0x1E,0x05,0x0E,0x14,0x0F,0x04,//'$'
0x03,0x13,0x08,0x04,0x02,0x19,0x18,//'%'
0x06,0x09,0x05,0x02,0x15,0x09,0x16,//'&'
0x03,0x02,0x01,0x00,0x00,0x00,0x00,//'''
0x04,0x02,0x01,0x01,0x01,0x02,0x04,//'('
0x01,0x02,0x04,0x04,0x04,0x02,0x01,//')'
0x00,0x0A,0x04,0x1F,0x04,0x0A,0x00,//'*'
0x00,0x04,0x04,0x1F,0x04,0x04,0x00,//'+'
0x00,0x00,0x00,0x00,0x03,0x02,0x01,//','
0x00,0x00,0x00,0x1F,0x00,0x00,0x00,//'-'
0x00,0x00,0x00,0x00,0x00,0x03,0x03,//'.'
0x00,0x10,0x08,0x04,0x02,0x01,0x00,//'/'
0x0E,0x11,0x19,0x15,0x13,0x11,0x0E,//'0'
0x04,0x06,0x04,0x04,0x04,0x04,0x0E,//'1'
0x0E,0x11,0x10,0x0C,0x02,0x01,0x1F,//'2'
0x0E,0x11,0x10,0x0C,0x10,0x11,0x0E,//'3'
0x08,0x0C,0x0A,0x09,0x1F,0x08,0x08,//'4'
0x1F,0x01,0x0F,0x10,0x10,0x11,0x0E,//'5'
0x0C,0x02,0x01,0x0F,0x11,0x11,0x0E,//'6'
0x1F,0x10,0x08,0x04,0x02,0x02,0x02,//'7'
0x0E,0x11,0x11,0x0E,0x11,0x11,0x0E,//'8'
0x0E,0x11,0x11,0x1E,0x10,0x08,0x06,//'9'
0x00,0x03,0x03,0x00,0x03,0x03,0x00,//':'
0x00,0x03,0x03,0x00,0x03,0x02,0x01,//';'
0x08,0x04,0x02,0x01,0x02,0x04,0x08,//'<'
0x00,0x00,0x1F,0x00,0x1F,0x00,0x00,//'='
0x01,0x02,0x04,0x08,0x04,0x02,0x01,//'>'
0x0E,0x11,0x10,0x08,0x04,0x00,0x04,//'?' 
0x0E,0x11,0x10,0x16,0x15,0x15,0x0E,//'@' 
0x0E,0x11,0x11,0x1F,0x11,0x11,0x11,//'A' 
0x0F,0x11,0x11,0x0F,0x11,0x11,0x0F,//'B' 
0x0E,0x11,0x01,0x01,0x01,0x11,0x0E,//'C' 
0x07,0x09,0x11,0x11,0x11,0x09,0x07,//'D' 
0x1F,0x01,0x01,0x0F,0x01,0x01,0x1F,//'E' 
0x1F,0x01,0x01,0x0F,0x01,0x01,0x01,//'F' 
0x0E,0x11,0x01,0x01,0x19,0x11,0x1E,//'G' 
0x11,0x11,0x11,0x1F,0x11,0x11,0x11,//'H' 
0x07,0x02,0x02,0x02,0x02,0x02,0x07,//'I' 
0x1C,0x08,0x08,0x08,0x08,0x09,0x06,//'J' 
0x11,0x09,0x05,0x03,0x05,0x09,0x11,//'K' 
0x01,0x01,0x01,0x01,0x01,0x01,0x1F,//'L' 
0x11,0x1B,0x15,0x15,0x11,0x11,0x11,//'M' 
0x11,0x11,0x13,0x15,0x19,0x11,0x11,//'N' 
0x0E,0x11,0x11,0x11,0x11,0x11,0x0E,//'O' 
0x0F,0x11,0x11,0x0F,0x01,0x01,0x01,//'P' 
0x0E,0x11,0x11,0x11,0x15,0x09,0x16,//'Q' 
0x0F,0x11,0x11,0x0F,0x05,0x09,0x11,//'R' 
0x0E,0x11,0x01,0x0E,0x10,0x11,0x0E,//'S' 
0x1F,0x04,0x04,0x04,0x04,0x04,0x04,//'T' 
0x11,0x11,0x11,0x11,0x11,0x11,0x0E,//'U' 
0x11,0x11,0x11,0x11,0x11,0x0A,0x04,//'V' 
0x11,0x11,0x11,0x15,0x15,0x15,0x0A,//'W' 
0x11,0x11,0x0A,0x04,0x0A,0x11,0x11,//'X' 
0x11,0x11,0x0A,0x04,0x04,0x04,0x04,//'Y' 
0x1F,0x10,0x08,0x04,0x02,0x01,0x1F,//'Z' 
0x07,0x01,0x01,0x01,0x01,0x01,0x07,//'[' 
0x00,0x01,0x02,0x04,0x08,0x10,0x00,//'\' 
0x07,0x04,0x04,0x04,0x04,0x04,0x07,//']' 
0x04,0x0A,0x11,0x00,0x00,0x00,0x00,//'^' 
0x00,0x00,0x00,0x00,0x00,0x00,0x1F,//'_'
0x01,0x02,0x04,0x00,0x00,0x00,0x00,//'`'
0x00,0x00,0x0E,0x10,0x1E,0x11,0x1E,//'a' 
0x01,0x01,0x0D,0x13,0x11,0x11,0x0F,//'b' 
0x00,0x00,0x06,0x09,0x01,0x09,0x06,//'c' 
0x10,0x10,0x16,0x19,0x11,0x11,0x1E,//'d' 
0x00,0x00,0x0E,0x11,0x1F,0x01,0x0E,//'e' 
0x04,0x0A,0x02,0x07,0x02,0x02,0x02,//'f' 
0x00,0x1E,0x11,0x11,0x1E,0x10,0x0E,//'g' 
0x01,0x01,0x0D,0x13,0x11,0x11,0x11,//'h' 
0x01,0x00,0x01,0x01,0x01,0x01,0x01,//'i' 
0x04,0x00,0x06,0x04,0x04,0x04,0x03,//'j' 
0x01,0x01,0x09,0x05,0x03,0x05,0x09,//'k' 
0x03,0x02,0x02,0x02,0x02,0x02,0x07,//'l' 
0x00,0x00,0x0B,0x15,0x11,0x11,0x11,//'m' 
0x00,0x00,0x0D,0x0B,0x09,0x09,0x09,//'n' 
0x00,0x00,0x06,0x09,0x09,0x09,0x06,//'o' 
0x00,0x07,0x09,0x09,0x07,0x01,0x01,//'p' 
0x00,0x0E,0x09,0x09,0x0E,0x08,0x08,//'q' 
0x00,0x00,0x05,0x03,0x01,0x01,0x01,//'r' 
0x00,0x00,0x0E,0x01,0x06,0x08,0x07,//'s' 
0x02,0x02,0x07,0x02,0x02,0x02,0x02,//'t' 
0x00,0x00,0x09,0x09,0x09,0x09,0x0E,//'u' 
0x00,0x00,0x11,0x11,0x11,0x0A,0x04,//'v' 
0x00,0x00,0x11,0x11,0x15,0x15,0x0A,//'w' 
0x00,0x00,0x11,0x0A,0x04,0x0A,0x11,//'x' 
0x00,0x09,0x09,0x09,0x0E,0x08,0x06,//'y' 
0x00,0x00,0x1F,0x08,0x04,0x02,0x1F,//'z' 
0x04,0x02,0x02,0x01,0x02,0x02,0x04,//'{' 
0x02,0x02,0x02,0x02,0x02,0x02,0x02,//'|' 
0x01,0x02,0x02,0x04,0x02,0x02,0x01,//'}' 
0x16,0x09,0x00,0x00,0x00,0x00,0x00,//'~' 
0x00,0x00,0x00,0x00,0x00,0x00,0x00,//'?' 
};

static uint8_t const GetBit[8] = {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};

uint8_t BitExchange(uint8_t data)
{
	uint8_t temp = 0;
	
	for(uint8_t i = 0; i < 8;i++){
		temp |= data & GetBit[i] ? GetBit[ 7 - i] : 0;
	}
	
	return temp;
}

uint8_t GetFontASCII_5_7(uint8_t code1, uint8_t *pBuff)
{
	uint16_t offset = code1 - 32;
	
	if(offset > ASCII_NUM){
		for(uint16_t i = 0; i < ASCII_EACH_SIZE; i++){
			pBuff[i] = 0;
		}
	}
	else{
		for(uint16_t i = 0; i < ASCII_EACH_SIZE; i++){
			pBuff[i] = BitExchange(ASCII_5_7[offset][i]);
		}
	}
	
	return 0;
}

/* END */