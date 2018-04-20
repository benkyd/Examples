using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Reminders
{
    class Program
    {
        static void Main()
        {
            var i = new Program();
            i.status();
        }

        private void status()
        {
            Console.Clear();
            Console.WriteLine(RunningTaskString());
            Console.WriteLine("(1) To create a new task");
            Console.WriteLine("(2) To delete an already running task");

            var response = Console.ReadKey();
            switch (response.KeyChar)
            {
                case '1':
                    NewTask();
                    break;
                case '2':
                    CancelTask();
                    break;
            }

            status();
        }

        private void CancelTask()
        {
            Console.Clear();
        }

        private void NewTask()
        {
            Console.Clear();
            Console.Write("What should the name of the task be: ");
            string name = Console.ReadLine();

            int time;
            bool correct = false;
            while (correct == false)
            {
                Console.Write("How long until the reminder (in minutes): ");
                try
                {
                    time = int.Parse(Console.ReadLine());
                    correct = true;
                    break;
                }
                catch (FormatException)
                {
                    Console.WriteLine("That is not a number");
                }
            }

            Console.ReadKey();
        }



        private void RunningTasks(string name, int time)
        {

        }

        private string RunningTaskString()
        {
            return "0";
        }

        private void popup(string message)
        {
            System.Windows.Forms.MessageBox.Show(message);
        }
    }
}
