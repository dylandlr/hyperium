# Hyperium Parameter Reference

This document tracks the first stable parameter IDs used by the C++ plugin skeleton.

Stable parameter IDs matter because they affect:

- DAW automation
- preset compatibility
- macro mappings
- motion routing
- future migration logic

## Naming Rule

Use clear domain-based IDs:

```text
module.control
```

Examples:

```text
oscA.position
texture.amount
macro.glow
```

## Oscillator Parameters

| ID | Display Name | Purpose |
|---|---|---|
| `oscA.position` | OSC A Position | Wavetable frame position |
| `oscA.warp` | OSC A Warp | Main oscillator shape/warp amount |
| `oscA.level` | OSC A Level | OSC A output level |
| `oscB.position` | OSC B Position | Wavetable frame position |
| `oscB.warp` | OSC B Warp | Main oscillator shape/warp amount |
| `oscB.level` | OSC B Level | OSC B output level |

## Texture Parameters

| ID | Display Name | Purpose |
|---|---|---|
| `texture.amount` | Texture Amount | Overall texture/noise layer amount |
| `texture.tone` | Texture Tone | Brightness/darkness of texture layer |
| `texture.stereo` | Texture Stereo | Texture width/spread |

## Filter / Shape Parameters

| ID | Display Name | Purpose |
|---|---|---|
| `filter.cutoff` | Filter Cutoff | Filter cutoff frequency |
| `filter.resonance` | Filter Resonance | Resonance/emphasis |
| `filter.drive` | Filter Drive | Input or post-filter drive |
| `filter.shape` | Filter Shape | Waveshaping/folding intensity |

## Motion Parameters

| ID | Display Name | Purpose |
|---|---|---|
| `motion.amount` | Motion Amount | Motion modulation depth |
| `motion.rate` | Motion Rate | Motion speed/rate |
| `motion.humanize` | Motion Humanize | Imperfection/randomization amount |

## Macro Parameters

| ID | Display Name | Purpose |
|---|---|---|
| `macro.bright` | Bright | Tone, harmonics, cutoff, sparkle |
| `macro.wide` | Wide | Stereo spread, chorus, texture width |
| `macro.crush` | Crush | Bitcrush, clipping, sample-rate reduction |
| `macro.glow` | Glow | Shimmer, air, reverb, upper bloom |
| `macro.drift` | Drift | Pitch instability, phase motion, wobble |
| `macro.punch` | Punch | Envelope snap, transient, compression feel |
| `macro.glitch` | Glitch | Stutter chance, buffer cuts, jump behavior |
| `macro.human` | Human | Velocity response, note variation, imperfection |

## Parameter Design Rules

### 1. IDs should not change casually

Once presets exist, changing an ID can break preset loading and DAW automation.

### 2. Display names can change more easily

The display name can become more musical over time without breaking automation if the underlying ID remains stable.

### 3. Musical controls should remain automatable

Macros, motion controls, and Morph Pad axes should be first-class DAW automation targets.

### 4. Avoid exposing every internal DSP value

Hyperium should expose parameters that improve workflow. Internal technical values can stay private unless users need them.

## Future Parameters

Likely additions:

```text
morph.x
morph.y
seed.mood
seed.energy
fx.pitch.mix
fx.crush.mix
fx.drive.mix
fx.chorus.mix
fx.space.mix
fx.comp.amount
sub.level
sub.octave
```

Future migrations should be handled carefully once preset compatibility matters.
