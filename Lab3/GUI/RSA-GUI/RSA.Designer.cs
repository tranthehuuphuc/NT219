namespace RSA_GUI
{
    partial class RSA
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
            groupBox1 = new GroupBox();
            AutoButton = new Button();
            label3 = new Label();
            label2 = new Label();
            label1 = new Label();
            PubKeyGen = new TextBox();
            PriKeyGen = new TextBox();
            GenerateButton = new Button();
            KeySize = new ComboBox();
            groupBox2 = new GroupBox();
            label6 = new Label();
            CipherEnc = new TextBox();
            EncyptButton = new Button();
            label5 = new Label();
            Plain = new TextBox();
            label4 = new Label();
            PubKeyEnc = new TextBox();
            groupBox3 = new GroupBox();
            label7 = new Label();
            Recovered = new TextBox();
            DecryptButton = new Button();
            label8 = new Label();
            CipherDec = new TextBox();
            label9 = new Label();
            PriKeyDec = new TextBox();
            label10 = new Label();
            AutoCipherButton = new Button();
            groupBox1.SuspendLayout();
            groupBox2.SuspendLayout();
            groupBox3.SuspendLayout();
            SuspendLayout();
            // 
            // groupBox1
            // 
            groupBox1.Controls.Add(AutoButton);
            groupBox1.Controls.Add(label3);
            groupBox1.Controls.Add(label2);
            groupBox1.Controls.Add(label1);
            groupBox1.Controls.Add(PubKeyGen);
            groupBox1.Controls.Add(PriKeyGen);
            groupBox1.Controls.Add(GenerateButton);
            groupBox1.Controls.Add(KeySize);
            groupBox1.Location = new Point(37, 37);
            groupBox1.Name = "groupBox1";
            groupBox1.Size = new Size(1500, 234);
            groupBox1.TabIndex = 2;
            groupBox1.TabStop = false;
            groupBox1.Text = "Keys Generation";
            // 
            // AutoButton
            // 
            AutoButton.BackColor = Color.LightGray;
            AutoButton.Location = new Point(1233, 34);
            AutoButton.Name = "AutoButton";
            AutoButton.Size = new Size(234, 46);
            AutoButton.TabIndex = 7;
            AutoButton.Text = "Auto Enter Keys";
            AutoButton.UseVisualStyleBackColor = false;
            AutoButton.Click += AutoButton_Click;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(155, 42);
            label3.Name = "label3";
            label3.Size = new Size(108, 32);
            label3.TabIndex = 6;
            label3.Text = "Key Size:";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(12, 168);
            label2.Name = "label2";
            label2.Size = new Size(129, 32);
            label2.TabIndex = 5;
            label2.Text = "Public Key:";
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(12, 104);
            label1.Name = "label1";
            label1.Size = new Size(137, 32);
            label1.TabIndex = 4;
            label1.Text = "Private Key:";
            // 
            // PubKeyGen
            // 
            PubKeyGen.Location = new Point(155, 165);
            PubKeyGen.Name = "PubKeyGen";
            PubKeyGen.Size = new Size(1312, 39);
            PubKeyGen.TabIndex = 3;
            // 
            // PriKeyGen
            // 
            PriKeyGen.Location = new Point(155, 101);
            PriKeyGen.Name = "PriKeyGen";
            PriKeyGen.Size = new Size(1312, 39);
            PriKeyGen.TabIndex = 2;
            // 
            // GenerateButton
            // 
            GenerateButton.BackColor = Color.WhiteSmoke;
            GenerateButton.Location = new Point(644, 38);
            GenerateButton.Name = "GenerateButton";
            GenerateButton.Size = new Size(206, 46);
            GenerateButton.TabIndex = 1;
            GenerateButton.Text = "Generate";
            GenerateButton.UseVisualStyleBackColor = false;
            GenerateButton.Click += GenerateButton_Click;
            // 
            // KeySize
            // 
            KeySize.FormattingEnabled = true;
            KeySize.Items.AddRange(new object[] { "3072 bits", "4096 bits", "5120 bits" });
            KeySize.Location = new Point(269, 39);
            KeySize.Name = "KeySize";
            KeySize.Size = new Size(159, 40);
            KeySize.TabIndex = 0;
            KeySize.Text = "3072 bits";
            // 
            // groupBox2
            // 
            groupBox2.Controls.Add(label6);
            groupBox2.Controls.Add(CipherEnc);
            groupBox2.Controls.Add(EncyptButton);
            groupBox2.Controls.Add(label5);
            groupBox2.Controls.Add(Plain);
            groupBox2.Controls.Add(label4);
            groupBox2.Controls.Add(PubKeyEnc);
            groupBox2.Location = new Point(38, 304);
            groupBox2.Name = "groupBox2";
            groupBox2.Size = new Size(1499, 279);
            groupBox2.TabIndex = 3;
            groupBox2.TabStop = false;
            groupBox2.Text = "RSA Encryption";
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Location = new Point(11, 224);
            label6.Name = "label6";
            label6.Size = new Size(136, 32);
            label6.TabIndex = 12;
            label6.Text = "Cipher text:";
            // 
            // CipherEnc
            // 
            CipherEnc.Location = new Point(154, 221);
            CipherEnc.Name = "CipherEnc";
            CipherEnc.Size = new Size(1312, 39);
            CipherEnc.TabIndex = 11;
            // 
            // EncyptButton
            // 
            EncyptButton.BackColor = Color.WhiteSmoke;
            EncyptButton.Location = new Point(643, 157);
            EncyptButton.Name = "EncyptButton";
            EncyptButton.Size = new Size(206, 46);
            EncyptButton.TabIndex = 7;
            EncyptButton.Text = "Encrypt";
            EncyptButton.UseVisualStyleBackColor = false;
            EncyptButton.Click += EncyptButton_Click;
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Location = new Point(11, 103);
            label5.Name = "label5";
            label5.Size = new Size(117, 32);
            label5.TabIndex = 10;
            label5.Text = "Plain text:";
            // 
            // Plain
            // 
            Plain.Location = new Point(154, 100);
            Plain.Name = "Plain";
            Plain.Size = new Size(1312, 39);
            Plain.TabIndex = 9;
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(11, 41);
            label4.Name = "label4";
            label4.Size = new Size(129, 32);
            label4.TabIndex = 8;
            label4.Text = "Public Key:";
            // 
            // PubKeyEnc
            // 
            PubKeyEnc.Location = new Point(154, 38);
            PubKeyEnc.Name = "PubKeyEnc";
            PubKeyEnc.Size = new Size(1312, 39);
            PubKeyEnc.TabIndex = 7;
            // 
            // groupBox3
            // 
            groupBox3.Controls.Add(AutoCipherButton);
            groupBox3.Controls.Add(label7);
            groupBox3.Controls.Add(Recovered);
            groupBox3.Controls.Add(DecryptButton);
            groupBox3.Controls.Add(label8);
            groupBox3.Controls.Add(CipherDec);
            groupBox3.Controls.Add(label9);
            groupBox3.Controls.Add(PriKeyDec);
            groupBox3.Location = new Point(38, 617);
            groupBox3.Name = "groupBox3";
            groupBox3.Size = new Size(1499, 279);
            groupBox3.TabIndex = 13;
            groupBox3.TabStop = false;
            groupBox3.Text = "RSA Encryption";
            // 
            // label7
            // 
            label7.AutoSize = true;
            label7.Location = new Point(11, 224);
            label7.Name = "label7";
            label7.Size = new Size(130, 32);
            label7.TabIndex = 12;
            label7.Text = "Recovered:";
            // 
            // Recovered
            // 
            Recovered.Location = new Point(154, 221);
            Recovered.Name = "Recovered";
            Recovered.Size = new Size(1312, 39);
            Recovered.TabIndex = 11;
            // 
            // DecryptButton
            // 
            DecryptButton.BackColor = Color.WhiteSmoke;
            DecryptButton.Location = new Point(643, 157);
            DecryptButton.Name = "DecryptButton";
            DecryptButton.Size = new Size(206, 46);
            DecryptButton.TabIndex = 7;
            DecryptButton.Text = "Decrypt";
            DecryptButton.UseVisualStyleBackColor = false;
            DecryptButton.Click += DecryptButton_Click;
            // 
            // label8
            // 
            label8.AutoSize = true;
            label8.Location = new Point(11, 103);
            label8.Name = "label8";
            label8.Size = new Size(136, 32);
            label8.TabIndex = 10;
            label8.Text = "Cipher text:";
            // 
            // CipherDec
            // 
            CipherDec.Location = new Point(154, 100);
            CipherDec.Name = "CipherDec";
            CipherDec.Size = new Size(1312, 39);
            CipherDec.TabIndex = 9;
            // 
            // label9
            // 
            label9.AutoSize = true;
            label9.Location = new Point(11, 41);
            label9.Name = "label9";
            label9.Size = new Size(137, 32);
            label9.TabIndex = 8;
            label9.Text = "Private Key:";
            // 
            // PriKeyDec
            // 
            PriKeyDec.Location = new Point(154, 38);
            PriKeyDec.Name = "PriKeyDec";
            PriKeyDec.Size = new Size(1312, 39);
            PriKeyDec.TabIndex = 7;
            // 
            // label10
            // 
            label10.AutoSize = true;
            label10.Location = new Point(1050, 914);
            label10.Name = "label10";
            label10.Size = new Size(487, 32);
            label10.TabIndex = 8;
            label10.Text = "* Generation Time may take several seconds";
            // 
            // AutoCipherButton
            // 
            AutoCipherButton.BackColor = Color.LightGray;
            AutoCipherButton.Location = new Point(1232, 157);
            AutoCipherButton.Name = "AutoCipherButton";
            AutoCipherButton.Size = new Size(234, 46);
            AutoCipherButton.TabIndex = 8;
            AutoCipherButton.Text = "Auto Enter Cipher";
            AutoCipherButton.UseVisualStyleBackColor = false;
            AutoCipherButton.Click += AutoCipherButton_Click;
            // 
            // RSA
            // 
            AutoScaleDimensions = new SizeF(13F, 32F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.White;
            ClientSize = new Size(1574, 963);
            Controls.Add(label10);
            Controls.Add(groupBox3);
            Controls.Add(groupBox2);
            Controls.Add(groupBox1);
            Name = "RSA";
            StartPosition = FormStartPosition.CenterScreen;
            Text = "RSA";
            groupBox1.ResumeLayout(false);
            groupBox1.PerformLayout();
            groupBox2.ResumeLayout(false);
            groupBox2.PerformLayout();
            groupBox3.ResumeLayout(false);
            groupBox3.PerformLayout();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private GroupBox groupBox1;
        private Label label3;
        private Label label2;
        private Label label1;
        private TextBox PubKeyGen;
        private TextBox PriKeyGen;
        private Button GenerateButton;
        private ComboBox KeySize;
        private GroupBox groupBox2;
        private Label label6;
        private TextBox CipherEnc;
        private Button EncyptButton;
        private Label label5;
        private TextBox Plain;
        private Label label4;
        private TextBox PubKeyEnc;
        private GroupBox groupBox3;
        private Label label7;
        private TextBox Recovered;
        private Button DecryptButton;
        private Label label8;
        private TextBox CipherDec;
        private Label label9;
        private TextBox PriKeyDec;
        private Button AutoButton;
        private Label label10;
        private Button AutoCipherButton;
    }
}