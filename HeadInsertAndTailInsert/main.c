//
//  main.c
//  HeadInsertAndTailInsert
//
//  Created by chenyufeng on 16/2/25.
//  Copyright © 2016年 chenyufengweb. All rights reserved.
//

/**
 *  分别使用头插法和尾插法建立单链表
 */

#include <stdio.h>
#include "stdlib.h"
#include "string.h"

typedef int elemType;
typedef struct ListNode{

    int element;
    struct ListNode *next;
}Node;

void initList(Node *pNode){

    pNode = NULL;
    printf("%s函数执行，头结点初始化完成\n",__FUNCTION__);
}

void printList(Node *pNode){

    if (pNode == NULL) {
        printf("%s函数执行，链表为空，打印失败\n",__FUNCTION__);
    }else{
        while (pNode != NULL) {
            printf("%d ",pNode->element);
            pNode = pNode->next;
        }
        printf("\n");
    }
}

//头插法
Node *HeadInsert(Node *pNode){

    Node *pInsert;
    pInsert = (Node*)malloc(sizeof(Node));
    if (pInsert == NULL) {
        printf("%s函数执行，内存分配失败，建立链表失败\n",__FUNCTION__);
        return NULL;
    }

    memset(pInsert, 0, sizeof(Node));
    scanf("%d",&(pInsert->element));
    pInsert->next = NULL;

    if (pInsert->element <= 0) {
        printf("%s函数执行，输入数据有误，建立链表失败\n",__FUNCTION__);
        return NULL;
    }

    while (pInsert->element > 0) {

        if (pNode == NULL) {
            pNode = pInsert;
        }else{

            pInsert->next = pNode;
            pNode = pInsert;
        }

        pInsert = (Node*)malloc(sizeof(Node));
        if (pInsert == NULL) {
            printf("%s函数执行，内存分配失败，建立链表失败\n",__FUNCTION__);
            return NULL;
        }

        memset(pInsert, 0, sizeof(Node));
        scanf("%d",&(pInsert->element));
        pInsert->next = NULL;
    }

    printf("%s函数执行，头插法建立链表成功\n",__FUNCTION__);

    return pNode;
}

//尾插法
Node *TailInsert(Node *pNode){

    Node *pInsert;
    Node *pMove;
    pInsert = (Node*)malloc(sizeof(Node));
    if (pInsert == NULL) {
        printf("%s函数执行，内存分配失败，建立链表失败\n",__FUNCTION__);
        return NULL;
    }

    memset(pInsert, 0, sizeof(Node));
    scanf("%d",&(pInsert->element));
    pInsert->next = NULL;

    if (pInsert->element <= 0) {
        printf("%s函数执行，输入数据有误，建立链表失败\n",__FUNCTION__);
        return NULL;
    }

    pMove = pNode;
    while (pInsert->element > 0) {
        if (pNode == NULL) {
            pNode = pInsert;
            pMove = pNode;
        }else{

            while (pMove->next != NULL) {
                pMove = pMove->next;
            }
            pMove->next = pInsert;
        }

        pInsert = (Node*)malloc(sizeof(Node));
        if (pInsert == NULL) {
            printf("%s函数执行，内存分配失败，建立链表失败\n",__FUNCTION__);
            return NULL;
        }

        memset(pInsert, 0, sizeof(Node));
        scanf("%d",&(pInsert->element));
        pInsert->next = NULL;
    }

    printf("%s函数执行，尾插法建立链表成功\n",__FUNCTION__);

    return pNode;
}

int main(int argc, const char * argv[]) {

    Node *pList;

    initList(pList);
    printList(pList);

    //头插法建立链表
    pList = HeadInsert(pList);
    printList(pList);

    //尾插法建立链表
    pList = TailInsert(pList);
    printList(pList);

    return 0;
}







