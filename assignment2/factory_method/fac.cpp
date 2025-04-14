#include <iostream>
#include <string>
#include <memory>

class Animal {
public:
    virtual std::string speak() const = 0;
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    std::string speak() const override {
        return "Woof!";
    }
};

class Cat : public Animal {
public:
    std::string speak() const override {
        return "Meow!";
    }
};

class AnimalFactory {
public:
    std::unique_ptr<Animal> createAnimal(const std::string& type) {
        if (type == "dog") {
            return std::make_unique<Dog>();
        } else if (type == "cat") {
            return std::make_unique<Cat>();
        }
        return nullptr;
    }
};

// 테스트 코드
int main() {
    AnimalFactory factory;

    auto dog = factory.createAnimal("dog");
    if (dog) {
        std::cout << "Dog says: " << dog->speak() << std::endl;
    }

    auto cat = factory.createAnimal("cat");
    if (cat) {
        std::cout << "Cat says: " << cat->speak() << std::endl;
    }

    auto unknown = factory.createAnimal("elephant");
    if (!unknown) {
        std::cout << "Unknown animal type." << std::endl;
    }

    return 0;
}
