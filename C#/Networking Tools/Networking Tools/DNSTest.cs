using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;

namespace Networking_Tools {
    class DNSTest {
        public string HostName { get; set; }

        public string[] GetIPs() {
            List<string> ipAddresses = new List<string>();
            IPHostEntry iphost = Dns.GetHostEntry(HostName);

            foreach (IPAddress theAddress in iphost.AddressList) {
                if (theAddress.AddressFamily == System.Net.Sockets.AddressFamily.InterNetwork) {
                    ipAddresses.Add(theAddress.ToString());
                }
            }

            return ipAddresses.ToArray();
        }

    }
}
