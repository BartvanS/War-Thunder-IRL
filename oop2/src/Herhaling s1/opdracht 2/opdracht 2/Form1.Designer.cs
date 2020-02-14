namespace opdracht_2
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.addName = new System.Windows.Forms.Button();
            this.amountOccurrence = new System.Windows.Forms.Button();
            this.highest = new System.Windows.Forms.Button();
            this.lowest = new System.Windows.Forms.Button();
            this.avgNumber = new System.Windows.Forms.Button();
            this.numericUpDown1 = new System.Windows.Forms.NumericUpDown();
            this.listBox1 = new System.Windows.Forms.ListBox();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).BeginInit();
            this.SuspendLayout();
            // 
            // addName
            // 
            this.addName.Location = new System.Drawing.Point(93, 228);
            this.addName.Name = "addName";
            this.addName.Size = new System.Drawing.Size(75, 23);
            this.addName.TabIndex = 1;
            this.addName.Text = "Voeg toe";
            this.addName.UseVisualStyleBackColor = true;
            this.addName.Click += new System.EventHandler(this.addName_Click);
            // 
            // amountOccurrence
            // 
            this.amountOccurrence.Location = new System.Drawing.Point(93, 199);
            this.amountOccurrence.Name = "amountOccurrence";
            this.amountOccurrence.Size = new System.Drawing.Size(180, 23);
            this.amountOccurrence.TabIndex = 2;
            this.amountOccurrence.Text = "Hoe vaak komt een getal voor";
            this.amountOccurrence.UseVisualStyleBackColor = true;
            this.amountOccurrence.Click += new System.EventHandler(this.amountOccurrence_Click);
            // 
            // highest
            // 
            this.highest.Location = new System.Drawing.Point(174, 228);
            this.highest.Name = "highest";
            this.highest.Size = new System.Drawing.Size(155, 23);
            this.highest.TabIndex = 3;
            this.highest.Text = "Highest number";
            this.highest.UseVisualStyleBackColor = true;
            this.highest.Click += new System.EventHandler(this.highest_Click);
            // 
            // lowest
            // 
            this.lowest.Location = new System.Drawing.Point(335, 228);
            this.lowest.Name = "lowest";
            this.lowest.Size = new System.Drawing.Size(155, 23);
            this.lowest.TabIndex = 4;
            this.lowest.Text = "Lowest number";
            this.lowest.UseVisualStyleBackColor = true;
            this.lowest.Click += new System.EventHandler(this.lowest_Click);
            // 
            // avgNumber
            // 
            this.avgNumber.Location = new System.Drawing.Point(291, 199);
            this.avgNumber.Name = "avgNumber";
            this.avgNumber.Size = new System.Drawing.Size(155, 23);
            this.avgNumber.TabIndex = 5;
            this.avgNumber.Text = "Average";
            this.avgNumber.UseVisualStyleBackColor = true;
            this.avgNumber.Click += new System.EventHandler(this.avgNumber_Click);
            // 
            // numericUpDown1
            // 
            this.numericUpDown1.Location = new System.Drawing.Point(110, 75);
            this.numericUpDown1.Name = "numericUpDown1";
            this.numericUpDown1.Size = new System.Drawing.Size(120, 20);
            this.numericUpDown1.TabIndex = 7;
            this.numericUpDown1.ValueChanged += new System.EventHandler(this.numericUpDown1_ValueChanged);
            // 
            // listBox1
            // 
            this.listBox1.FormattingEnabled = true;
            this.listBox1.Location = new System.Drawing.Point(236, 49);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(120, 95);
            this.listBox1.TabIndex = 6;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.numericUpDown1);
            this.Controls.Add(this.listBox1);
            this.Controls.Add(this.avgNumber);
            this.Controls.Add(this.lowest);
            this.Controls.Add(this.highest);
            this.Controls.Add(this.amountOccurrence);
            this.Controls.Add(this.addName);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button addName;
        private System.Windows.Forms.Button amountOccurrence;
        private System.Windows.Forms.Button highest;
        private System.Windows.Forms.Button lowest;
        private System.Windows.Forms.Button avgNumber;
        private System.Windows.Forms.NumericUpDown numericUpDown1;
        private System.Windows.Forms.ListBox listBox1;
    }
}

