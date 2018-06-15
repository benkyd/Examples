using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Payload {
    class Config {
        public static string InstallFolder { get; set; } = "C:\\LostDir";
        public static string InstallPath { get; set; } = InstallFolder + "\\payload.exe";
    }
}
