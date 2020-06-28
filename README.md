# War-Thunder-IRL
Ever wanted to build a (simple) cockpit and the use the real time data from warthunder? That is now possible! Using the rest api of war thunder we are capable to do that.

**TODO: update Installation**
# Prerequisites
## Hardware
 - Arduino uno 
    - Other arduino compatable will probably work too, may need some tinkering in the source.
 - Jumper wires
 - Servo(s)
 
 ## Mentality
  - This is my first open source project, so please be kind. 😊
 

# Installation
## Step 1: Making sure the api works
Start a test flight in war thunded and start flying.
Open this url in the browser: http://127.0.0.1:8111/. If a page pops up with info, HURRAY! else....

Try
 - Start war thunder
 - Open settings
 - find something like "Enable Api"

## Step 2: install Visual studio (for if you want to modify the source code)
If you have not installed visual studio yet, install from [here](https://visualstudio.microsoft.com/).
Make sure that in the installer you select ".NET desktop development" for installment.

When installed open the solution by double clicking on "WarThunderScraper.sln" in the "War_Thunder_Scraper" folder. 

## Step 3: Edit / upload arduino code
### Option 1: using VSC
If you are using Visual Studio Code, you can use the extention platform.io. Using this extention you can instantly
 upload the code to the arduino(Default set do arduino uno, change this in file "platformio.ini" if neccecery)
  
### Option 2: using Arduino ide
If you don't want to use the platform.io extention you can resort to using the [Arduino IDE](https://www.arduino.cc/en/Main/Software).
You will need to change the folder structure of the source. Basically move all items from lib to the src, rename all files that end
in .cpp to .ino and open this folder in the IDE. Some tinkering to make this work may be needed.

## Step 4: Setting up hardware.
*Example tutorial coming soon (Hopefully...)*

For my own version I 3d printed [this speedometer](https://www.thingiverse.com/thing:3745020) 


#Usage
Once you opened the solution in VS, press f5 to start the application. Select the com port you thing your arduino is connected to. 
Start war thunder and start the application

**TADA!**

# Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

# License
[MIT](https://choosealicense.com/licenses/mit/)
