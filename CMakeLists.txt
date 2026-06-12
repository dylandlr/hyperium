cmake_minimum_required(VERSION 3.22)

project(Hyperium VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

# For local development, you can also provide JUCE as a subdirectory later.
# This keeps the first prototype easy to clone and configure.
FetchContent_Declare(
    JUCE
    GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
    GIT_TAG master
)

FetchContent_MakeAvailable(JUCE)

juce_add_plugin(Hyperium
    COMPANY_NAME "Hyperium Audio"
    BUNDLE_ID "com.hyperium.audio.hyperium"
    IS_SYNTH TRUE
    NEEDS_MIDI_INPUT TRUE
    NEEDS_MIDI_OUTPUT FALSE
    IS_MIDI_EFFECT FALSE
    EDITOR_WANTS_KEYBOARD_FOCUS TRUE
    COPY_PLUGIN_AFTER_BUILD TRUE
    PLUGIN_MANUFACTURER_CODE Hypr
    PLUGIN_CODE Hyrm
    FORMATS Standalone VST3
    PRODUCT_NAME "Hyperium"
)

target_sources(Hyperium
    PRIVATE
        Source/PluginProcessor.cpp
        Source/PluginEditor.cpp
        Source/Parameters.cpp
        Source/SoundSeed.cpp
)

target_include_directories(Hyperium
    PRIVATE
        Source
)

target_compile_definitions(Hyperium
    PUBLIC
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_VST3_CAN_REPLACE_VST2=0
)

target_link_libraries(Hyperium
    PRIVATE
        juce::juce_audio_utils
        juce::juce_dsp
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags
)
