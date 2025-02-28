#include <iostream>
#include <sstream>
#include <string>

//enum BuiltinCommand { ECHO, EXIT, TYPE, INVALID };
//
//class Command {
//private:
//    BuiltinCommand type = INVALID;
//
//};

std::string parseCommand(std::stringstream *ss) {
    std::string command;
    *ss >> command;
    return command;
}

void echo(std::stringstream *ss) {
    std::string word;
    while (!(*ss).eof()) {
        *ss >> word;
        std::cout << word << " ";
    }
    std::cout << std::endl;
}

void type(std::stringstream *ss) {
    std::string word;
    if (!(*ss).eof()) {
        *ss >> word;
        if (word == "echo") {
            std::cout << "echo is a shell builtin" << std::endl;
            return;
        }
        if (word == "exit") {
            std::cout << "exit is a shell builtin" << std::endl;
            return;
        }
        else {
            std::cout << word + ": not found" << std::endl;
            return;
        }
    }
    else {
        std::cout << "pass in an actual argument" << std::endl;
        return;
    }
}

int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  // Uncomment this block to pass the first stage
  while (true) {
      std::cout << "$ ";

      std::string input;
      std::getline(std::cin, input);
      std::stringstream ss(input);
      std::string command = parseCommand(&ss);
//      std::cout << command << std::endl;
      if (command == "exit") break;
      if (command == "echo") {
          echo(&ss);
          continue;
      }
      if (command == "type") {
          type(&ss);
          continue;
      }
      else std::cout << command << ": command not found" << std::endl;
  }

  exit(0);
}
