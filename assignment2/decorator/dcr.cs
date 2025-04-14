using System;

// 기본 커피 클래스
class Coffee {
    public virtual int Cost() {
        return 5;
    }
}

// 데코레이터 베이스 클래스
class CoffeeDecorator : Coffee {
    protected Coffee _coffee;

    public CoffeeDecorator(Coffee coffee) {
        _coffee = coffee;
    }

    public override int Cost() {
        return _coffee.Cost();
    }
}

// 밀크 추가
class MilkDecorator : CoffeeDecorator {
    public MilkDecorator(Coffee coffee) : base(coffee) {}

    public override int Cost() {
        return _coffee.Cost() + 2;
    }
}

// 설탕 추가
class SugarDecorator : CoffeeDecorator {
    public SugarDecorator(Coffee coffee) : base(coffee) {}

    public override int Cost() {
        return _coffee.Cost() + 1;
    }
}

// 테스트 코드
class Program {
    static void Main() {
        Coffee coffee = new Coffee();
        Console.WriteLine("Basic coffee: " + coffee.Cost());

        Coffee milkCoffee = new MilkDecorator(coffee);
        Console.WriteLine("With milk: " + milkCoffee.Cost());

        Coffee sugarCoffee = new SugarDecorator(coffee);
        Console.WriteLine("With sugar: " + sugarCoffee.Cost());

        Coffee milkSugarCoffee = new SugarDecorator(milkCoffee);
        Console.WriteLine("With milk and sugar: " + milkSugarCoffee.Cost());
    }
}
