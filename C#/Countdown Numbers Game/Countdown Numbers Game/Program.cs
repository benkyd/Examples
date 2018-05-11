using System;
using System.Diagnostics;

namespace Countdown_Numbers_Game {
    class Program {
        static void Main(string[] args) {

            Console.ForegroundColor = ConsoleColor.Cyan;
            Console.WriteLine("                                888        888                              ");
            Console.WriteLine("                                888        888                              ");
            Console.WriteLine("                                888        888                              ");
            Console.WriteLine(" .d8888b .d88b. 888  88888888b. 888888 .d88888 .d88b. 888  888  88888888b.  ");
            Console.WriteLine("d88P\"   d88\"\"88b888  888888 \"88b888   d88\" 888d88\"\"88b888  888  888888 \"88b ");
            Console.WriteLine("888     888  888888  888888  888888   888  888888  888888  888  888888  888 ");
            Console.WriteLine("Y88b.   Y88..88PY88b 888888  888Y88b. Y88b 888Y88..88PY88b 888 d88P888  888 ");
            Console.WriteLine(" \"Y8888P \"Y88P\"  \"Y88888888  888 \"Y888 \"Y88888 \"Y88P\"  \"Y8888888P\" 888  888 ");
            Console.WriteLine("");
            Console.ForegroundColor = ConsoleColor.White;

            Program p = new Program();
            p.getInput();
        }

        private void getInput() {
            int target = 0;
            int[] inputArray = new int[0];

            bool inputValid = false;
            while (!inputValid) {
                try {
                    Console.Write("Enter a target full number: ");
                    target = int.Parse(Console.ReadLine());
                    inputValid = true;
                } catch {
                    Console.WriteLine("That's not a valid number");
                }
            }

            inputValid = false;
            while (!inputValid) {
                try {
                    Console.Write("Enter an array of whole numbers sepperated by spaces: ");
                    string[] inputStringArray = Console.ReadLine().Trim().Split(' ');

                    inputArray = new int[inputStringArray.Length];

                    for (int i = 0; i < inputStringArray.Length; i++) {
                        inputArray[i] = int.Parse(inputStringArray[i]);
                    }
                    if (inputArray.Length > 11) {
                        throw new Exception();
                    }

                    inputValid = true;
                } catch {
                    Console.WriteLine("An error occured, you may not have formated the array correctly or diddnt use intigers or you had more than 11 indexes.");
                }
            }

            Solver solve = new Solver();
            string output = solve.getSolution(target, inputArray);

            if (output == "false") {
                Console.WriteLine("A soulution could not be found... \nPress any key to exit...");
            } else {
                Console.WriteLine("Solution found: " + output);
                Console.WriteLine("Press any key to exit...");
            }
            Console.ReadKey();
        }



        class Solver {
            public string getSolution(int target, int[] inputArray) {
                inputArray = SortArray(inputArray);

                Console.Write("Sorted Array: ");
                for (int i = 0; i < inputArray.Length; i++) {
                    Console.Write(inputArray[i] + " ");
                }
                Console.WriteLine();



                return makeAllPermutations(inputArray).ToString();
            }

            private int[,] makeAllPermutations(int[] inputArray) {
                Stopwatch s = new Stopwatch();
                s.Start();
                int[,] allPermutations = new int[Factorial(inputArray.Length) - 1, inputArray.Length];

                for (int i = 0; !NextPermutation(inputArray); i++) {
                    for (int j = 0; j < inputArray.Length; j++) {
                        allPermutations[i, j] = inputArray[j];
                    }
                }

                s.Stop();
                Console.WriteLine("All permutations found in: " + s.Elapsed.Milliseconds + "ms");

                PrintArray(allPermutations);

                return allPermutations;
            }

            private bool NextPermutation<T>(T[] elements) where T : IComparable<T> {
                var count = elements.Length;
                var done = true;
                for (var i = count - 1; i > 0; i--) {
                    var curr = elements[i];

                    if (curr.CompareTo(elements[i - 1]) < 0) {
                        continue;
                    }
                    done = false;
                    var prev = elements[i - 1];
                    var currIndex = i;

                    for (var j = i + 1; j < count; j++) {
                        var tmp = elements[j];
                        if (tmp.CompareTo(curr) < 0 && tmp.CompareTo(prev) > 0) {
                            curr = tmp;
                            currIndex = j;
                        }
                    }
                    elements[currIndex] = prev;
                    elements[i - 1] = curr;

                    for (var j = count - 1; j > i; j--, i++) {
                        var tmp = elements[j];
                        elements[j] = elements[i];
                        elements[i] = tmp;
                    }

                    break;
                }
                return done;
            } 

            private int[] SortArray(int[] array) {
                int length = array.Length;
                int temp = array[0];
                for (int i = 0; i < length; i++) {
                    for (int j = i + 1; j < length; j++) {
                        if (array[i] > array[j]) {
                            temp = array[i];
                            array[i] = array[j];
                            array[j] = temp;
                        }
                    }
                }
                return array;
            }

            private long Factorial(int arg) {
                long value = 1;
                for (int i = 2; i <= arg; i++) {
                    value *= i;
                }
                return value;
            }

            private void PrintArray(int[] arr) {
                for (int i = 0; i < arr.Length; i++) {
                    Console.Write(arr[i] + " ");
                }
                Console.WriteLine();
            }

            private void PrintArray(int[,] arr) {
                for (int i = 0; i < arr.GetLength(0); i++) {
                    for (int j = 0; j < arr.GetLength(1); j++) {
                        Console.Write(arr[i, j] + " ");
                    }
                    Console.WriteLine();
                }
            }
        }
    }
}
