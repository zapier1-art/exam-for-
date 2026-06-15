#include <iostream>
#include <vector>
#include <list>
#include <cassert>



int main() {
    // --- Тест 1: MyCountIf с разными контейнерами ---
    std::vector<int> v = {1, 2, 3, 4, 5, 6};
    std::list<int> l = {10, 15, 20, 25};

    // Считаем четные числа в векторе (ожидаем 3: это 2, 4, 6)
    auto is_even = [](int x) { return x % 2 == 0; };
    int vec_evens = MyCountIf(v.begin(), v.end(), is_even);
    assert(vec_evens == 3);

    // Считаем числа больше 18 в списке (ожидаем 2: это 20 и 25)
    auto greater_18 = [](int x) { return x > 18; };
    int list_greater = MyCountIf(l.begin(), l.end(), greater_18);
    assert(list_greater == 2);


    // --- Тест 2: Безопасное удаление из вектора ---
    std::vector<int> to_clean = {1, 2, 3, 4, 5, 6, 8, 9};
    RemoveEvens(to_clean);
    
    // Должны остаться только нечетные: 1, 3, 5, 9
    assert(to_clean.size() == 4);
    assert(to_clean[0] == 1);
    assert(to_clean[1] == 3);
    assert(to_clean[2] == 5);
    assert(to_clean[3] == 9);

    std::cout << "Task 5: Iterators & Algorithms Passed!" << std::endl;
    return 0;
}
