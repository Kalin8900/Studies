if(NOT EXISTS "E:/Projekty/CLion/lib/fltk-1.3.5/build/install_manifest.txt")
   message(FATAL_ERROR
      "Cannot find install manifest: \"E:/Projekty/CLion/lib/fltk-1.3.5/build/install_manifest.txt\"")
endif(NOT EXISTS "E:/Projekty/CLion/lib/fltk-1.3.5/build/install_manifest.txt")

file(READ "E:/Projekty/CLion/lib/fltk-1.3.5/build/install_manifest.txt" files)
string(REGEX REPLACE "\n" ";" files "${files}")

foreach(file ${files})
message(STATUS "Uninstalling \"$ENV{DESTDIR}${file}\"")
   exec_program("E:/Projekty/CLion/lib/cmake/bin/cmake.exe"
      ARGS "-E remove -f \"$ENV{DESTDIR}${file}\""
      OUTPUT_VARIABLE rm_out
      RETURN_VALUE rm_retval
   )
   if(NOT "${rm_retval}" STREQUAL 0)
      message(FATAL_ERROR "Problem when removing \"$ENV{DESTDIR}${file}\"")
   endif(NOT "${rm_retval}" STREQUAL 0)
endforeach(file)
