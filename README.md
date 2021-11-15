# 202unsold
Statistics for Selling Suit Stock

Steven is a suit-seller in Mississippi. Once a year, he gets rid of his unsold stock, selling separately jackets
and trousers, at $10, $20, $30, $40 and $50. He’d like to know how much each piece of clothing is likely to
yield (expected value and variance).
Steven gave his statistician friend a mission: to deduce from his past results the probability to sell a $x jacket
and $y trousers together. It appears that the probability is defined by the following formula (a and b being
integers greater than 50, depending on the economic climate):

(a − x)(b − y)
(5a − 150)(5b − 150)
Let’s call X, Y and Z, respectively, the random variables that represent “the price of a sold jacket”, “the price
of sold trousers” and “the price of a sold suit”. Given the values of a and b, your software must print:





• an array summing up the joint law of (X, Y ), and the marginal laws of X and Y ,
• an array summing up the law of Z,
• expected values and variances of X, Y and Z.



./202unsold -h
USAGE
./202unsold a b
DESCRIPTION
a constant computed from past results
b constant computed from past results

EXAMPLES
∇ Terminal - + x
∼/B-MAT-400> ./202unsold 60 70
-- --- --- -- --- --- --- --- --- -- --- --- --- --- --- -- --- --- --- --- --- --- -- --- --- --- --- --- -
X =10 X =20 X =30 X =40 X =50 Y law
Y =10 0.100 0.080 0.060 0.040 0.020 0.300
Y =20 0.083 0.067 0.050 0.033 0.017 0.250
Y =30 0.067 0.053 0.040 0.027 0.013 0.200
Y =40 0.050 0.040 0.030 0.020 0.010 0.150
Y =50 0.033 0.027 0.020 0.013 0.007 0.100
X law 0.333 0.267 0.200 0.133 0.067 1.000
-- --- --- -- --- --- --- --- --- -- --- --- --- --- --- -- --- --- --- --- --- --- -- --- --- --- --- --- -
z 20 30 40 50 60 70 80 90 100
p ( Z = z ) 0.100 0.163 0.193 0.193 0.167 0.100 0.053 0.023 0.007
-- --- --- -- --- --- --- --- --- -- --- --- --- --- --- -- --- --- --- --- --- --- -- --- --- --- --- --- -
expected value of X : 23.3
variance of X : 155.6
expected value of Y : 25.0
variance of Y : 175.0
expected value of Z : 48.3
variance of Z : 330.6
-- --- --- -- --- --- --- --- --- -- --- --- --- --- --- -- --- --- --- --- --- --- -- --- --- --- --- --- -
