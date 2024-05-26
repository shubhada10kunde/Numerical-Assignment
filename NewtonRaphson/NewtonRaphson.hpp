class RootFinding
{
public:
    // int iteration = 0;
    double x0 = 0;
    double previous;
    double ToL = 0.0001;
    double root;
    RootFinding();
    double f(double);
    double f_dash(double);
    double NewtonRaphson();

    // ~NewtonRaphson();
};
