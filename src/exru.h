#ifndef EXRU_H
#define EXRU_H

// MAJOR_VERSION

extern "C" {
  
  /*
   * rgbas is a list of 4-float tuples.
   */
  int write_rgba(int width, int height, char* filename, const float* rgbas);
}

#endif
