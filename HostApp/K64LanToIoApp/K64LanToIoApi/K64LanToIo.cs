using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace K64LanToIoApi
{
    public enum OPCODE : byte 
    {
        WRITE_SINGLE = 10,
        WRITE_GROUP = 19
    }

    public enum IOs : byte
    {
        LED,
        PTB18,
        PTB19,
        PTC1,
        PTC8,
        PTC9,
        PTC0,
        PTC7,
        PTC5,
        PTC16,
        PTC17,
        PTB9,
        PTA1,
        PTB23,
        PTA2,
        PTC2,
        PTC3

    }
    public class K64LanToIo
    {
        KTcpClient m_client;
        int m_id;
        public K64LanToIo(int boardId)
        {
            m_id = boardId;
            m_buffer[0] = 0xA5;
        }
        public bool Connect(out string outMessage)
        {
            outMessage = string.Empty;
            try
            {
                m_client = new KTcpClient(m_id);
                return true;
            }
            catch (Exception err)
            {
                outMessage = err.Message;
                return false;
            }            
        }
        
        public bool SetIO(IOs io)
        {
            lock (this)
            {
                m_buffer[1] = (byte)OPCODE.WRITE_SINGLE;
                m_buffer[2] = (byte)io;
                m_buffer[3] =1 ;
                m_client.Write(m_buffer, 0, 4);
                return true;
            }
        }
        public bool ClearIO(IOs io)
        {
            lock (this)
            {
                m_buffer[1] = (byte)OPCODE.WRITE_SINGLE;
                m_buffer[2] = (byte)io;
                m_buffer[3] = 0;
                m_client.Write(m_buffer, 0, 4);
                return true;
            }
        }
        byte[] m_buffer = new byte[10];
       
        public bool WriteIo(IOs io , bool enable)
        {
            lock (this)
            {
                m_buffer[1] = (byte)OPCODE.WRITE_SINGLE;
                m_buffer[2] = (byte)io;
                m_buffer[3] = (byte)(enable == true ? 1 : 0);                
                m_client.Write(m_buffer, 0, 4);
                return true;
            }
        }
    }
}
