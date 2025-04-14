// 기본 커피 클래스
open class Coffee {
    open fun cost(): Int = 5
}

// 데코레이터 베이스 클래스
open class CoffeeDecorator(private val coffee: Coffee) : Coffee() {
    override fun cost(): Int = coffee.cost()
}

// 밀크 추가
class MilkDecorator(coffee: Coffee) : CoffeeDecorator(coffee) {
    override fun cost(): Int = super.cost() + 2
}

// 설탕 추가
class SugarDecorator(coffee: Coffee) : CoffeeDecorator(coffee) {
    override fun cost(): Int = super.cost() + 1
}

// 테스트 코드
fun main() {
    val coffee = Coffee()
    println("Basic coffee: ${coffee.cost()}")

    val milkCoffee = MilkDecorator(coffee)
    println("With milk: ${milkCoffee.cost()}")

    val sugarCoffee = SugarDecorator(coffee)
    println("With sugar: ${sugarCoffee.cost()}")

    val milkSugarCoffee = SugarDecorator(milkCoffee)
    println("With milk and sugar: ${milkSugarCoffee.cost()}")
}
