#include <thread>
#include <cstdlib>
#include <vector>
#include <string>
#include <filesystem>
#include <iostream>

void processFile(const std::string& filePath) {
    // 获取文件名（不包括扩展名）
    std::string fileName = std::filesystem::path(filePath).stem().string();
    // 创建文件夹
    std::filesystem::create_directory(fileName);
    // 转换PDF到PNG
    std::string command = "pdftopng \"" + filePath + "\" \"" + fileName + "\\" + fileName + "\"";
    std::system(command.c_str());

    // 压缩文件夹
    command = "powershell.exe -ExecutionPolicy Bypass -File .\\zip.ps1 \"" + fileName + "\"";
    std::system(command.c_str());
    // 删除文件夹
    std::filesystem::remove_all(fileName);
}

int main() {
    // std::locale::global(std::locale("Chinese_China.936"));
    setlocale(LC_ALL, ".UTF8");
    std::vector<std::thread> threads;

    for (const auto & entry : std::filesystem::directory_iterator("./")) {
        std::cout << entry.path() << std::endl;
        if (entry.path().extension() == ".pdf") {
            threads.emplace_back(processFile, entry.path().string());
        }
    }

    for (auto& t : threads) {
        t.join();
    }

    return 0;
}