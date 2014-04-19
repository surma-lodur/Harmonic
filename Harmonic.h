
#include "math.h"
namespace Harmonic {
  static float NOTES[127];

  static void calculate(unsigned short offset) {
    for (unsigned short i = offset; i < offset + 127; i++) {
      float value = 440.0 * pow(2.0, ((i - 49.0) / 12.0));
      NOTES[i] = value;
    }

  }

}