#include <iostream>
#include <cstdlib> // malloc
#include <string>

// TO CLARIFY FOR ANYONE READING THIS
// THIS CODE ISNT WRITTEN SERIOUSLY AND
// IS INTENTIONALLY AWFUL, THAT BEING
// SAID, ENJOY :)

// Returns ammount of double matches, if there's 3 in a row it will return -1
int matchesInRowOfThree(int first, int second, int third) {

	// Check if all of the numbers are the same, if so then it will return
	// -1, indicating that all of the numbers were the same 
	if (first == second && second == third)
		return -1;

	if (first == second || second == third)
		return 1;

	// If all else fails, there was no matches, so it will return 0
	return 0;
}


// Returns ammount of double matches in a row of 2
int matchesInRowOfTwo(int first, int second) {

	// Check if all of the numbers are the same, if so then it will return
	// 1, indicating that all of the numbers were the same and there was 1 match
	if (first == second)
		return 1;

	// If all else fails, there was no matches, so it will return 0
	return 0;
}

int main(int theAmmountOfArgumentsThatWillBePassedInTheArgumentVectorThatProcedesThis, char** argumentVectorThatIsInputtedIntoTheProgramFromTheOSsCommandLineArguments) {
	// Firstly announce to the user that numbers are expected to be inputted and provide them a format to input said numbers in
	std::cout << "Enter 8 numbers such like '10 12 1 3 4 4 4 1': ";

	// Allocate the array that the numbers will be stored in
	// TODO: Find a more efficient way to allocate an array
	int* inputArray = (int*)malloc(sizeof(int) * 9);

	// Wait for the users formatted input and then store in the inputArray
	std::cin >> inputArray[0] >> inputArray[1] >> inputArray[2] >> inputArray[3] >> inputArray[4]
		>> inputArray[5] >> inputArray[6] >> inputArray[7] >> inputArray[8];

	// End the line for consistant formatting
	std::cout << std::endl << std::endl;

	int numberOfTriplets = 0;
	int numberOfDoubles = 0;

	// Check the horizontal rows for matches by using the 2 functions defined above
	int matchesOnTheFirstHorizontalRow  = matchesInRowOfThree(inputArray[0], inputArray[1], inputArray[2]);
	int matchesOnTheSecondHorizontalRow = matchesInRowOfThree(inputArray[3], inputArray[4], inputArray[5]);
	int matchesOnTheThirdHorizontalRow  = matchesInRowOfThree(inputArray[6], inputArray[7], inputArray[8]);

	if (matchesOnTheFirstHorizontalRow  == -1) numberOfTriplets = numberOfTriplets + 1;
	if (matchesOnTheSecondHorizontalRow == -1) numberOfTriplets = numberOfTriplets + 1;
	if (matchesOnTheThirdHorizontalRow  == -1) numberOfTriplets = numberOfTriplets + 1;

	if (matchesOnTheFirstHorizontalRow  == 1) numberOfDoubles = numberOfDoubles + 1;
	if (matchesOnTheSecondHorizontalRow == 1) numberOfDoubles = numberOfDoubles + 1;
	if (matchesOnTheThirdHorizontalRow  == 1) numberOfDoubles = numberOfDoubles + 1;

	// Check the vertical columns (but to keep consistency, rows)
	int matchesOnTheFirstVerticalRow   = matchesInRowOfThree(inputArray[0], inputArray[3], inputArray[6]);
	int matchesOnTheSecondVerticalRow  = matchesInRowOfThree(inputArray[1], inputArray[4], inputArray[7]);
	int matchesOnTheThirdVerticalRow   = matchesInRowOfThree(inputArray[2], inputArray[5], inputArray[8]);

	if (matchesOnTheFirstVerticalRow   == -1) numberOfTriplets = numberOfTriplets + 1;
	if (matchesOnTheSecondVerticalRow  == -1) numberOfTriplets = numberOfTriplets + 1;
	if (matchesOnTheThirdVerticalRow   == -1) numberOfTriplets = numberOfTriplets + 1;

	if (matchesOnTheFirstVerticalRow   == 1) numberOfDoubles = numberOfDoubles + 1;
	if (matchesOnTheSecondVerticalRow  == 1) numberOfDoubles = numberOfDoubles + 1;
	if (matchesOnTheThirdVerticalRow   == 1) numberOfDoubles = numberOfDoubles + 1;

	// Check the big 3 long diagonal rows
	int matchesOnRightHandUpLongDiagonal = matchesInRowOfThree(inputArray[6], inputArray[4], inputArray[2]);
	int matchesOnLeftHandUpLongDiagonal  = matchesInRowOfThree(inputArray[8], inputArray[4], inputArray[0]);

	if (matchesOnRightHandUpLongDiagonal == -1) numberOfTriplets = numberOfTriplets + 1;
	if (matchesOnLeftHandUpLongDiagonal  == -1) numberOfTriplets = numberOfTriplets + 1;

	if (matchesOnRightHandUpLongDiagonal == 1) numberOfDoubles = numberOfDoubles + 1;
	if (matchesOnLeftHandUpLongDiagonal  == 1) numberOfDoubles = numberOfDoubles + 1;

	// Check the 4 2 long diagonal rows
	int matchesOnRightHandBottomUpDiagonal = matchesInRowOfTwo(inputArray[7], inputArray[5]);
	int matchesOnLeftHandBottomUpDiagonal  = matchesInRowOfTwo(inputArray[7], inputArray[3]);
	int matchesOnRightHandTopDownDiagonal  = matchesInRowOfTwo(inputArray[1], inputArray[5]);
	int matchesOnLeftHandTopDownDiagonal   = matchesInRowOfTwo(inputArray[1], inputArray[3]);

	numberOfDoubles = numberOfDoubles + matchesOnRightHandBottomUpDiagonal;
	numberOfDoubles = numberOfDoubles + matchesOnLeftHandBottomUpDiagonal;
	numberOfDoubles = numberOfDoubles + matchesOnRightHandTopDownDiagonal;
	numberOfDoubles = numberOfDoubles + matchesOnLeftHandTopDownDiagonal;

	// Output the correct calculations to the user
	std::cout << "Triplets=" << numberOfTriplets << " Doubles=" << numberOfDoubles << std::endl;
}
