using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AES_DES
{
    public partial class DES : Form
    {
        [DllImport("DES.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "GenerateAndSaveKeys")]
        public static extern void GenerateAndSaveKeys(string OutputFormat, string FileName);

        [DllImport("DES.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "Encryption")]
        public static extern void Encryption(string Mode, string KeyFile, string KeyFormat, string PlaintextFile, string PlaintextFormat, string CiphertextFile, string CiphertextFormat);

        [DllImport("DES.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "Decryption")]
        public static extern void Decryption(string Mode, string KeyFile, string KeyFormat, string RecoveredFile, string RecoveredFormat, string CiphertextFile, string CiphertextFormat);

        public DES()
        {
            InitializeComponent();
        }

        private void Generate_Click(object sender, EventArgs e)
        {
            try
            {
                GenerateAndSaveKeys("HEX", "key.hex");
                KeyGen.Text = File.ReadAllText("key.hex");
                IVGen.Text = File.ReadAllText("iv.hex");

                KeyEnc.Text = KeyGen.Text;
                IVEnc.Text = IVGen.Text;

                KeyDec.Text = KeyGen.Text;
                IVDec.Text = IVGen.Text;
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void Encrypt_Click(object sender, EventArgs e)
        {
            try
            {
                string key = KeyEnc.Text;
                string IV = IVEnc.Text;
                string plain = Plain.Text;

                if (ModeEnc.SelectedItem == null || key == "" || IV == "" || plain == "")
                {
                    MessageBox.Show("Please fill in all inputs!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    return;
                }

                string mode = ModeEnc.SelectedItem.ToString();
                File.WriteAllText("key.hex", key);
                File.WriteAllText("iv.hex", IV);
                File.WriteAllText("plain.txt", plain);

                Encryption(mode, "key.hex", "HEX", "plain.txt", "text", "cipher.hex", "HEX");

                CipherEnc.Text = File.ReadAllText("cipher.hex");
                CipherDec.Text = CipherEnc.Text;
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
        }

        private void Decrypt_Click(object sender, EventArgs e)
        {
            try
            {
                string key = KeyDec.Text;
                string IV = IVDec.Text;
                string cipher = CipherDec.Text;

                if (ModeDec.SelectedItem == null || key == "" || IV == "" || cipher == "")
                {
                    MessageBox.Show("Please fill in all inputs!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    return;
                }

                string mode = ModeDec.SelectedItem.ToString();
                File.WriteAllText("key.hex", key);
                File.WriteAllText("iv.hex", IV);
                File.WriteAllText("cipher.hex", cipher);

                Decryption(mode, "key.hex", "HEX", "recovered.txt", "text", "cipher.hex", "HEX");

                Recovered.Text = File.ReadAllText("recovered.txt");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
        }

        private void ModeEnc_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (ModeDec.SelectedIndex != ModeEnc.SelectedIndex)
            {
                ModeDec.SelectedIndex = ModeEnc.SelectedIndex;
            }
        }
    }
}
