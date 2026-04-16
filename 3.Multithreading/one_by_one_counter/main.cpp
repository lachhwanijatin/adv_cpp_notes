#include <condition_variable>
#include <thread>
#include <vector>
#include <iostream>
#include <chrono>
#include <mutex>
using namespace std;

void function(int thread_id , int &start_number ,std::mutex &mtx, std::vector<bool> &turn, condition_variable &cv, int end_number){
    while(true){
        std::unique_lock<mutex> lock(mtx);
        cv.wait(lock, [&turn,&thread_id](){return turn[thread_id]==true;});
        if(start_number == end_number)
        {
            turn[(thread_id+1)%turn.size()] = true;
            lock.unlock();
            cv.notify_all();
            break;
        }
        std::cout<<"thread id:"<<thread_id<<" count:"<<start_number<<std::endl;
        start_number++;
        turn[thread_id] = false;
        turn[(thread_id+1)%turn.size()] = true;
        lock.unlock();
        cv.notify_all();
    }
}
int main() {
    int num_threads = 4;
    std::mutex mtx;
    std::vector<std::thread> threads;
    std::vector<bool> turn(num_threads,0);
    turn[0] = true;
    condition_variable cv;
    threads.reserve(num_threads);
    int start=0;
    for (int i=0; i<num_threads;i++)
    {
        threads.emplace_back(function,i, std::ref(start),std::ref(mtx), std::ref(turn), std::ref(cv), 100);
    }
    for(auto &th: threads) th.join();
}