#include "CommandHandler.h"
#include <regex>
#include <sstream>

std::vector<std::string> CommandHandler::splitArgs(const std::string &input) {
    std::vector<std::string> tokens;

    // Regs to match words or quoted strings
    std::regex rgx(R"((\"[^\"]+\"|\S+))"); // command \"arg1 with spaces\" arg2 \" arg3
    auto words_begin = std::sregex_iterator(input.begin(), input.end(), rgx);
    auto words_end = std::sregex_iterator();

    for(auto i = words_begin; i != words_end; ++i) {
        std::string token = i->str();
        // Remove quotes
        if (token.size() >= 2 && token.front() == '\"' && token.back() == '\"') {
            token = token.substr(1, token.size() - 2);
        }
        tokens.push_back(token);
    }

    return tokens;
}
/*
* -> start of an array
$ -> bulk of string
+arg
*/


std::string CommandHandler::buildRESPcommand(const std::vector<std::string> &args) {
    std::ostringstream oss;
    oss << "*" << args.size() << "\r\n"; // num of args

    for (const auto &args: args) {
        oss << "$" << args.size() << "\r\n" << "\r\n"; // len and value of arg
    }
    return oss.str();
}