using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;
using System.Net;
using Newtonsoft.Json.Linq;
using System.IO.Ports;
using War_Thunder_Scraper.classes;

namespace War_Thunder_Scraper.classes
{
    static class ArduinoActions
    {
        static Thread goFetchData;
        static bool keepFetching;

        /// <summary>
        /// Start a new thread and start fetching
        /// </summary>
        /// <param name="connection"></param>
        public static void StartActions(PortConnection connection)
        {
            try
            {
                keepFetching = true;
                GenerateThread(connection);
            }
            catch (Exception)
            {

                throw;
            }

        }

        /// <summary>
        /// Stop the current fetching thread
        /// </summary>
        public static void StopActions()
        {
            keepFetching = false;
            goFetchData = null;
        }

        /// <summary>
        /// Generates a background task via a thread to fetch the data
        /// </summary>
        /// <param name="connection"></param>
        private static void GenerateThread(PortConnection connection)
        {
            goFetchData =
            new Thread(
                 unused => ArduinoActions.FetchData(connection, "http://127.0.0.1:8111/state")
            );
            goFetchData.Start();
        }

        /// <summary>
        /// Fetches the json string from the given url and writes it to the serial
        /// </summary>
        /// <param name="connection"></param>
        private static void FetchData(object connection, string url)
        {
            while (keepFetching)
            {
                try
                {
                    string json = new WebClient().DownloadString(url);
                    string correctJson = json.Replace("TAS, km/h", "tas");
                    dynamic data = JObject.Parse(correctJson);
                    PortConnection connect = (PortConnection)connection;
                    string tas = Convert.ToString(data.tas);
                    DumpEverywere(connect, tas);
                    Thread.Sleep(1200);
                }
                catch (Exception)
                {
                    Console.WriteLine("Is the rest api on?");
                }

            }
            Console.WriteLine("Stopped fetching");
        }

        /// <summary>
        /// Print a string in the console and the serial
        /// </summary>
        /// <param name="connection"></param>
        /// <param name="value"></param>
        public static void DumpEverywere(PortConnection connection, string value)
        {
            Console.WriteLine(value);
            connection.WriteToSerial(value);
        }
    }
}
