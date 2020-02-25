using System;
using System.Collections.Generic;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace War_Thunder_Scraper.classes
{
    class PortConnection
    {
        public SerialPort Sp { get; set; }
        public string PortName { get; set; }
        public int BaudRate { get; set; }
        public int ReadTimeout { get; set; }
        public int WriteTimeout { get; set; }

        /// <summary>
        ///  Set up the properties of the PortConnection class
        /// </summary>
        /// <param name="portName"></param>
        /// <param name="baudRate"></param>
        /// <param name="readTimeout"></param>
        /// <param name="writeTimeout"></param>
        public PortConnection(string portName, int baudRate, int readTimeout, int writeTimeout)
        {
            this.Sp = new SerialPort();
            this.PortName = portName;
            this.BaudRate = baudRate;
            this.ReadTimeout = readTimeout;
            this.WriteTimeout = writeTimeout;
            this.setupConnection();
        }

        /// <summary>
        /// Establish a new port connection
        /// </summary>
        private void setupConnection()
        {
            this.Sp.PortName = this.PortName;
            this.Sp.BaudRate = this.BaudRate;
            this.Sp.ReadTimeout = this.ReadTimeout;
            this.Sp.WriteTimeout = this.WriteTimeout;
            //this.Sp.Handshake = Handshake.XOnXOff;
            this.Sp.Open();
        }

        /// <summary>
        /// If the port properties have been changed in this class you have to reopen de port.
        /// </summary>
        public void changeConnection()
        {
            if (this.Sp.IsOpen)
            {
                this.Sp.Close();
            }
            this.Sp.Open();
        }

        /// <summary>
        /// Write a string to the serialport
        /// </summary>
        /// <param name="value"></param>
        public void WriteToSerial(string value)
        {
            //string parsedValue = "%" + value + "#";
            //Sp.WriteLine(parsedValue);
            Sp.WriteLine(value);
        }

        /// <summary>
        /// You need to close to port if you are not using it anymore
        /// </summary>
        public void closePort()
        {
            Console.WriteLine("Port closed");
            Sp.Close();
        }
    }
}
