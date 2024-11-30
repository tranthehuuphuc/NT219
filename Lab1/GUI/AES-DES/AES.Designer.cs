namespace AES_DES
{
    partial class AES
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
            label3 = new Label();
            label2 = new Label();
            IVGen = new TextBox();
            KeyGen = new TextBox();
            Generate = new Button();
            label1 = new Label();
            KeySize = new ComboBox();
            groupBox2 = new GroupBox();
            CipherEnc = new TextBox();
            label8 = new Label();
            Plain = new TextBox();
            label7 = new Label();
            label4 = new Label();
            label5 = new Label();
            IVEnc = new TextBox();
            KeyEnc = new TextBox();
            Encrypt = new Button();
            label6 = new Label();
            ModeEnc = new ComboBox();
            groupBox3 = new GroupBox();
            Recovered = new TextBox();
            label9 = new Label();
            CipherDec = new TextBox();
            label10 = new Label();
            label11 = new Label();
            label12 = new Label();
            IVDec = new TextBox();
            KeyDec = new TextBox();
            Decrypt = new Button();
            label13 = new Label();
            ModeDec = new ComboBox();
            groupBox1.SuspendLayout();
            groupBox2.SuspendLayout();
            groupBox3.SuspendLayout();
            SuspendLayout();
            // 
            // groupBox1
            // 
            groupBox1.Controls.Add(label3);
            groupBox1.Controls.Add(label2);
            groupBox1.Controls.Add(IVGen);
            groupBox1.Controls.Add(KeyGen);
            groupBox1.Controls.Add(Generate);
            groupBox1.Controls.Add(label1);
            groupBox1.Controls.Add(KeySize);
            groupBox1.Font = new Font("Segoe UI", 9F, FontStyle.Regular, GraphicsUnit.Point, 0);
            groupBox1.Location = new Point(50, 33);
            groupBox1.Name = "groupBox1";
            groupBox1.Size = new Size(1816, 184);
            groupBox1.TabIndex = 0;
            groupBox1.TabStop = false;
            groupBox1.Text = "Keys Generation";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(783, 115);
            label3.Name = "label3";
            label3.Size = new Size(40, 32);
            label3.TabIndex = 6;
            label3.Text = "IV:";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(783, 41);
            label2.Name = "label2";
            label2.Size = new Size(58, 32);
            label2.TabIndex = 5;
            label2.Text = "Key:";
            // 
            // IVGen
            // 
            IVGen.Location = new Point(847, 112);
            IVGen.Name = "IVGen";
            IVGen.Size = new Size(915, 39);
            IVGen.TabIndex = 4;
            // 
            // KeyGen
            // 
            KeyGen.Location = new Point(847, 38);
            KeyGen.Name = "KeyGen";
            KeyGen.Size = new Size(915, 39);
            KeyGen.TabIndex = 3;
            // 
            // Generate
            // 
            Generate.BackColor = Color.WhiteSmoke;
            Generate.Location = new Point(471, 57);
            Generate.Name = "Generate";
            Generate.Size = new Size(204, 79);
            Generate.TabIndex = 2;
            Generate.Text = "Generate";
            Generate.UseVisualStyleBackColor = false;
            Generate.Click += Generate_Click;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(43, 80);
            label1.Name = "label1";
            label1.Size = new Size(108, 32);
            label1.TabIndex = 1;
            label1.Text = "Key Size:";
            // 
            // KeySize
            // 
            KeySize.FormattingEnabled = true;
            KeySize.Items.AddRange(new object[] { "128 bits", "192 bits", "256 bits" });
            KeySize.Location = new Point(157, 77);
            KeySize.Name = "KeySize";
            KeySize.Size = new Size(198, 40);
            KeySize.TabIndex = 0;
            KeySize.Text = "128 bits";
            // 
            // groupBox2
            // 
            groupBox2.Controls.Add(CipherEnc);
            groupBox2.Controls.Add(label8);
            groupBox2.Controls.Add(Plain);
            groupBox2.Controls.Add(label7);
            groupBox2.Controls.Add(label4);
            groupBox2.Controls.Add(label5);
            groupBox2.Controls.Add(IVEnc);
            groupBox2.Controls.Add(KeyEnc);
            groupBox2.Controls.Add(Encrypt);
            groupBox2.Controls.Add(label6);
            groupBox2.Controls.Add(ModeEnc);
            groupBox2.Font = new Font("Segoe UI", 9F, FontStyle.Regular, GraphicsUnit.Point, 0);
            groupBox2.Location = new Point(50, 251);
            groupBox2.Name = "groupBox2";
            groupBox2.Size = new Size(1816, 397);
            groupBox2.TabIndex = 7;
            groupBox2.TabStop = false;
            groupBox2.Text = "AES Encryption";
            // 
            // CipherEnc
            // 
            CipherEnc.Location = new Point(182, 316);
            CipherEnc.Name = "CipherEnc";
            CipherEnc.Size = new Size(1580, 39);
            CipherEnc.TabIndex = 10;
            // 
            // label8
            // 
            label8.AutoSize = true;
            label8.Location = new Point(43, 319);
            label8.Name = "label8";
            label8.Size = new Size(136, 32);
            label8.TabIndex = 9;
            label8.Text = "Cipher text:";
            // 
            // Plain
            // 
            Plain.Location = new Point(182, 128);
            Plain.Name = "Plain";
            Plain.Size = new Size(1580, 39);
            Plain.TabIndex = 8;
            // 
            // label7
            // 
            label7.AutoSize = true;
            label7.Location = new Point(43, 131);
            label7.Name = "label7";
            label7.Size = new Size(117, 32);
            label7.TabIndex = 7;
            label7.Text = "Plain text:";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(783, 55);
            label4.Name = "label4";
            label4.Size = new Size(40, 32);
            label4.TabIndex = 6;
            label4.Text = "IV:";
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Location = new Point(43, 55);
            label5.Name = "label5";
            label5.Size = new Size(58, 32);
            label5.TabIndex = 5;
            label5.Text = "Key:";
            // 
            // IVEnc
            // 
            IVEnc.Location = new Point(847, 52);
            IVEnc.Name = "IVEnc";
            IVEnc.Size = new Size(568, 39);
            IVEnc.TabIndex = 4;
            // 
            // KeyEnc
            // 
            KeyEnc.Location = new Point(107, 52);
            KeyEnc.Name = "KeyEnc";
            KeyEnc.Size = new Size(568, 39);
            KeyEnc.TabIndex = 3;
            // 
            // Encrypt
            // 
            Encrypt.BackColor = Color.WhiteSmoke;
            Encrypt.Location = new Point(800, 205);
            Encrypt.Name = "Encrypt";
            Encrypt.Size = new Size(204, 79);
            Encrypt.TabIndex = 2;
            Encrypt.Text = "Encrypt";
            Encrypt.UseVisualStyleBackColor = false;
            Encrypt.Click += Encrypt_Click;
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Location = new Point(1513, 55);
            label6.Name = "label6";
            label6.Size = new Size(82, 32);
            label6.TabIndex = 1;
            label6.Text = "Mode:";
            // 
            // ModeEnc
            // 
            ModeEnc.FormattingEnabled = true;
            ModeEnc.Items.AddRange(new object[] { "ECB", "CBC", "CFB", "OFB", "CTR", "XTS", "GCM", "CCM" });
            ModeEnc.Location = new Point(1599, 52);
            ModeEnc.Name = "ModeEnc";
            ModeEnc.Size = new Size(163, 40);
            ModeEnc.TabIndex = 0;
            ModeEnc.Text = "CBC";
            ModeEnc.SelectedIndexChanged += ModeEnc_SelectedIndexChanged;
            // 
            // groupBox3
            // 
            groupBox3.Controls.Add(Recovered);
            groupBox3.Controls.Add(label9);
            groupBox3.Controls.Add(CipherDec);
            groupBox3.Controls.Add(label10);
            groupBox3.Controls.Add(label11);
            groupBox3.Controls.Add(label12);
            groupBox3.Controls.Add(IVDec);
            groupBox3.Controls.Add(KeyDec);
            groupBox3.Controls.Add(Decrypt);
            groupBox3.Controls.Add(label13);
            groupBox3.Controls.Add(ModeDec);
            groupBox3.Font = new Font("Segoe UI", 9F, FontStyle.Regular, GraphicsUnit.Point, 0);
            groupBox3.Location = new Point(50, 682);
            groupBox3.Name = "groupBox3";
            groupBox3.Size = new Size(1816, 400);
            groupBox3.TabIndex = 11;
            groupBox3.TabStop = false;
            groupBox3.Text = "AES Decryption";
            // 
            // Recovered
            // 
            Recovered.Location = new Point(182, 320);
            Recovered.Name = "Recovered";
            Recovered.Size = new Size(1580, 39);
            Recovered.TabIndex = 10;
            // 
            // label9
            // 
            label9.AutoSize = true;
            label9.Location = new Point(46, 323);
            label9.Name = "label9";
            label9.Size = new Size(130, 32);
            label9.TabIndex = 9;
            label9.Text = "Recovered:";
            // 
            // CipherDec
            // 
            CipherDec.Location = new Point(182, 131);
            CipherDec.Name = "CipherDec";
            CipherDec.Size = new Size(1580, 39);
            CipherDec.TabIndex = 8;
            // 
            // label10
            // 
            label10.AutoSize = true;
            label10.Location = new Point(43, 134);
            label10.Name = "label10";
            label10.Size = new Size(136, 32);
            label10.TabIndex = 7;
            label10.Text = "Cipher text:";
            // 
            // label11
            // 
            label11.AutoSize = true;
            label11.Location = new Point(783, 57);
            label11.Name = "label11";
            label11.Size = new Size(40, 32);
            label11.TabIndex = 6;
            label11.Text = "IV:";
            // 
            // label12
            // 
            label12.AutoSize = true;
            label12.Location = new Point(43, 57);
            label12.Name = "label12";
            label12.Size = new Size(58, 32);
            label12.TabIndex = 5;
            label12.Text = "Key:";
            // 
            // IVDec
            // 
            IVDec.Location = new Point(847, 54);
            IVDec.Name = "IVDec";
            IVDec.Size = new Size(568, 39);
            IVDec.TabIndex = 4;
            // 
            // KeyDec
            // 
            KeyDec.Location = new Point(107, 54);
            KeyDec.Name = "KeyDec";
            KeyDec.Size = new Size(568, 39);
            KeyDec.TabIndex = 3;
            // 
            // Decrypt
            // 
            Decrypt.BackColor = Color.WhiteSmoke;
            Decrypt.Location = new Point(800, 206);
            Decrypt.Name = "Decrypt";
            Decrypt.Size = new Size(204, 79);
            Decrypt.TabIndex = 2;
            Decrypt.Text = "Decrypt";
            Decrypt.UseVisualStyleBackColor = false;
            Decrypt.Click += Decrypt_Click;
            // 
            // label13
            // 
            label13.AutoSize = true;
            label13.Location = new Point(1513, 57);
            label13.Name = "label13";
            label13.Size = new Size(82, 32);
            label13.TabIndex = 1;
            label13.Text = "Mode:";
            // 
            // ModeDec
            // 
            ModeDec.FormattingEnabled = true;
            ModeDec.Items.AddRange(new object[] { "ECB", "CBC", "CFB", "OFB", "CTR", "XTS", "GCM", "CCM" });
            ModeDec.Location = new Point(1599, 54);
            ModeDec.Name = "ModeDec";
            ModeDec.Size = new Size(163, 40);
            ModeDec.TabIndex = 0;
            ModeDec.Text = "CBC";
            // 
            // AES
            // 
            AutoScaleDimensions = new SizeF(13F, 32F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.White;
            ClientSize = new Size(1914, 1126);
            Controls.Add(groupBox3);
            Controls.Add(groupBox2);
            Controls.Add(groupBox1);
            Name = "AES";
            Text = "AES";
            groupBox1.ResumeLayout(false);
            groupBox1.PerformLayout();
            groupBox2.ResumeLayout(false);
            groupBox2.PerformLayout();
            groupBox3.ResumeLayout(false);
            groupBox3.PerformLayout();
            ResumeLayout(false);
        }

        #endregion

        private GroupBox groupBox1;
        private ComboBox KeySize;
        private Label label3;
        private Label label2;
        private TextBox IVGen;
        private TextBox KeyGen;
        private Button Generate;
        private Label label1;
        private GroupBox groupBox2;
        private Label label4;
        private Label label5;
        private TextBox IVEnc;
        private TextBox KeyEnc;
        private Button Encrypt;
        private Label label6;
        private ComboBox ModeEnc;
        private TextBox CipherEnc;
        private Label label8;
        private TextBox Plain;
        private Label label7;
        private GroupBox groupBox3;
        private TextBox Recovered;
        private Label label9;
        private TextBox CipherDec;
        private Label label10;
        private Label label11;
        private Label label12;
        private TextBox IVDec;
        private TextBox KeyDec;
        private Button Decrypt;
        private Label label13;
        private ComboBox ModeDec;
    }
}