#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Estructura para instanciar un GPIO
 *
 * gpio_t Puntero a una estructura anonima que representa un GPIO
 *
 */

typedef struct gpio_s * gpio_t;

/**
 * @brief Permite crear una instancia de un GPIO
 *
 * @param puerto Puerto del GPIO
 * @param bit Pin del GPIO
 * @return gpio_t Puntero al objeto GPIO creado
 *
 */

gpio_t gpioCreate(uint8_t puerto, uint8_t bit);

/**
 * @brief Configura el GPIO como Input o Output
 *
 * @param gpio Puntero a la estructura anonima del GPIO
 * @param output true para Output, false para Input
 */

void gpioSetOutput(gpio_t gpio, bool output);

/**
 * @brief Envia el estado del GPIO cuando esta configurado como Output
 *
 * @param gpio Puntero a la estructura anonima del GPIO
 * @param state true para HIGH, false para LOW
 */

void gpioSetState(gpio_t gpio, bool state);

/**
 * @brief Retorna el estado del GPIO
 *
 * @param gpio Puntero a la estructura anonima del GPIO
 * @return true GPIO en estado HIGH
 * @return false GPIO en estado LOW
 */

bool gpioGetState(gpio_t gpio);

#endif /* GPIO_H */