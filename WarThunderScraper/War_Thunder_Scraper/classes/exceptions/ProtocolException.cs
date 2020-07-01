using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace War_Thunder_Scraper.classes.exceptions
{
    [Serializable]
    public class ProtocolException : Exception
    {
        public ProtocolException()
        {
            
        }

        public ProtocolException(string message) : base(message)
        {
            
        }

        public ProtocolException(string message, Exception innerException) : base(message, innerException)
        {
        }

        protected ProtocolException(System.Runtime.Serialization.SerializationInfo serializationInfo, System.Runtime.Serialization.StreamingContext streamingContext)
        {
            throw new NotImplementedException();
        }
    }
}
