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

        public static void StopActions()
        {
            keepFetching = false;
            goFetchData = null;
        }

        private static void GenerateThread(PortConnection connection)
        {
                goFetchData =
                new Thread(
                     unused => ArduinoActions.FetchData(connection)
                );
                goFetchData.Start();
        }

        public static void FetchData(object connection)
        {
            while (keepFetching)
            {
                string json = new WebClient().DownloadString("http://127.0.0.1:8111/state");
                string correctJson = json.Replace("TAS, km/h", "tas");
                dynamic data = JObject.Parse(correctJson);
                PortConnection connect = (PortConnection)connection;
                string tas = Convert.ToString(data.tas);
                DumpEverywere(connect, tas);
                Thread.Sleep(2000);
            }
            Console.WriteLine("Stopped fetching");
        }

        public static void DumpEverywere(PortConnection connection, string value)
        {
            Console.WriteLine(value);
            connection.WriteToSerial(value);
        }
    }
}
