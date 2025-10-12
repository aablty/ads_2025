#include <iostream>
#include <stdexcept>
using namespace std;

class Heap
{
private:
    long long *data;
    long long capacity;
    long long size_;

    long long parent(long long i) { return (i - 1) / 2; }
    long long left(long long i) { return 2 * i + 1; }
    long long right(long long i) { return 2 * i + 2; }

    void heapifyUp(long long i)
    {
        while (i > 0 && data[parent(i)] > data[i])
        {
            swap(data[i], data[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(long long i)
    {
        long long smallest = i;
        long long l = left(i);
        long long r = right(i);

        if (l < size_ && data[l] < data[smallest])
            smallest = l;
        if (r < size_ && data[r] < data[smallest])
            smallest = r;

        if (smallest != i)
        {
            swap(data[i], data[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    Heap(long long cap)
    {
        capacity = cap;
        data = new long long[capacity];
        size_ = 0;
    }

    ~Heap()
    {
        delete[] data;
    }

    bool empty() const { return size_ == 0; }
    long long size() const { return size_; }

    void insert(long long val)
    {
        if (size_ == capacity)
            throw runtime_error("Heap is full");
        data[size_] = val;
        heapifyUp(size_);
        size_++;
    }

    long long extractMin()
    {
        if (size_ == 0)
            throw runtime_error("Heap is empty");
        long long minVal = data[0];
        data[0] = data[size_ - 1];
        size_--;
        heapifyDown(0);
        return minVal;
    }
};

int main()
{
    long long N;
    cin >> N;
    Heap heap(N);
    for (long long i = 0; i < N; i++)
    {
        long long x;
        cin >> x;
        heap.insert(x);
    }

    long long total = 0;
    while (heap.size() > 1)
    {
        long long a = heap.extractMin();
        long long b = heap.extractMin();
        total += a + b;
        heap.insert(a + b);
    }
    cout << total << endl;

    return 0;
}