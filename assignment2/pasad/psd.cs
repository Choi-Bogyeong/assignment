using System;

class CPU {
    public string Process() => "CPU 처리 중";
}

class Memory {
    public string Load() => "메모리 로딩 중";
}

class SSD {
    public string Read() => "SSD 드라이브 읽는 중";
}

class Computer { // 파사드 클래스
    private CPU cpu = new CPU();
    private Memory memory = new Memory();
    private SSD ssd = new SSD();

    public void Boot() {
        Console.WriteLine(ssd.Read());
        Console.WriteLine(memory.Load());
        Console.WriteLine(cpu.Process());
    }
}

// 테스트 코드
class Program {
    static void Main() {
        Computer c = new Computer();
        c.Boot();
    }
}
