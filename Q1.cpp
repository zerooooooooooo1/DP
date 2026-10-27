#include <iostream>
#include <string>
#include <regex>
using namespace std;

bool validateEmail(const string& email) {
    regex pattern(R"([a-zA-Z0-9._%-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    return regex_match(email, pattern);
}

bool validateAge(int age) {
    return age >= 1 && age <= 120;
}

int main() {
    string email = "user@example.com";
    int age = 25;

    cout << "Email valid: " << (validateEmail(email) ? "YES" : "NO") << endl;
    cout << "Age valid: " << (validateAge(age) ? "YES" : "NO") << endl;

    string bad = "notanemail";
    int bad_age = -5;

    cout << "Bad email valid: " << (validateEmail(bad) ? "YES" : "NO") << endl;
    cout << "Bad age valid: " << (validateAge(bad_age) ? "YES" : "NO") << endl;

    return 0;
}
