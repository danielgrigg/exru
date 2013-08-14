require 'formula'

class Libexru < Formula
  homepage 'http://sliplanesoftware.com'
  url 'https://github.com/danielgrigg/exru/archive/v1.0.0.tar.gz'
  sha1 'efefec456270ca5cae044a78714c505358277940'
  version '1.0.0'

  depends_on 'cmake'

  def install
    args = std_cmake_parameters.split
    system "mkdir build"
    args << ".."
    Dir.chdir 'build' do
      system "cmake", *args
      system "make install"
    end
  end
end
