#include <iostream>
#include <cassert>
#include <cstdint>


// ==========================================
// Полиморфная иерархия для TODO 2
struct Base {
    virtual ~Base() = default; // Полиморфный базовый класс
};

struct Derived : Base {
    int secret_data = 777;
};

struct FakeDerived : Base {
    int fake_data = 0;
};


// ==========================================
// Старая C-библиотека (менять эту функцию нельзя!)
void LegacyC_API(int* ptr) {
    *ptr *= 2; // Она удваивает значение
}



int main() {
    StrictBox box1(10);
    StrictBox box2(0);
    
    // StrictBox box_bad = 5; // Раскомментирование этой строки должно ломать компиляцию
    // int bad_math = box1 + 5; // И этой тоже
    
    assert(box1 ? true : false);  // Сработает operator bool
    assert(box2 ? false : true); 


    // --- Тест 2: dynamic_cast ---
    Derived real_derived;
    FakeDerived fake_derived;
    
    Base* ptr1 = &real_derived;
    Base* ptr2 = &fake_derived;

    assert(GetSecretData(ptr1) == 777);
    assert(GetSecretData(ptr2) == -1); // Безопасно отклонено!


    // --- Тест 3: const_cast ---
    int my_value = 10;
    const int* const_ptr = &my_value; // Сделали вид, что это константа
    
    UseLegacyAPI(const_ptr); // Должна вызвать LegacyC_API
    assert(my_value == 20);  // Значение должно удвоиться


    // --- Тест 4: reinterpret_cast ---
    float pi = 3.14f;
    int* int_ptr = ReadFloatAsInt(&pi);
    // Проверяем, что адреса абсолютно одинаковые
    assert((void*)&pi == (void*)int_ptr);

    std::cout << "Task 1: Type Conversions Passed!" << std::endl;
    return 0;
}
