/* configure the game as you like: */

#define MONEYSIGN "$"

/* what set of rules to use? (either the true rules or house rules) */
#define TRUE_RULES 

/* ------ The True Rules ------------------------------ */
#ifdef TRUE_RULES
#define START_CASH 1500
#define MORTGAGE_PERCENT 10

/* ------ House Rules (feel free to change these) ----- */
#else  /* house rules */

/* put your rules here */
#define START_CASH 1500
#define MORTGAGE_PERCENT 10

/* also if you want.. */
#define LAND_GO 400
#define FREE_PARKING 500

#endif
