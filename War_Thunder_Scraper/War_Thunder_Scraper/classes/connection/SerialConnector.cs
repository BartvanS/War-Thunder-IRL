using System;
using System.Collections.Generic;
using System.IO;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using War_Thunder_Scraper.classes.exceptions;
using WarThunderScraper.classes.connection;
using WarThunderScraper.classes.vehicles;

namespace War_Thunder_Scraper.classes.connection
{
    public class SerialConnector : IConnector

    {
        public SerialPort SP { get; set; }
        public string PortName { get; set; }
        public int BaudRate { get; set; }
        public int ReadTimeout { get; set; }
        public int WriteTimeout { get; set; }
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
            if (portName == null)
            {
                throw new ArgumentNullException();
            }
            SP = new SerialPort();
            PortName = portName;
            BaudRate = baudRate;
            ReadTimeout = readTimeout;
            WriteTimeout = writeTimeout;
            Connected = false;
            try
            {
                OpenPort();
            }
            catch (UnauthorizedAccessException e)
            {
                Console.WriteLine("Port al geopend: " +e);
            }
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
            SP.Open();
            Connected = true;   
        }

        /// <summary>
        /// If the port properties have been changed in this class you have to reopen de port.
        /// </summary>
        public void ChangeConnection()
        {
            if (SP.IsOpen)
            {
                ClosePort();
            }
            SP.Open();
        }

        /// <summary>
        /// Write a string to the serialport
        /// </summary>
        /// <param name="value"></param>
        /// <exception cref="ProtocolException"></exception>
        public bool Write(string value)
        {
            if (!Connected)
            {
                return false;
            }
            SP.Write("#" + value + "%"); // start with # and end with % comform to the agreed protocol
            string response = "";
            try
            {
                response = SP.ReadLine(); //\r
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
                Connected = false;
                SP.Close();
            }
        }
    }
}