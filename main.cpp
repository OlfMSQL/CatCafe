#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <limits>
#include <thread>

class VirtualCat {
private:
    std::string name;
    int age;
    int hunger;
    int happiness;
    int energy;
    std::vector<std::string> visits;

public:
    VirtualCat(std::string n, int a) : name(n), age(a), hunger(50), happiness(50), energy(50) {}

    std::string getName() const {
        return name;
    }

    void passTime() {
    hunger += 5;
    happiness -= 5;
    energy -= 5;
}

    void eat() {
        hunger -= 10;
        std::cout << name << " is eating. Hunger level: " << hunger << std::endl;
        visits.push_back(name + " ate.");
    }

    void play() {
        happiness += 10;
        energy -= 10;
        std::cout << name << " is playing. Happiness level: " << happiness << std::endl;
        visits.push_back(name + " played.");
    }

    void sleep() {
        energy += 20;
        std::cout << name << " is sleeping. Energy level: " << energy << std::endl;
        visits.push_back(name + " slept.");
    }

    void meow() {
        std::cout << name << " says: Meow! Meow!" << std::endl;
    }

    void checkStatus() {
        std::cout << "----- " << name << "'s Status -----" << std::endl;
        std::cout << "Age: " << age << " years" << std::endl;
        std::cout << "Hunger level: " << hunger << std::endl;
        std::cout << "Happiness level: " << happiness << std::endl;
        std::cout << "Energy level: " << energy << std::endl;
        std::cout << "------------------------" << std::endl;
    }

    const std::vector<std::string>& getVisits() const {
        return visits;
    }

    bool isGameOver() {
        return (hunger <= 0 || happiness <= 0 || energy <= 0);
    }
};

int main() {
    srand(static_cast<unsigned>(time(0)));

    std::vector<VirtualCat> cats;  // Store multiple cats
    std::string catName;
    int catAge;

    std::cout << "Welcome to the Virtual Cat Cafe!" << std::endl;

    int timerCount = 0;
    const int timeToPass = 10;

    while (true) {
        for (auto& cat : cats) {
            cat.passTime();
        }

        timerCount++;

        if (timerCount >= timeToPass) {
            timerCount = 0; 
        }

        std::cout << " /\\_/\\  " << std::endl;
        std::cout << "( o.o ) " << std::endl;
        std::cout << " > ^ <  \n" << std::endl;
        std::cout << "Choose an option:" << std::endl;
        std::cout << "1. Feed my cat" << std::endl;
        std::cout << "2. Play with my cat" << std::endl;
        std::cout << "3. Let my cat sleep" << std::endl;
        std::cout << "4. Add a new cat" << std::endl;
        std::cout << "5. See all visits" << std::endl;
        std::cout << "6. Check Cat status" << std::endl;
        std::cout << "7. Exit" << std::endl;

        int choice;
        std::cin >> choice;

                if (std::cin.fail()) {
            // Handle invalid input (non-numeric input)
            std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number (1-7)." << std::endl;
            continue;  // Restart the loop to get valid input
        }

        switch (choice) {
            case 1:
                if (cats.empty()) {
                    std::cout << "No cats to feed. Add a cat first." << std::endl;
                } else {
                    std::cout << "Choose a cat to feed:" << std::endl;
                    for (size_t i = 0; i < cats.size(); ++i) {
                        std::cout << i + 1 << ". " << cats[i].getName() << std::endl;
                    }
                    int catChoice;
                    std::cin >> catChoice;
                    if (catChoice >= 1 && catChoice <= static_cast<int>(cats.size())) {
                        cats[catChoice - 1].eat();
                    } else {
                        std::cout << "Invalid cat choice. Try again." << std::endl;
                    }
                }
                break;

            case 2:
                if (cats.empty()) {
                    std::cout << "No cats to play with. Add a cat first." << std::endl;
                } else {
                    std::cout << "Choose a cat to play with:" << std::endl;
                    for (size_t i = 0; i < cats.size(); ++i) {
                        std::cout << i + 1 << ". " << cats[i].getName() << std::endl;
                    }
                    int catChoice;
                    std::cin >> catChoice;
                    if (catChoice >= 1 && catChoice <= static_cast<int>(cats.size())) {
                        cats[catChoice - 1].play();
                    } else {
                        std::cout << "Invalid cat choice. Try again." << std::endl;
                    }
                }
                break;

            case 3:
                if (cats.empty()) {
                    std::cout << "No cats to let sleep. Add a cat first." << std::endl;
                } else {
                    std::cout << "Choose a cat to let sleep:" << std::endl;
                    for (size_t i = 0; i < cats.size(); ++i) {
                        std::cout << i + 1 << ". " << cats[i].getName() << std::endl;
                    }
                    int catChoice;
                    std::cin >> catChoice;
                    if (catChoice >= 1 && catChoice <= static_cast<int>(cats.size())) {
                        cats[catChoice - 1].sleep();
                    } else {
                        std::cout << "Invalid cat choice. Try again." << std::endl;
                    }
                }
                break;

            case 4:
                std::cout << "Enter the new cat's name: ";
                std::cin >> catName;
                std::cout << "Enter the new cat's age: ";
                std::cin >> catAge;
                cats.push_back(VirtualCat(catName, catAge));
                std::cout << catName << " has been added to the cat cafe!" << std::endl;
                break;

            case 5:
                std::cout << "Visits to the Cat Cafe:" << std::endl;
                for (const auto& cat : cats) {
                    std::cout << "Visits for " << cat.getName() << ":" << std::endl;
                    const auto& visits = cat.getVisits();
                    for (const auto& visit : visits) {
                        std::cout << " - " << visit << std::endl;
                    }
                }
                break;

            case 6:
                std::cout << "Check Cat status:" << std::endl;
                if (cats.empty()) {
                    std::cout << "No cats to let sleep. Add a cat first." << std::endl;
                } else {
                    std::cout << "Choose a status of a cat you want to check:" << std::endl;
                    for (size_t i = 0; i < cats.size(); ++i) {
                        std::cout << i + 1 << ". " << cats[i].getName() << std::endl;
                    }
                    int catChoice;
                    std::cin >> catChoice;
                    if (catChoice >= 1 && catChoice <= static_cast<int>(cats.size())) {
                        cats[catChoice - 1].checkStatus();
                    } else {
                        std::cout << "Invalid cat choice. Try again." << std::endl;
                    }
                }
                break;

            case 7:
                std::cout << "Exiting the cat cafe. Goodbye!" << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(5)); // Wait for 5 seconds
                return 0;

            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }
    }

    return 0;
}
