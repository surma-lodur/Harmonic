Harmonic
========

Harmonic is an little C++ Library to Calculate All harmonic tones.

The notes are limited to the max. number the MIDI-Protocol can handle *(127)*.


The calculation storesthe note scale  as Hertz in the NOTES-Array and as Periods in
PERIODS-Array. The offset parameter make it possible to shift the calculation per notes.

The factor will be used to calculate the Periods. The default is 10^6.


```cpp
#include "math.h"
#include <Harmonic.h>

unsigned short offset = 0;
unsigned long  factor = pow(10, 6);

Harmonic::calculate(offset, factor);
Harmonic::calculate(offset);
Harmonic::calculate();

Harmonic::NOTES[57];   // A4(440Hz)
Harmonic::PERIODS[57]; // A4(2272µs)
```


## Development and Testing

(https://github.com/bxparks/EpoxyDuino)[EpoxyDuino] for Tests recommended.


Use the **test** target for testing with EpoxyDuino.

```
make test
```

Use the **native_test** target for testing with a Arduino.
