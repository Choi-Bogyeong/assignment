#include <iostream>
#include <string>

// 기존 인터페이스
class InternalClass {
public:
    std::string fetch() {
        return "get user info";
    }
};

// 외부 클래스 (인터페이스가 다름)
class ExternalClass {
public:
    std::string search() {
        return "get user info";
    }
};

// 어댑터 클래스
class Adapter {
private:
    ExternalClass* external;
public:
    Adapter(ExternalClass* ext) : external(ext) {}

    std::string fetch() {
        return external->search();
    }
};

// 테스트 코드
int main() {
    ExternalClass external;
    Adapter adapter(&external);

    std::cout << "Adapter fetch: " << adapter.fetch() << std::endl;

    return 0;
}
