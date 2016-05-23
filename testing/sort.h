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

// O(n^2)
void bbsort(void *data, size_p num, size_p size, CompareFunc func){
	for(int i=0; i<num; i++){
		for(int j=num-1; j>i; j--){
			if(func((Byte_t)data+(j-1)*size, (Byte_t)data + j*size) > 0) swap(data, j-1, j, size);
		}
	}
	
}

// O(n^2)
void slsort(void *data, size_p num, size_p size, CompareFunc func){
    for(int i=0; i<num; i++){
        int min = i;
        for(int j=i+1; j<num; j++)
            if(func((Byte_t)data+min*size, (Byte_t)data+j*size)>0) min = j;
        swap(data, i, min, size);
    }
}

// O(nlogn)
void mgsort(void *data, size_p num, size_p size, CompareFunc func){
    if(num > 1){
        size_p lowpart = num/2;
        size_p highpart = num - lowpart;
        void *data2 = (Byte_t)data + lowpart*size;
        mgsort(data, lowpart, size, func);
        mgsort(data2, highpart, size, func);
        //
        void *tmp = malloc(num*size);
        int i=0, j=0, k=0;
        while(i<lowpart && j<highpart){
            if(func((Byte_t)data + i*size, (Byte_t)data2 + j*size) < 0)
                memcpy((Byte_t)tmp + (k++)*size, (Byte_t)data + (i++)*size, size);
            else
                memcpy((Byte_t)tmp + (k++)*size, (Byte_t)data2 + (j++)*size, size);
        }
        //
        if(i<lowpart) memcpy((Byte_t)tmp + k*size, (Byte_t)data + i*size, (lowpart-i)*size);
        if(j<highpart) memcpy((Byte_t)tmp + k*size, (Byte_t)data2 + j*size, (highpart-j)*size);
        //
        memcpy(data, tmp, num*size);
        free(tmp);
    }
}

// O(nlogn)
void qksort(void *data, size_p from, size_p to, size_p size, CompareFunc func){
    if(from < to){
        void *tmp = malloc(size);
        memcpy(tmp, (Byte_t)data + to*size, size);
        int j=from;
        for(int i=from; i<=to; i++){
            if(func((Byte_t)data+i*size, tmp)<0){
                swap(data, j, i, size);
                j++;
            }
        }
        swap(data, j, to, size);
        free(tmp);
        //
        qksort(data, from, j-1, size, func);
        qksort(data, j+1, to, size, func);
    }
}

// O(nlogn)
void hpsort(void *data, size_p num, size_p size, CompareFunc func){
    
}
