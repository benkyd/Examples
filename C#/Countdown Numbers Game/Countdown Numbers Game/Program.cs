using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

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
                    string inputString = Console.ReadLine();
                    string[] inputStringArray = inputString.Split(' ');
                    inputArray = new int[inputStringArray.Length];
                    for (int i = 0; i < inputStringArray.Length; i++) {
                        inputArray[i] = int.Parse(inputStringArray[i]);
                    }
                    inputValid = true;
                } catch {
                    Console.WriteLine("An error occured, you may not have formated the array correctly or diddnt use intigers");
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

                if (!isPossible(target, inputArray)) {
                    return "false";
                }

                return findMethod(target, inputArray);
            }

            private bool isPossible(int target, int[] inputArray) {
                for (int i = 1; i < inputArray.Length; i++) {
                    if (inputArray[i] + inputArray[i-1] == target) {
                        return true;
                    }
                }

                return false;
            }

            private string findMethod(int target, int[] inputArray) {
                for (int i = 1; i < inputArray.Length; i++) {
                    if (inputArray[i] + inputArray[i - 1] == target) {
                        return inputArray[i] + " + " + inputArray[i-1] + " = " + target;
                    }
                }
                return " ";
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
        }
    }
}
