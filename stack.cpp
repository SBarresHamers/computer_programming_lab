#include <iostream>
#include <limits>
#include <vector>

class Stack {
    public:
        Stack();
        bool isEmpty() const;
        int top() const;
        int pop();
        void push(int i);
        std::string toString() const;
    private:
        std::vector<int> elements;
};

Stack::Stack() {
    std::vector<int> elements;
}

bool Stack::isEmpty() const{
     if(elements.size() == 0) {
        return (true);
    }
    else {
        return (false);
    }
}

int Stack::top() const{
    if(isEmpty() == true) {
        throw std::runtime_error("stack is empty");
        return (0);
    }
    else {
        int topElement = elements.at(elements.size() - 1);
        return (topElement);
    }
}

int Stack::pop() {
    int temp;
    if(isEmpty() == true) {
        throw std::runtime_error("stack is empty");
        return (0);
    }
    else {
        temp = elements.at(elements.size() - 1);
        elements.pop_back();
        return (temp);
    }
}

void Stack::push(int i) {
    elements.push_back(i);
}

std::string Stack::toString() const{
    
    std::string outputString = "[";
      
   for(int i = elements.size() - 1; i >= 0; i--) {
        if (i > 0) {

            outputString += std::to_string(elements.at(i));
            outputString.push_back(',');
        }
        else {
            outputString += std::to_string(elements.at(i));
        }
    }
    outputString.push_back(']');
    return (outputString);
}

int main() {
    Stack stack;
    
    while (true) {
        try {
            std::cout << "stack> ";
            
            std::string command;
            std::cin >> command;
            
            if ( (command.compare("end") == 0) || std::cin.eof() ){
                break;
            } else if (command.compare("top") == 0) {
                std::cout << stack.top() << std::endl;
            } else if (command.compare("pop") == 0) {
                std::cout << stack.pop() << std::endl;
            } else if (command == "push") {
                if ( std::cin.eof() ) break;
                int i;
                std::cin >> i;
                bool failed = std::cin.fail();
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if ( failed ){
                  throw std::runtime_error("not a number");
                }
                stack.push(i);
            } else if ( command.compare("list") == 0){
                std::cout << stack.toString() << std::endl;;
            } else {
                throw std::runtime_error("invalid command");
            }
        } catch (std::runtime_error& e) {
            std::cout << "error: " << e.what() << std::endl;
        }
    }
    
    return 0;
}