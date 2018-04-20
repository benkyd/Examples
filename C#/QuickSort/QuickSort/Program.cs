using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace QuickSort
{
    class Program
    {
        static void Main()
        {
            Console.BackgroundColor = ConsoleColor.Black;
            Console.ForegroundColor = ConsoleColor.White;

            string[] sortstring = null;
            bool convertsuccess = false;
            while (convertsuccess == false)
            {
                Console.Write("Set of values to sort, separated by spaces: ");

                try
                {
                    sortstring = Console.ReadLine().Split(' ');
                    break;
                }
                catch (FormatException)
                {
                    Console.WriteLine("The set of values was not formated correctly");
                }
            }



        }
    }
}
