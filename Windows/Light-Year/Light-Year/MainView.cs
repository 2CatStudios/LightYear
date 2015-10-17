using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using System.Threading; //But not really, delete this later.

namespace Light_Year
{

    public partial class MainView : Form
    {

        private int doesItResizeEveryFrame = 0;

        public MainView()
        {
            InitializeComponent();

            //Thread countingWithString = new Thread(new ThreadStart(CountingWithString));

            TestButton("Population of QB138 " + doesItResizeEveryFrame);
        }


        private void CountingWithString ()
        {

            while (true)
            {

                doesItResizeEveryFrame = doesItResizeEveryFrame + 1;

                Thread.Sleep(120);
            }
        }
        //not "InitializeMyButton!" ? :P Maybe "Light-Year/Main/MainView/MainView/MainView( ) 
  
        //I will now make for you a threaded button.

        private void TestButton (string inputForButtonTitleWhenItGetsATitle)
        {

            // Create and initialize a Button.
            Button button1 = new Button();

            button1.Name = "Button1 Name";
            button1.Text = inputForButtonTitleWhenItGetsATitle;

            button1.AutoSize = true;

            // Set the button to return a value of OK when clicked.
            button1.DialogResult = DialogResult.OK;

            // Add the button to the form.
            Controls.Add(button1);
        }
    }
}
