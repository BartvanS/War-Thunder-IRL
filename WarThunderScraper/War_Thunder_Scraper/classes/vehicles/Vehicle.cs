using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WarThunderScraper.classes.vehicles
{
    public class Vehicle
    {
        public int Speed { get; set; }
        public double FuelLeft { get; set; }

        public Vehicle()
        {
            Speed = 0;
            FuelLeft = 0;
        }
        public Vehicle(int speed, double fuelLeft)
        {
            Speed = speed;
            FuelLeft = fuelLeft;
        }

        public virtual string ToString()
        {
            return string.Format("Speed: {0}, Fuel left: {1}", Speed, FuelLeft);
        }
    }
}
