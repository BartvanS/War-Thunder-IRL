using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace opdracht_2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void amountOccurrence_Click(object sender, EventArgs e)
        {
            int count = countAmount();
            MessageBox.Show(Convert.ToString(count));
        }

        private void addName_Click(object sender, EventArgs e)
        {
            if (Convert.ToInt32(numericUpDown1.Text) > 0 && Convert.ToInt32(numericUpDown1.Text) < 11)
            {
                listBox1.Items.Add(numericUpDown1.Text);
            }
        }

        private int countAmount()
        {
            int count = 0;
            foreach (var number in listBox1.Items)
            {
                if (Convert.ToInt32(number) == Convert.ToInt32(numericUpDown1.Text))
                {
                    count++;
                }
            }
            return count;
        }

        private void highest_Click(object sender, EventArgs e)
        {
            MessageBox.Show(Convert.ToString(getHighestClick()));
        }



        private void numericUpDown1_ValueChanged(object sender, EventArgs e)
        {

        }

        private void lowest_Click(object sender, EventArgs e)
        {
            MessageBox.Show(Convert.ToString(getLowestClick()));
        }
        private void avgNumber_Click(object sender, EventArgs e)
        {
            MessageBox.Show(Convert.ToString(getAvgClick()));
        }

        private int getHighestClick()
        {
            int high = 0;
            foreach (Object number in listBox1.Items)
            {
                int getal = Convert.ToInt32(number);
                if (getal > high)
                {
                    high = getal;
                }
            }
            return high;
        }

        private int getLowestClick()
        {
            int low = 10;
            foreach (Object number in listBox1.Items)
            {
                int getal = Convert.ToInt32(number);
                if (getal < low)
                {
                    low = getal;
                }
            }
            return low;
        }

        private double getAvgClick()
        {
            int count = 0;
            int total = 0;
            foreach (Object number in listBox1.Items)
            {
                count++;
                int getal = Convert.ToInt32(number);
                total += getal;
            }
            double avgNumber = Convert.ToDouble( total )/ count;
            return avgNumber;
        }
    }
}
