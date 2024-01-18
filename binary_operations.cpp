#include "utils.h"
 
bitset<32> concatBits(uint32 x, uint32 y) {
    /*
    ��������� �� ���� ��� 8 - �� ������ �����
    � ���������� 16 �����, ��� ������ �������� - ����
    ������� �����, ������ �������� - ���� ������� �����
    */
    uint16 result = 0;

    result = x << 8;
    result |= y;

    std::bitset<32> resultBits(result);

    return resultBits;
}

uint32 convertToGrey(uint32 a) {
    /*
    ������������ ����� � � �����,
    ��������������� ����� � � ���� ����
    */
    uint32 result = a >> 1;
    result ^= a;
    return result;
}

uint32 convertToBinary(uint32 a) {
    /*
    ������������ ����� � �� ���� ���� � �����,
    ��������������� ����� � � �������� ����
    */
    uint32 result = a;

    for (int i = 0; i < 31; i++) {
        result ^= (result >> 1);
    }

    return result;
}

bitset<32> getBitset(uint32 a) {
    /*
    ���������� �������� ��� �����
    */
    bitset<32> result(a);
    return result;
}

uint32 bitSwap(uint32 a, uint32 b, int position) {
    /* 
    ���������� c,� �������� ���� �� splitPosition �� a, ����� splitidx �� b
    */
    uint32 result,mask = 0;
    for (int i = 0; i <= 32; i++) {
        if (i >= (32 - position))
            mask |= (1 << i);
    }
    result = (a & mask) | (b & (~mask));
    return result;
}

uint32 invertBit(uint32 a, int position) {
    uint32 result = 0;
    uint32 mask = 1 << (32 - position);
    return result ^ mask;
}