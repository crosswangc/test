#include <bits/stdc++.h> // cout cin
// #include <iostream>
#include <vector>

using namespace std;

class MinHeap
{
    vector<int> v;
    // #define L(x) 2 * x + 1   // 左子节点
    // #define R(x) 2 * x + 2   // 右子节点
    // #define P(x) (x - 1) / 2 // 父节点

    void makeHeap(int i)
    {
        int l = 2 * i;
        int r = 2 * i + 1;
        // int l = L(i), r = R(i);
        int minIndex = i;
        if (l < v.size() && v[l] < v[minIndex])
        {
            minIndex = l;
        }
        if (r < v.size() && v[r] < v[minIndex])
        {
            minIndex = r;
        }
        if (minIndex != i)
        {
            swap(v[i], v[minIndex]);
            makeHeap(minIndex);
        }
    }

public:
    // minHeap() {
    //     v.push_back(-1);
    // }

    void pushHeap(int data)
    {
        v.push_back(data);
        int index = v.size() - 1;
        int parent = index / 2;
        while (v[parent] > v[index] && index > 0)
        {
            // while (v[parent] > v[index] && index > 1) {
            swap(v[parent], v[index]);
            index = parent;
            parent = parent / 2;
        }
    }

    void popHeap()
    {
        int last = v.size() - 1;
        swap(v[0], v[last]);
        v.pop_back();
        makeHeap(0);
    }

    int getMin()
    {
        return v[0];
        // return v[1];
    }

    bool isEmpty()
    {
        return v.size() == 0;
    }
};

class MaxHeap
{
    vector<int> v;

    void makeHeap(int i)
    {
        int l = 2 * i;
        int r = 2 * i + 1;
        int maxIndex = i;

        if (l < v.size() && v[l] > v[maxIndex])
        {
            maxIndex = l;
        }
        if (r < v.size() && v[r] > v[maxIndex])
        {
            maxIndex = r;
        }
        if (maxIndex != i)
        {
            swap(v[i], v[maxIndex]);
            makeHeap(maxIndex);
        }
    }

public:
    void pushHeap(int data)
    {
        v.push_back(data);
        int index = v.size() - 1;
        int parent = index / 2;

        while (v[index] > v[parent] && index > 0)
        {
            swap(v[index], v[parent]);
            index = parent;
            parent = parent / 2;
        }
    }

    void popHeap()
    {
        int last = v.size() - 1;
        swap(v[0], v[last]);
        v.pop_back();
        makeHeap(0);
    }

    int getMax()
    {
        return v[0];
    }

    bool isEmpty()
    {
        return v.size() == 0;
    }
};

template <typename T>
class BinaryHeapMax
{
private:
    vector<T> v; // ignore index 0
    int heap_size;

    int parent(int i)
    {
        return i >> 1; // i / 2
    }
    int left(int i)
    {
        return i << 1; // i * 2
    }
    int right(int i)
    {
        return (i << 1) + 1; // i * 2 + 1
    }

    void shift_up(int i)
    { // O(log(n))
        if (i == 1)
            return;
        if (v[i] > v[parent(i)])
        {
            swap(v[i], v[parent(i)]);
            shift_up(parent(i));
        }
    }

    void shift_down(int i)
    { // O(log(n))
        if (i > heap_size)
            return; // beyond last element, do nothing
        int swap_id = i;
        if (left(i) <= heap_size && v[i] < v[left(i)])
        { // compare with left child, if exists
            swap_id = left(i);
        }
        if (right(i) <= heap_size && v[i] < v[right(i)])
        {
            swap_id = right(i);
        }
        if (swap_id != i)
        {
            swap(v[i], v[swap_id]);
            shift_down(swap_id);
        }
    }

public:
    BinaryHeapMax()
    {
        v.push_back(T()); // O(1), set index 0 to be 'dummy'
        heap_size = 0;
    }
    ~BinaryHeapMax()
    {
        v.clear(); // O(n)
    }

    void push(T x)
    { // O(log(n))
        if (heap_size + 1 >= (int)v.size())
            v.push_back(T()); // enlarge the vector by one (internally, vector doubles its size) if needed, to avoid potential RTE below, O(1)
        v[heap_size] = x;
        shift_up(heap_size);
    }

    void pop()
    {                               // O(log n)
        swap(v[1], v[heap_size--]); // swap with the last existing leaf, O(1)
        shift_down(1);
    }

    T top() {
        return v[1]; // this is the root
    }

    bool isEmpty() {
        return heap_size == 0;
    }

    int size() {
        assert(heap_size <= (int)v.size());
        return heap_size;
    }
};

// int main()
// {
//     // if the dataset(a[]) is large
//     // ios_base::sync_with_stdio(false);
//     // cin.tie(NULL);

//     int a[] = {10, 45, 33, 211, 16, 120, 150, 132};
//     int n = sizeof(a) / sizeof(int);

//     // MinHeap minH;
//     // MaxHeap maxH;
//     BinaryHeapMax<int> maxH;
//     for (int i = 0; i < n; i++) {
//         // minH.pushHeap(a[i]);
//         maxH.push(a[i]);
//     }
//     // while (!minH.isEmpty()) {
//     while (!maxH.isEmpty()) {
//         // cout << minH.getMin() << " ";
//         cout << maxH.top() << " ";
//         // minH.popHeap();
//         maxH.pop();
//     }

//     return 0;
// }

/* Output : 10 16 33 45 120 132 150 211 */