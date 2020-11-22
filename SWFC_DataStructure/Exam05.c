// Exam05.c

#pragma warning(disable: 4996)
#pragma warning(disable: 4477)
#pragma warning(disable: 4313)

/***********************************************************/
// [1-5] 선형 리스트 - stack
/***********************************************************/

#if 0

#include <stdio.h>

#define MAX_STACK   10
#define STACK_EMPTY MAX_STACK
#define STACK_FULL  0

int Push_Stack(int data);
int Pop_Stack(int *p);
int Print_Stack(void);
int Count_Full_Data_Stack(void);
int Count_Empty_Data_Stack(void);

int a[MAX_STACK + 1] = { 1,2,3,4,5,6,7,8,9,10,11 };
int Stack[MAX_STACK];
int Sptr = STACK_EMPTY;

int Push_Stack(int data)
{
	if (Sptr == STACK_FULL) return -1;

	Stack[--Sptr] = data;
	return 1;
}

int Pop_Stack(int *p)
{
	if (Sptr == STACK_EMPTY) return -1;

	*p = Stack[Sptr++];
	return 1;
}

int Print_Stack(void)
{
	int i;

	for (i = Sptr; i < MAX_STACK; i++) {
		printf("STACK[%d] = %d\n", i, Stack[i]);
	}
	return MAX_STACK - Sptr;
}

int Count_Full_Data_Stack(void)
{
	return STACK_EMPTY - Sptr;
}

int Count_Empty_Data_Stack(void)
{
	return Sptr - STACK_FULL;
}

void main(void)
{
	int i;

	for (i = 0; i < (MAX_STACK + 1); i++) {
		printf("%d, ", a[i]);
	}
	printf("\n");

	for (i = 0; i < 5; i++)
	{
		printf("Push Result = %d\n", Push_Stack(a[i]));
		printf("Print Result = %d, ", Print_Stack());
		printf("Full = %d ", Count_Full_Data_Stack());
		printf("Empty = %d\n", Count_Empty_Data_Stack());
		printf("Sptr = %d\n", Sptr);
	}

	for (i = 0; i < 5; i++)
	{
		printf("Pop Result = %d\n", Pop_Stack(&a[i]));
		printf("Print Result = %d, ", Print_Stack());
		printf("Full = %d ", Count_Full_Data_Stack());
		printf("Empty = %d\n", Count_Empty_Data_Stack());
		printf("Sptr = %d\n", Sptr);
	}

	for (i = 0; i < (MAX_STACK + 1); i++)
	{
		printf("%d, ", a[i]);
	}

	printf("\n");

	for (i = 0; i < (MAX_STACK + 1); i++)
	{
		printf("Push Result = %d\n", Push_Stack(a[i]));
		printf("Print Result = %d, ", Print_Stack());
		printf("Full = %d ", Count_Full_Data_Stack());
		printf("Empty = %d\n", Count_Empty_Data_Stack());
		printf("Sptr = %d\n", Sptr);
	}

	for (i = 0; i < (MAX_STACK + 1); i++)
	{
		printf("Pop Result = %d\n", Pop_Stack(&a[i]));
		printf("Print Result = %d, ", Print_Stack());
		printf("Full = %d ", Count_Full_Data_Stack());
		printf("Empty = %d\n", Count_Empty_Data_Stack());
		printf("Sptr = %d\n", Sptr);
	}

	for (i = 0; i < (MAX_STACK + 1); i++)
	{
		printf("%d, ", a[i]);
	}

	printf("\n");
}

#endif

/***********************************************************/
// [1-6] 선형 리스트 - Linear Queue
/***********************************************************/

#if 0

#include <stdio.h>

#define MAX_Q   5
#define Q_EMPTY 0
#define Q_FULL  MAX_Q

int In_Queue(int data);
int Out_Queue(int *p);
int Print_Queue(void);
int Count_Full_Data_Queue(void);
int Count_Empty_Data_Queue(void);

int a[MAX_Q + 1] = { 1,2,3,4,5,6 };
int Queue[MAX_Q];
int Wrptr = Q_EMPTY;
int Rdptr = Q_EMPTY;

int In_Queue(int data)
{
	if (Wrptr == Q_FULL) {
		// 1] 저장 공간이 없는 경우
		if (Rdptr == Q_EMPTY) return -1;
		else {  // 2] 버퍼 공간이 있는 경우
			int cnt = Wrptr - Rdptr;
			for (int i = 0; i < cnt; i++) {
				Queue[i] = Queue[Rdptr++];
			}
			Rdptr = Q_EMPTY; Wrptr = cnt;
		}
	}
	Queue[Wrptr++] = data;
	return 1;
}

int Out_Queue(int *p)
{
	if (Rdptr == Wrptr) return -1;

	*p = Queue[Rdptr++];
	return 1;
}

int Print_Queue(void)
{
	int i;

	for (i = Rdptr; i < Wrptr; i++)
	{
		printf("Queue[%d] = %d\n", i, Queue[i]);
	}

	return Wrptr - Rdptr;
}

int Count_Full_Data_Queue(void)
{
	return Wrptr - Rdptr;
}

int Count_Empty_Data_Queue(void)
{
	return MAX_Q - (Wrptr - Rdptr);
}

void main(void)
{
	int i;

	for (i = 0; i < (MAX_Q + 1); i++)
	{
		printf("%d, ", a[i]);
	}

	printf("\n");

	for (i = 0; i < 3; i++)
	{
		printf("Queue Result = %d\n", In_Queue(a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d ", Count_Full_Data_Queue());
		printf("Empty = %d\n", Count_Empty_Data_Queue());
		printf("Wrptr = %d, Rdptr = %d\n", Wrptr, Rdptr);
	}

	for (i = 0; i < 3; i++)
	{
		a[i] = 0;
	}

	for (i = 0; i < 3; i++)
	{
		printf("Dequeue Result = %d\n", Out_Queue(&a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d ", Count_Full_Data_Queue());
		printf("Empty = %d\n", Count_Empty_Data_Queue());
		printf("Wrptr = %d, Rdptr = %d\n", Wrptr, Rdptr);
	}

	for (i = 0; i < (MAX_Q + 1); i++)
	{
		printf("%d, ", a[i]);
	}

	printf("\n");

	for (i = 0; i < (MAX_Q + 1); i++)
	{
		printf("Queue Result = %d\n", In_Queue(a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d ", Count_Full_Data_Queue());
		printf("Empty = %d\n", Count_Empty_Data_Queue());
		printf("Wrptr = %d, Rdptr = %d\n", Wrptr, Rdptr);
	}

	for (i = 0; i < (MAX_Q + 1); i++)
	{
		a[i] = 0;
	}

	for (i = 0; i < (MAX_Q + 1); i++)
	{
		printf("Dequeue Result = %d\n", Out_Queue(&a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d ", Count_Full_Data_Queue());
		printf("Empty = %d\n", Count_Empty_Data_Queue());
		printf("Wrptr = %d, Rdptr = %d\n", Wrptr, Rdptr);
	}

	for (i = 0; i < (MAX_Q + 1); i++)
	{
		printf("%d, ", a[i]);
	}

	printf("\n");
}

#endif

/***********************************************************/
// [1-7] 선형 리스트 - Circular Queue
/***********************************************************/

#if 0

#include <stdio.h>

#define MAX_Q   8
#define Q_MIN   0
#define Q_MAX   MAX_Q

int In_Queue(int data);
int Out_Queue(int *p);
int Print_Queue(void);
int Count_Full_Data_Queue(void);
int Count_Empty_Data_Queue(void);

int a[MAX_Q + 1] = { 1,2,3,4,5,6,7,8,9 };
int Queue[MAX_Q];
int Wrptr = Q_MIN;
int Rdptr = Q_MIN;

int In_Queue(int data)
{
	if (((Wrptr + 1) % MAX_Q) == Rdptr) return -1;

	Queue[Wrptr++] = data; Wrptr %= MAX_Q;
	return 1;
}

int Out_Queue(int *p)
{
	if (Rdptr == Wrptr) return -1;

	*p = Queue[Rdptr++]; Rdptr %= MAX_Q;
	return 1;
}

int Print_Queue(void)
{
	int i;
	int rd = Rdptr;
	int n = Count_Full_Data_Queue();

	for (i = 0; i < n; i++)  // 큐에 담긴 데이터 수만큼만 출력 반복문 진행
	{
		printf("Queue[%d] = %d\n", rd, Queue[rd]);
		rd++;
		rd %= MAX_Q;        // 순환해야하므로 항상 나머지 값으로 갱신.
	}
	return n;
}

int Count_Full_Data_Queue(void)
{
	if (Rdptr > Wrptr) return MAX_Q - (Rdptr - Wrptr);
	return Wrptr - Rdptr;
}

int Count_Empty_Data_Queue(void)
{
	return MAX_Q - Count_Full_Data_Queue() - 1;
}

void main(void)
{
	int i;

	for (i = 0; i < (MAX_Q + 1); i++)
	{
		printf("%d, ", a[i]);
	}

	printf("\n");

	for (i = 0; i < 3; i++)
	{
		printf("Queue Result = %d\n", In_Queue(a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d ", Count_Full_Data_Queue());
		printf("Empty = %d\n", Count_Empty_Data_Queue());
		printf("Wrptr = %d, Rdptr = %d\n", Wrptr, Rdptr);
	}

	for (i = 0; i < 3; i++)
	{
		a[i] = 0;
	}

	for (i = 0; i < 3; i++)
	{
		printf("Dequeue Result = %d\n", Out_Queue(&a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d ", Count_Full_Data_Queue());
		printf("Empty = %d\n", Count_Empty_Data_Queue());
		printf("Wrptr = %d, Rdptr = %d\n", Wrptr, Rdptr);
	}

	for (i = 0; i < (MAX_Q + 1); i++)
	{
		printf("%d, ", a[i]);
	}

	printf("\n");

	for (i = 0; i < (MAX_Q + 1); i++)
	{
		printf("Queue Result = %d\n", In_Queue(a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d ", Count_Full_Data_Queue());
		printf("Empty = %d\n", Count_Empty_Data_Queue());
		printf("Wrptr = %d, Rdptr = %d\n", Wrptr, Rdptr);
	}

	for (i = 0; i < (MAX_Q + 1); i++)
	{
		a[i] = 0;
	}

	for (i = 0; i < (MAX_Q + 1); i++)
	{
		printf("Dequeue Result = %d\n", Out_Queue(&a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d ", Count_Full_Data_Queue());
		printf("Empty = %d\n", Count_Empty_Data_Queue());
		printf("Wrptr = %d, Rdptr = %d\n", Wrptr, Rdptr);
	}

	for (i = 0; i < (MAX_Q + 1); i++)
	{
		printf("%d, ", a[i]);
	}

	printf("\n");
}

#endif