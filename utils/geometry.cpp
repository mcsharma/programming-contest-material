iint collinear(int x1, int y1, int x2, int y2, int x3, int y3) {
    // Calculation the area of
    // triangle. We have skipped
    // multiplication with 0.5
    // to avoid floating point
    // computations
    int a = x1 * (y2 - y3) +
            x2 * (y3 - y1) +
            x3 * (y1 - y2);
  
    return a == 0;
}
  
pair<double, double> findCircle(int x1, int y1, int x2, int y2, int x3, int y3) {
    double x12 = x1 - x2, x13 = x1 - x3, y12 = y1 - y2, y13 = y1 - y3;
    double y31 = y3 - y1, y21 = y2 - y1, x31 = x3 - x1, x21 = x2 - x1;
    double sx13 = x1*x1 - x3*x3, sy13 = y1*y1 - y3*y3;
    double sx21 = x2*x2 - x1*x1, sy21 = y2*y2 - y1*y1;
    double f = (sx13 * x12 + sy13 * x12 + sx21 * x13 + sy21 * x13) / (2.0 * (y31 * x12 - y21 * x13));
    double g = (sx13 * y12 + sy13 * y12 + sx21 * y13 + sy21 * y13) / (2.0 * (x31 * y12 - x21 * y13));
    // eqn of circle be x^2 + y^2 + 2*g*x + 2*f*y + c = 0
    // where centre is (h = -g, k = -f) and radius r
    // as r^2 = h^2 + k^2 - c
    return {-g, -f};
}

double distance(pair<double, double> p1, pair<double, double> p2) {
    return sqrt((p1.XX-p2.XX)*(p1.XX-p2.XX) + (p1.YY-p2.YY)*(p1.YY-p2.YY));
}

