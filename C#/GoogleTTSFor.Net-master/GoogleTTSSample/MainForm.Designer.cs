namespace WindowsFormsApp4
{
    partial class MainForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.createAndPlayBtn = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.useCacheCB = new System.Windows.Forms.CheckBox();
            this.writeWavCB = new System.Windows.Forms.CheckBox();
            this.wavFolderTB = new System.Windows.Forms.TextBox();
            this.mp3FolderTB = new System.Windows.Forms.TextBox();
            this.mp3FolderBtn = new System.Windows.Forms.Button();
            this.wavFolderBtn = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // createAndPlayBtn
            // 
            this.createAndPlayBtn.Location = new System.Drawing.Point(12, 90);
            this.createAndPlayBtn.Name = "createAndPlayBtn";
            this.createAndPlayBtn.Size = new System.Drawing.Size(237, 23);
            this.createAndPlayBtn.TabIndex = 3;
            this.createAndPlayBtn.Text = "Create Files and Play\r\n";
            this.createAndPlayBtn.UseVisualStyleBackColor = true;
            this.createAndPlayBtn.Click += new System.EventHandler(this.button1_Click);
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(12, 64);
            this.textBox1.MaxLength = 200;
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(237, 20);
            this.textBox1.TabIndex = 2;
            this.textBox1.Text = "Welcome";
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(12, 25);
            this.textBox2.MaxLength = 200;
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(237, 20);
            this.textBox2.TabIndex = 1;
            this.textBox2.Text = "en";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(105, 13);
            this.label1.TabIndex = 3;
            this.label1.Text = "Language Selection:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 48);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(111, 13);
            this.label2.TabIndex = 4;
            this.label2.Text = "Text To Speech Text:";
            // 
            // listBox1
            // 
            this.listBox1.FormattingEnabled = true;
            this.listBox1.Location = new System.Drawing.Point(12, 165);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(723, 134);
            this.listBox1.TabIndex = 5;
            // 
            // useCacheCB
            // 
            this.useCacheCB.AutoSize = true;
            this.useCacheCB.Checked = true;
            this.useCacheCB.CheckState = System.Windows.Forms.CheckState.Checked;
            this.useCacheCB.Location = new System.Drawing.Point(12, 142);
            this.useCacheCB.Name = "useCacheCB";
            this.useCacheCB.Size = new System.Drawing.Size(79, 17);
            this.useCacheCB.TabIndex = 6;
            this.useCacheCB.Text = "Use Cache";
            this.useCacheCB.UseVisualStyleBackColor = true;
            // 
            // writeWavCB
            // 
            this.writeWavCB.AutoSize = true;
            this.writeWavCB.Checked = true;
            this.writeWavCB.CheckState = System.Windows.Forms.CheckState.Checked;
            this.writeWavCB.Location = new System.Drawing.Point(12, 119);
            this.writeWavCB.Name = "writeWavCB";
            this.writeWavCB.Size = new System.Drawing.Size(74, 17);
            this.writeWavCB.TabIndex = 7;
            this.writeWavCB.Text = "Write wav";
            this.writeWavCB.UseVisualStyleBackColor = true;
            this.writeWavCB.CheckedChanged += new System.EventHandler(this.writeWavCB_CheckedChanged);
            // 
            // wavFolderTB
            // 
            this.wavFolderTB.Location = new System.Drawing.Point(498, 25);
            this.wavFolderTB.MaxLength = 200;
            this.wavFolderTB.Name = "wavFolderTB";
            this.wavFolderTB.ReadOnly = true;
            this.wavFolderTB.Size = new System.Drawing.Size(237, 20);
            this.wavFolderTB.TabIndex = 8;
            // 
            // mp3FolderTB
            // 
            this.mp3FolderTB.Location = new System.Drawing.Point(255, 25);
            this.mp3FolderTB.MaxLength = 200;
            this.mp3FolderTB.Name = "mp3FolderTB";
            this.mp3FolderTB.ReadOnly = true;
            this.mp3FolderTB.Size = new System.Drawing.Size(237, 20);
            this.mp3FolderTB.TabIndex = 11;
            // 
            // mp3FolderBtn
            // 
            this.mp3FolderBtn.Location = new System.Drawing.Point(255, 61);
            this.mp3FolderBtn.Name = "mp3FolderBtn";
            this.mp3FolderBtn.Size = new System.Drawing.Size(237, 23);
            this.mp3FolderBtn.TabIndex = 12;
            this.mp3FolderBtn.Text = "Select MP3 Output Folder";
            this.mp3FolderBtn.UseVisualStyleBackColor = true;
            this.mp3FolderBtn.Click += new System.EventHandler(this.mp3FolderBtn_Click);
            // 
            // wavFolderBtn
            // 
            this.wavFolderBtn.Location = new System.Drawing.Point(498, 61);
            this.wavFolderBtn.Name = "wavFolderBtn";
            this.wavFolderBtn.Size = new System.Drawing.Size(237, 23);
            this.wavFolderBtn.TabIndex = 13;
            this.wavFolderBtn.Text = "Select Wav Output Folder";
            this.wavFolderBtn.UseVisualStyleBackColor = true;
            this.wavFolderBtn.Click += new System.EventHandler(this.wavFolderBtn_Click);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(747, 322);
            this.Controls.Add(this.wavFolderBtn);
            this.Controls.Add(this.mp3FolderBtn);
            this.Controls.Add(this.mp3FolderTB);
            this.Controls.Add(this.wavFolderTB);
            this.Controls.Add(this.writeWavCB);
            this.Controls.Add(this.useCacheCB);
            this.Controls.Add(this.listBox1);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.createAndPlayBtn);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.MinimumSize = new System.Drawing.Size(364, 300);
            this.Name = "MainForm";
            this.Text = "Google Text To Speech Sample";
            this.Load += new System.EventHandler(this.MainForm_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button createAndPlayBtn;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.CheckBox useCacheCB;
        private System.Windows.Forms.CheckBox writeWavCB;
        private System.Windows.Forms.TextBox wavFolderTB;
        private System.Windows.Forms.TextBox mp3FolderTB;
        private System.Windows.Forms.Button mp3FolderBtn;
        private System.Windows.Forms.Button wavFolderBtn;
    }
}

