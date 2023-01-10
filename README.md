# GM LIN BUS
Using Arduino to interact with **2021 Corvette C8** LIN BUS

In this project we will be using Arduino UNO R3 and Mikroe MIKROE-3816 LIN Click board.  We will read and write LIN BUS between ECU and MAF sensor which contains Intake Air Temperature and Barometric Pressure sensor.

LIN Click board is configured to **5V** slave mode and jumper is set between 5V and EN pins (always enabled).  Not using any wake functionality.

GM uses bound rate of **10.417** . It is very important to set your serial communication bound rate from Arduino to LIN device to specified bound rate.  Otherwise, all data you record or send, will be useless.

**Sniffer.ino**
Gathers data from LIN BUS and writes it to SD card.


Data Explained.

Example:
**0, 55, 2b, 4b, cc, 4b, fc, 74,**

First 3 values are sent by **Master**

**0**  -> Break Field

**55** -> Sync Field

**2b** -> Protected Identified - In this case, its asking for Intake Air Tempterature


Next 4 bits are data from **Slave** followed by checksum(8th/last bit).
