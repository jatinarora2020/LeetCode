/* TOPIC: Different Types Of Thread Creation And Calling.
There are 5 different types of creating threads and calling callable in threads.

NOTES: Different types for creating threads.
1. Function Pointer -- this is the very basic form of creating threads.
2. Lambda Function
3. Functor (Function Object)
4. Non-static member function
5. Static member function */




/* TOPIC: Use Of join(), detach() and joinable() In Thread In C++ (C++11)

JOIN NOTES
0. Once a thread is started we wait for this thread to finish by calling join() function on thread object.
1. Double join will result into program termination.
2. If needed we should check thread is joinable before joining. ( using joinable() function)


DETACH NOTES
0. This is used to detach newly created thread from the parent thread.
1. Always check before detaching a thread that it is joinable otherwise we may end up double detaching and 
   double detach() will result into program termination.
2. If we have detached thread and main function is returning then the detached thread execution is suspended.

NOTES:
Either join() or detach() should be called on thread object, otherwise during thread object�s destructor it will  
terminate the program. Because inside destructor it checks if thread is still joinable? if yes then it terminates the program. */

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
using namespace std::chrono;

/* void fun(int x) {    //Function pointer
    while(x--)
    cout<<x<<endl;
} */

class Base  //Functor
{
public :
 void operator()(int x){
    while(x--)
    cout<<x<<endl;
 }
  void run(int x)
  {
      while(x--)
      cout<<x<<endl;
  }
 void static run2(int x)
 {
     while(x--)
     cout<<x<<endl;
 }
};

int main()
{
  /*   auto fun = [](int x) {
      while(x--)
      cout<<x<<endl;  
    }; */
    /* std::thread t1(Base(), 10); //Functors */
    Base b;
   /*  std::thread t1(&Base::run, &b,10); */ // Non Static Member functions 
    std::thread t1(&Base::run2,10); //Static Member functions
   
    t1.join();
    return 0;
}
