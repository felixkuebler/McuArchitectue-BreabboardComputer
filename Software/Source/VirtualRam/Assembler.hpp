#include "Arduino.h"  
#include "Utils.hpp"


class Assembler {
private:
  typedef BYTE OPCODE;
  typedef BYTE ADDR;

  BYTE assembly[ADDR_LEN] = { };
  uint8_t memAddr = 0;
  
  const OPCODE NOP_BITSTREAM  = {0, 0, 0, 0, 0, 0, 0, 0};
  const OPCODE LDI_BITSTREAM  = {0, 0, 0, 0, 0, 0, 0, 1};
  const OPCODE LD_BITSTREAM  =  {0, 0, 0, 0, 0, 0, 1, 0};
  const OPCODE STR_BITSTREAM  = {0, 0, 0, 0, 0, 0, 1, 1};
  const OPCODE ADD_BITSTREAM  = {0, 0, 0, 0, 0, 1, 0, 0};
  const OPCODE SUB_BITSTREAM  = {0, 0, 0, 0, 0, 1, 0, 1};
  const OPCODE JMP_BITSTREAM  = {0, 0, 0, 0, 0, 1, 1, 0};
  const OPCODE JMPZ_BITSTREAM = {0, 0, 0, 0, 0, 1, 1, 1};
  const OPCODE JMPC_BITSTREAM = {0, 0, 0, 0, 1, 0, 0, 0};
  const OPCODE HLT_BITSTREAM  = {0, 0, 0, 0, 1, 0, 0, 1};
  const OPCODE RST_BITSTREAM  = {0, 0, 0, 0, 1, 0, 1, 0};
  
  void NOP();
  
  void LOAD(ADDR addr);
  void LOAD(uint8_t addr);
  
  void STORE(ADDR addr);
  void STORE(uint8_t addr);
  
  void ADD(ADDR addr);
  void ADD(uint8_t addr);
  
  void SUB(ADDR addr);
  void SUB(uint8_t addr);
  
  void JUMP(ADDR addr);
  void JUMP(uint8_t addr);
  
  void JUMP_ZERO(ADDR addr);
  void JUMP_ZERO(uint8_t addr);
  
  void JUMP_CARRY(ADDR addr);
  void JUMP_CARRY(uint8_t addr);
  
  void HALT();
  void RESET();

  void VAR(ADDR addr, BYTE val);
  void VAR(uint8_t addr, uint8_t val);
  
  void CONST(ADDR addr, BYTE val);
  void CONST(uint8_t addr, uint8_t val);

  uint8_t BYTEtoUint8(BYTE val);
  BIT* uint8ToBYTE(uint8_t val);

  void Assembly();

 public:
  BYTE* getAssembly();
  
};
