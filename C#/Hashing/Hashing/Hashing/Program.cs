using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Security.Cryptography;


namespace Hashing
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("What string would you like to hash?");
            string inputString = Console.ReadLine();


            HashAlgorithm algorithm = SHA256.Create();
            byte[] hash = algorithm.ComputeHash(Encoding.UTF8.GetBytes(inputString));

            Console.WriteLine(Byte[0]);
            Console.ReadKey();
        }
    }
}
