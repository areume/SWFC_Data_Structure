//Exam04.c

#pragma warning(disable: 4996)
#pragma warning(disable: 4477)
#pragma warning(disable: 4313)

/***********************************************************/
// [1-4] �迭 ��� ���� ����Ʈ - ���� ��ũ
/***********************************************************/

#if 0

/***********************************************************/
// [1-4.1] ���� Linked List ����� �״�� ����ϴ� �Լ���
// ��, �μ��� �� Prev Node ���� �μ��ϵ��� �߰��Ѵ�
/***********************************************************/

#if 01

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <malloc.h>

typedef struct _score
{
	int id;
	int jumsu;
	char name[10];
	struct _score  *next;
	struct _score  *prev;
}SCORE;

SCORE Head;

#define MAX_ST  20

SCORE exam[MAX_ST];

// �������� ����Ǵ� ��� �Լ��� �� �κп� ������ �߰��Ѵ�

int Print_All_Data(void);
int Print_Data(int no);
int Count_Data(void);
int Create_Data(SCORE * p);
int Insert_Data(SCORE * p);
int Insert_Node(SCORE * head, SCORE * d);
int Print_All_Node(SCORE * head);
int Print_All_Node_Reverse(SCORE * head);
SCORE * Search_Id_Node(SCORE * head, int id);
int Count_Node(SCORE * head);
int Delete_Node(SCORE * head, int id);
int Copy_All_Node(SCORE * head, SCORE * buf);
int Count_Name_Node(SCORE * head, char * name);
int Count_Score_Node(SCORE * head, int jumsu);
int Copy_Name_Node(SCORE * head, char * name, SCORE * buf);
int Copy_Score_Node(SCORE * head, int jumsu, SCORE * buf);
int Print_Selected_Node(SCORE *head, int id, int num);
int Print_Selected_Node_Reverse(SCORE *head, int id, int num);

SCORE test[MAX_ST] = { { 10, 50, "kim" },{ 2, 80, "lew" },{ 8, 50, "lew" },{ 4, 45, "lee" },{ 1, 90, "song" },\
{3, 45, "kim"},{ 5, 50, "song" },{ 9, 100, "lee" },{ 7, 75, "moon" },{ 6, 90, "park" }, \
{15, 90, "ki"},{ 11, 20, "kong" },{ 14, 40, "shin" },{ 12, 50, "son" },{ 17, 48, "lee" }, \
{20, 100, "min"},{ 19, 80, "you" },{ 13, 45, "song" },{ 16, 54, "no" },{ 18, 100, "yang" } };

void Make_Test_Data(int n)
{
	int i;

	for (i = 0; i < n; i++) {
		exam[i] = test[i];
	}
}

int Create_Data(SCORE * p)
{
	printf("\n����� �Է��Ͻÿ� => ");
	scanf("%d", &p->id);
	fflush(stdin);
	printf("�̸��� �Է��Ͻÿ� => ");
	scanf("%s", p->name);
	fflush(stdin);
	printf("������ �Է��Ͻÿ� => ");
	scanf("%d", &p->jumsu);
	fflush(stdin);
	p->next = (SCORE *)0x0;
	p->prev = (SCORE *)0x0;

	return 1;
}

int Print_All_Data(void)
{
	int i;

	printf("Head= 0x%.8X, Head.next=0x%.8X, Head.prev=0x%.8X\n", &Head, Head.next, Head.prev);

	for (i = 0; i < MAX_ST; i++) {
		if (exam[i].id == 0) break;
		printf("[%d] addr=0x%.8X, ID=%d, NAME=%s, SCORE=%d, next=0x%.8X, prev=0x%.8X\n", i, &exam[i], exam[i].id, exam[i].name, exam[i].jumsu, exam[i].next, exam[i].prev);
	}

	return i;
}

int Print_Data(int no)
{
	if (exam[no].id == 0) return -1;
	printf("[%d] addr=0x%.8X, ID=%d, NAME=%s, SCORE=%d, next=0x%.8X, prev=0x%.8X\n", no, &exam[no], exam[no].id, exam[no].name, exam[no].jumsu, exam[no].next, exam[no].prev);
	return 1;
}

int Count_Data(void)
{
	int i;

	for (i = 0; i < MAX_ST; i++) {
		if (exam[i].id == 0) break;
	}

	return i;
}

int Insert_Data(SCORE *p)
{
	int i;

	for (i = 0; i < MAX_ST; i++) {
		if (exam[i].id == 0) {
			exam[i] = (*p);
			return i;
		}

		if (exam[i].id == p->id) {
			return -2;
		}
	}
	return -1;
}

int Print_All_Node(SCORE *head)
{
	int i;

	printf("Head.next = 0x%.8X Head.prev = 0x%.8X\n", head->next, head->prev);

	for (i = 0; i < MAX_ST; i++) {
		if (head->next == (SCORE *)0x0) return i;
		printf("addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, next=0x%.8X, prev=0x%.8X\n", head->next, head->next->id, head->next->name, head->next->jumsu, head->next->next, head->next->prev);
		head = head->next;
	}
	return i;
}

int Count_Node(SCORE *head)
{
	int i;

	for (i = 0; i < MAX_ST; i++) {
		if (head->next == (SCORE *)0x0) return i;
		head = head->next;
	}
	return i;
}

int Copy_All_Node(SCORE * head, SCORE * buf)
{
	int i;
	if (head->next == (SCORE *)0x0) return -1;

	for (i = 0; i < MAX_ST; i++) {
		if (head->next == (SCORE *)0x0) break;
		buf[i] = *head->next;
		buf[i].next = &buf[i + 1];
		head = head->next;
	}
	buf[i - 1].next = (SCORE *)0x0;
	return i;
}

int Count_Name_Node(SCORE * head, char * name)
{
	int n = 0;

	for (;;) {
		if (head->next == (SCORE *)0x0) return n;
		if (!strcmp(head->next->name, name)) n++;
		head = head->next;
	}
}

int Count_Score_Node(SCORE * head, int jumsu)
{
	int n = 0;

	for (;;) {
		if (head->next == (SCORE *)0x0) return n;
		if (head->next->jumsu == jumsu) n++;
		head = head->next;
	}
}

int Copy_Name_Node(SCORE * head, char * name, SCORE * buf)
{
	int n = 0;

	for (;;) {
		if (head->next == (SCORE *)0x0) break;
		if (!strcmp(head->next->name, name)) {
			buf[n] = *head->next;
			buf[n].next = &buf[n + 1];
			n++;
		}
		head = head->next;
	}
	if (n > 0) buf[n - 1].next = (SCORE *)0x0;
	return n;
}

int Copy_Score_Node(SCORE * head, int jumsu, SCORE * buf)
{
	int n = 0;

	for (;;) {
		if (head->next == (SCORE *)0x0) break;
		if (head->next->jumsu == jumsu) {
			buf[n] = *head->next;
			buf[n].next = &buf[n + 1];
			n++;
		}
		head = head->next;
	}
	if (n > 0) buf[n - 1].next = (SCORE *)0x0;
	return n;
}

#endif

/***********************************************************/
// [1-4.2] ������ �ϳ��� �����Ͽ� Linked List�� �߰��ϴ� �Լ�
/***********************************************************/

#if 01

int Insert_Node(SCORE *head, SCORE *d)
{
	for (int i = 0; i < MAX_ST; i++) {
		if (head->next == NULL || head->next->id > d->id) {
			d->next = head->next;
			d->prev = head;
			if (head->next) head->next->prev = d;          // �������� �ڷḦ �߰��� ��� head->next�� �������� �ʴ´�. (NULL)
			head->next = d;

			return 1;
		}
		if (head->next->id == d->id) return -2;

		head = head->next;
	}
	return -1;
}

#endif

#if 0

void main(void)
{
	int i;
	int r;

	for (i = 0; i < 8; i++)
	{
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Printed Data Count = %d\n", Print_All_Data());
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
		printf("Printed Data Count = %d\n", Print_All_Data());
	}
}

#endif

/***********************************************************/
// [1-4.3] �־��� ����� node�� ã�Ƽ� �����ϴ� �Լ�
/***********************************************************/

#if 01

SCORE *Search_Id_Node(SCORE *head, int id)
{
	while (head->next != NULL) {
		if (head->next->id == id) return head->next;
		head = head->next;
	}
	return (SCORE *)NULL;
}

int Delete_Node(SCORE *head, int id)
{
	SCORE *p = Search_Id_Node(head, id);
	if (p == (SCORE *)NULL) return -1;

	p->id = 0;
	p->prev->next = p->next;
	if (p->next != NULL) p->next->prev = p->prev;
	return 1;
}

#endif

#if 0

void main(void)
{
	int i;
	int r;

	for (i = 0; i < 8; i++)
	{
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
	}

	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	printf("[8] Delete Node Result = %d\n", Delete_Node(&Head, 8));
	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	printf("[7] Delete Node Result = %d\n", Delete_Node(&Head, 7));
	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	printf("[1] Delete Node Result = %d\n", Delete_Node(&Head, 1));
	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	printf("[10] Delete Node Result = %d\n", Delete_Node(&Head, 10));
	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
}

#endif

/***********************************************************/
// [1-4.4] ���� ��ũ ����� ���� 1, �������� �˻�
/***********************************************************/

#if 01

int Print_All_Node_Reverse(SCORE *head)
{
	int i;

	printf("Head.next = 0x%.8X Head.prev = 0x%.8X\n", head->next, head->prev);

	for (i = 0; i < MAX_ST; i++) {
		if (head->next == NULL) break;
		head = head->next;
	}

	printf("Tail.next = 0x%.8X Tail.prev = 0x%.8X\n", head->next, head->prev);

	for (i = 0; i < MAX_ST; i++) {
		if (head->prev == NULL) break;
		printf("addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, next = 0x%.8X, prev = 0x%.8X\n",
			head, head->id, head->name, head->jumsu, head->next, head->prev);
		head = head->prev;
	}

	return i;
}

#endif

#if 0

void main(void)
{
	int i;
	int r;

	for (i = 0; i < 8; i++)
	{
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
	}

	printf("Printed Node Count(Up) = %d\n", Print_All_Node(&Head));
	printf("Printed Node Count(Down) = %d\n", Print_All_Node_Reverse(&Head));
	printf("[8] Delete Node Result = %d\n", Delete_Node(&Head, 8));
	printf("Printed Node Count(Down) = %d\n", Print_All_Node_Reverse(&Head));
}

#endif

/***********************************************************/
// [1-4.5] ���� ��ũ ����� ���� 2, ���������� ���� ���� �μ�
/***********************************************************/

#if 01

int Print_Selected_Node(SCORE *head, int id, int num)
{
	int i = 0;
	head = Search_Id_Node(head, id);
	if (head == NULL) return -1;

	while (i < num)
	{
		printf("addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, next=0x%.8X, prev=0x%.8X\n", head, head->id, head->name, head->jumsu, head->next, head->prev);
		i++;
		if (head->next == (SCORE *)0x0) break;
		head = head->next;
	}
	return i;
}

int Print_Selected_Node_Reverse(SCORE *head, int id, int num)
{
	int i = 0;

	head = Search_Id_Node(head, id);

	if (head == (SCORE *)0x0) return -1;

	while (i < num)
	{
		printf("addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, next=0x%.8X, prev=0x%.8X\n", head, head->id, head->name, head->jumsu, head->next, head->prev);
		i++;
		if (head->prev->prev == (SCORE *)0x0) break;
		head = head->prev;
	}
	return i;
}

#endif

#if 01

void main(void)
{
	int i;
	int r;

	for (i = 0; i < MAX_ST; i++)
	{
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
	}

	printf("Printed Node Count(Up) = %d\n", Print_All_Node(&Head));
	printf("Printed Node Count(Down) = %d\n", Print_All_Node_Reverse(&Head));

	r = Print_Selected_Node(&Head, 7, 3);
	printf("Printed Data Number => %d\n", r);

	r = Print_Selected_Node(&Head, 19, 3);
	printf("Printed Data Number => %d\n", r);

	r = Print_Selected_Node_Reverse(&Head, 7, 3);
	printf("Printed Data Number => %d\n", r);

	r = Print_Selected_Node_Reverse(&Head, 2, 3);
	printf("Printed Data Number => %d\n", r);
}

#endif

#endif