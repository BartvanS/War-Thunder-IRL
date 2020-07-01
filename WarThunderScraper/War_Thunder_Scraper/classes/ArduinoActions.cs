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
        private Thread goFetchData;
        private bool keepFetching;
        private readonly WebClient webclient = new WebClient();

        public enum VehicleTypes
        {
            LandVehicle,
            Plane
        }

        public ArduinoActions()
        {
            keepFetching = false;
        }

        /// <summary>
        /// Start a new thread and start fetching
        /// </summary>
        /// <param name="connection"></param>
        /// <param name="vehicleType"></param>
        public void StartActions(IConnector connection, VehicleTypes vehicleType)
        {
            if (connection == null)
            {
                throw new ArgumentNullException();
            }
            keepFetching = true;
            GenerateThread(connection, vehicleType);
        }

        /// <summary>
        /// Stop the current fetching thread
        /// </summary>
        public void StopActions()
        {
            keepFetching = false;
            goFetchData = null;
        }

        /// <summary>
        /// Generates a background task via a thread to fetch the data
        /// </summary>
        /// <param name="connection"></param>
        private void GenerateThread(IConnector connection, VehicleTypes vehicleType)
        {
            goFetchData =
                new Thread(
                    unused => ProcessData(connection, "http://127.0.0.1:8111/state", vehicleType)
                );
            goFetchData.Start();
        }

        private void ProcessData(IConnector connection, string url, VehicleTypes vehicleType)
        {
            if (string.IsNullOrEmpty(url))
            {
                throw new ArgumentException("API url is not filled in");
            }
            Vehicle vehicle;
            if (vehicleType == VehicleTypes.Plane)
            {
                vehicle = new Plane();
            }
            else
            {
                //TODO: if there are other vehicletypes, add those
                vehicle = new Plane();
            }

            while (keepFetching)
            {
                Vehicle vehicleData = FetchData(url, vehicle);
                if (vehicleData != null)
                {
                    try
                    {
                        Plane plane = vehicleData as Plane;
                        connection.Write("speed", Convert.ToString(plane.Speed));
                        connection.Write("height", Convert.ToString(plane.FlyingHeight));
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
                json = webclient.DownloadString(url);
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
                Random randomNr = new Random();
                plane.FlyingHeight = height;
                plane.Speed = tas;
                vehicle = (Vehicle) plane;
            }

            return vehicle;
        }
    }
}