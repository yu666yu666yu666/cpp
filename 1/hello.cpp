#include <iostream> // for std::cout

int main()
{
    int i;
    std::cout << "Hello world!"; // print Hello world! to console
    std::cout << i/3 <<   "   4";
    return 0;
}




/*

std::cout
std::cerr
std::clog
int当整数的大小无关紧要（例如，数字总是在 2 字节有符号整数的范围内）并且变量是短暂的（例如，在函数结束时被销毁）时，首选。例如，如果您要求用户输入他们的年龄，或者从 1 数到 10，那么 int 是 16 位还是 32 位并不重要（数字都适合）。这将涵盖您可能遇到的绝大多数情况。
std::int#_t当存储需要保证范围的数量时首选。
std::uint#_t在进行位操作或需要明确定义的环绕行为时首选。

尽可能避免以下情况：

short和long整数——改用固定宽度类型。
持有数量的无符号类型。
8 位固定宽度整数类型。
快速和最小固定宽度类型。
任何特定于编译器的固定宽度整数 - 例如，Visual Studio 定义 __int8、__int16 等......

std::cout为false打印0，为true打印1
如果您希望 std::cout 打印“true”或“false”而不是 0 或 1，则可以使用std::boolalpha
您可以使用std::noboolalpha将其关闭。
要允许std::cin接受“false”和“true”作为输入，必须启用std::boolalpha选项
但是，当启用std::boolalpha时，“0”和“1”将不再被解释为布尔输入（它们都解析为“false”，就像任何非“true”输入一样）

通过 static_cast 运算符进行显式类型转换

与 C 风格的字符串文字不同，std::string文字std::string_view创建临时对象。这些临时对象必须立即使用，因为它们在创建它们的完整表达式结束时被销毁。

根据编译时常量的定义，只有带有常量表达式初始值设定项的 const整型变量才是编译时常量。b是一个double，它不是整型，所以不满足这个定义。
于变量来说，const意味着对象的值在初始化后就不能改变。 Constexpr 意味着对象必须具有编译时已知的值。

默认情况下，C++ 以十进制输出值。但是，您可以通过使用std::dec、std::oct和std::hexI/O 操纵符来更改输出格式

普通函数调用在运行时进行评估，提供的参数用于初始化函数的参数。由于函数参数的初始化发生在运行时，这会导致两个后果：
const函数参数被视为运行时常量（即使提供的参数是编译时常量）。
函数参数不能声明为constexpr，因为它们的初始化值直到运行时才确定。

在大多数情况下，您不应将函数或变量标记为内联，除非您在头文件中定义它们（并且它们尚未隐式内联）。

允许在编译时或运行时评估具有 constexpr 返回类型的函数，以便单个函数可以满足这两种情况。





*/