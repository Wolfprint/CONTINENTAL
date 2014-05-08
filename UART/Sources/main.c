
#include "derivative.h" /* include peripheral declarations */
#include "mcl\mcg_init.h"
#include "mcl\uart0_init.h"
#include "variables.h"
//#include "dcl\io_char.h"
//#include "dcl\charCtrlFnc.h"
#include "app\appChar.h"
#include "app\actuatorApp.h"


int main(void) {
	mcg_init();
	uart0_init();
    put("C: CheckSum\r\nS: Stop Bit\r\nLS: Light sensor\r\nSE: Selector status\r\nIS: Ignition status");
	put("\r\n| C | S | LS | SE | IS |");
	for (;;) {
		str_ctrl();
		print_str();
		actionSelector();
		
	}
	return 0;
}
