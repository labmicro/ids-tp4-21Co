#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>
#include <stdbool.h>

/**
 * @file gpio.h
 * @brief Estructura anonima para instanciar un GPIO
 *
 * gpio_t Puntero a una estructura anonima que representa o hace referencia a un gpio
 *
 */
typedef struct gpio_s * gpio_t;

/**
 * @brief Funcion que crea un objeto GPIO
 *
 * @param puerto Puerto del GPIO
 * @param bit Pin del GPIO
 * @return gpio_t Puntero al objeto GPIO creado
 *
 */
gpio_t gpioCreate(uint8_t puerto, uint8_t bit);

/**
 * @brief Configura al GPIO como entrada o salida
 *
 * @param gpio Puntero a la estructura anonima del GPIO
 * @param output true para output y false para input
 */
void gpioSetOutput(gpio_t gpio, bool output);

/**
 * @brief Envia el estado del GPIO
 *
 * @param gpio Puntero a la estructura anonima del GPIO
 * @param state true para HIGH y false para LOW
 */
void gpioSetState(gpio_t gpio, bool state);

/**
 * @brief Recive o lee el estado del GPIO
 *
 * @param gpio Puntero a la estructura anonima del GPIO
 * @return true GPIO en estado HIGH y false GPIO en estado LOW
 */
bool gpioGetState(gpio_t gpio);

#endif /* GPIO_H */
