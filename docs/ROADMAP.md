# Hyperium Roadmap

Hyperium should be developed in phases, with UI/UX tested early rather than added at the end.

## Phase 0 — Product Foundation

Status: in progress

Goals:

- define product identity
- define UI/UX direction
- define MVP scope
- define architecture direction
- create initial repository docs

Deliverables:

- README
- Product Spec
- UI/UX Spec
- Architecture Overview
- Roadmap

## Phase 1 — UI-First Prototype

Goal: create a non-audio clickable prototype that proves the workflow.

Why this comes first:

Hyperium's biggest differentiator is workflow. The UI should be validated before the full DSP engine is complex.

Deliverables:

- plugin window mockup
- header / preset browser
- oscillator panels
- texture panel
- motion panel
- FX strip
- macro bar
- morph pad
- basic interaction states

Success criteria:

- a user can understand the plugin layout in under 10 seconds
- a user can explain what the macros do without reading documentation
- the interface feels less intimidating than Serum
- sound-design flow is visible from the layout alone

## Phase 2 — JUCE Project Skeleton

Goal: create the first buildable plugin shell.

Deliverables:

- JUCE project
- VST3 target
- standalone target if useful
- PluginProcessor
- PluginEditor
- parameter tree
- basic UI rendering
- placeholder panels

Success criteria:

- project builds locally
- plugin opens in a DAW/plugin host
- UI scales correctly
- parameters can be automated

## Phase 3 — Basic Synth Engine

Goal: make Hyperium produce useful sound.

Deliverables:

- MIDI voice handling
- oscillator A
- oscillator B
- sub oscillator
- ADSR envelope
- gain staging
- initial wavetable playback
- basic preset state save/restore

Success criteria:

- polyphonic notes play correctly
- oscillator position can be automated
- core sound is stable without clicks or crashes

## Phase 4 — Filter, Shape, and Texture

Goal: add character.

Deliverables:

- multimode filter
- drive / waveshaper
- texture/noise layer
- texture type selector
- filter/shape UI
- texture UI

Success criteria:

- patches can sound polished with only oscillator + texture + filter/shape
- texture layer adds character without overwhelming the patch

## Phase 5 — Macro System

Goal: make Hyperium performable.

Deliverables:

- 8 macro parameters
- macro mapping data structure
- macro UI
- preset-stored mappings
- simple parameter modulation by macro value

Success criteria:

- every factory preset has useful macro mappings
- macros feel musical instead of arbitrary
- macro automation creates track-ready movement

## Phase 6 — Motion System

Goal: simplify modulation.

Deliverables:

- Motion source types: Pulse, Drift, Glitch
- destination selection
- amount/rate controls
- visible modulation feedback
- basic smoothing

Success criteria:

- user can add motion without opening a matrix
- motion destinations are clear
- glitch/drift behaviors feel musical, not random noise

## Phase 7 — FX Chain

Goal: make patches feel finished.

Deliverables:

- Pitch
- Crush
- Drive
- Chorus
- Space
- Comp
- FX strip UI
- per-effect bypass and mix

Success criteria:

- Hyperium sounds useful without external FX
- FX controls remain simple
- presets can be polished but not overprocessed

## Phase 8 — Sound Seeds and Presets

Goal: create the fast-start workflow.

Deliverables:

- procedural Sound Seed generator
- starter seed categories
- preset browser
- preset tags
- factory preset bank

Success criteria:

- a user can generate a useful starting patch in seconds
- seeds feel curated, not random
- preset tags match modern producer language

## Phase 9 — Macro Morph Pad

Goal: create a signature performance feature.

Deliverables:

- XY morph pad
- four emotional corners
- parameter mapping system
- visual feedback
- automation support

Success criteria:

- morphing changes feel musical
- pad works for live performance and DAW automation
- movement feels expressive instead of gimmicky

## Phase 10 — Polish and Release Preparation

Goal: prepare a first public alpha/beta.

Deliverables:

- UI polish
- accessibility pass
- CPU optimization
- preset polish
- installer/package plan
- user guide
- demo project
- issue templates

Success criteria:

- stable plugin behavior
- polished visual identity
- clear first-user experience
- enough presets to demonstrate identity

## Development Priority Rule

For every feature, ask:

1. Does it make sound design faster?
2. Does it make Hyperium sound more unique?
3. Does it fit the minimal UI?
4. Can a producer understand it quickly?

If not, postpone it.
