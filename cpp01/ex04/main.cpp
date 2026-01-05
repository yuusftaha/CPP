#include <string>
#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
    if (ac != 4 || !av[1] || !av[2] || !av[3])
    {
        std::cout << "missing parameter" << std::endl;
        return 1;
    }    

    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open()) 
    {
        std::cerr << "Error: File could not be opened!" << std::endl;
        return (1);
    }

    std::string outputFile = filename + ".replace";
    std::ofstream outFile(outputFile.c_str());
    if (!outFile.is_open())
    {
        std::cerr << "Error: Could not create replace file!" << std::endl;
        inputFile.close();
        return (1);
    }

    std::string line;
    while (std::getline(inputFile, line))
    {
        size_t i = 0;
            while ((i = line.find(s1, i)) != std::string::npos)
            {
                line.erase(i, s1.length());
                line.insert(i, s2);
                i += s2.length();
            }
        outFile << line;
        if (!inputFile.eof())
            outFile << std::endl;
    }
    
    inputFile.close();
    outFile.close();
    return 0;
}
