using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hypotenuse
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("This program calculates the hypotenuse of a triangle");
            Console.WriteLine("Using the leingths of the other 2 sides");

            Console.WriteLine("a:");
            double a = double.Parse(Console.ReadLine());

            Console.WriteLine("b:");
            double b = double.Parse(Console.ReadLine());

            double a2 = Math.Pow(a, 2);
            double b2 = Math.Pow(b, 2);

            double c2 = a2 + b2;

            double c = Math.Sqrt(c2);

            Console.WriteLine("The leingth of the hypotenuse is {0}", c);
            Console.ReadKey();
        }
    }
}
