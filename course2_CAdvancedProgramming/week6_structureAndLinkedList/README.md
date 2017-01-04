# 结构体和链表

## 结构体

```c++
struct student {
    int id;
    char name[20];
    int age;
}; //注意分号要加

student student1;
```

结构体是一种**数据类型**，和int, char一样，是用来定义变量的

## 链表

- 链表头：指向链表第一个节点的指针
- 链表节点：链表的每一个元素，包括
    - 当前节点数据
    - 下一个节点的弟子
- 链表尾： 地址部分为NULL
链表的插入删除操作十分方便

链表的创建

new 和 delete
```c++
int *pint = new int(1024);
// new => 用于开辟存储空间，并返回空间的起始地址
// int => 表明存放变量的类型
// 1024 => 初始值，可以不写
delete pint;
// delete => 释放指针指向的存储空间    
```

```c++
struct student {
    int id;
    int *next;
};
student *head;
head = new student;
student *temp = head;
if(创建新节点) {
    temp -> next = new student; //temp -> next == (*temp).next, 即引用结构体变量的next
    temp = temp -> next;
    if(创建新节点) {
        ...
    } else {
        temp = NULL;
    }
} else {
    temp = NULL;
}
```
