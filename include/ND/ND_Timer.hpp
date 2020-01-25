/**
 * @file ND_Timer.hpp
 * @author jose gregorio hernandez & agatha IA
 * @brief Timer x86 API
 * */
namespace ND{
	namespace Timer{
			void Setup();
			void Phase(int hz);
			void Wait(int ticks);
		}
}
extern "C"
void ND_Timer_Handler(struct regs* r);
