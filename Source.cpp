#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
	int n = 1986;
	int numar[7] = { 1, 5, 10, 50, 100, 500, 1000 };
	char litere[8] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M', '\0' };
	int cifra;
	int ordin = 0;
	char N[100];
	int n_copy = n;
	int i;


	while ()
		while (n != 0) {
			cifra = n_copy % 10;
			n_copy = n_copy / 10;

			ordin++;
		}

	cifra = cifra * pow(10, ordin);
	for (i = 2 * ordin; i < 2 * ordin + 2; i++) {
		if (cifra == numar[i]) {
			strcat(N, litere[i]);
			break;
		}
		else if (cifra == numar[i] - 1) {
			strcat(N, "I");
			strcat(N, litere[i]);
		}
	}






	printf("%s", N);

	return 0;
}