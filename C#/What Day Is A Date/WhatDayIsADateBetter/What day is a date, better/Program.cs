using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace What_day_is_a_date__better
{
    class Program
    {
        static void Main()
        {
            Console.WriteLine("What date would you like to know the day of? Format it like yyyy, mm, dd");
            long date = long.Parse(Console.ReadLine());
            DateTime dateValue = new DateTime(2018, 12, 12);
            Console.WriteLine(dateValue.ToString("dddd"));
            Console.ReadKey();
        }
    }
}
