if(NOT EXISTS "/home/adel/ros2_ws/build/cola2_lib/install_manifest.txt")
    message(FATAL_ERROR "Cannot find install manifest: \"/home/adel/ros2_ws/build/cola2_lib/install_manifest.txt\"")
endif(NOT EXISTS "/home/adel/ros2_ws/build/cola2_lib/install_manifest.txt")

file(READ "/home/adel/ros2_ws/build/cola2_lib/install_manifest.txt" files)
string(REGEX REPLACE "\n" ";" files "${files}")
foreach(file ${files})
    message(STATUS "Uninstalling \"$ENV{DESTDIR}${file}\"")
    if(EXISTS "$ENV{DESTDIR}${file}" OR IS_SYMLINK "$ENV{DESTDIR}${file}")
        exec_program("/usr/bin/cmake" ARGS "-E remove \"$ENV{DESTDIR}${file}\""
            OUTPUT_VARIABLE rm_out RETURN_VALUE rm_retval)
        if(NOT "${rm_retval}" STREQUAL 0)
            message(FATAL_ERROR "Problem when removing \"$ENV{DESTDIR}${file}\"")
        endif(NOT "${rm_retval}" STREQUAL 0)
    else(EXISTS "$ENV{DESTDIR}${file}" OR IS_SYMLINK "$ENV{DESTDIR}${file}")
        message(STATUS "File \"$ENV{DESTDIR}${file}\" does not exist.")
    endif(EXISTS "$ENV{DESTDIR}${file}" OR IS_SYMLINK "$ENV{DESTDIR}${file}")
endforeach(file)

# remove cola2_lib directory in include (removes all files in it!)
message(STATUS "Uninstalling \"/home/adel/ros2_ws/install/cola2_lib/include/cola2_lib\"")
if(EXISTS "/home/adel/ros2_ws/install/cola2_lib/include/cola2_lib")
    exec_program("/usr/bin/cmake"
        ARGS "-E remove_directory \"/home/adel/ros2_ws/install/cola2_lib/include/cola2_lib\""
        OUTPUT_VARIABLE rm_out RETURN_VALUE rm_retval)
    if(NOT "${rm_retval}" STREQUAL 0)
        message(FATAL_ERROR
            "Problem when removing \"/home/adel/ros2_ws/install/cola2_lib/include/cola2_lib\"")
    endif(NOT "${rm_retval}" STREQUAL 0)
else(EXISTS "/home/adel/ros2_ws/install/cola2_lib/include/cola2_lib")
    message(STATUS
        "Directory \"/home/adel/ros2_ws/install/cola2_lib/include/cola2_lib\" does not exist.")
endif(EXISTS "/home/adel/ros2_ws/install/cola2_lib/include/cola2_lib")

# remove cola2_lib directory in share (removes all files in it!)¡
message(STATUS "Uninstalling \"/home/adel/ros2_ws/install/cola2_lib/share/cola2_lib\"")
if(EXISTS "/home/adel/ros2_ws/install/cola2_lib/share/cola2_lib")
    exec_program("/usr/bin/cmake"
        ARGS "-E remove_directory \"/home/adel/ros2_ws/install/cola2_lib/share/cola2_lib\""
        OUTPUT_VARIABLE rm_out RETURN_VALUE rm_retval)
    if(NOT "${rm_retval}" STREQUAL 0)
        message(FATAL_ERROR
            "Problem when removing \"/home/adel/ros2_ws/install/cola2_lib/share/cola2_lib\"")
    endif(NOT "${rm_retval}" STREQUAL 0)
else(EXISTS "/home/adel/ros2_ws/install/cola2_lib/share/cola2_lib")
    message(STATUS
        "Directory \"/home/adel/ros2_ws/install/cola2_lib/share/cola2_lib\" does not exist.")
endif(EXISTS "/home/adel/ros2_ws/install/cola2_lib/share/cola2_lib")

# remove python 3 installed files
message("Uninstalling python package cola2")
exec_program("/usr/bin/python3" ARGS "-m pip uninstall -y cola2" OUTPUT_VARIABLE pip3_uninstall_out)
message("${pip3_uninstall_out}")
