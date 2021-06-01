An FT-891 CAT Control Emulator Library by WA2FZW
Version 1.2

This library provides a means of adding CAT (Computer Aided Transceiver)
functionality to Arduino (or other microprocessor) based applications.

I have used it in an ESP32 based digital VFO and my simple interface for
digital audio, which runs on an Arduino Nano. It should work on almost any
of the popular microprocessors.

This was originally developed for a digital VFO project by me, Glenn (VK3PE)
and Jim (G3ZQC).

Modified in Version 1.1 (9/26/2019) to allow the library to optionally handle
transmit/receive switching optionally.

Modified in Version 1.2 (11/22/2020) to change the return type of the GetTX method from
bool to uint8_t so one can tell if the transmitter is on due to manual control
or CAT control.


Update 01/04/2020 - Somehow the change of the return type of the GetTX function
never got changed in the header file. It is now fixed.

Update 06/01/2021 - Fixed a bug in the handling of the "IF', "OI" amd "MD"
status requests. The mode was not bsing handled properly if it was greater
than 9. Thanks to Dick MacDonald for finding the problem!
