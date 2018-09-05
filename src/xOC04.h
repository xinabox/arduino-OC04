/*
	This is a library for the OC04
	Relay Out High Voltage

	The board uses I2C for communication.
	The board communicates with the following I2C device:
	* 	PCA9554A
	
	Data Sheets:
	PCA9554A - http://www.ti.com/lit/ds/symlink/pca9554a.pdf
*/

#ifndef xOC04_h
#define xOC04_h

// Include File Headers
#include "xCore.h"

// PCA9536 Register Definitions
#define PCA9554A_REG_INPUT_PORT		0x00
#define PCA9554A_REG_OUTPUT_PORT	0x01	
#define PCA9554A_REG_POL_INVERSION	0x02
#define PCA9554A_REG_CONFIG			0x03

#define PCA9554A_CONF_OUTPUT		0x00
#define PCA9554A_CONF_INPUT			0xFF

#define PCA9554A_ALL_OUTPUTS_OFF	0x00

/********************************************************************/

class xOC04: public xCoreClass
{
	public:
		/**
		* Constructor
		* Creates a new instance of Sensor class.
		*/		
		xOC04();
		xOC04(uint8_t addr);
		
		/*
		* Runs the setup of the sensor. 
		* Call this in setup(), before reading any sensor data.
		*
		* @return true if setup was successful.
		*/		
		bool begin(void);

		/*
		* Runs the setup of the sensor. 
		* Call this in setup(), before reading any sensor data.
		*
		* @param state, allows users to configure specific pins 
		* to be high on start up.
		*
		* @return true if setup was successful.
		*/	
		bool begin(bool state);		
		
		/*
		* Used to write to the pin. HIGH or LOW. 
		* Call this in loop().
		*
		* @param state. State which you would like to write to the output pin.
		* @return none
		*/			
		void write(bool state);

		/*
		* Used to determine the status of Output Pins 
		* Call this in loop().
		*
		* @return status of bytes
		*/
		uint8_t getStatus(void);
		
	private:
		// PCA9536 Device I2C Address
		uint8_t PCA9554A_I2C_ADDRESS;
};

#endif
