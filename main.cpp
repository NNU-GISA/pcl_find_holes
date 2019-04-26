#include <iostream>
#include <string>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include "easyloggingcpp/easylogging++.h"

// Initialize logging system
INITIALIZE_EASYLOGGINGPP
using namespace std;

int main (int argc, char** argv)
{
  // Load configuration from file
  el::Configurations conf("src/logConfig.config");
  // Reconfigure single logger
  el::Loggers::reconfigureLogger("default", conf);
  // Check command line for log-relevant flags
  START_EASYLOGGINGPP(argc, argv);
  // Log program title
  LOG(INFO) << argv[0] << " has started successfully\n";

  pcl::PointCloud<pcl::PointXYZ> cloud;
  // Load data
  string dataF = "data/20160426_CALIB.txt";
  if (pcl::io::load(dataF, cloud) == -1)
  {
    LOG(ERROR) << "Cannot load file " << dataF << "\n";
    return -1;
  }

  //pcl::io::savePCDFileASCII ("test_pcd.pcd", cloud);
  //std::cerr << "Saved " << cloud.points.size () << " data points to test_pcd.pcd." << std::endl;

  for (size_t i = 0; i < 5; ++i)
    std::cerr << "    " << cloud.points[i].x << " " << cloud.points[i].y << " " << cloud.points[i].z << std::endl;

  return (0);
}
