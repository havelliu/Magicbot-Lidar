#include <urdf/model.h>
#include "ros/ros.h"

int main(int argc, char** argv)
{
	ros::init(argc, argv, "magicbot_parser");
	if(argc != 2)
	{
		ROS_ERROR("NEED AN URDF FILE AS AN ARGUMENT");
		return -1;
 	}
	std::string urdf_file = argv[1];

	urdf::Model model;
	if(!model.initFile(urdf_file))
	{
		ROS_ERROR("FAILED TO PARSE URDF FILE");
		return -1;
	}
	ROS_INFO("SUCCESSFULLY PARSED URDF FILE");
	return 0;
}
