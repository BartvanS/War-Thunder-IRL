using System;
using System.IO;
using System.IO.Ports;
using System.Windows;
using System.Windows.Controls;
using War_Thunder_Scraper.classes.connection;
using War_Thunder_Scraper.classes.exceptions;
using War_Thunder_Scraper.forms;
using WarThunderScraper.classes;
using WarThunderScraper.classes.connection;


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

        private string logPath =
            "C:\\projects\\t-db2-vj1920-bartvansevenbergen\\eigen_project\\War_Thunder_Scraper\\War_Thunder_Scraper\\logs\\vehiclelogs.txt";

        private void Setup()
        {
            UpdatePortList();
            VehicleTypeSelectBox.SelectionMode = SelectionMode.Single;
            VehicleTypeSelectBox.Items.Add("Plane");
            VehicleTypeSelectBox.SelectedIndex = 0;
        }

        private void handleFetching()
        {
            if (!_connection.Connected)
            {
                MessageBox.Show("Make sure you are connected to a port");
                return;
            }

            string SelectedVehicleString = VehicleTypeSelectBox.SelectedItem.ToString();
            try
            {
                Enum.TryParse(SelectedVehicleString, out ArduinoActions.VehicleTypes vehicleType);
                if (vehicleType != null)
                {
                    arduinoActions.StartActions(_connection, vehicleType);
                }
                else
                {
                    MessageBox.Show("No valid type of vehicle is selected");
                }
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
            handleFetching();
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

        private void SwitchLogging_Click(object sender, RoutedEventArgs e)
        {
            if (arduinoActions.FillLogs)
            {
                arduinoActions.fileWriter.Close();
                arduinoActions.FillLogs = false;
                MessageBox.Show("stopped logging");
            }
            else
            {
                try
                {
                    arduinoActions.fileWriter =
                        new StreamWriter(
                            logPath,
                            true);
                    arduinoActions.FillLogs = true;
                    MessageBox.Show("started logging");
                }
                catch (ArgumentNullException)
                {
                    MessageBox.Show("Path is null");
                }

                catch (ArgumentException)
                {
                    MessageBox.Show("Path is invalid");
                }
            }
        }


        private void ShowLogs_Click(object sender, RoutedEventArgs e)
        {
            Logs logsWindow = new Logs();
            string[] lines =
                File.ReadAllLines(
                    logPath);
            logsWindow.VehiclesLog.Items.Clear();
            foreach (string line in lines)
            {
                logsWindow.VehiclesLog.Items.Add(line);
            }

            logsWindow.Show();
        }

        private void EmptyLogsButton_Click(object sender, RoutedEventArgs e)
        {
            File.Delete(logPath);
        }
    }
}