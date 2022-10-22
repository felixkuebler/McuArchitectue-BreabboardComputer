#include "Assembler.hpp"

void Assembler::NOP() {
  *assembly[memAddr++] = NOP_BITSTREAM;
}

void Assembler::LOAD(ADDR addr) {
  *assembly[memAddr++] = LD_BITSTREAM;
  *assembly[memAddr++] = addr;
}

void Assembler::LOAD(uint8_t addr) {
  LOAD(uint8ToBYTE(addr));
}

void Assembler::STORE(ADDR addr) {
  *assembly[memAddr++] = STR_BITSTREAM;
  *assembly[memAddr++] = addr;
}

void Assembler::STORE(uint8_t addr) {
  STORE(uint8ToBYTE(addr));
}

void Assembler::ADD(ADDR addr) {
  *assembly[memAddr++] = ADD_BITSTREAM;
  *assembly[memAddr++] = addr;
}

void Assembler::ADD(uint8_t addr) {
  ADD(uint8ToBYTE(addr));
}

void Assembler::SUB(ADDR addr) {
  *assembly[memAddr++] = SUB_BITSTREAM;
  *assembly[memAddr++] = addr;
}

void Assembler::SUB(uint8_t addr) {
  SUB(uint8ToBYTE(addr));
}

void Assembler::JUMP(ADDR addr) {
  *assembly[memAddr++] = JMP_BITSTREAM;
  *assembly[memAddr++] = addr;
}

void Assembler::JUMP(uint8_t addr) {
  JUMP(uint8ToBYTE(addr));
}

void Assembler::JUMP_ZERO(ADDR addr) {
  *assembly[memAddr++] = JMPZ_BITSTREAM;
  *assembly[memAddr++] = addr;
}

void Assembler::JUMP_ZERO(uint8_t addr) {
  JUMP_ZERO(uint8ToBYTE(addr));
}

void Assembler::JUMP_CARRY(ADDR addr) {
  *assembly[memAddr++] = JMPC_BITSTREAM;
  *assembly[memAddr++] = addr;
}

void Assembler::JUMP_CARRY(uint8_t addr) {
  JUMP_CARRY(uint8ToBYTE(addr));
}

void Assembler::HALT() {
  *assembly[memAddr++] = HLT_BITSTREAM;
}

void Assembler::RESET() {
  *assembly[memAddr++] = RST_BITSTREAM;
}  

void Assembler::VAR(ADDR addr, BYTE val) {
  *assembly[BYTEtoUint8(addr)] = val;

}

void Assembler::VAR(uint8_t addr, uint8_t val) {
  *assembly[addr] = uint8ToBYTE(val);
}

void Assembler::CONST(ADDR addr, BYTE val) {
  VAR(addr, val);
}

void Assembler::CONST(uint8_t addr, uint8_t val) {
  VAR(addr, val);
}

uint8_t Assembler::BYTEtoUint8(BYTE val) {
  uint8_t ret = 0;
  for (int i = 0; i < BIT_LEN; i++) {
      ret |=  (val[BIT_LEN-i-1] & 0b00000001) << i;
  }
  return ret;
}

BIT* Assembler::uint8ToBYTE(uint8_t val) {
  BYTE ret;
  for (int i = 0; i < BIT_LEN; i++) {
      ret[BIT_LEN-i-1] = (val >> i) & 0b00000001;
  }
  return ret;
}

BYTE* Assembler::getAssembly() {
  Assembly();
  return assembly;
}
