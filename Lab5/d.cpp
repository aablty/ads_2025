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
        if (size_ < capacity)
        {
            data[size_] = val;
            heapifyUp(size_);
            size_++;
        }
        else if (val > data[0])
        {
            data[0] = val;
            heapifyDown(0);
        }
    }

    long long getMin()
    {
        if (size_ == 0)
            throw runtime_error("Heap is empty");
        return data[0];
    }

    long long getData(long long i)
    {
        return data[i];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, K;
    cin >> N >> K;

    Heap heap(K);
    long long currentSum = 0;

    while (N--)
    {
        string cmd;
        cin >> cmd;
        if (cmd == "print")
        {
            cout << currentSum << "\n";
        }
        else if (cmd == "insert")
        {
            long long val;
            cin >> val;

            if (heap.size() < K)
            {
                heap.insert(val);
                currentSum += val;
            }
            else if (val > heap.getMin())
            {
                currentSum -= heap.getMin();
                heap.insert(val);
                currentSum += val;
            }
        }
    }

    return 0;
}   
