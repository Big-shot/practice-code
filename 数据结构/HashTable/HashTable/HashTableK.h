#ifndef __HASHTABLEK_H__
#define __HASHTABLEK_H__

#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>

typedef int KeyType;
typedef int ValueType;

typedef struct HashNode
{
    struct HashNode* _next;
    KeyType _key;
    ValueType _value;
}HashNode;

typedef struct HashTable 
{
    HashNode**_tables;
    size_t _size;
    size_t _N;
}HashTable;

size_t HashTableKPrime(size_t N); //��ȡ����
HashNode* BuyHashKNode(KeyType key,ValueType value); //�����½ڵ�
void HashTableKInit(HashTable *ht,size_t N);//��ʼ��
int HashTableKInsert(HashTable* ht, KeyType key, ValueType value); //����
HashNode* HashTableKFind(HashTable* ht, KeyType key); //����
int HashTableKRemove(HashTable* ht, KeyType key); //ɾ��
void HashTableKDestory(HashTable* ht); //����

#endif//__HASHTABLEK_H__
