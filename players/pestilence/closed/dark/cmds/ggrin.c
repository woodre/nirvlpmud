inherit "/players/vertebraker/closed/shardak/std/emote";
#include "/players/pestilence/ansi.h"


void
reset(status arg)
{
    if(arg) return;
    ::reset();
    load_targeted_msgs(({
     "You grin "+HIR+"satanically"+NORM+" at #T#.\n",
      ""+HIK+"#N# grins "+HIR+"satanically"+NORM+" at #T#.\n",
      ""+HIK+"#N# grins "+HIR+"satanically"+NORM+" at you.\n" }));
    load_untargeted_msgs(({
      "You grin "+HIR+"satanically"+NORM+".\n",
      ""+HIK+"#N# grins "+HIR+"satanically"+NORM+".\n", }));
}
