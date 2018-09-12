using System;
using System.Drawing;
using System.Diagnostics;
using System.Windows.Forms;
using System.ComponentModel;
using System.Runtime.InteropServices;
using IronOcr;

namespace TypeRacer_cheat {
    class Program {
        static void Main(string[] args) {
            Run();
            AutoOcr ocr = new AutoOcr();

            string testImage = @"C:/Users/Ben/Desktop/Programming/Examples/C#/TypeRacer cheat/TypeRacer cheat/bin/Debug/Hey.png";

            Image image = Image.FromFile(testImage);

            Console.WriteLine("Reading image...");
            var Results = ocr.Read(image);
            Console.WriteLine("OCR OUTPUT: {0}", Results.Text);

            Console.ReadKey();
        }

        static void Run() {
            Console.WriteLine("Getting chrome processes");
            Process[] ChromeProcs = Process.GetProcessesByName("chrome");

            Console.WriteLine("Testing BringWindowToTop");
            foreach (Process ChromeProc in ChromeProcs) {
                bool Success = BringWindowToTop(ChromeProc.MainWindowHandle);
                if (!Success)
                    Console.WriteLine($"Method fail: {new Win32Exception(Marshal.GetLastWin32Error()).Message}");
                else
                    Console.WriteLine("Method success");
            }
            Console.WriteLine("Finished");
            Console.ReadLine();
        }

        [DllImport("User32.dll")]
        private static extern bool BringWindowToTop(IntPtr hWnd);
    }

    class KeyPress {
        public KeyPress(char key) {

        }
    }

    class Capture {
        public static Image CaptureScreen() {
            Rectangle screenSize = Screen.PrimaryScreen.Bounds;
            Bitmap target = new Bitmap(screenSize.Width, screenSize.Height);
            using (Graphics g = Graphics.FromImage(target)) {
                g.CopyFromScreen(0, 0, 0, 0, new Size(screenSize.Width, screenSize.Height));
            }
            target.Save("screenshot.png");
            return target;
        }
    }
}
