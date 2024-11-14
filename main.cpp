#include <iostream>
#include <string>

class Stat {
public:
    std::string name;
    int stat;
    
    Stat() {
        name = "[unnamed stat]";
        stat = 0;
    }
    
    Stat(std::string name, int stat) {
        this->name = name;
        this->stat = stat;
    }
    
    void add(int value) {
        if (value == 0) {
            return;
        }
        
        stat += value;
        
        char sign = '+';
        if (value < 0) {
            value *= -1;
            sign = '-';
        }
        
        std::cout << name << " " << sign << " " << value << std::endl;
        std::cout << name << " = " << stat << std::endl;
    }
    
    void display() {
        std::cout << name << ": " << stat << std::endl;
    }
};

class Pet {
private:
    Stat energy;
    Stat health;
    Stat happiness;
    
public:
    Pet() {
        energy = Stat("Energy", 30);
        health = Stat("Health", 30);
        happiness = Stat("Happiness", 30);
    }
    
    int getEnergy() {
        return energy.stat;
    }
    
    void display() {
        std::cout << "Pet stats: " << std::endl;
        health.display();
        happiness.display();
        energy.display();
    }
    
    void play() {
        std::cout << "Your pet played a game." << std::endl;
        happiness.add(10);
        energy.add(-5);
    }
};

int main() {
    Pet puff = Pet();
    
    puff.display();
    std::cout << std::endl;
    puff.play();
    std::cout << std::endl;
    puff.display();
    std::cout << std::endl;
}
