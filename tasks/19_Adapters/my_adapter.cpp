#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <cassert>

template <typename T, typename Container = std::deque<T>>
class MyStack {
private:

    Container c; 

public:
    
};

int main() {
    // --- Тест 1: Стек по умолчанию (под капотом deque) ---
    MyStack<int> s1;
    s1.push(10);
    s1.push(20);
    
    assert(s1.top() == 20);
    s1.pop();
    assert(s1.top() == 10);
    
    // --- Тест 2: Стек на основе Вектора! ---
    // Мы явно говорим: "Используй vector для хранения!"
    MyStack<int, std::vector<int>> s2;
    s2.push(99);
    s2.push(88);
    
    assert(s2.top() == 88);
    
    // --- Тест 3: А почему у стека нет итераторов? ---
    // Попробуй раскомментировать код ниже. Он не скомпилируется!
    // У класса MyStack нет методов begin() и end(). 
    // Мы спрятали вектор (он private) и запретили по нему бегать.
    /*
    for (int x : s2) {
        std::cout << x; 
    }
    */

    std::cout << "My custom stack works perfectly!" << std::endl;
    return 0;
}
