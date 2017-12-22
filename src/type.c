#include "../head/type.h"
#include "../head/type_check.h"

Type* copyType(Type* src){
    if(src == NULL) return NULL;
    Type* dst = (Type*)malloc(sizeof(Type));
    dst->kind = src->kind;
    if(src->kind == ARRAY){
        dst->array.size = src->array.size;
        dst->array.elem = copyType(src->array.elem);
    }else if(src->kind == STRUCTURE){
        FieldList* p = src->structure;
        FieldList* head=NULL,*tail=NULL;
        while(p){
            FieldList* t = (FieldList*)malloc(sizeof(FieldList));
            t->next = NULL;
            copyString(&t->name,p->name);
            t->type = copyType(p->type);
            if(head==NULL){
                head = tail = t;
            }else{
                tail->next = t;
                tail = t;
            }
            p = p->next;
        }
        dst->structure = head;
    }else if(src->kind == FUNCTION){
        int size = src->function.size;
        dst->function.size = size;
        dst->function.elem = (Type**)malloc(size*sizeof(Type*));
        for(int i=0;i<size;++i){
            dst->function.elem[i] = copyType(src->function.elem[i]);
        }
    }
    return dst;
}

int type_equal(Type* t1, Type* t2){
    if(t1 == NULL || t2 == NULL){
        return 0;
    }
    if(t1->kind != t2->kind){
        return 0;
    }
    else if(t1->kind == BASIC_INT || t1->kind == BASIC_FLOAT){
        return 1;
    }
    else if(t1->kind == ARRAY){
        if(t1->array.size != t2->array.size){
            return 0;
        }else{
            return type_equal(t1->array.elem, t2->array.elem);
        }
    }else if(t1->kind == STRUCTURE){
        FieldList* h1 = t1->structure;
        FieldList* h2 = t2->structure;
        while(h1 != NULL && h2 != NULL){
            if(!type_equal(h1->type,h2->type)){
                return 0;
            }
            h1 = h1->next;
            h2 = h2->next;
        }
        if(h1 == NULL && h2 == NULL) {
            return 1;
        }
        else {
            return 0;
        }
    }else if(t1->kind == FUNCTION){
        if(t1->function.size != t2->function.size){
            return 0;
        }else{
            int size = t1->function.size;
            for(int i=0;i<size;++i){
                if(!type_equal(t1->function.elem[i], t2->function.elem[i])){
                    return 0;
                }
            }
            return 1;
        }
    }
    assert(1 == 0);
    return 0;
}

int para_equal(Type *p1, Type *p2) {
    int size1 = p1->function.size;
    int size2 = p2->function.size;
    if(size1 != size2) {
        return 0;
    }
    for(int i = 1;i < size1;i++) {
        if(type_equal(p1->function.elem[i], p2->function.elem[i]) == 0) {
            // updated
            return 0;
        }
    }
    return 1;
}