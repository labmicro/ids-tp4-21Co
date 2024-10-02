/**
 * @file leds.h
 * @author Edilberto Carvajal
 * @date 26/09/2024
 *
 * @brief Archivo de cabecera biblioteca leds
 */

#ifndef LEDS_H
#define LEDS_H

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Inicializa el puerto y apaga todos los LEDs
 *
 * @param direccion
 * @return true
 * @return false
 */
bool LedsCreate(uint16_t * direccion);

/**
 * @brief Enciende un LED
 *
 * @param led
 * @return true
 * @return false
 */
bool LedsSetOn(int led);

/**
 * @brief apaga un LED
 *
 * @param led
 * @return true
 * @return false
 */
bool LedsSetOff(int led);

/**
 * @brief Enciende todos los LEDs
 *
 */
void AllLedsSetOn(void);

/**
 * @brief Apaga todos los LEDs
 *
 */
void AllLedsSetOff(void);

/**
 * @brief Consulta si un LED está prendido
 *
 * @param led
 * @return true
 * @return false
 */
bool LedIsOn(int led);

/**
 * @brief Consulta si un LED está apagado
 *
 * @param led
 * @return true
 * @return false
 */
bool LedIsOff(int led);

#endif // LEDS_H
