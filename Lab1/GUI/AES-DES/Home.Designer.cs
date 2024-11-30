namespace AES_DES
{
    partial class Home
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
            AES = new Button();
            DES = new Button();
            label1 = new Label();
            SuspendLayout();
            // 
            // AES
            // 
            AES.BackColor = Color.WhiteSmoke;
            AES.Font = new Font("Segoe UI", 16.125F, FontStyle.Regular, GraphicsUnit.Point, 0);
            AES.Location = new Point(256, 232);
            AES.Name = "AES";
            AES.Size = new Size(246, 134);
            AES.TabIndex = 0;
            AES.Text = "AES";
            AES.UseVisualStyleBackColor = false;
            AES.Click += AES_Click;
            // 
            // DES
            // 
            DES.BackColor = Color.WhiteSmoke;
            DES.Font = new Font("Segoe UI", 16.125F, FontStyle.Regular, GraphicsUnit.Point, 0);
            DES.Location = new Point(673, 232);
            DES.Name = "DES";
            DES.Size = new Size(246, 134);
            DES.TabIndex = 1;
            DES.Text = "DES";
            DES.UseVisualStyleBackColor = false;
            DES.Click += DES_Click;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Segoe UI", 24F, FontStyle.Bold, GraphicsUnit.Point, 0);
            label1.Location = new Point(429, 100);
            label1.Name = "label1";
            label1.Size = new Size(316, 86);
            label1.TabIndex = 3;
            label1.Text = "Welcome";
            // 
            // Home
            // 
            AutoScaleDimensions = new SizeF(13F, 32F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.White;
            ClientSize = new Size(1174, 529);
            Controls.Add(label1);
            Controls.Add(DES);
            Controls.Add(AES);
            Name = "Home";
            StartPosition = FormStartPosition.CenterScreen;
            Text = "Home";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Button AES;
        private Button DES;
        private Label label1;
    }
}