#include <superpes.h>

int main()
{
    std::cout << "                            <<Superpes>>" << std::endl;
    std::cout << "Please, input a dog name:" << std::endl;
    std::string name;
    std::cin >> name;
    std::cout << "Please, input a dog age:" << std::endl;
    int age;
    std::cin >> age;
    Dog* dog = new Dog(age, name);
    std::string command;
    while (true)
    {
        std::cout << "Input a command (add, show, exit):" << std::endl;
        std::cin >> command;
        while (command != "add" &&
               command != "show" &&
               command != "exit")
        {
            std::cerr << "Incorrect input, try again" << std::endl;
            std::cin >> command;
        }
        if (command == "add") {
            dog->addTalent();
        }
        else if (command == "show") {
            dog->showTalents();
        } else {
            break;
        }
    }
    delete dog;
    return 0;
}