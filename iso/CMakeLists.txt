PROJECT(quorra-OS-iso)

MESSAGE(STATUS "Generating ISO script")
FILE(WRITE iso.sh "#!/bin/bash\n grub-mkrescue --compress=xz --product-name=quorra-OS --product-version=0.0.1 -o Quorra-OS.iso quorra")
INSTALL(PROGRAMS iso.sh DESTINATION ..)
