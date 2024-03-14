#include <iostream>
#include <string>
#include <vector>
#include <memory> 

class Logger{
    public:
        static Logger& GetInstance(){
            static Logger* s_instance = new Logger;
           // static std::unique_ptr<Logger> s_instance = std::make_unique<Logger>(nullptr);
            
            return *s_instance;
        }

        void printMessage(){
            std::cout << "Accessing the log." << std::endl;
            for (auto& e : m_messages){
                std::cout << e << std::endl;
            } 
        }

        void addMessage(std::string s){
            m_messages.push_back(s);
        }
    
    private:
        Logger(){
            std::cout << "Logger was created.\n"<< std::endl;
            
        }

        ~Logger(){
            
            std::cout << "Logger was destructed.\n" << std::endl;
        }

        static Logger* s_instance;
        std::vector<std::string> m_messages;
      
};

//Logger* Logger::s_instance = nullptr;

void counter(){
    static int i = 0;
    std::cout << "i is: " << i << std::endl;
    i++;
}


int main(){

    //Logger::GetInstance->printMessage();
    // Logger* logger;
    // logger->printMessage();

    
    Logger::GetInstance().addMessage("Message 01\n");
    Logger::GetInstance().addMessage("Message 02\n");
    Logger::GetInstance().addMessage("Message 03\n");
    Logger::GetInstance().addMessage("Message 04\n");
    Logger::GetInstance().printMessage();
    //Logger delete;

    return 0;
}

        

