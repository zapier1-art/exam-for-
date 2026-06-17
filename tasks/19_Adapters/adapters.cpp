#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <cassert>
#include <vector>

// ==========================================
// TODO 1: Правильная скобочная последовательность (Классика стека)
// Функция принимает строку из скобок: '(', ')', '[', ']', '{', '}'.
// Она должна вернуть true, если скобки расставлены правильно, и false, если нет.
// Примеры: 
// "({[]})" -> true
// "([)]"   -> false (скобка ')' закрылась раньше, чем '[')
// Подсказка: Иди по строке. Открывающие скобки клади в std::stack. 
// При встрече закрывающей - проверяй, совпадает ли она с верхней в стеке (top), и делай pop.
bool IsValidBrackets(const std::string& s) {
    // ... пиши код здесь ...
    return false;
}


// ==========================================
// TODO 2: Очередь на двух стеках (Вопрос с собеседования)
// Напиши класс очереди (FIFO), используя внутри ТОЛЬКО два стека (LIFO).
// Использовать массивы, векторы или deque запрещено. Только 2 объекта std::stack.
template <typename T>
class QueueViaStacks {
private:
    std::stack<T> stack_in;  // Стек для добавления
    std::stack<T> stack_out; // Стек для выдачи

public:
    // Добавление в конец очереди
    void push(const T& val) {
        // ...
    }

    // Возвращает первый элемент очереди
    T front() {
        // Подсказка: Если stack_out пуст, нужно "перелить" все элементы 
        // из stack_in в stack_out. При переливании из одного стека в другой 
        // их порядок КАК РАЗ перевернется, и последний добавленный станет первым!
        // ...
    }

    // Удаляет первый элемент очереди
    void pop() {
        // ...
    }
};


// ==========================================
// TODO 3: Кастомная очередь с приоритетом (Больница)
// У нас есть пациенты.
struct Patient {
    std::string name;
    int severity; // Тяжесть ранения (1 - царапина, 10 - оторвана нога)
};

// Напиши компаратор (функтор), который заставит priority_queue 
// выдавать первыми пациентов с САМОЙ ВЫСОКОЙ severity.
struct PatientCompare {
    bool operator()(const Patient& a, const Patient& b) const {
        // priority_queue по умолчанию работает как Max-Heap, 
        // он поднимает наверх элемент, для которого компаратор говорит "я меньше".
        // Верни true, если 'a' имеет МЕНЬШИЙ приоритет, чем 'b'.
        // ...
    }
};

// ==========================================

int main() {
    // --- Тест 1: Скобки (Стек) ---
    assert(IsValidBrackets("({[]})") == true);
    assert(IsValidBrackets("()[]{}") == true);
    assert(IsValidBrackets("([)]") == false);
    assert(IsValidBrackets("(") == false);
    assert(IsValidBrackets("]") == false);


    // --- Тест 2: Очередь на двух стеках ---
    QueueViaStacks<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    assert(q.front() == 1); 
    q.pop(); // Удалили 1

    q.push(4); // Добавили 4. Очередь: 2, 3, 4

    assert(q.front() == 2);
    q.pop();
    assert(q.front() == 3);


    // --- Тест 3: Больница (Priority Queue) ---
    // Передаем наш тип, underlying контейнер (всегда vector) и наш компаратор
    std::priority_queue<Patient, std::vector<Patient>, PatientCompare> er;
    
    er.push({"Bob", 3});
    er.push({"Alice", 10}); // У Алисы самое тяжелое ранение
    er.push({"Charlie", 7});

    assert(er.top().name == "Alice"); // Алиса должна пойти к врачу первой!
    er.pop();
    
    assert(er.top().name == "Charlie"); // Затем Чарли
    
    std::cout << "Task 9: Adapters Master Passed!" << std::endl;
    return 0;
}
