int main() {
    // --- Тест 1: Рекурсивная сумма ---
    assert(SumRecursive(1, 2, 3, 4, 5) == 15);
    assert(SumRecursive(10, 20) == 30);
    assert(SumRecursive(42) == 42);
    assert(SumRecursive() == 0);


    // --- Тест 2: Сумма через Fold Expressions ---
    // auto позволяет функции вернуть правильный тип (int или double)
    assert(SumFold(1, 2, 3) == 6);
    assert(SumFold(2.5, 2.5, 5.0) == 10.0);


    // --- Тест 3: Принтер ---
    std::cout << "Should print: Args count: 3 | Values: 10 Hello 3.14\n";
    std::cout << "Real output:  ";
    PrintTypes(10, "Hello", 3.14);
    std::cout << "\n";

    std::cout << "Task: Variadic Templates Passed!" << std::endl;
    return 0;
}
