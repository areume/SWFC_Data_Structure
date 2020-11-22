//Exam06.c

#pragma warning(disable: 4996)
#pragma warning(disable: 4477)
#pragma warning(disable: 4313)

/***********************************************************/
// [2-1] 힙 기반 Linked List
/***********************************************************/

#if 0

/***********************************************************/
// [2-1.1] 기존 배열 기반 linked list 방식중 그대로 사용하는 함수들
/***********************************************************/

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <malloc.h>

typedef struct _score
{
	int id;
	int jumsu;
	char name[10];
	struct _score  * next;
}SCORE;

SCORE Head;

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

#define MAX_ST  20

SCORE test[MAX_ST] = { { 10, 50, "kim" },{ 2, 80, "lew" },{ 8, 50, "lew" },{ 4, 45, "lee" },{ 1, 90, "song" },\
{3, 45, "kim"},{ 5, 50, "song" },{ 9, 100, "lee" },{ 7, 75, "moon" },{ 6, 90, "park" }, \
{15, 90, "ki"},{ 11, 20, "kong" },{ 14, 40, "shin" },{ 12, 50, "son" },{ 17, 48, "lee" }, \
{20, 100, "min"},{ 19, 80, "you" },{ 13, 45, "song" },{ 16, 54, "no" },{ 18, 100, "yang" } };

int Create_Data(SCORE * p)
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

int Print_All_Node(SCORE * head)
{
	int n = 0;

	printf("Head.next = 0x%.8X\n", head->next);

	for (;;)
	{
		if (head->next == (SCORE *)0x0) return n;
		printf("addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, next = 0x%.8X\n", head->next, head->next->id, head->next->name, head->next->jumsu, head->next->next);
		n++;
		head = head->next;
	}
}

SCORE *Search_Id_Node(SCORE * head, int id)
{
	for (;;)
	{
		if (head->next == (SCORE *)0x0) return (SCORE *)0x0;
		if (head->next->id == id) return head->next;
		head = head->next;
	}
}

int Count_Node(SCORE * head)
{
	int n = 0;

	for (;;)
	{
		if (head->next == (SCORE *)0x0) return n;
		n++;
		head = head->next;
	}
}

int Print_Node(SCORE * head, int id)
{
	SCORE * p = Search_Id_Node(head, id);

	if (p != (SCORE *)0x0)
	{
		printf("ID=%d, NAME=%s, SCORE=%d, next = 0x%.8X\n", p->id, p->name, p->jumsu, p->next);
		return 1;
	}

	return -1;
}

int Copy_All_Node(SCORE * head, SCORE * buf)
{
	int n = 0;

	if (head->next == (SCORE *)0x0) return -1;

	for (;;)
	{
		if (head->next == (SCORE *)0x0) break;
		buf[n] = *head->next;
		buf[n].next = &buf[n + 1];
		n++;
		head = head->next;
	}
	buf[n - 1].next = NULL;
	return n;
}

int Count_Name_Node(SCORE * head, char * name)
{
	int n = 0;

	for (;;)
	{
		if (head->next == (SCORE *)0x0) return n;
		if (!strcmp(head->next->name, name)) n++;
		head = head->next;
	}
}

int Count_Score_Node(SCORE * head, int jumsu)
{
	int n = 0;

	for (;;)
	{
		if (head->next == (SCORE *)0x0) return n;
		if (head->next->jumsu == jumsu) n++;
		head = head->next;
	}
}

int Copy_Name_Node(SCORE * head, char * name, SCORE * buf)
{
	int n = 0;

	for (;;)
	{
		if (head->next == (SCORE *)0x0) break;
		if (!strcmp(head->next->name, name))
		{
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

	for (;;)
	{
		if (head->next == (SCORE *)0x0) break;
		if (head->next->jumsu == jumsu)
		{
			buf[n] = *head->next;
			buf[n].next = &buf[n + 1];
			n++;
		}
		head = head->next;
	}
	if (n > 0) buf[n - 1].next = (SCORE *)0x0;
	return n;
}

/***********************************************************/
// [2-1.2] 전달받은 데이터를 힙에 생성하고 Linked List에 추가하는 함수 (calloc 사용)
/***********************************************************/

#if 01

int Insert_Node(SCORE *head, SCORE *d)
{
	SCORE *p;

	for (;;) {  // heap 기반에서는 무한루프로 돌려줘야 한다.
		if (head->next == NULL || head->next->id > d->id) {
			p = calloc(1, sizeof(SCORE));

			if (p == (SCORE *)NULL) return -1;  // malloc이나 calloc 사용 시, 반환값을 반드시 확인해주어야 한다.
			*p = *d;                            // p=d로 작성하면 p는 test 배열의 요소를 가리키게 되므로 heap에 생성된 것이 아니다.

			p->next = head->next;
			head->next = p;

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
	SCORE * p;

	for (i = 0; i < 8; i++)
	{
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &test[i]));
	}

	printf("Printed Node Count = %d\n", Print_All_Node(&Head));

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
// [2-1.3] 전달받은 사번의 자료를 링크와 힙에서 삭제하는 함수 (free 사용)
/***********************************************************/

#if 01

int Delete_Node(SCORE *head, int id)
{
	SCORE *p;

	while (head->next != (SCORE *)NULL) {
		if (head->next->id == id) {
			p = head->next;
			head->next = p->next;
			free(p);
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

	for (i = 0; i < 8; i++)
	{
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &test[i]));
	}

	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	printf("Delete Node Result = %d\n", Delete_Node(&Head, 8));
	printf("Delete Node Result = %d\n", Delete_Node(&Head, 7));
	printf("Delete Node Result = %d\n", Delete_Node(&Head, 1));
	printf("Delete Node Result = %d\n", Delete_Node(&Head, 10));
	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
}

#endif

#endif

/***********************************************************/
// [2-2] 힙 기반 연결 리스트 - 다중 링크
/***********************************************************/

#if 0

/***********************************************************/
// 기존 배열 기반 연결 리스트와 동일하게 사용되는 함수들 
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
	struct _score  * nid;
	struct _score  * njumsu;
}SCORE;

SCORE Head;

#define MAX_ST      20

SCORE exam[MAX_ST];

// 이제부터 설계되는 모든 함수는 이 부분에 선언을 추가한다

int Print_All_Data(void);
int Print_Data(int no);
int Count_Data(void);
int Create_Data(SCORE * p);
int Insert_Data(SCORE * p);
int Insert_Node(SCORE * head, SCORE * d);
int Print_All_Node(SCORE * head);
int Print_All_Id_Node(SCORE * head);
int Print_All_Jumsu_Node(SCORE * head);
SCORE * Search_Id_Node(SCORE * head, int id);
SCORE * Search_Jumsu_Node(SCORE * head, int jumsu);
int Count_Node(SCORE * head);
int Print_Id_Node(SCORE * head, int id);
int Print_Jumsu_Node(SCORE * head, int jumsu);
int Delete_Id_Node(SCORE * head, int id);
void Delete_One_Jumsu_Node(SCORE * head, int jumsu, int id);
int Delete_Jumsu_Node(SCORE * head, int id);
int Copy_All_Node(SCORE * head, SCORE * buf);
int Count_Name_Node(SCORE * head, char * name);
int Count_Score_Node(SCORE * head, int jumsu);
int Copy_Name_Node(SCORE * head, char * name, SCORE * buf);
int Copy_Score_Node(SCORE * head, int jumsu, SCORE * buf);

SCORE test[MAX_ST] = { { 10, 50, "kim" },{ 2, 80, "lew" },{ 8, 50, "lew" },{ 4, 45, "lee" },{ 1, 90, "song" },\
{3, 45, "kim"},{ 5, 50, "song" },{ 9, 100, "lee" },{ 7, 75, "moon" },{ 6, 90, "park" }, \
{15, 90, "ki"},{ 11, 20, "kong" },{ 14, 40, "shin" },{ 12, 50, "son" },{ 17, 48, "lee" }, \
{20, 100, "min"},{ 19, 80, "you" },{ 13, 45, "song" },{ 16, 54, "no" },{ 18, 100, "yang" } };

int Create_Data(SCORE * p)
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
	p->nid = (SCORE *)0x0;
	p->njumsu = (SCORE *)0x0;

	return 1;
}


int Print_All_Node(SCORE * head)
{
	Print_All_Id_Node(head);
	return Print_All_Jumsu_Node(head);
}

int Print_All_Id_Node(SCORE * head)
{
	int i = 0;

	printf("[Id] Head.nid = 0x%.8X\n", head->nid);

	for (;;)
	{
		if (head->nid == (SCORE *)0x0) return i;
		printf("addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, nid = 0x%.8X\n", head->nid, head->nid->id, head->nid->name, head->nid->jumsu, head->nid->nid);
		head = head->nid;
		i++;
	}
}

int Print_All_Jumsu_Node(SCORE * head)
{
	int i = 0;

	printf("[Jumsu] Head.njumsu = 0x%.8X\n", head->njumsu);

	for (;;)
	{
		if (head->njumsu == (SCORE *)0x0) return i;
		printf("addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, njumsu = 0x%.8X\n", head->njumsu, head->njumsu->id, head->njumsu->name, head->njumsu->jumsu, head->njumsu->njumsu);
		head = head->njumsu;
		i++;
	}
}

SCORE *Search_Id_Node(SCORE * head, int id)
{
	for (;;)
	{
		if (head->nid == (SCORE *)0x0) return (SCORE *)0x0;
		if (head->nid->id == id) return head->nid;
		head = head->nid;
	}
}

SCORE *Search_Jumsu_Node(SCORE * head, int jumsu)
{
	for (;;)
	{
		if (head->njumsu == (SCORE *)0x0) return (SCORE *)0x0;
		if (head->njumsu->jumsu == jumsu) return head->njumsu;
		head = head->njumsu;
	}
}

int Count_Node(SCORE * head)
{
	int n = 0;

	for (;;)
	{
		if (head->nid == (SCORE *)0x0) return n;
		head = head->nid;
		n++;
	}
}

int Print_Id_Node(SCORE * head, int id)
{
	SCORE * p = Search_Id_Node(head, id);

	if (p != (SCORE *)0x0)
	{
		printf("ID=%d, NAME=%s, SCORE=%d, nid = 0x%.8X\n", p->id, p->name, p->jumsu, p->nid);
		return 1;
	}

	return -1;
}

int Print_Jumsu_Node(SCORE * head, int jumsu)
{
	SCORE * p = head;
	int r = -1;

	for (;;)
	{
		p = Search_Jumsu_Node(p, jumsu);
		if (p == (SCORE *)0x0) break;
		printf("ID=%d, NAME=%s, SCORE=%d, njumsu = 0x%.8X\n", p->id, p->name, p->jumsu, p->njumsu);
		r = 1;
	}

	return r;
}

int Count_Name_Node(SCORE * head, char * name)
{
	int n = 0;

	for (;;)
	{
		if (head->nid == (SCORE *)0x0) return n;
		if (!strcmp(head->nid->name, name)) n++;
		head = head->nid;
	}
}

int Count_Score_Node(SCORE * head, int jumsu)
{
	int n = 0;

	for (;;)
	{
		if (head->njumsu == (SCORE *)0x0) return n;
		if (head->njumsu->jumsu == jumsu) n++;
		head = head->njumsu;
	}
}

int Copy_Name_Node(SCORE * head, char * name, SCORE * buf)
{
	int n = 0;

	for (;;)
	{
		if (head->nid == (SCORE *)0x0) break;
		if (!strcmp(head->nid->name, name))
		{
			buf[n] = *head->nid;
			buf[n].nid = &buf[n + 1];
			n++;
		}
		head = head->nid;
	}
	if (n > 0) buf[n - 1].nid = (SCORE *)0x0;
	return n;
}

int Copy_Score_Node(SCORE * head, int jumsu, SCORE * buf)
{
	int n = 0;

	for (;;)
	{
		if (head->njumsu == (SCORE *)0x0) break;
		if (head->njumsu->jumsu == jumsu)
		{
			buf[n] = *head->njumsu;
			buf[n].njumsu = &buf[n + 1];
			n++;
		}
		head = head->njumsu;
	}
	if (n > 0) buf[n - 1].njumsu = (SCORE *)0x0;
	return n;
}

#endif

/***********************************************************/
// [2-2.1] 데이터 하나를 생성하여 Linked List에 추가하는 함수  (calloc 사용)
/***********************************************************/

#if 01

int Insert_Node(SCORE *head, SCORE * d)
{
	SCORE *p;
	SCORE *temp = head;

	for (;;) {
		if (head->nid == (SCORE *)NULL || head->nid->id > d->id) {
			p = calloc(1, sizeof(SCORE));
			if (p == (SCORE *)NULL) return -1;

			*p = *d;
			p->nid = head->nid;
			head->nid = p;
			break;
		}
		if (head->nid->id == d->id) return -2;
		head = head->nid;
	}
	head = temp;

	for (;;) {
		if (head->njumsu == (SCORE *)NULL || head->njumsu->jumsu > d->jumsu) {
			p->njumsu = head->njumsu;
			head->njumsu = p;
			return 1;
		}
		head = head->njumsu;
	}
	return -1;
}

#endif

#if 0

void main(void)
{
	int i;

	for (i = 0; i < 8; i++)
	{
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &test[i]));
		printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	}
}

#endif

/***********************************************************/
// [2-2.2] link에 따라서 주어진 사번의 node를 찾아서 삭제하는 함수 (free 사용)
/***********************************************************/

#if 01

int Delete_Id_Node(SCORE *head, int id)
{
	SCORE *p = head;

	while (head->nid != NULL) {
		if (head->nid->id == id) {
			Delete_One_Jumsu_Node(p, head->nid->jumsu, id);

			p = head->nid;
			head->nid = head->nid->nid;
			free(p);
			return 1;
		}
		head = head->nid;
	}
	return -1;
}

void Delete_One_Jumsu_Node(SCORE *head, int jumsu, int id)
{
	while (head->njumsu != NULL) {
		if (head->njumsu->jumsu == jumsu && head->njumsu->id == id) {
			head->njumsu = head->njumsu->njumsu;
			return;
		}
		head = head->njumsu;
	}
}

int Delete_Jumsu_Node(SCORE * head, int jumsu)
{
	SCORE *p = head;

	int flag = -1;

	while (head->njumsu != NULL) {
		p = Search_Jumsu_Node(head, jumsu);     // 배열기반에서는 p를 넘겨주었지만, 힙기반에서는 head를 넘겨준다
		if (p == NULL) break;                   //

		Delete_Id_Node(head, p->id);
		flag = 1;
	}
	return flag;
}

#endif

#if 0

void main(void)
{
	int i;

	for (i = 0; i < MAX_ST; i++)
	{
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &test[i]));
	}

	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	printf("Delete Id(8) Node Result = %d\n", Delete_Id_Node(&Head, 8));
	printf("Delete Id(7) Node Result = %d\n", Delete_Id_Node(&Head, 7));
	printf("Delete Id(1) Node Result = %d\n", Delete_Id_Node(&Head, 1));
	printf("Delete Id(10) Node Result = %d\n", Delete_Id_Node(&Head, 10));
	printf("Delete Id(25) Node Result = %d\n", Delete_Id_Node(&Head, 25));
	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	printf("Delete Jumsu(45) Node Result = %d\n", Delete_Jumsu_Node(&Head, 45));
	printf("Delete Jumsu(20) Node Result = %d\n", Delete_Jumsu_Node(&Head, 20));
	printf("Delete Jumsu(90) Node Result = %d\n", Delete_Jumsu_Node(&Head, 90));
	printf("Delete Jumsu(100) Node Result = %d\n", Delete_Jumsu_Node(&Head, 100));
	printf("Delete Jumsu(87) Node Result = %d\n", Delete_Jumsu_Node(&Head, 97));
	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
}

#endif

#endif

/***********************************************************/
// [2-3] 힙 기반 연결 리스트 - 더블 링크
/***********************************************************/

#if 0

/***********************************************************/
// [2-3.1] 기존 Linked List 방식중 그대로 사용하는 함수들
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
	struct _score  * next;
	struct _score  * prev;
}SCORE;

SCORE Head;

#define MAX_ST      20


// 이제부터 설계되는 모든 함수는 이 부분에 선언을 추가한다

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
int Print_Node(SCORE * head, int id);
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


int Create_Data(SCORE * p)
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
	p->prev = (SCORE *)0x0;

	return 1;
}

SCORE * Search_Id_Node(SCORE * head, int id)
{
	for (;;)
	{
		if (head->next == (SCORE *)0x0) return (SCORE *)0x0;
		if (head->next->id == id) return head->next;
		head = head->next;
	}
}

int Count_Node(SCORE * head)
{
	int i = 0;

	for (;;)
	{
		if (head->next == (SCORE *)0x0) return i;
		head = head->next;
		i++;
	}
}

int Print_Node(SCORE * head, int id)
{
	SCORE * p = Search_Id_Node(head, id);

	if (p != (SCORE *)0x0)
	{
		printf("ID=%d, NAME=%s, SCORE=%d, next=0x%.8X, prev=0x%.8X\n", p->id, p->name, p->jumsu, p->next, p->prev);
		return 1;
	}

	return -1;
}

int Copy_All_Node(SCORE * head, SCORE * buf)
{
	int n = 0;

	if (head->next == (SCORE *)0x0) return -1;

	for (;;)
	{
		if (head->next == (SCORE *)0x0) break;
		buf[n] = *head->next;
		buf[n].next = &buf[n + 1];
		n++;
		head = head->next;
	}
	buf[n - 1].next = NULL;
	return n;
}

int Count_Name_Node(SCORE * head, char * name)
{
	int n = 0;

	for (;;)
	{
		if (head->next == (SCORE *)0x0) return n;
		if (!strcmp(head->next->name, name)) n++;
		head = head->next;
	}
}

int Count_Score_Node(SCORE * head, int jumsu)
{
	int n = 0;

	for (;;)
	{
		if (head->next == (SCORE *)0x0) return n;
		if (head->next->jumsu == jumsu) n++;
		head = head->next;
	}
}

int Copy_Name_Node(SCORE * head, char * name, SCORE * buf)
{
	int n = 0;

	for (;;)
	{
		if (head->next == (SCORE *)0x0) break;
		if (!strcmp(head->next->name, name))
		{
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

	for (;;)
	{
		if (head->next == (SCORE *)0x0) break;
		if (head->next->jumsu == jumsu)
		{
			buf[n] = *head->next;
			buf[n].next = &buf[n + 1];
			n++;
		}
		head = head->next;
	}
	if (n > 0) buf[n - 1].next = (SCORE *)0x0;
	return n;
}

int Print_All_Node(SCORE * head)
{
	int i = 0;

	printf("Head.next = 0x%.8X Head.prev = 0x%.8X\n", head->next, head->prev);

	for (;;)
	{
		if (head->next == (SCORE *)0x0) return i;
		printf("addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, next=0x%.8X, prev=0x%.8X\n", head->next, head->next->id, head->next->name, head->next->jumsu, head->next->next, head->next->prev);
		head = head->next;
		i++;
	}
}

int Print_All_Node_Reverse(SCORE * head)
{
	int i = 0;

	printf("Head.next = 0x%.8X Head.prev = 0x%.8X\n", head->next, head->prev);

	while (head->next != (SCORE *)0x0)
	{
		head = head->next;
	}

	printf("Tail.next = 0x%.8X Tail.prev = 0x%.8X\n", head->next, head->prev);

	for (;;)
	{
		if (head->prev == (SCORE *)0x0) return i;
		printf("addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, next=0x%.8X, prev=0x%.8X\n", head, head->id, head->name, head->jumsu, head->next, head->prev);
		head = head->prev;
		i++;
	}
}

int Print_Selected_Node(SCORE * head, int id, int num)
{
	int i = 0;

	head = Search_Id_Node(head, id);

	if (head == (SCORE *)0x0) return -1;

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

/***********************************************************/
// [2-3.2] 데이터 하나를 생성하여 Linked List에 추가하는 함수 (calloc 사용)
/***********************************************************/

#if 01

int Insert_Node(SCORE * head, SCORE * d)
{
	SCORE *p;

	for (;;) {
		if (head->next == (SCORE *)NULL || head->next->id > d->id) {
			p = calloc(1, sizeof(SCORE));
			if (p == NULL) return -1;

			*p = *d;
			p->next = head->next;
			p->prev = head;

			head->next = p;
			if (p->next != NULL) p->next->prev = p;

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

	for (i = 0; i < 8; i++)
	{
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &test[i]));
		printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	}
}

#endif

/***********************************************************/
// [2-3.3] 주어진 사번의 node를 찾아서 삭제하는 함수
/***********************************************************/

#if 01

int Delete_Node(SCORE *head, int id)
{
	SCORE *p = Search_Id_Node(head, id);

	if (p == NULL) return -1;

	p->prev->next = p->next;
	if (p->next != NULL) p->next->prev = p->prev;;
	free(p);

	return 1;
}

#endif

#if 0

void main(void)
{
	int i;

	for (i = 0; i < 8; i++)
	{
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &test[i]));
	}

	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	printf("Delete Node Result = %d\n", Delete_Node(&Head, 8));
	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	printf("Delete Node Result = %d\n", Delete_Node(&Head, 7));
	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	printf("Delete Node Result = %d\n", Delete_Node(&Head, 1));
	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	printf("Delete Node Result = %d\n", Delete_Node(&Head, 10));
	printf("Printed Node Count = %d\n", Print_All_Node(&Head));
}

#endif

#endif

/***********************************************************/
// [2-4] 힙 기반 stack
/***********************************************************/

#if 0

#include <stdio.h>
#include <malloc.h>

typedef struct _stk
{
	int num;
	struct _stk *next;
}STACK;

STACK *Sptr = (STACK *)0;
STACK a[10] = { { 1,0 },{ 2,0 },{ 3,0 },{ 4,0 },{ 5,0 },{ 6,0 },{ 7,0 },{ 8,0 },{ 9,0 },{ 10,0 } };

int Push_Stack(STACK *data);
int Pop_Stack(STACK *p);
int Print_Stack(void);
int Count_Full_Data_Stack(void);

int Push_Stack(STACK *data)
{
	// 여기서부터 작성






}

int Pop_Stack(STACK *p)
{
	// 여기서부터 작성






}

int Print_Stack(void)
{
	// 여기서부터 작성






}

int Count_Full_Data_Stack(void)
{
	// 여기서부터 작성






}

void main(void)
{
	int i;

	for (i = 0; i < 5; i++)
	{
		printf("Push Result = %d\n", Push_Stack(&a[i]));
		printf("Print Result = %d, ", Print_Stack());
		printf("Full = %d\n", Count_Full_Data_Stack());
	}

	for (i = 0; i < 6; i++)
	{
		printf("Pop Result = %d\n", Pop_Stack(&a[i]));
		printf("Print Result = %d, ", Print_Stack());
		printf("Full = %d\n ", Count_Full_Data_Stack());
	}

	for (i = 0; i < 3; i++)
	{
		printf("Push Result = %d\n", Push_Stack(&a[i]));
		printf("Print Result = %d, ", Print_Stack());
		printf("Full = %d\n", Count_Full_Data_Stack());
	}

	for (i = 0; i < 5; i++)
	{
		printf("Pop Result = %d\n", Pop_Stack(&a[i]));
		printf("Print Result = %d, ", Print_Stack());
		printf("Full = %d\n ", Count_Full_Data_Stack());
	}

	printf("\n");
}

#endif

/***********************************************************/
// [2-5] 힙 기반  Linear Queue
/***********************************************************/

#if 0

#include <stdio.h>
#include <malloc.h>

typedef struct _que
{
	int num;
	struct _que * next;
}QUEUE;

QUEUE * Wrptr = (QUEUE *)0;;
QUEUE * Rdptr = (QUEUE *)0;;

QUEUE a[10] = { { 1,0 },{ 2,0 },{ 3,0 },{ 4,0 },{ 5,0 },{ 6,0 },{ 7,0 },{ 8,0 },{ 9,0 },{ 10,0 } };

int In_Queue(QUEUE * data);
int Out_Queue(QUEUE * p);
int Print_Queue(void);
int Count_Full_Data_Queue(void);

int In_Queue(QUEUE * data)
{
	// 여기서부터 작성






}

int Out_Queue(QUEUE * p)
{
	// 여기서부터 작성






}

int Print_Queue(void)
{
	// 여기서부터 작성






}

int Count_Full_Data_Queue(void)
{
	// 여기서부터 작성






}

void main(void)
{
	int i;

	for (i = 0; i < 3; i++)
	{
		printf("Queue Result = %d\n", In_Queue(&a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d\n", Count_Full_Data_Queue());
	}

	for (i = 0; i < 2; i++)
	{
		printf("Dequeue Result = %d\n", Out_Queue(&a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d\n", Count_Full_Data_Queue());
	}

	for (i = 0; i < 4; i++)
	{
		printf("Queue Result = %d\n", In_Queue(&a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d\n", Count_Full_Data_Queue());
	}

	for (i = 0; i < 7; i++)
	{
		printf("Dequeue Result = %d\n", Out_Queue(&a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d\n", Count_Full_Data_Queue());
	}

	for (i = 0; i < 3; i++)
	{
		printf("Queue Result = %d\n", In_Queue(&a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d\n", Count_Full_Data_Queue());
	}

	for (i = 0; i < 3; i++)
	{
		printf("Dequeue Result = %d\n", Out_Queue(&a[i]));
		printf("Print Result = %d, ", Print_Queue());
		printf("Full = %d\n", Count_Full_Data_Queue());
	}
}

#endif