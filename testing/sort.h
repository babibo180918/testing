#include <stdlib.h>
#include <stdio.h>
typedef int size_p;
typedef char *Byte_t;
typedef int (*CompareFunc)(void *p1, void *p2);

void swap (void *data, int pst1, int pst2, size_p size){
	void *tmp = malloc(size);
	memcpy(tmp,(Byte_t)data + pst1*size, size);
	memcpy((Byte_t)data+pst1*size, (Byte_t)data+pst2*size, size);
	memcpy((Byte_t)data+pst2*size, tmp, size);
	free(tmp);
}

void bbsort(void *data, size_p num, size_p size, CompareFunc func){
	for(int i=0; i<num; i++){
		for(int j=num-1; j>i; j--){
			if(func((Byte_t)data+(j-1)*size, (Byte_t)data + j*size) > 0) swap(data, j-1, j, size);
		}
	}
	
}

void slsort(void *data, size_p num, size_p size, CompareFunc func){
    ;
}

void mgsort(void *data, size_p num, size_p size, CompareFunc func){
    ;
}
