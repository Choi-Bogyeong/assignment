using System;

abstract class Animal {
    public abstract string Speak();
}

class Dog : Animal {
    public override string Speak() => "Woof!";
}

class Cat : Animal {
    public override string Speak() => "Meow!";
}

class AnimalFactory {
    public Animal CreateAnimal(string type) {
        if (type == "dog") {
            return new Dog();
        } else if (type == "cat") {
            return new Cat();
        }
        return null;
    }
}

// 테스트 코드
class Program {
    static void Main() {
        AnimalFactory factory = new AnimalFactory();

        Animal dog = factory.CreateAnimal("dog");
        if (dog != null) {
            Console.WriteLine("Dog says: " + dog.Speak());
        }

        Animal cat = factory.CreateAnimal("cat");
        if (cat != null) {
            Console.WriteLine("Cat says: " + cat.Speak());
        }

        Animal unknown = factory.CreateAnimal("elephant");
        if (unknown == null) {
            Console.WriteLine("Unknown animal type.");
        }
    }
}
