using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;

namespace K64LanToIoApi
{
    
    public class KTcpClient
    {
        TcpClient m_client;
        NetworkStream m_stream;
        public KTcpClient(int boardId)
        {
            m_client = new TcpClient("192.168.10.102", 8720 + boardId);
            m_stream = m_client.GetStream();
        }

        public void Write(byte [] data)
        {
            m_stream.Write(data, 0, data.Length);
        }
        public void Write(byte[] data, int index , int size)
        {
            m_stream.Write(data, index, size);
        } 
    }
}
