using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AES_DES
{
    public partial class Home : Form
    {
        public Home()
        {
            InitializeComponent();
        }

        private void AES_Click(object sender, EventArgs e)
        {
            AES aes = new AES();
            aes.Show();
        }

        private void DES_Click(object sender, EventArgs e)
        {
            DES des = new DES();
            des.Show();
        }
    }
}
