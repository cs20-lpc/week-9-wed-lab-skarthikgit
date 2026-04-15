template <typename T>
ArrayQueue<T>::ArrayQueue(int i) {
    if (i <= 0) {
        throw string("queue size must be positive");
    }

    maxSize = i;
    buffer = new T[maxSize];
    frontIndex = 0;
    backIndex = maxSize - 1;
    this->length = 0;
}

template <typename T>
ArrayQueue<T>::ArrayQueue(const ArrayQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayQueue<T>& ArrayQueue<T>::operator=(const ArrayQueue<T>& rightObj) {
    if (this != &rightObj) {
        delete[] buffer;
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayQueue<T>::~ArrayQueue() {
    delete[] buffer;
}

template <typename T>
T ArrayQueue<T>::back() const {
    if (isEmpty()) {
        throw string("cannot access back of an empty queue");
    }

    return buffer[backIndex];
}

template <typename T>
void ArrayQueue<T>::clear() {
    this->length = 0;
    frontIndex = 0;
    backIndex = maxSize - 1;
}

template <typename T>
void ArrayQueue<T>::copy(const ArrayQueue<T>& copyObj) {
    maxSize = copyObj.maxSize;
    buffer = new T[maxSize];
    this->length = copyObj.length;
    frontIndex = copyObj.frontIndex;
    backIndex = copyObj.backIndex;

    for (int i = 0; i < maxSize; i++) {
        buffer[i] = copyObj.buffer[i];
    }
}

template <typename T>
void ArrayQueue<T>::dequeue() {
    if (isEmpty()) {
        throw string("cannot dequeue from an empty queue");
    }

    frontIndex = (frontIndex + 1) % maxSize;
    this->length--;

    if (isEmpty()) {
        frontIndex = 0;
        backIndex = maxSize - 1;
    }
}

template <typename T>
void ArrayQueue<T>::enqueue(const T& elem) {
    if (isFull()) {
        throw string("cannot enqueue into a full queue");
    }

    backIndex = (backIndex + 1) % maxSize;
    buffer[backIndex] = elem;
    this->length++;
}

template <typename T>
T ArrayQueue<T>::front() const {
    if (isEmpty()) {
        throw string("cannot access front of an empty queue");
    }

    return buffer[frontIndex];
}

template <typename T>
int ArrayQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayQueue<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayQueue<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayQueue<T>::isFull() const {
    return this->length == maxSize;
}
