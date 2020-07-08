using System;
using System.Collections.Generic;
using System.IO;
using System.IO.Ports;
using System.Linq;
using System.Windows;
using System.Windows.Controls;
using War_Thunder_Scraper.classes;
using War_Thunder_Scraper.classes.connection;
using War_Thunder_Scraper.classes.exceptions;
using WarThunderScraper.classes;
using WarThunderScraper.classes.connection;
using WarThunderScraper.Properties;


namespace WarThunderScraper
{
    /// <summary>
    /// Interaction logic for Menu.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            Setup();
        }

        private IConnector _connection = new SerialConnector();
        readonly ArduinoActions arduinoActions = new ArduinoActions();


        private void Setup()
        {
            UpdatePortList();
            VehicleTypeSelectBox.SelectionMode = SelectionMode.Single;
            VehicleTypeSelectBox.Items.Add("Plane");
            VehicleTypeSelectBox.SelectedIndex = 0;
        }

        private void handleFetching(bool fetchAllData, VehicleSettings vehicleSettings)
        {
            if (!_connection.Connected)
            {
                MessageBox.Show("Make sure you are connected to a port");
                return;
            }

            try
            {
                arduinoActions.StartActions(_connection, vehicleSettings.VehicleType);
            }
            catch (ObjectDisposedException exception)
            {
                MessageBox.Show(exception.Message);
            }
            catch (IOException exception)
            {
                MessageBox.Show(exception.Message);
            }
            catch (ArgumentNullException exception)
            {
                MessageBox.Show(exception.Message);
            }
            catch (ProtocolException)
            {
                MessageBox.Show("Probleem aan de arduino kant: ProtocolException");
            }
        }

        private void handleStopFetching()
        {
            arduinoActions.StopActions();
        }

        private void DisconnectPortClick(object sender, RoutedEventArgs e)
        {
            try
            {
                _connection.ClosePort();
                arduinoActions.StopActions();
            }
            catch (IOException ioException)
            {
                MessageBox.Show(ioException.Message);
            }

            handleStopFetching();
        }

        private void ConnectPort_Click(object sender, RoutedEventArgs e)
        {
            InitializePort();
            string selectedVehicleString = VehicleTypeSelectBox.SelectedItem.ToString();
            bool parseSuccess = Enum.TryParse(selectedVehicleString, out ArduinoActions.VehicleType vehicleType);
            if (parseSuccess)
            {
                //todo: vehicleSettings
                VehicleSettings vehicleSettings = new VehicleSettings();
                vehicleSettings.RetrieveHeight = false;
                vehicleSettings.RetrieveSpeed = false;
                vehicleSettings.UseTestData = false;
                vehicleSettings.VehicleType = vehicleType;
                handleFetching(true, vehicleSettings);
                }
            else
            {
                MessageBox.Show("No valid type of vehicle is selected");
            }
        }

        /// <summary>
        /// Start the port _connection
        /// </summary>
        private void InitializePort()
        {
            try
            {
                if (availablePorts.HasItems)
                {
                    string portName = availablePorts.Items[availablePorts.SelectedIndex].ToString();
                    _connection = new SerialConnector(portName, 9600, 500, 500);
                }
            }
            catch (IOException e)
            {
                MessageBox.Show(e.Message);
            }
            catch (ArgumentOutOfRangeException e)
            {
                MessageBox.Show(e.Message + ". No port selected");
            }
        }

        /// <summary>
        /// Runs methods before application is completely closed
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void RunCloseCheckups(object sender, System.ComponentModel.CancelEventArgs e)
        {
            arduinoActions.StopActions();
            _connection?.ClosePort();
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