#include <vector>

#include "singleton/singleton.hpp"

int main()
{

    std::vector<std::thread> threads;

    for(int i = 0; i< 10; ++i)
    {
        threads.emplace_back(std::thread([](){
            auto& sgl = Singleton<double>::create_instance();
            sgl.set_msg("correct ->");
        }));

        for (auto& thr : threads)
        {
            if(thr.joinable())
            {
                thr.join();
            }
        }
    }

    auto& sgl_02 = Singleton<int>::create_instance();
    std::cout << sgl_02.get_msg() << '\n';
     

    return 0;
}