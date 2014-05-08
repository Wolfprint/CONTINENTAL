#ifndef CRYSTALCLOCK_H_
#define CRYSTALCLOCK_H_


#define CORE_CLOCK				 (48000000)
#define PERIPHERAL_BUS_CLOCK (CORE_CLOCK/2)

/*UART*/
#define CLK0_FREQ_HZ        8000000
#define CLK0_TYPE           CRYSTAL
#define PLL0_PRDIV      4       // divider eference by 4 = 2 MHz
#define PLL0_VDIV       24      // multiply reference by 24 = 48 MHz

// Constants for use in pll_init
#define NO_OSCINIT 0
#define OSCINIT 1

#define OSC_0 0
#define OSC_1 1

#define LOW_POWER 0
#define HIGH_GAIN 1

#define CANNED_OSC  0
#define CRYSTAL 1

#define PLL_0 0
#define PLL_1 1

#define PLL_ONLY 0
#define MCGOUT 1

// MCG Mode defines

#define BLPI 1
#define FBI  2
#define FEI  3
#define FEE  4
#define FBE  5
#define BLPE 6
#define PBE  7
#define PEE  8

// IRC defines
#define SLOW_IRC 0
#define FAST_IRC 1

int pll_init(int crystal_val, unsigned char hgo_val, unsigned char erefs_val, signed char prdiv_val, signed char vdiv_val, unsigned char mcgout_select);

void InitClock(void);


#endif /* CRYSTALCLOCK_H_ */
