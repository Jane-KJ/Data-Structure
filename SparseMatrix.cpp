// ConsoleApplication24.cpp : 定义控制台应用程序的入口点。


#include <string.h>
#include <iostream>
using namespace std;

# define MAXSIZE 20

typedef struct
{
	int index, column; // 三元组的行号和列号
	int value;  // 三元组的元素值
} Triple;

typedef struct
{
	Triple data[MAXSIZE];
	int m, n, t; // m行n列的矩阵，非零元个数为t
} SparseMatrix;

// 1. 创建稀疏矩阵
void CreateMatrix(SparseMatrix& M)
{
	cout << "请输入矩阵行数:";
	cin >> M.m;

	cout << "请输入矩阵列数：";
	cin >> M.n;

	cout << "请输入非零元个数：";
	cin >> M.t;

	cout << "请输入非零元素（输入格式：行号 列号 数值）：\n" << endl;
	for (int p = 0; p < M.t; p++)
	{
		cin >> M.data[p].index >> M.data[p].column >> M.data[p].value;
	}

	printf("\n");
}

// 2. 展示稀疏矩阵
void ShowMatrix(SparseMatrix& M)
{
	int p = 0;

	for (int i = 1; i <= M.m; i++) // 遍历行数
	{
		for (int j = 1; j <= M.n; j++)  // 遍历列数
		{
			if (M.data[p].index == i && M.data[p].column == j)  // 打印非零元素
			{
				printf("%d ", M.data[p].value);
				p++;
			}

			else  // 打印零值元素
			{
				cout << "0 ";
			}
		}
		printf("\n");
	}
}

// 3.1 稀疏矩阵转置：若采用节省空间的方法，可以将矩阵行号列号对换，再进行排序转移元素位置
void InvertMatrix1(SparseMatrix M)
{
	printf("\n方法一 节省空间的转置方法的转置结果：\n");

	// Step1.修改矩阵行数列数
	int temp = 0;
	temp = M.m;
	M.m = M.n;
	M.n = temp;

	// Step2.将非零元素的行号和列号对换

	for (int p = 0; p < M.t; p++)
	{
		if (M.data[p].index != M.data[p].column)  // 行号和列好不相等的元素才需要进行对换
		{
			temp = M.data[p].index;
			M.data[p].index = M.data[p].column;
			M.data[p].column = temp;
		}
	}


	// Step3.将对换行号列号的非零元素进行排序
	
	int	temp_ind, temp_col, temp_val, i, j;
	for(j=0; j<M.t-1; j++)
	{
		for(i=0; i<M.t-j-1; i++)
		{
			if(M.data[i].index>M.data[i+1].index)
			{
				// 交换行号
				temp_ind = M.data[i].index;
				M.data[i].index = M.data[i+1].index;
				M.data[i + 1].index = temp_ind;

				// 交换列号
				temp_col = M.data[i].column;
				M.data[i].column = M.data[i+1].column;
				M.data[i+1].column = temp_col;

				// 交换元素值
				temp_val = M.data[i].value;
				M.data[i].value = M.data[i + 1].value;
				M.data[i + 1].value = temp_val;
			}
		}
	}

	ShowMatrix(M);

}

// 3.2 稀疏矩阵转置：若采用节省时间的方法，可以通过创建新的矩阵一步步存储转置后的矩阵。
void InvertMatrix2(SparseMatrix M, SparseMatrix& T)
{
	printf("\n方法二 节省时间的转置方法的转置结果：\n");
	T.m = M.n;
	T.n = M.m;
	T.t = M.t;

	int q = 0;

	for (int col = 1; col <= M.n; col++) // 遍历原矩阵列数
	{
		for (int p=0; p < M.t; p++) // 遍历矩阵元素
		{
			if (col == M.data[p].column) // 元素列数越大，转置后排序越后
			{
				// 转换行号列号
				T.data[q].index = M.data[p].column;
				T.data[q].column = M.data[p].index;
				T.data[q].value = M.data[p].value;
				q++;
			}
		}
	}

	ShowMatrix(T);
}


int main()
{
	SparseMatrix M;

	CreateMatrix(M);

	printf("稀疏矩阵的展示：\n");

	ShowMatrix(M);

	SparseMatrix T;
	
	InvertMatrix1(M);

	InvertMatrix2(M, T);

}