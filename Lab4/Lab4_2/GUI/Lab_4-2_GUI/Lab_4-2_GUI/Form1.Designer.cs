namespace Lab_4_2_GUI
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
            btnCheck = new Button();
            btnOpenOutput = new Button();
            btnOpenCA = new Button();
            txbOutput = new TextBox();
            label3 = new Label();
            label2 = new Label();
            txbCA = new TextBox();
            label1 = new Label();
            cbFormat = new ComboBox();
            btnOpenImm = new Button();
            label4 = new Label();
            txbImm = new TextBox();
            btnOpenWebsiteCert = new Button();
            label5 = new Label();
            txbWebCert = new TextBox();
            richTextBox1 = new RichTextBox();
            SuspendLayout();
            // 
            // btnCheck
            // 
            btnCheck.BackColor = Color.DarkOrange;
            btnCheck.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            btnCheck.ForeColor = Color.White;
            btnCheck.Location = new Point(295, 810);
            btnCheck.Name = "btnCheck";
            btnCheck.Size = new Size(255, 70);
            btnCheck.TabIndex = 19;
            btnCheck.Text = "Verify";
            btnCheck.UseVisualStyleBackColor = false;
            btnCheck.Click += btnCheck_Click;
            // 
            // btnOpenOutput
            // 
            btnOpenOutput.BackColor = Color.SlateGray;
            btnOpenOutput.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            btnOpenOutput.ForeColor = Color.White;
            btnOpenOutput.Location = new Point(622, 692);
            btnOpenOutput.Name = "btnOpenOutput";
            btnOpenOutput.Size = new Size(152, 70);
            btnOpenOutput.TabIndex = 18;
            btnOpenOutput.Text = "Browse";
            btnOpenOutput.UseVisualStyleBackColor = false;
            btnOpenOutput.Click += btnOpenOutput_Click;
            // 
            // btnOpenCA
            // 
            btnOpenCA.BackColor = Color.SlateGray;
            btnOpenCA.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            btnOpenCA.ForeColor = Color.White;
            btnOpenCA.Location = new Point(620, 226);
            btnOpenCA.Name = "btnOpenCA";
            btnOpenCA.Size = new Size(152, 70);
            btnOpenCA.TabIndex = 17;
            btnOpenCA.Text = "Browse";
            btnOpenCA.UseVisualStyleBackColor = false;
            btnOpenCA.Click += btnOpenCA_Click;
            // 
            // txbOutput
            // 
            txbOutput.Location = new Point(103, 692);
            txbOutput.Multiline = true;
            txbOutput.Name = "txbOutput";
            txbOutput.Size = new Size(480, 70);
            txbOutput.TabIndex = 16;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            label3.Location = new Point(59, 644);
            label3.Name = "label3";
            label3.Size = new Size(148, 32);
            label3.TabIndex = 15;
            label3.Text = "Output File:";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            label2.Location = new Point(59, 178);
            label2.Name = "label2";
            label2.Size = new Size(162, 32);
            label2.TabIndex = 14;
            label2.Text = "RootCA Cert:";
            // 
            // txbCA
            // 
            txbCA.Location = new Point(101, 226);
            txbCA.Multiline = true;
            txbCA.Name = "txbCA";
            txbCA.Size = new Size(480, 70);
            txbCA.TabIndex = 13;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            label1.Location = new Point(59, 49);
            label1.Name = "label1";
            label1.Size = new Size(157, 32);
            label1.TabIndex = 12;
            label1.Text = "Cert Format:";
            // 
            // cbFormat
            // 
            cbFormat.DropDownStyle = ComboBoxStyle.DropDownList;
            cbFormat.FlatStyle = FlatStyle.Flat;
            cbFormat.FormattingEnabled = true;
            cbFormat.Items.AddRange(new object[] { "PEM", "DER" });
            cbFormat.Location = new Point(101, 94);
            cbFormat.Name = "cbFormat";
            cbFormat.Size = new Size(482, 40);
            cbFormat.TabIndex = 50;
            // 
            // btnOpenImm
            // 
            btnOpenImm.BackColor = Color.SlateGray;
            btnOpenImm.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            btnOpenImm.ForeColor = Color.White;
            btnOpenImm.Location = new Point(620, 377);
            btnOpenImm.Name = "btnOpenImm";
            btnOpenImm.Size = new Size(152, 70);
            btnOpenImm.TabIndex = 22;
            btnOpenImm.Text = "Browse";
            btnOpenImm.UseVisualStyleBackColor = false;
            btnOpenImm.Click += btnOpenImm_Click;
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            label4.Location = new Point(59, 329);
            label4.Name = "label4";
            label4.Size = new Size(223, 32);
            label4.TabIndex = 21;
            label4.Text = "Intermediate Cert:";
            // 
            // txbImm
            // 
            txbImm.Location = new Point(101, 377);
            txbImm.Multiline = true;
            txbImm.Name = "txbImm";
            txbImm.Size = new Size(480, 70);
            txbImm.TabIndex = 20;
            // 
            // btnOpenWebsiteCert
            // 
            btnOpenWebsiteCert.BackColor = Color.SlateGray;
            btnOpenWebsiteCert.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            btnOpenWebsiteCert.ForeColor = Color.White;
            btnOpenWebsiteCert.Location = new Point(620, 528);
            btnOpenWebsiteCert.Name = "btnOpenWebsiteCert";
            btnOpenWebsiteCert.Size = new Size(152, 70);
            btnOpenWebsiteCert.TabIndex = 25;
            btnOpenWebsiteCert.Text = "Browse";
            btnOpenWebsiteCert.UseVisualStyleBackColor = false;
            btnOpenWebsiteCert.Click += btnOpenWebsiteCert_Click;
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Font = new Font("Segoe UI", 9F, FontStyle.Bold);
            label5.Location = new Point(59, 482);
            label5.Name = "label5";
            label5.Size = new Size(167, 32);
            label5.TabIndex = 24;
            label5.Text = "Website Cert:";
            // 
            // txbWebCert
            // 
            txbWebCert.Location = new Point(101, 528);
            txbWebCert.Multiline = true;
            txbWebCert.Name = "txbWebCert";
            txbWebCert.Size = new Size(480, 70);
            txbWebCert.TabIndex = 23;
            // 
            // richTextBox1
            // 
            richTextBox1.BorderStyle = BorderStyle.None;
            richTextBox1.Location = new Point(840, 21);
            richTextBox1.Name = "richTextBox1";
            richTextBox1.Size = new Size(794, 859);
            richTextBox1.TabIndex = 26;
            richTextBox1.Text = "";
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(13F, 32F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = SystemColors.Control;
            ClientSize = new Size(1682, 936);
            Controls.Add(richTextBox1);
            Controls.Add(btnOpenWebsiteCert);
            Controls.Add(label5);
            Controls.Add(txbWebCert);
            Controls.Add(btnOpenImm);
            Controls.Add(label4);
            Controls.Add(txbImm);
            Controls.Add(btnCheck);
            Controls.Add(btnOpenOutput);
            Controls.Add(btnOpenCA);
            Controls.Add(txbOutput);
            Controls.Add(label3);
            Controls.Add(label2);
            Controls.Add(txbCA);
            Controls.Add(label1);
            Controls.Add(cbFormat);
            Name = "Form1";
            StartPosition = FormStartPosition.CenterScreen;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Button btnCheck;
        private Button btnOpenOutput;
        private Button btnOpenCA;
        private TextBox txbOutput;
        private Label label3;
        private Label label2;
        private TextBox txbCA;
        private Label label1;
        private ComboBox cbFormat;
        private Button btnOpenImm;
        private Label label4;
        private TextBox txbImm;
        private Button btnOpenWebsiteCert;
        private Label label5;
        private TextBox txbWebCert;
        private RichTextBox richTextBox1;
    }
}
