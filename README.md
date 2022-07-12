# C++实现顺序表的基本操作
- 线性表表操作内容：
初始化、添加元素、删除元素、清空、销毁。
## 1. 顺序表表
- 顺序表特点：
只有一个“第一个元素”和“最后一个元素”。除了头和尾，每个元素仅一个前驱，一个后驱。
![image](https://user-images.githubusercontent.com/81895930/178459334-31aeb16c-3fca-4fc6-bba1-ca127373f80f.png)

- 顺序表结构：
![image](https://user-images.githubusercontent.com/81895930/178459546-4c31f8e4-65ba-49e1-a665-abd5ccb943b8.png)

## 2. 单链表
- 单链表结构：
第一个结点（首元结点）前附设头结点，数据域可以不存储信息，或者存储线性表长度（前提是数据域类型定义为整型），指针域指向第一个结点。
  - 便于首元节点的处理
  - 方便判断空表：L==NULL
  - 头指针始终是指向头结点的非空指针
![image](https://user-images.githubusercontent.com/81895930/178479012-1eb3ee75-2a82-4a87-93b5-371ebaa7d189.png)
