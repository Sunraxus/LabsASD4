#include "LabsASD4.h"
#include <chrono>
#include <ctime>
#include <iostream>
#include <random>
#include <numeric> 


using namespace std;

/*template<typename Func>
double measure_time(Func func) {
    auto start = chrono::steady_clock::now();
    func();
    auto end = chrono::steady_clock::now();
    return chrono::duration<double>(end - start).count();
}

void fill_tree(Tree& tree, size_t num_elements) {
    for (size_t i = 0; i < num_elements; ++i) {
        int value = lcg() % (num_elements * 10) + 1;
        while (!tree.insert(value)) {
            value = lcg() % (num_elements * 10) + 1;
        }
    }
}

bool search_tree(Tree& tree, size_t num_elements) {
    int value = lcg() % (num_elements * 10) + 1;
    return tree.contains(value);
}

void add_and_remove_random(Tree& tree, size_t num_elements) {
    int value = lcg() % (num_elements * 10) + 1;
    tree.insert(value);

    value = lcg() % (num_elements * 10) + 1;
    tree.erase(value);
}

template<typename Func>
double average_time(Func func, size_t num_attempts) {
    vector<double> times;
    times.reserve(num_attempts);
    for (size_t i = 0; i < num_attempts; ++i) {
        double time = measure_time(func);
        times.push_back(time);
    }
    return std::accumulate(times.begin(), times.end(), 0.0) / num_attempts;
}

void calc() {
    const size_t num_attempts = 100;
    const size_t num_elements[] = { 1000, 10000, 100000 };

    for (size_t num : num_elements) {
        double fill_time = average_time([&]() {
            Tree tree;
        fill_tree(tree, num);
            }, num_attempts);
        cout << "Average fill time for " << num << " elements: " << fill_time << " sec" << endl;

        double search_time = average_time([&]() {
            Tree tree;
        fill_tree(tree, num);
        search_tree(tree, num);
            }, num_attempts * 10);
        cout << "Average search time for " << num << " elements: " << search_time << " sec" << endl;

        double add_remove_time = average_time([&]() {
            Tree tree;
        fill_tree(tree, num);
        add_and_remove_random(tree, num);
            }, num_attempts * 10);
        cout << "Average add and remove time for " << num << " elements: " << add_remove_time << " sec" << endl;
    }
}

template<typename Func>
double measure_time(Func func) {
    auto start = chrono::steady_clock::now();
    func();
    auto end = chrono::steady_clock::now();
    return chrono::duration<double>(end - start).count();
}

void fill_vector(vector<int>& vec, size_t num_elements) {
    for (size_t i = 0; i < num_elements; ++i) {
        int value = lcg() % (num_elements * 10) + 1;
        while (find(vec.begin(), vec.end(), value) != vec.end()) {
            value = lcg() % (num_elements * 10) + 1;
        }
        vec.push_back(value);
    }
}

bool search_vector(const std::vector<int>& vec, size_t num_elements) {
    int value = lcg() % (num_elements * 10) + 1;
    return std::find(vec.begin(), vec.end(), value) != vec.end();
}

void add_and_remove_random(vector<int>& vec, size_t num_elements) {
    int value = lcg() % (num_elements * 10) + 1;
    vec.push_back(value);

    value = lcg() % (num_elements * 10) + 1;
    vec.erase(remove(vec.begin(), vec.end(), value), vec.end());
}

template<typename Func>
double average_time(Func func, size_t num_attempts) {
    vector<double> times;
    times.reserve(num_attempts);
    for (size_t i = 0; i < num_attempts; ++i) {
        double time = measure_time(func);
        times.push_back(time);
    }
    return accumulate(times.begin(), times.end(), 0.0) / num_attempts;
}

void calc() {
    const size_t num_attempts = 100;
    const size_t num_elements[] = { 1000, 10000, 100000 };

    for (size_t num : num_elements) {
        double fill_time = average_time([&]() {
            vector<int> vec;
        fill_vector(vec, num);
            }, num_attempts);
        cout << "Average fill time for " << num << " elements: " << fill_time << " sec" << endl;

        double search_time = average_time([&]() {
            vector<int> vec;
        fill_vector(vec, num);
        search_vector(vec, num);
            }, num_attempts * 10);
        cout << "Average search time for " << num << " elements: " << search_time << " sec" << endl;

        double add_remove_time = average_time([&]() {
            vector<int> vec;
        fill_vector(vec, num);
        add_and_remove_random(vec, num);
            }, num_attempts * 10);
        cout << "Average add and remove time for " << num << " elements: " << add_remove_time << " sec" << endl;
    }
}*/

#define time \
  duration_cast<microseconds>(system_clock::now().time_since_epoch()).count()

using namespace std;
using std::cout;
using std::endl;
using std::chrono::duration_cast;
using std::chrono::microseconds;
using std::chrono::seconds;
using std::chrono::system_clock;

int getRandomValue(int limit) { return rand() % limit; }

double getMeanCreateTimeTree(int limit, double& insert_time, double& search_time,
    double& delete_time) {
    srand(0);
    size_t mean_time = 0;
    for (int i = 0; i < 100; ++i) {
        cout << i << " ";

        size_t time_create_1 = time;
        Tree set;
        for (int j = 0; j < limit; ++j) {
            set.insert(getRandomValue(limit * 3));
        }
        size_t time_create_2 = time;
        int value = getRandomValue(limit * 2);

        size_t time_insert_1 = time;
        set.insert(value);
        size_t time_insert_2 = time;

        size_t time_search_1 = time;
        set.contains(value);
        size_t time_search_2 = time;

        size_t time_delete_1 = time;
        set.erase(value);
        size_t time_delete_2 = time;

        mean_time += (time_create_2 - time_create_1);
        insert_time += (time_insert_2 - time_insert_1);
        search_time += (time_search_2 - time_search_1);
        delete_time += (time_delete_2 - time_delete_1);
    }
    insert_time /= double(100.0);
    search_time /= double(100.0);
    delete_time /= double(100.0);
    return (double(mean_time) / 100);
}

double getMeanCreateTimeVector(int limit, double& insert_time, double& search_time,
    double& delete_time) {
    srand(0);
    size_t mean_time = 0;
    for (int i = 0; i < 100; ++i) {
        cout << i << " ";

        size_t time_create_1 = time;
        vector<int> vec;
        vec.reserve(limit);

        for (int j = 0; j < limit; ++j) {
            vec.push_back(getRandomValue(limit * 3));
        }

        size_t time_create_2 = time;
        int value = getRandomValue(limit * 2);
        size_t time_insert_1 = time;
        vec.push_back(value);
        size_t time_insert_2 = time;

        size_t time_search_1 = time;
        auto it = std::find(vec.begin(), vec.end(), value);
        size_t time_search_2 = time;

        size_t time_delete_1 = time;
        if (it != vec.end())
            vec.erase(it);
        size_t time_delete_2 = time;

        mean_time += (time_create_2 - time_create_1);
        insert_time += (time_insert_2 - time_insert_1);
        search_time += (time_search_2 - time_search_1);
        delete_time += (time_delete_2 - time_delete_1);
    }
    insert_time /= double(100.0);
    search_time /= double(100.0);
    delete_time /= double(100.0);
    return (double(mean_time) / 100);
}

int main()
{
    setlocale(LC_ALL, "RUS");
    double insert_time = 0, search_time = 0, delete_time = 0;
    cout << getMeanCreateTimeTree(100000, insert_time, search_time, delete_time);
    cout << "\n"
        << "insert_time: " << insert_time << endl
        << "search_time: " << search_time << endl
        << "delete_time: " << delete_time << endl;
    //calc();
    /*Tree tree;

    // Вставка элементов в дерево
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    // Вывод содержимого дерева
    std::cout << "Дерево: ";
    tree.print(); // Ожидаемый вывод: 5 3 2 4 7 6 8

    // Проверка метода contains
    std::cout << "Содержит 4? " << (tree.contains(4) ? "Да" : "Нет") << std::endl; // Ожидаемый вывод: Да
    std::cout << "Содержит 9? " << (tree.contains(9) ? "Да" : "Нет") << std::endl; // Ожидаемый вывод: Нет

    // Вывод минимального значения в дереве
    std::cout << "Минимальное значение в дереве: " << tree.min() << std::endl; // Ожидаемый вывод: 2

    // Удаление элемента из дерева
    tree.erase(11);
    tree.insert(8);

    // Вывод содержимого дерева после удаления элемента
    std::cout << "Дерево после удаления: ";
    tree.print(); // Ожидаемый вывод: 5 4 2 7 6 8

    // Очистка дерева
    tree.clear();

    // Проверка, пустое ли дерево
    std::cout << "Дерево пустое? " << (tree.to_vector().empty() ? "Да" : "Нет") << std::endl; // Ожидаемый вывод: Да*/

	return 0;
}
