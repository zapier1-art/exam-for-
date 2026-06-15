#include <iostream>
#include <cassert>
#include <cstring>

int Add(int a, int b) { return a + b; }
int Mul(int a, int b) { return a * b; }

struct Player {
    int health = 100;
    int mana = 50;

    void Heal() { health += 20; }
    void RestoreMana() { mana += 20; }
};



int main() {
    // --- Тест 1: GenericSwap ---
    double d1 = 3.14;
    double d2 = 2.71;
    GenericSwap(&d1, &d2, sizeof(double));
    assert(d1 == 2.71);
    assert(d2 == 3.14);

    struct Secret { int id; char code; };
    Secret s1{1, 'A'}, s2{2, 'B'};
    GenericSwap(&s1, &s2, sizeof(Secret));
    assert(s1.id == 2 && s1.code == 'B');


    // --- Тест 2: Указатели на функции ---
    assert(ApplyOperation(5, 3, &Add) == 8);
    assert(ApplyOperation(5, 3, &Mul) == 15);


    // --- Тест 3: Указатели на методы (Pointer to Member) ---
    Player p1;
    
    // Заводим указатели на методы
    void (Player::*heal_ptr)() = &Player::Heal;
    void (Player::*mana_ptr)() = &Player::RestoreMana;

    CastSpell(p1, heal_ptr); // Должно увеличить hp
    CastSpell(p1, mana_ptr); // Должно увеличить mana

    assert(p1.health == 120);
    assert(p1.mana == 70);


    std::cout << "Task 3: Pointers Passed!" << std::endl;
    return 0;
}
