using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace overige_opdrachten.classes
{
    class Resultaat
    {
        public Vak Vak
        {
            get; set;
        }
        public int Eindcijfer
        {
            get; set;
        }

        public Resultaat(Vak vak, int grade)
        {
            this.Vak = vak;
            this.Eindcijfer = grade;
        }

    }
}
