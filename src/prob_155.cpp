#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int size;
	int maxSize;
	int *data;
	int minData;
} MinStack;

MinStack *minStackCreate(int maxSize)
{
	MinStack *sta = (MinStack *)malloc(sizeof(MinStack));
	sta->size = 0;
	sta->maxSize = maxSize;
	sta->data = (int *)malloc(sizeof(int) * maxSize);
	return sta;
}

void minStackPush(MinStack *obj, int x)
{
	if (obj->size >= obj->maxSize)
		return;
	// push
	for (int i = obj->size; i > 0; --i) {
		obj->data[i] = obj->data[i - 1];
	}
	obj->data[0] = x;
	++obj->size;
	// min data
	if (obj->size == 1)
		obj->minData = x;
	else
		obj->minData = x < obj->minData ? x : obj->minData;
}

void minStackPop(MinStack *obj)
{
	int popData = obj->data[0];
	for (int i = 0; i < obj->size - 1; ++i) {
		obj->data[i] = obj->data[i + 1];
	}
	--obj->size;
	// pop the min => find min again
	if (obj->minData == popData && obj->size > 0) {
		obj->minData = obj->data[0];
		for (int i = 1; i < obj->size; ++i) {
			obj->minData = obj->data[i] < obj->minData
					   ? obj->data[i]
					   : obj->minData;
		}
	}
}

int minStackTop(MinStack *obj)
{
	return obj->data[0];
}

int minStackGetMin(MinStack *obj)
{
	return obj->minData;
}

void minStackFree(MinStack *obj)
{
	free(obj->data);
}

int main()
{
	return 0;
}
