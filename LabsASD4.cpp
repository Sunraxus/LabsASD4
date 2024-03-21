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
    return accumulate(times.begin(), times.end(), 0.0) / num_attempts;
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

int main()
{
    setlocale(LC_ALL, "RUS");
    //calc();
    Tree tree;

    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    cout << "Дерево: ";
    tree.print(); 

    cout << "Содержит 4? " << (tree.contains(4) ? "Да" : "Нет") << endl;
    cout << "Содержит 9? " << (tree.contains(9) ? "Да" : "Нет") << endl; 

    cout << "Минимальное значение в дереве: " << tree.min() << endl; 

    tree.erase(11);
    tree.insert(8);

    cout << "Дерево после удаления: ";
    tree.print();

    tree.clear();

    std::cout << "Дерево пустое? " << (tree.to_vector().empty() ? "Да" : "Нет") << std::endl;

    vector<int> vec = { 1, 2, 3, 2, 4, 5, 3, 6, 7, 8, 8, 9 };
    vector<int> duplicates = DuplicatesVector(vec);

    cout << "Duplicates: ";
    for (int value : duplicates) {
        cout << value << " ";
    }
    cout << endl;

	return 0;
}
