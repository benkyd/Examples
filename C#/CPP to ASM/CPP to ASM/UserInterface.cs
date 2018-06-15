using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Threading.Tasks;

namespace CPP_to_ASM {
    class UserInterface {

        public static string TargetFile { get; set; } = "target.c";
        public static string OutputFile { get; set; } = "output.asm";

        public UserInterface() {
            Console.WriteLine("");

            Console.WriteLine("");

            Console.WriteLine("");

            Console.WriteLine("");
        }

        private bool validateFile() {
            if (!File.Exists(TargetFile)) {
                Console.WriteLine("The target file does not exist");
            }

            return false;
        }
    }
}
