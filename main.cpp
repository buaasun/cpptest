#include <iostream>
#include <thread>
#include <atomic>
#include <vector>
class Variable {
public:
    Variable() = delete;
    explicit Variable(int val) : val(val) {
        std::cout << "I am constructed #" << count << std::endl;
        ++count;
    }
    Variable(const Variable &) = delete;
    Variable(Variable &&) = delete;
    int val{1};
    long ptr{(long) &val};
    static std::atomic_int count;
};
std::atomic_int Variable::count{0};
//  thread_local Variable global(3);
void thread_local_test() {
    thread_local static Variable global(3);
    int num_threads = 2;
    std::vector<std::thread> threads;
    std::cout << std::hex << global.ptr << std::endl;
    for (int i = 0; i < num_threads; ++i) {
        auto func = [&global]() -> void { std::cout << std::hex << global.ptr << std::endl; };
        threads.push_back(std::thread(func));
    }
    for (auto &thread : threads) thread.join();
}

int main() {
    std::cout << "Hello, World!++" << std::endl;

    thread_local_test();
    return 0;
}