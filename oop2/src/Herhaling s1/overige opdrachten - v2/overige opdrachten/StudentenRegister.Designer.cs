namespace overige_opdrachten
{
    partial class StudentenRegister
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
            this.StudentCode = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.Adres = new System.Windows.Forms.TextBox();
            this.Geboortedatum = new System.Windows.Forms.TextBox();
            this.AddStudent = new System.Windows.Forms.Button();
            this.StudentsList = new System.Windows.Forms.ListBox();
            this.GetStudentInfo = new System.Windows.Forms.Button();
            this.label5 = new System.Windows.Forms.Label();
            this.GevolgdeVakken = new System.Windows.Forms.Button();
            this.TotalSBU = new System.Windows.Forms.Button();
            this.HighestResult = new System.Windows.Forms.Button();
            this.CompletedVakken = new System.Windows.Forms.Button();
            this.AddGrade = new System.Windows.Forms.Button();
            this.VakCode = new System.Windows.Forms.TextBox();
            this.Grade = new System.Windows.Forms.TextBox();
            this.VakNaam = new System.Windows.Forms.TextBox();
            this.SBU = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.StudentNaam = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // StudentCode
            // 
            this.StudentCode.BackColor = System.Drawing.Color.White;
            this.StudentCode.Location = new System.Drawing.Point(65, 27);
            this.StudentCode.Name = "StudentCode";
            this.StudentCode.Size = new System.Drawing.Size(100, 20);
            this.StudentCode.TabIndex = 1;
            this.StudentCode.Text = "1";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(201, 34);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(71, 13);
            this.label2.TabIndex = 3;
            this.label2.Text = "Student code";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(201, 142);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(34, 13);
            this.label3.TabIndex = 4;
            this.label3.Text = "Adres";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(201, 174);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(80, 13);
            this.label4.TabIndex = 5;
            this.label4.Text = "Geboortedatum";
            // 
            // Adres
            // 
            this.Adres.Location = new System.Drawing.Point(65, 142);
            this.Adres.Name = "Adres";
            this.Adres.Size = new System.Drawing.Size(100, 20);
            this.Adres.TabIndex = 6;
            this.Adres.Text = "testadres";
            // 
            // Geboortedatum
            // 
            this.Geboortedatum.Location = new System.Drawing.Point(65, 174);
            this.Geboortedatum.Name = "Geboortedatum";
            this.Geboortedatum.Size = new System.Drawing.Size(100, 20);
            this.Geboortedatum.TabIndex = 7;
            this.Geboortedatum.Text = "testgeboortedatum";
            // 
            // AddStudent
            // 
            this.AddStudent.Location = new System.Drawing.Point(65, 200);
            this.AddStudent.Name = "AddStudent";
            this.AddStudent.Size = new System.Drawing.Size(100, 23);
            this.AddStudent.TabIndex = 8;
            this.AddStudent.Text = "Voeg student toe";
            this.AddStudent.UseVisualStyleBackColor = true;
            this.AddStudent.Click += new System.EventHandler(this.AddStudent_Click);
            // 
            // StudentsList
            // 
            this.StudentsList.ForeColor = System.Drawing.Color.Tomato;
            this.StudentsList.FormattingEnabled = true;
            this.StudentsList.Location = new System.Drawing.Point(584, 30);
            this.StudentsList.Name = "StudentsList";
            this.StudentsList.Size = new System.Drawing.Size(120, 95);
            this.StudentsList.TabIndex = 9;
            // 
            // GetStudentInfo
            // 
            this.GetStudentInfo.Location = new System.Drawing.Point(391, 51);
            this.GetStudentInfo.Name = "GetStudentInfo";
            this.GetStudentInfo.Size = new System.Drawing.Size(147, 23);
            this.GetStudentInfo.TabIndex = 10;
            this.GetStudentInfo.Text = "Student info";
            this.GetStudentInfo.UseVisualStyleBackColor = true;
            this.GetStudentInfo.Click += new System.EventHandler(this.GetStudentInfo_Click);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(388, 30);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(139, 13);
            this.label5.TabIndex = 11;
            this.label5.Text = "Vul eerst de student code in";
            // 
            // GevolgdeVakken
            // 
            this.GevolgdeVakken.Location = new System.Drawing.Point(391, 80);
            this.GevolgdeVakken.Name = "GevolgdeVakken";
            this.GevolgdeVakken.Size = new System.Drawing.Size(147, 23);
            this.GevolgdeVakken.TabIndex = 12;
            this.GevolgdeVakken.Text = "Gevolgde vakken";
            this.GevolgdeVakken.UseVisualStyleBackColor = true;
            this.GevolgdeVakken.Click += new System.EventHandler(this.GevolgdeVakken_Click);
            // 
            // TotalSBU
            // 
            this.TotalSBU.Location = new System.Drawing.Point(391, 142);
            this.TotalSBU.Name = "TotalSBU";
            this.TotalSBU.Size = new System.Drawing.Size(182, 23);
            this.TotalSBU.TabIndex = 13;
            this.TotalSBU.Text = "De totaal behaalde studielast";
            this.TotalSBU.UseVisualStyleBackColor = true;
            this.TotalSBU.Click += new System.EventHandler(this.TotalSBU_Click);
            // 
            // HighestResult
            // 
            this.HighestResult.Location = new System.Drawing.Point(391, 174);
            this.HighestResult.Name = "HighestResult";
            this.HighestResult.Size = new System.Drawing.Size(147, 23);
            this.HighestResult.TabIndex = 14;
            this.HighestResult.Text = "Het hoogste resultaat";
            this.HighestResult.UseVisualStyleBackColor = true;
            this.HighestResult.Click += new System.EventHandler(this.HighestResult_Click);
            // 
            // CompletedVakken
            // 
            this.CompletedVakken.Location = new System.Drawing.Point(391, 110);
            this.CompletedVakken.Name = "CompletedVakken";
            this.CompletedVakken.Size = new System.Drawing.Size(147, 23);
            this.CompletedVakken.TabIndex = 15;
            this.CompletedVakken.Text = "De behaalde vakken";
            this.CompletedVakken.UseVisualStyleBackColor = true;
            this.CompletedVakken.Click += new System.EventHandler(this.CompletedVakken_Click);
            // 
            // AddGrade
            // 
            this.AddGrade.Location = new System.Drawing.Point(65, 382);
            this.AddGrade.Name = "AddGrade";
            this.AddGrade.Size = new System.Drawing.Size(100, 23);
            this.AddGrade.TabIndex = 16;
            this.AddGrade.Text = "Voeg cijfer toe";
            this.AddGrade.UseVisualStyleBackColor = true;
            this.AddGrade.Click += new System.EventHandler(this.AddGrade_Click);
            // 
            // VakCode
            // 
            this.VakCode.Location = new System.Drawing.Point(65, 276);
            this.VakCode.Name = "VakCode";
            this.VakCode.Size = new System.Drawing.Size(100, 20);
            this.VakCode.TabIndex = 17;
            this.VakCode.Text = "1";
            // 
            // Grade
            // 
            this.Grade.Location = new System.Drawing.Point(65, 302);
            this.Grade.Name = "Grade";
            this.Grade.Size = new System.Drawing.Size(100, 20);
            this.Grade.TabIndex = 18;
            this.Grade.Text = "6";
            // 
            // VakNaam
            // 
            this.VakNaam.Location = new System.Drawing.Point(65, 329);
            this.VakNaam.Name = "VakNaam";
            this.VakNaam.Size = new System.Drawing.Size(100, 20);
            this.VakNaam.TabIndex = 19;
            this.VakNaam.Text = "Wiskunde";
            // 
            // SBU
            // 
            this.SBU.Location = new System.Drawing.Point(65, 356);
            this.SBU.Name = "SBU";
            this.SBU.Size = new System.Drawing.Size(100, 20);
            this.SBU.TabIndex = 20;
            this.SBU.Text = "5";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(201, 112);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(73, 13);
            this.label1.TabIndex = 22;
            this.label1.Text = "Student naam";
            // 
            // StudentNaam
            // 
            this.StudentNaam.Location = new System.Drawing.Point(65, 105);
            this.StudentNaam.Name = "StudentNaam";
            this.StudentNaam.Size = new System.Drawing.Size(100, 20);
            this.StudentNaam.TabIndex = 21;
            this.StudentNaam.Text = "test";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(183, 279);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(52, 13);
            this.label6.TabIndex = 23;
            this.label6.Text = "vak code";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(186, 302);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(30, 13);
            this.label7.TabIndex = 24;
            this.label7.Text = "Cijfer";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(186, 329);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(35, 13);
            this.label8.TabIndex = 25;
            this.label8.Text = "Naam";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(189, 362);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(29, 13);
            this.label9.TabIndex = 26;
            this.label9.Text = "SBU";
            // 
            // StudentenRegister
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 541);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.StudentNaam);
            this.Controls.Add(this.SBU);
            this.Controls.Add(this.VakNaam);
            this.Controls.Add(this.Grade);
            this.Controls.Add(this.VakCode);
            this.Controls.Add(this.AddGrade);
            this.Controls.Add(this.CompletedVakken);
            this.Controls.Add(this.HighestResult);
            this.Controls.Add(this.TotalSBU);
            this.Controls.Add(this.GevolgdeVakken);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.GetStudentInfo);
            this.Controls.Add(this.StudentsList);
            this.Controls.Add(this.AddStudent);
            this.Controls.Add(this.Geboortedatum);
            this.Controls.Add(this.Adres);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.StudentCode);
            this.Name = "StudentenRegister";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.TextBox StudentCode;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox Adres;
        private System.Windows.Forms.TextBox Geboortedatum;
        private System.Windows.Forms.Button AddStudent;
        private System.Windows.Forms.ListBox StudentsList;
        private System.Windows.Forms.Button GetStudentInfo;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Button GevolgdeVakken;
        private System.Windows.Forms.Button TotalSBU;
        private System.Windows.Forms.Button HighestResult;
        private System.Windows.Forms.Button CompletedVakken;
        private System.Windows.Forms.Button AddGrade;
        private System.Windows.Forms.TextBox VakCode;
        private System.Windows.Forms.TextBox Grade;
        private System.Windows.Forms.TextBox VakNaam;
        private System.Windows.Forms.TextBox SBU;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox StudentNaam;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
    }
}

