using System;

// 기존 내부 클래스
class InternalClass {
    public string Fetch() {
        return "get user info";
    }
}

// 외부 라이브러리 클래스
class ExternalClass {
    public string Search() {
        return "get user info";
    }
}

// 어댑터 클래스
class Adapter {
    private ExternalClass external;

    public Adapter(ExternalClass external) {
        this.external = external;
    }

    public string Fetch() {
        return external.Search();
    }
}

// 테스트 코드
class Program {
    static void Main() {
        ExternalClass external = new ExternalClass();
        Adapter adapter = new Adapter(external);

        Console.WriteLine("Adapter fetch: " + adapter.Fetch());
    }
}
