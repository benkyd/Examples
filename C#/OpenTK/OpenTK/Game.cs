using System;
using OpenTK;
using OpenTK.Graphics;
using OpenTK.Graphics.OpenGL;
using OpenTK.Input;

namespace OpenTK {
    class Game {
        private GameWindow window;
        public Game() {
            this.window = new GameWindow(640, 480);
            this.window.Title = "Game engine";
            Start();
        }

        void Start() {
            window.Load += OnLoad;
            window.RenderFrame += RenderF;

            window.Run(1.0 / 60.0);
        }

        void OnLoad(object o, EventArgs e) {
            GL.ClearColor(66f / 255f, 134f / 255f, 244f / 255f, 1f);
        }
 
        void RenderF(object o, EventArgs e) {
            GL.Clear(ClearBufferMask.ColorBufferBit);
            window.SwapBuffers();
        }
    }
}
