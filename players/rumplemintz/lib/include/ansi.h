/************************************************************/
/*** These macro's allow you to use ansi graphic escape   ***/
/*** sequences with ease within code.                     ***/
/***                                                      ***/
/*** Eg. write(BOLD+"This is Bold.\n"+OFF);               ***/
/***     write(BOLD+RED+"This is bold and red.\n"+OFF);   ***/
/***                                                      ***/
/***  Remember ALWAYS turn the graphics "OFF"             ***/
/************************************************************/ 

#include "/sys/ansi.h"

#ifndef ESC
#define ESC         "["
#endif
#ifndef BOLD
#define BOLD        "[1m"
#endif
#define FAINT       "[2m"
/* does not work
#define ITALIC      "[3m"
 */
#define UNDERLINE   "[4m"
#ifndef BLINK
#define BLINK       "[5m"
#endif
/* does not work...
#define R_BLINK     "[6m"
 */
#ifndef REVERSE
#define REVERSE     "[7m"
#endif
/* CONCEAL is banned till I can turn it off, If you more this then you've 
   stuffed your screen, relog in to fix screen.
#define CONCEAL     "[8m"
 */

/*** Foreground colours ***/

#define BLACK_F     "[30m"
#define RED_F       "[31m"
#define GREEN_F     "[32m"
#define YELLOW_F    "[33m"
#define BLUE_F      "[34m"
#define MAGENTA_F   "[35m"
#define CYAN_F      "[36m"
#define WHITE_F     "[37m"

/*** Background Colours ***/

#define BLACK_B     "[40m"
#define RED_B       "[41m"
#define GREEN_B     "[42m"
#define YELLOW_B    "[43m"
#define BLUE_B      "[44m"
#define MAGENTA_B   "[45m"
#define CYAN_B      "[46m"
#define WHITE_B     "[47m"


/*** Experimental ***/

#define CUP(XXX,ZZZ)                 "["+ZZZ+";"+XXX+"h"
#define CURSOR(XXX,ZZZ)              "["+ZZZ+";"+XXX+"f"
#ifndef OFF
#define OFF  "[0m"
#endif

#define ANSI_ON (status)this_player()->ansi_on()

#define ADMIN_COL      BOLD+MAGENTA_F
#define ARCH_COL       MAGENTA_F
#define QC_COL         BLUE_F
#define LORD_COL       GREEN_F+BOLD
#define ELDER_COL      GREEN_F
#define SENIOR_COL     YELLOW_F+BOLD
#define CREATOR_COL    YELLOW_F
#define APPRENTICE_COL RED_F+BOLD
#define ASP_COL        RED_F
#define PLAYER_COL     CYAN_F

