#include <iostream>
#include <cctype>

void megaphone(int ac, char **av)
{
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        int j = 1;
        while (av[j])
        {
            int i = 0;
            while (av[j][i])
            {   
                char a = std::toupper(av[j][i++]);
                std::cout << a;
            }
            j++;
        }
    }
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    megaphone(argc, argv);
    return 0;
}
