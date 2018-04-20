using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Guess_random_number
{
    class Program
    {
        static void Main(string[] args)
        {
            Random rnd = new Random();
            int RandomNumber = rnd.Next(1, 100);

            Console.WriteLine("A random number has been generated, you have to guess it. " +
                "Each guess you will be told wheather your guess was higher or lower");

            int guess;
            bool correct = false;
            while (correct == false)
            {
                Console.Write("Your guess:");

                string stringguess = Console.ReadLine();
                try
                {
                    guess = int.Parse(stringguess);
                    Console.WriteLine();

                    if (guess == RandomNumber)
                    {
                        break;
                    }
                    else if (guess < RandomNumber)
                    {
                        Console.WriteLine("The number is greater than your guess");
                    }
                    else if (guess > RandomNumber)
                    {
                        Console.WriteLine("The number is less than your guess");
                    }
                }
                catch (FormatException)
                {
                    Console.WriteLine("{0} is not a number", stringguess);
                }
            }

            Console.WriteLine("Correct, the number was {0}", RandomNumber);
            Console.ReadKey();
        }
    }
}
