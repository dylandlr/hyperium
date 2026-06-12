# Hyperium UI/UX Specification

Hyperium's UI/UX is a core product feature. The interface should not simply expose the sound engine. It should guide the producer through a faster, cleaner, more musical sound-design process.

## UX Mission

> Make advanced wavetable sound design feel immediate, emotional, and performable.

Hyperium should help the user answer four questions quickly:

1. What is the sound?
2. How bright, wide, crushed, or emotional is it?
3. How does it move?
4. Is it ready to use in a track?

## Target User

Hyperium is designed for producers making:

- hyperpop
- pop
- electronic pop
- glitch pop
- experimental indie
- indie-electronic
- bright digital trap/pop hybrids
- vocal-chop-inspired synth music

The user may understand synthesis, but the plugin should not require deep synthesis knowledge to make good sounds.

## UI Personality

Hyperium should feel:

- minimal
- glossy
- fast
- playful
- precise
- slightly futuristic
- emotionally expressive
- less technical than Serum
- more serious than a toy plugin

## Core UX Principles

### 1. One-screen first

The main sound-design workflow should happen on a single screen. Avoid deep tab diving unless the user explicitly opens advanced controls.

### 2. Musical labels first

Use emotional or musical control names before technical names when possible.

Examples:

| Preferred | Avoid as primary label |
|---|---|
| Glow | High-frequency reverb send |
| Crush | Bit depth and sample-rate reduction |
| Drift | Pitch random walk |
| Human | Velocity/random variation |
| Motion | Modulation matrix |
| Texture | Noise oscillator |

Technical labels can still appear in advanced panels or tooltips.

### 3. Fast defaults

Every module should sound useful when enabled. No module should open in an unusable neutral state that requires five adjustments before it becomes musical.

### 4. Macro-first sound shaping

The user should be able to perform a patch using the eight macros without opening the deeper editor.

### 5. Progressive disclosure

Default view: simple controls.

Expanded view: deeper parameters.

Expert view: modulation routing, parameter ranges, hidden DSP controls.

## Main Layout

```text
┌────────────────────────────────────────────────────────┐
│ HYPERIUM      Preset Name                  Save  Menu   │
├────────────────────────────────────────────────────────┤
│ Seed / Morph Strip                                      │
│ [cute] [glass] [dream] [crush] [glitch]   Morph Pad     │
├───────────────┬───────────────┬────────────────────────┤
│ OSC A         │ OSC B         │ TEXTURE                │
│ Wave          │ Wave          │ Air / Glass / Bits     │
│ Position      │ Position      │ Amount Tone Motion     │
│ Warp          │ Warp          │ Stereo                 │
│ Level         │ Level         │                        │
├───────────────┴───────────────┴────────────────────────┤
│ FILTER / SHAPE                                          │
│ Type   Cutoff   Res   Drive   Shape                     │
├────────────────────────────────────────────────────────┤
│ MOTION                                                  │
│ Pulse | Drift | Glitch | Bloom | Orbit                  │
│ Target      Amount      Rate      Humanize              │
├────────────────────────────────────────────────────────┤
│ FX                                                      │
│ Pitch   Crush   Drive   Chorus   Space   Comp           │
├────────────────────────────────────────────────────────┤
│ MACROS                                                  │
│ Bright Wide Crush Glow Drift Punch Glitch Human         │
└────────────────────────────────────────────────────────┘
```

## Primary Workflow

### 1. Start from a seed

The user chooses a Sound Seed such as:

- glass lead
- crushed candy bass
- vocal pluck
- vhs keys
- dreamy pad
- glitch arp
- soft chrome
- pixel bell

The seed initializes oscillator choices, texture, filter, motion, FX, and macro assignments.

### 2. Shape the tone

The user adjusts only the most important sound controls:

- Wave
- Position
- Warp
- Texture Amount
- Filter Cutoff
- Shape

### 3. Add motion

The user chooses one movement style:

- Pulse
- Drift
- Glitch
- Bloom
- Orbit
- Shake

Then chooses a destination and amount.

### 4. Finish with macros

The user performs or automates the patch with:

- Bright
- Wide
- Crush
- Glow
- Drift
- Punch
- Glitch
- Human

## Macro Design

### Bright

Controls:

- filter cutoff
- harmonic brightness
- texture tone
- subtle high-shelf style lift

### Wide

Controls:

- unison spread
- stereo texture width
- chorus width
- reverb width

### Crush

Controls:

- bitcrush amount
- digital distortion
- sample-rate reduction
- transient aggression

### Glow

Controls:

- shimmer amount
- reverb send
- upper harmonic bloom
- airy texture

### Drift

Controls:

- pitch instability
- wavetable position drift
- tape-style wobble
- phase randomization

### Punch

Controls:

- envelope snap
- transient shaping
- compression intensity
- low-end focus

### Glitch

Controls:

- stutter chance
- buffer repeat amount
- rhythmic chop depth
- micro pitch jumps

### Human

Controls:

- velocity sensitivity
- note-to-note variation
- slight detune variation
- timing and modulation imperfection

## Visual Design Direction

### General style

- dark interface
- soft contrast
- glassy panels
- sharp typography
- subtle gradients
- minimal neon accents
- smooth animation
- no cluttered skeuomorphism

### Visual language

| Element | Visual metaphor |
|---|---|
| Wavetables | clean animated waveform strips |
| Motion | glowing path or pulse lane |
| Macros | large performance-ready controls |
| Texture | fine particle/noise field |
| Morph Pad | emotional XY space |
| Modulation | thin animated connection lines |

## Color System

Use restrained color, not rainbow overload.

Suggested palette concept:

- background: near-black blue/purple
- panels: translucent dark graphite
- primary accent: hyper violet or electric cyan
- secondary accent: soft pink or glass blue
- warning/aggression accent: crushed red/orange
- text: high-contrast off-white
- muted text: cool gray

Color should communicate function:

| Color role | Meaning |
|---|---|
| Violet | core Hyperium identity |
| Cyan | motion/modulation |
| Pink | glow/vocal/pop energy |
| Orange/red | crush/distortion/glitch |
| Blue | texture/space/depth |

## Accessibility Requirements

The UI must remain readable and usable:

- strong text contrast
- scalable UI
- clear knob values
- keyboard focus states
- no color-only status indicators
- optional reduced animation mode
- visible modulation amounts
- legible labels at small sizes

## Interaction Details

### Knobs

Knobs should support:

- drag vertically
- shift-drag for fine control
- double-click to reset
- right-click or menu for modulation assignment
- visible value readout on hover/drag

### Modulation assignment

Preferred interaction:

1. click Motion source
2. drag or click target parameter
3. adjust amount ring around target

The user should not need to open a giant matrix for common routing.

### Advanced panels

Each module can expand downward or open a small inline panel. Avoid full-screen mode changes.

Example oscillator advanced panel:

- unison
- detune
- phase
- random
- stereo
- harmonic mode

## Preset Browser UX

The preset browser should support producer-friendly categories:

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

Preset browser should include tags:

- bright
- soft
- aggressive
- nostalgic
- airy
- glitchy
- clean
- distorted
- wide
- dry
- wet

## UX Anti-Goals

Avoid:

- too many tabs
- tiny unlabeled knobs
- technical-only parameter names
- cluttered modulation matrix as the main workflow
- generic EDM-only sound categories
- unreadable neon-on-black text
- making math visible when it does not improve music-making
- adding features that slow down the first 30 seconds of use

## Final UX Rule

> The best Hyperium UI is one where a producer can make a track-ready sound before they fully understand how the patch works.
