PROJECT(quorra-OS-quorraroot)

MESSAGE(STATUS "Creating quorraRoot directory")
INSTALL(DIRECTORY ../grub DESTINATION boot)
INSTALL(DIRECTORY ../include DESTINATION .)
