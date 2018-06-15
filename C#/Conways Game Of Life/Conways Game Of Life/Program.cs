using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;

namespace Conways_Game_Of_Life {
    class Program {

        static void Main() {
            Game start = new Game();
            start.initGame();
        }
    }
}
