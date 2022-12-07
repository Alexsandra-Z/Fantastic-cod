#define _USE_MATH_DEFINES
#include "vectors.hpp"
#include <iostream>
#include <cmath>
#include <limits>

std::ostream& operator<<(std::ostream& ostrm, const Rdec2D& vectr) {
    return ostrm << '[' << vectr.x << "; " << vectr.y << ']';
}

std::ostream& operator<<(std::ostream& ostrm, const Rpol2D& vectr) {
    return ostrm << '(' << vectr.r << "; " << vectr.phi << ')';
}

Rdec2D operator-(const Rdec2D& vectr) {
    return { -vectr.x, -vectr.y };
}

Rpol2D operator-(const Rpol2D& vectr) {
    if (vectr.phi >= M_PI) {
        return { vectr.r, vectr.phi - M_PI };
    }
    else {
        return { vectr.r, vectr.phi + M_PI };
    }
}

Rdec2D operator+(const Rdec2D& vectr1, const Rdec2D& vectr2) {
    return { vectr1.x + vectr2.x, vectr1.y + vectr2.y };
}

Rpol2D operator+(const Rpol2D& vectr1, const Rpol2D& vectr2) {
    Rdec2D vectr3 = ToDec(vectr1);
    Rdec2D vectr4 = ToDec(vectr2);
    return ToPol({ vectr3.x + vectr4.x, vectr3.y + vectr4.y });
}

void operator+=(Rdec2D& vectr1, const Rdec2D& vectr2) {
    vectr1 = vectr1 + vectr2;
}

void operator+=(Rpol2D& vectr1, const Rpol2D& vectr2) {
    Rdec2D vectr3 = ToDec(vectr1);
    Rdec2D vectr4 = ToDec(vectr2);
    vectr3 = vectr3 + vectr4;
    vectr1 = ToPol(vectr3);
}

Rdec2D operator-(const Rdec2D& vectr1, const Rdec2D& vectr2) {
    return { vectr1.x - vectr2.x, vectr1.y - vectr2.y };
}

Rpol2D operator-(const Rpol2D& vectr1, const Rpol2D& vectr2) {
    Rdec2D vectr3 = ToDec(vectr1);
    Rdec2D vectr4 = ToDec(vectr2);
    return ToPol({ vectr3.x - vectr4.x, vectr3.y - vectr4.y });
}

void operator-=(Rdec2D& vectr1, const Rdec2D& vectr2) {
    vectr1 = vectr1 - vectr2;
}

void operator-=(Rpol2D& vectr1, const Rpol2D& vectr2) {
    Rdec2D vectr3 = ToDec(vectr1);
    Rdec2D vectr4 = ToDec(vectr2);
    vectr3 = vectr3 - vectr4;
    vectr1 = ToPol(vectr3);
}

Rdec2D operator*(const Rdec2D& vectr, const double& scalar) {
    return { vectr.x * scalar, vectr.y * scalar };
}

Rpol2D operator*(const Rpol2D& vectr, const double& scalar) {
    return { vectr.r * scalar, vectr.phi };
}

Rdec2D operator/(const Rdec2D& vectr, const double& scalar) {
    return { vectr.x / scalar, vectr.y / scalar };
}

Rpol2D operator/(const Rpol2D& vectr, const double& scalar) {
    return { vectr.r / scalar, vectr.phi };
}

double Dot(const Rdec2D& vectr1, const Rdec2D& vectr2) {
    return vectr1.x * vectr2.x + vectr1.y * vectr2.y;
}

double Dot(const Rpol2D& vectr1, const Rpol2D& vectr2) {
    return (vectr1.r * vectr2.r * std::cos(std::abs(vectr1.phi - vectr2.phi)));
}

double Norm(const Rdec2D& vectr) {
    return sqrt(Dot(vectr, vectr));
}

Rdec2D ToDec(const Rpol2D& vectr) {
    return { vectr.r * std::cos(vectr.phi), vectr.r * std::sin(vectr.phi) };
}

Rpol2D ToPol(const Rdec2D& vectr) {
    if (vectr.y > 0) {
        return { Norm(vectr), std::acos(vectr.x / Norm(vectr)) };
    }
    else {
        return { Norm(vectr), 2 * M_PI - std::acos(vectr.x / Norm(vectr)) };
    }
}

double Cor(const Rdec2D& vectr1, const Rdec2D& vectr2) {
    return (acos(Dot(vectr1, vectr2) / (Norm(vectr1) * Norm(vectr2))));
}

double Cor(const Rpol2D& vectr1, const Rpol2D& vectr2) {
    return (std::min(std::abs(vectr1.phi - vectr2.phi), std::abs(vectr1.phi - vectr2.phi + 2 * M_PI)));
}

bool operator==(const Rdec2D& vectr1, const Rdec2D& vectr2) {
    return ((std::abs(vectr1.x - vectr2.x) < epsl) && (std::abs(vectr1.y - vectr2.y) < epsl));
}

bool operator!=(const Rdec2D& vectr1, const Rdec2D& vectr2) {
    return !((std::abs(vectr1.x - vectr2.x) < epsl) && (std::abs(vectr1.y - vectr2.y) < epsl));
}

bool operator==(const Rpol2D& vectr1, const Rpol2D& vectr2) {
    return ((std::abs(vectr1.r - vectr2.r) < epsl) && (std::abs(vectr1.phi - vectr2.phi) < epsl));
}

bool operator!=(const Rpol2D& vectr1, const Rpol2D& vectr2) {
    return !((std::abs(vectr1.r - vectr2.r) < epsl) && (std::abs(vectr1.phi - vectr2.phi) < epsl));
}