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
    int heapSize;//�ѵĴ�С
    int maxHeapSize;//�ѿ��ٵ��������ɿռ�

    void heapfy(int i)//��i��ʼ������ɸ��heapfy
    {
        int l = this->leftChild(i);
        int r = this->rightChild(i);

        //�ҵ���ĸ�����ӣ��Һ���3��Ԫ������СԪ�ص��±�
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
        if(this->maxHeapSize < length)//����̫���������¿��ٿռ�
        {
            delete []A;
            A = new T[length+1];
            this->maxHeapSize = length;
        }

        this->heapSize = length;

        for(int i = 0; i < length; i++)//ԭʼ����copy��A��
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
            exit(1);//����ֱ���˳�
        }

        return A[1];
    }

    T extractMin()
    {
        if(this->heapSize < 1)
        {
            exit(1);//����ֱ���˳�
        }

        T min = this->A[1];

        A[1] = A[heapSize];
        this->heapSize -= 1;
        this->heapfy(1);

        return min;

    }

    void insert(T key)
    {
        if(this->heapSize == this->maxHeapSize)//���Ѿ�����
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
        A[this->heapSize] = key;//�²����ֵ�ŵ����
        int i = heapSize;
        while(i > 1 && A[parent(i)] > A[i])//����ɸ
        {
            swap(A[i],A[parent(i)]);
            i = parent(i);
        }

    }

    void decreaseKey(int i,T key)//��λ��i�ļ�ֵ���ٵ�key
    {
        if(A[i] < key)//key��ֵ��A[i]��С����ȻΥ���˱���������ĳ���
        {
            exit(1);
        }

        A[i] = key;

        while(i > 1 && A[i] < A[parent(i)])//A[i]�ļ�ֵ��parentҪ����Ȼ����ɸ
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
