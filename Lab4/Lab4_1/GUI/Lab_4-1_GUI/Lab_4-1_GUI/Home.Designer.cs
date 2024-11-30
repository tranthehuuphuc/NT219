namespace Lab_4_1_GUI
{
    partial class Home
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            tabControl1 = new TabControl();
            tabPage1 = new TabPage();
            txbOutLeng = new TextBox();
            label4 = new Label();
            btnHash = new Button();
            btnOpenOutput = new Button();
            btnOpenInput = new Button();
            txbOutput = new TextBox();
            label3 = new Label();
            label2 = new Label();
            txbInput = new TextBox();
            label1 = new Label();
            comboBox1 = new ComboBox();
            tabPage2 = new TabPage();
            txbOutLeng_2 = new TextBox();
            label5 = new Label();
            btnHash_2 = new Button();
            txbOutput_2 = new TextBox();
            label6 = new Label();
            label7 = new Label();
            txbInput_2 = new TextBox();
            label8 = new Label();
            cbType_2 = new ComboBox();
            tabControl1.SuspendLayout();
            tabPage1.SuspendLayout();
            tabPage2.SuspendLayout();
            SuspendLayout();
            // 
            // tabControl1
            // 
            tabControl1.Controls.Add(tabPage1);
            tabControl1.Controls.Add(tabPage2);
            tabControl1.Location = new Point(2, 4);
            tabControl1.Name = "tabControl1";
            tabControl1.SelectedIndex = 0;
            tabControl1.Size = new Size(1167, 599);
            tabControl1.TabIndex = 0;
            // 
            // tabPage1
            // 
            tabPage1.Controls.Add(txbOutLeng);
            tabPage1.Controls.Add(label4);
            tabPage1.Controls.Add(btnHash);
            tabPage1.Controls.Add(btnOpenOutput);
            tabPage1.Controls.Add(btnOpenInput);
            tabPage1.Controls.Add(txbOutput);
            tabPage1.Controls.Add(label3);
            tabPage1.Controls.Add(label2);
            tabPage1.Controls.Add(txbInput);
            tabPage1.Controls.Add(label1);
            tabPage1.Controls.Add(comboBox1);
            tabPage1.Location = new Point(8, 46);
            tabPage1.Name = "tabPage1";
            tabPage1.Padding = new Padding(3);
            tabPage1.Size = new Size(1151, 545);
            tabPage1.TabIndex = 0;
            tabPage1.Text = "From File";
            tabPage1.UseVisualStyleBackColor = true;
            // 
            // txbOutLeng
            // 
            txbOutLeng.Location = new Point(861, 61);
            txbOutLeng.Name = "txbOutLeng";
            txbOutLeng.Size = new Size(232, 39);
            txbOutLeng.TabIndex = 10;
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            label4.Location = new Point(509, 64);
            label4.Name = "label4";
            label4.Size = new Size(346, 32);
            label4.TabIndex = 9;
            label4.Text = "Output Length (SHAKE only):";
            // 
            // btnHash
            // 
            btnHash.BackColor = Color.DarkOrange;
            btnHash.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            btnHash.ForeColor = Color.White;
            btnHash.Location = new Point(445, 294);
            btnHash.Name = "btnHash";
            btnHash.Size = new Size(255, 70);
            btnHash.TabIndex = 8;
            btnHash.Text = "HASH";
            btnHash.UseVisualStyleBackColor = false;
            btnHash.Click += btnHash_Click;
            // 
            // btnOpenOutput
            // 
            btnOpenOutput.BackColor = Color.SlateGray;
            btnOpenOutput.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            btnOpenOutput.ForeColor = Color.White;
            btnOpenOutput.Location = new Point(899, 417);
            btnOpenOutput.Name = "btnOpenOutput";
            btnOpenOutput.Size = new Size(152, 70);
            btnOpenOutput.TabIndex = 7;
            btnOpenOutput.Text = "Browse";
            btnOpenOutput.UseVisualStyleBackColor = false;
            btnOpenOutput.Click += btnOpenOutput_Click;
            // 
            // btnOpenInput
            // 
            btnOpenInput.BackColor = Color.SlateGray;
            btnOpenInput.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            btnOpenInput.ForeColor = Color.White;
            btnOpenInput.Location = new Point(899, 162);
            btnOpenInput.Name = "btnOpenInput";
            btnOpenInput.Size = new Size(152, 70);
            btnOpenInput.TabIndex = 6;
            btnOpenInput.Text = "Browse";
            btnOpenInput.UseVisualStyleBackColor = false;
            btnOpenInput.Click += button1_Click;
            // 
            // txbOutput
            // 
            txbOutput.Location = new Point(199, 417);
            txbOutput.Multiline = true;
            txbOutput.Name = "txbOutput";
            txbOutput.Size = new Size(656, 70);
            txbOutput.TabIndex = 5;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            label3.Location = new Point(55, 436);
            label3.Name = "label3";
            label3.Size = new Size(148, 32);
            label3.TabIndex = 4;
            label3.Text = "Output File:";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            label2.Location = new Point(55, 181);
            label2.Name = "label2";
            label2.Size = new Size(129, 32);
            label2.TabIndex = 3;
            label2.Text = "Input File:";
            // 
            // txbInput
            // 
            txbInput.Location = new Point(199, 162);
            txbInput.Multiline = true;
            txbInput.Name = "txbInput";
            txbInput.Size = new Size(656, 70);
            txbInput.TabIndex = 2;
            txbInput.TextChanged += textBox1_TextChanged;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            label1.Location = new Point(55, 64);
            label1.Name = "label1";
            label1.Size = new Size(138, 32);
            label1.TabIndex = 1;
            label1.Text = "Hash Type:";
            // 
            // comboBox1
            // 
            comboBox1.DropDownStyle = ComboBoxStyle.DropDownList;
            comboBox1.FlatStyle = FlatStyle.Flat;
            comboBox1.FormattingEnabled = true;
            comboBox1.Items.AddRange(new object[] { "SHA_224", "SHA_256", "SHA_512", "SHA3_224", "SHA3_256", "SHA3_384", "SHA3_512", "SHAKE128", "SHAKE256" });
            comboBox1.Location = new Point(199, 61);
            comboBox1.Name = "comboBox1";
            comboBox1.Size = new Size(232, 40);
            comboBox1.TabIndex = 0;
            // 
            // tabPage2
            // 
            tabPage2.Controls.Add(txbOutLeng_2);
            tabPage2.Controls.Add(label5);
            tabPage2.Controls.Add(btnHash_2);
            tabPage2.Controls.Add(txbOutput_2);
            tabPage2.Controls.Add(label6);
            tabPage2.Controls.Add(label7);
            tabPage2.Controls.Add(txbInput_2);
            tabPage2.Controls.Add(label8);
            tabPage2.Controls.Add(cbType_2);
            tabPage2.Location = new Point(8, 46);
            tabPage2.Name = "tabPage2";
            tabPage2.Padding = new Padding(3);
            tabPage2.Size = new Size(1151, 545);
            tabPage2.TabIndex = 1;
            tabPage2.Text = "From Screen";
            tabPage2.UseVisualStyleBackColor = true;
            // 
            // txbOutLeng_2
            // 
            txbOutLeng_2.Location = new Point(839, 62);
            txbOutLeng_2.Name = "txbOutLeng_2";
            txbOutLeng_2.Size = new Size(232, 39);
            txbOutLeng_2.TabIndex = 21;
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            label5.Location = new Point(487, 65);
            label5.Name = "label5";
            label5.Size = new Size(346, 32);
            label5.TabIndex = 20;
            label5.Text = "Output Length (SHAKE only):";
            // 
            // btnHash_2
            // 
            btnHash_2.BackColor = Color.DarkOrange;
            btnHash_2.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            btnHash_2.ForeColor = Color.White;
            btnHash_2.Location = new Point(442, 269);
            btnHash_2.Name = "btnHash_2";
            btnHash_2.Size = new Size(255, 70);
            btnHash_2.TabIndex = 19;
            btnHash_2.Text = "HASH";
            btnHash_2.UseVisualStyleBackColor = false;
            btnHash_2.Click += btnHash_2_Click;
            // 
            // txbOutput_2
            // 
            txbOutput_2.Location = new Point(199, 399);
            txbOutput_2.Multiline = true;
            txbOutput_2.Name = "txbOutput_2";
            txbOutput_2.Size = new Size(872, 70);
            txbOutput_2.TabIndex = 16;
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            label6.Location = new Point(55, 417);
            label6.Name = "label6";
            label6.Size = new Size(102, 32);
            label6.TabIndex = 15;
            label6.Text = "Output:";
            // 
            // label7
            // 
            label7.AutoSize = true;
            label7.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            label7.Location = new Point(55, 158);
            label7.Name = "label7";
            label7.Size = new Size(83, 32);
            label7.TabIndex = 14;
            label7.Text = "Input:";
            // 
            // txbInput_2
            // 
            txbInput_2.Location = new Point(199, 138);
            txbInput_2.Multiline = true;
            txbInput_2.Name = "txbInput_2";
            txbInput_2.Size = new Size(872, 70);
            txbInput_2.TabIndex = 13;
            // 
            // label8
            // 
            label8.AutoSize = true;
            label8.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            label8.Location = new Point(55, 65);
            label8.Name = "label8";
            label8.Size = new Size(138, 32);
            label8.TabIndex = 12;
            label8.Text = "Hash Type:";
            // 
            // cbType_2
            // 
            cbType_2.DropDownStyle = ComboBoxStyle.DropDownList;
            cbType_2.FlatStyle = FlatStyle.Flat;
            cbType_2.FormattingEnabled = true;
            cbType_2.Items.AddRange(new object[] { "SHA_224", "SHA_256", "SHA_512", "SHA3_224", "SHA3_256", "SHA3_384", "SHA3_512", "SHAKE128", "SHAKE256" });
            cbType_2.Location = new Point(199, 62);
            cbType_2.Name = "cbType_2";
            cbType_2.Size = new Size(232, 40);
            cbType_2.TabIndex = 11;
            // 
            // Home
            // 
            AutoScaleDimensions = new SizeF(13F, 32F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(1172, 602);
            Controls.Add(tabControl1);
            Name = "Home";
            StartPosition = FormStartPosition.CenterScreen;
            tabControl1.ResumeLayout(false);
            tabPage1.ResumeLayout(false);
            tabPage1.PerformLayout();
            tabPage2.ResumeLayout(false);
            tabPage2.PerformLayout();
            ResumeLayout(false);
        }

        #endregion

        private TabControl tabControl1;
        private TabPage tabPage1;
        private Label label1;
        private ComboBox comboBox1;
        private TabPage tabPage2;
        private TextBox txbInput;
        private Button btnOpenOutput;
        private Button btnOpenInput;
        private TextBox txbOutput;
        private Label label3;
        private Label label2;
        private Button btnHash;
        private Label label4;
        private Label label5;
        private Button btnHash_2;
        private TextBox txbOutput_2;
        private Label label6;
        private Label label7;
        private TextBox txbInput_2;
        private Label label8;
        private ComboBox cbType_2;
        private TextBox txbOutLeng;
        private TextBox txbOutLeng_2;
    }
}
