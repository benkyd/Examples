using System;
using System.Net.NetworkInformation;


namespace Networking_Tools {
    class Connectivity_Test {
        public bool checkConnection(string host) {
            bool pingable = false;
            Ping pinger = new Ping();
            try {
                PingReply reply = pinger.Send(host);
                pingable = reply.Status == IPStatus.Success;
            } catch (PingException) { }
            return pingable;
        }
    }
}
