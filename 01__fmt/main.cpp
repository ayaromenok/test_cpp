//required https://fmt.dev/latest/api.html
//speed comparation https://aras-p.info/blog/2022/02/25/Curious-lack-of-sprintf-scaling/

#include <fmt/core.h>
#include <fmt/format.h>//for fmt::literals;

int main() {
    fmt::print("The answer is {}.\n", 42);
    fmt::print("Don't {}\n", "panic");
    fmt::print("I'd rather be {1} than {0}.\n", "right", "happy");
    fmt::print("Hello, {name}! The answer is {number}. Goodbye, {name}.\n",
               fmt::arg("name", "World"), fmt::arg("number", 42));

using namespace fmt::literals;
    fmt::print("Hello, {name}! The answer is {number}. Goodbye, {name}.\n",
               "name"_a="World", "number"_a=42);

    fmt::print(stderr, "System error code = {}\n", errno);

    return 0;
}
