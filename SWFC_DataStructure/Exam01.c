// Exam01.c

#pragma warning(disable: 4996)
#pragma warning(disable: 4477)
#pragma warning(disable: 4313)

/***********************************************************/
// [1-1] 배열 기반 순차 리스트
/***********************************************************/

#if 0

/***********************************************************/
// [1-1.1] 데이터 모델링
/***********************************************************/

#if 01

#include <stdio.h>
#include <string.h>
#include <conio.h>

typedef struct _score
{
	int id;
	int jumsu;
	char name[10];
}SCORE;

#define MAX_ST      20

SCORE exam[MAX_ST];

// 이제부터 설계되는 모든 함수는 이 부분에 선언을 추가한다

int Print_All_Data(void);
int Print_Data(int no);
int Count_Data(void);
int Create_Data(SCORE * p);
int Insert_Data(SCORE * p);
int Delete_Data(int id);
int Search_Complete_Data(SCORE * p);
int Search_Data(int n, SCORE * p, int(*comp)(SCORE * x, SCORE* y));
int Compare_Id(SCORE * x, SCORE* y);
int Compare_Name(SCORE * x, SCORE* y);
int Compare_Jumsu(SCORE * x, SCORE* y);
int Sort_Bubble(SCORE * d, int order, int(*comp)(SCORE * x, SCORE * y));
int Sort_Select(SCORE * d, int order, int(*comp)(SCORE * x, SCORE * y));
int Sort_Insertion(SCORE * d, int order, int(*comp)(SCORE * x, SCORE * y));
int Insert_and_Sort_Data(SCORE * p);
int Copy_Data(int n, SCORE * p);
int Copy_All_Data(SCORE * p, int max);
int Print_All_Buffer(SCORE * d, int max);
int Sort_Quick(SCORE *d, int order, int m, int n, int(*comp)(SCORE * x, SCORE * y));

SCORE test[10] = { { 10, 50, "kim" },{ 2, 80, "lew" },{ 8, 50, "lew" },{ 4, 45, "lee" },{ 1, 90, "song" },\
{3, 45, "kim"},{ 5, 50, "song" },{ 9, 100, "lee" },{ 7, 75, "moon" },{ 6, 90, "park" } };

void Make_Test_Data(int n)
{
	int i;

	for (i = 0; i < n; i++) {
		exam[i] = test[i];
	}
}

#endif

/***********************************************************/
// [1-1.2] 배열의 모든 자료 인쇄
/***********************************************************/

#if 01

int Print_All_Data(void)
{
	int i;
	for (i = 0; i < MAX_ST; i++) {
		if (exam[i].id == 0) break;
		printf("[%d] ID=%d, NAME=%s, SCORE=%d\n", i, exam[i].id, exam[i].name, exam[i].jumsu);
	}
	return i;
}

#endif

/***********************************************************/
// [1-1.3] 특정 요소번호의 데이터만 인쇄
/***********************************************************/

#if 01

int Print_Data(int no)
{
	if (exam[no].id == 0) return -1;
	printf("ID=%d, NAME=%s, SCORE=%d\n", exam[no].id, exam[no].name, exam[no].jumsu);
	return 1;
}

#endif

/***********************************************************/
// [1-1.4] 배열에 있는 모든 자료의 수를 계산
/***********************************************************/

#if 01

int Count_Data(void)
{
	int MAX;
	for (MAX = 0; MAX < MAX_ST; MAX++) {
		if (exam[MAX].id == 0) break;
	}
	return MAX;
}

#endif

/***********************************************************/
// [1-1.5] 배열에 데이터 하나를 생성
/***********************************************************/

#if 01

int Create_Data(SCORE *p)
{
	printf("\n사번을 입력하시오 => ");
	scanf("%d", &p->id);
	fflush(stdin);                          // 입력 공간을 비워준다.
	printf("이름을 입력하시오 => ");
	scanf("%s", p->name);
	fflush(stdin);
	printf("점수를 입력하시오 => ");
	scanf("%d", &p->jumsu);
	fflush(stdin);

	return 1;
}

#endif

#if 0

void main(void)
{
	int i;

	for (i = 0; i<3; i++) {
		Create_Data(&exam[i]);
		printf("\nCount = %d\n", Count_Data());
		printf("Print Result = %d\n", Print_Data(i));
		printf("Printed Data Count = %d\n", Print_All_Data());
	}
}

#endif

/***********************************************************/
// [1-1.6] 데이터 하나를 생성하여 배열에 추가로 저장하는 함수
/***********************************************************/

#if 01

int Insert_Data(SCORE *p)
{
	int i;
	for (i = 0; i < MAX_ST; i++) {
		if (exam[i].id == p->id) return -2;
		if (exam[i].id == 0) {
			exam[i] = *p;
			return i;
		}
	}
	return -1;
}

#endif

#if 0

void main(void)
{
	SCORE tmp;

	do {
		Create_Data(&tmp);
		printf("\n\nInsert Result = %d\n", Insert_Data(&tmp));
		printf("Printed Data Count = %d\n", Print_All_Data());
		printf("\n계속(아무키), 그만(x 키)\n");
	} while (getch() != 'x');
}

#endif

/***********************************************************/
// [1-1.7] 지정한 사번의 데이터 삭제 기능을 수행하는 함수
/***********************************************************/

#if 01

int Delete_Data(int id)
{
	int i, j;

	if (exam[0].id == 0) return -2;             // 0] 비어있는 배열이면 -2 리턴.

	for (i = 0; i < MAX_ST; i++) {
		if (exam[i].id == id) {                 // 1] 일치하는 id를 찾는다.
			for (j = i; j < MAX_ST - 1; j++) {   // 2] 해당 id 뒤의 자료를 한칸씩 땡기기.
				if (exam[j + 1].id == 0) {      // 3] 뒤의 자료의 id가 0이면 현재 자료가 끝.
					exam[j].id = 0;             // 4] id 0으로 초기화하고, 
					return i;                   // 5] 삭제 요소 번호 반환.
				}
				exam[j] = exam[j + 1];          // 6] 자료 한칸씩 땡기기.
			}
			exam[j].id = 0;                     // 7] 자료가 끝까지 저장되어 있는 경우, 마지막 자료 id를 0으로 초기화.
			return i;                           // 8] 삭제 요소 번호 반환.
		}
	}
	return -1;                                  // 9] 해당 id가 없으면 -1 리턴.
}

#endif

#if 0

void main(void)
{
	int i;

	Make_Test_Data(5);
	printf("Printed Data Count = %d\n", Print_All_Data());

	do
	{
		printf("\n삭제할 자료의 사번을 입력하시오 => ");
		scanf("%d", &i);
		fflush(stdin);
		printf("\n\nDelete Element = %d\n", Delete_Data(i));
		printf("Printed Data Count = %d\n", Print_All_Data());
		printf("\n계속(아무키), 그만(x 키)\n");
	} while (getch() != 'x');
}

#endif

/***********************************************************/
// [1-1.8] 모든 멤버가 일치하는 데이터를 탐색하는 함수
/***********************************************************/

#if 01

int Search_Complete_Data(SCORE *p)
{
	int i;
	if (exam[0].id == 0) return -2;

	for (i = 0; i < MAX_ST; i++) {
		if (exam[i].id == 0) return -1;

		if (exam[i].id == p->id) {
			if (strcmp(exam[i].name, p->name) == 0 && (exam[i].jumsu == p->jumsu)) return i;
		}
	}
	return -1;
}

#endif

#if 0

void main(void)
{
	SCORE tmp;

	Make_Test_Data(8);
	printf("Printed Data Count = %d\n", Print_All_Data());

	do
	{
		printf("\n탐색할 자료를 입력하시오\n");
		Create_Data(&tmp);
		printf("\n\nSearched Element = %d\n", Search_Complete_Data(&tmp));
		printf("Printed Data Count = %d\n", Print_All_Data());
		printf("\n계속(아무키), 그만(x 키)\n");
	} while (getch() != 'x');
}

#endif

/***********************************************************/
// [1-1.9] 원하는 멤버를 갖는 데이터를 탐색하는 함수, 비교를 위한 call back 함수도 설계
/***********************************************************/

#if 01

int Search_Data(int n, SCORE *p, int(*comp)(SCORE *x, SCORE *y))
{
	if (exam[0].id == 0) return -2;

	for (int i = n; i < MAX_ST; i++) {
		if (comp(&exam[i], p) == 0) return i;
	}
	return -1;
}

int Compare_Id(SCORE *x, SCORE *y)
{
	if (x->id == y->id) return 0;
	else if (x->id > y->id) return 1;
	else return -1;
}

int Compare_Name(SCORE *x, SCORE *y)
{
	return strcmp(x->name, y->name);
}

int Compare_Jumsu(SCORE *x, SCORE *y)
{
	if (x->jumsu == y->jumsu) return 0;
	else if (x->jumsu > y->jumsu) return 1;
	else return -1;
}

#endif

#if 0

void main(void)
{
	int n;
	SCORE tmp;

	Make_Test_Data(8);
	printf("Printed Data Count = %d\n", Print_All_Data());

	do
	{
		printf("\n탐색할 자료를 입력하시오\n");
		Create_Data(&tmp);

		printf("\nSearched Element (ID) = %d\n", n = Search_Data(0, &tmp, Compare_Id));
		Print_Data(n);

		n = 0;

		do
		{
			printf("\nSearched Element (Name) = %d\n", n = Search_Data(n, &tmp, Compare_Name));
			Print_Data(n);
			n++;
		} while (n > 0);

		n = 0;

		do
		{
			printf("\nSearched Element (Jumsu) = %d\n", n = Search_Data(n, &tmp, Compare_Jumsu));
			Print_Data(n);
			n++;
		} while (n > 0);

		printf("Printed Data Count = %d\n", Print_All_Data());

		printf("\n계속(아무키), 그만(x 키)\n");
	} while (getch() != 'x');
}

#endif

/***********************************************************/
// [1-1.10] 자료를 버블소트로 정렬하는 함수
/***********************************************************/

#if 01

int Sort_Bubble(SCORE *d, int order, int(*comp)(SCORE *x, SCORE *y))
{
	int i, j;
	int MAX = Count_Data();

	for (i = 0; i < MAX - 1; i++) {
		for (j = 0; j < MAX - 1 - i; j++) {
			if (comp(&d[j], &d[j + 1]) == order) {
				SCORE temp = d[j + 1];
				d[j + 1] = d[j];
				d[j] = temp;
			}
		}
	}
	return MAX;
}

#endif

#if 0

void main(void)
{
	Make_Test_Data(8);
	printf("Printed Data Count = %d\n", Print_All_Data());

	printf("===================================================\n");
	printf("Sorted Data Count = %d\n", Sort_Bubble(exam, 1, Compare_Id));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("Sorted Data Count = %d\n", Sort_Bubble(exam, -1, Compare_Id));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("===================================================\n");
	printf("Sorted Data Count = %d\n", Sort_Bubble(exam, 1, Compare_Name));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("Sorted Data Count = %d\n", Sort_Bubble(exam, -1, Compare_Name));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("===================================================\n");
	printf("Sorted Data Count = %d\n", Sort_Bubble(exam, 1, Compare_Jumsu));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("Sorted Data Count = %d\n", Sort_Bubble(exam, -1, Compare_Jumsu));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("===================================================\n");
}

#endif

/***********************************************************/
// [1-1.11] 자료를 선택 정렬로 정렬하는 함수
/***********************************************************/

#if 01

int Sort_Select(SCORE *d, int order, int(*comp)(SCORE *x, SCORE *y))
{
	int i, j, max;
	int MAX = Count_Data();

	for (i = 0; i < MAX - 1; i++) {
		max = 0;                                        // 1] 각 회전마다 최대값을 다시 계산하기 위해 초기화.
		for (j = 0; j < MAX - 1 - i; j++) {
			if (comp(&d[j + 1], &d[max]) == order) {    // 2] 위치보다 하나 더 뒤에 자료를 비교하기 위해 j+1 사용.
				max = j + 1;                            // 3] 최대값과 비교하여 최대값 갱신.
			}
		}
		if (max != j) {                                 // 4] 최대값의 위치가 마지막이 아닐 경우 교환.
			SCORE temp = d[max];
			d[max] = d[j];
			d[j] = temp;
		}
	}
	return MAX;
}

#endif

#if 0

void main(void)
{
	Make_Test_Data(8);
	printf("Printed Data Count = %d\n", Print_All_Data());

	printf("===================================================\n");
	printf("Sorted Data Count = %d\n", Sort_Select(exam, 1, Compare_Id));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("Sorted Data Count = %d\n", Sort_Select(exam, -1, Compare_Id));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("===================================================\n");
	printf("Sorted Data Count = %d\n", Sort_Select(exam, 1, Compare_Name));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("Sorted Data Count = %d\n", Sort_Select(exam, -1, Compare_Name));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("===================================================\n");
	printf("Sorted Data Count = %d\n", Sort_Select(exam, 1, Compare_Jumsu));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("Sorted Data Count = %d\n", Sort_Select(exam, -1, Compare_Jumsu));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("===================================================\n");
}

#endif

/***********************************************************/
// [1-1.12] 자료를 삽입 정렬로 정렬하는 함수
/***********************************************************/

// 내 코드

#if 01

int Sort_Insertion(SCORE *d, int order, int(*comp)(SCORE *x, SCORE *y))
{
	int i, j, k;
	int MAX = Count_Data();

	for (i = 1; i < MAX; i++) {                  // 1] 0번 자료는 정렬이 되었다고 가정하므로 1번 자료부터 자리를 찾는다.
		for (j = 0; j < i; j++) {                // 2] i번 이전 자료를 탐색. (j)
			if (comp(&d[j], &d[i]) == order) {  // 3] j번 자료가 i번 자료보다 크면 이전 자료 탐색 중단.
				break;
			}
		}
		SCORE temp = d[i];                      // 4] i번 자료를 저장.
		if (i != j) {                           // 5] i와 j 값이 다르면 자리 변화가 있음.
			for (k = i; k > j; k--) {            // 6] j번 자리를 비우기 위해 자료를 뒤로 밀기.
				d[k] = d[k - 1];
			}
			d[k] = temp;                        // 7] 비어진 자리에 i번 자료 넣기.
		}
	}
	return MAX;
}

#endif

// 강사님 코드

#if 0

int Sort_Insertion(SCORE *d, int order, int(*comp)(SCORE *x, SCORE *y))
{
	int i, j, k;
	SCORE temp;

	if (!d[i].id) return 0;

	for (i = 1; i < MAX_ST; i++) {
		if (!d[i].id) break;
		for (j = 0; j < i; j++) {
			if (comp(&d[j], &d[i]) == order) {
				temp = d[i];
				for (k = i; k > j; k--) d[k] = d[k - 1];
				d[j] = temp;
				break;
			}
		}
	}
}

#endif

#if 0

void main(void)
{
	Make_Test_Data(8);
	printf("Printed Data Count = %d\n", Print_All_Data());

	printf("===================================================\n");
	printf("Sorted Data Count = %d\n", Sort_Insertion(exam, 1, Compare_Id));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("Sorted Data Count = %d\n", Sort_Insertion(exam, -1, Compare_Id));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("===================================================\n");
	printf("Sorted Data Count = %d\n", Sort_Insertion(exam, 1, Compare_Name));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("Sorted Data Count = %d\n", Sort_Insertion(exam, -1, Compare_Name));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("===================================================\n");
	printf("Sorted Data Count = %d\n", Sort_Insertion(exam, 1, Compare_Jumsu));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("Sorted Data Count = %d\n", Sort_Insertion(exam, -1, Compare_Jumsu));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("===================================================\n");
}

#endif

/***********************************************************/
// [1-1.13] 사번순 정렬을 유지하면서 데이터를 배열에 추가하는 함수
/***********************************************************/

#if 01

int Insert_and_Sort_Data(SCORE *p)
{
	int i, j;
	int MAX = Count_Data();

	if (MAX == MAX_ST) return -1;           // 1] 저장공간이 없을경우 -1 리턴.

	for (i = 0; i < MAX; i++) {
		if (exam[i].id == p->id) return -2;  // 2] 동일한 사번이 존재할 경우 -2 리턴.

		if (exam[i].id > p->id) {         // 3] 삽입할 위치를 찾은 경우.
			for (j = MAX; j > i; j--) {      // 4] 기존 자료 뒤로 밀기.
				exam[j] = exam[j - 1];
			}
			exam[j] = *p;                   // 5] 비어진 자리에 자료 넣기.
			return j;                       // 6] 요소 번호 반환.
		}
	}
	exam[i] = *p;                           // 7] 새로운 자료의 사번이 가장 큰 경우 배열의 마지막에 삽입.
	return i;                               // 8] 요소 번호 반환.
}

#endif

#if 0

void main(void)
{
	int i;
	SCORE tmp;

	for (i = 0; i<sizeof(test) / sizeof(test[0]); i++)
	{
		printf("\n\nInsert = %d\n", Insert_and_Sort_Data(&test[i]));
		printf("Printed Data Count = %d\n", Print_All_Data());
	}

	tmp.id = 4;
	printf("\n\nInsert = %d\n", Insert_and_Sort_Data(&tmp));
	printf("Printed Data Count = %d\n", Print_All_Data());
}

#endif

/***********************************************************/
// [1-1.14] 지정한 데이터를 구조체에 복사하여 주는 함수 
/***********************************************************/

#if 01

int Copy_Data(int n, SCORE *p)
{
	if (exam[n].id == 0) return -1;
	*p = exam[n];
	return 1;
}

#endif

#if 0

void main(void)
{
	SCORE tmp;

	Make_Test_Data(8);
	printf("Printed Data Count = %d\n", Print_All_Data());

	printf("Data Copy Result = %d\n", Copy_Data(3, &tmp));
	printf("ID: %d, Name: %s, Score: %d\n", tmp.id, tmp.name, tmp.jumsu);
	printf("Data Copy Result = %d\n", Copy_Data(9, &tmp));
}

#endif

/***********************************************************/
// [1-1.15] 지정한 수 만큼 자료를 주어진 buffer에서 꺼내어 인쇄하는 함수
/***********************************************************/

#if 01

int Print_All_Buffer(SCORE *d, int max)
{
	int i;
	int n = Count_Data();
	max = (max < n) ? max : n;

	for (i = 0; i < max; i++) {
		printf("[%d] ID=%d, NAME=%s, SCORE=%d\n", i, d[i].id, d[i].name, d[i].jumsu);
	}
	return max;
}

#endif

#if 0

void main(void)
{
	Make_Test_Data(10);
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("All Buffer Print = %d\n", Print_All_Buffer(exam, 10));
	printf("All Buffer Print = %d\n", Print_All_Buffer(exam, 4));
}

#endif

/***********************************************************/
// [1-1.16] 주어진 수 만큼의 자료를 전달받은 buffer에 복사하여 주는 함수
/***********************************************************/

#if 01

int Copy_All_Data(SCORE *p, int max)
{
	int n = Count_Data();
	max = (max < n) ? max : n;

	for (int i = 0; i < max; i++) {
		p[i] = exam[i];
	}
	return max;
}

#endif

#if 0

SCORE tmp[MAX_ST];

void main(void)
{
	Make_Test_Data(10);
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("All Data Copy Result = %d\n", Copy_All_Data(tmp, 10));
	printf("All Buffer Print = %d\n", Print_All_Buffer(tmp, 10));
	printf("Sorted Data Count = %d\n", Sort_Bubble(tmp, 1, Compare_Jumsu));
	printf("All Buffer Print = %d\n", Print_All_Buffer(tmp, 10));
}

#endif

/***********************************************************/
// [1-1.17] Quick Sort 함수 설계
/***********************************************************/

#if 01

int Sort_Quick(SCORE *d, int order, int m, int n, int(*comp)(SCORE *x, SCORE *y))
{
	SCORE temp;
	int pivot, mark, cur;
	pivot = n; mark = cur = m;

	if (m >= n) return n - m + 1;

	for (cur = m; cur < pivot; cur++) {
		if (comp(&d[cur], &d[pivot])*order < 0) {
			if (mark != cur) {
				temp = d[mark]; d[mark] = d[cur]; d[cur] = temp;
			}
			mark++;
		}
	}
	if (mark != pivot) {
		temp = d[mark]; d[mark] = d[pivot]; d[pivot] = temp;
	}
	Sort_Quick(d, order, m, mark - 1, comp);
	Sort_Quick(d, order, mark + 1, n, comp);

	return n - m + 1;
}

#endif

#if 0

void main(void)
{
	int N;

	Make_Test_Data(8);
	printf("Printed Data Count = %d\n", Print_All_Data());

	N = Count_Data();

	printf("===================================================\n");
	printf("Sorted Data Count = %d\n", Sort_Quick(exam, 1, 0, N - 1, Compare_Id));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("Sorted Data Count = %d\n", Sort_Quick(exam, -1, 0, N - 1, Compare_Id));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("===================================================\n");
	printf("Sorted Data Count = %d\n", Sort_Quick(exam, 1, 0, N - 1, Compare_Name));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("Sorted Data Count = %d\n", Sort_Quick(exam, -1, 0, N - 1, Compare_Name));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("===================================================\n");
	printf("Sorted Data Count = %d\n", Sort_Quick(exam, 1, 0, N - 1, Compare_Jumsu));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("Sorted Data Count = %d\n", Sort_Quick(exam, -1, 0, N - 1, Compare_Jumsu));
	printf("Printed Data Count = %d\n", Print_All_Data());
	printf("===================================================\n");
}

#endif

/***********************************************************/
// [1-1.18] 설계한 함수들을 이용한 성적처리 프로그램
/***********************************************************/

#if 0

#include <stdlib.h>

void main(void)
{
	// 여기서부터 작성






}

#endif

#endif