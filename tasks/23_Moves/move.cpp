HeavyString MakeStringGood() {
    HeavyString local("ITMO");
    // ТВОЯ ЗАДАЧА: Сделай правильный return
    return std::move(local); // Убери ошибку джуниора!
}


// ==========================================
// TODO 3: Детектор категорий (Функция-индикатор)
// У нас есть две перегрузки одной функции.
// Первая принимает lvalue, вторая - rvalue.

int DetectCategory(std::string& s) {
    return 1; // Это lvalue (живой объект)
}

int DetectCategory(std::string&& s) {
    return 2; // Это rvalue (prvalue или xvalue)
}


int main() {
    // Сбрасываем счетчики
    copy_calls = 0;
    move_calls = 0;

    // --- Тест 1: Конструкторы ---
    HeavyString a("Hello");
    HeavyString b = a;            // Должен вызваться конструктор копирования
    HeavyString c = std::move(a); // Должен вызваться Move-конструктор

    assert(copy_calls == 1);
    assert(move_calls == 1);

    // --- Тест 2: Оператор присваивания ---
    HeavyString d;
    d = std::move(b); // Должен вызваться Move-оператор присваивания
    assert(move_calls == 2);

    // --- Тест 3: RVO ---
    copy_calls = 0;
    move_calls = 0;
    HeavyString e = MakeStringGood();
    
    // Если ты исправил TODO 2, компилятор сделает RVO (или NRVO),
    // и счетчики останутся равны НУЛЮ!
    assert(copy_calls == 0);
    assert(move_calls == 0);

    // --- Тест 4: Детектор категорий ---
    std::string text = "Magic";
    
    // Ты должен угадать, какая версия DetectCategory вызовется!
    // Замени 0 на правильный ожидаемый ответ (1 или 2).
    
    assert(DetectCategory(text) == 1 /* Замени 0 */); 
    
    assert(DetectCategory(std::string("Temp")) == 2 /* Замени 0 */);
    
    assert(DetectCategory(std::move(text)) == 2 /* Замени 0 */);

    std::cout << "Task: Move Semantics Passed!" << std::endl;
    return 0;
}
