using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace same_py
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("NUMBER NOW PLS: ");
            int x = int.Parse(Console.ReadLine());

            Console.WriteLine("Your number is: {0}", x);

            if (x == 2)
            {
                Console.WriteLine("X is 2");
            }
            else
            {
                Console.WriteLine("X is not 2");
            }
            Console.ReadKey();
        }
    }
}
