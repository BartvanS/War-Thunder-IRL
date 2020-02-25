using System;
using System.IO.Ports;
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
        PortConnection connection = null;
        bool connected = false;
        private void setup()
        {
            UpdatePortList();
        }

        private void StartFetching_Click(object sender, RoutedEventArgs e)
        {
            if (connected)
            {
                ArduinoActions.StartActions(connection);
            }
            else
            {
                Utils.Show("Make sure you are connected to a port");
            }
        }

        private void StopFetching_Click(object sender, RoutedEventArgs e)
        {
            ArduinoActions.StopActions();
        }

        private void disconnectPort_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                connection.closePort();
                connected = false;
            }
            catch (Exception)
            {
                MessageBox.Show("No opened port.");
            }
        }
        
        private void connectPort_Click(object sender, RoutedEventArgs e)
        {
            InitializePort();
        }

        /// <summary>
        /// Start the port connection
        /// </summary>
        private void InitializePort()
        {
            if (availablePorts.HasItems)
            {
                string portName = availablePorts.Items[availablePorts.SelectedIndex].ToString();
                connection = new PortConnection(portName, 9600, 500, 500);
                connected = true;
            }
        }

        /// <summary>
        /// Runs methods before application is completely closed
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void RunCloseCheckups(object sender, System.ComponentModel.CancelEventArgs e)
        {
            ArduinoActions.StopActions();
            if (connection != null)
            {
                connection.closePort();
            }
        }

        private void RefreshPorts_OnClick(object sender, RoutedEventArgs e)
        {
            UpdatePortList();
        }

        private void UpdatePortList()
        {
            string[] ports = SerialPort.GetPortNames();
            availablePorts.Items.Clear();
            foreach (string port in ports)
            {
                availablePorts.Items.Add(port);
            }
        }
    }
}
