using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Conways_Game_Of_Life {
    class Game {
        public char[,] Grid;
        public char[,] OldGrid;

        public void initGame() {
            Grid = new char[Console.WindowWidth, Console.WindowHeight];

            for (int i = 0; i < Grid.GetLength(0); i++) {
                for (int j = 0; j < Grid.GetLength(1); j++) {
                    Grid[i, j] = ' ';
                }
            }

            
        }

        private void gameLoop() {

        }

        private char[,] copyGrid(char[,] old) {
            return old;
        }
    }
}
