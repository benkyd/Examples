using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Rocket_launch_game
{
    class Program
    {
        Random crash = new Random(); //declare the random chance of crashing
        string status; //what will be cleared then printed 
        string body; //user defined
        string continueAfterDefine; //continue Y/N
        int rocketLost = 0; //declare lost value at 0 - rocket is intact
        int timeToTakeoff; //user defined
        int stageCount; //user defined 

        static void Main()
        {
            Program p = new Program();
            p.DeclerationOfVariables();
        }

        public void DeclerationOfVariables()
        {
            Console.WriteLine("How long until rocket takeoff?");
            timeToTakeoff = int.Parse(Console.ReadLine()); //define the countdown timer length 
            Console.WriteLine("The launch timer is set to {0} seconds", timeToTakeoff);
            Console.WriteLine("How many stages will the rocket have? (more = less chance of success. but with less you cant go as far)");
            stageCount = int.Parse(Console.ReadLine()); //define stage count

            heading:
            Console.WriteLine("What celestial body are you aiming for? choose from 'The moon' or 'Mars' (further away requres more stages)");
            body = Console.ReadLine(); //define heading

            if (body.ToLower() == "the moon" || body.ToLower() == "mars")
            {
                goto Continue;
            }
            else
            {
                Console.WriteLine("The heading you chose is not valid");
                goto heading;
            }

            Continue:
            Console.Clear();
            Console.WriteLine("The rocket will take off in {0} seconds, with {1} stages and will be heading to {2}. Do you wish to continue Y/N", timeToTakeoff, stageCount, body);
            continueAfterDefine = Console.ReadLine();

            if (continueAfterDefine.ToLower() == "y")
            {
                LaunchAndFlight();
            }
        }

        public void LaunchAndFlight()
        {
            Console.WriteLine("ASD");
            Console.ReadKey();
        }

        public void WriteLine()
        {
            Console.Clear();
            Console.WriteLine(status);
            return;
        }
    }
}
