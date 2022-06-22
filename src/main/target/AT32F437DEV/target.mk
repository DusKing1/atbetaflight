AT32F43xxMT7_TARGETS += $(TARGET)

CUSTOM_DEFAULTS_EXTENDED = yes
FEATURES       +=  VCP ONBOARDFLASH

TARGET_SRC = \
			drivers/accgyro/accgyro_mpu6500.c \
            drivers/accgyro/accgyro_spi_icm20689.c\
            drivers/barometer/barometer_bmp280.c \
            drivers/accgyro/accgyro_spi_mpu6000.c \
            drivers/accgyro/accgyro_spi_mpu6500.c\
            drivers/max7456.c \
            drivers/vtx_rtc6705.c \
            drivers/vtx_rtc6705_soft_spi.c \
            drivers/rx/expresslrs_driver.c \
            drivers/rx/rx_sx127x.c \
            drivers/rx/rx_sx1280.c \
            rx/expresslrs_telemetry.c \
            rx/expresslrs_common.c \
            rx/expresslrs.c

