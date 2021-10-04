#include <iostream>

#include <gflags/gflags.h>
#include <glog/logging.h>

static bool ValidatePort(const char* flagname, gflags::int32 value)
{
    if (value > 0 && value < 32768)
    {
        return true;
    }
    return false;
}

DEFINE_int32(port, 9527, "What port to listen on");
DEFINE_validator(port, &ValidatePort);

DEFINE_bool(debug, false, "Turn on the debug mode");

int main(int argc, char* argv[])
{
    // parse command line parameters
    gflags::ParseCommandLineFlags(&argc, &argv, true);
    // ./example --port=80 --debug
    std::cout << "port = " << FLAGS_port << std::endl;
    std::cout << "debug = " << std::boolalpha << FLAGS_debug << std::endl;

    // Initialize the log
    google::InitGoogleLogging(argv[0]);
    CHECK_LE(5, 6);
    LOG(ERROR) << "Hello, World!";
}
