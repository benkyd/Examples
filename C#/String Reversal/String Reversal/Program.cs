using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace String_Reversal
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter a string to reverse: ");
            string inputstring = Console.ReadLine();

            char[] input = inputstring.ToCharArray();

            Array.Reverse(input);

            string output = new string(input);

            if (output.ToLower() == inputstring.ToLower())
            {
                Console.WriteLine("That is a palendrome");
            }
            Console.WriteLine(output);
            Console.ReadKey();
        }
    }
}
