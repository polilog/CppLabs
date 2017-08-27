void integrate (double (*p_func) (double, double, double), double s, double t, double a = 0.4, double b = 1.2, double e = 0.000001);

double sum (double (*p_func) (double, double, double), double s, double t, int n, double a = 0.4, double b = 1.2);

double myfun (double x, double s, double t);