#include <iostream>
#include <vector>

int main() {
    // 벡터 생성
    std::vector<int> vec;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    std::cout << "First element: " << vec[0] << std::endl; // vec.at(0) 도 사용 가능

    // 크기와 용량
    std::cout << "Size: " << vec.size() << std::endl;
    std::cout << "Capacity: " << vec.capacity() << std::endl;

    // 삽입
    vec.insert(vec.begin() + 1, 10); // 두 번째 위치에 10 삽입

    std::cout << "Elements: ";
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Capacity: " << vec.capacity() << std::endl;



    // 삭제
    vec.erase(vec.begin() + 2); // 세 번째 요소 삭제

    // 전체 요소 출력
    std::cout << "Elements: ";
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    vec.push_back(7);
    vec.push_back(8);
    vec.push_back(9);
    vec.push_back(10);
    vec.push_back(11);
    vec.push_back(12);
    
    std::cout << "Elements: ";
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Capacity: " << vec.capacity() << std::endl;


    return 0;
}
