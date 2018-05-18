using System;
using System.Collections.Generic;
using System.Net;
using System.Net.Sockets;

namespace Networking_Tools {
    class DNSTest {
        private string hostName { get; set; }
        private string[] inputArray { get; set; }
        private string[] trimmedInputArray { get; set; }

        public DNSTest(string[] input, string[] trimmedInput) {
            inputArray = input;
            trimmedInputArray = trimmedInput;
        }

        public string[] DNSParser() {
            switch (inputArray[0]) {
                case "":
                    break;
            }
            return new string[0];
        }

        private string[] GetIPs() {
            List<string> ipAddresses = new List<string>();

            try {
                IPHostEntry iphost = Dns.GetHostEntry(hostName);

                foreach (IPAddress theAddress in iphost.AddressList) {
                    if (theAddress.AddressFamily == AddressFamily.InterNetwork) {
                        ipAddresses.Add(theAddress.ToString());
                    }
                }
            } catch (SocketException) {
                ipAddresses.Add("");
            }
            return ipAddresses.ToArray();
        }

        private string GetDNSEnd() {
            return "";
        }
    }
}
