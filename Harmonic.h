
#include "math.h"

namespace Harmonic {

static const unsigned int  max_notes = 127;

static float        NOTES[max_notes];
static unsigned int PERIODS[max_notes];

// Frequency of C0 in hertz
static const float  baseFreq = 16.3516;
// Ratio between consecutive frequencies (C1 to C2, C2 to C3, etc.)
static const double ratio    = 1.0594630943593;



static float calculateHertz(unsigned short note) {
    return baseFreq * pow(ratio, note);
}

static void calculate(unsigned short offset, unsigned long factor) {
    for (unsigned short note = 0; note <= max_notes; note++) {
        NOTES[note]   = calculateHertz(note + offset) ;
        PERIODS[note] = ((1 / NOTES[note]) * factor);
    }
}
static void calculate(unsigned short offset) {
    calculate(offset, pow(10,6)) ;
}

static void calculate() {
    calculate(0) ;
}
}
