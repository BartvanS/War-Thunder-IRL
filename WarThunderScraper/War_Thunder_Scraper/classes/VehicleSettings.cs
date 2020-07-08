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
        /// If you want te select what data to use, you can manually select it.
        /// </summary>

        public bool RetrieveSpeed { get; set; } = false;

        public bool RetrieveHeight { get; set; } = false;

        public bool UseTestData { get; set; } = false;
        public ArduinoActions.VehicleType VehicleType { get; set; } = ArduinoActions.VehicleType.Plane;

        public VehicleSettings()
        {
        }
    }
}