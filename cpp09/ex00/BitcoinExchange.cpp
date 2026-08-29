#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() 
{
    std::ifstream file("data.csv");
    if (!file.is_open()) 
        throw std::runtime_error("Error: could not open database file.");

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) 
    {
        std::istringstream ss(line);
        std::string date;
        float value;

        if (std::getline(ss, date, ',') && (ss >> value)) 
        {
            if (isValidDate(date)) 
                database[date] = value;
        }
    }
    
    if (database.empty())
        throw std::runtime_error("Error: database is empty or corrupted.");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) 
{
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) 
{
    if (this != &other) {
        this->database = other.database;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isValidDate(const std::string& date) const 
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') 
        return false;

    for (int i = 0; i < 10; ++i) 
    {
        if (i == 4 || i == 7) 
            continue;
        if (!isdigit(date[i])) 
            return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) 
        return false;
    
    if (month == 2) 
    {
        bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (isLeap) 
        {
            if (day > 29) 
                return false;
        } 
        else 
        {
            if (day > 28) 
                return false;
        }
    }
    return true;
}


void BitcoinExchange::processInput(const std::string& filename) 
{
    std::ifstream file(filename.c_str());
    if (!file.is_open()) 
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) 
    {
        if (line.empty())
            continue;

        size_t delimPos = line.find(" | ");
        if (delimPos == std::string::npos) 
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, delimPos);
        std::string valueStr = line.substr(delimPos + 3);

        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        char* end;
        float value = std::strtof(valueStr.c_str(), &end);

        if (*end != '\0' && *end != 'f' && *end != '\r') 
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (value < 0) 
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000) 
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        std::map<std::string, float>::iterator it = database.lower_bound(date);
        if (it == database.end() || it->first != date) 
        {
            if (it == database.begin()) 
            {
                std::cerr << "Error: date is earlier than database records => " << date << std::endl;
                continue;
            }
            --it;
        }
        std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
    }
}