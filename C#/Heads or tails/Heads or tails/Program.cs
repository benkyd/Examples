using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Heads_or_tails
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Heads or Tails?");

            string UserHeadsString;
            bool UserHeads = false;
            bool RandomHeads;
            bool Won;

            UserHeadsString = Console.ReadLine();

            if (UserHeadsString.ToLower() == "heads")
            {
                UserHeads = true;
            }
            else if (UserHeadsString.ToLower() == "tails")
            {
                UserHeads = false;
            }
            
            Random rnd = new Random();
            int HeadsOrTails = rnd.Next(1, 2);

            if (HeadsOrTails == 1)
            {
                RandomHeads = true;
            }
            else
            {
                RandomHeads = false;
            }

            string StringRandomHeadsPrint;

            if (RandomHeads)
            {
                StringRandomHeadsPrint = "Heads!";
            }
            else
            {
                StringRandomHeadsPrint = "Tails!";
            }

            string StringRandomHeads = Convert.ToString(RandomHeads);
            string StringUserHeads = Convert.ToString(UserHeads);

            Console.WriteLine(StringRandomHeadsPrint);

            if (StringRandomHeads == StringUserHeads)
            {
                Won = true;
            }
            else
            {
                Won = false;
            }

            if (Won)
            {
                Console.WriteLine("You won!");
            }
            else
            {
                Console.WriteLine("You loose");
            }
            Console.ReadKey();
        }
    }
}
