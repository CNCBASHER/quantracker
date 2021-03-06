#ifndef TELEMETRY_HPP_INCLUDED
#define TELEMETRY_HPP_INCLUDED

#include <quan/uav/position.hpp>
#include "frsky_serial_port.hpp"

struct telemetry{

   typedef quan::angle::deg lat_lon_type;
   typedef quan::length::mm     altitude_type;

   typedef quan::uav::position<lat_lon_type,altitude_type> gps_position;
   static constexpr quan::length::m  			  radius_of_world{6371000};

   static gps_position m_home_position;
   static gps_position m_aircraft_position;
   static frsky_serial_port serial_port;

   static void recalc();

   static void parse_input();
  
   static bool state_changed;
   static void set_home();
   static void filter_pos();
   
};


#endif // TELEMETRY_HPP_INCLUDED
