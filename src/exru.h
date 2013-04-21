#ifndef EXRU_H
#define EXRU_H

// MAJOR_VERSION

extern "C" {
  
  /*
   * Write an RGBA EXR.
   *
   * remarks The output image is half precision..
   * rgbas is a list of 4-float tuples.
   *
   * returns 1 on success
   */
  int write_rgba(int width, 
      int height, 
      const char* filename, 
      const float* rgbas);
}

#endif
