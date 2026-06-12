# Building Hyperium

Hyperium is planned as a JUCE/CMake plugin project.

The current C++ code is an early skeleton intended to establish:

- project shape
- parameter IDs
- plugin processor/editor wiring
- UI-first layout direction
- placeholder audio output

It is not a finished synth engine yet.

## Requirements

Recommended local tools:

- CMake 3.22+
- a C++17 compiler
- Git
- a supported plugin host or DAW for testing VST3

Platform-specific tools:

- macOS: Xcode command line tools
- Windows: Visual Studio with C++ desktop workload
- Linux: a modern GCC/Clang toolchain and required JUCE system packages

## Configure

From the repository root:

```bash
cmake -S . -B build
```

The current `CMakeLists.txt` fetches JUCE automatically through CMake `FetchContent`.

## Build

```bash
cmake --build build --config Release
```

## Expected Targets

The current CMake target asks JUCE to generate:

- Standalone
- VST3

## Current Skeleton Scope

The current code includes:

```text
Source/
├── Parameters.h
├── Parameters.cpp
├── PluginProcessor.h
├── PluginProcessor.cpp
├── PluginEditor.h
└── PluginEditor.cpp
```

## Important Notes

### This is not production DSP yet

The current processor contains a simple placeholder voice. It exists so UI, MIDI, state saving, and parameters can be wired early.

The final Hyperium engine still needs:

- real wavetable playback
- anti-aliasing strategy
- voice management
- envelopes
- texture engine
- motion system
- macro mapping system
- FX chain
- preset browser

### UI-first development

Hyperium's core differentiator is workflow. The recommended next development step is to make the `PluginEditor` visually and interactively match the static prototype before overbuilding DSP.

## Suggested Development Loop

```bash
cmake -S . -B build
cmake --build build --config Debug
```

Then open the generated Standalone app or load the VST3 in a plugin host.

## Troubleshooting

### JUCE fetch fails

If `FetchContent` cannot download JUCE, clone JUCE manually and adapt `CMakeLists.txt` to use a local `add_subdirectory` path.

### Plugin does not appear in DAW

- confirm the VST3 built successfully
- rescan plugins in the DAW
- check that the plugin format is supported by the host
- test the Standalone target first

### UI opens but no polished synth sound

That is expected at this stage. The current audio path is a placeholder for development.
