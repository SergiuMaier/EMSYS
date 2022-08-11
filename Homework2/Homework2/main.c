/*
 * Homework2.c
 *
 * Created: 8/3/2022 2:55:55 PM
 * Author : Sergiu
 */ 
#define F_CPU 16000000UL
//#define INITIAL_DELAY 40000UL

#define PORT_LED0	PORTD
#define PIN_LED0	PIND4
#define PORT_LED1	PORTD
#define PIN_LED1	PIND5
#define PORT_LED2	PORTD
#define PIN_LED2	PIND6
#define PORT_LED3	PORTD
#define PIN_LED3	PIND7
#define PORT_LED4	PORTB
#define PIN_LED4	PINB0
#define PORT_LED5	PORTB
#define PIN_LED5	PINB1
#define PORT_LED6	PORTB
#define PIN_LED6	PINB2
#define PORT_LED7	PORTB
#define PIN_LED7	PINB3
#define PORT_LED8	PORTB
#define PIN_LED8	PINB4
#define PORT_LED9	PORTB
#define PIN_LED9	PINB5	//This also corresponds to the onboard LED

#include <avr/io.h>
#include <util/delay.h>

uint32_t delay;

void basic_delay(uint32_t interations);
void pinToggle(volatile uint8_t *port, uint8_t pin);
void pinSet(volatile uint8_t *port, uint8_t pin);
void pinReset(volatile uint8_t *port, uint8_t pin);

int main(void)
{
	//Initialize data
	delay = INITIAL_DELAY;
	
	//Initialize peripherals. Set all ports as outputs
	DDRB = 0xFF;
	DDRC = 0x3F;
	DDRD = 0xFF;

	//Set the output value of the ports to low
	PORTB = 0x00;
	PORTC = 0x00;
	PORTD = 0x00;

	//Main loop of the application.
	do{
		
		//From left to right
		pinSet(&PORT_LED0, PIN_LED0);  //A from the image
		pinSet(&PORT_LED1, PIN_LED1);
		_delay_ms(500);
		
		pinReset(&PORT_LED0, PIN_LED0);//B
		pinSet(&PORT_LED2, PIN_LED2);
		_delay_ms(500);
		
		pinReset(&PORT_LED1, PIN_LED1);//C
		pinSet(&PORT_LED3, PIN_LED3);
		_delay_ms(500);
		
		pinReset(&PORT_LED2, PIN_LED2);//D
		pinSet(&PORT_LED4, PIN_LED4);
		_delay_ms(500);
		
		pinReset(&PORT_LED3, PIN_LED3);//E
		pinSet(&PORT_LED5, PIN_LED5);
		_delay_ms(500);
		
		pinReset(&PORT_LED4, PIN_LED4);//F
		pinSet(&PORT_LED6, PIN_LED6);
		_delay_ms(500);
		
		pinReset(&PORT_LED5, PIN_LED5);//G
		pinSet(&PORT_LED7, PIN_LED7);
		_delay_ms(500);
		
		pinReset(&PORT_LED6, PIN_LED6);//H
		pinSet(&PORT_LED8, PIN_LED8);
		_delay_ms(500);
		
		pinReset(&PORT_LED7, PIN_LED7);//I
		pinSet(&PORT_LED9, PIN_LED9);
		_delay_ms(500);
		
		pinReset(&PORT_LED8, PIN_LED8);//J
		_delay_ms(500);
		
		//From right to left
		pinSet(&PORT_LED8, PIN_LED8);//I
		_delay_ms(500);
		
		pinReset(&PORT_LED9, PIN_LED9);//H
		pinSet(&PORT_LED7, PIN_LED7);
		_delay_ms(500);
		
		pinReset(&PORT_LED8, PIN_LED8);//G
		pinSet(&PORT_LED6, PIN_LED6);
		_delay_ms(500);
		
		pinReset(&PORT_LED7, PIN_LED7);//F
		pinSet(&PORT_LED5, PIN_LED5);
		_delay_ms(500);
		
		pinReset(&PORT_LED6, PIN_LED6);//E
		pinSet(&PORT_LED4, PIN_LED4);
		_delay_ms(500);
		
		pinReset(&PORT_LED5, PIN_LED5);//D
		pinSet(&PORT_LED3, PIN_LED3);
		_delay_ms(500);
		
		pinReset(&PORT_LED4, PIN_LED4);//C
		pinSet(&PORT_LED2, PIN_LED2);
		_delay_ms(500);
		
		pinReset(&PORT_LED3, PIN_LED3);//B
		pinSet(&PORT_LED1, PIN_LED1);
		_delay_ms(500);
		
		pinReset(&PORT_LED2, PIN_LED2);//A
		pinSet(&PORT_LED0, PIN_LED0);
		_delay_ms(500);
		
		pinReset(&PORT_LED1, PIN_LED1);//0
		_delay_ms(500);
	}
	while(1);
}

void basic_delay(uint32_t interations){
	do{
		interations--;
	}
	while(interations>0);
}

void pinToggle(volatile uint8_t *port, uint8_t pin){
	*port ^=  1 << pin;
}

void pinSet(volatile uint8_t *port, uint8_t pin){
	*port |=  1 << pin;
}

void pinReset(volatile uint8_t *port, uint8_t pin){
	*port &=  ~(1 << pin);
}