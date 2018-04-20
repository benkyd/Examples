using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Feet_To_Inches
{
    class Program
    {
        static void Main(string[] args)
        {
            String Method;
            double convert;
            int done = 1;

            while (done == 1)
                {
                Console.WriteLine("If you would like to convert feet into inches, type feet. If you would like to convert inches to feet, type inches");

                Method = Console.ReadLine();

                if (Method.ToLower() == "feet")
                {
                    Console.WriteLine("How many feet would you like to convert into inches?");
                    convert = double.Parse(Console.ReadLine());

                    double converted = convert * 12.0;

                    Console.WriteLine("{0} feet is {1} inches", convert, String.Format("{0:0.0}", converted));
                    Console.ReadKey();
                }
                if (Method.ToLower() == "inches")
                {
                    Console.WriteLine("How many inches would you like to convert into feet?");
                    convert = double.Parse(Console.ReadLine());

                    double converted = convert / 12.0;

                    Console.WriteLine("{0} inches is {1} feet", convert, String.Format("{0:0.0}", converted));
                    Console.ReadKey();
                }
            }
        }
    }
}

