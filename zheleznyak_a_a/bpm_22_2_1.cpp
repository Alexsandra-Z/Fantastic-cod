#include <iostream>
#include <cmath>

int main() {
	double eps = 0.0001;
	double x1 = 0.1;
	double x2 = 1;
	double dx = 0.05;

	for (double x = x1; x <= x2; x += dx) {
		double sum = 0;
		double ch_sum = 1;
		int i = 0;
		while (std::abs(ch_sum) >= eps) {
			ch_sum = std::pow(x, 2 * i + 1) / (2 * i + 1);
			if (i % 2 == 1) {
				ch_sum = -ch_sum;
			}
			if (std::abs(ch_sum) >= eps) {
				sum += ch_sum;
			}
			i += 1;
		}

		std::cout << x << "  " << sum << "\n";
	}
}
