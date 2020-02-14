using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace overige_opdrachten.classes
{
    class Student
    {
        public int Studentnummer { get; set; }

        public string Naam { get; set; }

        public string Adres { get; set; }
        public string Geboortedatum { get; set; }
        public List<Resultaat> Resultaten { get; set; }

        public Student()
        {

        }

        public int getGradePerClasscode(int vakCode)
        {
            foreach (Resultaat item in Resultaten)
            {
                if (item.Vak.VakCode == vakCode)
                {
                   return item.Eindcijfer;          
                }
            }
            return 0;
        }

        public void addGrade(int vakCode, int grade, string name, int sbu)
        {
            bool excists = false;
            foreach (Resultaat item in Resultaten)
            {
                if (item.Vak.VakCode == vakCode)
                {
                    if(item.Eindcijfer < grade)
                    {
                        item.Eindcijfer = grade;
                        excists = true;
                        break;
                    }
                }
            }
            if (!excists)
            {
                    Vak vak = new Vak(vakCode, name, sbu);
                    Resultaat resultaat = new Resultaat(vak, grade);
                    Resultaten.Add(resultaat);
            }
        }

        public int getHighestGrade()
        {
            int highestGrade = 0;
            foreach(Resultaat item in Resultaten)
            {
                if (item.Eindcijfer > highestGrade)
                {
                    highestGrade = item.Eindcijfer;
                }
            }
            return highestGrade;
        }

        public int getSbuTotal()
        {
            int sbuTotal = 0;
            foreach (Resultaat item in Resultaten)
            {
                int sbu = item.Vak.Sbu;
                if (sbu >= 6 )
                {
                    sbuTotal += sbu;
                }
            }
            return sbuTotal;
        }

    }
}
