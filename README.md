# C++实现串的基本操作
## 1. BF算法
暴力匹配，时间复杂度高，存在大量回溯，匹配成功过的字符需要向右滑动一段距离。
## 2. KPM算法

- 求模式串的PMT数组，每个元素的PMT的值是其前缀和后缀交集中最长的字符串的长度
- 再把PMT数组相对模式串向右移动一个单位，第一个空缺值用-1填补，得到next数组
- 模式串部分匹配成功的时候，i 不移动，j 应向右移动的单位等于元素对应next数组的值
![image](https://user-images.githubusercontent.com/81895930/178531708-a86fcbbc-bdf2-4e2c-9b03-c2d8ccd79379.png)![image](https://user-images.githubusercontent.com/81895930/178531772-034db54a-d7c5-4d94-aef8-c4de3d7c4d37.png)


如何求next数组：
- 如index为11的元素a，前一位是index为10的 c（目标：回溯找到c），其next值是4，index为4的是a（不等于c），a的next值是2，index为2的是a（不等于c），其next值是0，index为0的元素是a（不等于c），其next值是-1，只好 -1+1=0，成为最后求出的index为11的a的next值。
- 如index为5的元素a，前一个元素是index为4的a（目标：回溯找到a），next值是2，index为2 的元素是a（找到啦！帮忙找到该元素的归功于前一个index的next，即2），因此index为4 的元素的next值 2，+1=3，3是index为5的元素的next值。
![image](https://user-images.githubusercontent.com/81895930/178531830-3501ae62-6ab3-40fe-baba-d611250aabd8.png)
![image](https://user-images.githubusercontent.com/81895930/178531848-bd9603ed-ca78-4506-97fc-89a43dd5dfde.png)
