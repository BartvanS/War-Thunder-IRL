using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
namespace War_Thunder_Scraper.classes
{
    class Utils
    {
        public static void Show(int value)
        {
            MessageBox.Show(Convert.ToString(value));
        }

        public static void Show(String value)
        {
            MessageBox.Show(value);
        }
    }
}
