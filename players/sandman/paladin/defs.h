
/* Main guild object */
#define MAIN "/players/sandman/paladin/powers"

/* For color */
#include "ansi.h"

string filter_color(string str, string color, object player) {
   object medal;

   if(!player)
     player = this_player();
   medal = present("guild_medal", player);   
   if(!medal || !medal->query_color()) 
     return str;
   else
     return color+str+NORM;
}

/* directory for help files */
#define HELPDIR "/players/sandman/paladin/helpdir/"

/* Deny execution of command */
#define notify_fail(A) { write(filter_color(A+"\n",HIR)); return 1; } 

/* Define levels and costs for use of powers */
#define MIN_ALIGN 0     /* Minimum alignment necessary to use powers */
#define BLESS_DUR 200   /* duration of bless spell */

/* Formats columns nicely */
justify(str, len){return extract(str+"                             ",0,len-1);}

#define PALGUILD "/players/sandman/paladin/adv_guild"  

#define MOREFILE "/players/sandman/paladin/more"
