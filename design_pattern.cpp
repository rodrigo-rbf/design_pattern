#include <iostream>
#include <iostream>
#include <vector>


struct Character{
    int x;
    int y;
    std::string name;
    Character(std::string _name) : name(_name){}
    void move(int _x, int _y){
        x = _x;
        y = _y;
    }
};

class Command{
    public:
        Command(){};
        ~Command(){};

        virtual void execute(Character& c) = 0;
        virtual void undo(Character& c) = 0;
};

class Move : public Command{
    public:
        void execute(Character& c){
            std::cout << c.name << " moved\n";
        }

        void undo(Character& c){}

};

// class Jump{

// };

int main(int argc, char* argv[])
{
    
   
    std::vector<Command*> command_queue;
    Character nickname("Digo");
    Move* m1 = new Move;
    command_queue.push_back(m1);
    Move* m2 = new Move;
    command_queue.push_back(m2);
    Move* m3 = new Move;
    command_queue.push_back(m3);
    Move* m4 = new Move;
    command_queue.push_back(m4);

    for(int i = 0; i < command_queue.size(); i++){
        command_queue[i]->execute(nickname);
    }

   
    return 0;
}