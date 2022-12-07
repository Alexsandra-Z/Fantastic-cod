#include <iosfwd>
#include <limits>

struct Rdec2D {
    double x = 0.0;
    double y = 0.0;
};

struct Rpol2D {
    double r = 0.0;
    double phi = 0.0;
};

const double epsl = std::numeric_limits<double>::epsilon() * 2.0;

std::ostream& operator<<(std::ostream& ostrm, const Rdec2D& vectr);
std::ostream& operator<<(std::ostream& ostrm, const Rpol2D& vectr);

Rdec2D operator-(const Rdec2D& vectr);
Rpol2D operator-(const Rpol2D& vectr);

Rdec2D operator+(const Rdec2D& vectr1, const Rdec2D& vectr2);
Rpol2D operator+(const Rpol2D& vectr1, const Rpol2D& vectr2);

void operator+=(Rdec2D& vectr1, const Rdec2D& vectr2);
void operator+=(Rpol2D& vectr1, const Rpol2D& vectr2);

Rdec2D operator-(const Rdec2D& vectr1, const Rdec2D& vectr2);
Rpol2D operator-(const Rpol2D& vectr1, const Rpol2D& vectr2);

void operator-=(Rdec2D& vectr1, const Rdec2D& vectr2);
void operator-=(Rpol2D& vectr1, const Rpol2D& vectr2);

Rdec2D operator*(const Rdec2D& vectr, const double& scalar);
Rpol2D operator*(const Rpol2D& vectr, const double& scalar);

Rdec2D operator/(const Rdec2D& vectr, const double& scalar);
Rpol2D operator/(const Rpol2D& vectr, const double& scalar);

double Dot(const Rdec2D& vectr1, const Rdec2D& vectr2);
double Dot(const Rpol2D& vectr1, const Rpol2D& vectr2);

double Norm(const Rdec2D& vectr);

Rdec2D ToDec(const Rpol2D& vectr);
Rpol2D ToPol(const Rdec2D& vectr);

double Cor(const Rdec2D& vectr1, const Rdec2D& vectr2);
double Cor(const Rpol2D& vectr1, const Rpol2D& vectr2);

bool operator==(const Rdec2D& vectr1, const Rdec2D& vectr2);
bool operator==(const Rpol2D& vectr1, const Rpol2D& vectr2);

bool operator!=(const Rdec2D& vectr1, const Rdec2D& vectr2);
bool operator!=(const Rpol2D& vectr1, const Rpol2D& vectr2);