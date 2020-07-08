using System;
using System.IO;
using System.Threading;
using System.Net;
using System.Net.Sockets;
using Newtonsoft.Json.Linq;
using War_Thunder_Scraper.classes;
using WarThunderScraper.classes.connection;
using WarThunderScraper.classes.vehicles;

namespace WarThunderScraper.classes
{
    public class ArduinoActions
    {
        private Thread _goFetchData;
        private bool _keepFetching;
        private readonly WebClient _webclient = new WebClient();

        public enum VehicleType
        {
            LandVehicle,
            Plane
        }

        public ArduinoActions()
        {
            _keepFetching = false;
        }

        /// <summary>
        /// Start a new thread and start fetching
        /// </summary>
        /// <param name="connection"></param>
        /// <param name="vehicleType"></param>
        public void StartActions(IConnector connection, VehicleSettings vehicleSettings)
        {
            if (connection == null)
            {
                throw new ArgumentNullException("connection");
            }

            _keepFetching = true;
            GenerateThread(connection, vehicleSettings);
        }

        /// <summary>
        /// Stop the current fetching thread
        /// </summary>
        public void StopActions()
        {
            _keepFetching = false;
            _goFetchData = null;
        }

        /// <summary>
        /// Generates a background task via a thread to fetch the data
        /// </summary>
        /// <param name="connection"></param>
        private void GenerateThread(IConnector connection, VehicleSettings vehicleSettings)
        {
            _goFetchData =
                new Thread(
                    unused => ProcessData(connection, "http://127.0.0.1:8111/state", vehicleSettings)
                );
            _goFetchData.Start();
        }

        private void ProcessData(IConnector connection, string url, VehicleSettings vehicleSettings)
        {
            if (string.IsNullOrEmpty(url))
            {
                throw new ArgumentException("API url is not filled in");
            }

            Vehicle vehicle;
            if (vehicleSettings.VehicleType == VehicleType.Plane)
            {
                vehicle = new Plane();
            }
            else //if()
            {
                //TODO: if there are other vehicletypes, add those
                vehicle = new Plane();
            }


            while (_keepFetching)
            {
                Vehicle vehicleData;
                if (vehicleSettings.UseTestData)
                {
                    vehicleData = FetchTestData();
                    Console.WriteLine(vehicleData.Speed);
                }
                else
                {
                    vehicleData = FetchData(url, vehicle);
                }

                if (vehicleData != null)
                {
                    try
                    {
                        Plane plane = vehicleData as Plane;
                        if (vehicleSettings.RetrieveSpeed)
                        {
                            connection.Write("speed", Convert.ToString(plane.Speed));
                        }

                        if (vehicleSettings.RetrieveHeight)
                        {
                            connection.Write("height", Convert.ToString(plane.FlyingHeight));
                        }
                    }
                    catch (TimeoutException e)
                    {
                        Console.WriteLine("No response from the arduino: " + e.Message);
                    }
                }

                Thread.Sleep(500);
            }

            Console.WriteLine("Stopped fetching");
        }

        private Vehicle FetchTestData()
        {
            Plane vehicle = new Plane();
            Random r = new Random();
            vehicle.FuelLeft = r.Next(100, 1000);
            vehicle.Speed = r.Next(300, 500);
            vehicle.FlyingHeight = r.Next(2000, 3000);
            return vehicle;
        }

        /// <summary>
        /// Fetches the json string from the given url and returns a vehicle object
        /// </summary>
        /// <param name="url"></param>
        /// <param name="vehicle"></param>
        private Vehicle FetchData(string url, Vehicle vehicle)
        {
            string json = "";
            try
            {
                json = _webclient.DownloadString(url);
            }
            catch (WebException e)
            {
                Console.WriteLine(e);
                return null;
            }

            string correctJson = json.Replace("TAS, km/h", "tas");
            correctJson = correctJson.Replace("H, m", "height");
            dynamic data = JObject.Parse(correctJson);

            if (vehicle is Plane)
            {
                int tas = 0;
                int height = 0;
                tas = Convert.ToInt16(data.tas);
                height = Convert.ToInt16(data.height);
                Plane plane = vehicle as Plane;
                plane.FlyingHeight = height;
                plane.Speed = tas;
                vehicle = (Vehicle) plane;
            }

            return vehicle;
        }
    }
}