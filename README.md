Pour compiler

```bash
mkdir build
cd build
git clone git@github.com:yobeonline/test.git ../src
pushd ../src
git submodule init
git submodule update
popd
cmake ../src -G "Visual Studio 15 2017 Win64"
cmake --build . --target test --config Release
.\Release\test.exe
```