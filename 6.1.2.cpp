#include <iostream>
#include <thread>
#include <random>
#include <future>


void counting_points(int& in_circle, int n) {

    std::random_device rd;
    int x = rd() % n; //делим длину стороны квадратика на n одинаковых частей и смотрим, в какой мини-квадратик попадет точка
    int y = rd() % n;
    if (x * x + y * y <= n * n) {
        in_circle++;
    }
}
int main() {

    int in_circle = 0;
    int n;


    std::cout << "enter the number of points: ";
    std::cin >> n;

    std::vector <std::thread> threads;
    for (int i = 0; i < n; i++)
    {
        threads.push_back(std::thread(counting_points, std::ref(in_circle), n));
    }


    for (int i = 0; i < n; i++)
    {
        threads[i].join();
    }

    std::cout << "the value of pi: " << 4.0 * float(in_circle) / float(n) << std::endl;

    return 0;
}
