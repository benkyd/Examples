using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace SimpleRocketGame
{
    class Rocket
    {
        public int LaunchTimer { get; set; }

        public int TimeUntilLaunch { get; set; }

        public Boolean hasLaunched { get; private set; }

        public Boolean isLost { get; private set; }

        public int flightTime { get; private set; }

        private Random random;

        public Rocket()
        {
            //create the default rocket with a counter of 10
            this.LaunchTimer = 10;
            random = new Random();
        }

        public void Launch()
        {
            if (hasLaunched || isLost)
                return;

            //perform launch countdown, and on success fly
            this.TimeUntilLaunch = LaunchTimer;
            while (TimeUntilLaunch > 0 && !isLost)
            {
                
                Thread.Sleep(1000);
                
                TimeUntilLaunch--;
                if (TimeUntilLaunch == 3)
                {
                    Console.WriteLine("Starting Main Engines");
                }
                else
                {
                    Console.WriteLine("T-{0} seconds until launch", TimeUntilLaunch);
                }
                if (random.Next(10) == 1)
                {
                    isLost = true;
                    Console.WriteLine("An accident occured on the launch pad, Rocket Lost");
                }
            }
            if (TimeUntilLaunch == 0 && !isLost)
            {
                Console.WriteLine("Lift Off");
                hasLaunched = true;
                Fly();
            }
            else
            {
                hasLaunched = false;
            }
        }

        private void Fly()
        {
            //perform the rockets flight calculations and return how long the rocket was in the air
            while (!isLost)
            {
                Thread.Sleep(1000);
                flightTime++;
                Console.WriteLine("Rocket away t+{0}", flightTime);
                if (random.Next(flightTime, 1000) > 800) //ensure crash after 800 seconds, with increasing chance of failure
                {
                    Console.WriteLine("Citical engine failure, Rocket Lost");
                    this.isLost = true;
                }
            }
        }
    }
}
