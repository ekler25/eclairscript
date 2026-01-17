#include <iostream>
#include <fstream>
#include <classes/lexer.hpp>
#include <types.hpp>

int main(int argc, char** argv) {
    if (!argv[1]) {
        std::cout << "[ \x1b[91mUsage Error\x1b[0m ] Please provide a file name!\n";
        return 1;
    }

    std::fstream File;

    File.open(argv[1], std::ios::in);

    if (!File.is_open()) {
        std::cout << "[ \x1b[91mFile Error\x1b[0m ] Failed to open \x1b[91m" << argv[1] << "\x1b[0m!\n";
        return 1;
    }

    Lexer LexerInstance;

    String LineBuffer;
    while (std::getline(File, LineBuffer)) {
        if (!LineBuffer.empty() && LineBuffer.back() == '\r') LineBuffer.pop_back();
        std::cout << "\nProcessing \x1b[92m" << LineBuffer << "\x1b[0m\n";

        LexerInstance.Final.insert(
            LexerInstance.Final.end(),
            std::make_move_iterator(LexerInstance.ToReturn.begin()),
            std::make_move_iterator(LexerInstance.ToReturn.end())
        );
        LexerInstance.ToReturn.clear();
        LexerInstance.ToReturn.shrink_to_fit();  
        LexerInstance.LexicalAnalisys(LineBuffer);
    }
}
