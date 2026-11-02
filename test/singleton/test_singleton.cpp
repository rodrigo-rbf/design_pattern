#include <vector>
#include <csignal>
#include <iostream>
#include <thread>
#include <chrono>
#include <time.h>
#include<unistd.h>


#include "singleton/singleton.hpp"

int main()
{}

/*
volatile std::sig_atomic_t done = 0;

struct Test {
 double d;
 std::string msg;
};

void loop_thread_1()
{
    auto& sgl = Singleton<Test>::create_instance();
    while(!done){
        if (sgl.msg == "loop_thread_2")
        {
            sgl.d = 0.55;
            sgl.msg = "loop_thread_1";
        }
       sleep(4);
    }
}

void loop_thread_2()
{
    auto& sgl = Singleton<Test>::create_instance();
    while(!done){
        if (sgl.msg == "loop_thread_1")
        {
            sgl.d = 0.1978;
            sgl.msg = "loop_thread_2";
        }
    sleep(4);
    }
}

int main()
{    
    std::thread loop_1(loop_thread_1);
    sleep(2);
    std::thread loop_2(loop_thread_2);

    auto& sgl_main = Singleton<Test>::create_instance();
    sgl_main.msg = "loop_thread_2";
    sgl_main.d = 1978.4;

    for(int i = 0; i< 5; ++i)
    {
        std::cout << i << ": " << sgl_main.msg << " : " << sgl_main.d << '\n';
        sleep(2);
    }

    sleep(2);
    done = true;

    if (loop_1.joinable()) {
        loop_1.join(); 
    }

    if (loop_2.joinable()) {
        loop_2.join();
    }

    return 0;
}
*/