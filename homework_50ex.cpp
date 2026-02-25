#include <iostream>
#include <windows.h>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm> // для swap
#include <ctime>     // для rand()
using namespace std;

//Простые помощники
long long absll(long long x) { return (x < 0) ? -x : x; }

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * 1LL * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

long long gcdll(long long a, long long b) {
    a = absll(a);
    b = absll(b);
    while (b != 0) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}


// 1. Вывести 1..10
void task1() {
    cout << "FOR: ";
    for (int i = 1; i <= 10; i++) cout << i << " ";
    cout << "\n";

    cout << "WHILE: ";
    int j = 1;
    while (j <= 10) { cout << j << " "; j++; }
    cout << "\n";

    cout << "DO-WHILE: ";
    int k = 1;
    do { cout << k << " "; k++; } while (k <= 10);
    cout << "\n";
}

// 2. Вывести 10..1
void task2() {
    cout << "FOR: ";
    for (int i = 10; i >= 1; i--) cout << i << " ";
    cout << "\n";

    cout << "WHILE: ";
    int j = 10;
    while (j >= 1) { cout << j << " "; j--; }
    cout << "\n";

    cout << "DO-WHILE: ";
    int k = 10;
    do { cout << k << " "; k--; } while (k >= 1);
    cout << "\n";
}

// 3. Четные 2..20
void task3() {
    cout << "FOR: ";
    for (int i = 2; i <= 20; i += 2) cout << i << " ";
    cout << "\n";

    cout << "WHILE: ";
    int j = 2;
    while (j <= 20) { cout << j << " "; j += 2; }
    cout << "\n";

    cout << "DO-WHILE: ";
    int k = 2;
    do { cout << k << " "; k += 2; } while (k <= 20);
    cout << "\n";
}

// 4. Сумма 1..N
void task4() {
    long long N;
    cout << "N: ";
    cin >> N;

    long long s1 = 0;
    for (long long i = 1; i <= N; i++) s1 += i;
    cout << "FOR sum = " << s1 << "\n";

    long long s2 = 0, j = 1;
    while (j <= N) { s2 += j; j++; }
    cout << "WHILE sum = " << s2 << "\n";

    long long s3 = 0;
    if (N >= 1) {
        long long k = 1;
        do { s3 += k; k++; } while (k <= N);
    }
    cout << "DO-WHILE sum = " << s3 << "\n";
}

// 5. Факториал 1..N
void task5() {
    long long N;
    cout << "N: ";
    cin >> N;
    if (N < 0) { cout << "N должен быть >= 0\n"; return; }

    unsigned long long f1 = 1;
    for (long long i = 1; i <= N; i++) f1 *= (unsigned long long)i;
    cout << "FOR factorial = " << f1 << "\n";

    unsigned long long f2 = 1;
    long long j = 1;
    while (j <= N) { f2 *= (unsigned long long)j; j++; }
    cout << "WHILE factorial = " << f2 << "\n";

    unsigned long long f3 = 1;
    if (N >= 1) {
        long long k = 1;
        do { f3 *= (unsigned long long)k; k++; } while (k <= N);
    }
    cout << "DO-WHILE factorial = " << f3 << "\n";
}

// 6. Таблица умножения для числа X (до 10)
void task6() {
    long long x;
    cout << "X: ";
    cin >> x;

    cout << "FOR:\n";
    for (int i = 1; i <= 10; i++) cout << x << " * " << i << " = " << x * i << "\n";

    cout << "WHILE:\n";
    int j = 1;
    while (j <= 10) { cout << x << " * " << j << " = " << x * j << "\n"; j++; }

    cout << "DO-WHILE:\n";
    int k = 1;
    do { cout << x << " * " << k << " = " << x * k << "\n"; k++; } while (k <= 10);
}

// 7. Среднее арифм N чисел
void task7() {
    int N;
    cout << "N: ";
    cin >> N;
    if (N <= 0) { cout << "N должен быть > 0\n"; return; }

    // FOR
    double sum = 0;
    cout << "FOR: вводи " << N << " чисел:\n";
    for (int i = 0; i < N; i++) {
        double a; cin >> a;
        sum += a;
    }
    cout << "FOR average = " << sum / N << "\n";

    // WHILE
    sum = 0;
    cout << "WHILE: вводи " << N << " чисел:\n";
    int j = 0;
    while (j < N) {
        double a; cin >> a;
        sum += a;
        j++;
    }
    cout << "WHILE average = " << sum / N << "\n";

    // DO-WHILE
    sum = 0;
    cout << "DO-WHILE: вводи " << N << " чисел:\n";
    int k = 0;
    do {
        double a; cin >> a;
        sum += a;
        k++;
    } while (k < N);
    cout << "DO-WHILE average = " << sum / N << "\n";
}

// 8. Количество цифр в числе
void task8() {
    long long x;
    cout << "x: ";
    cin >> x;
    x = absll(x);

    // FOR
    int c1 = 0;
    if (x == 0) c1 = 1;
    else {
        for (; x > 0; x /= 10) c1++;
    }
    cout << "FOR digits = " << c1 << "\n";

    // восстановим ввод (проще заново спросить)
    cout << "Введите x снова: ";
    cin >> x;
    x = absll(x);

    // WHILE
    int c2 = 0;
    if (x == 0) c2 = 1;
    else {
        while (x > 0) { c2++; x /= 10; }
    }
    cout << "WHILE digits = " << c2 << "\n";

    cout << "Введите x снова: ";
    cin >> x;
    x = absll(x);

    // DO-WHILE
    int c3 = 0;
    do { c3++; x /= 10; } while (x > 0);
    cout << "DO-WHILE digits = " << c3 << "\n";
}

// 9. Сумма цифр
void task9() {
    long long x;
    cout << "x: ";
    cin >> x;
    x = absll(x);

    // FOR
    int s1 = 0;
    for (; x > 0; x /= 10) s1 += (int)(x % 10);
    cout << "FOR sum digits = " << s1 << "\n";

    cout << "Введите x снова: ";
    cin >> x;
    x = absll(x);

    // WHILE
    int s2 = 0;
    while (x > 0) { s2 += (int)(x % 10); x /= 10; }
    cout << "WHILE sum digits = " << s2 << "\n";

    cout << "Введите x снова: ";
    cin >> x;
    x = absll(x);

    // DO-WHILE
    int s3 = 0;
    if (x == 0) s3 = 0; // 0 -> сумма 0
    else {
        do { s3 += (int)(x % 10); x /= 10; } while (x > 0);
    }
    cout << "DO-WHILE sum digits = " << s3 << "\n";
}

// 10. Цифры в обратном порядке
void task10() {
    long long x;
    cout << "x: ";
    cin >> x;
    long long y = absll(x);

    // FOR (через строку, чтобы показать цифры)
    string s = to_string(y);
    cout << "FOR reverse digits: ";
    for (int i = (int)s.size() - 1; i >= 0; i--) cout << s[i] << " ";
    cout << "\n";

    cout << "WHILE reverse digits: ";
    int i = (int)s.size() - 1;
    while (i >= 0) { cout << s[i] << " "; i--; }
    cout << "\n";

    cout << "DO-WHILE reverse digits: ";
    int k = (int)s.size() - 1;
    if (k >= 0) {
        do { cout << s[k] << " "; k--; } while (k >= 0);
    }
    cout << "\n";
}


// 11. Делители числа
void task11() {
    long long N;
    cout << "N: ";
    cin >> N;
    if (N <= 0) { cout << "Нужно N > 0\n"; return; }
    cout << "Делители: ";
    for (long long i = 1; i <= N; i++) {
        if (N % i == 0) cout << i << " ";
    }
    cout << "\n";
}

// 12. Простое ли число?
void task12() {
    int N;
    cout << "N: ";
    cin >> N;
    cout << (isPrime(N) ? "Простое\n" : "Не простое\n");
}

// 13. Все простые до N
void task13() {
    int N;
    cout << "N: ";
    cin >> N;
    for (int i = 2; i <= N; i++) {
        if (isPrime(i)) cout << i << " ";
    }
    cout << "\n";
}

// 14. Совершенные числа до N
void task14() {
    int N;
    cout << "N: ";
    cin >> N;
    cout << "Совершенные: ";
    for (int x = 2; x <= N; x++) {
        int sum = 0;
        for (int d = 1; d < x; d++) {
            if (x % d == 0) sum += d;
        }
        if (sum == x) cout << x << " ";
    }
    cout << "\n";
}

// 15. Первые N чисел Фибоначчи
void task15() {
    int N;
    cout << "N: ";
    cin >> N;
    long long a = 0, b = 1;
    for (int i = 0; i < N; i++) {
        cout << a << " ";
        long long c = a + b;
        a = b;
        b = c;
    }
    cout << "\n";
}

// 16. НОД (Евклид)
void task16() {
    long long a, b;
    cout << "a b: ";
    cin >> a >> b;
    cout << "НОД = " << gcdll(a, b) << "\n";
}

// 17. НОК
void task17() {
    long long a, b;
    cout << "a b: ";
    cin >> a >> b;
    if (a == 0 || b == 0) { cout << "НОК = 0\n"; return; }
    long long g = gcdll(a, b);
    cout << "НОК = " << (a / g) * b << "\n";
}

// 18. A^B без pow (B >= 0)
void task18() {
    long long A, B;
    cout << "A B(>=0): ";
    cin >> A >> B;
    if (B < 0) { cout << "Сделаем только B >= 0\n"; return; }
    long long res = 1;
    for (long long i = 0; i < B; i++) res *= A;
    cout << "A^B = " << res << "\n";
}

// 19. Факториал N (обычный)
void task19() {
    long long N;
    cout << "N: ";
    cin >> N;
    if (N < 0) { cout << "N должен быть >= 0\n"; return; }
    unsigned long long f = 1;
    for (long long i = 1; i <= N; i++) f *= (unsigned long long)i;
    cout << "N! = " << f << "\n";
}

// 20. Число Армстронга
void task20() {
    long long N;
    cout << "N: ";
    cin >> N;
    long long x = absll(N);
    string s = to_string(x);
    int k = (int)s.size();

    long long sum = 0;
    for (int i = 0; i < k; i++) {
        int d = s[i] - '0';
        long long p = 1;
        for (int j = 0; j < k; j++) p *= d; // d^k
        sum += p;
    }

    cout << ((sum == x) ? "Армстронг\n" : "Не Армстронг\n");
}


// 21. Прямоугольник MxN из '*'
void task21() {
    int M, N;
    cout << "M N: ";
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) cout << "*";
        cout << "\n";
    }
}

// 22. Пустой прямоугольник
void task22() {
    int M, N;
    cout << "M N: ";
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (i == 0 || i == M - 1 || j == 0 || j == N - 1) cout << "*";
            else cout << " ";
        }
        cout << "\n";
    }
}

// 23. Прямоугольный треугольник
void task23() {
    int H;
    cout << "H: ";
    cin >> H;
    for (int i = 1; i <= H; i++) {
        for (int j = 0; j < i; j++) cout << "*";
        cout << "\n";
    }
}

// 24. Равнобедренный треугольник
void task24() {
    int H;
    cout << "H: ";
    cin >> H;
    for (int i = 1; i <= H; i++) {
        for (int sp = 0; sp < H - i; sp++) cout << " ";
        for (int st = 0; st < 2 * i - 1; st++) cout << "*";
        cout << "\n";
    }
}

// 25. Ромб (по половине высоты)
void task25() {
    int H;
    cout << "H (например 4 => высота 7): ";
    cin >> H;
    if (H <= 0) return;

    for (int i = 1; i <= H; i++) {
        for (int sp = 0; sp < H - i; sp++) cout << " ";
        for (int st = 0; st < 2 * i - 1; st++) cout << "*";
        cout << "\n";
    }
    for (int i = H - 1; i >= 1; i--) {
        for (int sp = 0; sp < H - i; sp++) cout << " ";
        for (int st = 0; st < 2 * i - 1; st++) cout << "*";
        cout << "\n";
    }
}

// 26. Числовая пирамида 1, 22, 333, ...
void task26() {
    int H;
    cout << "H: ";
    cin >> H;
    for (int i = 1; i <= H; i++) {
        for (int j = 0; j < i; j++) cout << i;
        cout << "\n";
    }
}

// 27. Таблица Пифагора 10x10
void task27() {
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            cout << i * j << "\t";
        }
        cout << "\n";
    }
}

// 28. "Змейка" NxN (по строкам туда-сюда)
void task28() {
    int N;
    cout << "N: ";
    cin >> N;
    vector<vector<int>> a(N, vector<int>(N));
    int val = 1;

    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < N; j++) a[i][j] = val++;
        }
        else {
            for (int j = N - 1; j >= 0; j--) a[i][j] = val++;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cout << a[i][j] << "\t";
        cout << "\n";
    }
}

// 29. Игра "Жизнь" Конвея — один шаг (базово)
void task29() {
    int N;
    cout << "N: ";
    cin >> N;

    vector<vector<int>> g(N, vector<int>(N));
    cout << "Ввод поля " << N << "x" << N << " (0/1):\n";
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> g[i][j];

    vector<vector<int>> ng = g;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int cnt = 0;
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx == 0 && dy == 0) continue;
                    int x = i + dx, y = j + dy;
                    if (x >= 0 && x < N && y >= 0 && y < N) {
                        if (g[x][y] == 1) cnt++;
                    }
                }
            }

            if (g[i][j] == 1) {
                if (cnt == 2 || cnt == 3) ng[i][j] = 1;
                else ng[i][j] = 0;
            }
            else {
                if (cnt == 3) ng[i][j] = 1;
                else ng[i][j] = 0;
            }
        }
    }

    cout << "Следующий шаг:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cout << ng[i][j] << " ";
        cout << "\n";
    }
}

// 30. Треугольник Паскаля до N строк
void task30() {
    int N;
    cout << "N: ";
    cin >> N;
    vector<vector<long long>> t(N);

    for (int i = 0; i < N; i++) {
        t[i].resize(i + 1, 1);
        for (int j = 1; j < i; j++) {
            t[i][j] = t[i - 1][j - 1] + t[i - 1][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int sp = 0; sp < N - i - 1; sp++) cout << " ";
        for (int j = 0; j <= i; j++) cout << t[i][j] << " ";
        cout << "\n";
    }
}


// 31. 1 + 1/2 + ... + 1/N
void task31() {
    int N;
    cout << "N: ";
    cin >> N;
    double s = 0;
    for (int i = 1; i <= N; i++) s += 1.0 / i;
    cout << "Sum = " << s << "\n";
}

// 32. 1 - 1/2 + 1/3 - 1/4 + ...
void task32() {
    int N;
    cout << "N: ";
    cin >> N;
    double s = 0;
    for (int i = 1; i <= N; i++) {
        if (i % 2 == 1) s += 1.0 / i;
        else s -= 1.0 / i;
    }
    cout << "Sum = " << s << "\n";
}

// 33. sin(x) по Тейлору (до eps)
void task33() {
    double x, eps;
    cout << "x (радианы): ";
    cin >> x;
    cout << "eps (например 1e-6): ";
    cin >> eps;

    // sin(x)=x - x^3/3! + x^5/5! - ...
    double term = x;
    double sum = 0;
    int k = 1;

    while (fabs(term) > eps) {
        sum += term;
        // следующий член:
        // term = -term * x^2 / ((2k)*(2k+1))
        term = -term * x * x / ((2.0 * k) * (2.0 * k + 1.0));
        k++;
    }

    cout << "Taylor sin = " << sum << "\n";
    cout << "cmath sin  = " << sin(x) << "\n";
}

// 34. π по Лейбницу (N членов)
void task34() {
    int N;
    cout << "N: ";
    cin >> N;
    double s = 0;
    for (int i = 0; i < N; i++) {
        double term = 1.0 / (2 * i + 1);
        if (i % 2 == 0) s += term;
        else s -= term;
    }
    cout << "pi ~= " << 4 * s << "\n";
}

// 35. e^x по Тейлору (N членов)
void task35() {
    double x;
    int N;
    cout << "x: ";
    cin >> x;
    cout << "N (например 20): ";
    cin >> N;

    double sum = 1.0;  // 0-й член
    double term = 1.0; // текущий член x^k/k

    for (int k = 1; k < N; k++) {
        term = term * x / k;
        sum += term;
    }

    cout << "Taylor exp = " << sum << "\n";
    cout << "cmath exp  = " << exp(x) << "\n";
}

// 36. Цепная дробь (простая демонстрация на sqrt(2))
void task36() {
    int N;
    cout << "Глубина N (например 10): ";
    cin >> N;

    // sqrt(2) = 1 + 1/(2 + 1/(2 + 1/(2 + ... )))
    double val = 2.0;
    for (int i = 0; i < N - 1; i++) val = 2.0 + 1.0 / val;
    val = 1.0 + 1.0 / val;

    cout << "Value ~= " << val << "\n";
    cout << "sqrt(2)  = " << sqrt(2.0) << "\n";
}

// 37. Золотое сечение как F(n)/F(n-1)
void task37() {
    int N;
    cout << "N (>=2): ";
    cin >> N;
    if (N < 2) { cout << "Нужно N >= 2\n"; return; }

    long long a = 1, b = 1;
    for (int i = 3; i <= N; i++) {
        long long c = a + b;
        a = b;
        b = c;
    }

    cout << "phi ~= " << (double)b / (double)a << "\n";
}

// 38. Корень уравнения методом половинного деления (пример: x^3-x-2=0)
double f38(double x) {
    return x * x * x - x - 2;
}
void task38() {
    double a, b, eps;
    cout << "a b: ";
    cin >> a >> b;
    cout << "eps: ";
    cin >> eps;

    if (f38(a) * f38(b) > 0) {
        cout << "На [a,b] функция одного знака, выбери другой интервал.\n";
        return;
    }

    while (fabs(b - a) > eps) {
        double m = (a + b) / 2.0;
        if (f38(a) * f38(m) <= 0) b = m;
        else a = m;
    }
    cout << "root ~= " << (a + b) / 2.0 << "\n";
}

// 39. Квадратный корень Ньютона
void task39() {
    double N, eps;
    cout << "N (>=0): ";
    cin >> N;
    cout << "eps: ";
    cin >> eps;
    if (N < 0) { cout << "N должно быть >=0\n"; return; }
    if (N == 0) { cout << "sqrt = 0\n"; return; }

    double x = N;
    while (fabs(x * x - N) > eps) {
        x = 0.5 * (x + N / x);
    }
    cout << "sqrt ~= " << x << "\n";
    cout << "cmath sqrt = " << sqrt(N) << "\n";
}

// 40. Интеграл методом прямоугольников (пример: sin(x) на [a,b])
double f40(double x) { return sin(x); }
void task40() {
    double a, b;
    int N;
    cout << "a b: ";
    cin >> a >> b;
    cout << "N прямоугольников (например 10000): ";
    cin >> N;

    double h = (b - a) / N;
    double s = 0;

    // метод средних прямоугольников
    for (int i = 0; i < N; i++) {
        double x = a + (i + 0.5) * h;
        s += f40(x);
    }

    cout << "Integral ~= " << s * h << "\n";
}


// 41. Сортировка пузырьком
void task41() {
    int N;
    cout << "N: ";
    cin >> N;
    vector<int> a(N);
    cout << "Элементы:\n";
    for (int i = 0; i < N; i++) cin >> a[i];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j + 1 < N - i; j++) {
            if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
        }
    }

    cout << "Sorted: ";
    for (int i = 0; i < N; i++) cout << a[i] << " ";
    cout << "\n";
}

// 42. Сортировка вставками
void task42() {
    int N;
    cout << "N: ";
    cin >> N;
    vector<int> a(N);
    cout << "Элементы:\n";
    for (int i = 0; i < N; i++) cin >> a[i];

    for (int i = 1; i < N; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }

    cout << "Sorted: ";
    for (int i = 0; i < N; i++) cout << a[i] << " ";
    cout << "\n";
}

// 43. Бинарный поиск (в уже отсортированном массиве)
void task43() {
    int N;
    cout << "N: ";
    cin >> N;
    vector<int> a(N);
    cout << "Вводи отсортированный массив:\n";
    for (int i = 0; i < N; i++) cin >> a[i];

    int x;
    cout << "Ищем x: ";
    cin >> x;

    int l = 0, r = N - 1;
    int pos = -1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m] == x) { pos = m; break; }
        if (a[m] < x) l = m + 1;
        else r = m - 1;
    }

    if (pos == -1) cout << "Не найдено\n";
    else cout << "Найдено на индексе (0-based) = " << pos << "\n";
}

// 44. Решето Эратосфена (простые до N)
void task44() {
    int N;
    cout << "N: ";
    cin >> N;
    if (N < 2) { cout << "Нет простых\n"; return; }

    vector<bool> prime(N + 1, true);
    prime[0] = prime[1] = false;

    for (int p = 2; p * 1LL * p <= N; p++) {
        if (prime[p]) {
            for (int k = p * p; k <= N; k += p) prime[k] = false;
        }
    }

    for (int i = 2; i <= N; i++) if (prime[i]) cout << i << " ";
    cout << "\n";
}

// 45. Разложение на простые множители
void task45() {
    long long N;
    cout << "N (>1): ";
    cin >> N;
    if (N <= 1) { cout << "N должно быть > 1\n"; return; }

    cout << "Factors: ";
    for (long long p = 2; p * p <= N; p++) {
        while (N % p == 0) {
            cout << p << " ";
            N /= p;
        }
    }
    if (N > 1) cout << N;
    cout << "\n";
}

// 46. Палиндромы в диапазоне [a,b]
bool isPal(long long x) {
    if (x < 0) return false;
    long long orig = x, rev = 0;
    while (x > 0) {
        rev = rev * 10 + x % 10;
        x /= 10;
    }
    return orig == rev;
}
void task46() {
    long long a, b;
    cout << "a b: ";
    cin >> a >> b;
    if (a > b) swap(a, b);

    cout << "Palindromes: ";
    for (long long x = a; x <= b; x++) {
        if (isPal(x)) cout << x << " ";
        if (x == b) break; // защита от переполнения
    }
    cout << "\n";
}

// 47. Римские цифры (число <-> римское)
string toRoman(int num) {
    if (num <= 0 || num > 3999) return "N/A";
    int val[] = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
    string sym[] = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };

    string res = "";
    for (int i = 0; i < 13; i++) {
        while (num >= val[i]) {
            res += sym[i];
            num -= val[i];
        }
    }
    return res;
}
int fromRoman(string s) {
    auto v = [&](char c)->int {
        if (c == 'I') return 1;
        if (c == 'V') return 5;
        if (c == 'X') return 10;
        if (c == 'L') return 50;
        if (c == 'C') return 100;
        if (c == 'D') return 500;
        if (c == 'M') return 1000;
        return 0;
        };
    int sum = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        int cur = v(s[i]);
        int nxt = (i + 1 < (int)s.size()) ? v(s[i + 1]) : 0;
        if (cur < nxt) sum -= cur;
        else sum += cur;
    }
    return sum;
}
void task47() {
    int mode;
    cout << "1) число->римское  2) римское->число: ";
    cin >> mode;
    if (mode == 1) {
        int n;
        cout << "n (1..3999): ";
        cin >> n;
        cout << toRoman(n) << "\n";
    }
    else {
        string s;
        cout << "Римское (пример XIV): ";
        cin >> s;
        for (char& c : s) c = (char)toupper((unsigned char)c);
        cout << fromRoman(s) << "\n";
    }
}

// 48. Длинная арифметика: сложение больших чисел (строками)
void task48() {
    string a, b;
    cout << "A: ";
    cin >> a;
    cout << "B: ";
    cin >> b;

    // чтобы удобнее, делаем a самой длинной
    if (a.size() < b.size()) swap(a, b);

    int i = (int)a.size() - 1;
    int j = (int)b.size() - 1;
    int carry = 0;
    string res = "";

    while (i >= 0 || j >= 0 || carry) {
        int x = (i >= 0) ? (a[i] - '0') : 0;
        int y = (j >= 0) ? (b[j] - '0') : 0;
        int s = x + y + carry;
        carry = s / 10;
        res.push_back(char('0' + (s % 10)));
        i--; j--;
    }
    reverse(res.begin(), res.end());

    cout << "A+B = " << res << "\n";
}

// 49. Баланс скобок ((), {}, [])
void task49() {
    string s;
    cout << "Строка со скобками: ";
    cin >> s;

    vector<char> st;
    for (int i = 0; i < (int)s.size(); i++) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            st.push_back(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (st.empty()) { cout << "Не сбалансировано\n"; return; }
            char top = st.back();
            st.pop_back();
            if (!((top == '(' && c == ')') || (top == '{' && c == '}') || (top == '[' && c == ']'))) {
                cout << "Не сбалансировано\n";
                return;
            }
        }
    }
    cout << (st.empty() ? "Сбалансировано\n" : "Не сбалансировано\n");
}

// 50. Генерация случайных паролей
void task50() {
    srand((unsigned)time(nullptr));  // инициализация генератора

    int len, count;
    cout << "Длина пароля: ";
    cin >> len;
    cout << "Сколько паролей сгенерировать: ";
    cin >> count;

    if (len <= 0 || count <= 0) {
        cout << "Длина и количество должны быть > 0\n";
        return;
    }

    string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    for (int k = 0; k < count; k++) {

        string password = "";

        for (int i = 0; i < len; i++) {
            int index = rand() % chars.size();
            password += chars[index];
        }

        cout << password << endl;
    }
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    cout << "Выбери задачу 1-50 (0-выход)\n";

    while (true) {
        int t;
        cout << "\nНомер задачи: ";
        cin >> t;

        if (t == 0) break;

        switch (t) {
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        case 4: task4(); break;
        case 5: task5(); break;
        case 6: task6(); break;
        case 7: task7(); break;
        case 8: task8(); break;
        case 9: task9(); break;
        case 10: task10(); break;

        case 11: task11(); break;
        case 12: task12(); break;
        case 13: task13(); break;
        case 14: task14(); break;
        case 15: task15(); break;
        case 16: task16(); break;
        case 17: task17(); break;
        case 18: task18(); break;
        case 19: task19(); break;
        case 20: task20(); break;

        case 21: task21(); break;
        case 22: task22(); break;
        case 23: task23(); break;
        case 24: task24(); break;
        case 25: task25(); break;
        case 26: task26(); break;
        case 27: task27(); break;
        case 28: task28(); break;
        case 29: task29(); break;
        case 30: task30(); break;

        case 31: task31(); break;
        case 32: task32(); break;
        case 33: task33(); break;
        case 34: task34(); break;
        case 35: task35(); break;
        case 36: task36(); break;
        case 37: task37(); break;
        case 38: task38(); break;
        case 39: task39(); break;
        case 40: task40(); break;

        case 41: task41(); break;
        case 42: task42(); break;
        case 43: task43(); break;
        case 44: task44(); break;
        case 45: task45(); break;
        case 46: task46(); break;
        case 47: task47(); break;
        case 48: task48(); break;
        case 49: task49(); break;
        case 50: task50(); break;

        default:
            cout << "Нет такой задачи.\n";
        }
    }

    cout << "Готово.\n";
    return 0;
}
