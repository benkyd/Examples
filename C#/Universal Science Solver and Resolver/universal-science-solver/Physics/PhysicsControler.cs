using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace universal_science_solver.Physics {
    class PhysicsControler {

        public enum Topic : byte {
            USELECTED,
            BASICS,
            MECHANICS,
            WAVES
        }

        public static IList<Mode> ModeList = new List<Mode>();

        public static void Initializer() {
            ModeList.Add(new Mode("Speed distance time", Topic.BASICS, "Calculate distance, speed or time"));
        }

        public static IList<Mode> ListModes() {
            foreach (Mode mode in ModeList) {
                Console.WriteLine(mode.Title);
            }
            return ModeList;
        }
    }

    class Mode {
        public string Title;
        public PhysicsControler.Topic Topic;
        public string Desc;

        public Mode(string title, PhysicsControler.Topic topic, string desc) {
            this.Title = title;
            this.Topic = topic;
            this.Desc = desc;
        }
    }
}
