# War-Thunder-IRL

## To stop my crippling war thunder addiction, I decided to delete War Thunder. This means this project is not under development anymore!

This program retrieves data from your war thunder client and displays them physically in real life!

## Demo
https://www.reddit.com/r/Warthunder/comments/hqg5t7/wip_bringing_warthunder_to_life_sorry_for_potato/
# Prerequisites
## Hardware
 - Arduino uno 
    - Other arduino compatable boards will probably work too, may need some tinkering in the code for using the correct pins.
 - Jumper wires
 - stepper(s). I used the 28byj-48 as they are very cheap and are used in the 3d print.
 - For more then 1 stepper, you need an external powersupply
 - I used [this](https://www.thingiverse.com/thing:3745020) 3d print as gauge
 
 ## Mentality
  - This is my first open source project, so please be kind. 😊
 
# Installation
## Step 1: Making sure the api works
Start a test flight in war thunder and start flying.
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
### Option 1: using VSC (Recommended)
If you are using Visual Studio Code, you can use the extention "platform.io". Using this extention you can instantly
 upload the code to the arduino(Default set do arduino uno, change this in file "platformio.ini" if neccecery).
 [More info](https://docs.platformio.org/en/latest/integration/ide/vscode.html#platformio-toolbar)
  
### Option 2: using Arduino ide
If you don't want to use the platform.io extention you can resort to using the [Arduino IDE](https://www.arduino.cc/en/Main/Software).
You will need to change the folder structure of the source. Basically move all items from the lib to the src folder, rename all files that end
in .cpp to .ino and open this folder in the IDE. Some tinkering to make this work may be needed.

## Step 4: Setting up hardware.
*Example tutorial coming soon (Hopefully...)*

For my own version I 3d printed [this speedometer](https://www.thingiverse.com/thing:3745020) 

# Usage
*Make sure you connected your arduino via usb or bluetooth*
### Option 1: VS
Once you opened the solution in VS, press f5 to start the application. Select the com port you think your arduino is connected to. 
Start a flight and start the application

### Option 2: Executable
Dubble click the executable you downloaded from releases. Select the com port you think your arduino is connected to. 
Start a flight and start the application

**TADA!**

# Roadmap (So far)
- finishing Unit testing
- Negging the devs to improve the api
- Improve UI 
- Refactor code 
# Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

# License
[MIT](https://choosealicense.com/licenses/mit/)
