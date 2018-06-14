using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Conways_Game_Of_Life {
    class Cell {
        public int x { get; }
        public int y { get; }

        public Cell(int _x, int _y) {
            x = _x;
            y = _y;
        }

        public void update() {

        }
    }
}