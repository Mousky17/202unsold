
#include "../include/unsold.hpp"

int main(int ac, char **av)
{

    if (ac == 2 && strcmp(av[1], "-h") == 0)
        usage();
    else if (ac != 3)
        return (84);
    if (check_isdigit(ac, av) == 84 || limit_ab(ac, av) == 84)
        return (84);
    else
    {
        int a = std::stoi(av[1]);
        int b = std::stoi(av[2]);
        unsold(a, b);
    }
}
