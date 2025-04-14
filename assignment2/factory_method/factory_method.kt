abstract class Animal {
    abstract fun speak(): String
}

class Dog : Animal() {
    override fun speak(): String = "Woof!"
}

class Cat : Animal() {
    override fun speak(): String = "Meow!"
}

class AnimalFactory {
    fun createAnimal(type: String): Animal? {
        return when (type) {
            "dog" -> Dog()
            "cat" -> Cat()
            else -> null
        }
    }
}

// 테스트 코드
fun main() {
    val factory = AnimalFactory()

    val dog = factory.createAnimal("dog")
    println("Dog says: ${dog?.speak()}")

    val cat = factory.createAnimal("cat")
    println("Cat says: ${cat?.speak()}")

    val unknown = factory.createAnimal("elephant")
    if (unknown == null) {
        println("Unknown animal type.")
    }
}
