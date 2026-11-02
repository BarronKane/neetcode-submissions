class DynamicArray {

public:

    DynamicArray(int capacity) {
        _size = 0;
        _capacity = capacity;
        _data = new int[capacity];
    }

    ~DynamicArray() {
        delete[] _data;
    }

    DynamicArray(const DynamicArray&) = delete;
    DynamicArray& operator=(const DynamicArray&) = delete;

    DynamicArray(DynamicArray&& other) noexcept;
    DynamicArray& operator=(DynamicArray&& other) noexcept;

    int get(int i) {
        return _data[i];
    }

    void set(int i, int n) {
        _data[i] = n;
    }

    void pushback(int n) {
        if (_size == _capacity) {
            resize();
        }

        _data[_size] = n;
        _size++;
    }

    int popback() {
        _size--;
        return _data[_size];
    }

    void resize() {
        _capacity *= 2;
        int* newData = new int[_capacity];

        std::copy(_data, _data + _size, newData);

        delete[] _data;

        _data = newData;
    }

    int getSize() {
        return _size;
    }

    int getCapacity() {
        return _capacity;
    }

private:

    int _size;
    int _capacity;
    int* _data;
};
