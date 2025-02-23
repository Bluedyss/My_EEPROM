# My_EEPROM Library for Arduino

## Overview
My_EEPROM is a lightweight library for reading and writing various data types to the internal EEPROM of AVR-based Arduino boards. It does not use the built-in `EEPROM.h` library but directly manipulates EEPROM registers.

## Features
- Read and write various data types:
  - `bool`
  - `char`
  - `int16_t`, `int32_t`
  - `uint64_t`
  - `float`, `double`
  - `String`
- Clear EEPROM
- Uses direct register access for optimized performance

## Installation
1. Copy `My_EEPROM.h` and `My_EEPROM.cpp` to your Arduino project folder.
2. Include the header file in your sketch:
   ```cpp
   #include "My_EEPROM.h"
   ```

## Usage
### Initialize EEPROM
```cpp
My_EEPROM eprom;
```

### Writing Data
```cpp
int addr = 0;
bool value = true;
eprom.write(addr, value);
```

### Reading Data
```cpp
bool readValue;
eprom.read(addr, readValue);
Serial.println(readValue);
```

### Writing and Reading Strings
```cpp
eprom.writeString(10, "Hello EEPROM");
Serial.println(eprom.readString(10, 20));
```

### Clearing EEPROM
```cpp
eprom.clear();
```

## Example
See `example.ino` for a full demonstration of how to use the library.

## License
This library is released under the MIT License.

