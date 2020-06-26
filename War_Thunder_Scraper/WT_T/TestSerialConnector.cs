using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using War_Thunder_Scraper.classes.connection;
using WarThunderScraper.classes;
using WarThunderScraper.classes.connection;

namespace WT_T
{
    [TestClass]
    public class TestSerialConnector
    {
        /// <summary>
        /// Tests if you are not connected you cannot send a message
        /// </summary>
        [TestMethod]
        public void TestSerialConnectorWrite()
        {
            IConnector serialConnector = new SerialConnector();
            Assert.AreEqual(false, serialConnector.Write("test"));
        }

        [TestMethod]
        [ExpectedException(typeof(ArgumentNullException))]
        public void TestConstructorNull()
        {
            IConnector serialConnector = new SerialConnector(null, 100, 100, 100);
        }
    }
}