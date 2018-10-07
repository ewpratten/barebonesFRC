# BarebonesFRC
[![CircleCI](https://circleci.com/gh/Ewpratten/barebonesFRC/tree/master.svg?style=svg)](https://circleci.com/gh/Ewpratten/barebonesFRC/tree/master) [![DOI](https://zenodo.org/badge/132483654.svg)](https://zenodo.org/badge/latestdoi/132483654)

A barebones-ish codebase written in c++ to quickly get a robot driving

## How to Use?
Just clone the repo:
```sh
git clone https://github.com/ewpratten/barebonesfrc.git
```
Then open it in vscode.

## Why?
I \([@ewpratten](Https://github.com/ewpratten)\) have been observing comments and posts on various threads about FRC. They are a great place to learn new things (and sometimes you can find out about cool new tools from FRC half a year before release). During the first two months of the 2018 season, I kept seeing the same thing over and over again. "It has been 3 weeks and the programmers haven't even gotten to see the robot to start programming it" "Why should we have to give our programmer more than three days with the robot? How long does it take them?? All they have to do is press *Upload Code* right?". There are plenty more posts of programmers complaining that they arent given enough time and more posts where builders are complaining that the programmers are taking too long to get the drivebase to work. (yes.. we \([@frc5024](Https://github.com/frc5024)\) took a while to get our robot to do basic things too..) So, I came up with an idea. Why not build a simple (ish) codebase that (most) teams can use to immeadiatly get their bot moving around (and there is an integrated network based opencv server built in). So. This is it!

Now.. To address all those side-notes. The reason I say simple-ish is because the code is really just a super stripped down (and updated) version of: [5024 PowerUp](Https://github.com/frc5024/PowerUp). The code could be a lot smaller and more efficent (we are working on the efficency part) but I ran out of time to test the code because school finished. This codebase can not be used by all teams because **1.** It is written in c++. Not java or python. and **2.** Currently, the only supported ESC is the Talon SRX.

## Building the documentation
To build the documentation, make sure you have doxygen installed, then run:
```sh
doxygen ./doxygen.config 
```
The documentation will the be automattically pushed to the website for this repo.

## How do I Use This OpenCV Server?
Using the OpenCV Server is quite simple.

The "server" (more like an api) is designed to let you build whatever off-board vision code you want using any tools you want! Just plug a webcam in to the rio then follow these steps:
 - Make sure that both `Vision` and `Camera_Server` are equal to **true** in `RobotCFG.hpp`
 - Reboot the RIO
 - Connect your off-board device to the wifi or ethernet network
 - In your vision code on the device, set your camera feed to get video (mJPG stream) from http://10.TE.AM.2:1181/stream.mjpg (Replace TE.AM with your team number. for example, 50.24)
 - Use one of the many NetworkTables libraries (Like [this](https://github.com/robotpy/pynetworktables) one) to send your output motor speeds to the robot
 - Send the forward speed through `cvserv_speed`
 - Send the rotation through `cvserv_rotation`
 - Hold the **B** button on your controller during teleop and the robot will be fully controlled by your off-board code
 - Feel free to send sensor data through NetworkTables too!

If you would like an example of some off-board vision code, or are too lazy to write it yourself, check out my repo called [RIOCV-PI](https://github.com/Ewpratten/RioCV-PI) for some vision code that follows a PowerUp cube.

**Note for 5024 members:** until we set up cameras on the robot, and have a co-prosessor set up, our master branch **must** have this feature disabled.

## Info about CI
More info on that can be found over at my [CI For FRC](https://github.com/Ewpratten/FRC-CI) repo.

## Who Made This?
This project is based off of the [2017](https://github.com/RaiderRobotics5024/2017Main) and [2018](Https://github.com/frc5024/PowerUp) codebases from Team [5024](Https://github.com/frc5024)

The code was originally designed by:
 - [@ewpratten](Https://github.com/ewpratten)
 - [@slownie](Https://github.com/slownie)

And was tested by:
 - [@ewpratten](Https://github.com/ewpratten)
 - [@slownie](Https://github.com/slownie)
 - Andrew (non-githubber)
 - Ethan (non-githubber)
 - Josh (non-githubber)
 - [@retrax24](Https://github.com/retrax24)
 - [@Volxz](Https://github.com/Volxz)
 - Nick (non-githubber)

The OpenCv code can be found at:
https://github.com/Ewpratten/RioCV-PI

And was written by:
 - [@ewpratten](Https://github.com/ewpratten)
 - [@retrax24](Https://github.com/retrax24)

Special thanks to our two awesome programming mentors:
 - [@johnlownie](https://github.com/johnlownie)
 - [@LordMichaelmort](https://github.com/LordMichaelmort)
