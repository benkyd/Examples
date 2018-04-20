using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace How_Long
{
    class Program
    {
        static void Main()
        {
            string Continue;

            object value = DateTime.Now;
            DateTime result = (DateTime)value;
            double Time = double.Parse(result.ToString("HH.mm"));

            System.Console.WriteLine("The time is {0}", Time);

            Console.WriteLine();
            Console.WriteLine("Would you like to know how long it is to a spesific time today? (Y/N)");
            Continue = Console.ReadLine();

            while (Continue.ToLower() == "y") 
            {
                if (Continue.ToLower() == "y")
                {
                    Console.WriteLine("What time would you like to count to? Format it like hh.mm in 24 hour time");

                    double CountTo = double.Parse(Console.ReadLine());
                    double NewTime = (CountTo - Time);

                    double Remainder = NewTime / 60;

                    string split = NewTime.ToString("00.00");
                    string[] parts = split.Split('.');
                    int Hours = int.Parse(parts[0]);
                    int Minutes = int.Parse(parts[1]);

                    if (Hours == 1)
                    {
                        Console.WriteLine("It is {0} hour and {1} minutes", Hours, Minutes);
                    }
                    else
                    {
                        Console.WriteLine("It is {0} hours and {1} minutes", Hours, Minutes);
                    }
                    Console.ReadKey();
                }
                else
                {
                    Console.WriteLine("Why are you here?");
                }
            }
        }
    }
}
