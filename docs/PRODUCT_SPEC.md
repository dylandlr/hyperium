# Hyperium Product Specification

## Product Summary

**Hyperium** is a minimal wavetable synth for hyperpop, pop, electronic, and experimental indie sound design.

It combines a focused wavetable engine, modern texture layering, simplified modulation, curated hyperpop FX, and a workflow-first UI into a plugin that helps producers create polished sounds quickly.

## Product Positioning

Hyperium is not trying to replace every synth.

It is designed to be the synth a producer opens when they want:

- a glossy hyperpop lead
- a fast pop pluck
- a dreamy indie-electronic pad
- a crushed digital bass
- a vocal-like synth layer
- a glitchy motion patch
- a finished sound with minimal setup

## Comparison

| Tool | Strength | Hyperium Difference |
|---|---|---|
| Serum | deep wavetable synthesis | faster, more focused, more emotional workflow |
| Ableton Wavetable | clean native workflow | stronger character, texture, and hyperpop FX |
| Vital | flexible free wavetable synth | more curated, less technical surface |
| Portal | granular texture | Hyperium is a full synth, not only FX |
| RC-20 | nostalgic texture | Hyperium has built-in texture as part of synthesis |
| Gross Beat | rhythmic glitch/time FX | Hyperium has simpler patch-integrated glitch motion |

## Target Genres

Primary:

- hyperpop
- pop
- electronic pop
- glitch pop
- experimental electronic indie

Secondary:

- future bass
- bedroom pop
- alt-pop
- digicore
- indie dance
- ambient electronic

## Target Sounds

Hyperium should make these sounds quickly:

- glass leads
- candy plucks
- glossy chord stacks
- digital bells
- crushed basses
- vocal synths
- airy pads
- VHS-style keys
- bitcrushed arps
- glitch transitions
- shimmer textures
- experimental motion patches

## Core Modules

### 1. Oscillators

MVP:

- OSC A wavetable oscillator
- OSC B wavetable oscillator
- SUB oscillator
- Texture/noise layer

Visible controls:

- wave
- position
- warp
- tune
- level
- pan

Advanced controls:

- unison
- detune
- phase
- random phase
- stereo spread
- harmonic shaping

### 2. Texture Layer

The Texture Layer provides modern sonic detail.

Texture types:

- Air
- Dust
- Glass
- Breath
- Bits
- Tape
- Static
- Grain

Controls:

- type
- amount
- tone
- motion
- stereo

### 3. Filter / Shape

Combined tone-shaping section.

Controls:

- filter type
- cutoff
- resonance
- drive
- shape

Filter ideas:

- Clean LP
- Hyper LP
- Glass BP
- Vocal
- Digital Notch
- Soft Tape
- Hard Clip

### 4. Motion

Motion is Hyperium's simplified modulation workflow.

Motion types:

- Pulse
- Drift
- Bounce
- Glitch
- Bloom
- Shake
- Orbit

Controls:

- source type
- target
- amount
- rate
- humanize

The user should be able to create movement without managing a full modulation matrix.

### 5. FX Chain

Curated FX, not an endless rack.

MVP FX:

- Pitch
- Crush
- Drive
- Chorus
- Space
- Comp

Each effect should have a small number of musical controls.

### 6. Performance Macros

Hyperium uses eight core macros:

- Bright
- Wide
- Crush
- Glow
- Drift
- Punch
- Glitch
- Human

Macros should be pre-mapped in most presets.

### 7. Sound Seeds

Sound Seeds are procedural preset starters.

Seed inputs:

- mood
- energy
- motion
- texture

Example moods:

- glassy
- cute
- dreamy
- nostalgic
- dark
- crushed
- glitchy
- vocal

Seed output:

- oscillator selection
- texture layer
- filter setup
- motion assignment
- FX state
- macro mapping

### 8. Macro Morph Pad

The Morph Pad lets users perform large sound changes with one gesture.

Possible corners:

```text
       DREAM
         ▲
         |
SOFT ◄───┼───► CRUSH
         |
         ▼
       GLITCH
```

The pad should move multiple parameters together.

## MVP Feature Set

### Required for V1 Prototype

- plugin shell
- basic UI frame
- wavetable oscillator A
- wavetable oscillator B
- sub oscillator
- texture/noise layer
- ADSR envelope
- LFO
- filter
- drive/waveshaper
- 8 macro controls
- basic preset loading/saving

### Required for V1 Product Direction

- Sound Seeds prototype
- Motion lane prototype
- curated FX chain
- preset browser categories
- responsive/scalable UI
- accessible contrast and readable labels

## Non-Goals for Early Versions

Avoid early complexity:

- full modular routing
- too many oscillator types
- huge matrix editor as the main modulation workflow
- sample library management
- spectral resynthesis
- full granular engine
- AI model dependency
- overwhelming advanced tab layout

## Sound Quality Goals

Hyperium should sound:

- bright without harshness
- digital without being thin
- polished without needing many external plugins
- emotional rather than sterile
- capable of both clean pop and aggressive hyperpop

## UX Quality Goals

Hyperium should feel:

- fast
- readable
- direct
- inspiring
- modern
- uncluttered
- performable

## Success Criteria

Hyperium is successful when a user can:

1. open the plugin
2. choose or generate a seed
3. adjust 3-5 controls
4. add movement
5. automate macros
6. use the sound in a real track

within a short creative flow, without needing to deeply edit the patch.
