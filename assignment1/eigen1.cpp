#include <iostream>
#include <Eigen/Dense>

int main() {
    // 첫 번째 행렬: 3x2
    Eigen::Matrix<float, 3, 2> A;
    A << 1, 2,
         3, 4,
         5, 6;

    // 두 번째 행렬: 2x3
    Eigen::Matrix<float, 2, 3> B;
    B << 7, 8, 9,
         10, 11, 12;

    // 행렬 곱: 3x3
    Eigen::Matrix<float, 3, 3> result = A * B;

    std::cout << "결과 행렬:\n" << result << std::endl;
    return 0;
}
