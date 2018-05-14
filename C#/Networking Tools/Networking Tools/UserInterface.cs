using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Networking_Tools {
    class UserInterface {

        private int startWidth;
        private int startHeight;

        public void Load() {
            Console.SetCursorPosition(0, 0);
            startHeight = Console.WindowHeight;
            startWidth = Console.WindowWidth;
            MainMenu();       
        }

        public void MainMenu() {
            Console.WriteLine("Networking Tools by Benjamin Kyd");
            while (true) {
                Console.Write("> ");
                options();
            }
        }

        private void options() {
            var input = Console.ReadLine().Trim();

            string[] parsed = parseInput(input);
            string[] trimmed = trimFirst(parsed);
            string[] response = new string[0];

            switch (parsed[0]) {
                case "":
                    break;

                case "ping":
                    break;

                case "getdns":
                    if (parsed.Length > 1) {
                        DNSTest dns = new DNSTest();
                        dns.HostName = parsed[1];
                        response = dns.GetIPs();
                    } else {
                        response = new string[1];
                        response[0] = "No arguments given";
                    }
                    break;

                default:
                    Console.WriteLine($"Command `{ input }` not recognized");
                    break;
            }

            printArray(response);
        }

        private string[] parseInput(string arr) {
            return arr.ToLower().Split(' ');
        }

        private string[] trimFirst(string[] arr) {
            arr = arr.Where(w => w != arr[0]).ToArray();
            return arr;
        }

        private void printArray(string[] arr) {
            for (int i = 0; i < arr.Length; i++) {
                Console.WriteLine(arr[i]);
            }
        }
    }
}
