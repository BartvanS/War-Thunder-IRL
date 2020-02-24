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
        public static void StartActions(PortConnection connection)
        {
            bool keepFetching = true;
            GenerateThread(keepFetching, connection);
        }

        public static void StopActions()
        {
            GenerateThread(false, null);
        }

        private static void GenerateThread(bool keepFetching, PortConnection connection)
        {
            if (keepFetching)
            {
                goFetchData =
                new Thread(
                     unused => ArduinoActions.FetchData(connection, keepFetching)
                );
                goFetchData.Start();
            }
            else
            {
                goFetchData = null;
            }

        }

        public static void FetchData(object connection, bool keepFetching)
        {
            while (keepFetching)
            {
                string json = new WebClient().DownloadString("http://127.0.0.1:8111/state");
                string correctJson = json.Replace("TAS, km/h", "tas");
                dynamic data = JObject.Parse(correctJson);
                PortConnection connect = (PortConnection)connection;
                //connection.WriteToSerial(Convert.ToString(data.tas));
                //connection.WriteToSerial("kaas");
                Thread.Sleep(1000);
            }
        }
    }
}
