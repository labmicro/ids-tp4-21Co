#include "leds.h"

static uint16_t * leds;

static int Leds_ConvertirNumeroEnBit(int numero_led) {
    return 1 << (numero_led - 1);
}

void Leds_Create(uint16_t * direccion) {
    leds = direccion;
    *leds = 0;
};

void Leds_TurnOn(int led) {
    *leds |= Leds_ConvertirNumeroEnBit(led);
};

void Leds_TurnOff(int led) {
    *leds &= ~Leds_ConvertirNumeroEnBit(led);
};
