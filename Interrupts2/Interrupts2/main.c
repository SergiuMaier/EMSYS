/*
 * Interrupts2.c
 *
 * Created: 8/17/2022 3:43:39 PM
 * Author : Maier Sergiu
 */ 
#define F_CPU 16000000UL

#define PORT_LED0	PORTD
#define PIN_LED0	PIND0
#define PORT_LED1	PORTD
#define PIN_LED1	PIND1
#define PORT_LED2	PORTD
#define PIN_LED2	PIND2
#define PORT_LED3	PORTD
#define PIN_LED3	PINB3

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void pinSet(volatile uint8_t *port, uint8_t pin);
void pinReset(volatile uint8_t *port, uint8_t pin);

int flag = 0; //Initially, all 4 LEDs will be powered-on

int main(void)
{
	//Output for LEDs
	DDRB = 0x0F;
	//DDRB |= (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3);  
	PORTB = 0x00; 
	
	DDRD |= (0 << 2) | (0 << 3);  
	//SREG |= (1 << SREG_I);
	sei();
	
	MCUCR |= (1 << IVCE);
	EICRA |= (1 << ISC11) | (1 << ISC10) | (1 << ISC01) | (1 << ISC00);
	EIMSK |= (1 << INT1) | (1 << INT0);
	EIFR |= (0 << INTF1) | (0 << INTF0);
	PCICR |= (0 << PCIE2) | (0 << PCIE1) | (0 << PCIE0);
			
    while (1) 
    { 
		//pinSet(&PORT_LED0, PIN_LED0);
		//pinSet(&PORT_LED1, PIN_LED1);
		//pinSet(&PORT_LED2, PIN_LED2);
		//pinSet(&PORT_LED3, PIN_LED3);
		//_delay_ms(1000);
		//pinReset(&PORT_LED0, PIN_LED0);
		//pinReset(&PORT_LED1, PIN_LED1);
		//pinReset(&PORT_LED2, PIN_LED2);
		//pinReset(&PORT_LED3, PIN_LED3);
		//_delay_ms(1000);
    }
}

void pinSet(volatile uint8_t *port, uint8_t pin){
	*port |=  1 << pin;
}

void pinReset(volatile uint8_t *port, uint8_t pin){
	*port &=  ~(1 << pin);
}

ISR(INT0_vect) {
	
	cli();
	//SREG &= ~(1 << SREG_I);
	//flag = 1;
	if(( PORTB & ( (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3) ) ) != 0) //HIGH -> LOW
	{
			pinReset(&PORT_LED0, PIN_LED0);
			pinReset(&PORT_LED1, PIN_LED1);
			pinReset(&PORT_LED2, PIN_LED2);
			pinReset(&PORT_LED3, PIN_LED3);
	}
	sei();	
	//SREG |= (1 << SREG_I);
}

ISR(INT1_vect) {
	
	cli();
	//SREG &= ~(1 << SREG_I);
	//flag = !flag;
	if((PORTB & ( (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3) ) ) == 0) //LOW -> HIGH
	{
			pinSet(&PORT_LED0, PIN_LED0);
			pinSet(&PORT_LED1, PIN_LED1);
			pinSet(&PORT_LED2, PIN_LED2);
			pinSet(&PORT_LED3, PIN_LED3);
	}
		
	sei();			
	//SREG |= (1 << SREG_I);
}
