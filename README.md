# PeerToPeerEnergyTrading

1. Hardware: ESP32
2. Language: C++

## How to run
Click upload button on VS code while pressing Boot button on ESP32

## Pin Connection Details
1. Solar Panel: Pin GPIO 34


## Introducing 2.8in SPI LCD Touchscreen ILI9341

* In platform IO, VS code --> go to libraries --> search for "tft_espi"

* Install TFT_eSPI by Bodmer library.

* Go to installation folder from VS code "Reveal" option.
	"E:\MyProjects\PeerToPeerEnergyTrading\.pio\libdeps\nodemcu-32s\TFT_eSPI"

TFT				esp32
---------------------------
D2				D26
D3				D25
D4				(17) TX2


D5				(16) RX2

D6				D27

D7				D14

D0				D12

D1				D13

RST 			D32

CS				D33

RS (OR DC)		D15

WR				D4

RD				D2
3.3V 			3.3V
GND 			GND




* Go to installation folder from VS code "Reveal" option.
	"E:\MyProjects\PeerToPeerEnergyTrading\.pio\libdeps\nodemcu-32s\TFT_eSPI"

* Go inside the file: User_Setup_Select.h

	and comment the line "#include <User_Setup.h>           // Default setup is root library folder"


	and uncomment the line; "//#include <Setup14_ILI9341_Parallel.h>   "


