#include "exru.h"
#include <vector>
#include <ImfRgbaFile.h>

int write_rgba(int width, 
    int height, 
    char* filename, 
    const float* raw_rgbas) {

  std::vector<Imf::Rgba> pixels(width * height);
  for (int p = 0; p < width * height; ++p) {
    pixels[p] = Imf::Rgba(raw_rgbas[4*p+0], 
                          raw_rgbas[4*p+1], 
                          raw_rgbas[4*p+2],
                          raw_rgbas[4*p+3]);
  }
  Imf::RgbaOutputFile file (filename, width, height, Imf::WRITE_RGBA);
  file.setFrameBuffer(&pixels[0], 1, width);
  file.writePixels (height); 
  return 1;
}

