# Build Logs

## 2026-05-20 — Project planning and parts selection
- To begin my project, I had to come up with a plan. That plan I came up with is a typical SMARS-like car/rover except with visual/laser based sensor(s) and the ability to remote control drive it using one of my old Xbox controller.
- My main goal throughout this project is to learn how to 3D Model my own designs using FreeCAD, learn electronics engineering through my wiring and parts, and develop my coding skills into robotics applications.
- I hope to document this learning journey so that I can look back on all the progress I made and reflect on my growth.
- I selected Robo Pico + Pico WH as the controller stack because I wanted a cheap way to use the wireless capability to connect to my controller and I stumbled upon the Robo Pico purely by chance. I am sure there are a ton of other control boards that would satisfy what I need for this project, but this is the one I chose for no particular reason. Other than maybe the board being purple and I thought it looked cool.
- I chose VL53L5CX 8x8 ToF sensor for decent imaging and depth/fov for driving capabilities.
- I decided to start with 4xAA NiMH power instead of LiPo for safer beginner power management. I don't really understand all the stipulations that come with LiPo batteries, so this is safer.
- Open issue: verify encoder motor wire color mapping after motors arrive.

## 2026-05-24 — Motor inspection
- Motors arrived with six exposed wires: red, black, green, yellow, blue, white.
- Confirmed that the wire colors are not to be trusted. Correct labeling is as follows:
    - White - M1
    - Red - M2
    - Blue - GND
    - Green - C1
    - Yellow - C2
    - Black - Vin
- Other parts have begun to arrive. I now have the Pico W, the motors, the batteries, the battery holder and the sensor. I am awaiting the arrival of the Robo Pico.

## 2026-05-25 - Learning to Solder
- Today my soldering station came in the mail.
- I've never soldered before so I decided to start with an extra battery charger I bought. I stripped the wires attached to the battery holder to roughly 6mm. I did the same for two male dupont wires. I then threaded together the two exposed copper wires and soldered them together, successfully getting a working electrical connection. I then covered the joint with a heat shrink for safety.
- Practiced with the multimeter, the soldering iron, and the breadboard. Tested the 4x NiMh batteries and it's holder.
- Realized the Robo Pico only has a single Vin header, when I need three. Ordered a couple of Grove port adapters that I can use for the motor encoders and the sensor.

## 2026-05-26 - FreeCAD SMARS Tutorial
- Spent the day trying to learn FreeCAD so that I can make a parameterized SMARS chassis/wheel base that fits my needs.
- Followed the tutorial by KevsRobots.com. Site: https://www.kevsrobots.com/learn/freecad_smars/08_motor_holder.html
- I did NOT input my specific chassis specifications and rather just followed exactly the inputs as seen in the tutorial. I realized that this wasn't scalable once I reached the final step of the tutorial.
- Currently looking into FreeCAD spreadsheets so that if I decide to start from scratch on the tutorial, but with my values instead. That way I can update the parameterized values without needing to redo the 3D modeling all over again.
- Note about that tutorial: I'm not sure when it was published, but FreeCAD has changed a lot since then. Modern workarounds were needed for several of the steps involved in the process.
- Still waiting on the Robo Pico to arrive.
- Created the repository for this project!

## 2026-05-27 - More FreeCAD And Adapting The Tutorial Model To My Needs
- Continued yesterday's dive into learning FreeCAD. 
- I reworked what I had made yesterday following the tutorial to fit my specific needs. That included changing the chassis length/width and moving essential parts like the wheel attachments into their correct placement.
- My method for updating yesterday's model included heavy usage of the Spreadsheets function on FreeCAD. So now most of my parameters should be updatable from the spreadsheet + recomputation
- Photos of today's struggle are documented in media->FreeCAD->May_27_2026
- My Robo Pico should arrive tomorrow, which is when I can measure things more accurately and update the chassis model for better alignment
- Additional thought I had today: The original design I have been following from Kev's Robots was designed for an Arduino Nano, for the purpose of sliding into the chassis cleanly. That will not work with the Robo Pico because I have to use the Grove terminals, which demand extra space. Therefore, I will have to add some sort of bracket system on the inside of the chassis to hold the Robo Pico while also expanding the chassis width to accomodate that. I will not implement this change in the model until I have the Robo Pico in hand so I can measure it properly.

## 2026-05-30 - Even More FreeCAD And Developing Clip
- So Today's goal was to start looking into how I can develop a second level for my chassis so that I have a multilevel chassis with the bottom layer including the battery compartment and the motors while the top part has my Robo Pico board. So my idea was to have a clip feature so that I can clip the top part in and out from the bottom.
- I created my first test clip in FreeCAD and printed it out using my BambuLabs A1. It didn't go very well. I think the diameter of the circular peg I put onto the clip was too small and the printer has too large of a margin of error at that level. I think going forward I should increase the tolerances in my build so that the pegs fit into the holes better.
- After watching a youtube video about pegs and 3D printing I'm thinking of changing the design to be slimmer in width and moving away from the circular peg. I think if the bottom of the clip is a rectangle jutting out and the chassis having a rectangular opening, then it may be easier to 3d print.
- I came back later today and actually created a second version of the clip following what I had determined from the previously bullet. It worked better than the circle pin idea, but I identified further problems with it. First, the 3d print is not smooth. I think I'll have to sand things down regardless of what settings I put. Secondly, I need to add some thickness to the clamp arm so they don't bend and break. Third, I need to increase the overall width of the slot so the sides of the clip don't rub so much, causing placement in and out difficult (I had to sand out the holes and the sides to make it work). I think the overall design on this though may just work.
- Photos of today's progress can be found in media folder.

## 2026-06-03 - More FreeCAD and Developing Sensor/Eye Attachment + 3D Printing
- The past couple of days have all revolved around creating the chassis and successfully designing the clip for the top layer that the Robo Pico will sit on. I have since completed my design and 3D printed it using my Bambu Labs A1 printer. Now, I did not get it right in my first attempt. My first attempt at printing it in PetG at a 45 degree angle ended poorly, as documented in today's media folder. I had to turn on supports and increase the threshold angle to 45 degrees so that I was confident everything was supported. I also tried making my own support directly in FreeCAD, which was an interesting learning experience, but ultimately a mistake as I had to later saw it off and sand down the surface it had been stuck to.
- I have moved onto 3D modeling the "eye" of my SMARS robot. Normally the SMARS uses different sensors that are more cylindrical in nature, lending to an easier eye design. However, my sensor, the Time of Flight VL53L5CX, is rectangular and on a small PCB. Most of today was spent trying to think up and prototype a design that works.
- I went with a simple design of a rectangle that wedges onto the edge of the main chassis and attached to it is a smaller square and a cosmetic circle that acts as the eye. There is a gap in which I can slide my sensor in and out of once the sensor is actually attached to a small piece of plastic I also designed. I will likely try to print this either tonight or tomorrow since I am currently in the process of 3D printing the chassis for the first time.
- For almost all my design choices, I've decided instead of trying to guess the perfect wedge to hole ratios, it is best to make it the same size and then simply sand down sides and edges until everything works. It isn't clean, but it should work.
- Update: Printed my chassis and here are a couple takeaways: 
1. The motor holes in the chassis were too small by about 2mm. They needed to be sanded down to allow for that additional room to actually put the motors in and for the encoder to spin.
2. The clips I designed were very flimsy and broke very quickly. Luckily I designed the top piece to match the dimensions of the rest of the chassis so it can be shimmed into the main vehicle anyways. I will likely brake off the pegs that I made for the clips and just shim it in. The next iteration could use the holes in the chassis that were designed for the clips as holes for pegs to get hammered into. Kind of a bummer considering the time I put into designing those, but that's the learning process I suppose.
3. The shims to keep the motors secure is about half a milimeter too large. It just clips the attachment to the encoder on the motors. I can fix with a bit of sanding.
4. Battery holder is surprisngly a decent size 

## 2026-06-04 - Finishing up 3D Designs and Printing Everything Out + Lots of Sanding
- Today I spent most of my time finishing up on a couple of my 3D designs and then printing them out.
- I am now able to assemble my chassis with my eye and my top level. As I am typing, I am printing out the wheels. Important note for the wheels, that is one thing I am not designing myself. I am simply grabbing the public STL files for the powered and upowered wheels off of Kevs Robots website. 
- Once I physically know I can put all these physical pieces of my robot together, the next step is trying to actually learn the robotics side of this project. So that will be breadboard work, soldering wires together, and starting to develop the codebase for my project. 
- So far into the project I've focused on CAD work and 3D Parametric Design, which has been a lot of fun. I am still excited for the other portions of this project, but I think the 3D Design aspect was my main motivator. Time to get familiar with coding again.
- Photos of today's progress can be found in the media folder

## 2026-06-05 - Downloading Thonny & Testing A Motor and My Sensor
- Today was a big day because it was the first departure from FreeCAD and 3D modeling my chassis. Now it is all coding and programming my robot.
- I hooked up the Pico 2W to my Robo Pico and got it connected to my laptop. From there I successfully booted the Pico up and downloaded MicroPython onto it.
- Although I would've liked for my coding environment to be in my Linux virtual machine, I sadly have to use Thonny on Windows for the ease of my USB access.
- I hooked up my motor's power to the Robo Pico and tested it. Then I hooked up the encoder to Grove 3 slot and tested that the encoder works. It does, thankfully.
- Not so thankfully is the fact that I had to solder together wires that were not compatible and ended up accidentally burning myself with the soldering iron. It doesn't seem like a bad burn but it has left a white blister that has a residual dull pain.
- I also tested the sensor. Not super in depth, but I confirmed that it can connect to the Grove 2 port and that it can turn on. I haven't tried getting any readouts yet because I'm simply just not there yet. 
- Since this has been a day long ordeal of attempting to get MicroPython and the tests to work, I'm stopping progress a little early, but I am happy my components are working.
- As a last note before I forget: The wheels I printed out are somehow too big so that the shaft of the motor just spins inside it, which is annoying.

## 2026-06-06 - Testing Out Switching From Thronny to VSCode for Ease of Code Documentation
- While I was testing with Thronny the thought occured to me that I wouldn't be super easily able to document my progress with the code if I have to manually transfer the files over to here every time I changed something. So I looked into it and there's actually a well documented extention for VS Code where I can edit the code from there and still successfully connect to the Pico 2W.
- This is a good development for me because I am accustommed to coding in VSCode and I enjoy the perks that it comes with like my favorite color palette and easy Git control.
- It wasn't totally smooth sailing to get it setup, but I am happy to say that I have my code development under the code folder, which has been initialized with the MicroPico extension.
- I had to set up "Preferences: Open User Settings (JSON)" so that if I ever upload my code directly onto the board, it only takes things out of my code folder. I tested this and it did only pull the files I wanted it to. The alternative to uploading the entire project is to upload individual files one by one, but just in case I wanted to take this precaution.
- I will say that VSCode doesn't recognize "machine" as a package so it throws a warning with a yellow squiggly line, but the code still works, so its not a big deal. Just annoying.

## 2026-07-19 - Getting Back Into The Swing of Things + Project Path Correction
- It has been a little over a month since I have been able to spend any real meaningful effort to continue this project. Throughout the extended break, I have considered several aspects of this project. Here is what I have decided:
    1. I will be moving away from MicroPython and instead continue working on the project in Arduino/C++. This decision is a reflection of my desire to grow my skillset in other coding languages besides Python. In addition, it is strictly the better language to program a robot in since it is a compiler language and will save processing power/time. I do not currently have skills to code in C++, but I am hoping that I get to learn those skills throughout this project.
    2. I need to go back and reconfigure my 3D model for the "eye" of my robot, aka the VL52L5CX sensor holder. Currently, the sliding function works as intended, but I had failed to consider how the male dupont wires would stick out of the back of the sensor and then how the wires would physically make it back to the microcontroller. I had assumed the hole I left would be adequate, but as I put it on the main chassis, I realized that assumption was incorrect and that the hole was largely plugged by the side of the chassis. That was a crucial design error that I need to improve upon. So my current idea is to hop back into FreeCAD and instead of having the eye be on the very front of the chassis, I will have it raised up higher to allow for better wiring access.
    3. I should begin approaching this project with a more rigorous testing methodology. By that, I mean that my goals shouldn't just be to get the robot up and running, but to also be running quantitative tests on every aspect of the robot to get useful telemetry and meaningful data that I can then use to show performance statistics.
- Today my goal is to get the MicroPython I currently have flashed on my microcontroller replaced with the Arduino/C++ software instead. In addition to that, I would like to get my setup correctly oriented again in VSCode so that I do not have to use Arduino IDE. Whether or not that is possible currently is yet to be seen, but I vastly prefer using VSCode over other IDEs.
- Update: I successfully got a version of Arduino C++ functioning on my VSCode setup using the PlatformIO extention. I was also able to build my first testing script in C++ and "test" it using PlatformIO build. Moved my old MicroPython files into ~/code/legacy/micropython.