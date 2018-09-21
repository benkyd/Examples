using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace universal_science_solver.Physics {
    class PhysicsController {
        public enum Topic : byte {
            USELECTED,
            BASICS,
            MECHANICS,
            WAVES
        }

        public static IList<Mode> ModeList = new List<Mode>();
        public static Dictionary<Topic, string> TopicDictionary = new Dictionary<Topic, string>();

        public static void Initializer() {
            TopicDictionary.Add(Topic.USELECTED, "No topic selected");
            TopicDictionary.Add(Topic.BASICS, "Physics basics");
            TopicDictionary.Add(Topic.MECHANICS, "Mechanics");
            TopicDictionary.Add(Topic.WAVES, "Waves");

            ModeList.Add(new Mode("Speed distance time", Topic.BASICS, "Calculate distance, speed or time", BasicPhysics.SpeedDistanceTime));
        }

        public static void TakeControl() {
            Console.WriteLine();
            Console.WriteLine("Available physics modes:");
            listModes();
            selectMode();
        }

        private static void selectMode() {
            Console.Write("> ");
            var key = Console.ReadKey();
            Console.WriteLine();

            int index = 0;
            try {
                index = int.Parse(key.KeyChar.ToString()) - 1;
                Mode selected = ModeList[index];

                Console.WriteLine("Mode [" + selected.Title + "] selected");
                selected.FunctionReference();
                Console.ReadKey();

            } catch (Exception e) {
                Console.WriteLine("You must select a number");
                selectMode();
            }
        }

        private static IList<Mode> listModes() { 
            for (int i = 0; i < ModeList.Count(); i++) {
                Console.Write("(" + (i + 1) + ") ");
                Console.Write(ModeList[i].Title);
                Console.Write(" in the topic [" + TopicDictionary[ModeList[i].Topic] + "]");
            }
            Console.WriteLine();
            return ModeList;
        }
    }

    class Mode {
        public string Title;
        public PhysicsController.Topic Topic;
        public string Desc;
        public Action FunctionReference;

        public Mode(string title, PhysicsController.Topic topic, string desc, Action functionReference) {
            this.Title = title;
            this.Topic = topic;
            this.Desc = desc;
            this.FunctionReference = functionReference;
        }
    }
}
