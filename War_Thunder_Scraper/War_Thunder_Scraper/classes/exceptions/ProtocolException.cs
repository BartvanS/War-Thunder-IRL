using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace War_Thunder_Scraper.classes.exceptions
{
    public class ProtocolException : Exception
    {
        public ProtocolException()
        {
            
        }

        public ProtocolException(string message) : base(message)
        {
            
        }
    }
}
