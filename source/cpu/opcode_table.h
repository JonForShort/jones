//
// MIT License
//
// Copyright 2018
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
#pragma once

#include "addressing_mode.h"
#include "instruction_set.h"

namespace jones {
  
  using is = InstructionSet;
  using am = AddressingMode;
  using mnemonic_t = const char*;
  
  struct opcode_t {
    uint8_t opcode;
    InstructionSet type;
    mnemonic_t mnemonic;
    AddressingMode addr;
  };
  
  //
  // Reference: https://wiki.nesdev.com/w/index.php/CPU_unofficial_opcodes
  //
  struct opcode_t instruction_set[256] {

    { 0x00, is::BRK, "BRK", am::IMPLICIT         },
    { 0x01, is::ORA, "ORA", am::INDEXED_INDIRECT },
    { 0x02, is::STP, "STP", am::IMPLICIT         },
    { 0x03, is::SLO, "SLO", am::INDEXED_INDIRECT },
    { 0x04, is::NOP, "NOP", am::ZERO_PAGE        },
    { 0x05, is::ORA, "ORA", am::ZERO_PAGE        },
    { 0x06, is::ASL, "ASL", am::ZERO_PAGE        },
    { 0x07, is::SLO, "SLO", am::ZERO_PAGE        },
    { 0x08, is::PHP, "PHP", am::IMPLICIT         },
    { 0x09, is::ORA, "ORA", am::IMMEDIATE        },
    { 0x0A, is::ASL, "ASL", am::IMPLICIT         },
    { 0x0B, is::ANC, "ANC", am::IMMEDIATE        },
    { 0x0C, is::NOP, "NOP", am::ABSOLUTE         },
    { 0x0D, is::ORA, "ORA", am::ABSOLUTE         },
    { 0x0E, is::ASL, "ASL", am::ABSOLUTE         },
    { 0x0F, is::SLO, "SLO", am::ABSOLUTE         },

    { 0x10, is::BPL, "BPL", am::RELATIVE         },
    { 0x11, is::ORA, "ORA", am::INDIRECT_INDEXED },
    { 0x12, is::STP, "STP", am::IMPLICIT         },
    { 0x13, is::SLO, "SLO", am::INDIRECT_INDEXED },
    { 0x14, is::NOP, "NOP", am::ZERO_PAGE_X      },
    { 0x15, is::ORA, "ORA", am::ZERO_PAGE_X      },
    { 0x16, is::ASL, "ASL", am::ZERO_PAGE_X      },
    { 0x17, is::SLO, "SLO", am::ZERO_PAGE_X      },	      
    { 0x18, is::CLC, "CLC", am::IMPLICIT         },
    { 0x19, is::ORA, "ORA", am::ABSOLUTE_Y       },
    { 0x1A, is::NOP, "NOP", am::IMPLICIT         },
    { 0x1B, is::SLO, "SLO", am::ABSOLUTE_Y       },
    { 0x1C, is::NOP, "NOP", am::ABSOLUTE_X       },
    { 0x1D, is::ORA, "ORA", am::ABSOLUTE_X       },
    { 0x1E, is::ASL, "ASL", am::ABSOLUTE_X       },
    { 0x1F, is::SLO, "SLO", am::ABSOLUTE_X       },

    { 0x20, is::BRK, "BRK" },
    { 0x21, is::ORA, "ORA" },
    { 0x22, is::STP, "ORA" },
    { 0x23, is::SLO, "ORA" },
    { 0x24, is::NOP, "ORA" },
    { 0x25, is::ASL, "ORA" },
    { 0x26, is::ORA, "ORA" },
    { 0x27, is::ORA, "ORA" },	      
    { 0x28, is::BRK, "BRK" },
    { 0x29, is::ORA, "ORA" },
    { 0x2A, is::STP, "ORA" },
    { 0x2B, is::SLO, "ORA" },
    { 0x2C, is::NOP, "ORA" },
    { 0x2D, is::ASL, "ORA" },
    { 0x2E, is::ORA, "ORA" },
    { 0x2F, is::ORA, "ORA" },
    { 0x30, is::BRK, "BRK" },
    { 0x31, is::ORA, "ORA" },
    { 0x32, is::STP, "ORA" },
    { 0x33, is::SLO, "ORA" },
    { 0x34, is::NOP, "ORA" },
    { 0x35, is::ASL, "ORA" },
    { 0x36, is::ORA, "ORA" },
    { 0x37, is::ORA, "ORA" },	      
    { 0x38, is::BRK, "BRK" },
    { 0x39, is::ORA, "ORA" },
    { 0x3A, is::STP, "ORA" },
    { 0x3B, is::SLO, "ORA" },
    { 0x3C, is::NOP, "ORA" },
    { 0x3D, is::ASL, "ORA" },
    { 0x3E, is::ORA, "ORA" },
    { 0x3F, is::ORA, "ORA" },
    { 0x40, is::BRK, "BRK" },
    { 0x41, is::ORA, "ORA" },
    { 0x42, is::STP, "ORA" },
    { 0x43, is::SLO, "ORA" },
    { 0x44, is::NOP, "ORA" },
    { 0x45, is::ASL, "ORA" },
    { 0x46, is::ORA, "ORA" },
    { 0x47, is::ORA, "ORA" },	      
    { 0x48, is::BRK, "BRK" },
    { 0x49, is::ORA, "ORA" },
    { 0x4A, is::STP, "ORA" },
    { 0x4B, is::SLO, "ORA" },
    { 0x4C, is::NOP, "ORA" },
    { 0x4D, is::ASL, "ORA" },
    { 0x4E, is::ORA, "ORA" },
    { 0x4F, is::ORA, "ORA" },
    { 0x50, is::BRK, "BRK" },
    { 0x51, is::ORA, "ORA" },
    { 0x52, is::STP, "ORA" },
    { 0x53, is::SLO, "ORA" },
    { 0x54, is::NOP, "ORA" },
    { 0x55, is::ASL, "ORA" },
    { 0x56, is::ORA, "ORA" },
    { 0x57, is::ORA, "ORA" },	      
    { 0x58, is::BRK, "BRK" },
    { 0x59, is::ORA, "ORA" },
    { 0x5A, is::STP, "ORA" },
    { 0x5B, is::SLO, "ORA" },
    { 0x5C, is::NOP, "ORA" },
    { 0x5D, is::ASL, "ORA" },
    { 0x5E, is::ORA, "ORA" },
    { 0x5F, is::ORA, "ORA" },
    { 0x60, is::BRK, "BRK" },
    { 0x61, is::ORA, "ORA" },
    { 0x62, is::STP, "ORA" },
    { 0x63, is::SLO, "ORA" },
    { 0x64, is::NOP, "ORA" },
    { 0x65, is::ASL, "ORA" },
    { 0x66, is::ORA, "ORA" },
    { 0x67, is::ORA, "ORA" },	      
    { 0x68, is::BRK, "BRK" },
    { 0x69, is::ORA, "ORA" },
    { 0x6A, is::STP, "ORA" },
    { 0x6B, is::SLO, "ORA" },
    { 0x6C, is::NOP, "ORA" },
    { 0x6D, is::ASL, "ORA" },
    { 0x6E, is::ORA, "ORA" },
    { 0x6F, is::ORA, "ORA" },
    { 0x70, is::BRK, "BRK" },
    { 0x71, is::ORA, "ORA" },
    { 0x72, is::STP, "ORA" },
    { 0x73, is::SLO, "ORA" },
    { 0x74, is::NOP, "ORA" },
    { 0x75, is::ASL, "ORA" },
    { 0x76, is::ORA, "ORA" },
    { 0x77, is::ORA, "ORA" },	      
    { 0x78, is::BRK, "BRK" },
    { 0x79, is::ORA, "ORA" },
    { 0x7A, is::STP, "ORA" },
    { 0x7B, is::SLO, "ORA" },
    { 0x7C, is::NOP, "ORA" },
    { 0x7D, is::ASL, "ORA" },
    { 0x7E, is::ORA, "ORA" },
    { 0x7F, is::ORA, "ORA" },
    { 0x80, is::BRK, "BRK" },
    { 0x81, is::ORA, "ORA" },
    { 0x82, is::STP, "ORA" },
    { 0x83, is::SLO, "ORA" },
    { 0x84, is::NOP, "ORA" },
    { 0x85, is::ASL, "ORA" },
    { 0x86, is::ORA, "ORA" },
    { 0x87, is::ORA, "ORA" },	      
    { 0x88, is::BRK, "BRK" },
    { 0x89, is::ORA, "ORA" },
    { 0x8A, is::STP, "ORA" },
    { 0x8B, is::SLO, "ORA" },
    { 0x8C, is::NOP, "ORA" },
    { 0x8D, is::ASL, "ORA" },
    { 0x8E, is::ORA, "ORA" },
    { 0x8F, is::ORA, "ORA" },
    { 0x90, is::BRK, "BRK" },
    { 0x91, is::ORA, "ORA" },
    { 0x92, is::STP, "ORA" },
    { 0x93, is::SLO, "ORA" },
    { 0x94, is::NOP, "ORA" },
    { 0x95, is::ASL, "ORA" },
    { 0x96, is::ORA, "ORA" },
    { 0x97, is::ORA, "ORA" },	      
    { 0x98, is::BRK, "BRK" },
    { 0x99, is::ORA, "ORA" },
    { 0x9A, is::STP, "ORA" },
    { 0x9B, is::SLO, "ORA" },
    { 0x9C, is::NOP, "ORA" },
    { 0x9D, is::ASL, "ORA" },
    { 0x9E, is::ORA, "ORA" },
    { 0x9F, is::ORA, "ORA" },
    { 0xA0, is::BRK, "BRK" },
    { 0xA1, is::ORA, "ORA" },
    { 0xA2, is::STP, "ORA" },
    { 0xA3, is::SLO, "ORA" },
    { 0xA4, is::NOP, "ORA" },
    { 0xA5, is::ASL, "ORA" },
    { 0xA6, is::ORA, "ORA" },
    { 0xA7, is::ORA, "ORA" },	      
    { 0xA8, is::BRK, "BRK" },
    { 0xA9, is::ORA, "ORA" },
    { 0xAA, is::STP, "ORA" },
    { 0xAB, is::SLO, "ORA" },
    { 0xAC, is::NOP, "ORA" },
    { 0xAD, is::ASL, "ORA" },
    { 0xAE, is::ORA, "ORA" },
    { 0xAF, is::ORA, "ORA" },
    { 0xB0, is::BRK, "BRK" },
    { 0xB1, is::ORA, "ORA" },
    { 0xB2, is::STP, "ORA" },
    { 0xB3, is::SLO, "ORA" },
    { 0xB4, is::NOP, "ORA" },
    { 0xB5, is::ASL, "ORA" },
    { 0xB6, is::ORA, "ORA" },
    { 0xB7, is::ORA, "ORA" },	      
    { 0xB8, is::BRK, "BRK" },
    { 0xB9, is::ORA, "ORA" },
    { 0xBA, is::STP, "ORA" },
    { 0xBB, is::SLO, "ORA" },
    { 0xBC, is::NOP, "ORA" },
    { 0xBD, is::ASL, "ORA" },
    { 0xBE, is::ORA, "ORA" },
    { 0xBF, is::ORA, "ORA" },
    { 0xC0, is::BRK, "BRK" },
    { 0xC1, is::ORA, "ORA" },
    { 0xC2, is::STP, "ORA" },
    { 0xC3, is::SLO, "ORA" },
    { 0xC4, is::NOP, "ORA" },
    { 0xC5, is::ASL, "ORA" },
    { 0xC6, is::ORA, "ORA" },
    { 0xC7, is::ORA, "ORA" },	      
    { 0xC8, is::BRK, "BRK" },
    { 0xC9, is::ORA, "ORA" },
    { 0xCA, is::STP, "ORA" },
    { 0xCB, is::SLO, "ORA" },
    { 0xCC, is::NOP, "ORA" },
    { 0xCD, is::ASL, "ORA" },
    { 0xCE, is::ORA, "ORA" },
    { 0xCF, is::ORA, "ORA" },
    { 0xD0, is::BRK, "BRK" },
    { 0xD1, is::ORA, "ORA" },
    { 0xD2, is::STP, "ORA" },
    { 0xD3, is::SLO, "ORA" },
    { 0xD4, is::NOP, "ORA" },
    { 0xD5, is::ASL, "ORA" },
    { 0xD6, is::ORA, "ORA" },
    { 0xD7, is::ORA, "ORA" },	      
    { 0xD8, is::BRK, "BRK" },
    { 0xD9, is::ORA, "ORA" },
    { 0xDA, is::STP, "ORA" },
    { 0xDB, is::SLO, "ORA" },
    { 0xDC, is::NOP, "ORA" },
    { 0xDD, is::ASL, "ORA" },
    { 0xDE, is::ORA, "ORA" },
    { 0xDF, is::ORA, "ORA" },
    { 0xE0, is::BRK, "BRK" },
    { 0xE1, is::ORA, "ORA" },
    { 0xE2, is::STP, "ORA" },
    { 0xE3, is::SLO, "ORA" },
    { 0xE4, is::NOP, "ORA" },
    { 0xE5, is::ASL, "ORA" },
    { 0xE6, is::ORA, "ORA" },
    { 0xE7, is::ORA, "ORA" },	      
    { 0xE8, is::BRK, "BRK" },
    { 0xE9, is::ORA, "ORA" },
    { 0xEA, is::STP, "ORA" },
    { 0xEB, is::SLO, "ORA" },
    { 0xEC, is::NOP, "ORA" },
    { 0xED, is::ASL, "ORA" },
    { 0xEE, is::ORA, "ORA" },
    { 0xEF, is::ORA, "ORA" },
    { 0xF0, is::BRK, "BRK" },
    { 0xF1, is::ORA, "ORA" },
    { 0xF2, is::STP, "ORA" },
    { 0xF3, is::SLO, "ORA" },
    { 0xF4, is::NOP, "ORA" },
    { 0xF5, is::ASL, "ORA" },
    { 0xF6, is::ORA, "ORA" },
    { 0xF7, is::ORA, "ORA" },	      
    { 0xF8, is::BRK, "BRK" },
    { 0xF9, is::ORA, "ORA" },
    { 0xFA, is::STP, "ORA" },
    { 0xFB, is::SLO, "ORA" },
    { 0xFC, is::NOP, "ORA" },
    { 0xFD, is::ASL, "ORA" },
    { 0xFE, is::ORA, "ORA" },
    { 0xFF, is::ORA, "ORA" }
  };
}
