// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
#include "stdafx.h"
#include <ostream>
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *next;
} *LinkList;
Node *CreateLinkList(int n) {
    //声明一个头指针，作为函数返回值，表示当前创建的链表
    Node *head;
    Node *p;
    //初始化链表的头结点
    LinkList = new Node;
    //初始化头指针
    head = LinkList;
    LinkList->next = NULL;
    //向链表中填充数据
    for (auto i = 0; i < n; i++) {
        p = new Node;
        p->data = i;
        p->next = LinkList->next;
        LinkList->next = p;
    }
    return head;
}
void ForeachLinkList(Node *head) {
    Node *p = head->next;
    while (p != NULL) {
        std::cout << p->data << "   ";
        p = p->next;
    }
    cout << "" << endl;
}
int GetElementFromLinkList(Node *head, int n)
{
    Node *p = head->next;
    int j = 1;
    while (p&&j < n)
    {
        p = p->next;
        j++;
    }
    return (p->data);
}
//向链表中插入数据
bool InsertElement(Node *head, int n, int element) {
    int j = 0;
    Node *p, *newNode;
    p = head;
    while (p != NULL && j < n) {
        p = p->next;
        j++;
    }
    if (p == NULL || j > n) {
        return false;
    }
    newNode = new Node;
    newNode->data = element;
    newNode->next = p->next;
    p->next = newNode;
    return true;
}
//从链表中删除数据
bool DeleteElement(Node *head, int n) {
    int j = 0;
    Node *p, *deleteNode;
    p = head;
    while (p&&j < n) {
        p = p->next;
        j++;
    }
    if (p == NULL || j > n) {
        return false;
    }
    deleteNode = p->next;
    p->next = deleteNode->next;
    delete deleteNode;
    return true;
}
int main()
{
    Node *head = CreateLinkList(10);
    cout << "-----分割线-------" << endl;
    cout << "初始链表中的数据元素" << endl;
    ForeachLinkList(head);
    cout << "从单链表中获取第五个结点的数据值" << endl;
    cout << GetElementFromLinkList(head, 7) << endl;
    cout << "-----分割线-------" << endl;
    InsertElement(head, 3, 88);
    cout << "向链表的第三个位置插入数据后，链表中的元素如下" << endl;
    ForeachLinkList(head);
    cout << "-----分割线-------" << endl;
    DeleteElement(head, 2);
    cout << "删除链表中第二个位置的数据后，链表中的元素如下" << endl;
    ForeachLinkList(head);
    return 0;
}