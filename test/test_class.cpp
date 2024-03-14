#include <iostream>


class Hello_word{
    public:
        int getLength(std::string text);
        Hello_word();
        ~Hello_word();
    
    private:
        int len;
};

Hello_word::Hello_word(void){
    std::cout << "Objeto criado com sucesso.\n";
}

Hello_word::~Hello_word(void){
    std::cout << "Objeto destruido com sucesso.\n";
}

int Hello_word::getLength(std::string text){
    len = text.size();
    return len;
}

int main(){
    int tam;
    Hello_word hello_word;
    tam = hello_word.getLength("Hello_Word");
    std::cout << "Número de caracteres: " << tam << std::endl;

    return 0;

}


