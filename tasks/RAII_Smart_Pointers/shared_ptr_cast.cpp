#include <iostream>
#include <cassert>

// TODO: Доработай свой SharedPtr из Задачи 1.
// Нужно добавить шаблонный конструктор, принимающий SharedPtr<U>.

struct Base {
    int b;
    Base() : b(1) {}
    virtual ~Base() = default;
};

struct Derived : Base {
    int d;
    Derived() : d(2) {}
};

int main() {
    SharedPtr<Derived> derived_ptr(new Derived());
    assert(derived_ptr.use_count() == 1);

    // ВНИМАНИЕ: Здесь создается SharedPtr<Base> из SharedPtr<Derived>
    // Если ты не написал template <typename U> SharedPtr(const SharedPtr<U>& other),
    // код не скомпилируется.
    SharedPtr<Base> base_ptr = derived_ptr;

    assert(base_ptr->b == 1);
    
    // Control block должен быть ОБЩИМ для Base и Derived!
    assert(base_ptr.use_count() == 2);
    assert(derived_ptr.use_count() == 2);

    std::cout << "Task 3: Polymorphic SharedPtr Passed!" << std::endl;
    return 0;
}
