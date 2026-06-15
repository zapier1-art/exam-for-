int main() {
    MyDeque<int> d;
     

    // --- Тест 1: Базовый push_back и размер ---
    // твой Deque должен выделить второй блок памяти!
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_back(40);
    d.push_back(50);

    

    assert(d.size() == 5);
    assert(d[0] == 10);
    assert(d[3] == 40);
    assert(d[4] == 50);

    // --- Тест 2: push_front (Магия Deque) ---
    // Добавляем в начало. Это должно привести к выделению 
    // НОВОГО блока слева (или использованию свободного места в первом блоке).
    d.push_front(9);
    d.push_front(8);

    assert(d.size() == 7);
    
    // // Индексы должны сдвинуться! То, что мы добавили спереди, теперь 0 и 1.
    assert(d[0] == 8);
    assert(d[1] == 9);
    
    // // Старые элементы должны быть доступны по новым индексам
    assert(d[2] == 10); // Бывший d[0]
    assert(d[6] == 50); // Бывший d[4]

    // // --- Тест 3: Массовый стресс-тест ---
    MyDeque<int> big_d;
    for (int i = 0; i < 100; ++i) {
        big_d.push_back(i);        // Четные сзади (логически)
        big_d.push_front(-i - 1);  // Отрицательные спереди
    }

    assert(big_d.size() == 200);
    assert(big_d[0] == -100);
    assert(big_d[99] == -1);
    assert(big_d[100] == 0);
    assert(big_d[199] == 99);

    std::cout << "Task: Custom Deque Passed! You are a monster!" << std::endl;
    return 0;
}
