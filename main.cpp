#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;

// Функция для вычисления чисел Фибоначчи
unsigned long long fibonacci(unsigned n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    // Время запуска программы
    auto start = high_resolution_clock::now();

    // Указываем, сколько секунд должна выполняться программа
    int durationSeconds = 30;

    while (true) {
        // Текущее время
        auto now = high_resolution_clock::now();
        auto elapsed = duration_cast<seconds>(now - start);

        // Проверяем, не прошло ли 30 секунд
        if (elapsed.count() >= durationSeconds) break;

        // Вычисляем числа Фибоначчи
        unsigned long long fibResult = fibonacci(30); // Вы можете изменить это число для разной нагрузки

        // Выводим результат, чтобы предотвратить оптимизацию компилятора
        cout << "Fibonacci result: " << fibResult << endl;

        // Небольшая задержка, чтобы уменьшить нагрузку на процессор
        this_thread::sleep_for(milliseconds(100));
    }

    // Время окончания работы программы
    auto end = high_resolution_clock::now();

    // Выводим затраченное время
    auto elapsed = duration_cast<seconds>(end - start);
    cout << "Program finished. Total execution time: " << elapsed.count() << " seconds." << endl;

    return 0;
}

