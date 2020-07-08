using System;
using System.IO;
using System.IO.Ports;
using War_Thunder_Scraper.classes.exceptions;
using WarThunderScraper.classes.connection;

namespace War_Thunder_Scraper.classes.connection
{
    public class SerialConnector : IConnector
    {
        public SerialPort SP { get; set; }
        private string PortName { get; set; }
        private int BaudRate { get; set; }
        private int ReadTimeout { get; set; }
        private int WriteTimeout { get; set; }
        public bool Connected { get; set; }

        public SerialConnector()
        {
            SP = new SerialPort();
            PortName = "COM3";
            BaudRate = 9600;
            ReadTimeout = 1000;
            WriteTimeout = 1000;
            Connected = false;
        }

        /// <summary>
        ///  Set up the properties of the PortConnection class
        /// </summary>
        /// <param name="portName"></param>
        /// <param name="baudRate"></param>
        /// <param name="readTimeout"></param>
        /// <param name="writeTimeout"></param>
        public SerialConnector(string portName, int baudRate, int readTimeout, int writeTimeout)
        {
            SP = new SerialPort();
            PortName = portName ?? throw new ArgumentNullException(nameof(portName));
            BaudRate = baudRate;
            ReadTimeout = readTimeout;
            WriteTimeout = writeTimeout;
            Connected = false;
            OpenPort();
        }

        /// <summary>
        /// Establish a new port connection
        /// </summary>
        public void OpenPort()
        {
            SP.PortName = this.PortName;
            SP.BaudRate = this.BaudRate;
            SP.ReadTimeout = this.ReadTimeout;
            SP.WriteTimeout = this.WriteTimeout;
            try
            {
                SP.Open();
            }
            catch (UnauthorizedAccessException e)
            {
                Console.WriteLine("Port is already opened: " + e);
            }

            Connected = true;
        }

        /// <summary>
        /// Write a string to the serialport
        /// </summary>
        /// <param name="value"></param>
        /// <exception cref="ProtocolException"></exception>
        public bool Write(string valueType, string value)
        {
            if (!Connected)
            {
                return false;
            }

            string startMessage = "#";
            string splitMessage = "@";
            string endMessage = "%";
            string protocolMessage = startMessage + valueType + splitMessage + value + endMessage; // start with #, split with @ and end with % conform to the agreed protocol
            try
            {
                SP.Write(protocolMessage);
            }
            catch (InvalidOperationException e)
            {
                Console.WriteLine(e);
            }
            string response = "";
            try
            {
                response = SP.ReadLine(); 
            }
            catch (IOException e)
            {
                Console.WriteLine("something something no connection arduino: " + e);
            }

            response = response.Replace("\n", string.Empty);
            response = response.Replace("\r", string.Empty);
            response = response.Replace("\t", string.Empty);
            if (response == "NACK")
            {
                throw new ProtocolException("Error on the arduino side.");
            }

            Console.WriteLine(response);
            return true;
        }

        /// <summary>   
        /// You need to close to port if you are not using it anymore
        /// </summary>
        public void ClosePort()
        {
            if (Connected)
            {
                try
                {
                    Connected = false;
                    SP.Close();
                }
                catch (IOException e)
                {
                    Console.WriteLine("something something IOException: " + e);
                }
            }
        }
    }
}