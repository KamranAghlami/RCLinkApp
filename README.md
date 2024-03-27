# RCLinkApp
This is the WebAssembly running behind the [RCLink](https://github.com/KamranAghlami/RCLink) project.
### Build
In order to build the project using VSCode add this to your _`settings.json`_ file.
``` json
{
    "cmake.configureArgs": [
        "-DCMAKE_TOOLCHAIN_FILE=/path/to/your/emsdk/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake"
    ]
}
```
### Debug
In order to debug the project using Chrome, install the `C/C++ DevTools Support (DWARF)` extension.
#### Debugging when building with WSL2
 The extension tries to open files locally, this is problematic when using WSL2, I fixed it by adding the following as path substitutions in the extension's options: (pay attention to the order and adjust to your emsdk installation directory.)

```
"/b/s/w/ir/x/w/install" -> "//wsl.localhost/Ubuntu/path/to/your/emsdk/upstream"

"/emsdk/emscripten" -> "//wsl.localhost/Ubuntu/path/to/your/emsdk/upstream/emscripten"

"/" -> "//wsl.localhost/Ubuntu/"
```
Then go to the DevTools settings, and enable the following option:
```
Allow DevTools to load resources, such as source maps, from remote file paths. Disabled by default for security reasons.
```
Reloaded the DevTools and sources now should be found.
