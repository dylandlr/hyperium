# Hyperium Design System

Hyperium's design system should make the plugin feel minimal, premium, futuristic, and fast. It should support a sound-design workflow where the user can understand the patch visually before touching every parameter.

## Design Goal

> Make complex synthesis feel like manipulating light, motion, texture, and emotion.

The visual design should communicate:

- clarity
- gloss
- movement
- softness
- precision
- controlled chaos
- modern electronic music culture

## Visual Identity

### Keywords

- glass
- chrome
- violet
- bloom
- digital air
- soft neon
- motion trails
- precise geometry
- minimal control density

### Avoid

- fake hardware panels
- overloaded neon cyberpunk
- EDM spaceship clutter
- tiny unreadable labels
- skeuomorphic screws/racks
- math-symbol overload
- generic dark plugin UI

## Layout System

Use a modular grid with strong spacing.

Suggested base:

```text
Window: 1200 x 760 initial design target
Outer margin: 24px
Panel gap: 12px
Panel radius: 20px
Control radius: 14px
Header height: 64px
Macro bar height: 118px
```

The UI should scale to common plugin sizes:

- compact: 900 x 600
- default: 1200 x 760
- large: 1500 x 950

## Spacing Tokens

```text
space.1 = 4px
space.2 = 8px
space.3 = 12px
space.4 = 16px
space.5 = 24px
space.6 = 32px
space.7 = 48px
```

## Radius Tokens

```text
radius.sm = 8px
radius.md = 14px
radius.lg = 20px
radius.xl = 28px
radius.round = 999px
```

## Color Tokens

### Core

```text
color.bg.deep = #07070D
color.bg.panel = #11111C
color.bg.panelSoft = #171725
color.bg.elevated = #1E1E31
color.text.primary = #F4F1FF
color.text.secondary = #A7A2BE
color.text.muted = #6E6985
```

### Accents

```text
color.accent.violet = #9B5CFF
color.accent.cyan = #56D8FF
color.accent.pink = #FF7DCD
color.accent.blue = #6B9BFF
color.accent.orange = #FF9A5C
color.accent.red = #FF5C7A
```

### Semantic Usage

| Color | Usage |
|---|---|
| Violet | Hyperium brand, selected states, primary controls |
| Cyan | motion, modulation, routing, LFO-style movement |
| Pink | glow, vocal, pop sweetness, shimmer |
| Blue | texture, space, depth, stereo |
| Orange | drive, punch, warmth |
| Red | crush, glitch, clipping, danger states |

## Typography

Recommended characteristics:

- clean geometric sans
- high legibility
- slightly futuristic
- not too decorative

Type scale:

```text
type.micro = 10px / 12px
type.label = 12px / 16px
type.body = 14px / 20px
type.control = 16px / 22px
type.section = 18px / 24px
type.title = 24px / 32px
type.display = 36px / 44px
```

### Text Rules

- Module titles should be uppercase or small caps.
- Preset names can be lowercase for aesthetic identity.
- Values should always be readable while dragging.
- Avoid long labels inside dense panels.

## Panel Design

Panels should feel like glass surfaces floating above a deep background.

Panel traits:

- soft border
- subtle inner glow
- very light gradient
- high contrast text
- no heavy outlines

Panel states:

| State | Behavior |
|---|---|
| Idle | low contrast border |
| Hover | slight border glow |
| Active | accent glow and stronger title |
| Modulated | animated thin accent ring or line |
| Disabled | lower opacity, keep readable |

## Control Types

### Knobs

Knobs should be clean, circular, and readable.

Required states:

- idle value arc
- hover value display
- dragging precise value display
- modulation amount ring
- macro-controlled secondary ring

### Sliders

Use sliders for continuous spatial controls:

- wavetable position
- motion rate
- texture amount
- FX mix

### Buttons

Button types:

- pill buttons for mode selection
- square toggles for FX bypass
- large buttons for Sound Seeds
- icon buttons only when meaning is obvious

### Morph Pad

The Morph Pad should be the most expressive visual control.

It should show:

- four named emotional corners
- current dot position
- subtle trails while moving
- parameter movement preview
- automation-friendly values

## Motion and Animation

Animation should be subtle and functional.

Use animation for:

- active modulation feedback
- waveform movement
- morph pad trails
- selected state transitions
- seed generation pulse

Avoid:

- distracting loops
- excessive particle systems
- UI elements that constantly move without meaning
- performance-heavy visual effects

## Data Visualization

Hyperium should visualize sound without overwhelming the user.

### Wavetable View

Show:

- current waveform
- wavetable position
- subtle motion overlay when modulated

### Texture View

Show:

- particle/noise density
- stereo width as horizontal spread
- tone as vertical brightness

### Motion View

Show:

- source shape
- rate pulse
- destination line
- modulation amount

### Macro View

Show:

- macro value
- mapped parameter count
- color-coded influence

## Accessibility

Requirements:

- minimum readable contrast for labels
- scalable UI
- no critical meaning conveyed by color alone
- reduced-motion mode
- clear focus states
- readable value display
- mod amounts visible numerically on hover

## Design Principle

> Hyperium should look beautiful because it helps the user understand and perform sound, not because it adds decorative complexity.
