from conans import ConanFile, CMake, tools


class VioletConan(ConanFile):
    name = "violet"
    version = "0.1.0"
    license = "MIT/Apache-2.0"
    url = "https://github.com/markushedvall/violet"
    description = "C++ game engine"
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False]}
    default_options = "shared=False"
    generators = "cmake"
    exports_sources = "src/*", "CMakeLists.txt"
    requires = "spdlog/1.3.1@bincrafters/stable"

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        self.copy("*.h", dst="include", src="src")
        self.copy("*.dll", dst="bin", keep_path=False)
        self.copy("*.so", dst="lib", keep_path=False)
        self.copy("*.dylib", dst="lib", keep_path=False)
        self.copy("*.a", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = ["violet"]
