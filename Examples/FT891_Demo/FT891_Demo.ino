/*
 *	FT891_Demo
 *
 *		A simple program to demonstrate the use of the "FT891_CAT" library.
 *
 *		Using the Arduino IDE's serial monitor you can send any of the
 *		commands or status requests supported by the library. Sending
 *		"TX1;" and "TX0;" messages will turn the Arduino's built-in LED
 *		on or off.
 *
 *		This will work on any of the more common Arduinos (Uno, Nano, 
 *		Mega, etc.) as well as on an ESP32.
 */

#include <FT891_CAT.h>					// FT891 Cat control library

#define	BIT_RATE	115200				// Baud setting for the USB port


/*
 *	The only pins used are D4, which keys the transmitter PTT line via a solid
 *	state relay and D13 which turns the LED on the Arduino board on or off.	
 */

#define	PTT_PIN	 4						// Push-to-talk line
#define	LED_PIN	13						// The Arduino's built in LED


/*
 *	These definitions are for the on/off state of the LED
 */

#define	LED_ON	HIGH					// HIGH turns the LED on
#define	LED_OFF	LOW						// So LOW must turn it off!


	FT891_CAT	CAT;					// Make the CAT control object


/*
 *	"setup" initializes everything the rest of the program needs to function properly
 */

void setup ()
{

/*
 *	Set up the LED:
 */

	pinMode ( LED_PIN, OUTPUT );				// Turns the Arduino's built-in LED on or off
	digitalWrite ( LED_PIN, LED_OFF );			// Turn the LED off


/*
 *	Start the serial monitor
 */

	Serial.begin ( BIT_RATE );					// Serial monitor runs at high speed


/*
 * 	Startup the CAT library. Note, I have used the optional 2nd argument which
 * 	will cause a newline character to be appended to received messages.
 */

	CAT.begin ( PTT_PIN, true );
}


/*
 *	The loop processing is pretty trivial. We see if DxCommander has anything to say,
 *	and if so, we read it and process it.
 */

void loop ()
{
	if ( CAT.CheckCAT() )							// If any new commands
	{
		if ( CAT.GetTX() )							// Transmitter on?
			digitalWrite ( LED_PIN, LED_ON );		// Light the LED

		else										// Receiving
			digitalWrite ( LED_PIN, LED_OFF );		// So turn the LED off
	}

	Delay ( 25 );									// Only check every 25mS
}


/*
 *	"Delay" is a non-blocking delay function. The standard Arduino "delay" function
 *	turns off interrupts, which prevents the Serial I/O functions from working. That
 *	sometimes causes characters to be missed and junk commands to show up.
 */

void Delay ( unsigned long interval )
{
unsigned long currentTime = 0UL;

unsigned long startTime = millis();

	while ( startTime + interval > currentTime )
    	currentTime = millis();
}
