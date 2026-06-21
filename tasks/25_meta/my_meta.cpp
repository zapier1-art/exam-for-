int main() {
    // --- Тест 1: Проверяем my_is_pointer ---
    static_assert(my_is_pointer<int>::value == false, "int is not a pointer!");
    static_assert(my_is_pointer<int*>::value == true, "int* is a pointer!");
    static_assert(my_is_pointer<double**>::value == true, "double** is a pointer!");

    // --- Тест 2: Проверяем синтаксический сахар _v ---
    static_assert(my_is_pointer_v<int> == false, "Failed _v for false");
    static_assert(my_is_pointer_v<char*> == true, "Failed _v for true");

    // --- Тест 3: Проверяем my_remove_pointer ---
    // Убираем ОДИН уровень указателя
    using T1 = my_remove_pointer<int*>::type;  // Должен стать int
    using T2 = my_remove_pointer<int>::type;   // Должен остаться int
    using T3 = my_remove_pointer<int**>::type; // Должен стать int* 

    static_assert(std::is_same_v<T1, int>, "T1 should be int");
    static_assert(std::is_same_v<T2, int>, "T2 should be int");
    static_assert(std::is_same_v<T3, int*>, "T3 should be int*");

    // --- Тест 4: Проверяем синтаксический сахар _t ---
    using T4 = my_remove_pointer_t<float*>;
    static_assert(std::is_same_v<T4, float>, "T4 should be float via _t");

    std::cout << "Task: Metafunctions Inside-Out Passed!" << std::endl;
    return 0;
}
