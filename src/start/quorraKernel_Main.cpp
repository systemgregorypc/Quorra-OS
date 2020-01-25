 /* Check if the compiler thinks if we are targeting the wrong operating system. */
#ifndef quorra_OS
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif
#include <ND_Screen.hpp>
#include <ND_Color.hpp>
#include <ND_Panic.hpp>
#include <ND_Keyboard.hpp>
#include <ND_GDT.hpp>
#include <ND_IDT.hpp>
#include <ND_IRQ.hpp>
#include <ND_Timer.hpp>
#include "quorraShellLite.hpp"

/*
 * - Add VGA UI System 
 * - Add Threads
 * - Add FS
 * - Add Pagination
 * - Add hability to load programs
 * */
/* Headers for description tables */
//#include "quorraKernel_GDT.h"
/* Headers for all system functions */
//#include "quorra-OS.h"
/* Headers for MultiBoot */
//#include <ND_Multiboot.hpp>
/* Headers for quorraFS */
//#include "quorraFS.h"
//#include "ND_Initrd.h"
//extern uint32_t placement_address;
//extern fs_node_t* fs_root;
#if defined(__cplusplus)
extern "C" /* Use C linkage for kernel_main. */
#endif
int quorraKernel_Main(/*struct multiboot *mboot_ptr*/)
{
	asm volatile("cli");
	ND::Screen::Clear(ND_COLOR_WHITE);
	ND::Screen::SetColor(ND_SIDE_BACKGROUND,ND_COLOR_WHITE);
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_GREEN);
	ND::Screen::PutString("NextDivel\n");
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_BLACK);
	ND::Screen::PutString("Licensed under GNU GPL v2\n");
	ND::GDT::Install();
	ND::IDT::Install();
	ND::IRQ::Install();

	ND::Keyboard::Setup();
	ND::Timer::Setup();

	ND::Timer::Phase(50);

	asm volatile("sti");
	ND::Keyboard::wait();

	ND::Screen::SetColor(ND_SIDE_FOREGROUND, ND_COLOR_BLACK);
	ND::Screen::PutString("\nWaiting 100 ticks...");
	ND::Timer::Wait(100);
	ND::Screen::SetColor(ND_SIDE_FOREGROUND, ND_COLOR_GREEN);
	ND::Screen::PutString("done");

	quorraShell::Lite::main();

	while(1)
	{
		//in a future jump to a hardware agnostic loop
	}

	return 0;
}
