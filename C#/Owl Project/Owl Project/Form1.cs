using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;
using System.Windows.Forms;

namespace Owl_Project {
    public partial class Form1 : Form {
        public Form1() {
            InitializeComponent();
        }

        string box;

        private void textBox1_TextChanged(object sender, EventArgs e) {

        }

        private void button1_Click(object sender, EventArgs e) {
            box = textBox1.Text;
            Debug.WriteLine(box);
        }

        private void Form1_Load(object sender, EventArgs e) {

        }
    }
}
