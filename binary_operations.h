#pragma once

#include "utils.h"

bitset<32> concatBits(uint32 x, uint32 y);

uint32 convertToGrey(uint32 a);

uint32 convertToBinary(uint32 a);

bitset<32> getBitset(uint32 a);

uint32 bitSwap(uint32 a, uint32 b, int position);

uint32 invertBit(uint32 a, int position);