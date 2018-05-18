using System;
using System.Linq;

namespace Networking_Tools {
    class CLI_Tools {
        public string[] ParseInput(string arr) => arr.ToLower().Split(' ');

        public string[] TrimFirst(string[] arr) => arr.Where(w => w != arr[0]).ToArray();

        public void PrintArray(string[] arr) {
            for (int i = 0; i < arr.Length; i++) {
                Console.WriteLine(arr[i]);
            }
        }
    }
}
