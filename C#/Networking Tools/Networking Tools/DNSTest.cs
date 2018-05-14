using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;

namespace Networking_Tools {
    class DNSTest {
        public string HostName { get; set; }

        public string[] GetIPs() {
            List<string> ipAddresses = new List<string>();

            try {
                IPHostEntry iphost = Dns.GetHostEntry(HostName);

                foreach (IPAddress theAddress in iphost.AddressList) {
                    if (theAddress.AddressFamily == System.Net.Sockets.AddressFamily.InterNetwork) {
                        ipAddresses.Add(theAddress.ToString());
                    }
                }
            } catch (SocketException) {
                ipAddresses.Add("");
            }
            return ipAddresses.ToArray();
        }
    }
}
