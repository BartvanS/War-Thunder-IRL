using HtmlAgilityPack;
using Newtonsoft.Json.Linq;
using ScrapySharp.Extensions;
using System;
using System.Collections.Generic;
using System.IO.Ports;
using System.Net;
using System.Threading;
using System.Windows;
using War_Thunder_Scraper.classes;


namespace War_Thunder_Scraper
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            setup();
        }
        PortConnection connection;
        private void setup()
        {
            string[] ports = SerialPort.GetPortNames();
            foreach (string port in ports)
            {
                availablePorts.Items.Add(port);
            }
        }
        private void startScraping_Click(object sender, RoutedEventArgs e)
        {
            string json = new WebClient().DownloadString("http://127.0.0.1:8111/state");
            string correctJson = json.Replace("TAS, km/h", "tas");
            dynamic data = JObject.Parse(correctJson);
            Console.WriteLine(data.tas);
            connection.writeToSerial(Convert.ToString(data.tas));
        }

        private void disconnectPort_Click(object sender, RoutedEventArgs e)
        {
            if (connection.Sp.IsOpen)
            {
                connection.closePort();
            }
        }


        private void connectPort_Click(object sender, RoutedEventArgs e)
        {
            initializePort();
        }

        private void initializePort()
        {
            if (availablePorts.HasItems)
            {
                string portName = availablePorts.Items[availablePorts.SelectedIndex].ToString();
                connection = new PortConnection(portName, 9600, 500, 500);
            }
        }


    }
}
