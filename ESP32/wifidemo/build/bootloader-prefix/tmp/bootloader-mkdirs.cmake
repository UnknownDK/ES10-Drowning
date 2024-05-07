# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/tardi/esp/v5.2.1/esp-idf/components/bootloader/subproject"
  "C:/Users/tardi/Desktop/ES10-Drowning/ESP32/wifidemo/build/bootloader"
  "C:/Users/tardi/Desktop/ES10-Drowning/ESP32/wifidemo/build/bootloader-prefix"
  "C:/Users/tardi/Desktop/ES10-Drowning/ESP32/wifidemo/build/bootloader-prefix/tmp"
  "C:/Users/tardi/Desktop/ES10-Drowning/ESP32/wifidemo/build/bootloader-prefix/src/bootloader-stamp"
  "C:/Users/tardi/Desktop/ES10-Drowning/ESP32/wifidemo/build/bootloader-prefix/src"
  "C:/Users/tardi/Desktop/ES10-Drowning/ESP32/wifidemo/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/tardi/Desktop/ES10-Drowning/ESP32/wifidemo/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/tardi/Desktop/ES10-Drowning/ESP32/wifidemo/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
