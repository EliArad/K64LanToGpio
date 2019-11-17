using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using K64LanToIoApp.Properties;
using K64LanToIoApi;

namespace K64LanToIoApp
{
    public partial class IOControl : UserControl
    {

        K64LanToIo m_client;
        IOs m_io;
        public IOControl()
        {
            InitializeComponent();
            ts.Style = JCS.ToggleSwitch.ToggleSwitchStyle.Fancy; //Only to provide an interesting look
            ts.Size = new Size(100, 30); //Only to provide an interesting look
            ts.OnText = "ON"; //Only to provide an interesting look
            ts.OnFont = new Font(Font.FontFamily, 10, FontStyle.Bold); //Only to provide an interesting look
            ts.OnForeColor = Color.White; //Only to provide an interesting look
            ts.OffText = "OFF"; //Only to provide an interesting look
            ts.OffFont = new Font(Font.FontFamily, 10, FontStyle.Bold); //Only to provide an interesting look
            ts.OffForeColor = Color.White; //Only to provide an interesting look
            ts.ButtonImage = Resources.arrowright; //Only to provide an interesting look
            ts.GrayWhenDisabled = false;
        }

        public void LoadControl(IOs io, string text)
        {           
            m_io = io;
            label1.Text = text;
        }       

        public void LoadControl(K64LanToIo client, IOs io, string text)
        {
            m_client = client;
            m_io = io;
            label1.Text = text;
        }

        public void LoadControl(K64LanToIo client)
        {
            m_client = client;
        }
        bool m_reversedIo = false;
        public void ReversedIo(bool r)
        {
            m_reversedIo = r;
        }
        
        private void ts_CheckedChanged(object sender, EventArgs e)
        {
            m_client.WriteIo(m_io, m_reversedIo == false ? ts.Checked : !ts.Checked);
        }
    }
}
