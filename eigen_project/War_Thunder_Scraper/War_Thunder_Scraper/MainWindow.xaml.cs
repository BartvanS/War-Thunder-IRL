using HtmlAgilityPack;
using Newtonsoft.Json.Linq;
using ScrapySharp.Extensions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using System.Web.Script.Serialization;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using War_Thunder_Scraper.classes;

namespace War_Thunder_Scraper
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void startScraping_Click(object sender, RoutedEventArgs e)
        {
            string json = new WebClient().DownloadString("http://127.0.0.1:8111/state");
            string correctJson = json.Replace("TAS, km/h", "tas");
            dynamic data = JObject.Parse(correctJson);
            Console.WriteLine(data.tas);
        }
    }
}
