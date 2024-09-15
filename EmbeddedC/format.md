# Registers Definitions Formats

## Overview

This document outlines the definitions for 8-bit and 16-bit registers in C.

## Register Definitions

### 8-Bit Register

```c
typedef union {
    uint8 Byte;
    struct {
        uint8 BIT0 : 1;
        uint8 BIT1 : 1;
        uint8 BIT2 : 1;
        uint8 BIT3 : 1;
        uint8 BIT4 : 1;
        uint8 BIT5 : 1;
        uint8 BIT6 : 1;
        uint8 BIT7 : 1;
    } Bits;
} REG_NAME_TYPE;
```

### 16-Bit Register

```c
typedef union {
    uint16 TwoBytes;
    struct {
        uint16 Bit0  : 1;
        uint16 Bit1  : 1;
        uint16 Bit2  : 1;
        uint16 Bit3  : 1;
        uint16 Bit4  : 1;
        uint16 Bit5  : 1;
        uint16 Bit6  : 1;
        uint16 Bit7  : 1;
        uint16 Bit8  : 1;
        uint16 Bit9  : 1;
        uint16 Bit10 : 1;
        uint16 Bit11 : 1;
        uint16 Bit12 : 1;
        uint16 Bit13 : 1;
        uint16 Bit14 : 1;
        uint16 Bit15 : 1;
    } Bits;
} Register_name_Type;
```

## Register Macro

```c
#define REG_name (*(volatile REG_type*) REG_address)
```

- **REG_name**: Symbolic register name.
- **REG_type**: Type definition 
- **REG_address**: Memory address of the register.
