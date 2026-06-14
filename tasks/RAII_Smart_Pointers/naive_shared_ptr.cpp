#include <iostream>
#include <cassert>
#include <utility>

// TODO: Реализуй template <typename T> class SharedPtr
// Подсказка: нужен вспомогательный ControlBlock, чтобы счетчик разделялся между копиями.

struct A {
    int value;
    A(int v) : value(v) {}
};

int main() {
    SharedPtr<int> p1(new int(42));
    assert(*p1 == 42);
    assert(p1.use_count() == 1);

    // 2. Копирование
    {
        SharedPtr<int> p2 = p1;
        assert(p1.use_count() == 2);
        assert(p2.use_count() == 2);
        *p2 = 10;
    } // p2 уничтожается, счетчик должен стать 1
    
    assert(*p1 == 10);
    assert(p1.use_count() == 1);

    // 3. Move-семантика (важно!)
    SharedPtr<int> p3 = std::move(p1);
    assert(p3.use_count() == 1);
    assert(p1.use_count() == 0); // После move p1 пуст
    assert(p1.get() == nullptr);

    // 4. Оператор ->
    SharedPtr<A> pa(new A(100));
    assert(pa->value == 100);

    // 5. Самоприсваивание
    p3 = p3;
    assert(*p3 == 10);

    std::cout << "Task 1: SharedPtr Passed!" << std::endl;
    return 0;
}
