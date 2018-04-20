using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SimpleSort
{
    class Program
    {
        static void Main()
        {
            Console.BackgroundColor = ConsoleColor.Black;
            Console.ForegroundColor = ConsoleColor.White;

            string[] numberstring = Console.ReadLine().Split(' '); ;
            int[] number = null;
            bool convertsuccess = false;
            while (convertsuccess == false)
            {
                Console.Write("Set of values to sort, separated by spaces: ");

                try
                {
                    number = int.Parse(numberstring);
                }

                catch (FormatException)
                {
                    Console.WriteLine("The set of values was not formated correctly");
                }
                catch (ArgumentOutOfRangeException)
                {
                    Console.WriteLine("The set of values was not formated correctly");
                }
            }

            bool flag = true;
            int temp;
            int numLength = number.Length;

            //sorting an array
            for (int i = 1; (i <= (numLength - 1)) && flag; i++)
            {
                flag = false;
                for (int j = 0; j < (numLength - 1); j++)
                {
                    if (number[j + 1] > number[j])
                    {
                        temp = number[j];
                        number[j] = number[j + 1];
                        number[j + 1] = temp;
                        flag = true;
                    }
                }
            }

            //Sorted array
            foreach (int num in number)
            {
                Console.Write("\t {0}", num);
            }
            Console.Read();

        }
    }
}
