# Building the project for the first time

Regarding the **Game Engine Architecture** course, we were invited to try out the course framework and I was wondering if black screen into immediate exit (*see attached image*) is the intended behaviour of a build if we've made no changes to the repo? @carlitzer 

---

I'm developing with Visual Studio Code on Windows 10.
- `ninja version 1.12.1` (Installed via Chocolatery as per the [**README.md**](<https://github.com/cjgribel/eduEngine/blob/main/README.md>))  
- `cmake version 3.30.5-msvc23` (Installed via Visual Studio Installer)
- `clang version 19.1.1` (Installed via Visual Studio Installer)

### Miscellaneous build-process insights that might interest others using Visual Studio Code in Windows 10
Because VSC automatically executes tasks and launch commands in the regular terminal by default instead of a developer command prompt (whose use is required for your machine to recognise the build tools installed via Visual Studio Installer), it does not recognise `clang` or `cmake` when Run and Debugging (F5) since it then doesn't recognise the commands:

`cmake -G Ninja -S C:\users\chris\repos\eduEngine -B C:\users\chris\repos\eduEngine/Debug -DCMAKE_BUILD_TYPE=Debug`

`cmake -G Ninja -S C:\users\chris\repos\eduEngine -B C:\users\chris\repos\eduEngine/Release -DCMAKE_BUILD_TYPE=Release`

`cmake --build C:\users\chris\repos\eduEngine/Debug --config Debug`

`cmake --build C:\users\chris\repos\eduEngine/Release --config Release`

I ended up running these commands manually in my developer command prompt because I haven't figured out how to get VSC to do that automatically just yet. Then I just launched the `Module1.exe` executables manually as well.

---

I solved it.

1. Open VS Code using developer command prompt
2. Download the required assets
3. Run task `CMake Configure (Debug) (Ninja)`
4. Launch (`Launch (Debug)`)

---

# Problems I've encountered during feature implementation

Exact same code and implementation, but when I try to put the implementation in a `.cpp` file instead of in its respective header, I get a bunch of linker errors, even if I use the same `#include` arguments. What in the world?

I couldn't get `weak_ptr` to work, so I opted to use `shared_ptr`.

---

# Lab & Presentaton Feedback

```cpp
// USE THIS ENTITY ITERATION METHOD INSTEAD!
for(auto [entity, transform, velocity] : view.each())
{
    //...
    transform.position // do something...
    //...
}
```