using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WarThunderScraper.classes.vehicles;

namespace WarThunderScraper.classes.connection
{
    public interface IConnector
    {
        void OpenPort();
        void ClosePort();
        void ChangeConnection();
        bool Write(string value);
        bool Connected { get; set; }

    }
}
