#ifndef UTILS_HPP
#define UTILS_HPP

const uint8_t BIT_LEN = 8;

#ifdef TEST
const uint8_t ADDR_LEN = 14;
#else
const uint8_t ADDR_LEN = 256;
#endif

 typedef bool BIT;
  typedef bool BYTE[BIT_LEN];
  
const uint8_t CLK_PIN = 2;
const uint8_t ENABLE_PIN = 3;

const uint8_t ADDR_PINS[BIT_LEN] = {13, 12, 11, 10, 9, 8, 7, 6};
const uint8_t INPUT_PINS[BIT_LEN] = {14, 15, 16, 17, 18, 19, 20, 21};
const uint8_t OUTPUT_PINS[BIT_LEN] = {A0, A1, A2, A3, A4, A5, A6, A7};

#endif
