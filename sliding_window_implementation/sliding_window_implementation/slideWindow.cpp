#include <stdio.h>
#include <stdlib.h>


int* decrypt(int* code, int codeSize, int k, int* returnSize) {
    int* arr = (int*)malloc(sizeof(int) * codeSize);
    *returnSize = codeSize;

    int direction = k > 0 ? 1 : -1, i, j, sum, idx;

    if (k == 0) {
        for (i = 0; i < codeSize; i++) {
            arr[i] = 0;
        }
    }
    else {
        k = k > 0 ? k : -k;

        for (i = 0; i < codeSize; i++) {
            sum = 0;
            for (j = 1; j <= k; j++) {
                idx = (i + direction * j + codeSize) % codeSize;
                sum += code[idx];
            }
            arr[i] = sum;
        }
    }

    return arr;
}

int main(void) {
    int code[4] = {2,8,4,3}, k = 3, size;
    int* arr = decrypt(code, 4, k, &size);

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}