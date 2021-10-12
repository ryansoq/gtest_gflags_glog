## How to use
example

```c++
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
```

```sh
>./make.sh
```

## Submodule information
You need to set the option to generate a static library
(BUILD_SHARED_LIBS "Build shared libraries" OFF)

```sh
cd <PROJECT>/third-party
git submodule add https://github.com/google/glog.git
cd glog
mkdir build
mkdir usr
cd build
cmake -DCMAKE_INSTALL_PREFIX=<PROJECT>/third-party/glog/usr
make 
make install

cd <PROJECT>/third-party
git submodule add https://github.com/gflags/gflags.git
cd glog
mkdir build
mkdir usr
cd build
cmake -DCMAKE_INSTALL_PREFIX=<PROJECT>/third-party/gflags/usr
make
make install

git submodule foreach --recursive git pull
```
