# Hyperium Sound Seeds

Sound Seeds are one of Hyperium's signature workflow features.

They let the user start from a musical/emotional direction instead of a blank oscillator state.

## Goal

> Let producers create a useful starting patch with one click, then shape it with macros.

A Sound Seed should feel curated, not random.

## User-Facing Inputs

The full planned seed model has four input groups:

```text
Mood
Energy
Motion
Texture
```

### Mood

- glassy
- cute
- dreamy
- crushed
- vocal

### Energy

- soft
- medium
- hard

### Motion

- still
- pulsing
- drifting
- glitchy
- blooming

### Texture

- clean
- airy
- dusty
- digital
- tape
- grain
- breath

## Current C++ Implementation

The current first implementation lives in:

```text
Source/SoundSeed.h
Source/SoundSeed.cpp
```

The engine returns:

```text
presetName
description
parameter assignments
```

Each assignment contains:

```text
parameterId
normalizedValue
```

This keeps Sound Seeds compatible with the plugin parameter system and DAW automation model.

## Current UI Wiring

The `PluginEditor` seed buttons currently call the Sound Seed engine and write values into `AudioProcessorValueTreeState` parameters.

Current buttons:

- glassy
- cute
- dreamy
- crushed
- vocal

The `Generate` button currently chooses a random mood from the same set.

## Current Seed Behavior

### Glassy

Designed for bright hyperpop leads.

Common traits:

- higher oscillator positions
- bright macro
- glow macro
- digital texture
- glitchy motion

### Cute

Designed for candy-like pop plucks.

Common traits:

- moderate oscillator warp
- bright macro
- human macro
- airy texture
- medium energy

### Dreamy

Designed for indie-electronic pads and soft keys.

Common traits:

- softer filter/shape
- high glow
- wide macro
- drift macro
- tape texture
- blooming motion

### Crushed

Designed for aggressive hyperpop basses and leads.

Common traits:

- high oscillator warp
- high drive/shape
- high crush
- high punch
- low glow
- glitchy motion

### Vocal

Designed for formant-like synth movement.

Common traits:

- vocal-like oscillator position
- medium motion
- breath texture
- human macro
- glow macro

## Design Rules

### 1. Seeds should be constrained

A generated patch should not become painfully loud, broken, or useless.

### 2. Seeds should expose intent

The preset name and description should tell the user what kind of sound they created.

### 3. Seeds should be editable

The seed is only a starting point. After generation, the user edits normal controls and macros.

### 4. Seeds should preserve workflow

The user should not need to understand the engine internals to benefit from the seed.

## Next Implementation Steps

- Add seed input controls for Energy, Motion, and Texture
- Let Generate preserve selected dimensions
- Store seed metadata in presets
- Add seed-aware macro mapping
- Add undo support for seed application
- Add better preset naming
- Add weighted random generation by category

## Future Idea: Seed Locking

Let the user lock parts of a patch before regenerating.

Example:

```text
Lock Texture
Lock Macros
Regenerate Oscillators + Motion
```

This would make Sound Seeds feel like a creative partner rather than a randomizer.
