using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SimpleRocketGame
{
    class UserInterface
    {
        private Rocket LocalRocket { get; set; }

        private Boolean running { get; set; }
        public UserInterface()
        {
            LocalRocket = new Rocket();
            running = true;
        }

        public void Start()
        {
            Console.WriteLine("Welcome to the simple rocket game.");
            Console.WriteLine("This game allows you to edit and simulate a simple rocket");
            
            while (running)
            {
                Console.WriteLine("Please select how you wish to proceed?");
                Console.WriteLine("\tRocket: {0} seconds to launch", LocalRocket.LaunchTimer);
                Console.WriteLine("(E)dit, (S)imulate, (Q)uit");
                var response = Console.ReadKey();
                Console.WriteLine();
                switch (response.KeyChar)
                {
                    case 'E':
                    case 'e':
                        //edit the rocket
                        EditRocket();
                        break;
                    case 'S':
                    case 's':
                        this.Simulate();
                        break;
                    case 'Q':
                    case 'q':
                        Console.WriteLine("Thanks for playing");
                        Console.Read();
                        this.running = false;
                        break;
                }
                if (!running)
                    continue;
            }
        }

        public void EditRocket()
        {
            //show options to edit the rocket
            var back = false;
            while (!back)
            {
                Console.WriteLine("What do you wish to edit:");
                Console.WriteLine("(1) Countdown Time: {0} seconds", LocalRocket.LaunchTimer);
                Console.WriteLine("(B)ack");
                var response = Console.ReadKey();
                Console.WriteLine();
                switch (response.KeyChar)
                {
                    case '1':
                        var success = false;
                        while (!success)
                        {
                            Console.WriteLine("Please enter a positive whole number to count down from:");
                            var userInput = Console.ReadLine();
                            if (userInput.ToLower() == "back")
                            {
                                success = true;
                                break; //could also use continue
                            }
                            if (int.TryParse(userInput, out var value))
                            {
                                if (value > 0)
                                {
                                    this.LocalRocket.LaunchTimer = value;
                                    success = true;
                                }
                                else
                                {
                                    Console.WriteLine("Please enter a positive number");
                                }
                            }
                            else
                            {
                                Console.WriteLine("Please enter a number, or back");
                            }
                        }
                        break;
                    case 'B':
                    case 'b':
                        back = true;
                        break;
                }
            }
        }

        public void Simulate()
        {
            //show the rocket simulation details
            Console.WriteLine("Launching Rocket");
            LocalRocket.Launch();
            Console.WriteLine("Results: ");
            if (LocalRocket.hasLaunched)
            {
                Console.WriteLine("Rocket launched after {0} seconds and flew for {1} seconds before crashing", LocalRocket.LaunchTimer, LocalRocket.flightTime);
            } else
            {
                Console.WriteLine("Rocket crashed after {0} seconds, {1} seconds before expected launch", LocalRocket.LaunchTimer - LocalRocket.TimeUntilLaunch, LocalRocket.TimeUntilLaunch);
            }
            Console.WriteLine("Creating New rocket");
            this.LocalRocket = new Rocket();
        }
    }
}
