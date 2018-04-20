using System;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

//longest long = 9223372036854775807

namespace Prime
{
    class Program
    {
        static void Main()
        {

            var a = new Program();
            long num = 100000000000000000;
            Stopwatch time = new Stopwatch();
            time.Start();


            while (num >= 0)
            {
                if (a.IsPrime(num))
                {
                    Console.WriteLine(num + " is a prime in: " + time.ElapsedMilliseconds + "ms");

                    try
                    {
                        File.AppendAllText("Pr1mes.txt", num + " ");
                    }
                    catch (IOException)
                    {
                        Console.WriteLine("Could not write to file, it is in use by another program");
                    }

                    time.Restart();

                    try
                    {
                        num++;
                    }
                    catch (ArgumentOutOfRangeException)
                    {
                        Console.WriteLine("Too long to be stored in a long intiger");
                        Console.WriteLine("Press enter to continue");
                        Console.ReadKey();
                        Environment.Exit(1123);
                    }
                }
                else
                {
                    try
                    {
                        num++;
                    }
                    catch (ArgumentOutOfRangeException)
                    {
                        Console.WriteLine("Too long to be stored in a long intiger");
                        Console.WriteLine("Press enter to continue");
                        Console.ReadKey();
                        Environment.Exit(1234);
                    }
                }
            }
        }

        private bool IsPrime(long number)
        {
            if ((number & 1) == 0)
            {
                return (number == 2);
            }

            int limit = (int)Math.Sqrt(number);

            for (long i = 3; i <= limit; i += 2)
            {
                if ((number % i) == 0)
                {
                    return false;
                }
            }
            return true;
        }
    }
}
