#pragma once

#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>

typedef struct BitMap
{
    size_t* _bits;
    size_t _range;
}BitMap;

void BitMapInit(BitMap *bm,size_t range); //��ʼ��
void BitMapSet(BitMap *bm,size_t x);//�����Ӧλ
void BitMapReset(BitMap *bm,size_t x);//�ָ���Ӧλ
int BitMapTest(BitMap *bm,size_t x); 
void BitMapDestory(BitMap *bm);

