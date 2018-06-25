using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

namespace FileLister {
    class Program {
        static void Main(string[] args) {
            StreamReader reader;
            string Path = "";
            do {
                Console.Write("Insert Path : ");
                Path = Console.ReadLine();
            } while (!Directory.Exists(Path));
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine("Successfully navigated to {0} {1}", Path, "\n\n");
            Console.ForegroundColor = ConsoleColor.White;

            Console.WriteLine("Insert Type to search for \n" +
                              "0 : Files\n" +
                              "1 : Folders\n"
                              );
            bool completed = false;

            Console.Write("\n\n\n\n\n");

            do {
                string Input = Console.ReadLine();
                switch (Input) {
                    case "0":
                        string[] Files = Directory.GetFiles(Path);
                        foreach (string File in Files) {
                            Console.WriteLine(File);
                            Thread.Sleep(50);
                        }
                        completed = true;
                        break;
                    case "1":
                        string[] Dirs = Directory.GetDirectories(Path);
                        foreach (string Dir in Dirs) {
                            Console.WriteLine(Dir);
                            Thread.Sleep(50);
                        }
                        completed = true;
                        break;
                    default:
                        break;
                }
            } while (!completed);

            Console.ReadKey();
        }
    }
}