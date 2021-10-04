#include <gflags/gflags.h>
#include <glog/logging.h>

int main(int argc, char* argv[])
{
    // parse command line parameters
    gflags::ParseCommandLineFlags(&argc, &argv, true);

    // Initialize the log
    google::InitGoogleLogging(argv[0]);
    LOG(ERROR) << "Hello, World!";
}
