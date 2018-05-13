using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Networking_Tools {
    class UserInterface {

        private int startWidth;
        private int startHeight;

        public void Load() {
            Console.SetCursorPosition(0, 0);
            startHeight = Console.WindowHeight;
            startWidth = Console.WindowWidth;

            
        }



    }
}
