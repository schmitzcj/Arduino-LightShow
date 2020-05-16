# Arduino-LightShow

### Parts used
* x1 Arduino Nano 
* x6 Ethernet cables 7ft
* x6 Sparkfun RJ45 breakouts
* x6 Aluminum channels for LED strips 3.3ft
* x6 Strip Pigtail Connector (4-pin)
* x6 WS2813 60LED strips @ 12v
* x1 LED Driver 150W @ 12v
* x2 Ground terminal bus
* x3 2-terminal breadboard terminal blocks


### Instructions
#### LED Strips
* Cut one end of the ethernet cables
* Solder one twisted pair per LED lead (Should be four total leads). Remember what twisted pair belongs to what lead
* Using the female pigtail connector, solder one pig tail wire per two RJ45 leads. Remeber which ones are Data, 12v, and GND

#### Power
* Connect the positive wire from the driver to one terminal bus, and the negative to the other remember the polarities
* Using the male pigtail connector, connect the 12v wire to the positive terminal bus. Connect the GND wire to the negative terminal bus

#### Breadboard
* On a breadboad, place the Nano and the terminal blocks, make sure that the terminal blocks connect to Digital pins
* Fasten the Data wires to the terminal blocks
* Connect the Nano VIN to the 12v terminal bus
* Connect the Nano GND to the GND terminal bus

#### Code
* DO NOT have the driver plugged in at this time
* Using the Arduino IDE, open the file and verify that the Data pins are correct and make changes as necessary
* Push your changes to the Nano and unplug it from the computer
* Plug in the driver
