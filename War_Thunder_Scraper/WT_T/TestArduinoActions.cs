using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
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
            arduinoActions.StartActions(null, ArduinoActions.VehicleTypes.LandVehicle);
        }
    }
}
