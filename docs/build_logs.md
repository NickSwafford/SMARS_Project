# Build Logs

## 2026-05-20 — Project planning and parts selection
- Defined project goal: Xbox-controlled rover with laser ToF sensing.
- Selected Robo Pico + Pico WH as the controller stack.
- Chose VL53L5CX 8x8 ToF sensor for decent imaging.
- Decided to start with 4xAA NiMH power instead of LiPo for safer beginner power management.
- Open issue: verify encoder motor wire color mapping after motors arrive.

## 2026-05-24 — Motor inspection
- Motors arrived with six exposed wires: red, black, green, yellow, blue, white.
- Confirmed that the wire colors are not to be trusted. Correct labeling is as follows:
White - M1
Red - M2
Blue - GND
Green - C1
Yellow - C2
Black - Vin
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

## 