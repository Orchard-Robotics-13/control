#ifndef BASE_PLANNER_H
#define BASE_PLANNER_H

// includes 
#include "control/interface/base_controller.hpp"

/**
 * @brief Main planner node
 * @ the idea 
 * the planner gives the main pointers and directions to the control node.
 * 
 * Workflow:
 * A plot of land is preselected and given to the planner. 
 * the planner probes current location of the robot.
 * checks if it already on a mission and slots the next mission after completing the current one.
 * 
 * if idle 
 * the planner starts a system health check
 * location check and surrounding scan via camera.
 * the idea to give a go ahead that everything is safe and ready to go..
 * 
 * 2nd location of the plot is given to the robot selecting the entry point based on the efficeint path.
 * 
 * the robot navigates to the position - given farmland outlook would mostly be straight lines
 * 
 * enters into selected plot - post a min safe dist into land - does surrounding scan and enables all 
 * required sensors.
 * returns a status level after hearing from the sensors.- high - med - low ------( Will need to decide these)
 * 
 * the planner gives the remaining overall points based on the land selection. 
 * 
 * the robot inspecting tress and land can be at different levels on inspection depending on what the client
 * wants and other constraints battery , system temps, outdoor temps and status of sensors of what is possible.
 * 
 * the idea to have max utilization even though things might not be avialable. 
 * 
 * the robot follows gathering data and finishes mission.
 * 
 * post finish the home position of the base is called - (predefined)
 */

 namespace control::planner