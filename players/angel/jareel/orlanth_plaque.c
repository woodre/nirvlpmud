#include "/players/jareel/define.h"
inherit "obj/treasure.c";

reset(arg)
{
  if(arg) return;
  no_clean = 1;
  set_short("A plaque");
  set_alias("plaque");

set_long("It appears to be a commandment plaque, you probably could read the commandments.\n");
set_read(
"          "+BOLD+"Breath is in everyone: all Air is your friend\n"+
"            All Air must move for storm or breeze.\n"+
"                   Answer the call for assistance\n"+
"             Then charge what is fair, in your own eye.\n"+
"               Pay all debts, even if it breaks you,\n"+
"               Especially those gained in emergency.\n"+
"                If you demand payment in your turn\n"+
"                    You will expect to be paid.\n"+
"                Give freely! Do not break a friend.\n"+
"                In emergencies a fair man will aid\n"+
"                But take praise and cheers for pay.\n"+
"                    Do it free, they will too."+NORM+"\n");
}
get() { return 0; }
