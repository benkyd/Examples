using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Letter_By_Letter
{
    class Program
    {
        static void Main()
        {
            Console.Write("What would you like to type out: ");
            string input = Console.ReadLine();

            var x = new Program();
            x.WriteLine(input);

            Console.ReadKey();
        }

        private void WriteLine(string input)
        {
            Console.WriteLine();

            for (int i = 0; i < input.Length; i++)
            {
                Console.Write(input[i]);
                Random rnd = new Random();
                Thread.Sleep(rnd.Next(20, 120));
            }
        }
    }
}