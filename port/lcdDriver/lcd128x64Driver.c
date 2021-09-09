/**
  * @file   lcd128x64Driver.c
  * @author  guoweilkd
  * @version V1.1.0
  * @date    2018/05/09
  * @brief  Lcd驱动
  * 本文件Lcd为128x64
  */

#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/spi_master.h"
#include "lcd128x64Driver.h"

#define LCD_HOST    SPI2_HOST

#define PIN_NUM_MISO 2  //没用

#define PIN_NUM_MOSI 7
#define PIN_NUM_CLK  6
#define PIN_NUM_CS   10
#define PIN_NUM_DC   19
#define PIN_NUM_RST  18

#define PARALLEL_LINES 16

static spi_device_handle_t spi;

/**
  *@brief LCD初始化
  *@param  None
  *@retval None
  */
void Lcd128x64Init(void)
{
    esp_err_t ret;
	spi_bus_config_t buscfg={
        .miso_io_num=PIN_NUM_MISO,
        .mosi_io_num=PIN_NUM_MOSI,
        .sclk_io_num=PIN_NUM_CLK,
        .quadwp_io_num=-1,
        .quadhd_io_num=-1,
        .max_transfer_sz=128,
    };

    spi_device_interface_config_t devcfg={
        .clock_speed_hz=8*1000*1000,           //Clock out at 10 MHz
        .mode=0,                               //SPI mode 0
        .spics_io_num=PIN_NUM_CS,              //CS pin
        .queue_size=7,                         //We want to be able to queue 7 transactions at a time
    };

    ret=spi_bus_initialize(LCD_HOST, &buscfg, SPI_DMA_CH_AUTO);
    ESP_ERROR_CHECK(ret);

    ret=spi_bus_add_device(LCD_HOST, &devcfg, &spi);
    ESP_ERROR_CHECK(ret);

    gpio_reset_pin(PIN_NUM_DC);
	gpio_set_direction(PIN_NUM_DC, GPIO_MODE_OUTPUT);

    gpio_reset_pin(PIN_NUM_RST);
	gpio_set_direction(PIN_NUM_RST, GPIO_MODE_OUTPUT);

	gpio_set_level(PIN_NUM_RST, 0);
	vTaskDelay(100 / portTICK_RATE_MS);
	gpio_set_level(PIN_NUM_RST, 1);
	vTaskDelay(100 / portTICK_RATE_MS);

	Lcd128x64WriteCommand(0xE3);
	Lcd128x64WriteCommand(0xAE);
	Lcd128x64WriteCommand(0x40);
	Lcd128x64WriteCommand(0x2F);
	Lcd128x64WriteCommand(0x22);
	Lcd128x64WriteCommand(0x81);
	Lcd128x64WriteCommand(0x2F);
	Lcd128x64WriteCommand(0xA3);
	Lcd128x64WriteCommand(0xA0);
	Lcd128x64WriteCommand(0xC8);
	Lcd128x64WriteCommand(0xA4);
	Lcd128x64WriteCommand(0xA6);
	Lcd128x64WriteCommand(0xAF);
}

/**
  *@brief 写命令
  *@param  cmd 命令
  *@retval None
  */
void Lcd128x64WriteCommand(uint8_t cmd)
{
    esp_err_t ret;
    spi_transaction_t t;

    gpio_set_level(PIN_NUM_DC, 0);

    memset(&t, 0, sizeof(t));       //Zero out the transaction
    t.length = 8;                     //Command is 8 bits
    t.tx_buffer = &cmd;               //The data is the cmd itself
    t.user = (void*)0;                //D/C needs to be set to 0
    ret = spi_device_polling_transmit(spi, &t);  //Transmit!
    assert(ret==ESP_OK);            //Should have had no issues.
}

/**
  *@brief 写数据
  *@param  data 数据
  *@retval None
  */
void Lcd128x64WriteData(void *data, uint16_t length)
{
    esp_err_t ret;
    spi_transaction_t t;

    gpio_set_level(PIN_NUM_DC, 1);

    memset(&t, 0, sizeof(t));       //Zero out the transaction
    t.length = 8*length;            //Command is 8 bits
    t.tx_buffer = data;               //The data is the cmd itself
    t.user = (void*)0;                //D/C needs to be set to 0
    ret = spi_device_polling_transmit(spi, &t);  //Transmit!
    assert(ret==ESP_OK);            //Should have had no issues.
}

/**
  *@brief 设置起始行
  *@param  row 行
  *@retval None
  */
void Lcd128x64SetRow(uint8_t row)
{
	Lcd128x64WriteCommand(0xB0 | row);  
}

/**
  *@brief 设置起始列
  *@param  col 列地址
  *@retval None
  */
void Lcd128x64SetCol(uint8_t col)
{
    uint8_t columnLow = col & 0x0F;
	uint8_t columnHigh = (col >> 4) & 0x0F;
	Lcd128x64WriteCommand(0x10 | columnHigh);
	Lcd128x64WriteCommand(0x00 | columnLow); 
}

/**
  *@brief 开显示
  *@param  None
  *@retval None
  */
void Lcd128x64OpenDisplay(void)
{
	Lcd128x64WriteCommand(0xAF);
}

/**
  *@brief 关显示
  *@param  None
  *@retval None
  */
void Lcd128x64CloseDisplay(void)
{
    Lcd128x64WriteCommand(0xAE);
}



/* END */
