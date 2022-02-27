//required https://fmt.dev/latest/api.html
//speed comparation https://aras-p.info/blog/2022/02/25/Curious-lack-of-sprintf-scaling/

#include <fmt/core.h>
#include <fmt/format.h>//for fmt::literals;
#include <vector>
#include <locale>
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

//C++14 required
void fmt__compile_time_checks(){
    //NoK
    //std::string s_nok = fmt::format(FMT_STRING("{:d}"), "NaN");
    //std::string s_ok = fmt::format(FMT_STRING("{:d}"), "42");
    //qInfo() << "Compile time checks" << s_ok.c_str();
}

void fmt_locale(){
    std::locale::global(std::locale("en_US.UTF-8"));
    auto s = fmt::format("{:L}", 1000000);
    qInfo() << "Locale(en_US): " << s.c_str();
}

int main() {
    fmt__print();
    fmt__format_to();
    fmt__compile_time_checks(); //NoK
    fmt_locale();
    return 0;
}
