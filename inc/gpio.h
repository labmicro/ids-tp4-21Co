
#ifndef GPIO_H
#define GPIO_H_

/**
 * @file gpio.h
 * @author Blanco Miguel Manuel (miguelmanuelblanco@gmail.com)
 * @brief API para comandar GPIOs
 */
/* === Headers files inclusions ================================================================ */
#include <stdint.h>
#include <stdbool.h>
/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */

/* === Public data type declarations =========================================================== */
typedef struct gpio_s * gpio_t; // puntero a estructura anonima

/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */
/**
 * @brief Construtor instancia de gpio
 *
 * @param puerto Puerto de 8bit a usar
 * @param bit Pin de gpio a usar
 * @return gpio_t
 */
gpio_t gpioCreate(uint8_t puerto, uint8_t bit);

/**
 * @brief Configura la instancia del gpio como entrada o salida.
 *
 * @param gpio Instancia de gpio sobre la que se trabaja.
 * @param output Estado deseado para el gpio.
 */
void gpioSetOutput(gpio_t gpio, bool output);

/**
 * @brief Setea el estado de un pin, de una instancia configurada como salida.
 *
 * @param gpio Instancia de gpio sobre la que se trabaja
 * @param state Estado deseado para el pin
 */
void gpioSetState(gpio_t gpio, bool state);

/**
 * @brief Lee el estado de una instancia configurada como entrada
 *
 * @param gpio Instancia de gpio sobre la que se trabaja
 * @return true - se lee un estado altoasdfasdfasfd
 * @return false - se lee un estado bajo
 */
bool gpioGetState(gpio_t gpio);

/* === End of documentation ==================================================================== */
#ifdef __cplusplus
}
#endif

#endif
