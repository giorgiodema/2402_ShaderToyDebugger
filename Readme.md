# ShaderToy Debugger

## Overview
The ShaderToy Debugger is a simple tool designed for debugging GLSL shaders. It emulates the ShaderToy environment, allowing shaders to run serially on a CPU. This setup enables the use of standard C++ debuggers, such as GDB, for inserting breakpoints and conducting thorough inspections.

## Key Features
- **Serial Execution:** Unlike the parallel nature of GPU, this debugger runs shaders serially on a CPU.
- **Compatibility with GLSL:** Most GLSL functionalities are supported, with GLM (OpenGL Mathematics) used for mathematical operations.
- **Debugging Tools:** Integrate with C++ debuggers like GDB for detailed debugging, including breakpoints.

## Syntax Adaptations
While the debugger strives to remain as close to the original GLSL syntax as possible, some minor differences exist:
- **Swizzling Method:** Swizzling in GLSL is slightly modified. It is performed via method invocation. For instance, the GLSL code `vec3 b = a.xyx;` should be written as `vec3 b = a.xyx();` in this debugger.

## Implemented ShaderToy Features
The debugger currently supports a limited but essential subset of ShaderToy features:
- `fragColor` and `fragCoord`
- `iTime`
- `iMouse`
- `iFrame`

These features are sufficient for basic debugging tasks. Users are encouraged to expand the functionality to include additional ShaderToy features as needed.
