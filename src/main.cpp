#include <iostream>
#include <sstream>
#include <string>

std::string parseCommand(std::stringstream *ss) {
    std::string command;
    *ss >> command;
    return command;
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
      if (input == "exit 0") break;
      if (command == "echo") {
          std::string word;
          while (!ss.eof()) {
              ss >> word;
              std::cout << word << " ";
          }
          std::cout << std::endl;
      }
      else std::cout << input << ": command not found" << std::endl;
  }
}
