using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.IO.Ports;
using System.Net;
using System.Threading;
using System.Threading.Tasks;
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

        private void StartFetching_Click(object sender, RoutedEventArgs e)
        {
            ArduinoActions.StartActions(connection);
        }

        private void StopFetching_Click(object sender, RoutedEventArgs e)
        {
            ArduinoActions.StopActions();
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
