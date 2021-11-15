
#ifndef UNSOLD_HPP_
#define UNSOLD_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <iomanip>
#include <list>

void usage();

struct seller
{
    int x;
    int y;
};


/*====== ERROR HANDLING ======*/
int check_isdigit(int ac, char **av);
int limit_ab(int ac, char **av);
/*================================*/

/*====== JOINT LAW OF (X, Y) && MARGINAL LAWS OF X AND Y ======*/
double **probability(int a, int b);
/*================================*/

/*====== THE LAW OF Z ======*/
double *Z_law(int a, int b);
/*================================*/

/*====== EXPECTED VALUES AND VARIANCES OF X, Y AND Z ======*/
double *expct_variance(int a, int b);
/*================================*/

void unsold(int a, int b);
int main(int ac, char **av);









#endif
