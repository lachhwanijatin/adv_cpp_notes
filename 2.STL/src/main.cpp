#include <iostream>
#include <vector>
#include <algorithm>
#include <algorithm>


/*
4 core categories of things STL provides:
-> Containers
-> algorithms
-> iterators
-> functors

// discussion on STL containers
vector - dynamic array
list -> dll 
set, map -> self balancing bst (unique key), O(logn for operations) (cache miss quite common)
multiset and multimap -> (not unique key) everything else same as set and map

unordered_set/map -> hasmap -> worst case (O(n)) avg case (O(1)) (unique keys)
unordered_multiset/map ->  (non unique keys possible)

container adaptors:
std::queue, std::stack, std::priority_queue

// algorithms
std::sort
sort(startiter, enditer, greater<int>)

auto it = find(b,e,element);
if(it!=end) {// found}
std::binary_search
std::reverse()

std::accumulate(bi,ei,start_value); // the main value lies in using your own function as argument and customizing it
std::count
std::unique
std::remove, std::remove_if // interesting optimization used here
std::transform

*/
int main()
{
    /*
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    pq.push(4);
    pq.push(9);
    pq.push(12);
    pq.push(3);
    pq.push(6);

    while (!pq.empty()){
        std::cout<<pq.top()<<std::endl;
        pq.pop();
    }
    */

    std::vector<int> v;
    v.reserve(9);
    v.push_back(2);
    v.push_back(3);
    v.push_back(3);
    v.push_back(3);
    v.push_back(3);
    v.push_back(4);
    v.push_back(4);
    v.push_back(4);
    v.push_back(4);

    std::cout<<v.capacity()<<std::endl;

    // v.erase(std::remove(v.begin(),v.end(),3), v.end());
    // v.erase(std::remove_if(v.begin(), v.end(),[](int x)-> bool {return x>2;}), v.end());

    std::transform(v.begin(), v.end(), v.begin(), [&v](int x){
        return x*2;
    });
    for(auto &element: v)
    {
        std::cout<<element<<std::endl;
    }
}