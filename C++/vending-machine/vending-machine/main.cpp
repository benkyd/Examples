#include "common.h"
#include "user.h"
#include "machine.h"
#include "item.h"

void printArr(char arr[][5], int rows) {

	int cols = sizeof(arr[0]) / sizeof(arr[0][0]);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}

	// std::cout << rows << " " << cols << std::endl;
}

int main() {
	char arr[10][5] = {
	{ '1','2','3','4','1' },
	{ '1','2','3','4','2' },
	{ '1','2','3','4','3' },
	{ '1','2','3','4','4' },
	{ '1','2','3','4','5' },
	{ '1','2','3','4','6' },
	{ '1','2','3','4','7' },
	{ '1','2','3','4','8' },
	{ '1','2','3','4','9' },
	{ '1','2','3','4','0' }
	};

	printArr(arr, 10);

	while (true) { }
}
