#include <iostream>
#include <cassert>

// TODO: Реализуй template <typename T, typename Deleter = DefaultDeleter<T>> class UniquePtr

// Дефолтный удалитель
template <typename T>
struct DefaultDeleter {
    void operator()(T* ptr) const {
        delete ptr;
    }
};

int main() {
    // 1. Базовое использование
    UniquePtr<int> p1(new int(5));
    assert(*p1 == 5);

    // 2. Проверка EBO (Empty Base Optimization)
    // Дефолтный удалитель не имеет состояния (нет полей), значит размер 
    // UniquePtr должен быть равен размеру одного указателя!
    static_assert(sizeof(UniquePtr<int>) == sizeof(int*), 
        "Провал! EBO не реализована, твой UniquePtr слишком толстый!");

    // 3. Кастомный Deleter с состоянием (лямбда)
    bool is_deleted = false;
    auto custom_deleter = [&is_deleted](int* ptr) {
        is_deleted = true;
        delete ptr;
    };

    {
        // Передаем тип лямбды и саму лямбду
        UniquePtr<int, decltype(custom_deleter)> p2(new int(10), custom_deleter);
        assert(*p2 == 10);
    }
    
    assert(is_deleted == true); // Деструктор p2 должен был вызвать лямбду

    std::cout << "Task 2: UniquePtr Passed!" << std::endl;
    return 0;
}
