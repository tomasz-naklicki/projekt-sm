using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;

namespace GUI_App
{
    public partial class Form : System.Windows.Forms.Form
    {
        private static readonly Dictionary<string, int> _baudRates = new Dictionary<string, int>()
        {
            ["75"] = 75,
            ["110"] = 110,
            ["150"] = 150,
            ["300"] = 300,
            ["600"] = 600,
            ["1'200"] = 1_200,
            ["1'800"] = 1_800,
            ["2'400"] = 2_400,
            ["4'800"] = 4_800,
            ["7'200"] = 7_200,
            ["9'600"] = 9_600,
            ["14'400"] = 14_400,
            ["19'200"] = 19_200,
            ["38'400"] = 38_400,
            ["56'000"] = 56_000,
            ["57'600"] = 57_600,
            ["115'200"] = 115_200,
            ["128'000"] = 128_000,
        };
        public Form()
        {
            InitializeComponent();
            InitializeData();
        }
        private void InitializeData()
        {
            portNameComboBox.DataSource = SerialPort.GetPortNames();
        }
        private bool Connect(string portName)
        {
            // TODO
            return true;
        }
        private void Disconnect()
        {
            // TODO
        }
        private void connectButton_Click(object sender, EventArgs e)
        {
            if (portNameComboBox.SelectedIndex == -1)
            {
                return;
            }
            if (!(portNameComboBox.SelectedItem is string portName))
            {
                return;
            }
            if (!Connect(portName))
            {
                return;
            }

            connectButton.Enabled = false;
            portNameComboBox.Enabled = false;
            disconnectButton.Enabled = true;
        }
        private void disconnectButton_Click(object sender, EventArgs e)
        {
            Disconnect();
            disconnectButton.Enabled = false;
            connectButton.Enabled = true;
            portNameComboBox.Enabled = true;
        }
    }
}
