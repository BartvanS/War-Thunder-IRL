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

        public PortConnection(string portName, int baudRate, int readTimeout, int writeTimeout)
        {
            this.Sp = new SerialPort();
            this.PortName = portName;
            this.BaudRate = baudRate;
            this.ReadTimeout = readTimeout;
            this.WriteTimeout = writeTimeout;
            this.setupConnection();
        }

        private void setupConnection()
        {
            this.Sp.PortName = this.PortName;
            this.Sp.BaudRate = this.BaudRate;
            this.Sp.ReadTimeout = this.ReadTimeout;
            this.Sp.WriteTimeout = this.WriteTimeout;
            this.Sp.Open();
        }
        public void writeToSerial(string value)
        {
            //string parsedValue = "%" + value + "#";
            Console.WriteLine(Convert.ToString(this.ReadTimeout) + " + " + Convert.ToString(this.WriteTimeout) + " + " + this.PortName + " + " + Convert.ToString(this.BaudRate));
            Sp.Write(value);
        }

        public void closePort()
        {
            Console.WriteLine("Port closed");
            Sp.Close();
        }

    }
}
