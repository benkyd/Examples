using System;
using System.Threading;

namespace _10_PRINT {
    class Program {
        static void Main() {
            Random rnd = new Random();
            string forward = "/";
            string backward = "\\";

            while (true) {
                int next = rnd.Next(0, 2);
                if (next == 1) {
                    Console.Write(forward);
                } else {
                    Console.Write(backward);
                }
                Thread.Sleep(10);
            }
        }
    }
}
