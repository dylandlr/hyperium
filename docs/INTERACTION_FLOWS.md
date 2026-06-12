# Hyperium Interaction Flows

This document defines the main user journeys inside Hyperium. The goal is to make the plugin feel fast, musical, and understandable before the user has to think technically.

## Flow 1 — First Sound in 30 Seconds

Goal: user opens Hyperium and creates something usable immediately.

```text
Open Hyperium
   ↓
Choose Sound Seed
   ↓
Adjust Bright / Glow / Crush macros
   ↓
Pick Motion type
   ↓
Adjust Texture amount
   ↓
Play or record
```

### UX Requirements

- Sound Seeds must be visible immediately.
- Macros must be large enough to invite interaction.
- The default patch must sound intentional.
- The user should not need to open a menu.

### Success Criteria

A new user can create a usable sound with:

- 1 seed click
- 2-4 macro changes
- 1 motion adjustment

## Flow 2 — Build a Hyperpop Lead

```text
Choose Seed: glass lead
   ↓
Set OSC A to bright wavetable
   ↓
Set OSC B slightly detuned or vocal-like
   ↓
Enable Octave Stack
   ↓
Raise Bright and Wide
   ↓
Add Glitch Motion to wavetable position
   ↓
Add Space and Comp
```

### UI Needs

- Octave Stack should be visible or one click away.
- Glitch Motion should be simple to assign.
- Macro feedback should show what is changing.

## Flow 3 — Build a Crushed Bass

```text
Choose Seed: crushed bass
   ↓
Lower OSC pitch or enable sub
   ↓
Increase Shape / Drive
   ↓
Increase Crush macro
   ↓
Reduce Space
   ↓
Increase Punch
   ↓
Add subtle Drift or Glitch
```

### UI Needs

- Bass patches should not default to too much reverb.
- Crush and Punch macros should be obvious.
- Output gain should be protected from extreme distortion.

## Flow 4 — Add Motion Without a Matrix

```text
Select Motion type
   ↓
Choose target from common destinations
   ↓
Set amount
   ↓
Set rate
   ↓
Hear movement immediately
```

### Common Motion Destinations

- wavetable position
- filter cutoff
- texture amount
- pitch drift
- crush amount
- space mix
- stereo width

### UX Requirement

The user should not have to understand a modulation matrix for basic movement.

## Flow 5 — Macro Mapping

Default path:

```text
Right-click parameter
   ↓
Assign to Macro
   ↓
Choose macro
   ↓
Drag amount ring
```

Alternative path:

```text
Click Macro
   ↓
Click parameter
   ↓
Set mapping depth
```

### UI Needs

- parameter rings show macro mapping depth
- macro panel shows mapped parameter count
- mappings can be removed quickly
- mappings are saved inside presets

## Flow 6 — Sound Seed Generation

```text
Open Seed Strip
   ↓
Choose Mood
   ↓
Choose Energy
   ↓
Choose Motion
   ↓
Choose Texture
   ↓
Generate
   ↓
Audition and tweak
```

### Seed Inputs

Mood:

- glassy
- cute
- dreamy
- nostalgic
- dark
- crushed
- glitchy
- vocal

Energy:

- soft
- medium
- hard

Motion:

- still
- pulsing
- drifting
- glitchy
- blooming

Texture:

- clean
- airy
- dusty
- digital
- tape
- grain

### UX Requirements

- generated patches should feel curated
- randomization should be constrained
- Generate should never create painfully loud or unusable patches
- a user should be able to regenerate while holding some choices fixed

## Flow 7 — Morph Pad Performance

```text
Load preset
   ↓
Move Morph Pad toward Dream, Crush, Glitch, or Soft
   ↓
Hear multiple parameters move together
   ↓
Automate XY movement in DAW
```

### Morph Corners

```text
       DREAM
         ▲
         |
SOFT ◄───┼───► CRUSH
         |
         ▼
       GLITCH
```

### UX Requirements

- corner labels should be emotionally meaningful
- dot movement should be smooth
- parameter changes should be visible but not overwhelming
- DAW automation should expose X and Y

## Flow 8 — Preset Browsing

```text
Open browser
   ↓
Filter by category
   ↓
Filter by tag
   ↓
Audition preset
   ↓
Favorite or load
```

### Categories

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

### Tags

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

### UX Requirements

- no massive generic preset dump
- tags should feel like producer language
- preset names should communicate vibe
- favorite presets should be one click

## Flow 9 — Advanced Editing Without Clutter

```text
Click module expand
   ↓
Advanced panel opens inline
   ↓
Edit deeper controls
   ↓
Collapse back to main workflow
```

### Example OSC Advanced Controls

- unison
- detune
- phase
- random
- harmonic mode
- stereo

### UX Requirements

- advanced editing should not replace the main screen
- expanded modules should feel temporary and reversible
- deep controls should not be required for basic sound design

## Flow 10 — Saving a Preset

```text
Click Save
   ↓
Name preset
   ↓
Choose category
   ↓
Add tags
   ↓
Save
```

Preset metadata:

- name
- author
- category
- tags
- seed origin if generated
- macro mapping summary

## Global Interaction Rules

### Knobs

- vertical drag changes value
- shift-drag fine tunes
- double-click resets
- right-click opens assignment menu
- hover shows value

### Buttons

- primary actions should be visually clear
- destructive actions need confirmation or undo
- mode buttons should show selected state clearly

### Tooltips

Tooltips should explain musical meaning first.

Example:

```text
Glow: Adds shimmer, air, and upper harmonic bloom.
```

Technical info can come second.

## Final Interaction Rule

> Every common action should be reachable in one or two gestures, and every advanced action should be discoverable without making the main UI feel complex.
