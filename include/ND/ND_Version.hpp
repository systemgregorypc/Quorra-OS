/**
* @file ND_Version.hpp
* @author jose gregorio h c & agatha IA
* @brief Defines the version constants
* ND_Versions.hpp defines the version of the kernel and the operating system
*/
#ifndef ND_VERSION_HPP
#define ND_VERSION_HPP

/**
* @brief The codename of the OS version
*/
#define quorra_OS_CODENAME "Inteligencia artificial"

/**
* @brief The name of the quorra-OS distro
*/
#define QUORRA_OS_DISTRO "quorra-OS"

/**
* @brief The year of the OS
*/
#define quorra_OS_YEAR "2020"

/**
* @brief The vendor of the OS
*/
#define QUORRA_OS_VENDOR "JOSE GREGORIO H & AGATHA IA"

/**
* @brief The releases of quorraOS
*/
#define QUORRA_OS_VERSION_MAJOR 0
#define QUORRA_OS_VERSION_MINOR 3
#define QUORRA_OS_VERSION_PATCH 0
/**
* @brief The current arch of quorraOS
*/
#define NEXT_DIVEL_ARCH "x86"
/**
* @brief 64 bits? Experimental
*/
#if (__SIZEOF_POINTER__ == 8)
#define QUORRA_OS_64
#else
#define QUORRA_OS_32
#endif
/**
* @brief Itanium? Experimental
*/
#if __ia64
#define QUORRA_OS_ITANIUM
#endif
/**
* @brief PowerPC? Experimental
*/
#if __powerpc__
#define QUORRA_OS_PPC
#endif
/**
* @brief SPARC? Experimental
*/
#if __sparc
#define QUORRA_OS_SPARC
#endif

/**
* @brief i386? Experimental
*/
#if __i386
#define QUORRA_OS_I386
#endif

/**
* @brief x86_64? Experimental
*/
#if __x86_64
#define QUORRA_OS_X86_64
#endif

/**
* @brief The current line
*/
#define QUORRA_OS_LINE __LINE__

/**
* @brief The current file
*/
#define QUORRA_OS_FILE __FILE__

/**
* @brief The current function
*/
#define QUORRA_OS_FUNCTION __func__
#endif
