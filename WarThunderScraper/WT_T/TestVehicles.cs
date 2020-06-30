using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using WarThunderScraper.classes.vehicles;

namespace WT_T
{
    [TestClass]
    public class TestVehicles
    {
        [TestMethod]
        public void TestPlaneToString()
        {
            var today = DateTime.Now.ToString();
            Plane plane = new Plane(100, 150.0, 200);
            Assert.AreEqual("Vliegtuig = vlieghoogte:200, snelheid:100, brandstof:150, Tijd: " + today, plane.ToString());

            Plane planeEmpty = new Plane();
            Assert.AreEqual("Vliegtuig = vlieghoogte:0, snelheid:0, brandstof:0, Tijd: " + today, planeEmpty.ToString());
        }

        // [TestMethod]
        public void TestPlaneNull()
        {
            // dit heeft geen nut want type int / double kan niet null zijn.
        }

        [TestMethod]
        public void TestVehicleToString()
        {
            Vehicle vehicle = new Vehicle(100, 150);
            Assert.AreEqual("Speed: 100, Fuel left: 150", vehicle.ToString());

            Vehicle vehicleEmpty = new Vehicle();
            Assert.AreEqual("Speed: 0, Fuel left: 0", vehicleEmpty.ToString());

        }

    }
}
