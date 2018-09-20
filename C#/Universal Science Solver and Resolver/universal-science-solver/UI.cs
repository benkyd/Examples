using System;
using System.Threading;
using universal_science_solver.Physics;

namespace universal_science_solver {
    class UI {
        public Modes Mode = Modes.UNSELECTED;
        private bool isRunning = true;

        public enum Modes : byte {
            UNSELECTED,
            PHYSICS,
            CHEMISTRY,
            MATHEMATICS
        }

        public UI() {
            Console.Clear();
            Console.WriteLine("Loading...");
            Thread.Sleep(400);
            PhysicsControler.Initializer();
            boot();
            eventLoop();
        }

        private void boot() {
            Console.Clear();
            Console.WriteLine("The Universal Science Solver and Resolver");
            Console.WriteLine("Copyright 2018 Benjamin Kyd, Licensed under the MIT license");
            Console.WriteLine();
            Console.WriteLine("Enter q at any point to return to the menu, Ctrl+C to exit the program at any time");
            Console.WriteLine();
        }

        private void eventLoop() {
            while (isRunning) {
                if (Mode == Modes.UNSELECTED) {
                    selectMode();
                    continue;
                }

                if (Mode == Modes.PHYSICS) {

                }
            }
        }

        private void selectMode() {
            Console.WriteLine("Physics (p), chemistry (c), mathematics (m)");
            Console.Write("> ");
            var key = Console.ReadKey();
            Console.WriteLine();

            switch (key.KeyChar.ToString().ToLower()[0]) {
                case 'p':
                    Mode = Modes.PHYSICS;
                    Console.WriteLine("Physics mode selected");
                    break;
                case 'c':
                    Mode = Modes.CHEMISTRY;
                    Console.WriteLine("Chemistry mode selected");
                    break;
                case 'm':
                    Mode = Modes.MATHEMATICS;
                    Console.WriteLine("Mathematics mode selected");
                    break;
                default:
                    Console.WriteLine("No mode selected");
                    break;
            }
        }
    }
}
