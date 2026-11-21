cmake_minimum_required(VERSION 3.22)
project(SpectralFX VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# JUCE : téléchargé automatiquement (ou fourni via -DJUCE_DIR=...)
if(DEFINED JUCE_DIR)
    add_subdirectory(${JUCE_DIR} JUCE)
else()
    include(FetchContent)
    FetchContent_Declare(JUCE
        GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
        GIT_TAG 8.0.4
        GIT_SHALLOW TRUE)
    FetchContent_MakeAvailable(JUCE)
endif()

# Formats : VST3 (pour Cubase) + application autonome (pour tester sans Cubase)
set(SPECTRALFX_FORMATS VST3 Standalone CACHE STRING "Formats de plugin à construire")

juce_add_plugin(SpectralFX
    PRODUCT_NAME "SpectralFX"
    COMPANY_NAME "Ali"
    BUNDLE_ID "fr.ali.spectralfx"
    PLUGIN_MANUFACTURER_CODE Alik
    PLUGIN_CODE Spfx
    FORMATS ${SPECTRALFX_FORMATS}
    IS_SYNTH FALSE
    NEEDS_MIDI_INPUT FALSE
    NEEDS_MIDI_OUTPUT FALSE
    IS_MIDI_EFFECT FALSE
    EDITOR_WANTS_KEYBOARD_FOCUS FALSE
    VST3_CATEGORIES Fx
    COPY_PLUGIN_AFTER_BUILD FALSE)

target_sources(SpectralFX PRIVATE
    src/PluginProcessor.cpp
    src/PluginEditor.cpp)

target_include_directories(SpectralFX PRIVATE src generated)

target_compile_definitions(SpectralFX PUBLIC
    JUCE_WEB_BROWSER=0
    JUCE_USE_CURL=0
    JUCE_VST3_CAN_REPLACE_VST2=0
    JUCE_DISPLAY_SPLASH_SCREEN=0)

if(MSVC)
    # Les noms des commandes sont en UTF-8 (accents)
    target_compile_options(SpectralFX PRIVATE /utf-8)
endif()

target_link_libraries(SpectralFX
    PRIVATE
        juce::juce_audio_utils
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags)
