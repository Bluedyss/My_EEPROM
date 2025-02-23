#ifndef MY_EEPROM_H
#define MY_EEPROM_H

#include <Arduino.h>

class My_EEPROM {
public:
    My_EEPROM();
    template <typename T>
    void write(int address, const T &value);
    template <typename T>
    void read(int address, T &value);
    void writeString(int address, const String &value);
    String readString(int address, size_t maxLen);
    void clear();
};

#endif
