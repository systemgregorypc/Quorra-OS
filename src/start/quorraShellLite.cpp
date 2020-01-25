/**
 * @file quorraShellLite.cpp
 * @author jose gregorio h c  
 * @brief A Little shell for basic operations
 * quorraShellLite is the first (and reduced) version of quorraShell (planned). The main difference is that quorraShellLite runs in kernel mode and it has built-in commands
 * */
#include <ND_Screen.hpp>
#include <ND_Keyboard.hpp>
#include "quorraShellLite.hpp"
#include <ND_String.hpp>

char DIVISION_EXCEPTION[]={0x66,0xb8,0x00,0x00,
						0x66,0xbb,0x00,0x00,
						0x66,0xf7,0xfb};

void quorraShell::Lite::Commands::Echo()
{
	char* str=ND::Keyboard::GetString();
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_GREEN);
	ND::Screen::PutString(str);
}

void quorraShell::Lite::Commands::Version()
{
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_GREEN);
	ND::Screen::PutString("quorra-OS 0.1.1 - quorraShellLite 0.1.2\n");
}

void quorraShell::Lite::Keys::Help()
{
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_GREEN);
	ND::Screen::PutString("\nquorra-OS Help\n");
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_BLACK);
	ND::Screen::PutString("About the system:\n");
	ND::Screen::PutString("quorra-OS es una inteligencia artificial OS write in C, C++ and Assembler. It's currently being developed by the community.\n");
	ND::Screen::PutString("For more complete documentation, plese visit hhttps://github.com/systemgregorypc/Quorra-OS/\n");
}

void quorraShell::Lite::Keys::Reboot()
{
	// It's not used (without ideas)
}

void quorraShell::Lite::Commands::ForceException()
{
	void (*f)(void) = (void (*)(void)) DIVISION_EXCEPTION;
	f();
}
void quorraShell::Lite::Commands::NotFound()
{
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_RED);
	ND::Screen::PutString("\nCommand not found. Try again\n");
}
int quorraShell::Lite::ExecuteString(char* script)
{
	if(ND::String::Compare("version\n",script)==0)
	{
		quorraShell::Lite::Commands::Version();
	}else if(ND::String::Compare("clear\n",script)==0)
	{
		ND::Screen::Clear(ND_COLOR_WHITE);
	}else
	{
		if(ND::String::Compare("echo\n",script)==0)
		{
			quorraShell::Lite::Commands::Echo();
		}else if(ND::String::Compare("H\n",script)==0)
		{
			quorraShell::Lite::Keys::Help();
		}else
		{
			quorraShell::Lite::Commands::NotFound();
		}
	
	}
	quorraShell::Lite::WaitForCommand();
}
int quorraShell::Lite::WaitForCommand()
{
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_BLACK);
	ND::Screen::PutString("NextShellLite:-> ");
	char* cmd=ND::Keyboard::GetString();
	//ND::Screen::PutString(cmd);
	quorraShell::Lite::ExecuteString(cmd);
	
}
int quorraShell::Lite::main()
{
	ND::Screen::Clear(ND_COLOR_BLACK);
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_WHITE);
	ND::Screen::PutString("Password: ");
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_BLACK);
	char* password=ND::Keyboard::GetString();
	if(ND::String::Compare("12345678\n",password)==0)
	{
	ND::Screen::Clear(ND_COLOR_WHITE);
	ND::Screen::SetColor(ND_SIDE_BACKGROUND,ND_COLOR_WHITE);
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_BLUE);
	ND::Screen::PutString("quorraShellLite v0.1.0\n");
	quorraShell::Lite::WaitForCommand();
	}
	else
	{
		ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_RED);
		ND::Screen::PutString("Incorrect password. Reboot the PC and try again.\n");
	}

}
