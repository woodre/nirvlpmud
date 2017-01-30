/* 
 *      Creator :  Gothic@TMI-2  
 *      The standard set of ANSI codes for mudlib use.
 */

#include "/players/illarion/esc.h"
#define CSI     ESC + "["
 
		/*  Foreground Colors  */
 
#define BLK ESC+"[0;30m"          /* Black    */
#define RED ESC+"[0;31m"          /* Red      */
#define GRN ESC+"[0;32m"          /* Green    */
#define YEL ESC+"[0;33m"          /* Yellow   */
#define BLU ESC+"[0;34m"          /* Blue     */
#define MAG ESC+"[0;35m"          /* Magenta  */
#define CYN ESC+"[0;36m"          /* Cyan     */
#define WHT ESC+"[0;37m"          /* White    */
 
		/*   Hi Intensity Foreground Colors   */
 
#define HIK ESC+"[1;30m"        /* Black    */
#define HIR ESC+"[1;31m"        /* Red      */
#define HIG ESC+"[1;32m"        /* Green    */
#define HIY ESC+"[1;33m"        /* Yellow   */
#define HIB ESC+"[1;34m"        /* Blue     */
#define HIM ESC+"[1;35m"        /* Magenta  */
#define HIC ESC+"[1;36m"        /* Cyan     */
#define HIW ESC+"[1;37m"        /* White    */
 
 
#define NORM ESC+"[2;37;0m"      /* Puts everything back to normal */
 
/*  Additional ansi Esc codes added to ansi.h by Gothic  april 23,1993 */
/* Note, these are Esc codes for VT100 terminals, and emmulators */
/*       and they may not all work within the mud               */
 
#define BOLD ESC+"[1m"          /* Turn on bold mode */
