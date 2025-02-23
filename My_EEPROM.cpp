#include "My_EEPROM.h"
#include <avr/io.h>
#include <util/delay.h>

My_EEPROM::My_EEPROM() {
}

template <typename T>
void My_EEPROM::write(int address, const T &value) {
    const uint8_t *ptr = (const uint8_t *)&value;
    for (size_t i = 0; i < sizeof(T); i++) {
        while (EECR & (1 << EEPE));
        EEAR = address + i;
        EEDR = ptr[i];
        EECR |= (1 << EEMPE);
        EECR |= (1 << EEPE);
    }
}

template <typename T>
void My_EEPROM::read(int address, T &value) {
    uint8_t *ptr = (uint8_t *)&value;
    for (size_t i = 0; i < sizeof(T); i++) {
        while (EECR & (1 << EEPE));
        EEAR = address + i;
        EECR |= (1 << EERE);
        ptr[i] = EEDR;
    }
}

void My_EEPROM::writeString(int address, const String &value) {
    for (size_t i = 0; i < value.length(); i++) {
        write(address + i, value[i]);
    }
    write(address + value.length(), '\0');
}

String My_EEPROM::readString(int address, size_t maxLen) {
    char buffer[maxLen + 1];
    for (size_t i = 0; i < maxLen; i++) {
        read(address + i, buffer[i]);
        if (buffer[i] == '\0') break;
    }
    buffer[maxLen] = '\0';
    return String(buffer);
}

void My_EEPROM::clear() {
    for (int i = 0; i < 1024; i++) {
        write(i, (uint8_t)0);
    }
}

