# GM LIN BUS
Using Arduino to interact with **2021 Corvette C8** LIN BUS

In this project we will be using Arduino UNO R3 and Mikroe MIKROE-3816 LIN Click board.  We will read and write LIN BUS between ECU and MAF sensor which contains Intake Air Temperature and Barometric Pressure sensor.

LIN Click board is configured to **5V** slave mode and jumper is set between 5V and EN pins (always enabled).  Not using any wake functionality.

GM uses bound rate of **10.417** . It is very important to set your serial communication bound rate from Arduino to LIN device to specified bound rate.  Otherwise, all data you record or send, will be useless.

