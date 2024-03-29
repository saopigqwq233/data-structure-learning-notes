# Shell排序复杂度分析  
## 1.大致思想
可以把希尔排序看作是发牌员，给每人轮流发一张牌。需要给n个人发牌，每人从第二张开始分别进行插入排序，那么第一轮下来后，
每人的牌就是有序的。接下来按照刚刚的发牌顺序把牌再收起来，减少人数，不断重复这个步骤，直到只剩下一个人，那么就是直接
插入排序。

希尔排序可以看作是插入排序的升级版本，**通过分组预先插入排序，为后续的插如排序减少循环次数，达到提高效率的目的**  
简单来说，希尔排序是
- 按照设置的 gap(\<n)值，先将数组分为不同的几组，索引为i+gap\*1、i+gap\*2、...、i+gap*j(<n)的为一组
- 对每组进行插入排序
- 缩小gap值，直至缩小至1，回到第一步
- 排序完成
## 2.代码实现
```c++
void swap(int*a,int*b){
    int tmp = *a;
    *a=*b;
    *b=tmp;
}

void shell_sort(int *a,int n){
    assert(a);
    for(int gap=n/2;gap>0;gap/=2){
        for(int i=gap;i<n;i++){
            for(int j=1;i-j*gap>-1;j++){
                if(a[i-(j-1)*gap]<a[i-j*gap])
                    swap(&a[i-(j-1)*gap],&a[i-j*gap]);
            }
        }
    }
}
```
和插入排序相似，从每组第二个元素开始遍历，对本组元素进行插入排序；gap更新后，重复该过程;gap=1时，直接进行
插入排序，最后结束。
## 复杂度
由于gap设置的差别，shell排序会出现不同的时间复杂度，此处仅分析gap以除以2减小的结果

> 最优情况：  
> 时间复杂度：O(N)  
> 空间复杂度：O(1)  
> 平均情况：  
> 时间复杂度：O(Nlog_2N)  
> 空间复杂度：O(1)


