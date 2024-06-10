#include "gpio.h"
#include <stddef.h>

#define USE_DYNAMIC_MEM

#ifndef GPIO_MAX_INSTANCES
#define GPIO_MAX_INSTANCES 10
#endif

/**
 * @brief Atributos de cada objeto GPIO
 *
 */

struct gpio_s {
    uint8_t port;
    uint8_t bit;
    bool output;
    bool used;
};

/**
 * @brief Funcion para validar si hay espacio disponible para instanciar un GPIO
 *
 * @return gpio_t Retorna un puntero a la instancia del GPIO que se puede asignar
 * o NULL si no hay espacio disponible
 */

static gpio_t allocateInstance() {
    static struct gpio_s instances[GPIO_MAX_INSTANCES] = {0};

    gpio_t result = NULL;
    for (int index = 0; index < GPIO_MAX_INSTANCES; index++) {
        if (!instances[index].used) {
            result = &instances[index];
            result->used = true;
            break;
        }
    }
    return result;
}

/**
 * @brief Crea un nuevo objeto GPIO
 *
 * @param puerto Puerto del GPIO
 * @param bit Pin del GPIO
 * @return gpio_t Puntero al objeto GPIO creado
 */

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

/**
 * @brief Configura el GPIO como Input o Output
 *
 * @param gpio Puntero a la estructura anonima del GPIO
 * @param output true para Output, false para Input
 */

void gpioSetOutput(gpio_t self, bool output) {
    self->output = output;
    HAL_GPIO_SET_OUTPUT(self->port, self->bit);
}

/**
 * @brief Envia el estado del GPIO cuando esta configurado como Output
 *
 * @param gpio Puntero a la estructura anonima del GPIO
 * @param state true para HIGH, false para LOW
 */

void gpioSetState(gpio_t self, bool output) {
    if (self->output) {
        HAL_GPIO_SET_STATE(self->port, self->bit);
    }
}

/**
 * @brief Retorna el estado del GPIO
 *
 * @param gpio Puntero a la estructura anonima del GPIO
 * @return true GPIO en estado HIGH
 * @return false GPIO en estado LOW
 */

bool gpioGetState(gpio_t self) {
    return HAL_GPIO_GET_STATE(self->port, self->bit);
}