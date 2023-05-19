#include <string>
#include <regex>
#include <iostream>

using namespace std;

int main() {
    string src = "GET /HTTP/1.1";
    string pattern = "^([A-Z]+) (.+) HTTP/1";
    regex r(pattern);
    smatch result;
    regex_search(src, result, r);
}