int main() {
    Cat my_cat;
    my_cat.MakeSound(); // Должно вывести "Meow!"

    // Раскомментирование этого кода должно приводить к ОШИБКЕ КОМПИЛЯЦИИ,
    // если ты правильно защитил базовый класс в TODO 2.
    FakeDog bad_dog;
    bad_dog.MakeSound();

    std::cout << "Task: CRTP Defender Passed!" << std::endl;
    return 0;
}
