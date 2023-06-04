# HMI-Para-Multiparrila

Compilar el proyecto con esta configuración:

[env:esp32doit-devkit-v1]
monitor_speed = 115200
platform = espressif32
board = esp32doit-devkit-v1
framework = arduino
lib_deps = 
	chris--a/Keypad@^3.1.1
	adafruit/Adafruit ILI9341@^1.5.12
	adafruit/Adafruit GFX Library@^1.11.5
	bodmer/TFT_eSPI@^2.5.30
	adafruit/SdFat - Adafruit Fork@^2.2.1
	siktec-lab/SIKTEC_EPD@^1.0.5
	adafruit/Adafruit BusIO@^1.14.1
	adafruit/Adafruit INA219 @ ^1.1.1
	Wire
	siktec-lab/SIKTEC_SRAM@^1.0.2
	SIKTEC_SRAM
	SIKTEC_SPI
	SPI
	FS
	SPIFFS
	regenbogencode/ESPNowW@^1.0.2
