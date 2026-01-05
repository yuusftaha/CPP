#include "Harl.hpp"

int main(void)
{
    Harl harl;

    std::cout << "--- TEST 4: ERROR ---" << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl;

    std::cout << "--- TEST 2: INFO ---" << std::endl;
    harl.complain("INFO");
    std::cout << std::endl;

    std::cout << "--- TEST 1: DEBUG ---" << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl;

    std::cout << "--- TEST 3: WARNING ---" << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;


    std::cout << "--- TEST 5: INVALID LEVEL (Should not crash) ---" << std::endl;
    harl.complain("I_WANT_FREE_FOOD");
    harl.complain("");
    harl.complain("42ISTANBUL");
    std::cout << "Test finished successfully!" << std::endl;

    return (0);
}