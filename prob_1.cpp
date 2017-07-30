#include <stdio.h>

void twoSum(int *A, int size, int sum, int &pos_1, int &pos_2)
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (A[i] + A[j] == sum) {
                pos_1 = i;
                pos_2 = j;
                return;
            }
        }
    }
}

int main()
{
    int A[] = {2, 7, 11, 15};
    int size = sizeof(A) / sizeof(A[0]);
    int pos_1, pos_2;
    twoSum(A, size, 9, pos_1, pos_2);
    printf("%d %d\n", pos_1, pos_2);
    return 0;
}
