#line 2 "HarmonicTest.ino"

#include <AUnit.h>

#include "Harmonic.h"

#define TOLERANCE 0.01

test(calculateHertz) {
    float c0 = Harmonic::calculateHertz(0);
    assertNear(c0, 16.3516, TOLERANCE);
    float c1 = Harmonic::calculateHertz(12);
    assertNear(c1, 32.7032, TOLERANCE);
    float a4 = Harmonic::calculateHertz(4*12 + 9);
    assertNear(a4, 440.0, TOLERANCE);
    float a7 = Harmonic::calculateHertz(7*12 + 9);
    assertNear(a7, 3520.0, TOLERANCE);
}

test(calculate) {
    Harmonic::calculate();

    unsigned int a4 = 2272;
    assertEqual(Harmonic::PERIODS[4*12+9], a4);
}

void setup() {
#if ! defined(EPOXY_DUINO)
    delay(1000); // wait for stability on some boards to prevent garbage Serial
#endif
    Serial.begin(115200); // ESP8266 default of 74880 not supported on Linux
    while (!Serial); // for the Arduino Leonardo/Micro only
#if defined(EPOXY_DUINO)
    Serial.setLineModeUnix();
#endif
}

void loop() {
    aunit::TestRunner::run();
}
