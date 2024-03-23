#ifndef _SINGLETON_SINGLETON_HPP_
#define _SINGLETON_SINGLETON_HPP_

#include <iostream>
#include <string>
#include <thread>
#include <mutex>

template <typename T>
class Singleton
{
    public:

        static Singleton& create_instance()
        {
            std::lock_guard<std::mutex> lock(m_mtx);
            static Singleton instance;
            return instance;
        }

        void set_msg(std::string msg)
        {
            this->msg = msg;
        }

        std::string get_msg()
        {
            return msg;
        }
        

    private:
        Singleton()
        {
            std::cout << "Created Singleton\n";
        }
        ~Singleton(){
            std::cout << "Destroyed Singleton\n";
        }
        std::string msg;
        static std::mutex m_mtx;
        
};
template <typename T>
std::mutex Singleton<T>::m_mtx;




#endif