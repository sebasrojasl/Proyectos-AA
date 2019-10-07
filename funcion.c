#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//  __________________________________________________________________________________________________________________ //
//  __________________________________________________________________________________________________________________ //
//  __________________________________________________________________________________________________________________ //



// __________________________________________________ ARRAY INT __________________________________________________ // 

typedef struct {
  int *array;
  size_t used;
  size_t size;

} ArrayInt;

void initArrayInt(ArrayInt *a, size_t initialSize) {
  a->array = (int *)malloc(initialSize * sizeof(int));
  a->used = 0;
  a->size = initialSize;

}


void insertArrayInt(ArrayInt *a, int element) {

  if (a->used == a->size) {
    a->size *= 2;
    a->array = (int *)realloc(a->array, a->size * sizeof(int));

  }

  a->array[a->used++] = element;
}

void freeArrayInt(ArrayInt *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;

}

void printArrayInt(ArrayInt *a){

  for(int i = 0; i < a->used; i++)
    printf(" El numero es %d \n", a->array[i]);

}

// __________________________________________________ ARRAY CHAR __________________________________________________ //

typedef struct {
  char *array;
  size_t used;
  size_t size;

} ArrayChar;

void initArrayChar(ArrayChar *a, size_t initialSize) {
  a->array = (char *)malloc(initialSize * sizeof(char));
  a->used = 0;
  a->size = initialSize;

}

void insertArrayChar(ArrayChar *a, char element) {

  if (a->used == a->size) {
    a->size *= 2;
    a->array = (char *)realloc(a->array, a->size * sizeof(char));

  }

  a->array[a->used++] = element;
}

void freeArrayChar(ArrayChar *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;

}

void printArrayChar(ArrayChar *a){

  for(int i = 0; i < a->used; i++)
    printf(" El caracter es %c \n", a->array[i]);

}

//  __________________________________________________________________________________________________________________ //
//  __________________________________________________________________________________________________________________ //
//  __________________________________________________________________________________________________________________ //


ArrayChar decimalToChar(ArrayInt *a){

  ArrayChar listaChar;

  initArrayChar(&listaChar, 1);

  for(int i = 0; i < a->used; i++)
    insertArrayChar(&listaChar, (char) a->array[i]);


  return listaChar;
}



int main(){

/*
  ArrayInt numeros;
  ArrayChar letras;

  initArrayInt(&numeros, 1);

  insertArrayInt(&numeros, 45);
  insertArrayInt(&numeros, 76);
  insertArrayInt(&numeros, 87);
  insertArrayInt(&numeros, 56);
  insertArrayInt(&numeros, 77);
  insertArrayInt(&numeros, 100);

  letras = int2Char(&numeros);

  printArrayChar(&letras);
  printArrayInt(&numeros);  

  */

	return 0;
}