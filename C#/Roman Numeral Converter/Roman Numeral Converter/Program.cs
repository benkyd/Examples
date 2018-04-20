using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Roman_Numeral_Converter
{
    class Program
    {
        static void Main()
        {
            bool startagain = true;
            while (startagain == true)
            {
                Console.WriteLine("Would you like to convert to Roman Numerals from Intigers or from Intigers to Roman Numerals");
                Console.WriteLine("(R)oman Numerals to Intiger");
                Console.WriteLine("(I)ntiger to Roman Numerals");

                var response = Console.ReadKey();
                Console.WriteLine();
                switch (response.KeyChar)
                {
                    case 'R':
                    case 'r':
                        RNtoInt();
                        break;
                    case 'I':
                    case 'i':
                        InttoRN();
                        break;
                }

                Console.Clear();
                Console.WriteLine("You have finished, would you like to do it again? Y/N");

                var retry = Console.ReadKey();
                Console.WriteLine();
                switch (retry.KeyChar)
                {
                    case 'Y':
                    case 'y':
                        startagain = true;
                        break;
                    case 'N':
                    case 'n':
                        startagain = false;
                        break;
                }
                Console.Clear();
            }
        }
        static void RNtoInt()
        {
            Console.Clear();
            Console.WriteLine("You have chosen Roman Numerals to Intigers");
            Console.ReadKey();
            return;
        }

        static void InttoRN()
        {
            Console.Clear();
            Console.WriteLine("You have chosen Intigers to Roman Numerals");
            Console.ReadKey();
            return;
        }
    }
}
