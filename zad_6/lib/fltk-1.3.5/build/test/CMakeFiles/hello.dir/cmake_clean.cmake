file(REMOVE_RECURSE
  "../bin/examples/hello.exe"
  "../bin/examples/hello.exe.manifest"
  "../bin/examples/hello.pdb"
  "../bin/examples/libhello.dll.a"
  "CMakeFiles/hello.dir/hello.cxx.obj"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/hello.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
