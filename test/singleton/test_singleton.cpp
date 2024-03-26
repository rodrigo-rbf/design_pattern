#include <vector>
#include <csignal>
#include <iostream>
#include <thread>
#include <chrono>
#include <time.h>
#include<unistd.h>


#include "singleton/singleton.hpp"

volatile std::sig_atomic_t done = 0;

void loop_thread_1()
{
    while(!done){
        auto& sgl = Singleton<double>::create_instance();
        if (sgl.get_msg() == "loop_thread_2")
        {
            sgl.set_msg("loop_thread_1");
        }
       sleep(4);
    }
}

void loop_thread_2()
{
    while(!done){
        auto& sgl = Singleton<double>::create_instance();
        if (sgl.get_msg() == "loop_thread_1")
        {
            sgl.set_msg("loop_thread_2");
        }
       sleep(4);
    }
}

int main()
{
    
    std::thread loop_1(loop_thread_1);
    sleep(2);
    std::thread loop_2(loop_thread_2);

    auto& sgl_main = Singleton<double>::create_instance();
    sgl_main.set_msg("loop_thread_2");

    for(int i = 0; i< 5; ++i)
    {
        std::cout << i << ": " << sgl_main.get_msg() << '\n';
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