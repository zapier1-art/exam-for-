int main() {
    std::unordered_map<Player, int> server_db;

    Player p1{"Arthas", 80};
    Player p2{"Illidan", 80};
    Player p3{"Arthas", 10}; // Тот же ник, но другой уровень (другой игрок/твинк)

    // Если ты не написал operator== или std::hash, этот код даже не скомпилируется!
    server_db[p1] = 5000;
    server_db[p2] = 9999;
    server_db[p3] = 100;

    // Проверяем, что хэши разные и коллизии разрешаются
    assert(server_db.size() == 3);
    assert(server_db[p1] == 5000);
    assert(server_db[p3] == 100);

    // --- Тест на обход Ловушки Джокера ---
    Player unknown{"Noob", 1};
    
    int score = GetPlayerScore(server_db, unknown);
    assert(score == -1); // Игрока нет, вернули -1
    
    // САМАЯ ВАЖНАЯ ПРОВЕРКА:
    // Если ты использовал db[unknown] внутри GetPlayerScore, размер базы станет 4!
    assert(server_db.size() == 3); 

    std::cout << "Task 7: Hashes and Trees Passed!" << std::endl;
    return 0;
}
