// Exam02.c

#pragma warning(disable: 4996)
#pragma warning(disable: 4477)
#pragma warning(disable: 4313)

/***********************************************************/
// [1-2] �迭 ��� ���� ����Ʈ
/***********************************************************/

#if 0

/***********************************************************/
// [1-2.1] ������ �𵨸�
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
}SCORE;

SCORE Head;

#define MAX_ST 20

SCORE exam[MAX_ST];

// �������� ����Ǵ� ��� �Լ��� �� �κп� ������ �߰��Ѵ�

int Print_All_Data(void);
int Print_Data(int no);
int Count_Data(void);
int Create_Data(SCORE * p);
int Insert_Data(SCORE * p);
int Insert_Node(SCORE * head, SCORE * d);
int Print_All_Node(SCORE * head);
SCORE * Search_Id_Node(SCORE * head, int id);
int Count_Node(SCORE * head);
int Print_Node(SCORE * head, int id);
int Delete_Node(SCORE * head, int id);
int Copy_All_Node(SCORE * head, SCORE * buf);
int Count_Name_Node(SCORE * head, char * name);
int Count_Score_Node(SCORE * head, int jumsu);
int Copy_Name_Node(SCORE * head, char * name, SCORE * buf);
int Copy_Score_Node(SCORE * head, int jumsu, SCORE * buf);

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

#endif

/***********************************************************/
// [1-2.2] ������ ����, �μ�, ��� �Լ� ����
/***********************************************************/

#if 01

int Create_Data(SCORE *p)
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

	return 1;
}

int Print_All_Data(void)
{
	int i;

	printf("Head.next = 0x%.8X\n", Head.next);

	for (i = 0; i < MAX_ST; i++) {
		if (exam[i].id == 0) break;
		printf("[%d] addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, next = 0x%.8X\n", i, &exam[i], exam[i].id, exam[i].name, exam[i].jumsu, exam[i].next);
	}
	return i;
}

int Print_Data(int no)
{
	if (exam[no].id == 0) return -1;
	printf("[%d] addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, next = 0x%.8X\n", no, &exam[no], exam[no].id, exam[no].name, exam[no].jumsu, exam[no].next);
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

int Insert_Data(SCORE *p)               // �迭�� �ڷḦ �����ϴ� �Լ�.
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

#endif

/***********************************************************/
// [1-2.3] ������ �ϳ��� �����Ͽ� Linked List�� �߰��ϴ� �Լ�
/***********************************************************/

// �� �ڵ�

#if 0

int Insert_Node(SCORE *head, SCORE *d)
{
	int n = Count_Data();
	if (n == MAX_ST) return -1;

	while (head->next != NULL) { // �ڷᰡ 1�� �̻� ����Ǿ� �ִ� ���.
		if (head->next->id == d->id) return -2;

		if (head->next->id > d->id) {
			d->next = head->next;
			head->next = d;
			return 1;
		}
		head = head->next;
	}
	d->next = NULL;                  // �ڷᰡ ���� ��� �Ǵ� �������� ���� ���.
	head->next = d;
	return 1;
}

#endif

// ����� �ڵ�

#if 01

int Insert_Node(SCORE *head, SCORE *d)
{
	int i;

	for (i = 0; i < MAX_ST; i++) {
		if ((head->next == NULL) || d->id < head->next->id) {    // �׻� head�� next�� NULL���� ���� üũ�ؾ� �Ѵ�.
			d->next = head->next;
			head->next = d;
			return 1;
		}
		if (d->id == head->next->id) return -2;

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
		printf("\n");
	}
}

#endif

/***********************************************************/
// [1-2.4] link�� ���� �� ����� ������ �μ��ϵ��� �Լ�
/***********************************************************/
/***********************************************************/
// [1-2.5] link�� ���� �־��� ����� �´� ��� �� ã�� �ּҸ� �����ϴ� �Լ�
/***********************************************************/

#if 01

// ������ ��ȯ�ϹǷ� for���� ����ϴ� ���� ����. -> Count_Node������ for�� ����غ���.

int Print_All_Node(SCORE *head)
{
	int cnt = 0;

	if (head->next == NULL) return 0;

	printf("Head.next = 0x%.8X\n", head->next);
	while (head->next != NULL) {
		printf("addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, next = 0x%.8X\n", head->next, head->next->id, head->next->name, head->next->jumsu, head->next->next);
		head = head->next;
		cnt++;
	}
	return cnt;
}

#endif

#if 01

SCORE *Search_Id_Node(SCORE *head, int id)
{
	while (head->next != NULL) {
		if (head->next->id == id) {
			return head->next;
		}
		head = head->next;
	}
	return (SCORE *)NULL;
}

#endif

#if 0

void main(void)
{
	int i;
	int r;
	SCORE *p;

	for (i = 0; i < 8; i++)
	{
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Printed Data Count = %d\n", Print_All_Data());
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
		printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	}

	printf("Searched Node Address = 0x%.8X\n", p = Search_Id_Node(&Head, 8));

	if (p != (SCORE *)0x0)
	{
		printf("ID=%d, NAME=%s, SCORE=%d, next = 0x%.8X\n", p->id, p->name, p->jumsu, p->next);
	}

	printf("Searched Node Address = 0x%.8X\n", p = Search_Id_Node(&Head, 7));

	if (p != (SCORE *)0x0)
	{
		printf("ID=%d, NAME=%s, SCORE=%d, next = 0x%.8X\n", p->id, p->name, p->jumsu, p->next);
	}
}

#endif

/***********************************************************/
// [1-2.6] list�� ����� �ڷ��� �Ѽ��� ����ϴ� �Լ�
/***********************************************************/

#if 01

int Count_Node(SCORE *head)
{
	int i;
	for (i = 0; i < MAX_ST; i++) {
		if (head->next == (SCORE *)NULL) return i;
		head = head->next;
	}
	return i;
}

#endif

/***********************************************************/
// [1-2.7] link�� ���� �־��� ����� �´� �ڷḦ �μ��ϴ� �Լ�
/***********************************************************/

#if 01

int Print_Node(SCORE *head, int id)
{
	SCORE *data;
	data = Search_Id_Node(head, id);

	if (data == (SCORE *)NULL) return -1;

	printf("ID = %d, NAME = %s, SCORE = %d, next = 0x%.8X\n", data->id, data->name, data->jumsu, data->next);
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
		d
			printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Printed Data Count = %d\n", Print_All_Data());
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
		printf("Printed Node Count = %d\n", Print_All_Node(&Head));
		printf("Node Count = %d\n", Count_Node(&Head));
	}

	printf("Print Node Result = %d\n", Print_Node(&Head, 8));
	printf("Print Node Result = %d\n", Print_Node(&Head, 7));
}

#endif

/***********************************************************/
// [1-2.8] link�� ���� �־��� ����� node�� ã�Ƽ� �����ϴ� �Լ�
/***********************************************************/

#if 01

int Delete_Node(SCORE *head, int id)
{
	while (head->next != NULL) {

		if (head->next->id == id) {
			head->next->id = 0;
			head->next = head->next->next;
			return 1;
		}
		if (head->next->id > id) return -1;

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

	for (i = 0; i < 8; i++) {
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
	}

	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	printf("Delete Node Result = %d\n", Delete_Node(&Head, 8));
	printf("Delete Node Result = %d\n", Delete_Node(&Head, 7));
	printf("Delete Node Result = %d\n", Delete_Node(&Head, 1));
	printf("Delete Node Result = %d\n", Delete_Node(&Head, 10));
	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
}

#endif

/***********************************************************/
// [1-2.9] �־��� ���ۿ� �ڷḦ ��� ������ �ִ� �Լ� 
/***********************************************************/

// �� �ڵ�

#if 01

int Copy_All_Node(SCORE *head, SCORE *buf)
{
	int i;

	if (head->next == NULL) return -1;
	for (i = 0; i < MAX_ST; i++) {
		if (head->next == NULL) break;

		buf[i] = *(head->next);
		buf[i].next = &buf[i + 1];
		head = head->next;
	}
	buf[i - 1].next = NULL;
	return i;
}

#endif

// ����� �ڵ�

#if 0

int Copy_All_Node(SCORE *head, SCORE *buf)
{
	int i;

	if (head->next == NULL) return -1;           // �ڷᰡ ������ -1 ����.

	for (i = 0; i < MAX_ST; i++) {
		if (head->next == NULL) break;           // ������ �ڷ��̸� �ݺ��� Ż��.

		buf[i] = *(head->next);                  // buf[i] �ڸ��� head->next ����ü�� ���� ����.
		buf[i].next = &buf[i + 1];              // buf[i]�� next�� ���� �޸� �ּҸ� ����.
		head = head->next;                       // head ��ġ ����.
	}
	buf[i - 1].next = NULL;                     // buf�� ������ �ڷ��� next�� NULL�� ����.
	return i;                                   // ��� ���� ��ȯ.
}

#endif

#if 0

void main(void)
{
	int i;
	int r;
	SCORE * p;
	SCORE new_head;

	for (i = 0; i < 8; i++)
	{
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
	}

	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	printf("Node Count = %d\n", r = Count_Node(&Head));

	p = calloc(r, sizeof(SCORE));
	printf("Copy All Node Result = %d\n", Copy_All_Node(&Head, p));
	new_head.next = p;
	printf("Printed Node Count = %d\n", Print_All_Node(&new_head));
	free(p);
}

#endif

/***********************************************************/
// [1-2.10] node���� ��û�� �ڷ��� ���� ����ϰų� ���ۿ� ������ �ִ� �Լ�
/***********************************************************/

#if 01

int Count_Name_Node(SCORE *head, char *name)
{
	int n = 0;
	for (;;) {
		if (head->next == (SCORE *)0x0) return n;
		if (!strcmp(head->next->name, name)) n++;
		head = head->next;
	}
}

int Count_Score_Node(SCORE *head, int jumsu)
{
	int n = 0;
	for (;;) {
		if (head->next == (SCORE *)0x0) return n;
		if (head->next->jumsu == jumsu) n++;
		head = head->next;
	}
}

int Copy_Name_Node(SCORE *head, char *name, SCORE *buf)
{
	int cnt = 0;

	for (int i = 0; i < MAX_ST; i++) {
		if (head->next == NULL) break;
		if (strcmp(head->next->name, name) == 0) {
			buf[cnt] = *(head->next);
			buf[cnt].next = &buf[cnt + 1];
			cnt++;
		}
		head = head->next;
	}
	if (cnt > 0) buf[cnt - 1].next = (SCORE *)NULL;
	return cnt;
}

int Copy_Score_Node(SCORE *head, int jumsu, SCORE *buf)
{
	int cnt = 0;

	for (int i = 0; i < MAX_ST; i++) {
		if (head->next == NULL) break;
		if (head->next->jumsu == jumsu) {
			buf[cnt] = *(head->next);
			buf[cnt].next = &buf[cnt + 1];
			cnt++;
		}
		head = head->next;
	}
	if (cnt > 0) buf[cnt - 1].next = (SCORE *)NULL;
	return cnt;
}

#endif

#if 0

void main(void)
{
	int i;
	int r;
	SCORE * p;
	SCORE new_head;

	for (i = 0; i < 20; i++) {
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
	}

	printf("Printed Node Count = %d\n", Print_All_Node(&Head));

	printf("Name Node Count = %d\n", r = Count_Name_Node(&Head, "lew"));
	p = calloc(r, sizeof(SCORE));
	printf("Copy Name Node Result = %d\n", Copy_Name_Node(&Head, "lew", p));
	new_head.next = p;
	printf("Printed Node Count = %d\n", Print_All_Node(&new_head));
	free(p);

	printf("Score Node Count = %d\n", r = Count_Score_Node(&Head, 100));
	p = calloc(r, sizeof(SCORE));
	printf("Copy Score Node Result = %d\n", Copy_Score_Node(&Head, 100, p));
	new_head.next = p;
	printf("Printed Node Count = %d\n", Print_All_Node(&new_head));
	free(p);
}

#endif

#endif