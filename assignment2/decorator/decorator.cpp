#include <iostream>
#include <memory>

// 기본 커피 클래스
class Coffee {
public:
    virtual int cost() const {
        return 5;
    }
    virtual ~Coffee() = default;
};

// 데코레이터 베이스 클래스
class CoffeeDecorator : public Coffee {
protected:
    std::shared_ptr<Coffee> coffee;
public:
    CoffeeDecorator(std::shared_ptr<Coffee> coffee) : coffee(coffee) {}
    int cost() const override {
        return coffee->cost();
    }
};

// 밀크 추가
class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(std::shared_ptr<Coffee> coffee) : CoffeeDecorator(coffee) {}
    int cost() const override {
        return coffee->cost() + 2;
    }
};

// 설탕 추가
class SugarDecorator : public CoffeeDecorator {
public:
    SugarDecorator(std::shared_ptr<Coffee> coffee) : CoffeeDecorator(coffee) {}
    int cost() const override {
        return coffee->cost() + 1;
    }
};

// 테스트 코드
int main() {
    auto coffee = std::make_shared<Coffee>();
    std::cout << "Basic coffee: " << coffee->cost() << std::endl;

    auto milkCoffee = std::make_shared<MilkDecorator>(coffee);
    std::cout << "With milk: " << milkCoffee->cost() << std::endl;

    auto sugarCoffee = std::make_shared<SugarDecorator>(coffee);
    std::cout << "With sugar: " << sugarCoffee->cost() << std::endl;

    auto milkSugarCoffee = std::make_shared<SugarDecorator>(milkCoffee);
    std::cout << "With milk and sugar: " << milkSugarCoffee->cost() << std::endl;

    return 0;
}
