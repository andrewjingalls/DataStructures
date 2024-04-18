#ifndef MIN_HEAP_H
#define MIN_HEAP_H

template <typename T>
class MinHeap{
    public:
        MinHeap(int c);
        virtual ~MinHeap();
        void insert(T k);
        T getMin();
        void deleteMin();
        bool isEmpty();

    private:
        T* m_heap;
        int m_size; //how many values are in the heap
        int m_cap; //the max number of values the heap can hold
        int getLeftIdx(int i);
        int getRightIdx(int i);
        int getParentIdx(int i);
        void fixHeap(int startIdx);
};

template<typename T>
MinHeap<T>::MinHeap(int c){
    m_heap = new T[c];
    m_size = 0;
    m_cap = c;
}

template<typename T>
MinHeap<T>::~MinHeap(){
    delete[] m_heap;
}

template<typename T>
bool MinHeap<T>::isEmpty(){
    return (m_size == 0);
}

template<typename T>
int MinHeap<T>::getLeftIdx(int i){
    return (2*i)+1;
}

template<typename T>
int MinHeap<T>::getRightIdx(int i){
    return (2*i)+2;
}

template<typename T>
int MinHeap<T>::getParentIdx(int i){
    return (i-1)/2;
}

template<typename T>
T MinHeap<T>::getMin(){
    //TODO: check for empty heap
    return m_heap[0];
}

template<typename T>
void MinHeap<T>::insert(T k){
    //TODO: make sure the array isn't full
    m_heap[m_size++] = k;
    int currIdx = m_size - 1;
    //make sure the thing is still a heap
    while((currIdx != 0) && (m_heap[currIdx] < m_heap[getParentIdx(currIdx)])){
        T temp = m_heap[currIdx];
        m_heap[currIdx] = m_heap[getParentIdx(currIdx)];
        m_heap[getParentIdx(currIdx)] = temp;
        currIdx = getParentIdx(currIdx);
    }
}

template<typename T>
void MinHeap<T>::deleteMin(){
    //TODO: check for empty heap
    if(m_size == 1){
        --m_size;
    }else{
        m_heap[0] = m_heap[m_size-1];
        --m_size;
        fixHeap(0); //fix the heap starting at the root
    }
}

template<typename T>
void MinHeap<T>::fixHeap(int startIdx){
    int left = getLeftIdx(startIdx);
    int right = getRightIdx(startIdx);
    int smallest = startIdx;
    if(left < m_size && m_heap[left] < m_heap[startIdx]){
        smallest = left;
    }
    if(right < m_size && m_heap[right] < m_heap[smallest]){
        smallest = right;
    }
    if(smallest != startIdx){
        T temp = m_heap[startIdx];
        m_heap[startIdx] = m_heap[smallest];
        m_heap[smallest] = temp;
        fixHeap(smallest);
    }
}

#endif