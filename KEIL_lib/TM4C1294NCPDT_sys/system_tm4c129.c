/**************************************************************************//**
 * @file     system_TM4C129.c
 * @brief    CMSIS Device System Source File for
 *           TI TIVA TM4C1294NCPDT Snowflake Device Series
 * @version  V1.00
 * @date     15. May 2013
 *
 * @note
 *
 *                                                             modified by Keil
 ******************************************************************************/

#include <stdint.h>
#include "TM4C1294NCPDT.h"

/*----------------------------------------------------------------------------
  DEFINES
 *----------------------------------------------------------------------------*/
//-------- <<< Use Configuration Wizard in Context Menu >>> ------------------
//
// This file can be used by the Keil uVision configuration wizard to set
// the following system clock configuration values.  Or the value of the
// macros can be directly edited below if not using the uVision configuration
// wizard.
//
//--------------------- Clock Configuration ----------------------------------
//
//  <e> Clock Configuration
//          <i> Uncheck this box to skip the clock configuration.
//
// The following controls whether the system clock is configured in the
// SystemInit() function.  If it is defined to be 1 then the system clock
// will be configured according to the macros in the rest of this file.
// If it is defined to be 0, then the system clock configuration is bypassed.
//
#define CLOCK_SETUP 1


//-----------------PLLREQ0-----------------//
//When controlling this register directly, software must change this value while the
//PLL is powered down. Writes to PLLFREQ0 are delayed from affecting the PLL until the RSCLKCFG
//register NEWFREQ bit is written with a 1.
//The PLL frequency can be calculated using the following equation:
//fVCO = (fIN * MDIV)
//where
//fIN = fXTAL/(Q+1)(N+1) or fPIOSC/(Q+1)(N+1)
//MDIV = MINT + (MFRAC / 1024)
//The Q and N values are programmed in the PLLFREQ1 register. Note that to reduce jitter, MFRAC
//should be programmed to 0x0.


//This bit controls power to the PLL. If set, the PLL power is applied and
//the PLL will oscillate based on the values in the PLLFREQ0 and
//PLLFREQ1 registers [23]
#define PLLPWR_ON  	(1UL<<23)
#define PLLPWR_OFF 	(0UL<<23) //reset

#define NEWFREQ_ON	(0x1UL << 30)
#define NEWFREQ_OFF	(0x0UL << 30)

//PLL M Fractional Value
//PLL M Integer Value
//This field contains the integer value of the PLL M value.
#define MFRAC				(0b0000000000 <<10) //reset [19:10]
#define MINT				(0b0000000001 <<0) //reset [9:0]


//-----------------PLLREQ1-----------------//
//PLL Q Value
//This field contains the PLL Q value
//PLL N Value
//This field contains the PLL N value.
#define Q						(0b00000<<8) //reset [12:8]
#define	N						(0b00000<<0) //reset [4:0]


//-----------------MEMTIM0-----------------//

//Specifies the length of the EEPROM bank clock high time
//Value Description
//0x0 1/2 system clock period
//0x1 1 system clock period
//0x2 1.5 system clock periods
//0x3 2 system clock periods
//0x4 2.5 system clock periods
//0x5 3 system clock periods
//0x6 3.5 system clock periods
//0x7 4 system clock periods
//0x8 4.5 system clock periods
#define EBCHT				0 //reset [25:22]

//Specifies the relationship of EEPROM clock to system clock
//Value Description
//0 EEPROM clock rising aligns with system clock rising
//1 EEPROM clock rising aligns with system clock falling
#define	EBCE				1 //reset [21]

//This field specifies the number of wait states inserted.
//Value Description
//0x0 0 wait states
//0x1 1 wait state
//0x2 2 wait states
//0x3 3 wait states
//0x4 4 wait states
//0x5 5 wait states
//0x6 6 wait states
//0x7 7 wait states
//0x8-0xF reserved
#define EWS					0 //reset [19:16]

//Specifies the length of the Flash bank clock high time
//Value Description
//0x0 1/2 system clock period
//0x1 1 system clock period
//0x2 1.5 system clock periods
//0x3 2 system clock periods
//0x4 2.5 system clock periods
//0x5 3 system clock periods
//0x6 3.5 system clock periods
//0x7 4 system clock periods
//0x8 4.5 system clock periods
#define FBCHT				0 //reset [9:6]

//Specifies the relationship of Flash clock to system clock
//Value Description
//0 Flash clock rising aligns with system clock rising
//1 Flash clock rising aligns with system clock falling
#define	FBCE				1 //reset [5]

//This field specifies the number of wait states inserted.
//Value Description
//0x0 0 wait states
//0x1 1 wait state
//0x2 2 wait states
//0x3 3 wait states
//0x4 4 wait states
//0x5 5 wait states
//0x6 6 wait states
//0x7 7 wait states
//0x8-0xF reserved
#define FWS					0 //reset [3:0]


//-----------------PLLSTAT-----------------//
//Read Only
//Value Description
//0 The PLL is unpowered or is not yet locked.
//1 The PLL powered and locked.
#define LOCK			0 //resert [0]

//POR State Power-On Reset State
//
//

/*----------------------------------------------------------------------------
  Define clocks
 *----------------------------------------------------------------------------*/
#define PIOSCLK     (16000000UL)            /* PIOSC        oscillator freq */
#define MOSCLK     	(25000000UL)            /* MOSC		     	oscillator freq */
#define LFIOSCLK    (   33000UL)            /* Internal 33K oscillator freq */
#define XTAL32K     (   32768UL)            /* external 32K oscillator freq */


/*----------------------------------------------------------------------------
  Get the OSC clock
	PLL calculater
 *----------------------------------------------------------------------------*/
static uint32_t getOscClk (uint32_t xtal, uint32_t oscSrc) {
  uint32_t oscClk = PIOSCLK;

  switch (oscSrc) {                      /* switch OSCSRC */
    case 0:                              /* MOSC Main oscillator */
      switch (xtal) {                    /* switch XTAL */
        case 0x0:
          oscClk = 1000000UL;
          break;
        case 0x1:
          oscClk = 1843200UL;
          break;
        case 0x2:
          oscClk = 2000000UL;
          break;
        case 0x3:
          oscClk = 2457600UL;
          break;
        case 0x4:
          oscClk = 3579545UL;
          break;
        case 0x5:
          oscClk = 3686400UL;
          break;
        case 0x6:
          oscClk = 4000000UL;
          break;
        case 0x7:
          oscClk = 4096000UL;
          break;
        case 0x8:
          oscClk = 4915200UL;
          break;
        case 0x9:
          oscClk = 5000000UL;
          break;
        case 0xA:
          oscClk = 5120000UL;
          break;
        case 0xB:
          oscClk = 6000000UL;
          break;
        case 0xC:
          oscClk = 6144000UL;
          break;
        case 0xD:
          oscClk = 7372800UL;
          break;
        case 0xE:
          oscClk = 8000000UL;
          break;
        case 0xF:
          oscClk = 8192000UL;
          break;
        case 0x10:
          oscClk = 10000000UL;
          break;
        case 0x11:
          oscClk = 12000000UL;
          break;
        case 0x12:
          oscClk = 12288000UL;
          break;
        case 0x13:
          oscClk = 13560000UL;
          break;
        case 0x14:
          oscClk = 14318180UL;
          break;
        case 0x15:
          oscClk = 16000000UL;
          break;
        case 0x16:
          oscClk = 16384000UL;
          break;
       }
      break;
    case 2:                         /* LFIOSCLK Internal oscillator */
      oscClk = LFIOSCLK;
      break;
    case 3:                         /* MOSCLK Internal oscillator/4 */
      oscClk = MOSCLK;
      break;
    case 4:                         /* 32kHz internal oscillator  */
      oscClk = XTAL32K;
      break;
		
		default:
			break;
			
  }

  return oscClk;
}

/*----------------------------------------------------------------------------
  Define clocks
 *----------------------------------------------------------------------------*/
#define __SYSTEM_CLOCK    (16000000ul)


/*----------------------------------------------------------------------------
  Clock Variable definitions
 *----------------------------------------------------------------------------*/
uint32_t SystemCoreClock = __SYSTEM_CLOCK; /*!< System Clock Frequency (Core Clock)*/


/*----------------------------------------------------------------------------
  Clock functions
 *----------------------------------------------------------------------------*/
void SystemCoreClockUpdate (void)            /* Get Core Clock Frequency      */
{
  /* TODO: Updates required to fully work with TM4C1294NCPDT series devices */
  SystemCoreClock = __SYSTEM_CLOCK;
	
	//-------------------------------------//

	/* Determine clock frequency according to clock register values */
	/*if the PLL is not being used*/
	/*The PLL is controlled using the PLLFREQ0, PLLFREQ1 and PLLSTAT registers.*/	
	/*Writes to PLLFREQ0 and PLLFREQ1 are delayed from affecting the PLL until the RSCLKCFG
	register NEWFREQ bit is written with a 1.*/
	
	/*the device is not in deep sleep mode*/
	/*The SLEEPDEEP bit of the System Control (SYSCTRL) register selects which sleep mode is used
	(see page 173).*/

		if(((SYSCTL->PLLSTAT &= (1UL << 0)) && (SYSCTL -> RSCLKCFG &= (1UL << 30))) || ((SCB->SCR &= (1UL << 2)) == 0x4)){
				SystemCoreClock = __SYSTEM_CLOCK;
			return;
		}
		//-----------//
		
		
		//----------------------------------------//
		uint32_t rsclkcfg = SYSCTL->RSCLKCFG;
		/*the OSYSDIV bit field in the RSCLKCFG register is the divisor used to determine the
		system clock.*/
		unsigned int clk_src = ((rsclkcfg &= (0xF << 20)) >> 20);
		rsclkcfg = SYSCTL->RSCLKCFG;
		unsigned int sys_div = ((rsclkcfg &= (0x7FF << 10)) >> 10);
				
		/* the PLL is being used, then PSYSDIV bit field in the RSCLKCFG register must be
programmed as well as the values in the PLLFREQ0 and PLLFREQ1 registers.*/
		//what is FREQ0 and  FREQ1 values
		
		unsigned int mint 	= (SYSCTL -> PLLFREQ0) & (0x3FF << 0);
		unsigned int mfrac 	=	((SYSCTL -> PLLFREQ0) & (0x3FF << 10)) >> 10;
		unsigned int mdiv 	= mint + (mfrac / 1024);
		
		unsigned int n_val = (SYSCTL -> PLLFREQ1) & (0x1F << 0);
		unsigned int q_val = ((SYSCTL -> PLLFREQ1) & (0x1F << 8)) >>8;
		
		
		unsigned int plldiv = (SYSCTL -> RSCLKCFG) & (0x3FF << 0);
		//fsysclk = fvco / (plldiv +1)
		unsigned int usepll = ((SYSCTL -> RSCLKCFG) & (0x1 << 28)) >> 28;
		unsigned int pll_src = ((rsclkcfg &= (0xF << 24)) >> 24);
		rsclkcfg = SYSCTL->RSCLKCFG;
		unsigned int fxtal = 16000000UL;
		
		switch ((rsclkcfg &= (0xF << 20)) >> 20){
			case 0x0: //PIOSCLK		16 000 000 UL		
				fxtal = 16000000UL;
			break;
			case 0x1: //reserved
				fxtal = 16000000UL;
			break;
			case 0x2: //LFIOSCLK
				fxtal = 16000000UL;
			break;
			case 0x3: //MOSCLK
				fxtal = 16000000UL;
			break;
			case 0x4: //Hibernation RTC_CLK
				fxtal = 16000000UL;
			break;
			default: //reserved
				fxtal = 16000000UL;
				break;				
		}
		rsclkcfg = SYSCTL->RSCLKCFG;
		
		if(usepll != 0x1){
			//do not use pll
			unsigned int fin = fxtal /((q_val + 1)*(n_val + 1)); //PIOSCLK
			unsigned int fvco = fin * mdiv;
			unsigned int fsys = fvco / (plldiv + 1);
			
		}else{
			//use pll
			
		}
		
		unsigned int clk_rate = getOscClk(clk_src, sys_div);
		
		switch ((rsclkcfg &= (0xF << 20)) >> 20){
			case 0x0: //PIOSCLK		16 000 000 UL		
			break;
			case 0x1: //reserved
			break;
			case 0x2: //LFIOSCLK
			break;
			case 0x3: //MOSCLK
			break;
			case 0x4: //Hibernation RTC_CLK
			break;
			default: //reserved
				break;				
		}
		rsclkcfg = SYSCTL->RSCLKCFG;
		
}



#define NOXTAL 			(1U << 2)
#define PWRDN 			(1U << 3)
#define MOSCPUPRIS	(1U << 8)
#define MOSC				(0x3U << 20)
#define DSOSCSRC		(0x3U << 20)
#define USEPLL			(0x1U << 28)
#define MEMTIMU			(0x1U	<< 31)
#define PSYSDIV			(0x00U << 0)

/**
 * Initialize the system
 *
 * @param  none
 * @return none
 *
 * @brief  Setup the microcontroller system.
 *         Initialize the System.
 */
void SystemInit (void){
	#if(CLOCK_SETUP)
			volatile uint32_t i;
	#endif
		
	/* FPU settings ------------------------------------------------------------*/
	#if (__FPU_USED == 1)
		SCB->CPACR |= ((3UL << 10*2) |                 /* set CP10 Full Access */
									 (3UL << 11*2)  );               /* set CP11 Full Access */
	#endif
		
	//Step 1:
	//Once POR has completed, the PIOSC is acting as the system clock.

	//Is the system Clock PIOSC?
	#if(CLOCK_SETUP)
		uint32_t volatile RSCLK_CFG, MOSCPUP_RIS, LOCK_val ;
		
		do {RSCLK_CFG = SYSCTL->RSCLKCFG;}
		while((RSCLK_CFG & (0xFU<<20))!= 0x00);
		//PIOSC is acting as the system clk
		
		//Step 2:
		//Power up the MOSC by clearing the NOXTAL bit in the MOSCCTL register.
		SYSCTL->MOSCCTL &= ~NOXTAL;
		
		//Step 3:
		//If single-ended MOSC mode is required, the MOSC is ready to use. If crystal mode is required,
		//clear the PWRDN bit and wait for the MOSCPUPRIS bit to be set in the Raw Interrupt Status
		//(RIS), indicating MOSC crystal mode is read

		SYSCTL->MOSCCTL &= ~PWRDN;
		
		do {MOSCPUP_RIS = SYSCTL->RIS;}
		while((MOSCPUP_RIS & MOSCPUPRIS)!= MOSCPUPRIS);
		
		//Step 4:
		// Set the OSCSRC field to 0x3 in the RSCLKCFG register at offset 0x0B0
		SYSCTL->RSCLKCFG |= MOSC;
		
		//Step 5:
		//If the application also requires the MOSC to be the deep-sleep clock source, then program the
		//DSOSCSRC field in the DSCLKCFG register to 0x3
		SYSCTL->DSCLKCFG |= DSOSCSRC;
		
		//Step 6:
		//Write the PLLFREQ0 and PLLFREQ1 registers with the values of Q, N, MINT, and MFRAC to
		//the configure the desired VCO frequency setting.
		//Step 7:
		//Write the MEMTIM0 register to correspond to the new system clock setting.
		
		//reset values
		// SYSCTL ->PLLFREQ0 |= MFRAC | MINT;
		// SYSCTL ->PLLFREQ1 |= Q | N ;
		// SYSCTL ->PLLFREQ0 |= PLLPWR_ON;
		// SYSCTL ->MEMTIM0	= 0x00300030;
		 
		// SYSCTL -> RSCLKCFG |= NEWFREQ_ON;
/* 		Step 8:
		Wait for the PLLSTAT register to indicate the PLL has reached lock at the new operating point */
		
		// do{LOCK_val = SYSCTL ->PLLSTAT;}
		// while((LOCK_val & 0x1U) != 0x1U);
	
	
		//Step 9:
		//Write the RSCLKCFG register's PSYSDIV value, set the USEPLL bit to enabled, and MEMTIMU
		//bit.
		//SYSCTL -> RSCLKCFG |= USEPLL;
		//SYSCTL -> RSCLKCFG |= MEMTIMU;	
		//SYSCTL -> RSCLKCFG |= PSYSDIV;
		
	#endif

}





void Q_onAssert(char const *module, int loc) {
    /* TBD: damage control */
    (void)module; /* avoid the "unused parameter" compiler warning */
    (void)loc;    /* avoid the "unused parameter" compiler warning */
    NVIC_SystemReset();
}


//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//

