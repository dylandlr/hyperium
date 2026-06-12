# Hyperium

**Hyperium** is a minimal wavetable synth designed for hyperpop, pop, electronic, and experimental indie sound design.

The goal is not to clone Serum. The goal is to keep the speed and flexibility producers love from modern wavetable synths, while building a more focused workflow around **glossy sound design, emotional movement, texture, glitch, and performance-ready macros**.

## Product Vision

> Hyperium is a fast, minimal, modern wavetable VST where producers can create polished hyperpop, pop, electronic, and indie-electronic sounds without getting trapped in technical menus.

Hyperium should feel like:

```text
open plugin
choose a seed
shape the tone
add motion
perform with macros
finish the sound
```

## Design Pillars

### 1. Minimal surface, deep engine

The interface should stay clean and musical. Advanced synthesis should exist underneath, but the first layer of interaction should feel simple, emotional, and fast.

### 2. UI/UX is part of the sound

Hyperium is not only an audio engine. The UI should directly improve the user's musical workflow. Every control should help the user move from idea to usable sound faster.

### 3. Hyperpop-first sound design

Hyperium should specialize in:

- glassy leads
- glossy pop plucks
- vocal-like synths
- bright digital bells
- crushed basses
- glitchy arps
- nostalgic indie-electronic keys
- airy textures
- shimmering pads
- experimental electronic motion

### 4. Emotional controls over technical clutter

Instead of exposing only technical controls, Hyperium should use musical controls like:

- Glow
- Crush
- Drift
- Wide
- Punch
- Glitch
- Human
- Bright

The math and DSP can be complex, but the workflow should remain intuitive.

## Prototype

A static UI prototype lives in:

```text
prototype/index.html
```

Open it in a browser to test the current interaction direction:

- Sound Seed buttons
- draggable Morph Pad
- keyboard-accessible Morph Pad
- Motion selector
- waveform visual previews
- Texture visualization
- FX strip
- Performance Macro bar

This prototype is intentionally non-audio. Its job is to validate workflow and visual hierarchy before the JUCE/DSP implementation gets heavy.

## Core MVP

The first real version should focus on a small but powerful feature set:

### Sound Engine

- 2 wavetable oscillators
- 1 sub oscillator
- 1 texture/noise layer
- multimode filter
- waveshaper
- curated FX chain

### Modulation

- 2 envelopes
- 2 LFOs
- 1 Motion lane
- 8 macros
- basic modulation matrix

### Hyperium Signature Features

- **Sound Seeds**: guided procedural preset generation
- **Macro Morph Pad**: performable emotional patch morphing
- **Texture Layer**: air, dust, glass, bits, tape, grain, breath
- **Octave Stack**: instant hyperpop octave layering
- **Vocalize**: formant and vowel-inspired synth shaping
- **Glitch Gate**: fast rhythmic chops and stutters

## Main UI Concept

Hyperium should primarily live on one screen:

```text
┌──────────────────────────────────────────────┐
│                 HYPERIUM                     │
│        Preset Browser / Main Macro Bar        │
├───────────────┬───────────────┬──────────────┤
│     OSC A     │     OSC B     │   TEXTURE    │
├───────────────┴───────────────┴──────────────┤
│                 FILTER / SHAPE                │
├──────────────────────────────────────────────┤
│                  MOTION                       │
├──────────────────────────────────────────────┤
│                    FX                         │
├──────────────────────────────────────────────┤
│               PERFORMANCE MACROS              │
└──────────────────────────────────────────────┘
```

## Repository Structure

```text
hyperium/
├── README.md
├── docs/
│   ├── PRODUCT_SPEC.md
│   ├── UI_UX_SPEC.md
│   ├── DESIGN_SYSTEM.md
│   ├── INTERACTION_FLOWS.md
│   ├── ARCHITECTURE.md
│   ├── ROADMAP.md
│   └── MVP_BACKLOG.md
├── prototype/
│   ├── index.html
│   ├── styles.css
│   └── app.js
└── .gitignore
```

## Current Status

This repository currently contains the product foundation, UI/UX specification, design system, interaction flows, MVP backlog, architecture plan, roadmap, and a static UI prototype.

The next step is to convert the prototype into a JUCE plugin shell and begin connecting parameters to placeholder DSP.

## Guiding Rule

> If a feature makes the plugin more powerful but slows the user's creative flow, hide it, simplify it, or remove it.
