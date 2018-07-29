#pragma once
#include <tuple>
#include <WPILib.h>
#include <ntcore.h>

std::tuple<double, double> GetMotorSpeeds(std::shared_ptr<NetworkTable> &ntable);