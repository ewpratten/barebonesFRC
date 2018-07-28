# BarebonesFRC
A barebones-ish codebase written in c++ to quickly get a robot driving

## How to Use?
Just clone the repo:
```bash
# For the main repo:
git clone https://github.com/ewpratten/barebonesfrc.git

# For the 5024 fork:
git clone https://github.com/frc5024/barebonesfrc.git
```
Then open it in vscode (That is explained below)

## Why?
I \([@ewpratten](Https://github.com/ewpratten)\) have been observing comments and posts on various threads about FRC. They are a great place to learn new things (and sometimes you can find out about cool new tools from FRC half a year before release). During the first two months of the 2018 season, I kept seeing the same thing over and over again. "It has been 3 weeks and the programmers haven't even gotten to see the robot to start programming it" "Why should we have to give our programmer more than three days with the robot? How long does it take them?? All they have to do is press *Upload Code* right?". There are plenty more posts of programmers complaining that they arent given enough time and more posts where builders are complaining that the programmers are taking too long to get the drivebase to work. (yes.. we \([@frc5024](Https://github.com/frc5024)\) took a while to get our robot to do basic things too..) So, I came up with an idea. Why not build a simple (ish) codebase that (most) teams can use to immeadiatly get their bot moving around (and there is an integrated network based opencv server built in). So. This is it!

Now.. To address all those side-notes. The reason I say simple-ish is because the code is really just a super stripped down (and updated) version of: [5024 PowerUp](Https://github.com/frc5024/PowerUp). The code could be a lot smaller and more efficent (we are working on the efficency part) but I ran out of time to test the code because school finished. This codebase can not be used by all teams because **1.** It is written in c++. Not java or python. and **2.** Currently, the only supported ESC is the Talon SRX.

## How do I Use This OpenCV Server?
Currently, the answer is **Don't**. We haven't had the time to document it and it needs some rewriting. Just don't touch the `camx` and `fspeed` vars in NetworkTables and everything should be fine. (also, unbind the **B** button in the code)

## Why Does the Project Look Weird?
*This section will be outdated as of January 6 2019*
This is the first public project ever (I think) to use the FRC 2019 Toolchain, Build system, and vscode plugin.

Instructions on installing the tools can be found here: [FRC 2019 Beta](https://wpilib.screenstepslive.com/s/currentCS/m/79833/c/259485)

You can use the `gradlew` or `gradlew.bat` files to build, deploy, and test from commandline.

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
 - [@retrax24](Https://github.com/retrax24)
 - [@Volxz](Https://github.com/Volxz)

The OpenCv code can be found at:
https://github.com/Ewpratten/RioCV-PI

And was written by:
 - [@ewpratten](Https://github.com/ewpratten)
 - [@retrax24](Https://github.com/retrax24)

Special thanks to our two programming mentors:
 - [@johnlownie](https://github.com/johnlownie)
 - [@LordMichaelmort](https://github.com/LordMichaelmort)
