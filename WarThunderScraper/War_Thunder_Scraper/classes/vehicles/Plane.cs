using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.AccessControl;
using System.Text;
using System.Threading.Tasks;
using WarThunderScraper.classes.vehicles;

namespace WarThunderScraper.classes.vehicles
{
    public class Plane : Vehicle
    {
        public int FlyingHeight { get; set; }

        public Plane()
        {
            FlyingHeight = 0;
        }
        public Plane(int speed, double fuelLeft, int flyingHeight) : base(speed, fuelLeft)
        {
            FlyingHeight = flyingHeight;
        }

        public override string ToString()
        {
            return string.Format(
                "Vliegtuig = vlieghoogte:{0}, snelheid:{1}, brandstof:{2}, Tijd: {3}",
                FlyingHeight,
                Speed, FuelLeft, DateTime.Now.ToString());
        }
    }
}
