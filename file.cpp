#include <iostream>
#include <fstream>
#include <regex>
#include <set>

int main()
{
    std::ifstream file("msg.html");
    std::set<std::string> links;
    std::string line;
    std::smatch match;
    std::regex need_find("<\\s*a.+href\\s*=\"(\\S+)\"");
    if (!file.is_open())
    {
        std::cout << "File not found\n";
        return 0;
    }
    while (std::getline(file, line))
    {
        if (std::regex_search(line, match, need_find))
        {
            links.insert(match[1]);
        }
    }
    if (links.empty())
    {
        std::cout << "This site haven't links\n";
    }
    else {
        for (auto item : links)
        {
            std::cout << item << "\n";
        }
    }
}