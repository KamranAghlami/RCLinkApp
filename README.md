# RCLinkApp
This is the WebAssembly running behind the [RCLink](https://github.com/KamranAghlami/RCLink).
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
#### Debugging inside VSCode
In order to debug the project inside VSCode, install the [WebAssembly DWARF Debugging](https://marketplace.visualstudio.com/items?itemName=ms-vscode.wasm-dwarf-debugging) extension, open `index.html` using [Live Preview]() extension, and then use `Debug: Open Link` command.
#### Debugging with Chrome
In order to debug the project using Chrome DevTools, install the [C/C++ DevTools Support (DWARF)](https://chromewebstore.google.com/detail/cc++-devtools-support-dwa/pdcpmagijalfljmkmjngeonclgbbannb) extension.
##### Note about WSL2
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
Reloade the DevTools and sources now should be found.
