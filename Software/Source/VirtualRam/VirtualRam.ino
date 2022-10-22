#define TEST

#include "Utils.hpp"
 
#ifdef TEST
/*
// load, add, store, halt
bool ram[ADDR_LEN][BIT_LEN] = {
  {0, 0, 0, 0, 0, 0, 0, 1}, // 0000 // load a
  {0, 0, 0, 0, 0, 1, 1, 1}, // 0001 // ref to addr 007
  {0, 0, 0, 0, 0, 0, 1, 1}, // 0010 // add
  {0, 0, 0, 0, 1, 0, 0, 0}, // 0011 // ref to addr 008
  {0, 0, 0, 0, 0, 0, 1, 0}, // 0100 // store a
  {0, 0, 0, 0, 1, 0, 0, 1}, // 0101 // ref to addr 009
  {1, 1, 1, 1, 1, 1, 1, 0}, // 0110 // halt
  {1, 0, 1, 0, 0, 0, 0, 0}, // 0111 // addr 007
  {0, 1, 0, 0, 0, 0, 0, 0}, // 1000 // addr 8
  {0, 0, 0, 0, 0, 0, 0, 0}  // 1001 // addr 9
};
*/
/*
// load, add, store, jump
bool ram[ADDR_LEN][BIT_LEN] = {
  {0, 0, 0, 0, 0, 0, 0, 1}, // 0000 // load a
  {0, 0, 0, 0, 1, 0, 0, 1}, // 0001 // ref to addr 009
  {0, 0, 0, 0, 0, 0, 1, 1}, // 0010 // add
  {0, 0, 0, 0, 1, 0, 1, 0}, // 0011 // ref to addr 010
  {0, 0, 0, 0, 0, 0, 1, 0}, // 0100 // store
  {0, 0, 0, 0, 1, 0, 0, 1}, // 0101 // ref to addr 009
  {0, 0, 0, 0, 0, 1, 0, 1}, // 0110 // jump
  {0, 0, 0, 0, 0, 0, 0, 0}, // 0111 // ref to addr 000
  {0, 0, 0, 0, 0, 0, 0, 0}, // 1000 // addr 008
  {0, 0, 0, 0, 0, 0, 0, 1}, // 1001 // addr 009
};
*/

/*
//store, halt
bool ram[ADDR_LEN][BIT_LEN] = {
  {0, 0, 0, 0, 0, 0, 1, 0}, // 0100 // store a
  {0, 0, 0, 0, 1, 0, 0, 1}, // 0101 // ref to addr 009
  {1, 1, 1, 1, 1, 1, 1, 0}, // 0111 // halt
  {1, 1, 1, 1, 1, 1, 1, 0}, // 1000 // halt
  {1, 1, 1, 1, 1, 1, 1, 0}, // 0111 // halt
  {1, 1, 1, 1, 1, 1, 1, 0}, // 1000 // halt
  {1, 1, 1, 1, 1, 1, 1, 0}, // 0110 // halt
  {1, 1, 1, 1, 1, 1, 1, 0}, // 0111 // halt
  {1, 1, 1, 1, 1, 1, 1, 0}, // 1000 // halt
  {0, 0, 0, 0, 0, 0, 0, 0}, // 1001 // halt
};
*/

/*
// Halt
bool ram[ADDR_LEN][BIT_LEN] = {
  {1, 1, 1, 1, 1, 1, 1, 1}, // 0111 // halt
  {1, 1, 1, 1, 1, 1, 1, 0}, // 1000 // halt
  {1, 1, 1, 1, 1, 1, 1, 0}, // 1000 // halt
  {1, 1, 1, 1, 1, 1, 1, 0}, // 1000 // halt
  {1, 1, 1, 1, 1, 1, 1, 0}, // 0111 // halt
  {1, 1, 1, 1, 1, 1, 1, 0}, // 1000 // halt
  {1, 1, 1, 1, 1, 1, 1, 0}, // 0110 // halt
  {1, 1, 1, 1, 1, 1, 1, 0}, // 0111 // halt
  {1, 1, 1, 1, 1, 1, 1, 0}, // 1000 // halt
  {0, 0, 0, 0, 0, 0, 0, 0}, // 1001 // halt
};
*/

// load, add, store, sub, jump_carry, halt
bool ram[ADDR_LEN][BIT_LEN] = {
  {0, 0, 0, 0, 0, 0, 0, 1}, // 0 // 0000 // load a
  {0, 0, 0, 0, 1, 0, 1, 1}, // 1 // 0001 // ref to addr 11
  {0, 0, 0, 0, 0, 0, 1, 1}, // 2 // 0010 // add
  {0, 0, 0, 0, 1, 1, 0, 0}, // 3 // 0011 // ref to addr 12
  {0, 0, 0, 0, 0, 0, 1, 0}, // 4 // 0100 // store a
  {0, 0, 0, 0, 1, 0, 1, 1}, // 5 // 0101 // ref to addr 11
  {0, 0, 0, 0, 0, 1, 1, 1}, // 6 // 0110 // jump carry
  {0, 0, 0, 0, 1, 0, 1, 0}, // 7 // 0111 // ref to addr 0
  {0, 0, 0, 0, 0, 1, 0, 1}, // 8 // 1000 // jump
  {0, 0, 0, 0, 0, 0, 0, 0}, // 9 // 1001 // ref to addr 0
  {1, 1, 1, 1, 1, 1, 1, 0}, // 10 // 1010 // halt
  {1, 1, 1, 1, 1, 1, 0, 0}, // 11 // 1011 // addr 11
  {0, 0, 0, 0, 0, 0, 0, 1}, // 12 // 1100 // addr 12
  {0, 0, 0, 0, 0, 0, 0, 0}  // 13 // 1101 // addr 13
};

#else
Assembler assembler;
bool ram[ADDR_LEN][BIT_LEN] = asselmber.getAssembly()
#endif


volatile bool writeEnable = false;

void isr() {
  writeEnable = (bool) digitalRead(ENABLE_PIN);
}

void setup() {

#ifdef TEST
  Serial.begin(9600);
#endif

  attachInterrupt(digitalPinToInterrupt(CLK_PIN), isr, RISING);

  pinMode(CLK_PIN, INPUT);
  pinMode(ENABLE_PIN, INPUT);

  for (uint8_t i = 0; i < BIT_LEN; i++) {
    pinMode(ADDR_PINS[i], INPUT);
    pinMode(INPUT_PINS[i], INPUT);
    pinMode(OUTPUT_PINS[i], OUTPUT);
  }
}

void loop() {
  
  uint8_t addr = 0;

  #ifdef TEST
  Serial.print("Address Lines: ");
  #endif
  
  for (uint8_t i = 0; i < BIT_LEN; i++) {
    float addrValue = (digitalRead(ADDR_PINS[i])==HIGH ? 1 : 0)*pow(2, BIT_LEN-i-1);
    addr += (uint8_t)(addrValue+0.1);

    #ifdef TEST
    Serial.print(digitalRead(ADDR_PINS[i])==HIGH ? 1 : 0);
    //Serial.print(addrValue);
    Serial.print(" ");
    #endif
  }
  #ifdef TEST
  Serial.print("\nAddress: ");
  Serial.println(addr);
  #endif

  if (writeEnable) {
  
    for (uint8_t i = 0; i < BIT_LEN; i++) {
      ram[ addr<ADDR_LEN ? addr : 0 ][i] = (bool) digitalRead(INPUT_PINS[i]);

      #ifdef TEST
      Serial.print(digitalRead(INPUT_PINS[i])==HIGH ? 1 : 0);
      #endif
    }

    #ifdef TEST
    Serial.println("");
    #endif

    writeEnable = false;
  }

  #ifdef TEST
  Serial.print("Output Lines: \t");
  #endif
    
  for (uint8_t i = 0; i < BIT_LEN; i++) {
    digitalWrite(OUTPUT_PINS[i], ram[ addr<ADDR_LEN ? addr : 0 ][i]);

    #ifdef TEST
    Serial.print(ram[ addr<ADDR_LEN ? addr : 0 ][i]==true ? 1 : 0);
    #endif
  }
  
  #ifdef TEST
  Serial.println("");
  #endif
}
