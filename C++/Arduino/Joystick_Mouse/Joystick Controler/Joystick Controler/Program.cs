using System;
using System.Text.RegularExpressions;
using System.Drawing;
using System.IO.Ports;
using System.Windows.Forms;

namespace Joystick_Controler {
    class Program {
        static void Main(string[] args) {
            Console.CursorVisible = false;
            var reader = new ArduinoSerialReader("COM3");

            Console.ReadKey();
        }
    }

    class ArduinoSerialReader {
        private SerialPort serialPort;

        public ArduinoSerialReader(string portName) {
            try {
                serialPort = new SerialPort(portName);

                serialPort.Open();
                serialPort.DataReceived += dataReceived;
            } catch { }
        }

        private void dataReceived(object s, SerialDataReceivedEventArgs e) {
            string fromPort = serialPort.ReadLine();

            Console.SetCursorPosition(0, 0);
            Console.WriteLine(fromPort);

            int[] XY = parser(fromPort);
            MouseTranslator translate = new MouseTranslator(XY[0], XY[1]);
        }

        private int[] parser(string input) {
            int[] output = new int[2];
            string pattern = @"X:(-?[0-9]+)Y:(-?[0-9]+)";
            input.Trim();

            try {
                Match match = Regex.Match(input, pattern);
                output[0] = int.Parse(match.Groups[1].ToString());
                output[1] = int.Parse(match.Groups[2].ToString());
            } catch { }

            return output;
        }
    }

    class MouseTranslator {
        private int joyX;
        private int joyY;

        public MouseTranslator(int x, int y) {
            joyX = x;
            joyY = y;
            moveMouse();
        }

        private void moveMouse() {
            Cursor.Position = new Point(Cursor.Position.X - joyX, Cursor.Position.Y - joyY);
        }
    }
}
