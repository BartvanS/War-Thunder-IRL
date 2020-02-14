using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace overige_opdrachten.classes
{
    class Vak
    {
        public int VakCode { get; set; }
        public string Vaknaam { get; set; }
        public int Sbu { get; set; }

        public Vak(int code, string name, int sbu)
        {
            this.VakCode = code;
            this.Vaknaam = name;
            this.Sbu = sbu;
        }
    }
}
