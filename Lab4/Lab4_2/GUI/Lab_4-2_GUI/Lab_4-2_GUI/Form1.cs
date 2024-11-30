using System.Runtime.InteropServices;
using System.Windows.Forms;

namespace Lab_4_2_GUI
{
    public partial class Form1 : Form
    {
        [DllImport("CheckCert.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "verifyAndSaveCert")]
        public static extern int verifyAndSaveCert(string format, string rootCACertFile, string intermediateCertFile, string websiteCertFile, string outputFile);
        public Form1()
        {
            InitializeComponent();
        }
        string format, rootCACertFile, intermediateCertFile, websiteCertFile, outputFile;
        private void btnOpenCA_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();

            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                txbCA.Text = openFileDialog.FileName;
                
            }
        }

        private void btnOpenImm_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();

            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                txbImm.Text = openFileDialog.FileName;
            }
        }

        private void btnOpenWebsiteCert_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();

            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                txbWebCert.Text = openFileDialog.FileName;
            }
        }

        private void btnOpenOutput_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();

            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                txbOutput.Text = openFileDialog.FileName;
            }
        }

        private void btnCheck_Click(object sender, EventArgs e)
        {
            rootCACertFile = txbCA.Text;
            intermediateCertFile = txbImm.Text;
            websiteCertFile = txbWebCert.Text;
            outputFile = txbOutput.Text;


            format = cbFormat.Text;
            int result = verifyAndSaveCert(format, rootCACertFile, intermediateCertFile, websiteCertFile, outputFile);
            if (result == 1)
            {
                MessageBox.Show("Checking your Certifications completed successfully!", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);
                string outputContent = System.IO.File.ReadAllText(outputFile);
                richTextBox1.Text = outputContent;
            }
            else
                MessageBox.Show("Checking your Certifications completed failed!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);

        }
    }
}
