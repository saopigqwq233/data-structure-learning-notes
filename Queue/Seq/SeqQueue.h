#ifndef SEQ_SEQQUEUE_H
#define SEQ_SEQQUEUE_H
#include "stdio.h"
#include "stdlib.h"
#include "windows.h"
#define True 1
#define False 0
//���ݽṹ����
typedef int QElementType;
typedef struct {
    QElementType *base;//
    int Front;//��ͷ
    int Rear;//��β
    int QueueStorag;//��������
}SeqQueue;
//��ʼ������
void InitQueue(SeqQueue*, int );//��ָ��˳�����ָ��Ͷӳ�Ϊ����
//����ʵ�ʳ��ȱȳ�ʼ���еĲ���ҪСһ������������ж϶���ʱ�õ����ٵ�һ��
//���ٶ���
void DestroyQueue(SeqQueue*);//��ָ��˳����е�ָ��Ϊ����
//��ն���
void ClearQueue(SeqQueue*);//��ָ��˳����е�ָ��Ϊ����
//�ӳ�
int LengthQueue(SeqQueue*);//��ָ��˳����е�ָ��Ϊ����,���ضӳ�
//��ö�ͷ
QElementType GetQueueFront(SeqQueue*);//��ָ��˳����е�ָ��Ϊ���������ض�ͷ����
//���
void EnterQueue(SeqQueue*,QElementType);//��ָ��˳����е�ָ��Ͷ�������Ϊ����
//����
QElementType DeQueue(SeqQueue*);//��ָ��˳����е�ָ��Ϊ���������ض��ж�βԪ��
//����
int QIsFull(SeqQueue*);//��ָ��˳����е�ָ��Ϊ����,����0����1
//�ӿ�
int QIsEmpty(SeqQueue*);//��ָ��˳����е�ָ��Ϊ����,����0����1
#endif //SEQ_SEQQUEUE_H
