#include <iostream>
#include <vector>


template <typename T>
class VectorForwardIterator
{
private:
    const std::vector<T>& data_;
    size_t index_;

public:
    VectorForwardIterator(const std::vector<T>& data, size_t index) : data_(data), index_(index) {}

    // возвращаем сам объект
    const T& operator*() const
    {
        return data_[index_];
    }

    // возвращаем указатель на объект
    const T* operator->() const
    {
        return &data_[index_];
    }

    friend bool operator==(const VectorForwardIterator<T>& a, const VectorForwardIterator<T>& b)
    {
        return a.index_ == b.index_;
    }

    friend bool operator!=(const VectorForwardIterator<T>& a, const VectorForwardIterator<T>& b)
    {
        return a.index_ != b.index_;
    }

    // возвращает уже измененный итератор
    const VectorForwardIterator<T>& operator++()
    {
        ++index_;
        return *this;
        
    }

    // инкрементирует и возвращает не измененный итератор
    const VectorForwardIterator<T>& operator++(int)
    {
        VectorForwardIterator<T> tmp = *this;
        ++(*this);
        return tmp;
    }
};


int main()
{
    // создаем вектор
    std::vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // создаем итератор на начало и конец
    VectorForwardIterator<int> it(data, 0);
    VectorForwardIterator<int> it_end(data, data.size());
    // проходим по вектору с помощью нашего итератора и выводим элементы
    for (; it != it_end; ++it)
    {
        std::cout << *it << '\n';
    }
}