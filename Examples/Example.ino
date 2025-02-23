#include "My_EEPROM.h"

My_EEPROM eprom;

void setup() {
    Serial.begin(115200);

   
    int addr = 0;
    Serial.print("Starting address: ");
    Serial.println(addr);
    
    bool b = true;
    eprom.write(addr, b);
    bool readB;
    eprom.read(addr, readB);
    Serial.print("Stored bool at "); Serial.print(addr); Serial.print(": ");
    Serial.println(readB);
    addr += sizeof(bool);
    
    char c = 'A';
    eprom.write(addr, c);
    char readC;
    eprom.read(addr, readC);
    Serial.print("Stored char at "); Serial.print(addr); Serial.print(": ");
    Serial.println(readC);
    addr += sizeof(char);
    
    int16_t i16 = -12345;
    eprom.write(addr, i16);
    int16_t readI16;
    eprom.read(addr, readI16);
    Serial.print("Stored int16_t at "); Serial.print(addr); Serial.print(": ");
    Serial.println(readI16);
    addr += sizeof(int16_t);
    
    int32_t i32 = -123456789;
    eprom.write(addr, i32);
    int32_t readI32;
    eprom.read(addr, readI32);
    Serial.print("Stored int32_t at "); Serial.print(addr); Serial.print(": ");
    Serial.println(readI32);
    addr += sizeof(int32_t);
    
    uint64_t u64 = 1234567890123456789ULL;
    eprom.write(addr, u64);
    uint64_t readU64;
    eprom.read(addr, readU64);
    Serial.print("Stored uint64_t at "); Serial.print(addr); Serial.print(": ");
    Serial.println(readU64);
    addr += sizeof(uint64_t);
    
    float f = 3.1415;
    eprom.write(addr, f);
    float readF;
    eprom.read(addr, readF);
    Serial.print("Stored float at "); Serial.print(addr); Serial.print(": ");
    Serial.println(readF);
    addr += sizeof(float);
    
    double d = 2.7182818284;
    eprom.write(addr, d);
    double readD;
    eprom.read(addr, readD);
    Serial.print("Stored double at "); Serial.print(addr); Serial.print(": ");
    Serial.println(readD);
    addr += sizeof(double);
    
    String str = "Hello EEPROM";
    eprom.writeString(addr, str);
    Serial.print("Stored String at "); Serial.print(addr); Serial.print(": ");
    Serial.println(eprom.readString(addr, 20));
}

void loop() {

}
