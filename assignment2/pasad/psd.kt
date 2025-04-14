class CPU {
    fun process(): String = "CPU 처리 중"
}

class Memory {
    fun load(): String = "메모리 로딩 중"
}

class SSD {
    fun read(): String = "SSD 드라이브 읽는 중"
}

class Computer { // 파사드 클래스
    private val cpu = CPU()
    private val memory = Memory()
    private val ssd = SSD()

    fun boot() {
        println(ssd.read())
        println(memory.load())
        println(cpu.process())
    }
}

// 테스트 코드
fun main() {
    val computer = Computer()
    computer.boot()
}
