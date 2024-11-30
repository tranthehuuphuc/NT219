namespace AES_DES
{
    partial class DES
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
            CipherEnc = new TextBox();
            label8 = new Label();
            Plain = new TextBox();
            label7 = new Label();
            label4 = new Label();
            label5 = new Label();
            IVEnc = new TextBox();
            KeyEnc = new TextBox();
            label6 = new Label();
            ModeEnc = new ComboBox();
            groupBox2 = new GroupBox();
            Encrypt = new Button();
            label3 = new Label();
            label2 = new Label();
            IVGen = new TextBox();
            KeyGen = new TextBox();
            Generate = new Button();
            label1 = new Label();
            KeySize = new ComboBox();
            groupBox1 = new GroupBox();
            groupBox3.SuspendLayout();
            groupBox2.SuspendLayout();
            groupBox1.SuspendLayout();
            SuspendLayout();
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
            groupBox3.Location = new Point(49, 682);
            groupBox3.Name = "groupBox3";
            groupBox3.Size = new Size(1813, 404);
            groupBox3.TabIndex = 14;
            groupBox3.TabStop = false;
            groupBox3.Text = "DES Decryption";
            // 
            // Recovered
            // 
            Recovered.Location = new Point(185, 322);
            Recovered.Name = "Recovered";
            Recovered.Size = new Size(1577, 39);
            Recovered.TabIndex = 10;
            // 
            // label9
            // 
            label9.AutoSize = true;
            label9.Location = new Point(43, 325);
            label9.Name = "label9";
            label9.Size = new Size(130, 32);
            label9.TabIndex = 9;
            label9.Text = "Recovered:";
            // 
            // CipherDec
            // 
            CipherDec.Location = new Point(185, 134);
            CipherDec.Name = "CipherDec";
            CipherDec.Size = new Size(1577, 39);
            CipherDec.TabIndex = 8;
            // 
            // label10
            // 
            label10.AutoSize = true;
            label10.Location = new Point(43, 137);
            label10.Name = "label10";
            label10.Size = new Size(136, 32);
            label10.TabIndex = 7;
            label10.Text = "Cipher text:";
            // 
            // label11
            // 
            label11.AutoSize = true;
            label11.Location = new Point(775, 61);
            label11.Name = "label11";
            label11.Size = new Size(40, 32);
            label11.TabIndex = 6;
            label11.Text = "IV:";
            // 
            // label12
            // 
            label12.AutoSize = true;
            label12.Location = new Point(43, 61);
            label12.Name = "label12";
            label12.Size = new Size(58, 32);
            label12.TabIndex = 5;
            label12.Text = "Key:";
            // 
            // IVDec
            // 
            IVDec.Location = new Point(839, 58);
            IVDec.Name = "IVDec";
            IVDec.Size = new Size(577, 39);
            IVDec.TabIndex = 4;
            // 
            // KeyDec
            // 
            KeyDec.Location = new Point(127, 58);
            KeyDec.Name = "KeyDec";
            KeyDec.Size = new Size(577, 39);
            KeyDec.TabIndex = 3;
            // 
            // Decrypt
            // 
            Decrypt.BackColor = Color.WhiteSmoke;
            Decrypt.Location = new Point(801, 212);
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
            label13.Location = new Point(1511, 61);
            label13.Name = "label13";
            label13.Size = new Size(82, 32);
            label13.TabIndex = 1;
            label13.Text = "Mode:";
            // 
            // ModeDec
            // 
            ModeDec.FormattingEnabled = true;
            ModeDec.Items.AddRange(new object[] { "ECB", "CBC", "CFB", "OFB", "CTR" });
            ModeDec.Location = new Point(1599, 58);
            ModeDec.Name = "ModeDec";
            ModeDec.Size = new Size(163, 40);
            ModeDec.TabIndex = 0;
            ModeDec.Text = "CBC";
            // 
            // CipherEnc
            // 
            CipherEnc.Location = new Point(185, 323);
            CipherEnc.Name = "CipherEnc";
            CipherEnc.Size = new Size(1577, 39);
            CipherEnc.TabIndex = 10;
            // 
            // label8
            // 
            label8.AutoSize = true;
            label8.Location = new Point(43, 326);
            label8.Name = "label8";
            label8.Size = new Size(136, 32);
            label8.TabIndex = 9;
            label8.Text = "Cipher text:";
            // 
            // Plain
            // 
            Plain.Location = new Point(185, 131);
            Plain.Name = "Plain";
            Plain.Size = new Size(1577, 39);
            Plain.TabIndex = 8;
            // 
            // label7
            // 
            label7.AutoSize = true;
            label7.Location = new Point(43, 134);
            label7.Name = "label7";
            label7.Size = new Size(117, 32);
            label7.TabIndex = 7;
            label7.Text = "Plain text:";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(775, 60);
            label4.Name = "label4";
            label4.Size = new Size(40, 32);
            label4.TabIndex = 6;
            label4.Text = "IV:";
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Location = new Point(43, 60);
            label5.Name = "label5";
            label5.Size = new Size(58, 32);
            label5.TabIndex = 5;
            label5.Text = "Key:";
            // 
            // IVEnc
            // 
            IVEnc.Location = new Point(839, 57);
            IVEnc.Name = "IVEnc";
            IVEnc.Size = new Size(577, 39);
            IVEnc.TabIndex = 4;
            // 
            // KeyEnc
            // 
            KeyEnc.Location = new Point(127, 57);
            KeyEnc.Name = "KeyEnc";
            KeyEnc.Size = new Size(577, 39);
            KeyEnc.TabIndex = 3;
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Location = new Point(1511, 60);
            label6.Name = "label6";
            label6.Size = new Size(82, 32);
            label6.TabIndex = 1;
            label6.Text = "Mode:";
            // 
            // ModeEnc
            // 
            ModeEnc.FormattingEnabled = true;
            ModeEnc.Items.AddRange(new object[] { "ECB", "CBC", "CFB", "OFB", "CTR" });
            ModeEnc.Location = new Point(1599, 57);
            ModeEnc.Name = "ModeEnc";
            ModeEnc.Size = new Size(163, 40);
            ModeEnc.TabIndex = 0;
            ModeEnc.Text = "CBC";
            ModeEnc.SelectedIndexChanged += ModeEnc_SelectedIndexChanged;
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
            groupBox2.Location = new Point(49, 251);
            groupBox2.Name = "groupBox2";
            groupBox2.Size = new Size(1813, 405);
            groupBox2.TabIndex = 13;
            groupBox2.TabStop = false;
            groupBox2.Text = "DES Encryption";
            // 
            // Encrypt
            // 
            Encrypt.BackColor = Color.WhiteSmoke;
            Encrypt.Location = new Point(801, 205);
            Encrypt.Name = "Encrypt";
            Encrypt.Size = new Size(204, 79);
            Encrypt.TabIndex = 2;
            Encrypt.Text = "Encrypt";
            Encrypt.UseVisualStyleBackColor = false;
            Encrypt.Click += Encrypt_Click;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(775, 116);
            label3.Name = "label3";
            label3.Size = new Size(40, 32);
            label3.TabIndex = 6;
            label3.Text = "IV:";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(775, 47);
            label2.Name = "label2";
            label2.Size = new Size(58, 32);
            label2.TabIndex = 5;
            label2.Text = "Key:";
            // 
            // IVGen
            // 
            IVGen.Location = new Point(839, 113);
            IVGen.Name = "IVGen";
            IVGen.Size = new Size(923, 39);
            IVGen.TabIndex = 4;
            // 
            // KeyGen
            // 
            KeyGen.Location = new Point(839, 44);
            KeyGen.Name = "KeyGen";
            KeyGen.Size = new Size(923, 39);
            KeyGen.TabIndex = 3;
            // 
            // Generate
            // 
            Generate.BackColor = Color.WhiteSmoke;
            Generate.Location = new Point(500, 57);
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
            KeySize.Items.AddRange(new object[] { "128 bits" });
            KeySize.Location = new Point(157, 77);
            KeySize.Name = "KeySize";
            KeySize.Size = new Size(242, 40);
            KeySize.TabIndex = 0;
            KeySize.Text = "128 bits";
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
            groupBox1.Location = new Point(49, 31);
            groupBox1.Name = "groupBox1";
            groupBox1.Size = new Size(1813, 188);
            groupBox1.TabIndex = 12;
            groupBox1.TabStop = false;
            groupBox1.Text = "Key Generation";
            // 
            // DES
            // 
            AutoScaleDimensions = new SizeF(13F, 32F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.White;
            ClientSize = new Size(1914, 1126);
            Controls.Add(groupBox3);
            Controls.Add(groupBox2);
            Controls.Add(groupBox1);
            Font = new Font("Segoe UI", 9F, FontStyle.Regular, GraphicsUnit.Point, 0);
            Name = "DES";
            Text = "DES";
            groupBox3.ResumeLayout(false);
            groupBox3.PerformLayout();
            groupBox2.ResumeLayout(false);
            groupBox2.PerformLayout();
            groupBox1.ResumeLayout(false);
            groupBox1.PerformLayout();
            ResumeLayout(false);
        }

        #endregion

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
        private TextBox CipherEnc;
        private Label label8;
        private TextBox Plain;
        private Label label7;
        private Label label4;
        private Label label5;
        private TextBox IVEnc;
        private TextBox KeyEnc;
        private Label label6;
        private ComboBox ModeEnc;
        private GroupBox groupBox2;
        private Button Encrypt;
        private Label label3;
        private Label label2;
        private TextBox IVGen;
        private TextBox KeyGen;
        private Button Generate;
        private Label label1;
        private ComboBox KeySize;
        private GroupBox groupBox1;
    }
}