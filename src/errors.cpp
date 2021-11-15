
#include "../include/unsold.hpp"

int check_isdigit(int ac, char **av)
{
    for (int i = 1; i < ac; i++) {
        for (int j = 0; j < strlen(av[i]); j++)
            if (!std::isdigit(av[i][j]))
                return (84);
    }
    return (0);
}

int limit_ab(int ac, char **av)
{
    int res = 0;
    for (int i = 1; i < ac; i++) {
        res = std::stoi(av[i]);
        if (res <= 50)
           return (84);
    }
    return (0);
}
