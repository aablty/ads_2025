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
        while (i > 0 && data[parent(i)] < data[i])
        {
            swap(data[i], data[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(long long i)
    {
        long long largest = i;
        long long l = left(i);
        long long r = right(i);

        if (l < size_ && data[l] > data[largest])
            largest = l;
        if (r < size_ && data[r] > data[largest])
            largest = r;

        if (largest != i)
        {
            swap(data[i], data[largest]);
            heapifyDown(largest);
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

    long long extractMax()
    {
        if (size_ == 0)
            throw runtime_error("Heap is empty");
        long long maxVal = data[0];
        data[0] = data[size_ - 1];
        size_--;
        heapifyDown(0);
        return maxVal;
    }
};

int main()
{
    long long N, X;
    cin >> N >> X;
    Heap heap(N);
    for (long long i = 0; i < N; i++)
    {
        long long x;
        cin >> x;
        heap.insert(x);
    }

    long long total = 0;
    while (X--)
    {
        long long a = heap.extractMax();

        if (a > 1)
        {
            total += a;
            heap.insert(a - 1);
        }
        else
        {
            total += a;
        }
    }
    cout << total << endl;

    return 0;
}