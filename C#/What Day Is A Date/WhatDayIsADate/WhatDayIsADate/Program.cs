using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WhatDayIsADate
{
    class Program
    {
        static void Main()
        {
            Console.WriteLine("What date would you like to know the day of? Format like dd/mm/yyyy");

            string Date = Console.ReadLine();

            string[] parts = Date.Split('/');
            int Day = int.Parse(parts[0]);
            int Month = int.Parse(parts[1]);
            int Year = int.Parse(parts[2]);

            int Century = Year / 100;
            int Decade = Year % 100;

            int BeforeKeyValue = Decade / 4 + Day;

            int MonthKeyValue = 0;

            if (Month == 01 || Month == 10)
            {
                MonthKeyValue = 1;
            }
            else if (Month == 02 || Month == 03 || Month == 11)
            {
                MonthKeyValue = 4;
            }
            else if (Month == 04 || Month == 07)
            {
                MonthKeyValue = 0;
            }
            else if (Month == 05)
            {
                MonthKeyValue = 2;
            }
            else if (Month == 06)
            {
                MonthKeyValue = 5;
            }
            else if (Month == 08)
            {
                MonthKeyValue = 3;
            }
            else if (Month == 09 || Month == 12)
            {
                MonthKeyValue = 6;
            }


            int AfterKeyValue = BeforeKeyValue + MonthKeyValue;


            if (Month == 1 || Month == 2)
            {
                if (Year % 4 == 0)
                {
                    AfterKeyValue--;
                }
            }

            if (Century == 17)
            {
                AfterKeyValue = AfterKeyValue + 4;
            }
            else if (Century == 18)
            {
                AfterKeyValue = AfterKeyValue + 2;
            }
            else if (Century == 19)
            {
                AfterKeyValue = AfterKeyValue + 0;
            }
            else if (Century == 20)
            {
                AfterKeyValue = AfterKeyValue + 6;
            }

            AfterKeyValue = AfterKeyValue + Decade;

            int Complete = AfterKeyValue / 7;
            string WeekDay = "Null";
            if (Complete == 0)
            {
                WeekDay = "Saturday";
            }
            else if (Complete == 1)
            {
                WeekDay = "Sunday";
            }
            else if (Complete == 2)
            {
                WeekDay = "Monday";
            }
            else if (Complete == 3)
            {
                WeekDay = "Tuseday";
            }
            else if (Complete == 4)
            {
                WeekDay = "Wednesday";
            }
            else if (Complete == 5)
            {
                WeekDay = "Thursday";
            }
            else if (Complete == 6)
            {
                WeekDay = "Friday";
            }

            Console.WriteLine(Day);
            Console.WriteLine(Month);
            Console.WriteLine(Year);
            Console.WriteLine(Century);
            Console.WriteLine(Decade);
            Console.WriteLine(BeforeKeyValue);
            Console.WriteLine(MonthKeyValue);
            Console.WriteLine(AfterKeyValue);
            Console.WriteLine(Complete);
            Console.WriteLine("This date falls on a {0}", WeekDay);

            Console.ReadKey();
        }
    }
}
