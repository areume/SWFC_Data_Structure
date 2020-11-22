// Exam02.c

#pragma warning(disable: 4996)
#pragma warning(disable: 4477)
#pragma warning(disable: 4313)

/***********************************************************/
// [1-2] 배열 기반 연결 리스트
/***********************************************************/

#if 0

/***********************************************************/
// [1-2.1] 데이터 모델링
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

// 이제부터 설계되는 모든 함수는 이 부분에 선언을 추가한다

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
// [1-2.2] 데이터 생성, 인쇄, 계수 함수 설계
/***********************************************************/

#if 01

int Create_Data(SCORE *p)
{
	printf("\n사번을 입력하시오 => ");
	scanf("%d", &p->id);
	fflush(stdin);
	printf("이름을 입력하시오 => ");
	scanf("%s", p->name);
	fflush(stdin);
	printf("점수를 입력하시오 => ");
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

int Insert_Data(SCORE *p)               // 배열에 자료를 생성하는 함수.
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
// [1-2.3] 데이터 하나를 생성하여 Linked List에 추가하는 함수
/***********************************************************/

// 내 코드

#if 0

int Insert_Node(SCORE *head, SCORE *d)
{
	int n = Count_Data();
	if (n == MAX_ST) return -1;

	while (head->next != NULL) { // 자료가 1개 이상 저장되어 있는 경우.
		if (head->next->id == d->id) return -2;

		if (head->next->id > d->id) {
			d->next = head->next;
			head->next = d;
			return 1;
		}
		head = head->next;
	}
	d->next = NULL;                  // 자료가 없는 경우 또는 마지막에 들어가는 경우.
	head->next = d;
	return 1;
}

#endif

// 강사님 코드

#if 01

int Insert_Node(SCORE *head, SCORE *d)
{
	int i;

	for (i = 0; i < MAX_ST; i++) {
		if ((head->next == NULL) || d->id < head->next->id) {    // 항상 head의 next가 NULL인지 먼저 체크해야 한다.
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
// [1-2.4] link에 따라서 각 노드의 정보를 인쇄하도록 함수
/***********************************************************/
/***********************************************************/
// [1-2.5] link에 따라서 주어진 사번에 맞는 노드 를 찾아 주소를 리턴하는 함수
/***********************************************************/

#if 01

// 개수를 반환하므로 for문을 사용하는 것이 좋다. -> Count_Node에서는 for문 사용해보기.

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
// [1-2.6] list에 저장된 자료의 총수를 계산하는 함수
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
// [1-2.7] link에 따라서 주어진 사번에 맞는 자료를 인쇄하는 함수
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
// [1-2.8] link에 따라서 주어진 사번의 node를 찾아서 삭제하는 함수
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
// [1-2.9] 주어진 버퍼에 자료를 모두 복사해 주는 함수 
/***********************************************************/

// 내 코드

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

// 강사님 코드

#if 0

int Copy_All_Node(SCORE *head, SCORE *buf)
{
	int i;

	if (head->next == NULL) return -1;           // 자료가 없으면 -1 리턴.

	for (i = 0; i < MAX_ST; i++) {
		if (head->next == NULL) break;           // 마지막 자료이면 반복문 탈출.

		buf[i] = *(head->next);                  // buf[i] 자리에 head->next 구조체를 복사 대입.
		buf[i].next = &buf[i + 1];              // buf[i]의 next에 다음 메모리 주소를 대입.
		head = head->next;                       // head 위치 변경.
	}
	buf[i - 1].next = NULL;                     // buf의 마지막 자료의 next를 NULL로 수정.
	return i;                                   // 요소 개수 반환.
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
// [1-2.10] node에서 요청한 자료의 수를 계수하거나 버퍼에 복사해 주는 함수
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