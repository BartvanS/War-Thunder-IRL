using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using overige_opdrachten.classes;
namespace overige_opdrachten
{
    public partial class StudentenRegister : Form
    {
        public StudentenRegister()
        {
            InitializeComponent();
        }
        List<Student> studentList= new List<Student>();
        List<string> vakken = new List<string>();

        private void AddStudent_Click(object sender, EventArgs e)
        {
            Student student = new Student(Convert.ToInt32(StudentCode.Text), StudentNaam.Text, Adres.Text, Geboortedatum.Text);
            studentList.Add(student);
        }

        private void GetStudentInfo_Click(object sender, EventArgs e)
        {
            Student student = getStudent(Convert.ToInt32(StudentCode.Text));
            MessageBox.Show(student.ToString());
        }

        private Student getStudent(int code)
        {
            foreach(Student student in studentList)
            {
                if(student.Studentnummer == code)
                {
                    return student;
                }
            }
            return null;
        }

        private void HighestResult_Click(object sender, EventArgs e)
        {
            int highest = 0;
            Student student = getStudent(Convert.ToInt32(StudentCode.Text));
            foreach (Resultaat result in student.Resultaten)
            {
                if( result.Eindcijfer > highest)
                {
                    highest = result.Eindcijfer;
                }
            }
            MessageBox.Show(Convert.ToString(highest));
        }

        private void GevolgdeVakken_Click(object sender, EventArgs e)
        {
            Student student = getStudent(Convert.ToInt32(StudentCode.Text));
            vakken.Clear();
            foreach (Resultaat result in student.Resultaten)
            {
                vakken.Add(result.Vak.Vaknaam);
                Console.WriteLine(result.Vak.Vaknaam);
            }
            MessageBox.Show(String.Join(", ", vakken.ToArray()));
        }

        private void AddGrade_Click(object sender, EventArgs e)
        {
            Student student = getStudent(Convert.ToInt32(StudentCode.Text));
            student.addGrade(Convert.ToInt32(VakCode.Text), Convert.ToInt32(Grade.Text), VakNaam.Text, Convert.ToInt32(SBU.Text));
        }

        private void CompletedVakken_Click(object sender, EventArgs e)
        {
            Student student = getStudent(Convert.ToInt32(StudentCode.Text));
            vakken.Clear();
            foreach (Resultaat result in student.Resultaten)
            {
                if (result.Eindcijfer >= 6)
                {
                    vakken.Add(result.Vak.Vaknaam);
                }
            }
            MessageBox.Show(String.Join(", ", vakken.ToArray()));
        }

        private void TotalSBU_Click(object sender, EventArgs e)
        {
            Student student = getStudent(Convert.ToInt32(StudentCode.Text));
            int sbuTotal = 0;
            foreach (Resultaat result in student.Resultaten)
            {
                if (result.Eindcijfer >= 6)
                {
                    sbuTotal += result.Eindcijfer;
                }
            }
            MessageBox.Show(String.Join(", ", vakken.ToArray()));
        }
    }
}
