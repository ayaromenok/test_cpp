//required https://fmt.dev/latest/api.html
//speed comparation https://aras-p.info/blog/2022/02/25/Curious-lack-of-sprintf-scaling/

#include <fmt/core.h>
#include <fmt/format.h>//for fmt::literals;
#include <vector>
#include <QtCore>


using namespace fmt::literals; //C++11 required

void fmt__print(){
    fmt::print("The answer is {}.\n", 42);
    fmt::print(stderr, "Don't {}!\n", "panic");

    fmt::print("I'd rather be {1} than {0}.\n", "right", "happy");
    fmt::print("Hello, {name}! The answer is {number}. Goodbye, {name}.\n",
               fmt::arg("name", "World"), fmt::arg("number", 42));


    fmt::print("Hello, {name}! The answer is {number}. Goodbye, {name}.\n",
               "name"_a="World", "number"_a=42);
    fmt::print(stderr, "System error code = {}\n", errno);
}

void fmt__format_to(){
    auto out = std::vector<char>();
    fmt::format_to(std::back_inserter(out), "{}", 42);
    qInfo() << "format_to  std::vector<char>"<< out;

    auto out_qt = QVector<char>();
    fmt::format_to(std::back_inserter(out_qt), "{}", 42);
    qInfo() << "format_to  QVector<char>"<< out_qt;
}

int main() {
    fmt__print();
    fmt__format_to();
    return 0;
}
