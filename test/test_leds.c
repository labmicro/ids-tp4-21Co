/**
 * @file leds.h
 * @author Edilberto Carvajal
 * @date 26/09/2024
 *
 * @brief Archivo de pruebas automatizadas para leds.c
 */

#include "unity.h"
#include "leds.h"

static uint16_t puerto_virtual;

// Se ejecuta antes de cada prueba
void setUp(void) {
    LedsCreate(&puerto_virtual);
}

// Se ejecuta despues de cada prueba
void tearDown(void) {
}

// Con la inicialización todos los LEDs quedan apagados.
void test_todos_los_leds_inician_apagados(void) {
    uint16_t puerto_virtual = 0xFFFF;
    TEST_ASSERT_TRUE(LedsCreate(&puerto_virtual));
    TEST_ASSERT_EQUAL_HEX16(0, puerto_virtual);
}

// Prender un LED individual.
void test_prender_un_led_individual(void) {
    TEST_ASSERT_TRUE(LedsSetOn(3));
    TEST_ASSERT_EQUAL_HEX16(1 << 2, puerto_virtual);
}

// Apagar un LED individual.
void test_prender_y_apagar_un_led_individual(void) {
    TEST_ASSERT_TRUE(LedsSetOn(3));
    TEST_ASSERT_TRUE(LedsSetOff(3));
    TEST_ASSERT_EQUAL_HEX16(0, puerto_virtual);
}

// Prender y apagar múltiples LED’s.
void test_prender_y_apagar_multiples_leds(void) {
    TEST_ASSERT_TRUE(LedsSetOn(7));
    TEST_ASSERT_TRUE(LedsSetOn(5));
    TEST_ASSERT_TRUE(LedsSetOff(2));
    TEST_ASSERT_TRUE(LedsSetOff(7));
    TEST_ASSERT_EQUAL_HEX16(1 << 4, puerto_virtual);
}

// Prender todos los LEDs de una vez.
void test_prender_todos_los_leds_simultaneamente(void) {
    AllLedsSetOn();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, puerto_virtual);
}

// Apagar todos los LEDs de una vez.
void test_apagar_todos_los_leds_simultaneamente(void) {
    AllLedsSetOff();
    TEST_ASSERT_EQUAL_HEX16(0, puerto_virtual);
}

// Consultar el estado de un LED que está encendido
void test_consultar_estado_de_led_encendido(void) {
    TEST_ASSERT_TRUE(LedsSetOn(15));
    TEST_ASSERT_TRUE(LedIsOn(15));
}

// Consultar el estado de un LED que est apagado
void test_consultar_estado_de_led_apagado(void) {
    TEST_ASSERT_TRUE(LedsSetOff(12));
    TEST_ASSERT_TRUE(LedIsOff(12));
}

// Prueba de puerto nulo
void test_puerto_nulo(void) {
    uint16_t puerto_virtual_nulo = NULL;
    TEST_ASSERT_FALSE(LedsCreate(puerto_virtual_nulo));
}

// Revisar limites de los parametros.
void test_limite_de_parametros(void) {
    TEST_ASSERT_TRUE(LedsSetOn(2));
    TEST_ASSERT_TRUE(LedsSetOn(8));
    TEST_ASSERT_TRUE(LedsSetOn(16));

    TEST_ASSERT_TRUE(LedsSetOff(1));
    TEST_ASSERT_TRUE(LedsSetOff(8));
    TEST_ASSERT_TRUE(LedsSetOff(16));
}

// Revisar parámetros fuera de los limites.
void test_parametros_fuera_de_limites(void) {
    TEST_ASSERT_FALSE(LedsSetOn(-1));
    TEST_ASSERT_FALSE(LedsSetOn(0));
    TEST_ASSERT_FALSE(LedsSetOn(18));

    TEST_ASSERT_FALSE(LedsSetOff(-2));
    TEST_ASSERT_FALSE(LedsSetOff(0));
    TEST_ASSERT_FALSE(LedsSetOff(20));
}
