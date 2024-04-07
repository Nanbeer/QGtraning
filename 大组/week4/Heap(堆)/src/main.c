#include"Heap.h"

int main() {
    HP heap;
    HeapInit(&heap);

    menu(&heap);

    HeapDestory(&heap);
    return 0;
}