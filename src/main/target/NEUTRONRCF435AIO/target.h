/*
 * This file is part of Cleanflight and Betaflight.
 *
 * Cleanflight and Betaflight are free software. You can redistribute
 * this software and/or modify this software under the terms of the
 * GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * Cleanflight and Betaflight are distributed in the hope that they
 * will be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software.
 *
 * If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define TARGET_BOARD_IDENTIFIER "NEUTRONRCF435AIO"
#define USBD_PRODUCT_STRING     "NERC"
/**********swd debuger reserved *****************
 *
 * pa13	swdio
 * pa14 swclk
 * PA15	JTDI
 * PB4 JREST
 * pb3 swo /DTO
 *
 * other pin
 *
 * BOOT0 button
 * PA8  MCO1
 * PA12 OTG1 D+ DP
 * PA11 OTG1 D- DM
 * PH0 HEXT IN
 * PH1 HEXT OUT
 */

//No Buttons

//LEDS
#define LED1_PIN                PC4 //confirm on LQFP64

#define USE_BEEPER
#define BEEPER_PIN              PC15
#define BEEPER_INVERTED		 //低电平触发

//ESC Protocol

#define ENABLE_DSHOT_DMAR       DSHOT_DMAR_AUTO
#define DSHOT_BITBANG_DEFAULT   DSHOT_BITBANG_AUTO

// *************** SPI **********************
#define USE_SPI
#define USE_SPI_DEVICE_1

#define SPI1_SCK_PIN            PA5
#define SPI1_MISO_PIN           PA6
#define SPI1_MOSI_PIN           PA7
#define SPI1_NSS_PIN            PA15

#define USE_SPI_DEVICE_2
#define SPI2_SCK_PIN            PB13
#define SPI2_MISO_PIN           PB14
#define SPI2_MOSI_PIN           PB15
#define SPI2_NSS_PIN            PB12

#define USE_SPI_DEVICE_3
#define SPI3_SCK_PIN            PB3
#define SPI3_MISO_PIN           PB4
#define SPI3_MOSI_PIN           PB5
#define SPI3_NSS_PIN 			PB9

// *************** Gyro & ACC **********************

#define USE_EXTI
#define USE_GYRO_EXTI
#define GYRO_1_EXTI_PIN        PA8
#define USE_MPU_DATA_READY_SIGNAL
#define ENSURE_MPU_DATA_READY_IS_LOW

#define GYRO_1_CS_PIN          SPI1_NSS_PIN
#define GYRO_1_SPI_INSTANCE    SPI1
#define GYRO_1_ALIGN           CW270_DEG


#define USE_GYRO
#define USE_GYRO_SPI_MPU6500  //debug only
#define USE_ACC_SPI_MPU6500		//debug only
#define USE_GYRO_SPI_ICM42688P
#define USE_ACCGYRO_BMI270
#define USE_ACCGYRO_LSM6DSO

#define USE_ACC
#define USE_ACC_SPI_ICM42688P


// *************** OSD *****************************
//USE SPI3 ON AT-START BOARD ,USE SPI2 ON LQFP64
#define USE_MAX7456
#define MAX7456_SPI_INSTANCE    SPI2
#define MAX7456_SPI_CS_PIN      SPI2_NSS_PIN

/********************BLACKBOX***********************/
#define ENABLE_BLACKBOX_LOGGING_ON_SPIFLASH_BY_DEFAULT
#define USE_FLASHFS
#define USE_FLASH_M25P16
#define USE_FLASH_W25N01G          // 1Gb NAND flash support
#define USE_FLASH_W25M             // Stacked die support
#define USE_FLASH_W25M512          // 512Kb (256Kb x 2 stacked) NOR flash support
#define USE_FLASH_W25M02G          // 2Gb (1Gb x 2 stacked) NAND flash support
#define FLASH_SPI_INSTANCE      SPI3
#define FLASH_CS_PIN            SPI3_NSS_PIN



// *************** Baro **************************
#define USE_I2C
#define USE_I2C_DEVICE_2
#define I2C_DEVICE              (I2CDEV_2)
#define I2C2_SCL                PB10        // SCL pad
#define I2C2_SDA                PB11        // SDA pad
#define USE_I2C_PULLUP

#define USE_BARO
#define USE_BARO_BMP280
#define USE_BARO_DPS310
#define BARO_I2C_INSTANCE       (I2CDEV_2)

#define USE_MAG
#define USE_MAG_HMC5883
#define USE_MAG_QMC5883
#define MAG_I2C_INSTANCE        (I2CDEV_2)


// *************** UART & Serial ******************
#define USE_VCP

#define USE_UART1
#define UART1_RX_PIN            PA10
#define UART1_TX_PIN            PA9

#define USE_UART2
#define UART2_RX_PIN            PA3
#define UART2_TX_PIN            PA2

#define USE_UART3
#define UART3_RX_PIN            PB11
#define UART3_TX_PIN            PB10

#define USE_UART4
#define UART4_RX_PIN            PC11
#define UART4_TX_PIN            PC10

//uart5 与i2c 复用，如果启用uart5 需要关闭i2c 的所有设备
#define USE_UART5
#define UART5_RX_PIN            PD2
#define UART5_TX_PIN            PC12

//#define USE_SOFTSERIAL1
//#define USE_SOFTSERIAL2

#define SERIAL_PORT_COUNT       6 // VCP  UART1 UART2 UART3 UART4 UART5

#define DEFAULT_RX_FEATURE      FEATURE_RX_SERIAL
#define SERIALRX_PROVIDER       SERIALRX_CRSF
#define SERIALRX_UART           SERIAL_PORT_USART2

//*******************CO-Proceseor*******************
#define USE_FUZZY_CO_PROCESSOR
#define CO_PROCESSOR_UART		SERIAL_PORT_UART5
#define CO_PROCESSOR_UART_BAUD	2250000
// #define UART5_TX_DMA_CHANNEL	DMA2_CHANNEL3_BASE
// #define UART5_RX_DMA_CHANNEL	DMA2_CHANNEL4_BASE

// *************** ADC *****************************
#define USE_ADC
#define ADC_INSTANCE         ADC1  // Default added
#define ADC1_DMA_OPT            11  //DMA 2 CH 5

#define VBAT_ADC_PIN            PC2
#define CURRENT_METER_ADC_PIN   PC1
//#define RSSI_ADC_PIN            0

#define USE_ESCSERIAL

#define DEFAULT_FEATURES                (FEATURE_OSD | FEATURE_TELEMETRY | FEATURE_SOFTSERIAL |FEATURE_LED_STRIP )
#define DEFAULT_VOLTAGE_METER_SOURCE    VOLTAGE_METER_ADC
#define DEFAULT_CURRENT_METER_SOURCE    CURRENT_METER_ADC

#define TARGET_IO_PORTA         0xffff
#define TARGET_IO_PORTB         0xffff
#define TARGET_IO_PORTC         0xffff
#define TARGET_IO_PORTD         0xffff
#define TARGET_IO_PORTE         BIT(2)

#define USABLE_TIMER_CHANNEL_COUNT 28
#define USED_TIMERS             ( TIM_N(1) | TIM_N(2) | TIM_N(3) | TIM_N(4) | TIM_N(5) | TIM_N(8) | TIM_N(20) )
