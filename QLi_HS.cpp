#include <iostream>
#include <vector>
#include <string>
#include <cctype>

class STUDENT {
    std::string Fullname;
    std::string Std_code;
    std::string EmailAddress;

public:
    void input() {
        std::cout << "Enter Fullname: ";
        std::cin.ignore();
        std::getline(std::cin, Fullname);
        std::cout << "Enter Student code: ";
        std::cin >> Std_code;
        std::cin.ignore();
        std::cout << "Enter Email Address: ";
        std::getline(std::cin, EmailAddress);
    }

    void display() {
        std::cout << "Fullname: " << Fullname << std::endl;
        std::cout << "Student code: " << Std_code << std::endl;
        std::cout << "Email Address: " << EmailAddress << std::endl;
    }

    const std::string& getStudent() const {
        return Std_code;
    }
};

class Tools{
    std::vector<STUDENT> STUDENTs;
    int n;

public:
    void AddStudent() {
        STUDENT newSTUDENT;
        newSTUDENT.input();
        STUDENTs.push_back(newSTUDENT);
    }

    void DeleteStudent() {
        std::string student_code;
        std::cout << "Enter Student code: ";
        std::cin >> student_code;

        for (auto it = STUDENTs.begin(); it != STUDENTs.end(); ++it) {
            if (it->getStudent() == student_code) {
                it = STUDENTs.erase(it);
                std::cout << "STUDENT deleted successfully." << std::endl;
                return;
            }
        }

        std::cout << "STUDENT not found." << std::endl;
    }

    void findStudent() {
        std::string student_code;
        std::cout << "Enter Student code: ";
        std::cin >> student_code;

        for (auto &STUDENT : STUDENTs) {
            if (STUDENT.getStudent() == student_code) {
                STUDENT.display();
                return;
            }
        }

        std::cout << "STUDENT not found." << std::endl;
    }

    void displayStudent() {
        for ( auto &ct : STUDENTs) {
            ct.display();
        }
    }

    void Select() {
        std::cout<<"----------------------------------------------------------------"<<std::endl;
        std::cout << "Enter:\n 1: Add new student.\n 2: Delete student information.\n ";
        std::cout<<"3: Search for student information.\n 4: Show all student information.\n 5: Exit.\n";
        std::cout<<"----------------------------------------------------------------"<<std::endl;
        std::cin >> n;
        switch (n) {
            case 1:
                AddStudent();
                break;
            case 2:
                DeleteStudent();
                break;
            case 3:
                findStudent();
                break;
            case 4:
                displayStudent();
                break;
            case 5:
                exit(0);
                break;
            default:
                std::cout << "Invalid choice." << std::endl;
                break;
        }
    }
};

int main() {
    Tools tools;
    while(true) {
        tools.Select();
    }
    return 0;
}