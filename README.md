## How to use

```sh
./make.sh
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
