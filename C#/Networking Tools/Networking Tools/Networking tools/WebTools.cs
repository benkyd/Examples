using System;

namespace Networking_Tools {
    class WebTools {
        private string hostName { get; set; }
        private string[] inputArray { get; set; }
        private string[] trimmedInputArray { get; set; }

        public WebTools(string[] input, string[] trimmedInput) {
            inputArray = input;
            trimmedInputArray = trimmedInput;
        }

        public string[] WebParser() {
            return new string[0];
        }

        private string ping() {
            return "";
        }

        private string[] redirects() {
            return new string[0];
        }
    }
}
