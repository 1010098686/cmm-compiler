#ifndef _TYPE_H_
#define _TYPE_H_

#include<string.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct Type_ Type;
typedef struct FieldList_ FieldList;

struct Type_{
    enum {BASIC_INT,BASIC_FLOAT,ARRAY,STRUCTURE,FUNCTION,UNDEFINED} kind;
    int is_constant;
    union
    {
        //int basic;
        struct {Type* elem; int size;} array;
		FieldList* structure;
        struct {Type** elem; int size;} function;
    };
};

struct FieldList_{
	char* name;
	Type* type;
	FieldList* next;
};

Type* copyType(Type* src);

int type_equal(Type* t1, Type* t2);

int para_equal(Type *p1, Type *p2);

#endif
