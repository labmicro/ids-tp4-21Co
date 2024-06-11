/**
 * @file: gpio.c
 * @brief Codigo fuente gpio.c
 *
 */

/* === Headers files inclusions =============================================================== */
#include "gpio.h"
#include <stddef.h>

/* === Public macros definitions =============================================================== */
#ifndef GPIO_MAX_INSTANCES
#define GPIO_MAX_INSTANCES 10
#endif

/* === Private data type definition ========================================================== */
struct gpio_s {
    uint8_t port;
    uint8_t bit;
    bool output;
    bool state;
    bool used;
};

/* === Private function definition ============================================================ */
/**
 * @brief Funcion privada para crear una instancia sin el uso de memoria dinamica
 *
 * @return gpio_t
 */
static gpio_t allocateInstance() {
    static struct gpio_s instances[GPIO_MAX_INSTANCES] = {0};

    gpio_t result = NULL;
    for (int index = 0; index < GPIO_MAX_INSTANCES; index++) {
        if (!instances[index].used) {
            result = &instances[index].used;
            result->used = true;
            break;
        }
    }
    return result;
}

/* === Public function definition ============================================================ */
gpio_t gpioCreate(uint8_t puerto, uint8_t bit) {
#ifdef USE_DYNAMIC_MEM
    gpio_t self = malloc(sizeof(struct gpio_s));
#else
    gpio_t self = allocateInstance();
#endif
    if (self) {
        self->port = puerto;
        self->bit = bit;
        self->output = false;
    }
    return self;
}

void gpioSetOutput(gpio_t gpio, bool output) {
    gpio->output = output;
    HAL_GPIO_SET_OUTPUT(gpio->port, gpio->bit);
}

void gpioSetState(gpio_t gpio, bool state) {
    if (gpio->output) {
        HAL_GPIO_SET_STATE(gpio->port, gpio->state);
    }
}

bool gpioGetState(gpio_t gpio) {
    return HAL_GPIO_GET_STATE(gpio->port, gpio->bit);
}
