# Hyperium Architecture

This document outlines the planned architecture for Hyperium as a UI-first wavetable synth plugin.

## Architecture Goals

Hyperium should be built around three priorities:

1. stable real-time audio processing
2. clean UI/UX and fast creative workflow
3. modular enough internals to support future sound-design expansion

## Recommended Technology Stack

Initial direction:

- Language: C++
- Framework: JUCE
- Initial plugin format: VST3
- Future plugin formats: AU, CLAP
- Preset format: JSON or structured binary preset format
- Wavetable storage: indexed wavetable frames with metadata

## High-Level System

```text
MIDI Input
   ↓
Voice Manager
   ↓
Synth Voice
   ├── Oscillator A
   ├── Oscillator B
   ├── Sub Oscillator
   ├── Texture Layer
   ├── Filter / Shape
   └── Voice Envelope
   ↓
Global FX Chain
   ├── Pitch
   ├── Crush
   ├── Drive
   ├── Chorus
   ├── Space
   └── Comp
   ↓
Output
```

## UI / Audio Separation

The UI must never directly perform audio processing.

Recommended separation:

```text
UI Components
   ↓ parameter gestures
Parameter State
   ↓ smoothed values
DSP Engine
   ↓ audio buffers
Output
```

## Core Subsystems

### 1. Parameter System

All user-facing controls should map to stable parameter IDs.

Example IDs:

```text
oscA.wave
oscA.position
oscA.warp
oscA.level
oscB.wave
texture.type
texture.amount
filter.cutoff
motion.rate
macro.bright
macro.glow
fx.crush.amount
```

Parameter requirements:

- stable IDs
- automation-friendly names
- normalized values
- display values
- smoothing where needed
- preset serialization

### 2. Voice System

Each active MIDI note should create or reuse a voice.

Voice contains:

- pitch state
- velocity
- oscillator instances
- envelope state
- per-voice modulation values
- filter state

### 3. Wavetable System

Responsibilities:

- load wavetable assets
- interpolate wavetable frames
- provide anti-aliased playback strategy
- support oscillator position modulation
- support future procedural wavetable generation

MVP should support a small curated wavetable set before advanced generation.

### 4. Texture System

The texture layer should behave like a simplified noise/sample-inspired oscillator.

Types:

- Air
- Dust
- Glass
- Breath
- Bits
- Tape
- Static
- Grain

Texture should be lightweight and controllable by macros.

### 5. Motion System

The Motion system is a simplified modulation layer.

It should route one chosen movement source to one or more destinations with a musical interface.

Possible implementation:

```text
MotionSource
   type: Pulse | Drift | Glitch | Bloom | Orbit | Shake
   rate
   amount
   humanize
   phase

MotionAssignment
   source
   destinationParameterID
   depth
```

### 6. Macro System

Macros are high-level controls that move multiple lower-level parameters.

Example:

```text
Macro: Glow
   → texture.amount +0.15
   → fx.space.mix +0.20
   → filter.cutoff +0.10
   → wavetable.position +0.05
```

Macro mappings should be stored inside presets.

### 7. Sound Seed System

Sound Seeds generate useful starting patches.

Seed inputs:

```text
mood
energy
motion
texture
```

Seed outputs:

```text
oscillator choices
wavetable positions
texture type
filter setup
motion route
FX states
macro mappings
```

Seed generation can begin as deterministic rules. It does not need AI.

### 8. Preset System

Preset should store:

- parameter values
- macro mappings
- motion assignments
- seed metadata
- wavetable references
- texture type
- author/tags

Suggested preset tags:

- Glass
- Candy
- Crush
- Vocal
- Dream
- Pixel
- Motion
- Indie
- Chaos
- Starter

## UI Component Architecture

Suggested UI components:

```text
PluginEditor
├── HeaderBar
├── PresetBrowser
├── SeedStrip
├── MorphPad
├── OscillatorPanel A
├── OscillatorPanel B
├── TexturePanel
├── FilterShapePanel
├── MotionPanel
├── FXStrip
└── MacroBar
```

## UX State Model

The interface should support layered complexity:

```text
Simple View
   ↓ expand module
Advanced Module View
   ↓ expert action
Routing / Mapping View
```

The user should never be forced into expert mode for normal sound design.

## Real-Time Audio Rules

Audio thread must avoid:

- memory allocation
- locks
- file I/O
- UI calls
- dynamic object creation
- slow random generation

UI thread can handle:

- drawing
- preset browsing
- seed selection
- parameter gestures
- file dialogs

## Future Expansion

Potential future systems:

- procedural wavetable generator
- per-note modulation
- CLAP support
- deeper motion editor
- spectral texture modes
- custom wavetable import
- visual modulation lanes
- expanded preset cloud/library

## Architecture Rule

> Keep the audio engine stable and modular, but let the UI decide how much complexity the user sees.
