#include <iostream>
#include <vector>
#include <stdexcept>
#include <cassert>
#include <string>


class MyError : public std::runtime_error {
public:
    MyError(const std::string& msg) : std::runtime_error(msg) {}
    const char* what() const noexcept override {
        return "FATAL: Database corrupted!";
    }
};

void ThrowDanger() {
    throw MyError("Simple error");
}

std::string RunTask1() {

    return "";
}

void close_connection() {
    throw std::runtime_error("Connection timeout during close!");
}

class NetworkConnection {
public:
    NetworkConnection() { std::cout << "Connected.\n"; }
    
    // ТВОЯ ЗАДАЧА: Исправить этот деструктор!
    ~NetworkConnection() {
        close_connection(); // Опасно!
    }
};

void RunTask2() {
    try {
        NetworkConnection conn;
        throw std::logic_error("Main logic failed!"); // Начинается раскрутка стека
    } catch (const std::exception& e) {
        std::cout << "Caught main error: " << e.what() << "\n";
    }
}


int copy_count = 0;
int move_count = 0;

class FastBox {
public:
    FastBox() = default;
    
    // Конструктор копирования
    FastBox(const FastBox&) { copy_count++; }
    
    // Move-конструктор
    // ДОБАВЬ СЮДА МАГИЧЕСКОЕ СЛОВО!
    FastBox(FastBox&&) { move_count++; }
};

void RunTask3() {
    std::vector<FastBox> v;
    v.reserve(1);
    v.push_back(FastBox()); // Кладем первый элемент (size 1, cap 1)
    
    // Заставляем вектор сделать реаллокацию!
    // Он должен перенести первый элемент в новую память.
    v.push_back(FastBox()); 
}

// ==========================================

int main() {
    // --- Тест 1: Полиморфный catch ---
    assert(RunTask1() == "FATAL: Database corrupted!");

    // --- Тест 2: Безопасный деструктор ---
    // Если ты не исправил деструктор, программа просто ЖЕСТКО УПАДЕТ здесь.
    // std::terminate called after throwing an instance...
    RunTask2();
    
    // --- Тест 3: std::vector и noexcept ---
    copy_count = 0;
    move_count = 0;
    RunTask3();
    
    // Вектор должен использовать Move-конструктор при реаллокации!
    // Если copy_count > 0, значит ты забыл noexcept.
    assert(copy_count == 0);
    assert(move_count >= 1);

    std::cout << "Task 10: Exceptions Passed!" << std::endl;
    return 0;
}
