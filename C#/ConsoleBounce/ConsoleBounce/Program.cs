using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace ConsoleBounce
{
    class Program
    {

        static void Main()
        {
            Console.CursorVisible = false;

            Thread ConsoleKeyListener = new Thread(new ThreadStart(ListerKeyBoardEvent));
            ConsoleKeyListener.Start();

            var draw = new Program();
            var ball = new Program();

            bool complete = false;
            while (complete == false)
            {
                string ballxy = ball.ball();
                draw.draw(ballxy);
                Thread.Sleep(25);


            }

            Console.ReadKey();
        }

        public static bool SpaceBar = false;

        private void draw(string xy)
        {
            Console.CursorVisible = false;
            Console.Clear();

            Console.WriteLine(SpaceBar);

            Console.WindowHeight = 40;
            Console.WindowWidth = 40;

            Console.SetCursorPosition(0, Console.WindowHeight);
            int width = Console.WindowWidth;



            string[] stringcoords = xy.Split(',');

            int[] coords = new int[2];
            coords[0] = int.Parse(stringcoords[0]);
            coords[1] = int.Parse(stringcoords[1]);

            Console.SetCursorPosition(coords[0], coords[1]);
            Console.Write("0");

            return;
        }

        public int y { get; private set; } = 0;
        private string ball()
        {
            int x = Console.WindowWidth / 3;

            if (y < Console.WindowHeight)
            {
                y++;
            }

            if (SpaceBar && y < 0)
            {
                y--;
                y--;
                y--;
            }

            SpaceBar = false;
            string xy = x + "," + y;
            return xy;
        }



        public static void ListerKeyBoardEvent()
        {
            do
            {
                if (Console.ReadKey(true).Key == ConsoleKey.Spacebar)
                {
                    SpaceBar = true;
                }
            } while (true);
        }
    }
}

