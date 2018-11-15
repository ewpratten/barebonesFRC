#include <tuple>
#include <Subsystems/CVServer.hpp>

std::tuple<double, double> GetMotorSpeeds(std::shared_ptr<NetworkTable> &ntable){
    double Rotation = (ntable->GetNumber("cvserv_rotation", 0.00) / 100);
    double Speed = (ntable->GetNumber("cvserv_speed", 0.00) / 100);
    
    return  std::make_tuple(Speed, Rotation);
}