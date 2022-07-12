# C++实现栈和队列的基本操作
- 顺序表操作内容：
初始化、添加元素、删除元素、清空、销毁。

## 1. 栈
### 1.1 顺序栈 
![image](https://user-images.githubusercontent.com/81895930/178480396-07d868ba-4dd4-4f15-97f1-20abc078fda7.png)
### 1.2 链栈
栈的主要操作是在栈顶插入和删除元素，所以不必设置头结点，直接作为栈顶最方便。
![image](https://user-images.githubusercontent.com/81895930/178480502-0c104461-033f-47de-8375-aff7a7502888.png)

## 2. 队列
![image](https://user-images.githubusercontent.com/81895930/178480615-7137426d-1922-4cd1-95cd-a404274e0443.png)

### 2.1 顺序队列
入队：rear+1，写入数据；
出队：front+1，读出数据
![image](https://user-images.githubusercontent.com/81895930/178480665-249bb98f-6703-41ba-ae05-3f09bdbcb8f5.png)

### 2.2 链队列
![image](https://user-images.githubusercontent.com/81895930/178480679-b8da6946-2181-4c7e-a3a3-aa12d16fde2c.png)
设置一个结构体，里面装载头指针和尾指针，这样就可以直接不需要遍历就能直接定位尾节点。
与单链表相同，设置头结点，头结点是空的！
