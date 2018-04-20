using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Trigonometry
{
    class Program
    {
        static void Main(string[] args)
        {
            TrianglePrint();
            UserInput();
            Console.ReadKey();
        }

        static void TrianglePrint()
        {
            Console.WriteLine("0");
            var height = 20;
            var _base = "";
            for (int i = 0; i < height; i++)
            {
                var line = "|";
                for (int j = i; j > 0; j--)
                {
                    line += " ";
                }
                line += @"\";
                Console.WriteLine(line);
                _base += "-";
            }
            Console.WriteLine(_base);
        }
        static void UserInput()
        {
            Console.WriteLine("HAHSD");
        }
    }
}
