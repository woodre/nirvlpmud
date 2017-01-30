inherit "/players/vertebraker/closed/shardak/std/emote";
#include "/players/pestilence/ansi.h"


void
reset(status arg)
{
    if(arg) return;
    ::reset();
    load_targeted_msgs(({
     "You express your deep "+HIK+"loathing"+NORM+" and "+RED+"hatred"+NORM+" towards #T#.\n",
      ""+HIK+"#N#"+NORM+" expresses their deep "+HIK+"loathing"+NORM+" and "+RED+"hatred"+NORM+" towards #T#.\n",
     ""+HIK+"#N#"+NORM+" expresses their deep "+HIK+"loathing"+NORM+" and "+RED+"hatred"+NORM+" toward you.\n" }));
    load_untargeted_msgs(({
      "You express your deep "+HIK+"loathing"+NORM+" and "+RED+"hatred"+NORM+" towards everyone.\n",
      ""+HIK+"#N#"+NORM+" expresses their deep "+HIK+"loathing"+NORM+" and "+RED+"hatred"+NORM+" towards everyone.\n", }));
}
