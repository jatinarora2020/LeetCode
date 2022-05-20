/* TOPIC: Mutex In C++ Threading | Why Use Mutex | What Is Race Condition And How To Solve It? | What Is Critical Section

Mutex: Mutual Exclusion

RACE CONDITION:
0. Race condition is a situation where two or more threads/process happens to change a common data at the same time.
1. If there is a race condition then we have to protect it and the protected section is  called critical section/region.

MUTEX:
0. Mutex is used to avoid race condition.
1. We use lock() , unlock() on mutex to avoid race condition. */


/* TOPIC: std::mutex::try_lock() On Mutex In C++11 Threading

0. try_lock() Tries to lock the mutex. Returns immediately. On successful lock acquisition returns true otherwise returns false.
1. If try_lock() is not able to lock mutex, then it doesn't get blocked that's why it is called non-blocking.
2. If try_lock is called again by the same thread which owns the mutex, the behavior is undefined.
   It is a dead lock situation with undefined behavior. (if you want to be able to lock the same mutex by same thread more than one time the go for recursive_mutex)

There are so many try_lock function
1. std::try_lock
2. std::mutex::try_lock
3. std::shared_lock::try_lock
4. std::timed_mutex::try_lock
5. std::unique_lock::try_lock
6. std::shared_mutex::try_lock
7. std::recursive_mutex::try_lock
8. std::shared_timed_mutex::try_lock
9. std::recursive_timed_mutex::try_lock
 */
#include<iostream>
#include <thread>
#include <mutex>
using namespace std;
std::mutex m;

int data;
void IncrData()
{
    m.lock();
    data++;
    m.unlock();
}

int main()
{
    std::thread t1(IncrData);
    std::thread t2(IncrData);

    t1.join();
    t2.join();
    cout<<data;
    return 0;

}