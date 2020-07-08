using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WarThunderScraper.classes;

namespace War_Thunder_Scraper.classes
{
    public class VehicleSettings
    {
        /// <summary>
        /// Retrieves all data available and sends it to the arduino. This is default
        /// </summary>
        // public bool retrieveAllData = true;


        /// <summary>
        /// If you want te select what data to use, you can manually select it.
        /// </summary>

        public bool RetrieveSpeed { get; set; } = false;

        public bool RetrieveHeight { get; set; } = false;

        public bool UseTestData { get; set; } = false;
        public ArduinoActions.VehicleType VehicleType { get; set; } = ArduinoActions.VehicleType.Plane;

        public VehicleSettings()
        {
        }
        // public void SetVehicleSettings(bool retrieveSpeed, bool retrieveHeight, bool useTestData, ArduinoActions.VehicleType vehicleType)
        // {
        //     RetrieveSpeed = retrieveSpeed;
        //     RetrieveHeight = retrieveHeight;
        //     UseTestData = useTestData;
        //     VehicleType = vehicleType;
        // }
    }
}