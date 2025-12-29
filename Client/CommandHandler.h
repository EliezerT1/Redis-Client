#ifndef COMMAND_HANDLER_H
#define COMMAND_HANDLER_H

#include <string>
#include <vector>

class CommandHandler {
    public:
    // Split comman into token
    static std::vector<std::string> splitArgs(const std::string &input);

    // Build a REST command from the vector arguments
    static std::string buildRESPcommand(const std::vector<std::string> &args);
};

#endif // COMMAND_HANDLER_H 