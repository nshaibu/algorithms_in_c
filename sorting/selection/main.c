#include "lib/selection_sort.h"

#define MAX_NUMBERS 10

int main(int argc, char *argv[]) {
    int nums[MAX_NUMBERS], v, count = 1;

    printf("Type %d numbers\n", MAX_NUMBERS);
    scanf("%d", &v);
    while (count < MAX_NUMBERS) {
        nums[count++] = v;
        scanf("%d", &v);
    }

    selection_sort(nums, 0, count-1);

    for (int i=0; i<=count-1; i++) printf("%d ", nums[i]);
    printf("\n");
    return 0;
}