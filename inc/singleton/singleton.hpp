#ifndef _SINGLETON_SINGLETON_HPP_
#define _SINGLETON_SINGLETON_HPP_

#include <iostream>
#include <memory>
#include <mutex>
#include <stdexcept>
#include <type_traits>


template <typename T>
class Singleton
{
    public:
        class ThreadSafe
        {
            public:
                ThreadSafe(Singleton<T> &settings, bool interrupt);


                T& create_instance()
                {
                    if(!safe.instance_ptr)
                    {
                        safe.instance_ptr = std::make_unique<T>();
                        std::cout << "\nESTIVE AQUI 01\n";
                    }

                    return *safe.instance_ptr;   
                }

                T& get_content();

            private:
                Singleton<T> &safe;
                friend class Singleton<T>;

        };

        static ThreadSafe get_safe(bool interrupt = false);
        static T& get_content();


    private:
        static Singleton<T>& instance()
        {
            static Singleton<T> instance;
            return instance;
        }
        std::mutex mutex;
        std::unique_ptr<T> instance_ptr = nullptr;

        Singleton() = default;
        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;
        ~Singleton() { mutex.unlock(); }
};

template <typename T>
typename Singleton<T>::ThreadSafe Singleton<T>::get_safe(bool interrupt)
{
    std::cout << "\nESTIVE AQUI 05\n";
    return ThreadSafe(Singleton<T>::instance(), interrupt);
}

template <typename T>
T& Singleton<T>::get_content()
{
    std::cout << "\nESTIVE AQUI 03\n";
    return get_safe().get_content();
}

template <typename T>
Singleton<T>::ThreadSafe::ThreadSafe(Singleton<T> &settings, bool interrupt) :
    safe(settings)
    // keep_mutex(false)
{
    std::cout << "\nESTIVE AQUI 02 A\n";
    safe.mutex.lock();
    std::cout << "\nESTIVE AQUI 02 B\n";
}

template <typename T>
T& Singleton<T>::ThreadSafe::get_content()
{
    std::cout << "\nESTIVE AQUI 04\n";
    return create_instance();
}


// template<typename T>
// class Singleton
// {
// public:
//     template<typename... Args>
//     static T& get_content(Args&&... args)
//     {
       
//         std::lock_guard<std::mutex> lock(m_mtx);
//         if (!instance_ptr)
//         {
//             std::cout << "ESTIVE AQUI \n";
//             if constexpr (sizeof...(Args) == 0)
//             {
//                 std::cout << "ESTIVE AQUI I\n";
//                 static_assert(std::is_default_constructible<T>::value, "Tipo T não possui construtor padrão e nenhum argumento foi fornecido.");
//                 instance_ptr = std::make_unique<T>();
//             }
//             else
//             {
//                 std::cout << "ESTIVE AQUI III \n";
//                 instance_ptr = std::make_unique<T>(std::forward<Args>(args)...);
//             }
//         }
//         else if constexpr (sizeof...(Args) > 0)
//         {
//             throw std::runtime_error("Singleton já foi inicializado — não pode ser reinicializado.");
//         }

//         return *instance_ptr;
//     }

//     static T& get()
//     {
//         // std::lock_guard<std::mutex> lock(m_mtx);
//         if (!instance_ptr)
//             throw std::runtime_error("Singleton ainda não foi inicializado.");
//         return *instance_ptr;
//     }

//     Singleton() = delete;
//     ~Singleton() = delete;
//     Singleton(const Singleton&) = delete;
//     Singleton& operator=(const Singleton&) = delete;

// private:
//     static std::unique_ptr<T> instance_ptr;
//     static std::mutex m_mtx;
// };

// template<typename T>
// std::unique_ptr<T> Singleton<T>::instance_ptr = nullptr;

// template<typename T>
// std::mutex Singleton<T>::m_mtx;



// template <typename T>
// class Singleton
// {
//     public:

//         static Singleton& create_instance()
//         {
//             std::lock_guard<std::mutex> lock(m_mtx);
//             static Singleton instance;
//             return instance;
//         }

//         static Singleton& create_instance(T& sgl)
//         {
//             std::lock_guard<std::mutex> lock(m_mtx);
//             static Singleton instance = sgl;
//             return instance;
//         }

//         void set(T value_template){
//             this->value_template = value_template;
//         }

//         T& get_content(){
//             return value_template;
//         }

//         void set_msg(std::string msg)
//         {
//             this->msg = msg;
//         }

//         std::string get_msg()
//         {
//             return msg;
//         }

//         // class ThreadSafe {
// 		// friend class Singleton<T>;
//         //     private:
//         //         Singleton<T> &safe;
//         //         bool keep_locked;

//         //     public:
//         //         ThreadSafe(Singleton<T> &settings);
//         //         ~ThreadSafe();

//         //         /**
//         //         * @brief Retorna uma referência para a instância do conteúdo do singleton
//         //         * @see Singleton<T>::get_content();
//         //         */
//         //         T& get_content();
//         // };
        

//     private:
//         // Singleton() = delete;
// 	    Singleton(const Singleton&) = delete;

//         Singleton()
//         {
//             std::cout << "Created Singleton\n";
//         }

//         // Singleton(T value_template) : T (value_template)
//         // {
//         //     std::cout << "Created Singleton\n";
           
//         // }

//         ~Singleton(){
//             std::cout << "Destroyed Singleton\n";
            
//         }
//         std::string msg;
//         T value_template;
//         static std::mutex m_mtx;

//         // struct Acess_permission{};
// 	    // std::thread::id current_thread_id;
        
// };
// template <typename T>
// std::mutex Singleton<T>::m_mtx;


// // template<typename T>
// // Singleton<T>::ThreadSafe::ThreadSafe(Singleton<T> &settings):
// // 	safe(settings),
// // 	keep_locked(false)
// // {
// // 	if (std::this_thread::get_id() != safe.current_thread_id){
// // 		if (false){
// // 			if (!safe.mutex.try_lock()){
// // 				//throw error::Singleton();
// // 			}
// // 		} else
// // 			safe.mutex.lock();
// // 	}
// // 	safe.current_thread_id = std::this_thread::get_id();
// // }

// // template <typename T>
// // T& Singleton<T>::ThreadSafe::get_content(){
// //     std::lock_guard<std::mutex> lock(m_mtx);
// //     //static Singleton instance;
// //     return safe.value_template;

// // }



#endif