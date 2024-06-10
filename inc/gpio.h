#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>
#include <stdbool.h>

// void gpioSetDirection(uint8_t puerto, uint8_t bit, bool salida);
// void gpioSetOutput(uint8_t puerto, uint8_t bit, bool estado);
// bool gpioSetInput(uint8_t puerto, uint8_t bit);

typedef struct gpio_s * gpio_t;


// Creacion devuelve ese puntero
gpio_t gpioCreate(uint8_t puerto, uint8_t bit);

//puntero sobre el que quiero operar 
void  gpioSetOutput(gpio_t gpio, bool output);

gpio_t gpioSetState(gpio_t gpio, bool state);

gpio_t gpioGetState(gpio_t gpio);

#endif /* GPIO_H */