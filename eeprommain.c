#include "eeprom.c"


int main(void) {
   
    // Initialize EEPROM
    EEPROMInit()
      

          // Save latitude to EEPROM (block number 0, address 0)
        eeprom_write(*(uint32_t*)&latitude, 0, 0);

        // Save longitude to EEPROM (block number 0, address 4)
        eeprom_write(*(uint32_t*)&longitude, 0, 4);

      
    
}