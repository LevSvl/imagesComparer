#include "utils.h"
 
bitset<16> concatBits(uint8 x, uint8 y) {
    /*
    ��������� �� ���� ��� 8 - �� ������ �����
    � ���������� 16 �����, ��� ������ �������� - ����
    ������� �����, ������ �������� - ���� ������� �����
    */
    uint16 result = 0;

    result = x << 8;
    result |= y;

    std::bitset<16> resultBits(result);

    return resultBits;
}

uint8 convertToGrey(uint8 a) {
    /*
    ������������ ����� � � �����,
    ��������������� ����� � � ���� ����
    */
    uint8 result = a >> 1;
    result ^= a;
    return result;
}

uint8 convertToBinary(uint8 a) {
    /*
    ������������ ����� � �� ���� ���� � �����,
    ��������������� ����� � � �������� ����
    */
    uint8 result = a;

    for (int i = 0; i < 7; i++) {
        result ^= (result >> 1);
    }

    return result;
}

bitset<8> getBitset(uint8 a) {
    /*
    ���������� �������� ��� �����
    */
    bitset<8> result(a);
    return result;
}

uint8 bitSwap(uint8 a, uint8 b, int position) {
    /* 
    ���������� c,� �������� ���� �� splitPosition �� a, ����� splitidx �� b
    */
    uint8 result,mask = 0;
    for (int i = 0; i <= 8; i++) {
        if (i >= (8 - position))
            mask |= (1 << i);
    }
    result = (a & mask) | (b & (~mask));
    return result;
}

uint8 invertBit(uint8 a, int position) {
    uint8 result = 0;
    uint8 mask = 1 << (7 - position);
    return result ^ mask;
}