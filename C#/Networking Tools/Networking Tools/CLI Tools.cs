using System;
using System.Linq;

namespace Networking_Tools {
    class CLI_Tools {
        public static string[] ParseInput(string arr) => arr.ToLower().Split(' ');

        public static string[] TrimFirst(string[] arr) => arr.Where(w => w != arr[0]).ToArray();

        public static void PrintArray(string[] arr) {
            for (int i = 0; i < arr.Length; i++) {
                Console.WriteLine(arr[i]);
            }
        }
    }
}
