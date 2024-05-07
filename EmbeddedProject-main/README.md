
# EEPROM-Driver-For-Tiva-C-TM4C123G

Driver for using the on-board EEPROM of Tiva C TM4C123G.


## Deployment

Add the files in your project and use the functions declared in the header file.



## Usage/Examples
### Initialization
After initializing the requisite ports call the following function.
```bash
  eeprom_init();
```
### Write to memory
To write to EEPROM you need to provide block number (0 - 31) and address (0 - 15) along with data.
For example to store 10 at the beginning of block number 1, we can call the write funnction as follows.
```bash
  eeprom_write(10,0,1);
```
### Read from memory
To read from EEPROM you need to provide block number (0 - 31) and address (0 - 15). Data stored at the location is then returned.
For example to read data from address number 5 of block 2, we can call the read function as follows. The returned data is stored in 'value' variable.
```bash
  data = eeprom_read(5,2);
```
