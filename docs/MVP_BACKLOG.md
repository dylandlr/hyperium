# Hyperium MVP Backlog

This backlog converts the product direction into implementation-sized tasks.

## Priority Levels

- **P0**: required for the first usable prototype
- **P1**: required for the first serious alpha
- **P2**: important, but can wait
- **P3**: future expansion

## P0 — UI Prototype Foundation

### UI Shell

- [ ] Create main plugin shell layout
- [ ] Add header bar with preset display
- [ ] Add seed strip
- [ ] Add oscillator panels
- [ ] Add texture panel
- [ ] Add filter/shape panel
- [ ] Add motion panel
- [ ] Add FX strip
- [ ] Add macro bar
- [ ] Add morph pad

### Interaction Prototype

- [ ] Seed buttons update visible patch state
- [ ] Motion buttons update active movement
- [ ] Morph pad supports pointer dragging
- [ ] Morph pad supports keyboard control
- [ ] Macro controls show value state
- [ ] Range controls have hover/drag feedback

### Visual Prototype

- [ ] Draw waveform previews
- [ ] Animate motion visualization
- [ ] Show texture particle field
- [ ] Add active/hover states
- [ ] Add responsive layout
- [ ] Add reduced-motion option later

## P0 — JUCE Project Skeleton

- [ ] Create JUCE project
- [ ] Configure VST3 target
- [ ] Configure standalone target
- [ ] Add `PluginProcessor`
- [ ] Add `PluginEditor`
- [ ] Add parameter layout
- [ ] Add initial UI component hierarchy
- [ ] Confirm plugin opens in a host

## P0 — Parameter System

- [ ] Define stable parameter IDs
- [ ] Define parameter ranges
- [ ] Define display names
- [ ] Add smoothing for audio-facing parameters
- [ ] Store/restore parameter state
- [ ] Connect UI controls to parameters

### Initial Parameter IDs

```text
oscA.position
oscA.warp
oscA.level
oscB.position
oscB.warp
oscB.level
texture.amount
texture.tone
texture.stereo
filter.cutoff
filter.resonance
filter.drive
filter.shape
motion.amount
motion.rate
motion.humanize
macro.bright
macro.wide
macro.crush
macro.glow
macro.drift
macro.punch
macro.glitch
macro.human
```

## P1 — Basic Audio Engine

### Voice System

- [ ] Implement voice allocation
- [ ] Implement note on/off
- [ ] Implement velocity handling
- [ ] Implement ADSR envelope
- [ ] Avoid clicks on note release

### Oscillators

- [ ] Implement basic sine/saw/square test oscillator
- [ ] Implement wavetable frame playback
- [ ] Implement wavetable position interpolation
- [ ] Implement oscillator level control
- [ ] Implement oscillator tuning
- [ ] Implement sub oscillator

### Output Safety

- [ ] Add output gain
- [ ] Add soft limiter or safety clamp
- [ ] Prevent generated patches from being painfully loud

## P1 — Texture Layer

- [ ] Implement Air texture
- [ ] Implement Dust texture
- [ ] Implement Glass texture
- [ ] Implement Bits texture
- [ ] Implement Tape texture
- [ ] Implement Breath texture
- [ ] Add amount/tone/stereo controls
- [ ] Macro-map texture parameters

## P1 — Filter / Shape

- [ ] Implement clean low-pass
- [ ] Implement high-pass or band-pass
- [ ] Implement drive stage
- [ ] Implement basic waveshaper
- [ ] Add filter/shape UI bindings
- [ ] Add macro mappings for Bright, Punch, Crush

## P1 — Macro System

- [ ] Implement macro parameter class
- [ ] Implement macro-to-parameter mapping
- [ ] Store macro mappings in presets
- [ ] Show mapped parameter count in UI
- [ ] Add modulation rings around controls
- [ ] Add default macro mappings for starter presets

## P1 — Motion System

- [ ] Implement Pulse motion source
- [ ] Implement Drift motion source
- [ ] Implement Glitch motion source
- [ ] Add destination selection
- [ ] Add modulation depth
- [ ] Add smoothing
- [ ] Show active modulation in UI

## P1 — Preset System

- [ ] Define preset schema
- [ ] Save parameter values
- [ ] Save macro mappings
- [ ] Save motion assignment
- [ ] Save seed metadata
- [ ] Load presets safely
- [ ] Add preset tags/categories

## P1 — Sound Seeds

- [ ] Define seed input model
- [ ] Add deterministic seed rules
- [ ] Generate oscillator choices
- [ ] Generate texture choices
- [ ] Generate motion choices
- [ ] Generate FX settings
- [ ] Generate macro mappings
- [ ] Add regenerate while preserving mood/energy later

## P2 — FX Chain

- [ ] Add Pitch module
- [ ] Add Crush module
- [ ] Add Drive module
- [ ] Add Chorus module
- [ ] Add Space module
- [ ] Add Comp module
- [ ] Add bypass/mix controls
- [ ] Add macro mapping to FX

## P2 — Preset Browser

- [ ] Add category list
- [ ] Add tags
- [ ] Add search
- [ ] Add favorites
- [ ] Add author metadata
- [ ] Add audition behavior

## P2 — Accessibility and Polish

- [ ] Add scalable UI
- [ ] Add focus states
- [ ] Add reduced-motion mode
- [ ] Validate text contrast
- [ ] Improve keyboard navigation
- [ ] Add value readouts

## P3 — Future Expansion

- [ ] Procedural wavetable generation
- [ ] Custom wavetable import
- [ ] CLAP support
- [ ] Per-note modulation
- [ ] Advanced motion editor
- [ ] Granular texture mode
- [ ] Preset cloud/library
- [ ] Theming support

## Next Best Task

Build the UI prototype into a JUCE `PluginEditor` layout before deep DSP work. Hyperium's differentiation depends on workflow, so the interface should be tested early.
