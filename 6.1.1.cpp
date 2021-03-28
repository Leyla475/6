#include <iostream> 
#include <random>



int main() {

    float in_circle = 0.0;
    int n;

    std::random_device rd;

    std::cout << "enter the number of points: ";
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x = rd() % n; // делим длину стороны квадратика на n одинаковых частей и смотрим, в какой мини-квадратик попадет точка
        int y = rd() % n;
        if (x * x + y * y <= n * n) {

            in_circle++;
        }
    }

    std::cout << "the value of pi: " << 4.0 * in_circle / float(n) << std::endl;

    return 0;
}