using System;
using System.Runtime.InteropServices;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DVD_Opener
{
    class Program
    {
        const uint GENERICREAD = 0x80000000;
        const uint OPENEXISTING = 3;
        const uint IOCTL_STORAGE_EJECT_MEDIA = 2967560;
        const int INVALID_HANDLE = -1;

        static void Main()
        {
            start:

            Console.WriteLine("Would you like to open the DVD tray? Y/N");
            string open = Console.ReadLine();

            if (open.ToLower() == "y")
            {
                DVD.Eject(@"\\.\E:");
                goto start;

            }
            else if (open.ToLower() == "n")
            {
                goto start;
            }
            else
            {
                goto start;
            }
        }
    }
}
