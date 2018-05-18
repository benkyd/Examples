using System;
using System.Collections.Generic;
using System.Threading;

namespace Networking_Tools {
    class UserInterface {

        private int startWidth { get; set; }
        private int startHeight { get; set; }

        public List<string> DNSTools;
        public List<string> WebTools;

        public void Load() {

            DNSTools = new List<string>() {
                "getips",
                "getdnsend"
            };

            WebTools = new List<string>() {
                "ping",
                "redirects"
            };

            Console.SetCursorPosition(0, 0);
            startHeight = Console.WindowHeight;
            startWidth = Console.WindowWidth;
            MainMenu();       
        }

        public void MainMenu() {
            Console.Clear();
            Console.WriteLine("Networking Tools by Benjamin Kyd");
            Connectivity_Test test = new Connectivity_Test();
            while (true) {
                if (test.checkConnection("www.plane000.co.uk")) {
                    Console.Write("> ");
                    getInput();
                } else {
                    Console.WriteLine("Connection failed... Attepting to reconnect...");
                    Thread.Sleep(10000);
                    MainMenu();
                }
            }
        }

        private void getInput() { 
            CLI_Tools cli = new CLI_Tools();

            var input = Console.ReadLine().Trim();

            string[] parsed = cli.ParseInput(input);
            string[] trimmed = cli.TrimFirst(parsed);
            string[] response = new string[0];

            switch (parsed[0]) {
                case "":
                    break;

                case "ping":
                    WebTools ping = new WebTools(parsed, trimmed);
                    response = ping.WebParser();
                    break;

                case "getdns":
                    DNSTest getDns = new DNSTest(parsed, trimmed);
                    response = getDns.DNSParser();
                    break;

                case "getdnsendpoint":
                    DNSTest endPoint = new DNSTest(parsed, trimmed);
                    response = endPoint.DNSParser();
                    break;

                default:
                    Console.WriteLine($"Command `{ input }` not recognized");
                    break;
            }

            cli.PrintArray(response);
        }
    }
}
