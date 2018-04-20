using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;


//Made by Ben Kyd


namespace _2048 {

    class Program {

        private bool gameState = true;
        private int score = 0;
        private int[] tableState = new int[] { //defult state of grid
            2 , 0 , 0 , 0,
            0 , 0 , 0 , 0,
            0 , 0 , 2 , 0,
            0 , 0 , 0 , 0 };


        static void Main(string[] args) {
            var i = new Program();
            i.gameLoop();
        }

        private void gameLoop() {

            do {
                Console.Clear();

                Console.WindowWidth = 40;
                Console.WindowHeight = 20;
                Console.CursorVisible = false;

                Console.SetCursorPosition(0, 0);

                drawGrid();

                var input = Console.ReadKey();
                if (input.Key == ConsoleKey.UpArrow) {
                    mergeUp();
                    moveUp();
                    checkEmpty();
                } else if (input.Key == ConsoleKey.RightArrow) {
                    mergeRight();
                    moveRight();
                    checkEmpty();
                } else if (input.Key == ConsoleKey.DownArrow) {
                    mergeDown();
                    moveDown();
                    checkEmpty();
                } else if (input.Key == ConsoleKey.LeftArrow) {
                    mergeLeft();
                    moveLeft();
                    checkEmpty();
                }

            } while (gameState);
        }

        private void drawGrid() {

            for (int j = 0; j < tableState.Length; j++) {

                textColour(tableState[j]);

                Console.Write(tableState[j] + "\t");
                if (j == 3) {
                    Console.WriteLine("\n\n\n");
                } else if (j == 7) {
                    Console.WriteLine("\n\n\n");
                } else if (j == 11) {
                    Console.WriteLine("\n\n\n");
                } else if (j == 16) {
                    Console.WriteLine("\n\n\n");
                }
            }
            Console.WriteLine();
            Console.WriteLine();
            Console.ForegroundColor = ConsoleColor.White;
            Console.WriteLine("Score: " + score);
        }

        private void checkEmpty() {
            var rnd = new Random();
            for (int i = 0; i < tableState.Length; i++) {
                if (tableState[i] == 0) {
                    if (rnd.Next(0, 21) > 18) {
                        tableState[i] = 2;
                    }
                }
            }
        }

        private void mergeUp() {
            for (int i = 0; i < 4; i++) { //loops over all rows
                for (int j = 0; j < 4; j++) { //loops over all columns
                    try {
                        if (tableState[i * 4 + j] == tableState[i * 4 + j - 4] && tableState[i * 4 + j] != 0) {
                            tableState[i * 4 + j - 4] = tableState[i * 4 + j] * 2;
                            tableState[i * 4 + j] = 0;
                        }
                    } catch (IndexOutOfRangeException) {
                    }
                }
            }
        }

        private void mergeRight() {
            for (int i = 0; i < 4; i++) { //loops over all rows
                for (int j = 0; j < 4; j++) { //loops over all columns
                    try {
                        if (tableState[i * 4 + j] == tableState[i * 4 + j + 1] && tableState[i * 4 + j] != 0) {
                            tableState[i * 4 + j + 1] = tableState[i * 4 + j] * 2;
                            tableState[i * 4 + j] = 0;
                        }
                    } catch (IndexOutOfRangeException) {
                    }
                }
            }
        }

        private void mergeDown() {
            for (int i = 0; i < 4; i++) { //loops over all rows
                for (int j = 0; j < 4; j++) { //loops over all columns
                    try {
                        if (tableState[i * 4 + j] == tableState[i * 4 + j + 4] && tableState[i * 4 + j] != 0) {
                            tableState[i * 4 + j + 4] = tableState[i * 4 + j] * 2;
                            tableState[i * 4 + j] = 0;
                        }
                    }
                    catch (IndexOutOfRangeException) {
                    }
                }
            }
        }

        private void mergeLeft() {
            for (int i = 0; i < 4; i++) { //loops over all rows
                for (int j = 0; j < 4; j++) { //loops over all columns
                    try {
                        if (tableState[i * 4 + j] == tableState[i * 4 + j - 1] && tableState[i * 4 + j] != 0) {
                            tableState[i * 4 + j - 1] = tableState[i * 4 + j] * 2;
                            tableState[i * 4 + j] = 0;
                        }
                    } catch (IndexOutOfRangeException) {
                    }
                }
            }
        }

        private void moveDown() {
/*            for (int i = 0; i < 4; i++) { //loops over all rows
                for (int j = 0; j < 4; j++) { //loops over all columns
                    try {
                        if (tableState[i * 4 + j] > 0 && tableState[i * 4 + j + 4] != 0) {
                            tableState[i * 4 + j + 4] = tableState[i * 4 + j];
                            tableState[i * 4 + j] = 0;
                        }
                    } catch (IndexOutOfRangeException) {
                    }
                }
            }
  */      }

        private void moveLeft() {

        }

        private void moveUp() {

        }

        private void moveRight() {

        }


        private void textColour(int num) {

            if (num == 0) {
                Console.ForegroundColor = ConsoleColor.White;
            } else if (num == 2) {
                Console.ForegroundColor = ConsoleColor.DarkGreen;
            } else if (num == 4) {
                Console.ForegroundColor = ConsoleColor.Green;
            } else if (num == 8) {
                Console.ForegroundColor = ConsoleColor.DarkYellow;
            } else if (num == 16) {
                Console.ForegroundColor = ConsoleColor.DarkMagenta;
            } else if (num == 32) {
                Console.ForegroundColor = ConsoleColor.Magenta;
            } else if (num == 64) {
                Console.ForegroundColor = ConsoleColor.Yellow;
            } else if (num == 128) {
                Console.ForegroundColor = ConsoleColor.DarkGreen;
            } else if (num == 256) {
                Console.ForegroundColor = ConsoleColor.Green;
            } else if (num == 512) {
                Console.ForegroundColor = ConsoleColor.DarkBlue;
            } else if (num == 1024) {
                Console.ForegroundColor = ConsoleColor.Blue;
            } else if (num == 2048) {
                Console.ForegroundColor = ConsoleColor.Cyan;
            } else if (num == 4096) {
                Console.ForegroundColor = ConsoleColor.Gray;
            }

            else {
                Console.ForegroundColor = ConsoleColor.White;
            }
        }
    }
}
