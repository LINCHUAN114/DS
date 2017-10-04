#include <cstdio>
#include <cstdlib>

#define INIT_SIZE 100
#define LISTINCREMENT 10

typedef struct {
    int *data;      //数据
    int length;     //当前表长
    int listsize;   //线性表容量
} SqList;

bool ListInsert(SqList &L, int i, int e);

bool ListDelete(SqList &L, int i, int &e);

int LocateElem(SqList L, int e);

bool Del_Min(SqList &L, int &min);

int main() {
    SqList L;
    int e;
    L.data = (int *) malloc(INIT_SIZE * sizeof(int));
    if (!L.data) exit(-2);
    L.length = 0;
    L.listsize = INIT_SIZE;

    printf("input five numbers:");
    for (int i = 1; i <= 5; ++i) {
        scanf("%d", &e);
        ListInsert(L, i, e);
    }

    //----------------------------
    int min = -1;
    Del_Min(L, min);
    printf("the minial number:%d\n", min);
    return 0;
}

/**
 * 插入操作
 * @param L
 * @param i
 * @param e
 * @return
 */
bool ListInsert(SqList &L, int i, int e) {
    if (i < 1 || i > L.length + 1) return false;    //判断i范围是否有效
    if (L.length >= L.listsize) return false;       //当前存储空间已满，不能插入
    for (int j = L.length; j >= i; j--)             //移动元素
        L.data[j] = L.data[j - 1];
    L.data[i - 1] = e;                              //插入元素
    L.length++;                                     //长度+1
    return true;
}

/**
 * 删除操作
 * @param L
 * @param i
 * @return
 */
bool ListDelete(SqList &L, int i, int &e) {
    if (i < 1 || i > L.length) return false;        //判断i的范围是否有效
    e = L.data[i - 1];                              //将被删除的元素赋值给e
    for (int j = i; j < L.length; j++)              //将第i个位置之后的元素前移
        L.data[j - 1] = L.data[j];
    L.length--;                                     //总长度-1
    return true;
}

int LocateElem(SqList L, int e) {
    int i;
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] == e) return i + 1;
    }
    return 0;
}

//================================================

bool Del_Min(SqList &L, int &min) {
    if (L.length == 0) return false;    //条件：表空，终止操作
    min = L.data[0];
    int pos = 0;  //位置标记
    for (int i = 1; i < L.length; ++i) {
        if (L.data[i] < min) {
            min = L.data[i];
            pos = i;
        }
    }
    L.data[pos] = L.data[L.length - 1]; //将空位用最后一个元素填补
    L.length--;
    return true;
}