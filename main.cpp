#include <filesystem>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>

int main() {
  using namespace std::filesystem;
  path dirPath = ".";
  if (!exists(dirPath)) {
    std::cerr << "Directory not founds" << std::endl;
    return 1;
  }

  std::string filePath{};
  for (const auto &entry : directory_iterator(dirPath)) {
    filePath = entry.path().string();
    // Find markdown files
    if (filePath.find(".md") != std::string::npos) {
      // Open logging file
      std::fstream log{"modifications.log", std::ios::app};
      if (!log) {
        std::cerr << "Error opening logging file";
      }
      log << "--------\n";
      log << "Modifing " << filePath << std::endl;

      std::cout << "--------\n";
      std::cout << "Modifing " << filePath << std::endl;
      // prepare new file
      std::string newFilePath{filePath + ".new"};
      std::ofstream newFile{newFilePath};
      if (!newFile) {
        std::cerr << "Error opening new file\n";
        return 1;
      }
      std::fstream file{filePath, std::ios::in};
      std::string line{};
      if (!file) {
        std::cerr << "Error opening md file\n";
        return 1;
      }
      // find the line in file
      while (std::getline(file, line)) {
        // Regex setup
        std::regex reg{"^Tags:\\s*(\\[\\[(\\w+)\\]\\]\\s*)+"};
        // Modify only links in Tags: line
        std::string modified{};
        if (std::regex_match(line, reg)) {
          // Modify
          std::regex pattern_B(R"(\[\[(\w+)\]\])");
          modified = std::regex_replace(line, pattern_B, "#$1");
          std::cout << "Change: " << modified << std::endl;
          log << "Change: " << modified << std::endl;
          newFile << modified << std::endl;
        } else {
          newFile << line << std::endl;
        }
        // Write to a new file
      }
    }
  }

  return 0;
}
