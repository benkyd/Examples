using System;
using System.Collections.Generic;
using System.Drawing;
using Console = Colorful.Console;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RainbowPrint {
    class Program {

        static void Main(string[] args) {

            Console.WriteLine("   ___       __  __               ______       _          ");
            Console.WriteLine("  |_  |     / _|/ _|              | ___ \\     | |        ");
            Console.WriteLine("    | | ___| |_| |_ ___ _ __ _   _| |_/ / ___ | |_        ");
            Console.WriteLine("    | |/ _ \\  _|  _/ _ \\ '__| | | | ___ \\/ _ \\| __|   ");
            Console.WriteLine("/\\__/ /  __/ | | ||  __/ |  | |_| | |_/ / (_) | |_       ");
            Console.WriteLine("\\____/ \\___|_| |_| \\___|_|   \\__, \\____/ \\___/ \\__|");
            Console.WriteLine("                              __/ |                       ");
            Console.WriteLine("                             |___/                        ");
            Console.WriteLine();



            string Logo = 
                "   ___       __  __               ______       _          \n" +
                "  |_  |     / _|/ _|              | ___ \\     | |        \n" +
                "    | | ___| |_| |_ ___ _ __ _   _| |_/ / ___ | |_        \n" +
                "    | |/ _ \\  _|  _/ _ \\ '__| | | | ___ \\/ _ \\| __|   \n" +
                "/\\__/ /  __/ | | ||  __/ |  | |_| | |_/ / (_) | |_       \n" +
                "\\____/ \\___|_| |_| \\___|_|   \\__, \\____/ \\___/ \\__|\n" +
                "                             |___/                        \n";

            char[] JefferyBot = Logo.ToCharArray(); ;
            Random r = new Random();

            int[] col = { 13, 7, 15, 11, 10, 6 };

            for (int i = 0; i < JefferyBot.Length; i++) {
                //Console.Write(JefferyBot[i]);
    
                if (JefferyBot [i] != ' ') {
                    for (int j = 0; j < col.Length; j++) {
                        Console.Write(Convert.ToString(JefferyBot[i]), (ConsoleColor)(col[j]));

                        //Console.ForegroundColor = (ConsoleColor)(col[j]);
                    }
                }
            }

            Console.WriteWithGradient(JefferyBot, Color.Yellow, Color.Fuchsia, 14);

            Console.ReadKey();
        }
    }
}