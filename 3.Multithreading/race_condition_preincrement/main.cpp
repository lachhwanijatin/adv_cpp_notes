#include <mutex>
#include <thread>
#include <iostream>
using namespace std;

// Helper function to print a matrix cleanly

int shared_variable=0;
std::mutex mtx;
void preincrement(int n){
    for(int i=0; i<n; i++)
    {
        // std::unique_lock<std::mutex> ul(mtx);
        ++shared_variable;
    }
}
int main() {
    thread t1(preincrement, 100000), t2(preincrement, 100000);
    t1.join();
    t2.join();

    std::cout<<shared_variable<<std::endl;
}