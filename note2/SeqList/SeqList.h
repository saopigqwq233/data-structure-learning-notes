#pragma once
//头文件
#include "stdio.h"
#include "stdlib.h"
//宏定义
//数据类型处理
typedef int ElementType;//顺序表存储数据类型.
//顺序表单元数据结构定义
typedef struct SeqList{
    ElementType *data;//存储数据的数组
    int date_size;//表中数据数量
    int capacity;//表容量
}SL;

