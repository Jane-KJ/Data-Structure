#include <iostream>
using namespace std;
// 链队列
int BF1(char s1[], char s2[])
{
    int len1 = strlen(s1), len2 = strlen(s2);
    int i = 0, j = 0;

    while (i < len1 && j < len2)
    {
        if (s1[i] == s2[j])
        {
            i++; j++;
        }
        else { i = i - j + 1; j = 0; }
    }

    if (j == len2) return i - j;
    else return -1;
}

int main()
{
    char s1 = "devfaoatnlovejis";
    char s2 = "love";
    cout << "主串匹配位置：" << BF1(s1, s2);
}