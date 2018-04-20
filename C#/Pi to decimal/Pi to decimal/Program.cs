using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pi_to_decimal
{
    class Program
    {
        static void Main(string[] args)
        {
            double pi = Math.PI;
            Console.WriteLine("How many decimal places would you like pi to?");
            string DecimalNumber = Console.ReadLine();
            pi.ToString({"N{0}"};, DecimalNumber);

        }
    }
}
