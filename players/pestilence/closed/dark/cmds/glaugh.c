inherit "/players/vertebraker/closed/shardak/std/emote";
#include "/players/pestilence/ansi.h"


void
reset(status arg)
{
    if(arg) return;
    ::reset();
    load_targeted_msgs(({
     "You laugh at #T# in a "+RED+"maniacal"+NORM+" fashion.\n",
      ""+HIK+"#N#"+NORM+" laughs at #T# in a "+RED+"manical"+NORM+" fashion.\n",
     ""+HIK+"#N#"+NORM+" laughs at you in a "+RED+"manical"+NORM+" fashion.\n" }));
    load_untargeted_msgs(({
      "You laugh in a "+RED+"maniacal"+NORM+" fashion.\n",
      ""+HIK+"#N#"+NORM+" laughs in a "+RED+"maniacal"+NORM+" fashion.\n", }));
}
