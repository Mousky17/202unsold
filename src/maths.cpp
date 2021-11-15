
#include "../include/unsold.hpp"

double **probability(int a, int b)
{
    int i = 0, j = 0;
    seller random = {10, 10};
    double result = 0;
    std::cout << std::setprecision(3) <<  std::fixed;
    double **table = new double*[6];

    for (int i = 0; i < 6; i++)
        table[i] = new double[6];
    for (i = 0, random.x = 10; i < 5, random.x <= 50; i++, random.x += 10) {
        for (j = 0, random.y = 10; j < 5, random.y <= 50; j++, random.y += 10) {
            table[i][j] = (double)((a - random.y) * (b - random.x)) / (((5 * a) - 150) * ((5 * b) - 150));
        }
    }

    for ( i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            result += table[i][j];
        }
        table[i][5] = result;
        result = 0;
    }

    result = 0;

    for (j = 0; j < 6; j++) {
        for (i = 0; i < 5; i++) {
            result += table[i][j];
        }
        table[5][j] = result;
        result = 0;
    }
    return (table);
}

double *Z_law(int a, int b)
{
    double **table = probability(a, b);
    double *law = new double[9];
    int i = 0, j = 0;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++)
            law[i + j] += table[i][j];
    }
    return (law);
}

double *expct_variance(int a, int b)
{
    double *table = new double[6];
    double **prob = probability(a, b);
    double *law = Z_law(a, b);

    for (int i = 0; i < 5; i++) {
        table[0] += ((i + 1) * 10) * prob[i][5];
        table[2] += ((i + 1) * 10) * prob[5][i];
        table[4] += ((i + 2) * 10) * law[i];
    }

    for (int i = 0; i < 5; i++) {
        table[1] += (((i + 1) * 10) - table[0]) * (((i + 1) * 10) - table[0]) * prob[i][5];
        table[3] += (((i + 1) * 10) - table[2]) * (((i + 1) * 10) - table[2]) * prob[5][i];
        if (i < 4)
        table[4] += ((i + 7) * 10) * law[i + 5];
    }

    for (int i = 0; i < 9; i++)
        table[5] += (((i + 2) * 10) - table[4]) * (((i + 2) * 10) - table[4]) * law[i];
    return (table);
}

void unsold(int a, int b)
{
    double **table = probability(a, b);
    double *law = Z_law(a, b);
    double *ex_var = expct_variance(a, b);
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
    std::cout << "\tX=10\tX=20\tX=30\tX=40\tX=50\tY law" << std::endl;

    for (int x = 10, i = 0; i < 6 && x < 70; i++, x += 10) {
        if (i != 5)
            std::cout << "Y=" << x << '\t';
        else if (i == 5)
            std::cout << "X law" << '\t';
        for (int j = 0; j < 6; j++) {
            if (j == 5)
                 std::cout << table[i][j] << std::endl;
            else
                std::cout << table[i][j] << '\t';
        }
    }
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
    std::cout << "z\t20\t30\t40\t50\t60\t70\t80\t90\t100" << std::endl;
    std::cout << "p(Z=z)  ";
    for (int i = 0; i < 9; i++) {
        if (i == 8)
            std::cout << law[i] << std::endl;
        else
            std::cout << law[i] << '\t';
    }
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
    std::cout << std::setprecision(1) <<  std::fixed;
    std::cout << "expected value of X:\t" << ex_var[0] << std::endl;
    std::cout << "variance of X:      \t" << ex_var[1] << std::endl;
    std::cout << "expected value of Y:\t" << ex_var[2] << std::endl;
    std::cout << "variance of Y:      \t" << ex_var[3] << std::endl;
    std::cout << "expected value of Z:\t" << ex_var[4] << std::endl;
    std::cout << "variance of Z:      \t" << ex_var[5] << std::endl;
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
}
