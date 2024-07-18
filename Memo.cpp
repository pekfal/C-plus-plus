#include <iostream>
#include <vector>
#include <string>

// MemoPad 클래스 정의
class MemoPad {
private:
    // 메모를 저장할 벡터
    std::vector<std::string> memos;

public:
    // 메모 추가 함수2
    void addMemo(const std::string& memo) {
        memos.push_back(memo);  // 벡터에 메모 추가
        std::cout << "Memo added.\n";
    }

    // 지정된 위치에 메모 삽입 함수
    void insertMemo(int index, const std::string& memo) {
        // 인덱스가 유효한지 확인
        if (index < 0 || index > memos.size()) {
            std::cout << "Invalid index.\n";
        } else {
            memos.insert(memos.begin() + index, memo);  // 지정된 인덱스에 메모 삽입
            std::cout << "Memo inserted.\n";
        }
    }

    // 메모 삭제 함수
    void deleteMemo(int index) {
        // 인덱스가 유효한지 확인
        if (index < 0 || index >= memos.size()) {
            std::cout << "Invalid index.\n";
        } else {
            memos.erase(memos.begin() + index);  // 지정된 인덱스의 메모 삭제
            std::cout << "Memo deleted.\n";
        }
    }

    // 메모 조회 함수
    void viewMemos() const {
        // 메모가 비어있는지 확인
        if (memos.empty()) {
            std::cout << "No memos available.\n";
        } else {
            // 모든 메모 출력
            for (size_t i = 0; i < memos.size(); ++i) {
                std::cout << i << ": " << memos[i] << std::endl;
            }
        }
    }
};

// 메인 함수
int main() {
    MemoPad memoPad;  // MemoPad 객체 생성
    int choice;       // 사용자 선택을 저장할 변수
    std::string input; // 메모 입력을 저장할 변수
    int index;        // 인덱스를 저장할 변수

    while (true) {
        // 메뉴 출력
        std::cout << "\nMemoPad Menu:\n";
        std::cout << "1. Add Memo\n";
        std::cout << "2. Insert Memo\n";
        std::cout << "3. Delete Memo\n";
        std::cout << "4. View Memos\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;   // 사용자 선택 입력
        std::cin.ignore();    // 개행 문자 제거

        switch (choice) {
            case 1:
                std::cout << "Enter memo: ";
                std::getline(std::cin, input); // 메모 내용 입력
                memoPad.addMemo(input);        // 메모 추가
                break;
            case 2:
                std::cout << "Enter index to insert at: ";
                std::cin >> index;             // 삽입할 인덱스 입력
                std::cin.ignore();             // 개행 문자 제거
                std::cout << "Enter memo: ";
                std::getline(std::cin, input); // 메모 내용 입력
                memoPad.insertMemo(index, input); // 메모 삽입
                break;
            case 3:
                std::cout << "Enter index to delete: ";
                std::cin >> index;             // 삭제할 메모의 인덱스 입력
                memoPad.deleteMemo(index);     // 메모 삭제
                break;
            case 4:
                memoPad.viewMemos();           // 저장된 메모 조회
                break;
            case 5:
                std::cout << "Exiting...\n";    // 종료 메시지 출력
                return 0;                       // 프로그램 종료
            default:
                std::cout << "Invalid choice. Please try again.\n"; // 유효하지 않은 선택 처리
        }
    }
}
