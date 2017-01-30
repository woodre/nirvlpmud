/*
 * Used by the new CN guild.
 * Contents personal copyright Mizan@Nirvana, 2003, 2004.
 * Exclusive rights also to Boltar@Nirvana.
 * Reproduction on other muds restricted, under penalty of law and personal retribution.
 *
 */

/* router.h
 *
 * the purpose of this file is to map commonly used functions to their
 * proper daemon counter parts. This also serves as a header file of sorts
 * so i can track where everything is going to be used in the development 
 * process.
 *
 * Each daemon has its own special job.
 *
 * This way i can make all of the functions available to anything that includes
 * this file. Yes, it can be messy perhaps but it allows for things to be very
 * predictable, and for humans when they encounter a function they don't understand
 * they can look it up here first like an index... and get pointed to where it is
 * defined fairly quickly instead of hunting through an entire directory tree.
 *
 */

/*
 * Config stores systemwide settings and parameters.
 * Ideally, any global changes to the guild should be applied through this object.
 *
 */

#ifndef IS_CONFIG_DM

#define CONFIG_DM       CONFIG_OBJECT_ROOT + "configDM.c"

/* Put your functions in here. Alphabetical order please. */

#endif

/*
 * Core contains all the basic stuff available to the guild. Really low level functions
 * and stuff like that.
 *
 */

#ifndef IS_CORE_DM

#define CORE_DM       CONFIG_OBJECT_ROOT + "coreDM.c"

/* Put your functions in here. Alphabetical order please. */
ANSI_filter(arg) { return CORE_DM->ANSI_filter(arg); }
ANSI_replace(arg) { return CORE_DM->ANSI_replace(arg); }


#endif



