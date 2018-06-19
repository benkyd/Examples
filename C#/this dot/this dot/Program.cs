using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace this_dot {
    class Program {
        static void Main() {
            Person one = new Person("Dave", 16);
            Person two = new Person("John", 21, one);
            Person three = new Person("Chris", 12, two);
            Person four = new Person("Vero", 23, three);

            Person[] ppl = { one, two, three, four };

            foreach (Person person in ppl) {
                this.getOlder();
            }
        }
    }

    class Person {
        public string Name { get; set; }
        public int Age { get; set; }
        public Person Parent { get; set; }

        public Person(string _name, int _age, Person _parent) {
            Name = _name;
            Age = _age;
            Parent = _parent;
        }

        public Person(string _name, int _age) {
            Name = _name;
            Age = _age;
        }

        public void getOlder() {
            Age++;
        }
    }
}
