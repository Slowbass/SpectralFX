// Interfaces minimales attendues par le code C++ généré par Faust.
#pragma once

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

struct Soundfile;

struct Meta
{
    virtual ~Meta() = default;
    virtual void declare (const char* key, const char* value) = 0;
};

struct UI
{
    virtual ~UI() = default;

    virtual void openTabBox (const char* label) = 0;
    virtual void openHorizontalBox (const char* label) = 0;
    virtual void openVerticalBox (const char* label) = 0;
    virtual void closeBox() = 0;

    virtual void addButton (const char* label, FAUSTFLOAT* zone) = 0;
    virtual void addCheckButton (const char* label, FAUSTFLOAT* zone) = 0;
    virtual void addVerticalSlider (const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;
    virtual void addHorizontalSlider (const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;
    virtual void addNumEntry (const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;

    virtual void addHorizontalBargraph (const char*, FAUSTFLOAT*, FAUSTFLOAT, FAUSTFLOAT) {}
    virtual void addVerticalBargraph (const char*, FAUSTFLOAT*, FAUSTFLOAT, FAUSTFLOAT) {}
    virtual void addSoundfile (const char*, const char*, Soundfile**) {}

    virtual void declare (FAUSTFLOAT*, const char*, const char*) {}
};

// Classe de base vide : les méthodes sont définies dans les classes générées.
class FaustBase
{
public:
    virtual ~FaustBase() = default;
};
