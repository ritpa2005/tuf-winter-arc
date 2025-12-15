#include <iostream>
using namespace std;

int main(){
    // User Input / Output
    int n; cin>>n;
    cout<<"n is "<<n<<endl;

    // Data Types in C++:
    //short, int, long, long long, float, double, long double (+ unsigned mods)	
    //char, wchar_t, char16_t, char32_t, std::string	
    //bool	
    //std::vector, std::array, std::list, std::deque, std::set, std::map, std::unordered_map	
    //nullptr	
    //struct, class, enum, union, templates

    //if-else statements
    int marks = 54;
    char grade;
    if (marks < 50 && marks >= 0) {
        grade = 'D';
    } else if (marks <= 59) {
        grade = 'C';
    } else if (marks <= 69) {
        grade = 'B';
    } else if (marks >= 70 && marks <= 100) {
        grade = 'A';
    } else {
        grade = 'X';
    }
    cout << "Grade: " << grade << endl;

    //switch statement
    int x = 10;
    int y = 5;

    switch (x + y) {
        case 15:
            cout << "Result is 15." << endl;
            break;
        case 20:
            cout << "Result is 20." << endl;
            break;
        default:
            cout << "No match found." << endl;
    }

    //Time Complexity: O(1) for both if-else and switch statements
    return 0;
}