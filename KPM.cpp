#include <iostream>
using namespace std;
// next 数组暴力求解: 前缀后缀子集最长字符串长度
void GetNext1(char s2[], int next[])
{
    // 1. next数组的 0 和 1 都是固定的
    next[0] = -1;
    next[1] = 0;

    // 2. 遍历剩余模式串求 next数组
    for (int j = 2; s2[j] != '\0'; j++)
    {
        int max_len = j - 1;
        int len, k;
        for (len = max_len; len >= 1; len--) // 从前缀后缀中子集最长的串开始遍历，逐次减小
        {
            for (k = 0; k < len; k++)  // 遍历前缀后缀一个子集的字符串
            {
                if (s2[k] != s2[k + j - len]) break;  // 判断前缀和后缀子集字符串是否相等，只要有不等就下一个len
            }
            if (k == len) // 上一个循环正常循环结束，说明该子集字符串匹配，将len赋给next数组，进行下一个len的子集
            {
                next[j] = len;
                break;
            }
        }
        if (len < 1) next[j] = 0; // 上述遍历子集后连长度为1的字符串也匹配不了，next值就是0了
    }
}
// next数组——递推算法
void GetNext2(char s2[], int next[])
{
    // 1. next数组的 0 和 1 都是固定的
    next[0] = -1;
    next[1] = 0;

    // 2. 定义变量找 next 值
    int k;
    // 3. 遍历剩余的模式串，求 next数组
    for (int j = 2; s2[j] != '\0'; j++)
    {
        k = next[j - 1];
        // 情况 1：碰到头了，next值直接置为0，继续求下一个 j的next值
        if (k == -1)
        {
            next[j] = 0;
            continue;
        }
        // 情况 2：没碰到头，继续递推
        else
        {
            while (s2[j - 1] != s2[k] && k != -1) k = next[k];
            // 情况 2.1：找到相等的
            if (s2[j - 1] == s2[k]) next[j] = k + 1;
            // 情况 2.2：没有找到相等的，到头了
            else next[j] = 0;
        }
    }
}

int KPM(char s1[], char s2[])
{
    int len1 = strlen(s1), len2 = strlen(s2);
    int i = 0, j = 0;
    int next[80];
    GetNext2(s2, next);
    while (i < len1 && j < len2)
    {
        if (s1[i] == s2[j] || j == -1) { i++; j++; }
        else { j = next[j]; }
    }

    if (j == len2) return i - j;
    else return -1;
}
int main()
{
    char s1[] = "lovloababaaaa";
    char s2[] = "ababa";
    cout << "主串s1：" << s1 << endl;
    cout << "模式串s2：" << s2 << endl;
    int len = strlen(s2);
    int next1[80], next2[80];
    GetNext1(s2, next1);
    GetNext2(s2, next2);
    cout << "\n暴力求解Next数组结果：";
    ShowNext(next1, len);
    cout << "\n递推求解Next数组结果：";
    ShowNext(next2, len);
    cout << "\nKPM算法匹配结果：" << KPM(s1, s2);
}
