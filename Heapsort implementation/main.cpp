#ifndef MAIN_CPP_INCLUDED
#define MAIN_CPP_INCLUDED
#include <iostream>
#include <cstdlib>
#include <cstdio>

#define MAXHEAPSIZE 20000
using namespace std;

template <typename T>
class MinHeap
{
private:
    T *A;
    int heapSize;//堆的大小
    int maxHeapSize;//堆开辟的最大可容纳空间

    void heapfy(int i)//从i开始逐步向下筛，heapfy
    {
        int l = this->leftChild(i);
        int r = this->rightChild(i);

        //找到父母，左孩子，右孩子3个元素中最小元素的下标
        int smallest = i;
        if(l <= this->heapSize && A[l] < A[i])
        {
            smallest = l;
        }

        if(r <= this->heapSize && A[r] < A[smallest])
        {
            smallest = r;
        }

        if(smallest != i)
        {
            swap(A[i],A[smallest]);
            this->heapfy(smallest);
        }

    }

public:
    MinHeap(const int maxSize = MAXHEAPSIZE) : heapSize(0),maxHeapSize(maxSize)
    {
        A = new T[maxHeapSize+1];
    }

    ~MinHeap()
    {
        delete []A;
    }

    void buildMinHeap(T *arr,int length)
    {
        if(this->maxHeapSize < length)//数组太长，需重新开辟空间
        {
            delete []A;
            A = new T[length+1];
            this->maxHeapSize = length;
        }

        this->heapSize = length;

        for(int i = 0; i < length; i++)//原始数组copy至A中
        {
            this->A[i+1] = arr[i];
        }


        for(int i = this->heapSize / 2; i >= 1; i--)
        {
            this->heapfy(i);
        }


    }

    T& min()
    {
        if(this->heapSize < 1)
        {
            exit(1);//程序直接退出
        }

        return A[1];
    }

    T extractMin()
    {
        if(this->heapSize < 1)
        {
            exit(1);//程序直接退出
        }

        T min = this->A[1];

        A[1] = A[heapSize];
        this->heapSize -= 1;
        this->heapfy(1);

        return min;

    }

    void insert(T key)
    {
        if(this->heapSize == this->maxHeapSize)//堆已经满了
        {
            this->maxHeapSize *= 2;

            T *newA = new T[this->maxHeapSize];
            for(int i = 1; i <= this->heapSize; i++)
            {
                newA[i] = this->A[i];
            }

            delete []A;
            A = newA;
        }

        this->heapSize += 1;
        A[this->heapSize] = key;//新插入的值放到最后
        int i = heapSize;
        while(i > 1 && A[parent(i)] > A[i])//向上筛
        {
            swap(A[i],A[parent(i)]);
            i = parent(i);
        }

    }

    void decreaseKey(int i,T key)//将位置i的键值减少到key
    {
        if(A[i] < key)//key的值比A[i]还小，显然违背了本函数定义的初衷
        {
            exit(1);
        }

        A[i] = key;

        while(i > 1 && A[i] < A[parent(i)])//A[i]的键值比parent要大，显然向上筛
        {
            swap(A[i],A[parent(i)]);
            i = parent(i);
        }

    }

    int parent(int i)
    {
        if(i > 1)
        {
            return i / 2;
        }
        else
        {
            exit(1);
        }

    }

    int leftChild(int i)
    {
        return 2 * i;
    }

    int rightChild(int i)
    {
        return 2 * i + 1;
    }

    int Size()
    {
        return this->heapSize;
    }

    void print()
    {
        for(int i = 1; i <= this->heapSize; i++)
        {
            std::cout << A[i] << " ";
        }

        std::cout << endl;
    }


};


int main()
{
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    std::ios::sync_with_stdio(false);

    int cases;
    scanf("%d", &cases);
    while(cases--)
    {
        int number;
        scanf("%d", &number);
        MinHeap<int> heap;
        while(number--)
        {
            int oper;
            scanf("%d", &oper);
            switch(oper)
            {
            case 1:
            {
                int value;
                scanf("%d", &value);
                heap.insert(value);
                break;
            }
            case 2:
            {
                printf("%d\n", heap.min());
                heap.extractMin();
                break;
            }
            default:
                break;
            }

        }
    }


    return 0;
}
#endif // MAIN_CPP_INCLUDED
