// Exam03.c

#pragma warning(disable: 4996)
#pragma warning(disable: 4477)
#pragma warning(disable: 4313)

/***********************************************************/
// [1-3] 배열 기반 연결 리스트 - 다중 링크
/***********************************************************/

#if 0

/***********************************************************/
// [1-3.1] 데이터 모델링
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
	struct _score  *nid;
	struct _score  *njumsu;
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

void Make_Test_Data(int n)
{
	int i;

	for (i = 0; i < n; i++) {
		exam[i] = test[i];
	}
}

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

int Print_All_Data(void)
{
	int i;

	printf("Head.nid = 0x%.8X, Head.njumsu = 0x%.8X\n", Head.nid, Head.njumsu);
	for (i = 0; i < MAX_ST; i++) {
		if (exam[i].id == 0) break;
		printf("[%d] addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, nid = 0x%.8X, njumsu = 0x%.8X\n", i, &exam[i], exam[i].id, exam[i].name, exam[i].jumsu, exam[i].nid, exam[i].njumsu);
	}

	return i;
}

int Print_Data(int no)
{
	if (exam[no].id == 0) return -1;
	printf("[%d] addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, nid = 0x%.8X, njumsu = 0x%.8X\n", no, &exam[no], exam[no].id, exam[no].name, exam[no].jumsu, exam[no].nid, exam[no].njumsu);
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

int Insert_Data(SCORE * p)
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
// [1-3.2] 데이터 하나를 생성하여 Linked List에 추가하는 함수
/***********************************************************/

#if 01

int Insert_Node(SCORE *head, SCORE *d)
{
	SCORE *temp = head;

	for (int i = 0; i < MAX_ST; i++) {
		if (head->nid == NULL || head->nid->id > d->id) {
			d->nid = head->nid;
			head->nid = d;
			break;
		}
		if (head->nid->id == d->id) return -2;
		head = head->nid;
	}
	head = temp;

	for (int i = 0; i < MAX_ST; i++) {
		if (head->njumsu == NULL || head->njumsu->jumsu > d->jumsu) {
			d->njumsu = head->njumsu;
			head->njumsu = d;
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
// [1-3.3] link에 따라서 각 노드의 정보를 인쇄하는 함수
/***********************************************************/
/***********************************************************/
// [1-3.4] link에 따라서 주어진 사번에 맞는 노드 를 찾아 주소를 리턴하는 함수
/***********************************************************/

#if 01

int Print_All_Node(SCORE *head)
{
	Print_All_Id_Node(head);
	return Print_All_Jumsu_Node(head);
}

int Print_All_Id_Node(SCORE *head)
{
	int i;
	printf("[Id] Head.nid = 0x%.8X\n", head->nid);
	for (i = 0; i < MAX_ST; i++) {
		if (head->nid == NULL) return i;
		printf("addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, nid = 0x%.8X\n",
			head->nid, head->nid->id, head->nid->name, head->nid->jumsu, head->nid->nid);
		head = head->nid;
	}
	return i;
}

int Print_All_Jumsu_Node(SCORE *head)
{
	int i;
	printf("[Jumsu] Head.njumsu = 0x%.8X\n", head->njumsu);
	for (i = 0; i < MAX_ST; i++) {
		if (head->njumsu == NULL) break;
		printf("addr = 0x%.8X, ID=%d, NAME=%s, SCORE=%d, njumsu = 0x%.8X\n",
			head->njumsu, head->njumsu->id, head->njumsu->name, head->njumsu->jumsu, head->njumsu->njumsu);
		head = head->njumsu;
	}
	return i;
}

SCORE *Search_Id_Node(SCORE *head, int id)
{
	while (head->nid != NULL) {
		if (head->nid->id == id) {
			return head->nid;
		}
		head = head->nid;
	}
	return (SCORE *)NULL;
}

SCORE *Search_Jumsu_Node(SCORE *head, int jumsu)
{
	while (head->njumsu != NULL) {
		if (head->njumsu->jumsu == jumsu) {
			return head->njumsu;
		}
		head = head->njumsu;
	}
	return (SCORE *)NULL;
}

#endif

#if 0

void main(void)
{
	int i;
	int r;
	SCORE * p;

	for (i = 0; i < 8; i++)
	{
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Printed Data Count = %d\n", Print_All_Data());
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
		printf("Printed Node Count = %d\n", Print_All_Node(&Head));
	}

	printf("[Id] Searched Node Address = 0x%.8X\n", p = Search_Id_Node(&Head, 8));

	if (p != (SCORE *)0x0)
	{
		printf("ID=%d, NAME=%s, SCORE=%d, nid = 0x%.8X\n", p->id, p->name, p->jumsu, p->nid);
	}

	printf("[Id] Searched Node Address = 0x%.8X\n", p = Search_Id_Node(&Head, 7));

	if (p != (SCORE *)0x0)
	{
		printf("ID=%d, NAME=%s, SCORE=%d, nid = 0x%.8X\n", p->id, p->name, p->jumsu, p->nid);
	}

	p = &Head;

	for (;;)
	{
		printf("p = 0x%.8X", p);
		printf("[Jumsu] Searched Node Address = 0x%.8X\n", p = Search_Jumsu_Node(p, 50));
		if (p == (SCORE *)0x0) break;
		printf("ID=%d, NAME=%s, SCORE=%d, njumsu = 0x%.8X\n", p->id, p->name, p->jumsu, p->njumsu);
	}
}

#endif

/***********************************************************/
// [1-3.5] list에 저장된 자료의 총수를 계산하는 함수
/***********************************************************/
/***********************************************************/
// [1-3.6] link에 따라서 주어진 사번에 맞는 자료를 인쇄하는 함수
/***********************************************************/

#if 01

int Count_Node(SCORE *head)
{
	int i;
	for (i = 0; i < MAX_ST; i++) {
		if (head->nid == (SCORE *)0x0) return i;
		head = head->nid;
	}
	return i;
}

int Print_Id_Node(SCORE *head, int id)
{
	SCORE *p = Search_Id_Node(head, id);

	if (p != (SCORE *)0x0) {
		printf("ID=%d, NAME=%s, SCORE=%d, nid = 0x%.8X\n", p->id, p->name, p->jumsu, p->nid);
		return 1;
	}
	return -1;
}

int Print_Jumsu_Node(SCORE *head, int jumsu)
{
	SCORE * p = head;
	int r = -1;

	for (;;) {
		p = Search_Jumsu_Node(p, jumsu);
		if (p == (SCORE *)0x0) break;
		printf("ID=%d, NAME=%s, SCORE=%d, njumsu = 0x%.8X\n", p->id, p->name, p->jumsu, p->njumsu);
		r = 1;
	}
	return r;
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
		printf("Printed Node Count = %d\n", Print_All_Node(&Head));
		printf("Node Count = %d\n", Count_Node(&Head));
	}

	printf("Print Id(8) Node Result = %d\n", Print_Id_Node(&Head, 8));
	printf("Print Id(7) Node Result = %d\n", Print_Id_Node(&Head, 7));
	printf("Print Jumsu(50) Node Result = %d\n", Print_Jumsu_Node(&Head, 50));
	printf("Print Jumsu(100) Node Result = %d\n", Print_Jumsu_Node(&Head, 100));
	printf("Print Jumsu(31) Node Result = %d\n", Print_Jumsu_Node(&Head, 31));
}

#endif

/***********************************************************/
// [1-3.7] link에 따라서 주어진 사번의 node를 찾아서 삭제하는 함수
/***********************************************************/

#if 01

int Delete_Id_Node(SCORE *head, int id)
{
	SCORE *p = head;

	while (head->nid != NULL) {
		if (head->nid->id == id) {
			Delete_One_Jumsu_Node(p, head->nid->jumsu, id);           // 점수로 연결된 링크를 먼저 해지한다.

			head->nid->id = 0;
			head->nid = head->nid->nid;
			return 1;
		}
		if (head->nid->id > id) return -1;
		head = head->nid;
	}
	return -1;
}

void Delete_One_Jumsu_Node(SCORE *head, int jumsu, int id)
{
	while (head->njumsu != NULL) {
		if (head->njumsu->jumsu == jumsu && head->njumsu->id == id) { // id와 jumsu가 모두 같은 경우의 노드만 삭제한다.
			head->njumsu = head->njumsu->njumsu;
			return;
		}
		head = head->njumsu;
	}
}

int Delete_Jumsu_Node(SCORE *head, int jumsu)
{
	int flag = -1;
	SCORE *p = head;
	for (;;) {                               // Search_Jumsu_Node 함수는 점수를 전달받아 자료에서 해당 점수의 첫번째 주소를 리턴한다.
		p = Search_Jumsu_Node(p, jumsu);    // p는 해당 점수의 위치. 다음 턴에서는 그 이후의 노드만 검사하도록 그래도 p를 전달한다. (오름차순)
		if (p == (SCORE *)NULL) break;
		Delete_Id_Node(head, p->id);     // p가 null이 아니면 해당 점수가 존재하므로 삭제 진행. id로 삭제할 때는 처음부터 탐색해야 한다.
		flag = 1;                           // 1개 이상 삭제했다는 것을 나타낸다.
	}
	return flag;
}

#endif

#if 0

void main(void)
{
	int i;
	int r;

	for (i = 0; i < MAX_ST; i++)
	{
		printf("[Loop: %d] Insert Result = %d\n", i, r = Insert_Data(&test[i]));
		printf("Insert Node Result = %d\n", Insert_Node(&Head, &exam[r]));
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

/***********************************************************/
// [1-3.8] node에서 요청한 자료의 수를 계수하거나 버퍼에 복사해 주는 함수
/***********************************************************/

#if 01

int Count_Name_Node(SCORE *head, char *name)
{
	int n = 0;

	for (;;) {
		if (head->nid == (SCORE *)0x0) return n;
		if (!strcmp(head->nid->name, name)) n++;
		head = head->nid;
	}
}

int Count_Score_Node(SCORE *head, int jumsu)
{
	int n = 0;

	for (;;) {
		if (head->njumsu == (SCORE *)0x0) return n;
		if (head->njumsu->jumsu == jumsu) n++;
		head = head->njumsu;
	}
}

int Copy_Name_Node(SCORE *head, char *name, SCORE *buf)
{
	int cnt = 0;

	for (;;) {
		if (head->nid == NULL) break;

		if (strcmp(head->nid->name, name) == 0) {
			buf[cnt] = *(head->nid);
			buf[cnt].nid = &buf[cnt + 1];
			cnt++;
		}
		head = head->nid;
	}
	if (cnt > 0) buf[cnt - 1].nid = (SCORE *)NULL;
	return cnt;
}

int Copy_Score_Node(SCORE *head, int jumsu, SCORE *buf)
{
	int cnt = 0;

	for (;;) {
		if (head->njumsu == NULL) break;

		if (head->njumsu->jumsu == jumsu) {
			buf[cnt] = *(head->njumsu);
			buf[cnt].nid = &buf[cnt + 1];
			cnt++;
		}
		head = head->njumsu;
	}
	if (cnt > 0) buf[cnt - 1].njumsu = (SCORE *)NULL;
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
	new_head.nid = p;
	printf("Printed Node Count = %d\n", Print_All_Id_Node(&new_head));
	free(p);

	printf("Score Node Count = %d\n", r = Count_Score_Node(&Head, 100));
	p = calloc(r, sizeof(SCORE));
	printf("Copy Score Node Result = %d\n", Copy_Score_Node(&Head, 100, p));
	new_head.njumsu = p;
	printf("Printed Node Count = %d\n", Print_All_Jumsu_Node(&new_head));
	free(p);
}

#endif

#endif