using System;
using System.Text.RegularExpressions;
using System.Drawing;
using System.IO.Ports;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace Joystick_Controler {
    class Program {
        static void Main(string[] args) {
            Console.CursorVisible = false;
            while (true) {
                var reader = new ArduinoSerialReader("COM3");
                Console.ReadKey();
            }
        }
    }

    class ArduinoSerialReader {
        private SerialPort serialPort;

        public ArduinoSerialReader(string portName) {
            try {
                serialPort = new SerialPort(portName);

                serialPort.Open();
                serialPort.DataReceived += dataReceived;
            } catch {
                Console.WriteLine("Access to serial port {0} denied...", portName);
            }
        }

        private void dataReceived(object s, SerialDataReceivedEventArgs e) {
            string fromPort = serialPort.ReadLine();

            //Console.SetCursorPosition(0, 0);
            //Console.WriteLine(fromPort);

            int[] XY = parser(fromPort);
            int x = XY[0];
            int y = XY[1];
            int button = XY[2];
            bool b = false;
            if (button == 0) {
                b = true;
                //Console.WriteLine("click");
            } else {
                b = false;
                //Console.WriteLine("     ");
            }

            if (y == -1) {
                y = 0;
            }
            if (x == -1) {
                x = 0;
            }

            MouseTranslator translate = new MouseTranslator(x, y, b);
        }

        private int[] parser(string input) {
            int[] output = new int[3];
            string pattern = @"X:(-?[0-9]+)Y:(-?[0-9]+)B:([0-9]+)";
            input.Trim();

            try {
                Match match = Regex.Match(input, pattern);
                output[0] = int.Parse(match.Groups[1].ToString());
                output[1] = int.Parse(match.Groups[2].ToString());
                output[2] = int.Parse(match.Groups[3].ToString());
            } catch { }

            return output;
        }
    }

    class MouseTranslator {

        private bool mouseDown;

        private int joyX;
        private int joyY;

        public MouseTranslator(int x, int y, bool b) {
            joyX = x;
            joyY = y;


        
            moveMouse();
        }

        private void moveMouse() {
            Cursor.Position = new Point(Cursor.Position.X - joyX, Cursor.Position.Y - joyY);
        }

        private void clickDown() {
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouseDown = true;
        }
        private void clickUp() {
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            mouseDown = false;
        }

        private const UInt32 MOUSEEVENTF_LEFTDOWN = 0x0002;
        private const UInt32 MOUSEEVENTF_LEFTUP = 0x0004;
        [DllImport("user32.dll")]
        private static extern void mouse_event(uint dwFlags, uint dx, uint dy, uint dwData, uint dwExtraInf);
    }
}
