#ifndef QUORRASHELLLITE_HPP
#define QUORRASHELLLITE_HPP

namespace QuorraShell{
	namespace Lite{
		int main();
		int WaitForCommand();
		int ExecuteString(char* script);
		namespace Commands{
			void Version();
			void Echo();
			void ForceException();
			void NotFound();
		}
		namespace Keys{
			void Help();
			void Reboot();
		}
	}
}

#endif
