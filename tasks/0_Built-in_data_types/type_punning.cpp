#include <iostream>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <string>
#include <cstring>

// TODO 1: Реализуй SafeEqual для сравнения double с учетом погрешности (epsilon)
// ...

// TODO 2: Реализуй GetFirstByte. 
// Функция должна принимать любой тип и возвращать значение самого первого 
// байта (по наименьшему адресу памяти), из которого состоит этот объект.
// ...

// TODO 3: Реализуй FloatToBits.
// Функция принимает float и возвращает его битовое представление в виде целого числа (uint32_t).
// ВАЖНО: В C++ кастовать float* в int* напрямую — это UB (Strict Aliasing Rule).
// ...

// TODO 4: Реализуй SqueezeString.
// Функция принимает строку по ссылке и заставляет ее "сбросить" лишнюю зарезервированную память (capacity),
// чтобы capacity стало равно (или почти равно) size.
// ...

int main() {
    // --- Тест 1: Математика с плавающей точкой ---
    double a = 0.1 + 0.2;
    double b = 0.3;
    assert(a != b); // Доказываем, что прямое сравнение не работает
    assert(SafeEqual(a, b) == true);


    // --- Тест 2: Endianness (Порядок байт) ---
    uint32_t magic = 0xDEADBEEF;
    // На процессорах x86/x64 используется Little-Endian.
    // Это значит, что младший байт (0xEF) лежит по самому первому адресу памяти!
    assert(GetFirstByte(magic) == 0xEF);


    // --- Тест 3: IEEE 754 своими глазами ---
    // Число -2.0f в памяти состоит из:
    // 1 бит знака (1), 8 бит экспоненты (1000 0000), 23 бита мантиссы (все 0).
    // Итого в битах: 1100 0000 0000 0000 0000 0000 0000 0000 (0xC0000000)
    assert(FloatToBits(-2.0f) == 0xC0000000);


    // --- Тест 4: Работа с capacity строки ---
    std::string str = "Hello";
    str.reserve(10000); // Искусственно раздуваем память строки
    assert(str.capacity() >= 10000);
    assert(str.size() == 5);

    SqueezeString(str); // Твоя функция должна сжать память

    assert(str.size() == 5); // Сама строка измениться не должна
    assert(str.capacity() < 100); // Вместимость должна сильно уменьшиться

    std::cout << "Task 0: Memory Hacker Passed!" << std::endl;
    return 0;
}
