using System.Runtime.InteropServices;

namespace Lab_5_ECDSA_GUI
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        string filePrivate, filePublic, format, signFile, filename;
        [DllImport("digital_signature.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "key_gen")]
        public static extern bool key_gen(string filePrivate, string filePublic, string format);

        [DllImport("digital_signature.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "sign")]
        public static extern int sign(string filePrivate, string filename, string signFile);

        [DllImport("digital_signature.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "verify")]
        public static extern int verify(string filePublic, string filename, string signFile);

        private void btnPrivateKey_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();

            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                txbPri.Text = openFileDialog.FileName;
                filePrivate = openFileDialog.FileName;
            }
        }

        private void btnPublicKey_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();

            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                txbPub.Text = openFileDialog.FileName;
                filePublic = openFileDialog.FileName;
            }
        }

        private void btnGenKey_Click(object sender, EventArgs e)
        {
            format = cbFormatKey.Text;
            bool result_key_gen = key_gen(filePrivate, filePublic, format);
            if (result_key_gen == true)
            {
                MessageBox.Show("Key generation completed successfully!", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else
                MessageBox.Show("Key generation completed failed!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);

        }

        private void btnPri2_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();

            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                txbPrivateKey2.Text = openFileDialog.FileName;
                filePrivate = openFileDialog.FileName;
            }
        }

        private void btnFile2_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();

            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                txbFile2.Text = openFileDialog.FileName;
                filename = openFileDialog.FileName;
            }
        }

        private void btnSign2_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();

            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                txbSign2.Text = openFileDialog.FileName;
                signFile = openFileDialog.FileName;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int result_sign = sign(filePrivate, filename, signFile);
            if (result_sign == 0)
            {
                MessageBox.Show("Signed the file successfully!", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else
                MessageBox.Show("Signed the file failed!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);

        }

        private void btnPub3_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();

            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                txbPublicKey3.Text = openFileDialog.FileName;
                filePublic = openFileDialog.FileName;
            }
        }

        private void btnVerify3_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();

            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                txbVerify3.Text = openFileDialog.FileName;
                filename = openFileDialog.FileName;
            }
        }

        private void btnSign3_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();

            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                txbSign3.Text = openFileDialog.FileName;
                signFile = openFileDialog.FileName;
            }
        }

        private void btnVerify_Click(object sender, EventArgs e)
        {
            int result_verify = verify(filePublic, filename, signFile);
            if (result_verify == 0)
            {
                MessageBox.Show("Signature verification successful!", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else
                MessageBox.Show("Signature verification failed.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);

        }

        private void txbSign3_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
