using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Speech.Synthesis;

namespace TTS {
    class Program {
        static void Main(string[] args) {
            using (SpeechSynthesizer synth = new System.Speech.Synthesis.SpeechSynthesizer()) {
                synth.Speak("Joe debono is a faggot");
            }
        }
    }
}
