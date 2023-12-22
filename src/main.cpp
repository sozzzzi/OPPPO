#include "../lib/maincycle.h"
#include <io.h>
#include <fcntl.h>
int main()
{
    _setmode(_fileno(stdout), _O_U8TEXT);
    _setmode(_fileno(stderr), _O_U8TEXT);
    std::string path_file = "input.txt";

    auto *mp = new MainCycle();
    if (!mp->run(path_file))
        std::wcout << L"Программа успешно завершена";
    else
        std::wcerr << L"Программа завершена c ошибкой!";
    return 0;
}
