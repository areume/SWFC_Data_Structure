// Exam01.c

#pragma warning(disable: 4996)
#pragma warning(disable: 4477)
#pragma warning(disable: 4313)

/***********************************************************/
// [1-1] �迭 ��� ���� ����Ʈ
/***********************************************************/

#if 0

/***********************************************************/
// [1-1.1] ������ �𵨸�
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

// �������� ����Ǵ� ��� �Լ��� �� �κп� ������ �߰��Ѵ�

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
// [1-1.2] �迭�� ��� �ڷ� �μ�
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
// [1-1.3] Ư�� ��ҹ�ȣ�� �����͸� �μ�
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
// [1-1.4] �迭�� �ִ� ��� �ڷ��� ���� ���
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
// [1-1.5] �迭�� ������ �ϳ��� ����
/***********************************************************/

#if 01

int Create_Data(SCORE *p)
{
	printf("\n����� �Է��Ͻÿ� => ");
	scanf("%d", &p->id);
	fflush(stdin);                          // �Է� ������ ����ش�.
	printf("�̸��� �Է��Ͻÿ� => ");
	scanf("%s", p->name);
	fflush(stdin);
	printf("������ �Է��Ͻÿ� => ");
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
// [1-1.6] ������ �ϳ��� �����Ͽ� �迭�� �߰��� �����ϴ� �Լ�
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
		printf("\n���(�ƹ�Ű), �׸�(x Ű)\n");
	} while (getch() != 'x');
}

#endif

/***********************************************************/
// [1-1.7] ������ ����� ������ ���� ����� �����ϴ� �Լ�
/***********************************************************/

#if 01

int Delete_Data(int id)
{
	int i, j;

	if (exam[0].id == 0) return -2;             // 0] ����ִ� �迭�̸� -2 ����.

	for (i = 0; i < MAX_ST; i++) {
		if (exam[i].id == id) {                 // 1] ��ġ�ϴ� id�� ã�´�.
			for (j = i; j < MAX_ST - 1; j++) {   // 2] �ش� id ���� �ڷḦ ��ĭ�� �����.
				if (exam[j + 1].id == 0) {      // 3] ���� �ڷ��� id�� 0�̸� ���� �ڷᰡ ��.
					exam[j].id = 0;             // 4] id 0���� �ʱ�ȭ�ϰ�, 
					return i;                   // 5] ���� ��� ��ȣ ��ȯ.
				}
				exam[j] = exam[j + 1];          // 6] �ڷ� ��ĭ�� �����.
			}
			exam[j].id = 0;                     // 7] �ڷᰡ ������ ����Ǿ� �ִ� ���, ������ �ڷ� id�� 0���� �ʱ�ȭ.
			return i;                           // 8] ���� ��� ��ȣ ��ȯ.
		}
	}
	return -1;                                  // 9] �ش� id�� ������ -1 ����.
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
		printf("\n������ �ڷ��� ����� �Է��Ͻÿ� => ");
		scanf("%d", &i);
		fflush(stdin);
		printf("\n\nDelete Element = %d\n", Delete_Data(i));
		printf("Printed Data Count = %d\n", Print_All_Data());
		printf("\n���(�ƹ�Ű), �׸�(x Ű)\n");
	} while (getch() != 'x');
}

#endif

/***********************************************************/
// [1-1.8] ��� ����� ��ġ�ϴ� �����͸� Ž���ϴ� �Լ�
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
		printf("\nŽ���� �ڷḦ �Է��Ͻÿ�\n");
		Create_Data(&tmp);
		printf("\n\nSearched Element = %d\n", Search_Complete_Data(&tmp));
		printf("Printed Data Count = %d\n", Print_All_Data());
		printf("\n���(�ƹ�Ű), �׸�(x Ű)\n");
	} while (getch() != 'x');
}

#endif

/***********************************************************/
// [1-1.9] ���ϴ� ����� ���� �����͸� Ž���ϴ� �Լ�, �񱳸� ���� call back �Լ��� ����
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
		printf("\nŽ���� �ڷḦ �Է��Ͻÿ�\n");
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

		printf("\n���(�ƹ�Ű), �׸�(x Ű)\n");
	} while (getch() != 'x');
}

#endif

/***********************************************************/
// [1-1.10] �ڷḦ �����Ʈ�� �����ϴ� �Լ�
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
// [1-1.11] �ڷḦ ���� ���ķ� �����ϴ� �Լ�
/***********************************************************/

#if 01

int Sort_Select(SCORE *d, int order, int(*comp)(SCORE *x, SCORE *y))
{
	int i, j, max;
	int MAX = Count_Data();

	for (i = 0; i < MAX - 1; i++) {
		max = 0;                                        // 1] �� ȸ������ �ִ밪�� �ٽ� ����ϱ� ���� �ʱ�ȭ.
		for (j = 0; j < MAX - 1 - i; j++) {
			if (comp(&d[j + 1], &d[max]) == order) {    // 2] ��ġ���� �ϳ� �� �ڿ� �ڷḦ ���ϱ� ���� j+1 ���.
				max = j + 1;                            // 3] �ִ밪�� ���Ͽ� �ִ밪 ����.
			}
		}
		if (max != j) {                                 // 4] �ִ밪�� ��ġ�� �������� �ƴ� ��� ��ȯ.
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
// [1-1.12] �ڷḦ ���� ���ķ� �����ϴ� �Լ�
/***********************************************************/

// �� �ڵ�

#if 01

int Sort_Insertion(SCORE *d, int order, int(*comp)(SCORE *x, SCORE *y))
{
	int i, j, k;
	int MAX = Count_Data();

	for (i = 1; i < MAX; i++) {                  // 1] 0�� �ڷ�� ������ �Ǿ��ٰ� �����ϹǷ� 1�� �ڷ���� �ڸ��� ã�´�.
		for (j = 0; j < i; j++) {                // 2] i�� ���� �ڷḦ Ž��. (j)
			if (comp(&d[j], &d[i]) == order) {  // 3] j�� �ڷᰡ i�� �ڷẸ�� ũ�� ���� �ڷ� Ž�� �ߴ�.
				break;
			}
		}
		SCORE temp = d[i];                      // 4] i�� �ڷḦ ����.
		if (i != j) {                           // 5] i�� j ���� �ٸ��� �ڸ� ��ȭ�� ����.
			for (k = i; k > j; k--) {            // 6] j�� �ڸ��� ���� ���� �ڷḦ �ڷ� �б�.
				d[k] = d[k - 1];
			}
			d[k] = temp;                        // 7] ����� �ڸ��� i�� �ڷ� �ֱ�.
		}
	}
	return MAX;
}

#endif

// ����� �ڵ�

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
// [1-1.13] ����� ������ �����ϸ鼭 �����͸� �迭�� �߰��ϴ� �Լ�
/***********************************************************/

#if 01

int Insert_and_Sort_Data(SCORE *p)
{
	int i, j;
	int MAX = Count_Data();

	if (MAX == MAX_ST) return -1;           // 1] ��������� ������� -1 ����.

	for (i = 0; i < MAX; i++) {
		if (exam[i].id == p->id) return -2;  // 2] ������ ����� ������ ��� -2 ����.

		if (exam[i].id > p->id) {         // 3] ������ ��ġ�� ã�� ���.
			for (j = MAX; j > i; j--) {      // 4] ���� �ڷ� �ڷ� �б�.
				exam[j] = exam[j - 1];
			}
			exam[j] = *p;                   // 5] ����� �ڸ��� �ڷ� �ֱ�.
			return j;                       // 6] ��� ��ȣ ��ȯ.
		}
	}
	exam[i] = *p;                           // 7] ���ο� �ڷ��� ����� ���� ū ��� �迭�� �������� ����.
	return i;                               // 8] ��� ��ȣ ��ȯ.
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
// [1-1.14] ������ �����͸� ����ü�� �����Ͽ� �ִ� �Լ� 
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
// [1-1.15] ������ �� ��ŭ �ڷḦ �־��� buffer���� ������ �μ��ϴ� �Լ�
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
// [1-1.16] �־��� �� ��ŭ�� �ڷḦ ���޹��� buffer�� �����Ͽ� �ִ� �Լ�
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
// [1-1.17] Quick Sort �Լ� ����
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
// [1-1.18] ������ �Լ����� �̿��� ����ó�� ���α׷�
/***********************************************************/

#if 0

#include <stdlib.h>

void main(void)
{
	// ���⼭���� �ۼ�






}

#endif

#endif