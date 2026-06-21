int main() {
    // --- Тест 1: Constexpr ---
    // Это проверяется прямо во время КОМПИЛЯЦИИ!
    // Если твоя функция не constexpr, компилятор выдаст ошибку здесь:
    static_assert(Factorial(5) == 120, "Math is broken!");
    static_assert(Factorial(0) == 1, "0! should be 1");


    // --- Тест 2: SFINAE Overload Resolution ---
    constexpr int a = 10;
    constexpr double b = 3.14;
    
    // Компилятор должен выбрать первую перегрузку (вернет 1)
    static_assert(GetTypeId(a) == 1, "SFINAE failed for int");
    
    // // Компилятор должен выбрать вторую перегрузку (вернет 2)
    static_assert(GetTypeId(b) == 2, "SFINAE failed for double");


    // // --- Тест 3: Concepts ---
    static_assert(GetTypeIdModern(a) == 1, "Concepts failed for int");
    static_assert(GetTypeIdModern(b) == 2, "Concepts failed for double");

    std::cout << "Task: Metaprogramming Passed! You are a Compiler Wizard!" << std::endl;
    return 0;
}
