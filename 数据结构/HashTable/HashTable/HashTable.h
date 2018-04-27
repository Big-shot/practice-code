#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#include <stdio.h>
#include <assert.h>
#include<malloc.h>

typedef int KeyType;
typedef int ValueType;

typedef enum Status
{
    EMPTY,
    EXIST,
    DELETE,
}Status;

typedef struct HashNode 
{
    KeyType _key;
    ValueType _value;
    Status _status;
}HashNode;

typedef struct HashTable
{
    HashNode *_table;
    size_t _size;
    size_t _N;
}HashTable;

size_t HashTablePrime(size_t N);
void HashTableInit(HashTable* ht,size_t N); //��ʼ��
void HashTablePrint(HashTable *ht); //��ӡhash��
int HashTableInsert(HashTable* ht, KeyType key, ValueType value); //����
HashNode* HashTableFind(HashTable* ht, KeyType key); //����
int HashTableRemove(HashTable* ht, KeyType key); //ɾ��
void HashTableDestory(HashTable* ht);//����


#endif //__HASHTABLE_H__