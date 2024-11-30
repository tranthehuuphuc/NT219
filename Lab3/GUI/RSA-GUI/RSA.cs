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

namespace RSA_GUI
{
    public partial class RSA : Form
    {
        [DllImport("RSA.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "GenerateAndSaveRSAKeys")]
        public static extern void GenerateAndSaveRSAKeys(int keySize, string format, string privateKeyFile, string publicKeyFile);

        [DllImport("RSA.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "RSAEncryption")]
        public static extern void RSAEncryption(string format, string publicKeyFile, string PlaintextFile, string CiphertFile);

        [DllImport("RSA.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "RSADecryption")]
        public static extern void RSADecryption(string format, string secretKeyFile, string PlaintextFile, string ciphertFile);

        public RSA()
        {
            InitializeComponent();
        }

        private void GenerateButton_Click(object sender, EventArgs e)
        {
            try
            {
                string[] part = KeySize.Text.Split(' ');
                GenerateAndSaveRSAKeys(int.Parse(part[0]), "Base64", "privateKey.pem", "publicKey.pem");
                PriKeyGen.Text = File.ReadAllText("privateKey.pem");
                PubKeyGen.Text = File.ReadAllText("publicKey.pem");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
        }

        private void EncyptButton_Click(object sender, EventArgs e)
        {
            try
            {
                string publicKey = PubKeyEnc.Text;
                string plainText = Plain.Text;

                if (publicKey == "" || plainText == "")
                {
                    MessageBox.Show("Please fill in all inputs!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    return;
                }

                File.WriteAllText("publicKey.pem", publicKey);
                File.WriteAllText("plain.txt", plainText);

                RSAEncryption("Base64", "publicKey.pem", "plain.txt", "cipher.pem");

                CipherEnc.Text = File.ReadAllText("cipher.pem");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
        }

        private void DecryptButton_Click(object sender, EventArgs e)
        {
            try
            {
                string privateKey = PriKeyDec.Text;
                string cipherText = CipherDec.Text;

                if (privateKey == "" || cipherText == "")
                {
                    MessageBox.Show("Please fill in all inputs!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    return;
                }

                File.WriteAllText("privateKey.pem", privateKey);
                File.WriteAllText("cipher.pem", cipherText);

                RSADecryption("Base64", "privateKey.pem", "recovered.txt", "cipher.pem");

                Recovered.Text = File.ReadAllText("recovered.txt");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
        }

        private void AutoButton_Click(object sender, EventArgs e)
        {
            if (PriKeyGen.Text == "" || PubKeyGen.Text == "")
            {
                MessageBox.Show("Please generate keys first!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }

            PubKeyEnc.Text = PubKeyGen.Text;
            PriKeyDec.Text = PriKeyGen.Text;
        }

        private void AutoCipherButton_Click(object sender, EventArgs e)
        {
            if (CipherEnc.Text == "")
            {
                MessageBox.Show("Please encrypt plain text first!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }

            CipherDec.Text = CipherEnc.Text;
        }
    }
}
