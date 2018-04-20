using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp3
{
    class Program
    {
        static void Main(string[] args)
        {
            int x = 0;
            while (x <= 10)
            {
                Console.WriteLine("{0}", x);
                x++;
            }
            Console.ReadKey();
        }
    }
}
