#include <stdint.h>
#define POINT_LATITUDE_ADDR 0x10 // Example address for latitude data in EEPROM
#define POINT_LONGITUDE_ADDR 0x14 // Example address for longitude data in EEPROM

// Function to save latitude and longitude to EEPROM
void savePointToEEPROM(uint32_t latitude, uint32_t longitude) {
    // Write latitude and longitude to EEPROM
    EEPROMProgram(&latitude, POINT_LATITUDE_ADDR, sizeof(uint32_t));
    EEPROMProgram(&longitude, POINT_LONGITUDE_ADDR, sizeof(uint32_t));
}
