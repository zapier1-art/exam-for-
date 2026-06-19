#include <iostream>
#include <cassert>
#include <vector>
#include <functional>
#include <algorithm>

struct CompilerGeneratedLambda {
    // ... пиши поля и методы здесь ...
};

std::function<int()> GetIdGenerator() {
    int current_id = 0;
    // return [???]() ??? { ... };
    return [](){ return 0; }; // Исправь это
}

auto is_greater = /* ... пиши лямбду здесь ... */;


// ==========================================

int main() {
    // --- Тест 1: Имитация компилятора ---
    int mult = 5;
    CompilerGeneratedLambda fake_lambda{mult};
    assert(fake_lambda(10) == 50);
    assert(fake_lambda(3) == 15);


    // --- Тест 2: Замыкание (Closure) и mutable ---
    auto generator1 = GetIdGenerator();
    auto generator2 = GetIdGenerator(); // Это должен быть НЕЗАВИСИМЫЙ генератор!

    assert(generator1() == 1);
    assert(generator1() == 2);
    assert(generator1() == 3);

    // Второй генератор должен начать с 1!
    assert(generator2() == 1);
    assert(generator2() == 2);


    // --- Тест 3: Шаблонная (Generic) лямбда ---
    assert(is_greater(10, 5) == true);        // С целыми числами
    assert(is_greater(3.14, 5.0) == false);   // С double
    assert(is_greater('Z', 'A') == true);     // С char

    std::vector<int> v = {1, 5, 2, 8, 3};
    // Используем твою лямбду для сортировки по убыванию
    std::sort(v.begin(), v.end(), is_greater); 
    assert(v[0] == 8);
    assert(v[4] == 1);

    std::cout << "Task: Lambdas Under The Hood Passed!" << std::endl;
    return 0;
}
