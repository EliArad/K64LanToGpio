using K64LanToIoApi;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace K64LanToIoApp
{
    public partial class Form1 : Form
    {
        K64LanToIo m_client;
        List<IOControl> m_allIo = new List<IOControl>();
        public Form1()
        {
            InitializeComponent();

            m_allIo.Add(ioControl1);
            m_allIo.Add(ioControl2);
            m_allIo.Add(ioControl3);
            m_allIo.Add(ioControl4);
            m_allIo.Add(ioControl5);
            m_allIo.Add(ioControl6);
            m_allIo.Add(ioControl7);
            m_allIo.Add(ioControl8);
            m_allIo.Add(ioControl9);
            m_allIo.Add(ioControl10);
            m_allIo.Add(ioControl11);
            m_allIo.Add(ioControl12);
            m_allIo.Add(ioControl13);
            m_allIo.Add(ioControl14);
            m_allIo.Add(ioControl15);
            m_allIo.Add(ioControl16);
            m_allIo.Add(ioControl17);
            m_allIo.Add(ioControl18);
            m_allIo.Add(ioControl19);
            m_allIo.Add(ioControl20);


            m_allIo[0].LoadControl(IOs.LED, "LED");
            m_allIo[0].ReversedIo(true);

            m_allIo[1].LoadControl(IOs.PTB18, "PTB18");
            m_allIo[2].LoadControl(IOs.PTB19, "PTB19");
            m_allIo[3].LoadControl(IOs.PTC1, "PTC1");
            m_allIo[4].LoadControl(IOs.PTC8, "PTC8");
            m_allIo[5].LoadControl(IOs.PTC9, "PTC9");

            m_allIo[6].LoadControl(IOs.PTC0, "PTC0");
            m_allIo[7].LoadControl(IOs.PTC7, "PTC7");
            m_allIo[8].LoadControl(IOs.PTC5, "PTC5");
            m_allIo[9].LoadControl(IOs.PTC16, "PTC16");
            m_allIo[10].LoadControl(IOs.PTC17, "PTC17");


            m_allIo[11].LoadControl(IOs.PTB9, "PTB9");
            m_allIo[12].LoadControl(IOs.PTA1, "PTA1");
            m_allIo[13].LoadControl(IOs.PTB23, "PTB23");
            m_allIo[14].LoadControl(IOs.PTA2, "PTA2");
            m_allIo[15].LoadControl(IOs.PTC2, "PTC2");
            m_allIo[16].LoadControl(IOs.PTC3, "PTC3");

          

        }

        private void button1_Click(object sender, EventArgs e)
        {
            m_client = new K64LanToIo(comboBox1.SelectedIndex);
            if (m_client.Connect(out string outMessage) == false)
            {
                button1.ForeColor = Color.Red;
                MessageBox.Show("Failed to connect board id: " + comboBox1.Text);
            }
            else
            {
                button1.ForeColor = Color.Green;
                for (int i = 0; i < m_allIo.Count ;i++)
                    m_allIo[i].LoadControl(m_client);
            }
        }
    }
}
