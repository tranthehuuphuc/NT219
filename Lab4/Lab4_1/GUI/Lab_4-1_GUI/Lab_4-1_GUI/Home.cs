using System.Runtime.InteropServices;

namespace Lab_4_1_GUI
{
    public partial class Home : Form
    {
        public Home()
        {
            InitializeComponent();
        }
        string input_option;
        string input_data;
        string output_filename;
        string algo;

        int shakeLength = 0;
        [DllImport("hashes.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "hashes")]
        public static extern void hashes(string algo, string input_option, string input_data, string output_filename, int shakeLength);

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();

            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                txbInput.Text = openFileDialog.FileName;
                input_data = openFileDialog.FileName;
            }
        }

        private void btnOpenOutput_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();

            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                txbOutput.Text = openFileDialog.FileName;
                output_filename = openFileDialog.FileName;
            }
        }

        private void btnHash_Click(object sender, EventArgs e)
        {
            algo = comboBox1.Text;
            input_option = "file";
            if (algo == "SHAKE128" || algo == "SHAKE256")
            {
                shakeLength = int.Parse(txbOutLeng.Text);
            }
            try
            {
                hashes(algo, input_option, input_data, output_filename, shakeLength);

                MessageBox.Show("Hashing operation completed successfully!", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            catch (Exception ex)
            {
                MessageBox.Show("Hashing operation failed. Please check your inputs and try again.\nError: " + ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void btnHash_2_Click(object sender, EventArgs e)
        {
            string algo = cbType_2.Text;
            string input_option = "screen";
            string input_data = txbInput_2.Text;
            string output_filename = System.IO.Path.GetTempFileName();
            int shakeLength = 0;

            if (algo == "SHAKE128" || algo == "SHAKE256")
            {
                shakeLength = int.Parse(txbOutLeng_2.Text);
            }

            try
            {
                hashes(algo, input_option, input_data, output_filename, shakeLength);

                MessageBox.Show("Hashing operation completed successfully!", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);

                System.Threading.Thread.Sleep(100);

                if (System.IO.File.Exists(output_filename))
                {
                    string outputContent = System.IO.File.ReadAllText(output_filename);
                    txbOutput_2.Text = outputContent;
                }
                else
                {
                    MessageBox.Show("Temporary output file does not exist.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("Hashing operation failed. Please check your inputs and try again.\nError: " + ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            finally
            {
                if (System.IO.File.Exists(output_filename))
                {
                    System.IO.File.Delete(output_filename);
                }
            }
        }

    }
}
