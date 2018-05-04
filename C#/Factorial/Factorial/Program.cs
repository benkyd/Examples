using System;
using System.Numerics;
using System.Diagnostics;

namespace Factorial {
    class Program {
        static void Main(string[] args) {
            bool exit = false;
            while (!exit) {
                bool correct = false;
                int find = 0;
                while (!correct) {
                    try {
                        Console.Write("Enter a number to find the factorial of: ");
                        find = int.Parse(Console.ReadLine());
                        correct = true;
                    } catch {
                        Console.WriteLine("That is not a number");
                    }
                }
                Console.WriteLine($"The factorial of { find } is { Factorial(find) }");
                Console.WriteLine("Press any key to exit and enter to try again");
                var response = Console.ReadKey();
                switch (response.Key) {
                    case ConsoleKey.Enter:
                        break;
                    default:
                        exit = true;
                        break;
                }
            }
        }

        static BigInteger Factorial(int arg) {
            Stopwatch t = new Stopwatch(); ;
            t.Start();
            BigInteger value = 1;
            for (int i = 2; i <= arg; i++) {
                value *= i;
            }
            t.Stop();
            Console.WriteLine("Found in {0} ms", t.Elapsed.TotalMilliseconds);
            return value;
        }
    }
}
