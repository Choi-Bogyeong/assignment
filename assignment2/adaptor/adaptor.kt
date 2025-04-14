// 내부 클래스
class InternalClass {
    fun fetch(): String = "get user info"
}

// 외부 클래스
class ExternalClass {
    fun search(): String = "get user info"
}

// 어댑터 클래스
class Adapter(private val external: ExternalClass) {
    fun fetch(): String = external.search()
}

// 테스트 코드
fun main() {
    val external = ExternalClass()
    val adapter = Adapter(external)

    println("Adapter fetch: ${adapter.fetch()}")
}
