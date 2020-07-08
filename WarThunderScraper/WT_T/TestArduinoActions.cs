using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using War_Thunder_Scraper.classes;
using WarThunderScraper.classes;


namespace WT_T
{
    [TestClass]
    public class TestArduinoActions
    {
        [TestMethod]
        [ExpectedException(typeof(ArgumentNullException))]
        public void TestStartActionsEmptyParameters()
        {
            ArduinoActions arduinoActions = new ArduinoActions();
            VehicleSettings vehicleSettings = new VehicleSettings();
            vehicleSettings.RetrieveHeight = true;
            vehicleSettings.RetrieveSpeed = true;
            vehicleSettings.VehicleType = ArduinoActions.VehicleType.LandVehicle;
            vehicleSettings.UseTestData = true;
            arduinoActions.StartActions(null, vehicleSettings);
        }
    }
}