using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Input;
using System.Drawing;
using System.Diagnostics;
using System.Windows.Forms;
using IronOcr;
using IronOcr.Languages;

namespace TypeRacer_cheat {
    class Program {
        static void Main(string[] args) {
            /* AdvancedOcr ocr = new AdvancedOcr() {
                CleanBackgroundNoise = true,
                EnhanceContrast = true,
                EnhanceResolution = true,
                Language = IronOcr.Languages.English.OcrLanguagePack,
                Strategy = IronOcr.AdvancedOcr.OcrStrategy.Advanced,
                ColorSpace = AdvancedOcr.OcrColorSpace.Color,
                DetectWhiteTextOnDarkBackgrounds = true,
                InputImageType = AdvancedOcr.InputTypes.AutoDetect,
                RotateAndStraighten = true,
                ReadBarCodes = true,
                ColorDepth = 4
            }; */

            AutoOcr ocr = new AutoOcr();

            string testImage = @"C:/Users/Ben/Desktop/Programming/Examples/C#/TypeRacer cheat/TypeRacer cheat/bin/Debug/Hey.png";

            Image image = Image.FromFile(testImage);

            Console.WriteLine("Reading image...");
            var Results = ocr.Read(image);
            Console.WriteLine("OCR OUTPUT: {0}", Results.Text);
            Console.ReadKey();
        }

        static void run() {
            Process[] procs = Process.GetProcessesByName("chrome");

            foreach (Process process in procs) {
                Console.WriteLine(process);
            }

            if (procs.Length > 0) {
                Console.WriteLine("Bringing chrome forward");
                var handle = procs[0].MainWindowHandle;
                Console.WriteLine(SetForegroundWindow(handle));
                Console.WriteLine(BringWindowToTop(handle));
                Console.WriteLine(ShowWindow(handle, 9));

                Console.WriteLine("Capturing screen");
                Capture.CaptureScreen();
            } else {
                Console.WriteLine("Could not find chrome...");
            }
            Console.ReadKey();
        }

        [DllImport("User32.dll")]
        private static extern bool BringWindowToTop(IntPtr hWnd);
        [DllImport("User32.dll")]
        private static extern bool ShowWindow(IntPtr handle, int nCmdShow);
        [DllImport("user32.dll")]
        private static extern bool SetForegroundWindow(IntPtr hWnd);
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
