namespace RSA_DigitalSign_GUI
{
    partial class Form1
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
            txbKeySize = new TextBox();
            label10 = new Label();
            btnGenKey = new Button();
            btnPublicKey = new Button();
            btnPrivateKey = new Button();
            txbPub = new TextBox();
            label3 = new Label();
            label2 = new Label();
            txbPri = new TextBox();
            label1 = new Label();
            cbFormatKey = new ComboBox();
            tabPage2 = new TabPage();
            btnSign2 = new Button();
            label7 = new Label();
            txbSign2 = new TextBox();
            btnFile2 = new Button();
            label6 = new Label();
            txbFile2 = new TextBox();
            btnSign = new Button();
            btnPri2 = new Button();
            label5 = new Label();
            txbPrivateKey2 = new TextBox();
            tabPage3 = new TabPage();
            btnSign3 = new Button();
            label4 = new Label();
            txbSign3 = new TextBox();
            btnVerify3 = new Button();
            label8 = new Label();
            txbVerify3 = new TextBox();
            btnVerify = new Button();
            btnPub3 = new Button();
            label9 = new Label();
            txbPublicKey3 = new TextBox();
            tabControl1.SuspendLayout();
            tabPage1.SuspendLayout();
            tabPage2.SuspendLayout();
            tabPage3.SuspendLayout();
            SuspendLayout();
            // 
            // tabControl1
            // 
            tabControl1.Controls.Add(tabPage1);
            tabControl1.Controls.Add(tabPage2);
            tabControl1.Controls.Add(tabPage3);
            tabControl1.Location = new Point(11, 10);
            tabControl1.Name = "tabControl1";
            tabControl1.SelectedIndex = 0;
            tabControl1.Size = new Size(1094, 730);
            tabControl1.TabIndex = 1;
            // 
            // tabPage1
            // 
            tabPage1.Controls.Add(txbKeySize);
            tabPage1.Controls.Add(label10);
            tabPage1.Controls.Add(btnGenKey);
            tabPage1.Controls.Add(btnPublicKey);
            tabPage1.Controls.Add(btnPrivateKey);
            tabPage1.Controls.Add(txbPub);
            tabPage1.Controls.Add(label3);
            tabPage1.Controls.Add(label2);
            tabPage1.Controls.Add(txbPri);
            tabPage1.Controls.Add(label1);
            tabPage1.Controls.Add(cbFormatKey);
            tabPage1.Location = new Point(8, 46);
            tabPage1.Name = "tabPage1";
            tabPage1.Padding = new Padding(3);
            tabPage1.Size = new Size(1078, 676);
            tabPage1.TabIndex = 0;
            tabPage1.Text = "Key Gen";
            tabPage1.UseVisualStyleBackColor = true;
            // 
            // txbKeySize
            // 
            txbKeySize.Location = new Point(686, 39);
            txbKeySize.Name = "txbKeySize";
            txbKeySize.Size = new Size(302, 39);
            txbKeySize.TabIndex = 10;
            // 
            // label10
            // 
            label10.AutoSize = true;
            label10.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            label10.Location = new Point(565, 42);
            label10.Name = "label10";
            label10.Size = new Size(115, 32);
            label10.TabIndex = 9;
            label10.Text = "Key Size:";
            // 
            // btnGenKey
            // 
            btnGenKey.BackColor = Color.DarkOrange;
            btnGenKey.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            btnGenKey.ForeColor = Color.White;
            btnGenKey.Location = new Point(417, 510);
            btnGenKey.Name = "btnGenKey";
            btnGenKey.Size = new Size(273, 81);
            btnGenKey.TabIndex = 8;
            btnGenKey.Text = "Generate";
            btnGenKey.UseVisualStyleBackColor = false;
            btnGenKey.Click += btnGenKey_Click;
            // 
            // btnPublicKey
            // 
            btnPublicKey.BackColor = Color.SlateGray;
            btnPublicKey.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            btnPublicKey.ForeColor = Color.White;
            btnPublicKey.Location = new Point(807, 353);
            btnPublicKey.Name = "btnPublicKey";
            btnPublicKey.Size = new Size(181, 81);
            btnPublicKey.TabIndex = 7;
            btnPublicKey.Text = "Browse";
            btnPublicKey.UseVisualStyleBackColor = false;
            btnPublicKey.Click += btnPublicKey_Click;
            // 
            // btnPrivateKey
            // 
            btnPrivateKey.BackColor = Color.SlateGray;
            btnPrivateKey.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            btnPrivateKey.ForeColor = Color.White;
            btnPrivateKey.Location = new Point(807, 169);
            btnPrivateKey.Name = "btnPrivateKey";
            btnPrivateKey.Size = new Size(181, 81);
            btnPrivateKey.TabIndex = 6;
            btnPrivateKey.Text = "Browse";
            btnPrivateKey.UseVisualStyleBackColor = false;
            btnPrivateKey.Click += btnPrivateKey_Click;
            // 
            // txbPub
            // 
            txbPub.Location = new Point(40, 353);
            txbPub.Multiline = true;
            txbPub.Name = "txbPub";
            txbPub.Size = new Size(688, 81);
            txbPub.TabIndex = 5;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            label3.Location = new Point(40, 309);
            label3.Name = "label3";
            label3.Size = new Size(187, 32);
            label3.TabIndex = 4;
            label3.Text = "Public Key File:";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            label2.Location = new Point(40, 128);
            label2.Name = "label2";
            label2.Size = new Size(196, 32);
            label2.TabIndex = 3;
            label2.Text = "Private Key File:";
            // 
            // txbPri
            // 
            txbPri.Location = new Point(40, 169);
            txbPri.Multiline = true;
            txbPri.Name = "txbPri";
            txbPri.Size = new Size(688, 81);
            txbPri.TabIndex = 2;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            label1.Location = new Point(40, 42);
            label1.Name = "label1";
            label1.Size = new Size(151, 32);
            label1.TabIndex = 1;
            label1.Text = "Key Format:";
            // 
            // cbFormatKey
            // 
            cbFormatKey.DropDownStyle = ComboBoxStyle.DropDownList;
            cbFormatKey.FlatStyle = FlatStyle.Popup;
            cbFormatKey.FormattingEnabled = true;
            cbFormatKey.Items.AddRange(new object[] { "PEM", "DER" });
            cbFormatKey.Location = new Point(197, 39);
            cbFormatKey.Name = "cbFormatKey";
            cbFormatKey.Size = new Size(316, 40);
            cbFormatKey.TabIndex = 0;
            // 
            // tabPage2
            // 
            tabPage2.Controls.Add(btnSign2);
            tabPage2.Controls.Add(label7);
            tabPage2.Controls.Add(txbSign2);
            tabPage2.Controls.Add(btnFile2);
            tabPage2.Controls.Add(label6);
            tabPage2.Controls.Add(txbFile2);
            tabPage2.Controls.Add(btnSign);
            tabPage2.Controls.Add(btnPri2);
            tabPage2.Controls.Add(label5);
            tabPage2.Controls.Add(txbPrivateKey2);
            tabPage2.Location = new Point(8, 46);
            tabPage2.Name = "tabPage2";
            tabPage2.Padding = new Padding(3);
            tabPage2.Size = new Size(1078, 676);
            tabPage2.TabIndex = 1;
            tabPage2.Text = "Sign";
            tabPage2.UseVisualStyleBackColor = true;
            // 
            // btnSign2
            // 
            btnSign2.BackColor = Color.SlateGray;
            btnSign2.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            btnSign2.ForeColor = Color.White;
            btnSign2.Location = new Point(801, 421);
            btnSign2.Name = "btnSign2";
            btnSign2.Size = new Size(181, 81);
            btnSign2.TabIndex = 21;
            btnSign2.Text = "Browse";
            btnSign2.UseVisualStyleBackColor = false;
            btnSign2.Click += btnSign2_Click;
            // 
            // label7
            // 
            label7.AutoSize = true;
            label7.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            label7.Location = new Point(78, 383);
            label7.Name = "label7";
            label7.Size = new Size(177, 32);
            label7.TabIndex = 20;
            label7.Text = "Signature File:";
            // 
            // txbSign2
            // 
            txbSign2.Location = new Point(78, 421);
            txbSign2.Multiline = true;
            txbSign2.Name = "txbSign2";
            txbSign2.Size = new Size(688, 81);
            txbSign2.TabIndex = 19;
            // 
            // btnFile2
            // 
            btnFile2.BackColor = Color.SlateGray;
            btnFile2.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            btnFile2.ForeColor = Color.White;
            btnFile2.Location = new Point(801, 253);
            btnFile2.Name = "btnFile2";
            btnFile2.Size = new Size(181, 81);
            btnFile2.TabIndex = 18;
            btnFile2.Text = "Browse";
            btnFile2.UseVisualStyleBackColor = false;
            btnFile2.Click += btnFile2_Click;
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            label6.Location = new Point(78, 209);
            label6.Name = "label6";
            label6.Size = new Size(129, 32);
            label6.TabIndex = 17;
            label6.Text = "Input File:";
            // 
            // txbFile2
            // 
            txbFile2.Location = new Point(78, 253);
            txbFile2.Multiline = true;
            txbFile2.Name = "txbFile2";
            txbFile2.Size = new Size(688, 81);
            txbFile2.TabIndex = 16;
            // 
            // btnSign
            // 
            btnSign.BackColor = Color.DarkOrange;
            btnSign.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            btnSign.ForeColor = Color.White;
            btnSign.Location = new Point(415, 557);
            btnSign.Name = "btnSign";
            btnSign.Size = new Size(273, 81);
            btnSign.TabIndex = 15;
            btnSign.Text = "Sign";
            btnSign.UseVisualStyleBackColor = false;
            btnSign.Click += button1_Click;
            // 
            // btnPri2
            // 
            btnPri2.BackColor = Color.SlateGray;
            btnPri2.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            btnPri2.ForeColor = Color.White;
            btnPri2.Location = new Point(801, 82);
            btnPri2.Name = "btnPri2";
            btnPri2.Size = new Size(181, 81);
            btnPri2.TabIndex = 13;
            btnPri2.Text = "Browse";
            btnPri2.UseVisualStyleBackColor = false;
            btnPri2.Click += btnPri2_Click;
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            label5.Location = new Point(78, 35);
            label5.Name = "label5";
            label5.Size = new Size(196, 32);
            label5.TabIndex = 10;
            label5.Text = "Private Key File:";
            // 
            // txbPrivateKey2
            // 
            txbPrivateKey2.Location = new Point(78, 82);
            txbPrivateKey2.Multiline = true;
            txbPrivateKey2.Name = "txbPrivateKey2";
            txbPrivateKey2.Size = new Size(688, 81);
            txbPrivateKey2.TabIndex = 9;
            // 
            // tabPage3
            // 
            tabPage3.Controls.Add(btnSign3);
            tabPage3.Controls.Add(label4);
            tabPage3.Controls.Add(txbSign3);
            tabPage3.Controls.Add(btnVerify3);
            tabPage3.Controls.Add(label8);
            tabPage3.Controls.Add(txbVerify3);
            tabPage3.Controls.Add(btnVerify);
            tabPage3.Controls.Add(btnPub3);
            tabPage3.Controls.Add(label9);
            tabPage3.Controls.Add(txbPublicKey3);
            tabPage3.Location = new Point(8, 46);
            tabPage3.Name = "tabPage3";
            tabPage3.Padding = new Padding(3);
            tabPage3.Size = new Size(1078, 676);
            tabPage3.TabIndex = 2;
            tabPage3.Text = "Verify";
            tabPage3.UseVisualStyleBackColor = true;
            // 
            // btnSign3
            // 
            btnSign3.BackColor = Color.SlateGray;
            btnSign3.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            btnSign3.ForeColor = Color.White;
            btnSign3.Location = new Point(810, 435);
            btnSign3.Name = "btnSign3";
            btnSign3.Size = new Size(181, 81);
            btnSign3.TabIndex = 31;
            btnSign3.Text = "Browse";
            btnSign3.UseVisualStyleBackColor = false;
            btnSign3.Click += btnSign3_Click;
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            label4.Location = new Point(90, 391);
            label4.Name = "label4";
            label4.Size = new Size(177, 32);
            label4.TabIndex = 30;
            label4.Text = "Signature File:";
            // 
            // txbSign3
            // 
            txbSign3.Location = new Point(87, 435);
            txbSign3.Multiline = true;
            txbSign3.Name = "txbSign3";
            txbSign3.Size = new Size(688, 81);
            txbSign3.TabIndex = 29;
            // 
            // btnVerify3
            // 
            btnVerify3.BackColor = Color.SlateGray;
            btnVerify3.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            btnVerify3.ForeColor = Color.White;
            btnVerify3.Location = new Point(810, 254);
            btnVerify3.Name = "btnVerify3";
            btnVerify3.Size = new Size(181, 81);
            btnVerify3.TabIndex = 28;
            btnVerify3.Text = "Browse";
            btnVerify3.UseVisualStyleBackColor = false;
            btnVerify3.Click += btnVerify3_Click;
            // 
            // label8
            // 
            label8.AutoSize = true;
            label8.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            label8.Location = new Point(90, 210);
            label8.Name = "label8";
            label8.Size = new Size(164, 32);
            label8.TabIndex = 27;
            label8.Text = "File to Verify:";
            // 
            // txbVerify3
            // 
            txbVerify3.Location = new Point(87, 254);
            txbVerify3.Multiline = true;
            txbVerify3.Name = "txbVerify3";
            txbVerify3.Size = new Size(688, 81);
            txbVerify3.TabIndex = 26;
            // 
            // btnVerify
            // 
            btnVerify.BackColor = Color.DarkOrange;
            btnVerify.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            btnVerify.ForeColor = Color.White;
            btnVerify.Location = new Point(422, 559);
            btnVerify.Name = "btnVerify";
            btnVerify.Size = new Size(273, 81);
            btnVerify.TabIndex = 25;
            btnVerify.Text = "Verify";
            btnVerify.UseVisualStyleBackColor = false;
            btnVerify.Click += btnVerify_Click;
            // 
            // btnPub3
            // 
            btnPub3.BackColor = Color.SlateGray;
            btnPub3.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            btnPub3.ForeColor = Color.White;
            btnPub3.Location = new Point(810, 77);
            btnPub3.Name = "btnPub3";
            btnPub3.Size = new Size(181, 81);
            btnPub3.TabIndex = 24;
            btnPub3.Text = "Browse";
            btnPub3.UseVisualStyleBackColor = false;
            btnPub3.Click += btnPub3_Click;
            // 
            // label9
            // 
            label9.AutoSize = true;
            label9.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            label9.Location = new Point(90, 33);
            label9.Name = "label9";
            label9.Size = new Size(187, 32);
            label9.TabIndex = 23;
            label9.Text = "Public Key File:";
            // 
            // txbPublicKey3
            // 
            txbPublicKey3.Location = new Point(87, 77);
            txbPublicKey3.Multiline = true;
            txbPublicKey3.Name = "txbPublicKey3";
            txbPublicKey3.Size = new Size(688, 81);
            txbPublicKey3.TabIndex = 22;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(13F, 32F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(1117, 750);
            Controls.Add(tabControl1);
            Name = "Form1";
            StartPosition = FormStartPosition.CenterScreen;
            Text = "Home";
            tabControl1.ResumeLayout(false);
            tabPage1.ResumeLayout(false);
            tabPage1.PerformLayout();
            tabPage2.ResumeLayout(false);
            tabPage2.PerformLayout();
            tabPage3.ResumeLayout(false);
            tabPage3.PerformLayout();
            ResumeLayout(false);
        }

        #endregion

        private TabControl tabControl1;
        private TabPage tabPage1;
        private TextBox txbKeySize;
        private Label label10;
        private Button btnGenKey;
        private Button btnPublicKey;
        private Button btnPrivateKey;
        private TextBox txbPub;
        private Label label3;
        private Label label2;
        private TextBox txbPri;
        private Label label1;
        private ComboBox cbFormatKey;
        private TabPage tabPage2;
        private Button btnSign2;
        private Label label7;
        private TextBox txbSign2;
        private Button btnFile2;
        private Label label6;
        private TextBox txbFile2;
        private Button btnSign;
        private Button btnPri2;
        private Label label5;
        private TextBox txbPrivateKey2;
        private TabPage tabPage3;
        private Button btnSign3;
        private Label label4;
        private TextBox txbSign3;
        private Button btnVerify3;
        private Label label8;
        private TextBox txbVerify3;
        private Button btnVerify;
        private Button btnPub3;
        private Label label9;
        private TextBox txbPublicKey3;
    }
}
