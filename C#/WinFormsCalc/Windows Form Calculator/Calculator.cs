using System;
using System.Diagnostics;
using System.Windows.Forms;

namespace Windows_Form_Calculator {
    public partial class Calculator : Form {
        public Calculator() {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e) {

        }

        private void C1_Click(object sender, EventArgs e) {
            Debug.WriteLine("Button 1");
        }

        private void C2_Click(object sender, EventArgs e) {
            Debug.WriteLine("Button 2");
        }
    }
}
