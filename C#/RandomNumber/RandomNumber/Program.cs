using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RandomNumber
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Between what 2 numbers would you like the random number?");
            Console.WriteLine("First number:");
            int Paramiter1 = int.Parse(Console.ReadLine());
            Console.WriteLine("Seccond number:");
            int Paramiter2 = int.Parse(Console.ReadLine());

            Random rnd = new Random();
            int Random = rnd.Next(Paramiter1, Paramiter2);

            Console.WriteLine("Think of a number between {0} and {1}", Paramiter1, Paramiter2);

            int ThinkOfANumber = int.Parse(Console.ReadLine());

            Console.WriteLine("The random number is {0}", Random);

            if (ThinkOfANumber == Random)
            {
                Console.WriteLine("You got it!");
            }
            else
            {
                Console.WriteLine("You diddnt get it");
            }
            Console.ReadKey();
        }
    }
}
